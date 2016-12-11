// Jass2 parser for bison/yacc
// by Rudi Cilibrasi
// Sun Jun  8 00:51:53 CEST 2003
// thanks to Jeff Pang for the handy documentation that this was based
// on at http://jass.sourceforge.net
%{

#include <stdio.h>
#include <string.h>
#include "token.yy.h"
#include "misc.h"


#define YYSTYPE union node
#define YYMAXDEPTH 100000
#define YYDEBUG 1

%}

%token IF
%token THEN
%token TYPE
%token EXTENDS
%token HANDLE
%token NEWLINE
%token GLOBALS
%token ENDGLOBALS
%token CONSTANT
%token NATIVE
%token TAKES
%token RETURNS
%token FUNCTION
%token ENDFUNCTION
%token LOCAL
%token ARRAY
%token SET
%token CALL
%token ELSE
%token ELSEIF
%token ENDIF
%token LOOP
%token EXITWHEN
%token RETURN
%token DEBUG
%token ENDLOOP
%token NOT
%token TNULL
%token TTRUE
%token TFALSE
%token CODE
%token STRING
%token INTEGER
%token REAL
%token BOOLEAN
%token NOTHING
%token ID
%token COMMA
%token AND
%token OR
%token EQUALS
%token TIMES
%token DIV
%token PLUS
%token MINUS
%token LPAREN
%token RPAREN
%token LBRACKET
%token RBRACKET
%token LESS
%token GREATER
%token LEQ
%token GEQ
%token EQCOMP
%token NEQ
%token STRINGLIT
%token INTLIT
%token REALLIT
%token UNITTYPEINT
%token ANNOTATION

%right EQUALS
%left AND
%left OR
%left LESS GREATER EQCOMP NEQ LEQ GEQ
%left NOT
%left MINUS PLUS
%left TIMES DIV

%%



program: topscopes globdefs topscopes funcdefns
;

topscopes: topscope
       | topscopes topscope
;

topscope: typedefs  
       | funcdecls
;

funcdefns: /* empty */
       | funcdefns funcdefn
;

globdefs: /* empty */
         | GLOBALS newline vardecls ENDGLOBALS endglobalsmarker
         | GLOBALS vardecls ENDGLOBALS endglobalsmarker {yyerrorline(syntaxerror, lineno - 1, "缺少换行，在global之后");}
;

endglobalsmarker: /* empty */  {afterendglobals = 1;}
;

vardecls: /* empty */
         | vd vardecls
;

vd:      newline
       | vardecl
;

funcdecls: /* empty */
         | fd funcdecls
;

fd:      newline
       | funcdecl
;

typedefs:  /* empty */
         | td typedefs
;

td:      newline
       | typedef
;

