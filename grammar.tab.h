/* A Bison parser, made by GNU Bison 2.4.2.  */

/* Skeleton interface for Bison's Yacc-like parsers in C
   
      Copyright (C) 1984, 1989-1990, 2000-2006, 2009-2010 Free Software
   Foundation, Inc.
   
   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.
   
   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.
   
   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.
   
   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */


/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     IF = 258,
     THEN = 259,
     TYPE = 260,
     EXTENDS = 261,
     HANDLE = 262,
     NEWLINE = 263,
     GLOBALS = 264,
     ENDGLOBALS = 265,
     CONSTANT = 266,
     NATIVE = 267,
     TAKES = 268,
     RETURNS = 269,
     FUNCTION = 270,
     ENDFUNCTION = 271,
     LOCAL = 272,
     ARRAY = 273,
     SET = 274,
     CALL = 275,
     ELSE = 276,
     ELSEIF = 277,
     ENDIF = 278,
     LOOP = 279,
     EXITWHEN = 280,
     RETURN = 281,
     DEBUG = 282,
     ENDLOOP = 283,
     NOT = 284,
     TNULL = 285,
     TTRUE = 286,
     TFALSE = 287,
     CODE = 288,
     STRING = 289,
     INTEGER = 290,
     REAL = 291,
     BOOLEAN = 292,
     NOTHING = 293,
     ID = 294,
     COMMA = 295,
     AND = 296,
     OR = 297,
     EQUALS = 298,
     TIMES = 299,
     DIV = 300,
     PLUS = 301,
     MINUS = 302,
     LPAREN = 303,
     RPAREN = 304,
     LBRACKET = 305,
     RBRACKET = 306,
     LESS = 307,
     GREATER = 308,
     LEQ = 309,
     GEQ = 310,
     EQCOMP = 311,
     NEQ = 312,
     STRINGLIT = 313,
     INTLIT = 314,
     REALLIT = 315,
     UNITTYPEINT = 316,
     ANNOTATION = 317
   };
#endif



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE yylval;


