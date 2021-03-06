// Jass2 parser for bison/yacc
// by Rudi Cilibrasi
// Sun Jun  8 00:51:53 CEST 2003
// thanks to Jeff Pang for the handy documentation that this was based
// on at http://jass.sourceforge.net
// Released under the BSD license
#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <stdlib.h>
#include <stdint.h>

#include "misc.h"

int pjass_flags;

int fno;
int lineno;
int haderrors;
int ignorederrors;
int totlines;
int islinebreak;
int isconstant;
int inconstant;
int infunction;
int inblock;
int strict;
int returnbug;
int fnannotations;
int annotations;
int didparse;
int inloop;
int afterendglobals;
int *showerrorlevel;

struct hashtable functions;
struct hashtable globals;
struct hashtable locals;
struct hashtable params;
struct hashtable types;
struct hashtable initialized;

struct hashtable *curtab;

const struct typenode *retval;
const char *curfile;
struct typenode *gInteger, *gReal, *gBoolean, *gString, *gCode, *gHandle, *gNothing, *gNull, *gAny, *gNone, *gEmpty;
struct typenode *gCodeReturnsNoBoolean, *gCodeReturnsBoolean;
struct typenode *gEmpty;
struct funcdecl *fCurrent;
struct funcdecl *fFilter, *fCondition;


struct hashtable available_flags;

void yyerrorline (enum errortype type, int line, const char *s)
{
    if(flagenabled(flag_syntaxerror) && type == syntaxerror){
        ignorederrors++;
        return;
    }

    if(flagenabled(flag_semanticerror) && type == semanticerror){
        ignorederrors++;
        return;
    }

    haderrors++;
    printf ("%s:%d: %s\n", curfile, line, s);
}

void yyerrorex (enum errortype type, const char *s)
{
    yyerrorline(type, lineno, s);
}

void yyerror (const char *s)  /* Called by yyparse on error */
{
    yyerrorex(syntaxerror, s);
}

void put(struct hashtable *h, const char *name, void *val){
    if( !ht_put(h, name, val) ){
        char ebuf[1024];
        snprintf(ebuf, 1024, "标识符 %s 重复定义", name);
        yyerrorline(semanticerror, islinebreak ? lineno - 1 : lineno, ebuf);
    }
}


#define min(a, b) (((a) < (b)) ? (a) : (b))

int abs(int i){
    if(i < 0)
        return -i;
    return i;
}

static int editdistance(const char *s, const char *t, int cutoff){
    if(!strcmp(s, t)) return 0;

    int a = strlen(s);
    int b = strlen(t);

    if(a==0) return b;
    if(b==0) return a;

    if(abs(a-b) > cutoff){
        return cutoff + 1;
    }

    int *v[3];
    int i;
    for(i = 0; i != 3; i++) {
        v[i] = malloc(sizeof(int) * (size_t)(b+1));
    }

    for(i = 0; i != b+1; i++){
        v[0][i] = i;
    }

    int pcur;
    int ppcur;
    int cur = 1;
    for(i = 0; i != a; i++){
        cur = (cur+1) % 3;
        pcur = cur -1;
        if(pcur < 0) pcur += 3;
        ppcur = pcur -1;
        if(ppcur < 0) ppcur += 3;

        v[cur][0] = i + 1;

        int minDistance = INT_MAX;

        int j;
        for(j = 0; j != b; j++){
            int cost = (s[i] == t[j]) ? 0 : 1;

            v[cur][j+1] = min(v[cur][j] + 1, min(v[pcur][j+1] + 1, v[pcur][j] + cost));

            if(i > 0 && j > 0 && s[i] == t[j-1] && s[i-1] == t[j]){
                v[cur][j+1] = min(v[cur][j+1], v[ppcur][j-1] + cost);
            }

            if(v[cur][j+1] < minDistance){
                minDistance = v[cur][j+1];
            }
        }

        if(minDistance > cutoff){
            return cutoff + 1;
        }
    }
    pcur = cur -1;
    if(pcur < 0) pcur += 3;
    int d = v[pcur][b];
    for(i = 0; i != 3; i++)
        free(v[i]);
    return d;
}