// Returns a typenode
expr: intexpr      { $$.ty = gInteger; }
      | realexpr   { $$.ty = gReal; }
      | stringexpr { $$.ty = gString; }
      | boolexpr   { $$.ty = gBoolean; }
      | FUNCTION rid { struct funcdecl *fd = ht_lookup(&functions, $2.str);
                       if (fd == NULL) {
                           char ebuf[1024];
                           snprintf(ebuf, 1024, "函数 %s 未定义", $2.str);
                           getsuggestions($2.str, ebuf, 1024, 1, &functions);
                           yyerrorex(semanticerror, ebuf);
                           $$.ty = gCode;
                       } else {
                           if (fd->p->head != NULL) {
                               char ebuf[1024];
                               snprintf(ebuf, 1024, "被转为code的函数 %s 不能有任何参数", $2.str);
                               yyerrorex(semanticerror, ebuf);
                           }
                           if( fd->ret == gBoolean) {
                               $$.ty = gCodeReturnsBoolean;
                           } else {
                               $$.ty = gCodeReturnsNoBoolean;
                           }
                       }
                     }
      | TNULL { $$.ty = gNull; }
      | expr LEQ expr { checkcomparison($1.ty, $3.ty); $$.ty = gBoolean; }
      | expr GEQ expr { checkcomparison($1.ty, $3.ty); $$.ty = gBoolean; }
      | expr LESS expr { checkcomparison($1.ty, $3.ty); $$.ty = gBoolean; }
      | expr GREATER expr { checkcomparison($1.ty, $3.ty); $$.ty = gBoolean; }
      | expr EQCOMP expr { checkeqtest($1.ty, $3.ty); $$.ty = gBoolean; }
      | expr NEQ expr { checkeqtest($1.ty, $3.ty); $$.ty = gBoolean; }
      | expr AND expr { canconvert($1.ty, gBoolean, 0); canconvert($3.ty, gBoolean, 0); $$.ty = gBoolean; }
      | expr OR expr { canconvert($1.ty, gBoolean, 0); canconvert($3.ty, gBoolean, 0); $$.ty = gBoolean; }
      | NOT expr { canconvert($2.ty, gBoolean, 0); $$.ty = gBoolean; }
      | expr TIMES expr { $$.ty = binop($1.ty, $3.ty); }
      | expr DIV expr { $$.ty = binop($1.ty, $3.ty); }
      | expr MINUS expr { $$.ty = binop($1.ty, $3.ty); }
      | expr PLUS expr { 
                         if ($1.ty == gString && $3.ty == gString)
                           $$.ty = gString;
                         else
                           $$.ty = binop($1.ty, $3.ty); }
      | MINUS expr { isnumeric($2.ty); $$.ty = $2.ty; }
      | LPAREN expr RPAREN { $$.ty = $2.ty; }
      | funccall { $$.ty = $1.ty; }
      | rid LBRACKET expr RBRACKET {
          const struct typeandname *tan = getVariable($1.str);
          if (!typeeq(tan->ty, gAny)) {
            if (!tan->isarray) {
              char ebuf[1024];
              snprintf(ebuf, 1024, "%s 不是数组", $1.str);
              yyerrorex(semanticerror, ebuf);
            }
            else {
              canconvert($3.ty, gInteger, 0);
            }
          }
          $$.ty = tan->ty;
       }
      | rid {
          const struct typeandname *tan = getVariable($1.str);
          if (tan->lineno == lineno && tan->fn == fno) {
            char ebuf[1024];
            snprintf(ebuf, 1024, "在定义变量 %s 之前使用了它", $1.str);
            yyerrorex(semanticerror, ebuf);
          } else if (islinebreak && tan->lineno == lineno - 1 && tan->fn == fno) {
            char ebuf[1024];
            snprintf(ebuf, 1024, "在定义变量 %s 之前使用了它", $1.str);
            yyerrorline(semanticerror, lineno - 1, ebuf);
          } else if (tan->isarray) {
            char ebuf[1024];
            snprintf(ebuf, 1024, "数组变量 %s 缺少索引", $1.str);
            yyerrorex(semanticerror, ebuf);
          }
          if(infunction && ht_lookup(curtab, $1.str) && !ht_lookup(&initialized, $1.str) ){
            char ebuf[1024];
            snprintf(ebuf, 1024, "变量 %s 没有初始化", $1.str);
            //yyerrorex(3, ebuf);
            yyerrorline(semanticerror, lineno - 1, ebuf);
          }
          $$.ty = tan->ty;
       }
      | expr EQUALS expr {yyerrorex(syntaxerror, "表达式中的 = ，可能是 =="); checkeqtest($1.ty, $3.ty); $$.ty = gBoolean;}
      | LPAREN expr {yyerrorex(syntaxerror, "缺少 ')'"); $$.ty = $2.ty;}
      
      // incomplete expressions 
      | expr LEQ { checkcomparisonsimple($1.ty); yyerrorex(syntaxerror, "比较运算符 <= 缺少表达式"); $$.ty = gBoolean; }
      | expr GEQ { checkcomparisonsimple($1.ty); yyerrorex(syntaxerror, "比较运算符 >= 缺少表达式"); $$.ty = gBoolean; }
      | expr LESS { checkcomparisonsimple($1.ty); yyerrorex(syntaxerror, "比较运算符 < 缺少表达式"); $$.ty = gBoolean; }
      | expr GREATER { checkcomparisonsimple($1.ty); yyerrorex(syntaxerror, "比较运算符 > 缺少表达式"); $$.ty = gBoolean; }
      | expr EQCOMP { yyerrorex(syntaxerror, "比较运算符 == 缺少表达式"); $$.ty = gBoolean; }
      | expr NEQ { yyerrorex(syntaxerror, "比较运算符 != 缺少表达式"); $$.ty = gBoolean; }
      | expr AND { canconvert($1.ty, gBoolean, 0); yyerrorex(syntaxerror, "逻辑运算符 and 缺少表达式"); $$.ty = gBoolean; }
      | expr OR { canconvert($1.ty, gBoolean, 0); yyerrorex(syntaxerror, "逻辑运算符 or 缺少表达式"); $$.ty = gBoolean; }
      | NOT { yyerrorex(syntaxerror, "逻辑运算符 not 缺少表达式"); $$.ty = gBoolean; }
