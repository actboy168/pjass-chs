/* A Bison parser, made by GNU Bison 2.4.2.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C
   
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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "2.4.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1

/* Using locations.  */
#define YYLSP_NEEDED 0



/* Copy the first part of user declarations.  */

/* Line 189 of yacc.c  */
#line 6 "grammar.y"


#include <stdio.h>
#include <string.h>
#include "token.yy.h"
#include "misc.h"


#define YYSTYPE union node
#define YYMAXDEPTH 100000
#define YYDEBUG 1



/* Line 189 of yacc.c  */
#line 87 "grammar.tab.c"

/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif


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


/* Copy the second part of user declarations.  */


/* Line 264 of yacc.c  */
#line 191 "grammar.tab.c"

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(e) ((void) (e))
#else
# define YYUSE(e) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(n) (n)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int yyi)
#else
static int
YYID (yyi)
    int yyi;
#endif
{
  return yyi;
}
#endif

#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef _STDLIB_H
#      define _STDLIB_H 1
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined _STDLIB_H \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef _STDLIB_H
#    define _STDLIB_H 1
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
	 || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T yyi;				\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (YYID (0))
#  endif
# endif

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)				\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack_alloc, Stack, yysize);			\
	Stack = &yyptr->Stack_alloc;					\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  26
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   613

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  63
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  49
/* YYNRULES -- Number of rules.  */
#define YYNRULES  145
/* YYNRULES -- Number of states.  */
#define YYNSTATES  234

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   317

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     8,    10,    13,    15,    17,    18,    21,
      22,    28,    33,    34,    35,    38,    40,    42,    43,    46,
      48,    50,    51,    54,    56,    58,    60,    62,    64,    66,
      69,    71,    75,    79,    83,    87,    91,    95,    99,   103,
     106,   110,   114,   118,   122,   125,   129,   131,   136,   138,
     142,   145,   148,   151,   154,   157,   160,   163,   166,   169,
     171,   176,   181,   182,   184,   186,   190,   192,   194,   196,
     198,   200,   202,   204,   206,   209,   211,   218,   220,   222,
     224,   229,   233,   235,   237,   239,   246,   254,   255,   258,
     260,   264,   274,   280,   289,   295,   299,   303,   307,   310,
     313,   321,   325,   329,   331,   333,   335,   337,   338,   342,
     343,   350,   352,   354,   356,   358,   360,   364,   366,   369,
     373,   377,   380,   384,   388,   390,   393,   396,   397,   400,
     404,   406,   409,   414,   416,   421,   424,   426,   428,   430,
     432,   434,   436,   438,   440,   442
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      64,     0,    -1,    65,    68,    65,    67,    -1,    66,    -1,
      65,    66,    -1,    74,    -1,    72,    -1,    -1,    67,    87,
      -1,    -1,     9,   111,    70,    10,    69,    -1,     9,    70,
      10,    69,    -1,    -1,    -1,    71,    70,    -1,   111,    -1,
     106,    -1,    -1,    73,    72,    -1,   111,    -1,    85,    -1,
      -1,    75,    74,    -1,   111,    -1,   107,    -1,    84,    -1,
      81,    -1,    80,    -1,    82,    -1,    15,   101,    -1,    30,
      -1,    76,    54,    76,    -1,    76,    55,    76,    -1,    76,
      52,    76,    -1,    76,    53,    76,    -1,    76,    56,    76,
      -1,    76,    57,    76,    -1,    76,    41,    76,    -1,    76,
      42,    76,    -1,    29,    76,    -1,    76,    44,    76,    -1,
      76,    45,    76,    -1,    76,    47,    76,    -1,    76,    46,
      76,    -1,    47,    76,    -1,    48,    76,    49,    -1,    77,
      -1,   101,    50,    76,    51,    -1,   101,    -1,    76,    43,
      76,    -1,    48,    76,    -1,    76,    54,    -1,    76,    55,
      -1,    76,    52,    -1,    76,    53,    -1,    76,    56,    -1,
      76,    57,    -1,    76,    41,    -1,    76,    42,    -1,    29,
      -1,   101,    48,    78,    49,    -1,   101,    48,    78,   111,
      -1,    -1,    79,    -1,    76,    -1,    76,    40,    79,    -1,
      58,    -1,    60,    -1,    83,    -1,    31,    -1,    32,    -1,
      59,    -1,    61,    -1,    86,    -1,    11,    86,    -1,    88,
      -1,    12,   101,    13,    98,    14,    99,    -1,   111,    -1,
      88,    -1,    93,    -1,    91,   103,    92,    89,    -1,    91,
     103,    92,    -1,    16,    -1,    14,    -1,    26,    -1,    15,
     101,    13,    98,    90,    99,    -1,    11,    15,   101,    13,
      98,    90,    99,    -1,    -1,    93,    92,    -1,   111,    -1,
      20,    77,   111,    -1,     3,    76,     4,   111,    92,    97,
      96,    23,   111,    -1,    19,   101,    43,    76,   111,    -1,
      19,   101,    50,    76,    51,    43,    76,   111,    -1,    94,
     111,    92,    95,   111,    -1,    94,   111,    92,    -1,    25,
      76,   111,    -1,    26,    76,   111,    -1,    26,   111,    -1,
      27,    93,    -1,     3,    76,     4,   111,    92,    97,    96,
      -1,     3,    76,   111,    -1,    19,    77,   111,    -1,   105,
      -1,     1,    -1,    24,    -1,    28,    -1,    -1,    21,   111,
      92,    -1,    -1,    22,    76,     4,   111,    92,    97,    -1,
     100,    -1,    38,    -1,    38,    -1,   109,    -1,   108,    -1,
     108,    40,   100,    -1,    39,    -1,   109,   101,    -1,    11,
     109,   101,    -1,   109,    18,   101,    -1,   109,     5,    -1,
      11,   109,     5,    -1,   109,    18,     5,    -1,   104,    -1,
     105,   103,    -1,   111,   103,    -1,    -1,    17,   106,    -1,
      11,    17,   106,    -1,   107,    -1,   102,   111,    -1,   102,
      43,    76,   111,    -1,     1,    -1,     5,   101,     6,   109,
      -1,   109,   101,    -1,   110,    -1,   101,    -1,     7,    -1,
      35,    -1,    36,    -1,    37,    -1,    34,    -1,    33,    -1,
       8,    -1,    62,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    93,    93,    96,    97,   100,   101,   104,   105,   108,
     109,   110,   113,   116,   117,   120,   121,   124,   125,   128,
     129,   132,   133,   136,   137,   141,   142,   143,   144,   145,
     165,   166,   167,   168,   169,   170,   171,   172,   173,   174,
     175,   176,   177,   178,   183,   184,   185,   186,   200,   223,
     224,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     238,   241,   247,   248,   251,   252,   256,   259,   262,   265,
     266,   269,   270,   274,   275,   276,   279,   307,   308,   309,
     312,   321,   331,   342,   343,   346,   352,   360,   361,   369,
     370,   372,   376,   394,   409,   410,   411,   412,   419,   424,
     426,   431,   436,   437,   441,   444,   447,   450,   451,   456,
     458,   473,   474,   477,   478,   481,   482,   485,   489,   493,
     501,   509,   515,   524,   533,   534,   535,   538,   541,   542,
     543,   546,   564,   586,   589,   604,   607,   608,   621,   622,
     623,   624,   625,   626,   629,   630
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "IF", "THEN", "TYPE", "EXTENDS",
  "HANDLE", "NEWLINE", "GLOBALS", "ENDGLOBALS", "CONSTANT", "NATIVE",
  "TAKES", "RETURNS", "FUNCTION", "ENDFUNCTION", "LOCAL", "ARRAY", "SET",
  "CALL", "ELSE", "ELSEIF", "ENDIF", "LOOP", "EXITWHEN", "RETURN", "DEBUG",
  "ENDLOOP", "NOT", "TNULL", "TTRUE", "TFALSE", "CODE", "STRING",
  "INTEGER", "REAL", "BOOLEAN", "NOTHING", "ID", "COMMA", "AND", "OR",
  "EQUALS", "TIMES", "DIV", "PLUS", "MINUS", "LPAREN", "RPAREN",
  "LBRACKET", "RBRACKET", "LESS", "GREATER", "LEQ", "GEQ", "EQCOMP", "NEQ",
  "STRINGLIT", "INTLIT", "REALLIT", "UNITTYPEINT", "ANNOTATION", "$accept",
  "program", "topscopes", "topscope", "funcdefns", "globdefs",
  "endglobalsmarker", "vardecls", "vd", "funcdecls", "fd", "typedefs",
  "td", "expr", "funccall", "exprlistcompl", "exprlist", "stringexpr",
  "realexpr", "boolexpr", "boollit", "intexpr", "funcdecl",
  "nativefuncdecl", "funcdefn", "funcdefncore", "funcend",
  "returnorreturns", "funcbegin", "codeblock", "statement", "loopstart",
  "loopend", "elseseq", "elsifseq", "optparam_list", "opttype",
  "param_list", "rid", "vartypedecl", "localblock", "endlocalsmarker",
  "lvardecl", "vardecl", "typedef", "typeandname", "type", "primtype",
  "newline", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    63,    64,    65,    65,    66,    66,    67,    67,    68,
      68,    68,    69,    70,    70,    71,    71,    72,    72,    73,
      73,    74,    74,    75,    75,    76,    76,    76,    76,    76,
      76,    76,    76,    76,    76,    76,    76,    76,    76,    76,
      76,    76,    76,    76,    76,    76,    76,    76,    76,    76,
      76,    76,    76,    76,    76,    76,    76,    76,    76,    76,
      77,    77,    78,    78,    79,    79,    80,    81,    82,    83,
      83,    84,    84,    85,    85,    85,    86,    87,    87,    87,
      88,    88,    89,    90,    90,    91,    91,    92,    92,    93,
      93,    93,    93,    93,    93,    93,    93,    93,    93,    93,
      93,    93,    93,    93,    93,    94,    95,    96,    96,    97,
      97,    98,    98,    99,    99,   100,   100,   101,   102,   102,
     102,   102,   102,   102,   103,   103,   103,   104,   105,   105,
     105,   106,   106,   106,   107,   108,   109,   109,   110,   110,
     110,   110,   110,   110,   111,   111
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     4,     1,     2,     1,     1,     0,     2,     0,
       5,     4,     0,     0,     2,     1,     1,     0,     2,     1,
       1,     0,     2,     1,     1,     1,     1,     1,     1,     2,
       1,     3,     3,     3,     3,     3,     3,     3,     3,     2,
       3,     3,     3,     3,     2,     3,     1,     4,     1,     3,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     1,
       4,     4,     0,     1,     1,     3,     1,     1,     1,     1,
       1,     1,     1,     1,     2,     1,     6,     1,     1,     1,
       4,     3,     1,     1,     1,     6,     7,     0,     2,     1,
       3,     9,     5,     8,     5,     3,     3,     3,     2,     2,
       7,     3,     3,     1,     1,     1,     1,     0,     3,     0,
       6,     1,     1,     1,     1,     1,     3,     1,     2,     3,
       3,     2,     3,     3,     1,     2,     2,     0,     2,     3,
       1,     2,     4,     1,     4,     2,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
      17,     0,   144,     0,     0,     0,   145,     0,     9,     3,
       6,    17,     5,    21,    20,    73,    75,   127,    24,    19,
     117,     0,     0,    74,     0,     0,     1,     0,     4,    17,
      18,    19,    22,    23,     0,     0,     0,   124,   127,   130,
     127,     0,     0,     0,     0,   133,   138,     0,   143,   142,
     139,   140,   141,     0,     0,   137,     0,    16,     0,   136,
       0,     7,     0,   128,   104,     0,     0,     0,   105,     0,
       0,     0,    81,     0,     0,   103,    89,   125,   126,   134,
       0,   112,     0,   111,   115,     0,     0,     0,    12,    14,
      15,     0,   131,   121,     0,   118,     0,     0,   129,     0,
      59,    30,    69,    70,     0,     0,    66,    71,    67,    72,
       0,    46,    27,    26,    28,    68,    25,    48,     0,     0,
       0,     0,     0,     0,    98,    99,    82,    80,    88,     0,
       0,     0,     0,   135,    83,    84,     0,   122,   119,    11,
       0,   123,   120,    12,     0,     8,    78,    79,    77,    29,
      39,    44,    50,     0,    57,    58,     0,     0,     0,     0,
       0,    53,    54,    51,    52,    55,    56,   101,    62,     0,
     102,     0,     0,    90,    96,    97,    95,     0,   113,    76,
     114,   116,    85,   132,    10,    45,     0,    37,    38,    49,
      40,    41,    43,    42,    33,    34,    31,    32,    35,    36,
      64,     0,    63,     0,     0,     0,   106,     0,    86,   109,
       0,    60,    61,    47,    92,     0,    94,     0,   107,    65,
       0,     0,     0,   100,     0,     0,     0,     0,    93,     0,
     108,    91,   109,   110
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     7,     8,     9,    97,    29,   139,    53,    54,    10,
      11,    12,    13,   200,   111,   201,   202,   112,   113,   114,
     115,   116,    14,    15,   145,    16,   127,   136,    17,    72,
      73,    74,   207,   223,   218,    82,   179,    83,   117,    56,
      36,    37,    75,    57,    39,    84,    58,    59,    76
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -113
static const yytype_int16 yypact[] =
{
      47,   -35,  -113,    69,   -35,   -35,  -113,    35,    67,  -113,
    -113,    93,  -113,    25,  -113,  -113,  -113,    15,  -113,  -113,
    -113,    33,   -35,  -113,    54,    73,  -113,    11,  -113,    47,
    -113,  -113,  -113,  -113,    82,   198,   298,  -113,    15,  -113,
      15,   140,    94,   446,   446,  -113,  -113,   140,  -113,  -113,
    -113,  -113,  -113,    85,    11,  -113,     6,  -113,    78,  -113,
      11,    47,   198,  -113,  -113,   428,   -35,   -35,  -113,   428,
     182,   354,    96,   264,    28,  -113,  -113,  -113,  -113,  -113,
     446,  -113,   102,  -113,   105,   -35,    27,    32,  -113,  -113,
    -113,   428,  -113,  -113,    61,  -113,   138,   327,  -113,   -35,
     428,  -113,  -113,  -113,   428,   428,  -113,  -113,  -113,  -113,
     341,  -113,  -113,  -113,  -113,  -113,  -113,    76,    28,    87,
      28,    88,   367,   367,  -113,  -113,  -113,  -113,  -113,   264,
      27,   457,   140,  -113,  -113,  -113,   457,  -113,  -113,  -113,
     367,  -113,  -113,  -113,   126,  -113,  -113,  -113,  -113,  -113,
     121,    58,   475,    28,   428,   428,   428,   428,   428,   428,
     428,   428,   428,   428,   428,   428,   428,  -113,   428,   428,
    -113,   428,   428,  -113,  -113,  -113,   124,   457,  -113,  -113,
    -113,  -113,  -113,  -113,  -113,  -113,   264,   542,   556,   526,
    -113,  -113,    58,    58,   121,   121,   121,   121,   121,   121,
     458,    72,  -113,   492,   367,   509,  -113,    28,  -113,   127,
     428,  -113,  -113,  -113,  -113,   115,  -113,   428,   141,  -113,
     428,   395,    28,   136,   367,    28,   264,    28,  -113,   264,
    -113,  -113,   127,  -113
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -113,  -113,   134,     8,  -113,  -113,    37,   -26,  -113,   170,
    -113,   171,  -113,    91,    66,  -113,   -25,  -113,  -113,  -113,
    -113,  -113,  -113,   183,  -113,    90,  -113,    59,  -113,   -72,
     -46,  -113,  -113,  -113,   -44,   -37,  -112,    60,    84,  -113,
     132,  -113,    75,    29,     2,  -113,   -38,  -113,     0
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -88
static const yytype_int16 yytable[] =
{
      19,   128,    18,    79,    20,    85,    85,    86,    19,    87,
      18,    31,    45,    33,     2,    18,    28,    40,    46,     2,
       1,   -13,    47,     2,   182,   125,    34,    60,    89,    19,
       1,    18,    35,     2,    96,    26,     2,   137,    40,    41,
      40,   134,    85,   130,    48,    49,    50,    51,    52,    91,
      20,   147,     1,   135,    90,     2,    92,   176,     3,     4,
      90,    19,     5,    18,    63,   208,   141,    43,     6,    28,
     124,    20,     1,     6,   129,     2,    27,     6,     3,     4,
       2,     4,     5,    93,    22,    21,    44,     6,    24,    25,
       6,    98,    38,   180,    85,    88,    94,   148,   180,    62,
      20,     2,   157,   158,     3,     4,    42,    80,     5,     6,
     167,    55,   126,    38,   209,    38,   131,    20,   170,    55,
     173,   211,   174,   175,   168,    55,   169,    55,    55,     6,
     171,    55,   118,   120,     6,   168,   168,   172,    55,   180,
     183,    22,    95,    62,    55,   132,    55,    46,   143,   217,
     119,   121,   206,   186,   230,     6,   110,   232,   220,   227,
     122,   123,   222,    61,    55,   157,   158,   159,   160,   133,
      77,   138,    78,    48,    49,    50,    51,    52,   142,    20,
     184,    30,   140,   149,    32,   219,    23,   146,   233,   177,
       2,   150,   181,     0,     0,   151,   152,    99,     0,    45,
       0,   212,     0,     0,   214,    46,     0,   216,     0,    47,
       0,   100,   101,   102,   103,    55,    55,     0,     0,     0,
      55,    20,   226,     0,   228,   229,     0,   231,     0,   104,
     105,    48,    49,    50,    51,    52,     0,    20,     0,     0,
     106,   107,   108,   109,     6,   187,   188,   189,   190,   191,
     192,   193,   194,   195,   196,   197,   198,   199,     0,     0,
     203,    55,   204,   205,   -87,    64,     0,    65,     0,     1,
       0,     0,     2,   -87,     0,    34,   -87,     0,     0,   -87,
     -87,    35,     0,    66,    67,   -87,   -87,   -87,    68,    69,
      70,    71,   -87,     0,     0,     0,     0,     0,   -87,    64,
       0,    65,     0,     1,     0,     0,     2,   -87,   221,    34,
     -87,   224,     0,   -87,   -87,    35,     0,    66,    67,     0,
       0,     0,    68,    69,    70,    71,     6,    -2,    64,     0,
      65,     0,     1,     0,     0,     2,     0,     0,   144,     0,
       0,     0,     5,     0,    35,   153,    66,    67,     0,     2,
       0,    68,    69,    70,    71,    64,     0,    65,     0,     1,
       6,     0,     2,     0,     0,    34,     0,     0,     0,     0,
       0,    35,     0,    66,    67,     2,     0,     0,    68,    69,
      70,    71,   154,   155,   156,   157,   158,   159,   160,     6,
       0,     0,     0,   161,   162,   163,   164,   165,   166,   225,
       0,     0,     0,     6,     0,     0,     0,     0,   154,   155,
     156,   157,   158,   159,   160,     0,     6,     0,     0,   161,
     162,   163,   164,   165,   166,     0,     0,     0,     0,     6,
       0,     0,     0,     0,     0,     0,   154,   155,   156,   157,
     158,   159,   160,    99,     0,     0,     0,   161,   162,   163,
     164,   165,   166,    46,     0,     0,     0,   100,   101,   102,
     103,     0,     0,     0,    46,     0,     0,    20,     0,     0,
       0,     0,     0,     0,     0,   104,   105,     0,     0,    48,
      49,    50,    51,    52,    81,    20,   106,   107,   108,   109,
      48,    49,    50,    51,    52,   178,    20,     0,   210,   154,
     155,   156,   157,   158,   159,   160,     0,     0,     0,     0,
     161,   162,   163,   164,   165,   166,   154,   155,   156,   157,
     158,   159,   160,     0,   185,     0,     0,   161,   162,   163,
     164,   165,   166,   154,   155,   156,   157,   158,   159,   160,
       0,     0,     0,   213,   161,   162,   163,   164,   165,   166,
     154,   155,   156,   157,   158,   159,   160,     0,     0,     0,
     215,   161,   162,   163,   164,   165,   166,   154,   155,   156,
     157,   158,   159,   160,     0,     0,     0,     0,   161,   162,
     163,   164,   165,   166,   155,     0,   157,   158,   159,   160,
       0,     0,     0,     0,   161,   162,   163,   164,   165,   166,
     157,   158,   159,   160,     0,     0,     0,     0,   161,   162,
     163,   164,   165,   166
};

static const yytype_int16 yycheck[] =
{
       0,    73,     0,    41,    39,    43,    44,    44,     8,    47,
       8,    11,     1,    13,     8,    13,     8,    17,     7,     8,
       5,    10,    11,     8,   136,    71,    11,    27,    54,    29,
       5,    29,    17,     8,    60,     0,     8,     5,    38,     6,
      40,    14,    80,    80,    33,    34,    35,    36,    37,    43,
      39,    97,     5,    26,    54,     8,    56,   129,    11,    12,
      60,    61,    15,    61,    35,   177,     5,    13,    62,    61,
      70,    39,     5,    62,    74,     8,     9,    62,    11,    12,
       8,    12,    15,     5,    15,     1,    13,    62,     4,     5,
      62,    62,    17,   131,   132,    10,    18,    97,   136,    17,
      39,     8,    44,    45,    11,    12,    22,    13,    15,    62,
     110,    27,    16,    38,   186,    40,    14,    39,   118,    35,
     120,    49,   122,   123,    48,    41,    50,    43,    44,    62,
      43,    47,    66,    67,    62,    48,    48,    50,    54,   177,
     140,    15,    58,    17,    60,    40,    62,     7,    10,    22,
      66,    67,    28,   153,   226,    62,    65,   229,    43,    23,
      69,    70,    21,    29,    80,    44,    45,    46,    47,    85,
      38,    87,    40,    33,    34,    35,    36,    37,    94,    39,
     143,    11,    91,    99,    13,   210,     3,    97,   232,   130,
       8,   100,   132,    -1,    -1,   104,   105,    15,    -1,     1,
      -1,   201,    -1,    -1,   204,     7,    -1,   207,    -1,    11,
      -1,    29,    30,    31,    32,   131,   132,    -1,    -1,    -1,
     136,    39,   222,    -1,   224,   225,    -1,   227,    -1,    47,
      48,    33,    34,    35,    36,    37,    -1,    39,    -1,    -1,
      58,    59,    60,    61,    62,   154,   155,   156,   157,   158,
     159,   160,   161,   162,   163,   164,   165,   166,    -1,    -1,
     169,   177,   171,   172,     0,     1,    -1,     3,    -1,     5,
      -1,    -1,     8,     9,    -1,    11,    12,    -1,    -1,    15,
      16,    17,    -1,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    -1,    -1,    -1,    -1,    -1,     0,     1,
      -1,     3,    -1,     5,    -1,    -1,     8,     9,   217,    11,
      12,   220,    -1,    15,    16,    17,    -1,    19,    20,    -1,
      -1,    -1,    24,    25,    26,    27,    62,     0,     1,    -1,
       3,    -1,     5,    -1,    -1,     8,    -1,    -1,    11,    -1,
      -1,    -1,    15,    -1,    17,     4,    19,    20,    -1,     8,
      -1,    24,    25,    26,    27,     1,    -1,     3,    -1,     5,
      62,    -1,     8,    -1,    -1,    11,    -1,    -1,    -1,    -1,
      -1,    17,    -1,    19,    20,     8,    -1,    -1,    24,    25,
      26,    27,    41,    42,    43,    44,    45,    46,    47,    62,
      -1,    -1,    -1,    52,    53,    54,    55,    56,    57,     4,
      -1,    -1,    -1,    62,    -1,    -1,    -1,    -1,    41,    42,
      43,    44,    45,    46,    47,    -1,    62,    -1,    -1,    52,
      53,    54,    55,    56,    57,    -1,    -1,    -1,    -1,    62,
      -1,    -1,    -1,    -1,    -1,    -1,    41,    42,    43,    44,
      45,    46,    47,    15,    -1,    -1,    -1,    52,    53,    54,
      55,    56,    57,     7,    -1,    -1,    -1,    29,    30,    31,
      32,    -1,    -1,    -1,     7,    -1,    -1,    39,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    47,    48,    -1,    -1,    33,
      34,    35,    36,    37,    38,    39,    58,    59,    60,    61,
      33,    34,    35,    36,    37,    38,    39,    -1,    40,    41,
      42,    43,    44,    45,    46,    47,    -1,    -1,    -1,    -1,
      52,    53,    54,    55,    56,    57,    41,    42,    43,    44,
      45,    46,    47,    -1,    49,    -1,    -1,    52,    53,    54,
      55,    56,    57,    41,    42,    43,    44,    45,    46,    47,
      -1,    -1,    -1,    51,    52,    53,    54,    55,    56,    57,
      41,    42,    43,    44,    45,    46,    47,    -1,    -1,    -1,
      51,    52,    53,    54,    55,    56,    57,    41,    42,    43,
      44,    45,    46,    47,    -1,    -1,    -1,    -1,    52,    53,
      54,    55,    56,    57,    42,    -1,    44,    45,    46,    47,
      -1,    -1,    -1,    -1,    52,    53,    54,    55,    56,    57,
      44,    45,    46,    47,    -1,    -1,    -1,    -1,    52,    53,
      54,    55,    56,    57
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     5,     8,    11,    12,    15,    62,    64,    65,    66,
      72,    73,    74,    75,    85,    86,    88,    91,   107,   111,
      39,   101,    15,    86,   101,   101,     0,     9,    66,    68,
      72,   111,    74,   111,    11,    17,   103,   104,   105,   107,
     111,     6,   101,    13,    13,     1,     7,    11,    33,    34,
      35,    36,    37,    70,    71,   101,   102,   106,   109,   110,
     111,    65,    17,   106,     1,     3,    19,    20,    24,    25,
      26,    27,    92,    93,    94,   105,   111,   103,   103,   109,
      13,    38,    98,   100,   108,   109,    98,   109,    10,    70,
     111,    43,   111,     5,    18,   101,    70,    67,   106,    15,
      29,    30,    31,    32,    47,    48,    58,    59,    60,    61,
      76,    77,    80,    81,    82,    83,    84,   101,    77,   101,
      77,   101,    76,    76,   111,    93,    16,    89,    92,   111,
      98,    14,    40,   101,    14,    26,    90,     5,   101,    69,
      76,     5,   101,    10,    11,    87,    88,    93,   111,   101,
      76,    76,    76,     4,    41,    42,    43,    44,    45,    46,
      47,    52,    53,    54,    55,    56,    57,   111,    48,    50,
     111,    43,    50,   111,   111,   111,    92,    90,    38,    99,
     109,   100,    99,   111,    69,    49,   111,    76,    76,    76,
      76,    76,    76,    76,    76,    76,    76,    76,    76,    76,
      76,    78,    79,    76,    76,    76,    28,    95,    99,    92,
      40,    49,   111,    51,   111,    51,   111,    22,    97,    79,
      43,    76,    21,    96,    76,     4,   111,    23,   111,   111,
      92,   111,    92,    97
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  However,
   YYFAIL appears to be in use.  Nevertheless, it is formally deprecated
   in Bison 2.4.2's NEWS entry, where a plan to phase it out is
   discussed.  */

#define YYFAIL		goto yyerrlab
#if defined YYFAIL
  /* This is here to suppress warnings from the GCC cpp's
     -Wunused-macros.  Normally we don't worry about that warning, but
     some users do, and we want to make it easy for users to remove
     YYFAIL uses, which will produce warnings from Bison 2.5.  */
#endif

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      yytoken = YYTRANSLATE (yychar);				\
      YYPOPSTACK (1);						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (YYID (N))                                                    \
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (YYID (0))
#endif


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
#  define YY_LOCATION_PRINT(File, Loc)			\
     fprintf (File, "%d.%d-%d.%d",			\
	      (Loc).first_line, (Loc).first_column,	\
	      (Loc).last_line,  (Loc).last_column)
# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */

#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
	break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
#else
static void
yy_stack_print (yybottom, yytop)
    yytype_int16 *yybottom;
    yytype_int16 *yytop;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yyrule)
    YYSTYPE *yyvsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule); \
} while (YYID (0))

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef	YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif



#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
	switch (*++yyp)
	  {
	  case '\'':
	  case ',':
	    goto do_not_strip_quotes;

	  case '\\':
	    if (*++yyp != '\\')
	      goto do_not_strip_quotes;
	    /* Fall through.  */
	  default:
	    if (yyres)
	      yyres[yyn] = *yyp;
	    yyn++;
	    break;

	  case '"':
	    if (yyres)
	      yyres[yyn] = '\0';
	    return yyn;
	  }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into YYRESULT an error message about the unexpected token
   YYCHAR while in state YYSTATE.  Return the number of bytes copied,
   including the terminating null byte.  If YYRESULT is null, do not
   copy anything; just return the number of bytes that would be
   copied.  As a special case, return 0 if an ordinary "syntax error"
   message will do.  Return YYSIZE_MAXIMUM if overflow occurs during
   size calculation.  */
static YYSIZE_T
yysyntax_error (char *yyresult, int yystate, int yychar)
{
  int yyn = yypact[yystate];

  if (! (YYPACT_NINF < yyn && yyn <= YYLAST))
    return 0;
  else
    {
      int yytype = YYTRANSLATE (yychar);
      YYSIZE_T yysize0 = yytnamerr (0, yytname[yytype]);
      YYSIZE_T yysize = yysize0;
      YYSIZE_T yysize1;
      int yysize_overflow = 0;
      enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
      char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
      int yyx;

# if 0
      /* This is so xgettext sees the translatable formats that are
	 constructed on the fly.  */
      YY_("syntax error, unexpected %s");
      YY_("syntax error, unexpected %s, expecting %s");
      YY_("syntax error, unexpected %s, expecting %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s");
# endif
      char *yyfmt;
      char const *yyf;
      static char const yyunexpected[] = "syntax error, unexpected %s";
      static char const yyexpecting[] = ", expecting %s";
      static char const yyor[] = " or %s";
      char yyformat[sizeof yyunexpected
		    + sizeof yyexpecting - 1
		    + ((YYERROR_VERBOSE_ARGS_MAXIMUM - 2)
		       * (sizeof yyor - 1))];
      char const *yyprefix = yyexpecting;

      /* Start YYX at -YYN if negative to avoid negative indexes in
	 YYCHECK.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;

      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yycount = 1;

      yyarg[0] = yytname[yytype];
      yyfmt = yystpcpy (yyformat, yyunexpected);

      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
	if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
	  {
	    if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
	      {
		yycount = 1;
		yysize = yysize0;
		yyformat[sizeof yyunexpected - 1] = '\0';
		break;
	      }
	    yyarg[yycount++] = yytname[yyx];
	    yysize1 = yysize + yytnamerr (0, yytname[yyx]);
	    yysize_overflow |= (yysize1 < yysize);
	    yysize = yysize1;
	    yyfmt = yystpcpy (yyfmt, yyprefix);
	    yyprefix = yyor;
	  }

      yyf = YY_(yyformat);
      yysize1 = yysize + yystrlen (yyf);
      yysize_overflow |= (yysize1 < yysize);
      yysize = yysize1;

      if (yysize_overflow)
	return YYSIZE_MAXIMUM;

      if (yyresult)
	{
	  /* Avoid sprintf, as that infringes on the user's name space.
	     Don't have undefined behavior even if the translation
	     produced a string with the wrong number of "%s"s.  */
	  char *yyp = yyresult;
	  int yyi = 0;
	  while ((*yyp = *yyf) != '\0')
	    {
	      if (*yyp == '%' && yyf[1] == 's' && yyi < yycount)
		{
		  yyp += yytnamerr (yyp, yyarg[yyi++]);
		  yyf += 2;
		}
	      else
		{
		  yyp++;
		  yyf++;
		}
	    }
	}
      return yysize;
    }
}
#endif /* YYERROR_VERBOSE */


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  YYUSE (yyvaluep);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
	break;
    }
}