void getsuggestions(const char *name, char *buff, size_t buffsize, int nTables, ...)
{
    va_list ap;

    int len = strlen(name);
    int cutoff = (int)((len+2)/4.0);
    int count = 0;

    struct {int distance; const char *name;} suggestions[3];
    int i;
    for(i = 0; i != 3; i++){
        suggestions[i].distance = INT_MAX;
        suggestions[i].name = NULL;
    }

    va_start(ap, nTables);

    
    for(i = 0; i != nTables; i++){
        struct hashtable *ht = va_arg(ap, struct hashtable*);
        
        size_t x;
        for(x = 0; x != ht->size; x++){
            if(ht->bucket[x].name){
                const struct typeandname *tan = ht->bucket[x].val;
                if(typeeq(tan->ty, gAny)){
                    continue;
                }

                int dist = editdistance(ht->bucket[x].name, name, cutoff);
                if(dist <= cutoff){
                    count++;
                    int j;
                    for(j = 0; j != 3; j++){
                        if(suggestions[j].distance > dist){
                            if(i == 0){
                                suggestions[2] = suggestions[1];
                                suggestions[1] = suggestions[0];
                            }else if(i == 1){
                                suggestions[2] = suggestions[1];
                            }
                            suggestions[j].distance = dist;
                            suggestions[j].name = ht->bucket[x].name;

                            break;
                        }
                    }

                }
            }
        }

    }
    va_end(ap);

    char hbuff[1024];
    if(count == 1){
        snprintf(hbuff, 1024, ". 或许你想要的是 %s", suggestions[0].name);
        strncat(buff, hbuff, buffsize);
    }else if(count == 2){
        snprintf(hbuff, 1024, ". 或许你想要的是 %s 或 %s", suggestions[0].name, suggestions[1].name);
        strncat(buff, hbuff, buffsize);
    }else if(count >= 3){
        snprintf(hbuff, 1024, ". 或许你想要的是 %s, %s 或 %s", suggestions[0].name, suggestions[1].name, suggestions[2].name);
        strncat(buff, hbuff, buffsize);
    }
}


const struct typeandname *getVariable(const char *varname)
{
    char ebuf[1024];
    struct typeandname *result;

    result = ht_lookup(&locals, varname);
    if (result) return result;

    result = ht_lookup(&params, varname);
    if (result) return result;

    result = ht_lookup(&globals, varname);
    if (result) return result;

    snprintf(ebuf, 1024, "变量 %s 没有定义", varname);
    getsuggestions(varname, ebuf, 1024, 3, &locals, &params, &globals);
    yyerrorline(semanticerror, islinebreak ? lineno - 1 : lineno, ebuf);

    // Store it as unidentified variable
    const struct typeandname *newtan = newtypeandname(gAny, varname);
    put(curtab, varname, (void*)newtan);
    if(infunction && !ht_lookup(&initialized, varname)){
        put(&initialized, varname, (void*)1);
    }
    return newtan;
}

void validateGlobalAssignment(const char *varname)
{
    char ebuf[1024];
    struct typeandname *result;
    result = ht_lookup(&globals, varname);
    if (result) {
        snprintf(ebuf, 1024, "在常量函数中，无法修改全局变量 %s ", varname);
        yyerrorline(semanticerror, lineno - 1, ebuf);
    }
}


void checkParameters(const struct funcdecl *fd, const struct paramlist *inp, bool mustretbool)
{
    const struct paramlist *func = fd->p;
    const struct typeandname *fi = func->head;
    const struct typeandname *pi = inp->head;
    while(true) {
        if (fi == NULL && pi == NULL)
            return;
        if (fi == NULL && pi != NULL) {
            char buf[1024];
            snprintf(buf, 1024, "函数 %s 的参数太多. ", fd->name);
            yyerrorex(semanticerror, buf);
            return;
        }
        if (fi != NULL && pi == NULL) {
            char buf[1024];
            snprintf(buf, 1024, "函数 %s 的参数太少. ", fd->name);
            strncat(buf, "还缺少: ", 1024);
            bool addComma = false;
            for(; fi; fi = fi->next){
                if(addComma){
                    strncat(buf, ", ", 1024);
                }
                strncat(buf, fi->name, 1024);
                addComma = true;
            }
            yyerrorex(semanticerror, buf);
            return;
        }
        char buf[1024];
        if(! canconvertbuf(buf, 1024, pi->ty, fi->ty )){
            char pbuf[1024];
            snprintf(pbuf, 1024, "，在调用函数 %s 时的参数 %s", fd->name, fi->name);
            strncat(buf, pbuf, 1024);
            yyerrorex(semanticerror, buf);
        }
        if(flagenabled(flag_filter) && mustretbool && typeeq(pi->ty, gCodeReturnsNoBoolean)){
            yyerrorex(semanticerror, "传递给 Filter 或 Condition 的函数的返回值必须是 boolean");
            return;
        }
        pi = pi->next;
        fi = fi->next;
    }
}
const struct typenode *binop(const struct typenode *a, const struct typenode *b)
{
    a = getPrimitiveAncestor(a);
    b = getPrimitiveAncestor(b);
    if (typeeq(a, gInteger) && typeeq(b, gInteger))
        return gInteger;
    if (typeeq(a, gAny))
        return b;
    if (typeeq(b, gAny))
        return a;
    if ((!typeeq(a, gInteger) && !typeeq(a, gReal)) || (!typeeq(b, gInteger) && !typeeq(b, gReal))) {
        yyerrorline(semanticerror, islinebreak ? lineno - 1 : lineno, "运算符两边的类型错误");
    }
    return gReal;
}