;

funccall: rid LPAREN exprlistcompl RPAREN {
        $$ = checkfunccall($1.str, $3.pl);    
    }
    |  rid LPAREN exprlistcompl newline {
        yyerrorex(syntaxerror, "缺少 ')'");
        $$ = checkfunccall($1.str, $3.pl);
    }
;

exprlistcompl: /* empty */ { $$.pl = newparamlist(); }
       | exprlist { $$.pl = $1.pl; }
;

exprlist: expr         { $$.pl = newparamlist(); addParam($$.pl, newtypeandname($1.ty, "")); }
       |  expr COMMA exprlist { $$.pl = $3.pl; addParam($$.pl, newtypeandname($1.ty, "")); }
;


stringexpr: STRINGLIT { $$.ty = gString; }
;

realexpr: REALLIT { $$.ty = gReal; }
;

boolexpr: boollit { $$.ty = gBoolean; }
;

boollit: TTRUE
       | TFALSE
;

intexpr:   INTLIT { $$.ty = gInteger; }
         | UNITTYPEINT { $$.ty = gInteger; }
;


funcdecl: nativefuncdecl { $$.fd = $1.fd; }
         | CONSTANT nativefuncdecl { $$.fd = $2.fd; }
         | funcdefncore { $$.fd = $1.fd; }
;

nativefuncdecl: NATIVE rid TAKES optparam_list RETURNS opttype
{
    if (ht_lookup(&locals, $2.str) || ht_lookup(&params, $2.str) || ht_lookup(&globals, $2.str)) {
        char buf[1024];
        snprintf(buf, 1024, "%s 已经被定义为变量", $2.str);
        yyerrorex(semanticerror, buf);
    } else if (ht_lookup(&types, $2.str)) {
        char buf[1024];
        snprintf(buf, 1024, "%s 已经被定义为类型", $2.str);
        yyerrorex(semanticerror, buf);
    }
    $$.fd = newfuncdecl(); 
    $$.fd->name = strdup($2.str);
    $$.fd->p = $4.pl;
    $$.fd->ret = $6.ty;
    $$.fd->isconst = isconstant;

    put(&functions, $$.fd->name, $$.fd);

    if( !strcmp("Filter", $$.fd->name) ){
        fFilter = $$.fd;
    }else if( !strcmp("Condition", $$.fd->name) ){
        fCondition = $$.fd;
    }

}
;

funcdefn: newline
       | funcdefncore
       | statement { yyerrorex(syntaxerror, "语句必须写在函数内"); }
;

funcdefncore: funcbegin localblock codeblock funcend {
            if(retval != gNothing) {
                if(!getTypeTag($3.ty))
                    yyerrorline(semanticerror, lineno - 1, "缺少 return");
                else if ( !flagenabled(flag_rb) )
                    canconvertreturn($3.ty, retval, -1);
            }
            fnannotations = 0;
        }
       | funcbegin localblock codeblock {
            yyerrorex(syntaxerror, "缺少 endfunction");
            ht_clear(&params);
            ht_clear(&locals);
            ht_clear(&initialized);
            curtab = &globals;
            fnannotations = 0;
        }