/* Prevent warnings from -Wmissing-prototypes.  */
#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */


/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;



/*-------------------------.
| yyparse or yypush_parse.  |
`-------------------------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{


    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       `yyss': related to states.
       `yyvs': related to semantic values.

       Refer to the stacks thru separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yytoken = 0;
  yyss = yyssa;
  yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */
  yyssp = yyss;
  yyvsp = yyvs;

  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
	/* Give user a chance to reallocate the stack.  Use copies of
	   these so that the &'s don't force the real ones into
	   memory.  */
	YYSTYPE *yyvs1 = yyvs;
	yytype_int16 *yyss1 = yyss;

	/* Each stack pointer address is followed by the size of the
	   data in use in that stack, in bytes.  This used to be a
	   conditional around just the two extra args, but that might
	   be undefined if yyoverflow is a macro.  */
	yyoverflow (YY_("memory exhausted"),
		    &yyss1, yysize * sizeof (*yyssp),
		    &yyvs1, yysize * sizeof (*yyvsp),
		    &yystacksize);

	yyss = yyss1;
	yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
	goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
	yystacksize = YYMAXDEPTH;

      {
	yytype_int16 *yyss1 = yyss;
	union yyalloc *yyptr =
	  (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
	if (! yyptr)
	  goto yyexhaustedlab;
	YYSTACK_RELOCATE (yyss_alloc, yyss);
	YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
	if (yyss1 != yyssa)
	  YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
		  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
	YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yyn == 0 || yyn == YYTABLE_NINF)
	goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  *++yyvsp = yylval;

  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     `$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 11:

/* Line 1464 of yacc.c  */
#line 110 "grammar.y"
    {yyerrorline(syntaxerror, lineno - 1, "Missing linebreak before global declaration");;}
    break;

  case 12:

/* Line 1464 of yacc.c  */
#line 113 "grammar.y"
    {afterendglobals = 1;;}
    break;

  case 25:

/* Line 1464 of yacc.c  */
#line 141 "grammar.y"
    { (yyval).ty = gInteger; ;}
    break;

  case 26:

/* Line 1464 of yacc.c  */
#line 142 "grammar.y"
    { (yyval).ty = gReal; ;}
    break;

  case 27:

/* Line 1464 of yacc.c  */
#line 143 "grammar.y"
    { (yyval).ty = gString; ;}
    break;

  case 28:

/* Line 1464 of yacc.c  */
#line 144 "grammar.y"
    { (yyval).ty = gBoolean; ;}
    break;

  case 29:

/* Line 1464 of yacc.c  */
#line 145 "grammar.y"
    { struct funcdecl *fd = ht_lookup(&functions, (yyvsp[(2) - (2)]).str);
                       if (fd == NULL) {
                           char ebuf[1024];
                           snprintf(ebuf, 1024, "Undefined function %s", (yyvsp[(2) - (2)]).str);
                           getsuggestions((yyvsp[(2) - (2)]).str, ebuf, 1024, 1, &functions);
                           yyerrorex(semanticerror, ebuf);
                           (yyval).ty = gCode;
                       } else {
                           if (fd->p->head != NULL) {
                               char ebuf[1024];
                               snprintf(ebuf, 1024, "Function %s must not take any arguments when used as code", (yyvsp[(2) - (2)]).str);
                               yyerrorex(semanticerror, ebuf);
                           }
                           if( fd->ret == gBoolean) {
                               (yyval).ty = gCodeReturnsBoolean;
                           } else {
                               (yyval).ty = gCodeReturnsNoBoolean;
                           }
                       }
                     ;}
    break;

  case 30:

/* Line 1464 of yacc.c  */
#line 165 "grammar.y"
    { (yyval).ty = gNull; ;}
    break;

  case 31:

/* Line 1464 of yacc.c  */
#line 166 "grammar.y"
    { checkcomparison((yyvsp[(1) - (3)]).ty, (yyvsp[(3) - (3)]).ty); (yyval).ty = gBoolean; ;}
    break;

  case 32:

/* Line 1464 of yacc.c  */
#line 167 "grammar.y"
    { checkcomparison((yyvsp[(1) - (3)]).ty, (yyvsp[(3) - (3)]).ty); (yyval).ty = gBoolean; ;}
    break;

  case 33:

/* Line 1464 of yacc.c  */
#line 168 "grammar.y"
    { checkcomparison((yyvsp[(1) - (3)]).ty, (yyvsp[(3) - (3)]).ty); (yyval).ty = gBoolean; ;}
    break;

  case 34:

/* Line 1464 of yacc.c  */
#line 169 "grammar.y"
    { checkcomparison((yyvsp[(1) - (3)]).ty, (yyvsp[(3) - (3)]).ty); (yyval).ty = gBoolean; ;}
    break;

  case 35:

/* Line 1464 of yacc.c  */
#line 170 "grammar.y"
    { checkeqtest((yyvsp[(1) - (3)]).ty, (yyvsp[(3) - (3)]).ty); (yyval).ty = gBoolean; ;}
    break;

  case 36:

/* Line 1464 of yacc.c  */
#line 171 "grammar.y"
    { checkeqtest((yyvsp[(1) - (3)]).ty, (yyvsp[(3) - (3)]).ty); (yyval).ty = gBoolean; ;}
    break;

  case 37:

/* Line 1464 of yacc.c  */
#line 172 "grammar.y"
    { canconvert((yyvsp[(1) - (3)]).ty, gBoolean, 0); canconvert((yyvsp[(3) - (3)]).ty, gBoolean, 0); (yyval).ty = gBoolean; ;}
    break;

  case 38:

/* Line 1464 of yacc.c  */
#line 173 "grammar.y"
    { canconvert((yyvsp[(1) - (3)]).ty, gBoolean, 0); canconvert((yyvsp[(3) - (3)]).ty, gBoolean, 0); (yyval).ty = gBoolean; ;}
    break;

  case 39:

/* Line 1464 of yacc.c  */
#line 174 "grammar.y"
    { canconvert((yyvsp[(2) - (2)]).ty, gBoolean, 0); (yyval).ty = gBoolean; ;}
    break;

  case 40:

/* Line 1464 of yacc.c  */
#line 175 "grammar.y"
    { (yyval).ty = binop((yyvsp[(1) - (3)]).ty, (yyvsp[(3) - (3)]).ty); ;}
    break;

  case 41:

/* Line 1464 of yacc.c  */
#line 176 "grammar.y"
    { (yyval).ty = binop((yyvsp[(1) - (3)]).ty, (yyvsp[(3) - (3)]).ty); ;}
    break;

  case 42:

/* Line 1464 of yacc.c  */
#line 177 "grammar.y"
    { (yyval).ty = binop((yyvsp[(1) - (3)]).ty, (yyvsp[(3) - (3)]).ty); ;}
    break;

  case 43:

/* Line 1464 of yacc.c  */
#line 178 "grammar.y"
    { 
                         if ((yyvsp[(1) - (3)]).ty == gString && (yyvsp[(3) - (3)]).ty == gString)
                           (yyval).ty = gString;
                         else
                           (yyval).ty = binop((yyvsp[(1) - (3)]).ty, (yyvsp[(3) - (3)]).ty); ;}
    break;

  case 44:

/* Line 1464 of yacc.c  */
#line 183 "grammar.y"
    { isnumeric((yyvsp[(2) - (2)]).ty); (yyval).ty = (yyvsp[(2) - (2)]).ty; ;}
    break;

  case 45:

/* Line 1464 of yacc.c  */
#line 184 "grammar.y"
    { (yyval).ty = (yyvsp[(2) - (3)]).ty; ;}
    break;

  case 46:

/* Line 1464 of yacc.c  */
#line 185 "grammar.y"
    { (yyval).ty = (yyvsp[(1) - (1)]).ty; ;}
    break;

  case 47:

/* Line 1464 of yacc.c  */
#line 186 "grammar.y"
    {
          const struct typeandname *tan = getVariable((yyvsp[(1) - (4)]).str);
          if (!typeeq(tan->ty, gAny)) {
            if (!tan->isarray) {
              char ebuf[1024];
              snprintf(ebuf, 1024, "%s not an array", (yyvsp[(1) - (4)]).str);
              yyerrorex(semanticerror, ebuf);
            }
            else {
              canconvert((yyvsp[(3) - (4)]).ty, gInteger, 0);
            }
          }
          (yyval).ty = tan->ty;
       ;}
    break;

  case 48:

/* Line 1464 of yacc.c  */
#line 200 "grammar.y"
    {
          const struct typeandname *tan = getVariable((yyvsp[(1) - (1)]).str);
          if (tan->lineno == lineno && tan->fn == fno) {
            char ebuf[1024];
            snprintf(ebuf, 1024, "Use of variable %s before its declaration", (yyvsp[(1) - (1)]).str);
            yyerrorex(semanticerror, ebuf);
          } else if (islinebreak && tan->lineno == lineno - 1 && tan->fn == fno) {
            char ebuf[1024];
            snprintf(ebuf, 1024, "Use of variable %s before its declaration", (yyvsp[(1) - (1)]).str);
            yyerrorline(semanticerror, lineno - 1, ebuf);
          } else if (tan->isarray) {
            char ebuf[1024];
            snprintf(ebuf, 1024, "Index missing for array variable %s", (yyvsp[(1) - (1)]).str);
            yyerrorex(semanticerror, ebuf);
          }
          if(infunction && ht_lookup(curtab, (yyvsp[(1) - (1)]).str) && !ht_lookup(&initialized, (yyvsp[(1) - (1)]).str) ){
            char ebuf[1024];
            snprintf(ebuf, 1024, "Variable %s is uninitialized", (yyvsp[(1) - (1)]).str);
            //yyerrorex(3, ebuf);
            yyerrorline(semanticerror, lineno - 1, ebuf);
          }
          (yyval).ty = tan->ty;
       ;}
    break;

  case 49:

/* Line 1464 of yacc.c  */
#line 223 "grammar.y"
    {yyerrorex(syntaxerror, "Single = in expression, should probably be =="); checkeqtest((yyvsp[(1) - (3)]).ty, (yyvsp[(3) - (3)]).ty); (yyval).ty = gBoolean;;}
    break;

  case 50:

/* Line 1464 of yacc.c  */
#line 224 "grammar.y"
    {yyerrorex(syntaxerror, "Mssing ')'"); (yyval).ty = (yyvsp[(2) - (2)]).ty;;}
    break;

  case 51:

/* Line 1464 of yacc.c  */
#line 227 "grammar.y"
    { checkcomparisonsimple((yyvsp[(1) - (2)]).ty); yyerrorex(syntaxerror, "Missing expression for comparison"); (yyval).ty = gBoolean; ;}
    break;

  case 52:

/* Line 1464 of yacc.c  */
#line 228 "grammar.y"
    { checkcomparisonsimple((yyvsp[(1) - (2)]).ty); yyerrorex(syntaxerror, "Missing expression for comparison"); (yyval).ty = gBoolean; ;}
    break;

  case 53:

/* Line 1464 of yacc.c  */
#line 229 "grammar.y"
    { checkcomparisonsimple((yyvsp[(1) - (2)]).ty); yyerrorex(syntaxerror, "Missing expression for comparison"); (yyval).ty = gBoolean; ;}
    break;

  case 54:

/* Line 1464 of yacc.c  */
#line 230 "grammar.y"
    { checkcomparisonsimple((yyvsp[(1) - (2)]).ty); yyerrorex(syntaxerror, "Missing expression for comparison"); (yyval).ty = gBoolean; ;}
    break;

  case 55:

/* Line 1464 of yacc.c  */
#line 231 "grammar.y"
    { yyerrorex(syntaxerror, "Missing expression for comparison"); (yyval).ty = gBoolean; ;}
    break;

  case 56:

/* Line 1464 of yacc.c  */
#line 232 "grammar.y"
    { yyerrorex(syntaxerror, "Missing expression for comparison"); (yyval).ty = gBoolean; ;}
    break;

  case 57:

/* Line 1464 of yacc.c  */
#line 233 "grammar.y"
    { canconvert((yyvsp[(1) - (2)]).ty, gBoolean, 0); yyerrorex(syntaxerror, "Missing expression for logical and"); (yyval).ty = gBoolean; ;}
    break;

  case 58:

/* Line 1464 of yacc.c  */
#line 234 "grammar.y"
    { canconvert((yyvsp[(1) - (2)]).ty, gBoolean, 0); yyerrorex(syntaxerror, "Missing expression for logical or"); (yyval).ty = gBoolean; ;}
    break;

  case 59:

/* Line 1464 of yacc.c  */
#line 235 "grammar.y"
    { yyerrorex(syntaxerror, "Missing expression for logical negation"); (yyval).ty = gBoolean; ;}
    break;

  case 60:

/* Line 1464 of yacc.c  */
#line 238 "grammar.y"
    {
        (yyval) = checkfunccall((yyvsp[(1) - (4)]).str, (yyvsp[(3) - (4)]).pl);    
    ;}
    break;

  case 61:

/* Line 1464 of yacc.c  */
#line 241 "grammar.y"
    {
        yyerrorex(syntaxerror, "Missing ')'");
        (yyval) = checkfunccall((yyvsp[(1) - (4)]).str, (yyvsp[(3) - (4)]).pl);
    ;}
    break;

  case 62:

/* Line 1464 of yacc.c  */
#line 247 "grammar.y"
    { (yyval).pl = newparamlist(); ;}
    break;

  case 63:

/* Line 1464 of yacc.c  */
#line 248 "grammar.y"
    { (yyval).pl = (yyvsp[(1) - (1)]).pl; ;}
    break;

  case 64:

/* Line 1464 of yacc.c  */
#line 251 "grammar.y"
    { (yyval).pl = newparamlist(); addParam((yyval).pl, newtypeandname((yyvsp[(1) - (1)]).ty, "")); ;}
    break;

  case 65:

/* Line 1464 of yacc.c  */
#line 252 "grammar.y"
    { (yyval).pl = (yyvsp[(3) - (3)]).pl; addParam((yyval).pl, newtypeandname((yyvsp[(1) - (3)]).ty, "")); ;}
    break;

  case 66:

/* Line 1464 of yacc.c  */
#line 256 "grammar.y"
    { (yyval).ty = gString; ;}
    break;

  case 67:

/* Line 1464 of yacc.c  */
#line 259 "grammar.y"
    { (yyval).ty = gReal; ;}
    break;

  case 68:

/* Line 1464 of yacc.c  */
#line 262 "grammar.y"
    { (yyval).ty = gBoolean; ;}
    break;

  case 71:

/* Line 1464 of yacc.c  */
#line 269 "grammar.y"
    { (yyval).ty = gInteger; ;}
    break;

  case 72:

/* Line 1464 of yacc.c  */
#line 270 "grammar.y"
    { (yyval).ty = gInteger; ;}
    break;

  case 73:

/* Line 1464 of yacc.c  */
#line 274 "grammar.y"
    { (yyval).fd = (yyvsp[(1) - (1)]).fd; ;}
    break;

  case 74:

/* Line 1464 of yacc.c  */
#line 275 "grammar.y"
    { (yyval).fd = (yyvsp[(2) - (2)]).fd; ;}
    break;

  case 75:

/* Line 1464 of yacc.c  */
#line 276 "grammar.y"
    { (yyval).fd = (yyvsp[(1) - (1)]).fd; ;}
    break;

  case 76:

/* Line 1464 of yacc.c  */
#line 280 "grammar.y"
    {
    if (ht_lookup(&locals, (yyvsp[(2) - (6)]).str) || ht_lookup(&params, (yyvsp[(2) - (6)]).str) || ht_lookup(&globals, (yyvsp[(2) - (6)]).str)) {
        char buf[1024];
        snprintf(buf, 1024, "%s already defined as variable", (yyvsp[(2) - (6)]).str);
        yyerrorex(semanticerror, buf);
    } else if (ht_lookup(&types, (yyvsp[(2) - (6)]).str)) {
        char buf[1024];
        snprintf(buf, 1024, "%s already defined as type", (yyvsp[(2) - (6)]).str);
        yyerrorex(semanticerror, buf);
    }
    (yyval).fd = newfuncdecl(); 
    (yyval).fd->name = strdup((yyvsp[(2) - (6)]).str);
    (yyval).fd->p = (yyvsp[(4) - (6)]).pl;
    (yyval).fd->ret = (yyvsp[(6) - (6)]).ty;
    (yyval).fd->isconst = isconstant;

    put(&functions, (yyval).fd->name, (yyval).fd);

    if( !strcmp("Filter", (yyval).fd->name) ){
        fFilter = (yyval).fd;
    }else if( !strcmp("Condition", (yyval).fd->name) ){
        fCondition = (yyval).fd;
    }

;}
    break;

  case 79:

/* Line 1464 of yacc.c  */
#line 309 "grammar.y"
    { yyerrorex(syntaxerror, "Statement outside of function"); ;}
    break;

  case 80:

/* Line 1464 of yacc.c  */
#line 312 "grammar.y"
    {
            if(retval != gNothing) {
                if(!getTypeTag((yyvsp[(3) - (4)]).ty))
                    yyerrorline(semanticerror, lineno - 1, "Missing return");
                else if ( flagenabled(flag_rb) )
                    canconvertreturn((yyvsp[(3) - (4)]).ty, retval, -1);
            }
            fnannotations = 0;
        ;}
    break;

  case 81:

/* Line 1464 of yacc.c  */
#line 321 "grammar.y"
    {
            yyerrorex(syntaxerror, "Missing endfunction");
            ht_clear(&params);
            ht_clear(&locals);
            ht_clear(&initialized);
            curtab = &globals;
            fnannotations = 0;
        ;}
    break;

  case 82:

/* Line 1464 of yacc.c  */
#line 331 "grammar.y"
    {
        ht_clear(&params);
        ht_clear(&locals);
        ht_clear(&initialized);
        curtab = &globals;
        inblock = 0;
        inconstant = 0;
        infunction = 0;
    ;}
    break;

  case 84:

/* Line 1464 of yacc.c  */
#line 343 "grammar.y"
    {yyerrorex(syntaxerror,"Expected \"returns\" instead of \"return\"");;}
    break;

  case 85:

/* Line 1464 of yacc.c  */
#line 346 "grammar.y"
    {
        inconstant = 0;
        infunction = 1;
        (yyval) = checkfunctionheader((yyvsp[(2) - (6)]).str, (yyvsp[(4) - (6)]).pl, (yyvsp[(6) - (6)]).ty);
        (yyval).fd->isconst = 0;
    ;}
    break;

  case 86:

/* Line 1464 of yacc.c  */
#line 352 "grammar.y"
    {
        inconstant = 1;
        infunction = 1;
        (yyval) = checkfunctionheader((yyvsp[(3) - (7)]).str, (yyvsp[(5) - (7)]).pl, (yyvsp[(7) - (7)]).ty);
        (yyval).fd->isconst = 1;
    ;}
    break;

  case 87:

/* Line 1464 of yacc.c  */
#line 360 "grammar.y"
    { (yyval).ty = gEmpty; ;}
    break;

  case 88:

/* Line 1464 of yacc.c  */
#line 361 "grammar.y"
    {
            if(typeeq((yyvsp[(2) - (2)]).ty, gEmpty))
                (yyval).ty = (yyvsp[(1) - (2)]).ty;
            else
                (yyval).ty = mkretty((yyvsp[(2) - (2)]).ty, getTypeTag((yyvsp[(1) - (2)]).ty) || getTypeTag((yyvsp[(2) - (2)]).ty) );
        ;}
    break;

  case 89:

/* Line 1464 of yacc.c  */
#line 369 "grammar.y"
    { (yyval).ty = gEmpty; ;}
    break;

  case 90:

/* Line 1464 of yacc.c  */
#line 370 "grammar.y"
    { (yyval).ty = gAny;;}
    break;

  case 91:

/* Line 1464 of yacc.c  */
#line 372 "grammar.y"
    {
            canconvert((yyvsp[(2) - (9)]).ty, gBoolean, -1);
            (yyval).ty = combinetype((yyvsp[(5) - (9)]).ty, combinetype((yyvsp[(6) - (9)]).ty, (yyvsp[(7) - (9)]).ty));
       ;}
    break;

  case 92:

/* Line 1464 of yacc.c  */
#line 376 "grammar.y"
    { if (getVariable((yyvsp[(2) - (5)]).str)->isarray) {
                                         char ebuf[1024];
                                         snprintf(ebuf, 1024, "Index missing for array variable %s", (yyvsp[(2) - (5)]).str);
                                         yyerrorline(semanticerror, lineno - 1,  ebuf);
                                       }
                                       canconvert((yyvsp[(4) - (5)]).ty, getVariable((yyvsp[(2) - (5)]).str)->ty, -1);
                                       (yyval).ty = gAny;
                                       if (getVariable((yyvsp[(2) - (5)]).str)->isconst) {
                                         char ebuf[1024];
                                         snprintf(ebuf, 1024, "Cannot assign to constant %s", (yyvsp[(2) - (5)]).str);
                                         yyerrorline(semanticerror, lineno - 1, ebuf);
                                       }
                                       if (inconstant)
                                         validateGlobalAssignment((yyvsp[(2) - (5)]).str);
                                       if(infunction && ht_lookup(curtab, (yyvsp[(2) - (5)]).str) && !ht_lookup(&initialized, (yyvsp[(2) - (5)]).str)){
                                         put(&initialized, (yyvsp[(2) - (5)]).str, (void*)1);
                                       }
				    ;}
    break;

  case 93:

/* Line 1464 of yacc.c  */
#line 394 "grammar.y"
    { 
           const struct typeandname *tan = getVariable((yyvsp[(2) - (8)]).str);
           (yyval).ty = gAny;
           if (tan->ty != gAny) {
             canconvert((yyvsp[(4) - (8)]).ty, gInteger, -1);
             if (!tan->isarray) {
               char ebuf[1024];
               snprintf(ebuf, 1024, "%s is not an array", (yyvsp[(2) - (8)]).str);
               yyerrorline(semanticerror, lineno - 1, ebuf);
             }
             canconvert((yyvsp[(7) - (8)]).ty, tan->ty, -1);
             if (inconstant)
               validateGlobalAssignment((yyvsp[(2) - (8)]).str);
             }
           ;}
    break;

  case 94:

/* Line 1464 of yacc.c  */
#line 409 "grammar.y"
    {(yyval).ty = (yyvsp[(3) - (5)]).ty;;}
    break;

  case 95:

/* Line 1464 of yacc.c  */
#line 410 "grammar.y"
    {(yyval).ty = (yyvsp[(3) - (3)]).ty; yyerrorex(syntaxerror, "Missing endloop");;}
    break;

  case 96:

/* Line 1464 of yacc.c  */
#line 411 "grammar.y"
    { canconvert((yyvsp[(2) - (3)]).ty, gBoolean, -1); if (!inloop) yyerrorline(syntaxerror, lineno - 1, "Exitwhen outside of loop"); (yyval).ty = gAny;;}
    break;

  case 97:

/* Line 1464 of yacc.c  */
#line 412 "grammar.y"
    {
            (yyval).ty = mkretty((yyvsp[(2) - (3)]).ty, 1);
            if(retval == gNothing)
                yyerrorline(semanticerror, lineno - 1, "Cannot return value from function that returns nothing");
            else if (! flagenabled(flag_rb) )
                canconvertreturn((yyvsp[(2) - (3)]).ty, retval, 0);
         ;}
    break;

  case 98:

/* Line 1464 of yacc.c  */
#line 419 "grammar.y"
    {
            if (retval != gNothing)
                yyerrorline(semanticerror, lineno - 1, "Return nothing in function that should return value");
                (yyval).ty = mkretty(gAny, 1);
            ;}
    break;

  case 99:

/* Line 1464 of yacc.c  */
#line 424 "grammar.y"
    {(yyval).ty = gAny;;}
    break;

  case 100:

/* Line 1464 of yacc.c  */
#line 426 "grammar.y"
    {
            canconvert((yyvsp[(2) - (7)]).ty, gBoolean, -1);
            (yyval).ty = combinetype((yyvsp[(5) - (7)]).ty, combinetype((yyvsp[(6) - (7)]).ty, (yyvsp[(7) - (7)]).ty));
            yyerrorex(syntaxerror, "Missing endif");
        ;}
    break;

  case 101:

/* Line 1464 of yacc.c  */
#line 431 "grammar.y"
    {
            canconvert((yyvsp[(2) - (3)]).ty, gBoolean, -1);
            (yyval).ty = gAny;
            yyerrorex(syntaxerror, "Missing then or non valid expression");
        ;}
    break;

  case 102:

/* Line 1464 of yacc.c  */
#line 436 "grammar.y"
    { (yyval).ty = gAny; yyerrorline(semanticerror, lineno - 1, "Call expected instead of set");;}
    break;

  case 103:

/* Line 1464 of yacc.c  */
#line 437 "grammar.y"
    {
            (yyval).ty = gAny;
            yyerrorex(semanticerror, "Local declaration after first statement");
        ;}
    break;

  case 104:

/* Line 1464 of yacc.c  */
#line 441 "grammar.y"
    {(yyval).ty = gAny; ;}
    break;

  case 105:

/* Line 1464 of yacc.c  */
#line 444 "grammar.y"
    {inloop++;;}
    break;

  case 106:

/* Line 1464 of yacc.c  */
#line 447 "grammar.y"
    {inloop--;;}
    break;

  case 107:

/* Line 1464 of yacc.c  */
#line 450 "grammar.y"
    { (yyval).ty = gAny; ;}
    break;

  case 108:

/* Line 1464 of yacc.c  */
#line 451 "grammar.y"
    {
            (yyval).ty = (yyvsp[(3) - (3)]).ty;
        ;}
    break;

  case 109:

/* Line 1464 of yacc.c  */
#line 456 "grammar.y"
    { (yyval).ty = mkretty(gEmpty, 1); ;}
    break;

  case 110:

/* Line 1464 of yacc.c  */
#line 458 "grammar.y"
    {
            canconvert((yyvsp[(2) - (6)]).ty, gBoolean, -1);
            
            if(typeeq((yyvsp[(6) - (6)]).ty, gEmpty)){
                if(typeeq((yyvsp[(5) - (6)]).ty, gEmpty)){
                    (yyval).ty = mkretty(gAny, 0);
                }else{
                    (yyval).ty = (yyvsp[(5) - (6)]).ty;
                }
            }else{
                (yyval).ty = combinetype((yyvsp[(5) - (6)]).ty, (yyvsp[(6) - (6)]).ty);
            }
        ;}
    break;

  case 111:

/* Line 1464 of yacc.c  */
#line 473 "grammar.y"
    { (yyval).pl = (yyvsp[(1) - (1)]).pl; ;}
    break;

  case 112:

/* Line 1464 of yacc.c  */
#line 474 "grammar.y"
    { (yyval).pl = newparamlist(); ;}
    break;

  case 113:

/* Line 1464 of yacc.c  */
#line 477 "grammar.y"
    { (yyval).ty = gNothing; ;}
    break;

  case 114:

/* Line 1464 of yacc.c  */
#line 478 "grammar.y"
    { (yyval).ty = (yyvsp[(1) - (1)]).ty; ;}
    break;

  case 115:

/* Line 1464 of yacc.c  */
#line 481 "grammar.y"
    { (yyval).pl = newparamlist(); addParam((yyval).pl, (yyvsp[(1) - (1)]).tan); ;}
    break;

  case 116:

/* Line 1464 of yacc.c  */
#line 482 "grammar.y"
    { addParam((yyvsp[(3) - (3)]).pl, (yyvsp[(1) - (3)]).tan); (yyval).pl = (yyvsp[(3) - (3)]).pl; ;}
    break;

  case 117:

/* Line 1464 of yacc.c  */
#line 486 "grammar.y"
    { (yyval).str = strdup(yytext); ;}
    break;

  case 118:

/* Line 1464 of yacc.c  */
#line 489 "grammar.y"
    {
        struct typeandname *tan = newtypeandname((yyvsp[(1) - (2)]).ty, (yyvsp[(2) - (2)]).str);
        (yyval) = checkvardecl(tan);
    ;}
    break;

  case 119:

/* Line 1464 of yacc.c  */
#line 493 "grammar.y"
    {
        if (infunction) {
            yyerrorex(semanticerror, "Local constants are not allowed");
        }
        struct typeandname *tan = newtypeandname((yyvsp[(2) - (3)]).ty, (yyvsp[(3) - (3)]).str);
        tan->isconst = 1;
        (yyval) = checkvardecl(tan);
    ;}
    break;

  case 120:

/* Line 1464 of yacc.c  */
#line 501 "grammar.y"
    {
        struct typeandname *tan = newtypeandname((yyvsp[(1) - (3)]).ty, (yyvsp[(3) - (3)]).str);
        tan->isarray = 1;
        (yyval) = checkarraydecl(tan);
  
    ;}
    break;

  case 121:

/* Line 1464 of yacc.c  */
#line 509 "grammar.y"
    {
        yyerrorex(syntaxerror, "Invalid variable name \"type\"");
        struct typeandname *tan = newtypeandname((yyvsp[(1) - (2)]).ty, "type");
        (yyval) = checkvardecl(tan);
    ;}
    break;

  case 122:

/* Line 1464 of yacc.c  */
#line 515 "grammar.y"
    {
        if (infunction) {
            yyerrorex(semanticerror, "Local constants are not allowed");
        }
        yyerrorex(syntaxerror, "Invalid variable name \"type\"");
        struct typeandname *tan = newtypeandname((yyvsp[(2) - (3)]).ty, "type");
        tan->isconst = 1;
        (yyval) = checkvardecl(tan);
    ;}
    break;

  case 123:

/* Line 1464 of yacc.c  */
#line 524 "grammar.y"
    {
        yyerrorex(syntaxerror, "Invalid variable name \"type\"");
        struct typeandname *tan = newtypeandname((yyvsp[(1) - (3)]).ty, "type");
        tan->isarray = 1;
        (yyval) = checkarraydecl(tan);

    ;}
    break;

  case 127:

/* Line 1464 of yacc.c  */
#line 538 "grammar.y"
    { fCurrent = NULL; ;}
    break;

  case 128:

/* Line 1464 of yacc.c  */
#line 541 "grammar.y"
    { ;}
    break;

  case 129:

/* Line 1464 of yacc.c  */
#line 542 "grammar.y"
    { yyerrorex(syntaxerror, "Local variables can not be declared constant"); ;}
    break;

  case 130:

/* Line 1464 of yacc.c  */
#line 543 "grammar.y"
    { yyerrorex(syntaxerror,"Types can not be extended inside functions"); ;}
    break;

  case 131:

/* Line 1464 of yacc.c  */
#line 546 "grammar.y"
    {
             const struct typeandname *tan = getVariable((yyvsp[(1) - (2)]).str);
             if (tan->isconst) {
               yyerrorline(syntaxerror, lineno - 1, "Constants must be initialized");
             }
             if(infunction && flagenabled(flag_shadowing) ){
                 if( ht_lookup(&globals, tan->name)){
                     char buf[1024];
                     snprintf(buf, 1024, "Local variable %s shadows global variable", tan->name);
                     yyerrorline(semanticerror, lineno -1, buf);
                 } else if( ht_lookup(&params, tan->name)){
                     char buf[1024];
                     snprintf(buf, 1024, "Local variable %s shadows parameter", tan->name);
                     yyerrorline(semanticerror, lineno -1, buf);
                 }
             }
             (yyval).ty = gNothing;
           ;}
    break;

  case 132:

/* Line 1464 of yacc.c  */
#line 564 "grammar.y"
    {
             const struct typeandname *tan = getVariable((yyvsp[(1) - (4)]).str);
             if (tan->isarray) {
               yyerrorex(syntaxerror, "Arrays cannot be directly initialized");
             }
             if(infunction && !ht_lookup(&initialized, tan->name)){
               put(&initialized, tan->name, (void*)1);
             }
             if(infunction && flagenabled(flag_shadowing) ){
                 if( ht_lookup(&globals, tan->name)){
                     char buf[1024];
                     snprintf(buf, 1024, "Local variable %s shadows global variable", tan->name);
                     yyerrorex(semanticerror, buf);
                 } else if( ht_lookup(&params, tan->name)){
                     char buf[1024];
                     snprintf(buf, 1024, "Local variable %s shadows parameter", tan->name);
                     yyerrorex(semanticerror, buf);
                 }
             }
             canconvert((yyvsp[(3) - (4)]).ty, tan->ty, -1);
             (yyval).ty = gNothing;
           ;}
    break;

  case 134:

/* Line 1464 of yacc.c  */
#line 589 "grammar.y"
    {
  if (ht_lookup(&types, (yyvsp[(2) - (4)]).str)) {
     char buf[1024];
     snprintf(buf, 1024, "Multiply defined type %s", (yyvsp[(2) - (4)]).str);
     yyerrorex(semanticerror, buf);
  } else if (ht_lookup(&functions, (yyvsp[(2) - (4)]).str)) {
    char buf[1024];
    snprintf(buf, 1024, "%s already defined as function", (yyvsp[(2) - (4)]).str);
    yyerrorex(semanticerror, buf);
  }
  else
    put(&types, (yyvsp[(2) - (4)]).str, newtypenode((yyvsp[(2) - (4)]).str, (yyvsp[(4) - (4)]).ty));
;}
    break;

  case 135:

/* Line 1464 of yacc.c  */
#line 604 "grammar.y"
    { (yyval).tan = newtypeandname((yyvsp[(1) - (2)]).ty, (yyvsp[(2) - (2)]).str); ;}
    break;

  case 136:

/* Line 1464 of yacc.c  */
#line 607 "grammar.y"
    { (yyval).ty = (yyvsp[(1) - (1)]).ty; ;}
    break;

  case 137:

/* Line 1464 of yacc.c  */
#line 608 "grammar.y"
    {
   if (ht_lookup(&types, (yyvsp[(1) - (1)]).str) == NULL) {
     char buf[1024];
     snprintf(buf, 1024, "Undefined type %s", (yyvsp[(1) - (1)]).str);
     getsuggestions((yyvsp[(1) - (1)]).str, buf, 1024, 1, &types);
     yyerrorex(semanticerror, buf);
     (yyval).ty = gAny;
   }
   else
     (yyval).ty = ht_lookup(&types, (yyvsp[(1) - (1)]).str);
;}
    break;

  case 138:

/* Line 1464 of yacc.c  */
#line 621 "grammar.y"
    { (yyval).ty = ht_lookup(&types, yytext); ;}
    break;

  case 139:

/* Line 1464 of yacc.c  */
#line 622 "grammar.y"
    { (yyval).ty = ht_lookup(&types, yytext); ;}
    break;

  case 140:

/* Line 1464 of yacc.c  */
#line 623 "grammar.y"
    { (yyval).ty = ht_lookup(&types, yytext); ;}
    break;

  case 141:

/* Line 1464 of yacc.c  */
#line 624 "grammar.y"
    { (yyval).ty = ht_lookup(&types, yytext); ;}
    break;

  case 142:

/* Line 1464 of yacc.c  */
#line 625 "grammar.y"
    { (yyval).ty = ht_lookup(&types, yytext); ;}
    break;

  case 143:

/* Line 1464 of yacc.c  */
#line 626 "grammar.y"
    { (yyval).ty = ht_lookup(&types, yytext); ;}
    break;

  case 144:

/* Line 1464 of yacc.c  */
#line 629 "grammar.y"
    { annotations = 0; ;}
    break;

  case 145:

/* Line 1464 of yacc.c  */
#line 630 "grammar.y"
    { annotations = updateannotation(annotations, yytext, &available_flags); ;}
    break;



/* Line 1464 of yacc.c  */
#line 2790 "grammar.tab.c"
      default: break;
    }
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
      {
	YYSIZE_T yysize = yysyntax_error (0, yystate, yychar);
	if (yymsg_alloc < yysize && yymsg_alloc < YYSTACK_ALLOC_MAXIMUM)
	  {
	    YYSIZE_T yyalloc = 2 * yysize;
	    if (! (yysize <= yyalloc && yyalloc <= YYSTACK_ALLOC_MAXIMUM))
	      yyalloc = YYSTACK_ALLOC_MAXIMUM;
	    if (yymsg != yymsgbuf)
	      YYSTACK_FREE (yymsg);
	    yymsg = (char *) YYSTACK_ALLOC (yyalloc);
	    if (yymsg)
	      yymsg_alloc = yyalloc;
	    else
	      {
		yymsg = yymsgbuf;
		yymsg_alloc = sizeof yymsgbuf;
	      }
	  }

	if (0 < yysize && yysize <= yymsg_alloc)
	  {
	    (void) yysyntax_error (yymsg, yystate, yychar);
	    yyerror (yymsg);
	  }
	else
	  {
	    yyerror (YY_("syntax error"));
	    if (yysize != 0)
	      goto yyexhaustedlab;
	  }
      }
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
	 error, discard it.  */

      if (yychar <= YYEOF)
	{
	  /* Return failure if at end of input.  */
	  if (yychar == YYEOF)
	    YYABORT;
	}
      else
	{
	  yydestruct ("Error: discarding",
		      yytoken, &yylval);
	  yychar = YYEMPTY;
	}
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule which action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (yyn != YYPACT_NINF)
	{
	  yyn += YYTERROR;
	  if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
	    {
	      yyn = yytable[yyn];
	      if (0 < yyn)
		break;
	    }
	}

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
	YYABORT;


      yydestruct ("Error: popping",
		  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  *++yyvsp = yylval;


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#if !defined(yyoverflow) || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
     yydestruct ("Cleanup: discarding lookahead",
		 yytoken, &yylval);
  /* Do not reclaim the symbols of the rule which action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
		  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}