const struct typenode *combinetype(const struct typenode *n1, const struct typenode *n2)
{
    uint8_t ret = getTypeTag(n1) & getTypeTag(n2);
    if ((typeeq(n1, gNone)) || (typeeq(n2, gNone)))
        return mkretty(gNone, ret);
    if (typeeq(n1, n2))
        return mkretty(n1, ret);
    if (typeeq(n1, gNull))
        return mkretty(n2, ret);
    if (typeeq(n2, gNull))
        return mkretty(n1, ret);

    n1 = getPrimitiveAncestor(n1);
    n2 = getPrimitiveAncestor(n2);

    if (typeeq(n1, n2))
        return mkretty(n1, ret);
    if (typeeq(n1, gNull))
        return mkretty(n2, ret);
    if (typeeq(n2, gNull))
        return mkretty(n1, ret);
    if ((typeeq(n1, gInteger)) && (typeeq(n2, gReal)))
        return mkretty(gReal, ret);
    if ((typeeq(n1, gReal)) && (typeeq(n2, gInteger)))
        return mkretty(gInteger, ret);
    return mkretty(gNone, ret);
}

bool canconvertbuf(char *buf, size_t buflen, const struct typenode *ufrom, const struct typenode *uto)
{
    const struct typenode *from = ufrom, *to = uto;
    if (from == NULL || to == NULL)
        return true;
    if (typeeq(from, gAny) || typeeq(to, gAny))
        return true;
    if (isDerivedFrom(from, to))
        return true;
    if (getTypePtr(from)->typename == NULL || getTypePtr(to)->typename == NULL)
        return true;
    if (typeeq(from, gNone) || typeeq(to, gNone))
        return true;
    from = getPrimitiveAncestor(from);
    to = getPrimitiveAncestor(to);
    if (typeeq(from, gNull) && !typeeq(to, gInteger) && !typeeq(to, gReal) && !typeeq(to, gBoolean))
        return true;
    if (typeeq(from, gInteger) && (typeeq(to, gReal) || typeeq(to, gInteger)))
        return true;
    if (typeeq(from, to) && (typeeq(from, gBoolean) || typeeq(from, gString) || typeeq(from, gReal) || typeeq(from, gInteger) || typeeq(from, gCode)))
        return true;

    snprintf(buf, buflen, "无法将类型从 %s 转换为 %s", ufrom->typename, uto->typename);
    return false;
}

// this is used for reducing expressions in many places (if/exitwhen conditions, assignments etc.)
void canconvert(const struct typenode *ufrom, const struct typenode *uto, const int linemod)
{
    char buf[1024];
    if(! canconvertbuf(buf, 1024, ufrom, uto ) ){
        yyerrorline(semanticerror, lineno + linemod, buf);
    }
}