;

funcend: ENDFUNCTION {
        ht_clear(&params);
        ht_clear(&locals);
        ht_clear(&initialized);
        curtab = &globals;
        inblock = 0;
        inconstant = 0;
        infunction = 0;
    }
;

returnorreturns: RETURNS
               | RETURN {yyerrorex(syntaxerror,"应该用 \"returns\" 而不是 \"return\"");}
;

funcbegin: FUNCTION rid TAKES optparam_list returnorreturns opttype {
        inconstant = 0;
        infunction = 1;
        $$ = checkfunctionheader($2.str, $4.pl, $6.ty);
        $$.fd->isconst = 0;
    }
    | CONSTANT FUNCTION rid TAKES optparam_list returnorreturns opttype {
        inconstant = 1;
        infunction = 1;
        $$ = checkfunctionheader($3.str, $5.pl, $7.ty);
        $$.fd->isconst = 1;
    }
;

codeblock: /* empty */ { $$.ty = gEmpty; }
       | statement codeblock {
            if(typeeq($2.ty, gEmpty))
                $$.ty = $1.ty;
            else
                $$.ty = mkretty($2.ty, getTypeTag($1.ty) || getTypeTag($2.ty) );
        }
;

statement:  newline { $$.ty = gEmpty; }
       | CALL funccall newline{ $$.ty = gAny;}
       /*1    2    3     4        5        6        7      8      9 */
       | IF expr THEN newline codeblock elsifseq elseseq ENDIF newline {
            canconvert($2.ty, gBoolean, -1);
            $$.ty = combinetype($5.ty, combinetype($6.ty, $7.ty));
       }
       | SET rid EQUALS expr newline { if (getVariable($2.str)->isarray) {
                                         char ebuf[1024];
                                         snprintf(ebuf, 1024, "数组变量 %s 缺少索引 ", $2.str);
                                         yyerrorline(semanticerror, lineno - 1,  ebuf);
                                       }
                                       canconvert($4.ty, getVariable($2.str)->ty, -1);
                                       $$.ty = gAny;
                                       if (getVariable($2.str)->isconst) {
                                         char ebuf[1024];
                                         snprintf(ebuf, 1024, "无法给常量 %s 赋值", $2.str);
                                         yyerrorline(semanticerror, lineno - 1, ebuf);
                                       }
                                       if (inconstant)
                                         validateGlobalAssignment($2.str);
                                       if(infunction && ht_lookup(curtab, $2.str) && !ht_lookup(&initialized, $2.str)){
                                         put(&initialized, $2.str, (void*)1);
                                       }
				    }
       | SET rid LBRACKET expr RBRACKET EQUALS expr newline{ 
           const struct typeandname *tan = getVariable($2.str);
           $$.ty = gAny;
           if (tan->ty != gAny) {
             canconvert($4.ty, gInteger, -1);
             if (!tan->isarray) {
               char ebuf[1024];
               snprintf(ebuf, 1024, "%s 不是数组", $2.str);
               yyerrorline(semanticerror, lineno - 1, ebuf);
             }
             canconvert($7.ty, tan->ty, -1);
             if (inconstant)
               validateGlobalAssignment($2.str);
             }
           }
       | loopstart newline codeblock loopend newline {$$.ty = $3.ty;}
       | loopstart newline codeblock {$$.ty = $3.ty; yyerrorex(syntaxerror, "Missing endloop");}
       | EXITWHEN expr newline { canconvert($2.ty, gBoolean, -1); if (!inloop) yyerrorline(syntaxerror, lineno - 1, "Exitwhen 不能在 loop 外使用"); $$.ty = gAny;}
       | RETURN expr newline {
            $$.ty = mkretty($2.ty, 1);
            if(retval == gNothing)
                yyerrorline(semanticerror, lineno - 1, "Return 不能有返回值，因为函数没有定义返回值");
            else if (! flagenabled(flag_rb) )
                canconvertreturn($2.ty, retval, 0);
         }
       | RETURN newline {
            if (retval != gNothing)
                yyerrorline(semanticerror, lineno - 1, "Return 不能没有返回值，因为函数定义了返回值");
                $$.ty = mkretty(gAny, 1);
            }
       | DEBUG statement {$$.ty = gAny;}
       /*1    2   3      4        5         6        7 */
       | IF expr THEN newline codeblock elsifseq elseseq {
            canconvert($2.ty, gBoolean, -1);
            $$.ty = combinetype($5.ty, combinetype($6.ty, $7.ty));
            yyerrorex(syntaxerror, "缺少 endif");
        }
       | IF expr newline {
            canconvert($2.ty, gBoolean, -1);
            $$.ty = gAny;
            yyerrorex(syntaxerror, "缺少 then 或 合法的表达式");
        }
       | SET funccall newline{ $$.ty = gAny; yyerrorline(semanticerror, lineno - 1, "应该用 call 而不是 set 来调用函数");}
       | lvardecl {
            $$.ty = gAny;
            yyerrorex(semanticerror, "局部变量定义必须在其他语句之前");
        }
       | error {$$.ty = gAny; }