// this is used for return statements only
void canconvertreturn(const struct typenode *ufrom, const struct typenode *uto, const int linemod)
{
    const struct typenode *from = ufrom, *to = uto;
    char ebuf[1024];
    if(typeeq(from, NULL) || typeeq(to, NULL))
        return; // garbage

    if (typeeq(from, gAny) || typeeq(to, gAny))
        return; // we don't care

    if (isDerivedFrom(from, to))
        return; // eg. from = unit, to = handle

    if (getTypePtr(from)->typename == NULL || getTypePtr(to)->typename == NULL)
        return; // garbage

    if (typeeq(from, gNone) || typeeq(to, gNone))
        return; // garbage


    from = getPrimitiveAncestor(from);
    to = getPrimitiveAncestor(to);
    if ((typeeq(to, gReal)) && (typeeq(from, gInteger))) {
    //    // can't return integer when it expects a real (added 9.5.2005)
    //    snprintf(ebuf, 1024, "无法将返回值的类型从 %s 转换为 %s", getTypePtr(from)->typename, getTypePtr(to)->typename);
    //    yyerrorline(semanticerror, lineno + linemod, ebuf);
        return;
    }

    if ((typeeq(from, gNull)) && (!typeeq(to, gInteger)) && (!typeeq(to, gReal)) && (!typeeq(to, gBoolean)))
        return; // can't return null when it expects integer, real or boolean (added 9.5.2005)

    if (typeeq(ufrom, uto)){
        return;
    }

    snprintf(ebuf, 1024, "无法将返回值的类型从 %s 转换为 %s", getTypePtr(ufrom)->typename, getTypePtr(uto)->typename);
    yyerrorline(semanticerror, lineno + linemod, ebuf);
    return;
}

void isnumeric(const struct typenode *ty)
{
    ty = getPrimitiveAncestor(ty);
    if (!(ty == gInteger || ty == gReal || ty == gAny))
        yyerrorline(semanticerror, islinebreak ? lineno - 1 : lineno, "无法转换为数字");
}

void checkcomparisonsimple(const struct typenode *a)
{
    const struct typenode *pa;
    pa = getPrimitiveAncestor(a);
    if (typeeq(pa, gString) || typeeq(pa, gHandle) || typeeq(pa, gCode) || typeeq(pa, gBoolean)) {
        yyerrorex(semanticerror, "只能比较整数或者实数");
        return;
    }
    if (typeeq(pa, gNull))
        yyerrorex(semanticerror, "无法比较空值");
}

void checkcomparison(const struct typenode *a, const struct typenode *b)
{
    const struct typenode *pa, *pb;
    pa = getPrimitiveAncestor(a);
    pb = getPrimitiveAncestor(b);
    if (typeeq(pa, gString) || typeeq(pa, gHandle) || typeeq(pa, gCode) || typeeq(pa, gBoolean) || typeeq(pb, gString) || typeeq(pb, gCode) || typeeq(pb, gHandle) || typeeq(pb, gBoolean)) {
        yyerrorex(semanticerror, "只能比较整数或者实数");
        return;
    }
    if (typeeq(pa, gNull) && typeeq(pb, gNull))
        yyerrorex(semanticerror, "无法比较空值");
}

void checkeqtest(const struct typenode *a, const struct typenode *b)
{
    const struct typenode *pa, *pb;
    pa = getPrimitiveAncestor(a);
    pb = getPrimitiveAncestor(b);
    if ((typeeq(pa, gInteger) || typeeq(pa, gReal)) && (typeeq(pb, gInteger) || typeeq(pb, gReal)))
        return;
    if (typeeq(pa, gNull) || typeeq(pb, gNull))
        return;
    if (!typeeq(pa, pb)) {
        yyerrorex(semanticerror, "无法比较两个类型不同的变量(除了整数和实数)");
        return;
    }
}

int isflag(char *txt, struct hashtable *flags){
    txt++; // ignore +/- at the start
    void *flag = ht_lookup(flags, txt);
    return (int)flag;
}

int updateflag(int cur, char *txt, struct hashtable *flags){
    char sgn = txt[0];
    int flag = isflag(txt, flags);

    if( flag){
        if(sgn == '+') {
            cur |= flag;
        } else if(sgn == '-') {
            cur &= ~flag;
        }
    }
    return cur;
}

int updateannotation(int cur, char *txt, struct hashtable *flags){
    char sep[] = " \t\r\n";
    memset(txt, ' ', strlen("//#"));
    char *ann;
    for(ann = strtok(txt, sep); ann; ann = strtok(NULL, sep)){
        cur = updateflag(cur, ann, flags);
    }
    return cur;
}

bool flagenabled(int flag)
{
    return (pjass_flags & flag) || (fnannotations & flag);
}

union node checkfunctionheader(const char *fnname, struct paramlist *pl, const struct typenode *retty)
{
    union node ret;

    if (ht_lookup(&locals, fnname) || ht_lookup(&params, fnname) || ht_lookup(&globals, fnname)) {
        char buf[1024];
        snprintf(buf, 1024, "标识符 %s 已经被定义为变量", fnname);
        yyerrorex(semanticerror, buf);
    } else if (ht_lookup(&types, fnname)) {
        char buf[1024];
        snprintf(buf, 1024, "标识符 %s 已经被定义为类型", fnname);
        yyerrorex(semanticerror, buf);
    }

    curtab = &locals;
    ret.fd = newfuncdecl(); 
    ret.fd->name = strdup(fnname);
    ret.fd->p = pl;
    ret.fd->ret = retty;

    put(&functions, ret.fd->name, ret.fd);

    fCurrent = ht_lookup(&functions, fnname);
    fnannotations = annotations;

    struct typeandname *tan = pl->head;
    for (;tan; tan=tan->next) {
        tan->lineno = lineno;
        tan->fn = fno;
        put(&params, strdup(tan->name), newtypeandname(tan->ty, tan->name));
        if (ht_lookup(&functions, tan->name)) {
            char buf[1024];
            snprintf(buf, 1024, "标识符 %s 已经被定义为函数", tan->name);
            yyerrorex(semanticerror, buf);
        } else if (ht_lookup(&types, tan->name)) {
            char buf[1024];
            snprintf(buf, 1024, "标识符 %s 已经被定义为类型", tan->name);
            yyerrorex(semanticerror, buf);
        }

        if( flagenabled(flag_shadowing) ){
            if( ht_lookup(&globals, tan->name) ){
                char buf[1024];
                snprintf(buf, 1024, "参数 %s 和全局变量重名", tan->name);
                yyerrorex(semanticerror, buf);
            }
        }

    }
    retval = ret.fd->ret;
    inblock = 1;
    inloop = 0;

    return ret;
}

union node checkfunccall(const char *fnname, struct paramlist *pl)
{
    union node ret;
    struct funcdecl *fd = ht_lookup(&functions, fnname);
    if (fd == NULL) {
        char ebuf[1024];
        snprintf(ebuf, 1024, "函数 %s 没有定义", fnname);
        getsuggestions(fnname, ebuf, 1024, 1, &functions);
        yyerrorex(semanticerror, ebuf);
        ret.ty = gAny;
    } else {
        if (inconstant && !(fd->isconst)) {
            char ebuf[1024];
            snprintf(ebuf, 1024, "在常量函数中，无法调用非常量函数 %s ", fnname);
            yyerrorex(semanticerror, ebuf);
        }
        if (fd == fCurrent && fCurrent)
            yyerrorex(semanticerror, "不能在局部变量定义时，在递归调用函数");
        checkParameters(fd, pl, fd == fFilter || fd == fCondition);
        ret.ty = fd->ret;
    }
    return ret;
}

static void checkvarname(struct typeandname *tan, bool isarray)
{
    const char *name = tan->name;
    if (ht_lookup(&functions, name)) {
        char buf[1024];
        snprintf(buf, 1024, "标识符 %s 已经被定义为函数", name);
        yyerrorex(semanticerror, buf);
    } else if (ht_lookup(&types, name)) {
        char buf[1024];
        snprintf(buf, 1024, "标识符 %s 已经被定义为类型", name);
        yyerrorex(semanticerror, buf);
    }

    struct typeandname *existing = ht_lookup(&locals, name);

    if (!existing) {
        char buf[1024];
        existing = ht_lookup(&params, name);
        if ( isarray && infunction && existing) {
            snprintf(buf, 1024, "标识符 %s 已经被定义为函数参数", name);
            yyerrorex(semanticerror, buf);
        }
        if (!existing) {
            existing = ht_lookup(&globals, name);
            if ( isarray && infunction && existing) {
                snprintf(buf, 1024, "标识符 %s 已经被定义为全局变量", name);
                yyerrorex(semanticerror, buf);
            }
        }
    }
    if (existing) {
        tan->lineno = existing->lineno;
        tan->fn = existing->fn;
    } else {
        tan->lineno = lineno;
        tan->fn = fno;
    }
}

union node checkvardecl(struct typeandname *tan)
{
    const char *name = tan->name;
    union node ret;
    checkvarname(tan, false);

    ret.str = name;
    put(curtab, name, tan);

    return ret;
}

union node checkarraydecl(struct typeandname *tan)
{
    const char *name = tan->name;
    union node ret;

    if (getPrimitiveAncestor(tan->ty) == gCode)
        yyerrorex(semanticerror, "无法使用code数组");

    checkvarname(tan, true);

    ret.str = name;
    put(curtab, name, tan);

    return ret;
}