;

loopstart: LOOP {inloop++;}
;

loopend: ENDLOOP {inloop--;}
;

elseseq: /* empty */ { $$.ty = gAny; }
        | ELSE newline codeblock {
            $$.ty = $3.ty;
        }
;

elsifseq: /* empty */ { $$.ty = mkretty(gEmpty, 1); }
        /*   1     2    3    4         5         6 */
        | ELSEIF expr THEN newline codeblock elsifseq {
            canconvert($2.ty, gBoolean, -1);
            
            if(typeeq($6.ty, gEmpty)){
                if(typeeq($5.ty, gEmpty)){
                    $$.ty = mkretty(gAny, 0);
                }else{
                    $$.ty = $5.ty;
                }
            }else{
                $$.ty = combinetype($5.ty, $6.ty);
            }
        }
;

optparam_list: param_list { $$.pl = $1.pl; }
               | NOTHING { $$.pl = newparamlist(); }
;

opttype: NOTHING { $$.ty = gNothing; }
         | type { $$.ty = $1.ty; }
;

param_list: typeandname { $$.pl = newparamlist(); addParam($$.pl, $1.tan); }
          | typeandname COMMA param_list { addParam($3.pl, $1.tan); $$.pl = $3.pl; }
;

rid: ID
{ $$.str = strdup(yytext); }
;

vartypedecl: type rid {
        struct typeandname *tan = newtypeandname($1.ty, $2.str);
        $$ = checkvardecl(tan);
    }
    | CONSTANT type rid {
        if (infunction) {
            yyerrorex(semanticerror, "局部变量不能是常量");
        }
        struct typeandname *tan = newtypeandname($2.ty, $3.str);
        tan->isconst = 1;
        $$ = checkvardecl(tan);
    }
    | type ARRAY rid {
        struct typeandname *tan = newtypeandname($1.ty, $3.str);
        tan->isarray = 1;
        $$ = checkarraydecl(tan);
  
    }

    // using "type" as variable name 
    | type TYPE {
        yyerrorex(syntaxerror, "非法的变量名 \"type\"");
        struct typeandname *tan = newtypeandname($1.ty, "type");
        $$ = checkvardecl(tan);
    }

    | CONSTANT type TYPE {
        if (infunction) {
            yyerrorex(semanticerror, "局部变量不能是常量");
        }
        yyerrorex(syntaxerror, "非法的变量名 \"type\"");
        struct typeandname *tan = newtypeandname($2.ty, "type");
        tan->isconst = 1;
        $$ = checkvardecl(tan);
    }
    | type ARRAY TYPE {
        yyerrorex(syntaxerror, "非法的变量名 \"type\"");
        struct typeandname *tan = newtypeandname($1.ty, "type");
        tan->isarray = 1;
        $$ = checkarraydecl(tan);

    }
;

localblock: endlocalsmarker
        | lvardecl localblock
        | newline localblock
;

endlocalsmarker: /* empty */ { fCurrent = NULL; }
;

lvardecl: LOCAL vardecl { }
        | CONSTANT LOCAL vardecl { yyerrorex(syntaxerror, "局部变量不能是常量"); }
        | typedef { yyerrorex(syntaxerror,"类型不能被定义在函数里"); }
;

vardecl: vartypedecl newline {
             const struct typeandname *tan = getVariable($1.str);
             if (tan->isconst) {
               yyerrorline(syntaxerror, lineno - 1, "常量必须初始化");
             }
             if(infunction && flagenabled(flag_shadowing) ){
                 if( ht_lookup(&globals, tan->name)){
                     char buf[1024];
                     snprintf(buf, 1024, "局部变量 %s 和全局变量重名", tan->name);
                     yyerrorline(semanticerror, lineno -1, buf);
                 } else if( ht_lookup(&params, tan->name)){
                     char buf[1024];
                     snprintf(buf, 1024, "局部变量 %s 和函数参数重名", tan->name);
                     yyerrorline(semanticerror, lineno -1, buf);
                 }
             }
             $$.ty = gNothing;
           }
        |  vartypedecl EQUALS expr newline {
             const struct typeandname *tan = getVariable($1.str);
             if (tan->isarray) {
               yyerrorex(syntaxerror, "数组不能直接初始化");
             }
             if(infunction && !ht_lookup(&initialized, tan->name)){
               put(&initialized, tan->name, (void*)1);
             }
             if(infunction && flagenabled(flag_shadowing) ){
                 if( ht_lookup(&globals, tan->name)){
                     char buf[1024];
                     snprintf(buf, 1024, "局部变量 %s 和全局变量重名", tan->name);
                     yyerrorex(semanticerror, buf);
                 } else if( ht_lookup(&params, tan->name)){
                     char buf[1024];
                     snprintf(buf, 1024, "局部变量 %s 和函数参数重名", tan->name);
                     yyerrorex(semanticerror, buf);
                 }
             }
             canconvert($3.ty, tan->ty, -1);
             $$.ty = gNothing;
           }
        | error
;

typedef: TYPE rid EXTENDS type {
  if (ht_lookup(&types, $2.str)) {
     char buf[1024];
     snprintf(buf, 1024, "类型 %s 重复定义", $2.str);
     yyerrorex(semanticerror, buf);
  } else if (ht_lookup(&functions, $2.str)) {
    char buf[1024];
    snprintf(buf, 1024, "%s 已经被定义为函数", $2.str);
    yyerrorex(semanticerror, buf);
  }
  else
    put(&types, $2.str, newtypenode($2.str, $4.ty));
}
;

typeandname: type rid { $$.tan = newtypeandname($1.ty, $2.str); }
;
  
type: primtype { $$.ty = $1.ty; }
  | rid {
   if (ht_lookup(&types, $1.str) == NULL) {
     char buf[1024];
     snprintf(buf, 1024, "类型 %s 未定义", $1.str);
     getsuggestions($1.str, buf, 1024, 1, &types);
     yyerrorex(semanticerror, buf);
     $$.ty = gAny;
   }
   else
     $$.ty = ht_lookup(&types, $1.str);
}
;

primtype: HANDLE  { $$.ty = ht_lookup(&types, yytext); }
 | INTEGER        { $$.ty = ht_lookup(&types, yytext); }
 | REAL           { $$.ty = ht_lookup(&types, yytext); }
 | BOOLEAN        { $$.ty = ht_lookup(&types, yytext); }
 | STRING         { $$.ty = ht_lookup(&types, yytext); }
 | CODE           { $$.ty = ht_lookup(&types, yytext); }
;

newline: NEWLINE { annotations = 0; }
       | ANNOTATION { annotations = updateannotation(annotations, yytext, &available_flags); }
;
