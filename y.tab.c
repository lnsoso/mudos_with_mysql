/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C

   Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 51 Franklin Street, Fifth Floor,
   Boston, MA 02110-1301, USA.  */

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
#define YYBISON_VERSION "2.3"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Using locations.  */
#define YYLSP_NEEDED 0



/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     L_STRING = 258,
     L_NUMBER = 259,
     L_REAL = 260,
     L_BASIC_TYPE = 261,
     L_TYPE_MODIFIER = 262,
     L_DEFINED_NAME = 263,
     L_IDENTIFIER = 264,
     L_EFUN = 265,
     L_INC = 266,
     L_DEC = 267,
     L_ASSIGN = 268,
     L_LAND = 269,
     L_LOR = 270,
     L_LSH = 271,
     L_RSH = 272,
     L_ORDER = 273,
     L_NOT = 274,
     L_IF = 275,
     L_ELSE = 276,
     L_SWITCH = 277,
     L_CASE = 278,
     L_DEFAULT = 279,
     L_RANGE = 280,
     L_DOT_DOT_DOT = 281,
     L_WHILE = 282,
     L_DO = 283,
     L_FOR = 284,
     L_FOREACH = 285,
     L_IN = 286,
     L_BREAK = 287,
     L_CONTINUE = 288,
     L_RETURN = 289,
     L_ARROW = 290,
     L_INHERIT = 291,
     L_COLON_COLON = 292,
     L_ARRAY_OPEN = 293,
     L_MAPPING_OPEN = 294,
     L_FUNCTION_OPEN = 295,
     L_NEW_FUNCTION_OPEN = 296,
     L_SSCANF = 297,
     L_CATCH = 298,
     L_ARRAY = 299,
     L_REF = 300,
     L_PARSE_COMMAND = 301,
     L_TIME_EXPRESSION = 302,
     L_CLASS = 303,
     L_NEW = 304,
     L_PARAMETER = 305,
     LOWER_THAN_ELSE = 306,
     L_NE = 307,
     L_EQ = 308
   };
#endif
/* Tokens.  */
#define L_STRING 258
#define L_NUMBER 259
#define L_REAL 260
#define L_BASIC_TYPE 261
#define L_TYPE_MODIFIER 262
#define L_DEFINED_NAME 263
#define L_IDENTIFIER 264
#define L_EFUN 265
#define L_INC 266
#define L_DEC 267
#define L_ASSIGN 268
#define L_LAND 269
#define L_LOR 270
#define L_LSH 271
#define L_RSH 272
#define L_ORDER 273
#define L_NOT 274
#define L_IF 275
#define L_ELSE 276
#define L_SWITCH 277
#define L_CASE 278
#define L_DEFAULT 279
#define L_RANGE 280
#define L_DOT_DOT_DOT 281
#define L_WHILE 282
#define L_DO 283
#define L_FOR 284
#define L_FOREACH 285
#define L_IN 286
#define L_BREAK 287
#define L_CONTINUE 288
#define L_RETURN 289
#define L_ARROW 290
#define L_INHERIT 291
#define L_COLON_COLON 292
#define L_ARRAY_OPEN 293
#define L_MAPPING_OPEN 294
#define L_FUNCTION_OPEN 295
#define L_NEW_FUNCTION_OPEN 296
#define L_SSCANF 297
#define L_CATCH 298
#define L_ARRAY 299
#define L_REF 300
#define L_PARSE_COMMAND 301
#define L_TIME_EXPRESSION 302
#define L_CLASS 303
#define L_NEW 304
#define L_PARAMETER 305
#define LOWER_THAN_ELSE 306
#define L_NE 307
#define L_EQ 308




/* Copy the first part of user declarations.  */
#line 3 "grammar.y"


#include "std.h"
#include "compiler.h"
#include "lex.h"
#include "scratchpad.h"

#include "lpc_incl.h"
#include "simul_efun.h"
#include "generate.h"
#include "master.h"

/* gross. Necessary? - Beek */
#ifdef WIN32
#define MSDOS
#endif
#line 18 "grammar.y.pre"
/*
 * This is the grammar definition of LPC, and its parse tree generator.
 */

/* down to one global :) 
   bits:
      SWITCH_CONTEXT     - we're inside a switch
      LOOP_CONTEXT       - we're inside a loop
      SWITCH_STRINGS     - a string case has been found
      SWITCH_NUMBERS     - a non-zero numeric case has been found
      SWITCH_RANGES      - a range has been found
      SWITCH_DEFAULT     - a default has been found
 */
int context;
int num_refs;

/*
 * bison & yacc don't prototype this in y.tab.h
 */
int yyparse PROT((void));



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

#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 122 "grammar.y"
{
    POINTER_INT pointer_int;
    int number;
    float real;
    char *string;
    int type;
    struct { short num_arg; char flags; } argument;
    ident_hash_elem_t *ihe;
    parse_node_t *node;
    function_context_t *contextp;
    struct {
	parse_node_t *node;
        char num;
    } decl; /* 5 */
    struct {
	char num_local;
	char max_num_locals; 
	short context; 
	short save_current_type; 
	short save_exact_types;
    } func_block; /* 8 */
}
/* Line 193 of yacc.c.  */
#line 265 "y.tab.c"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 216 of yacc.c.  */
#line 278 "y.tab.c"

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
# if YYENABLE_NLS
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
YYID (int i)
#else
static int
YYID (i)
    int i;
#endif
{
  return i;
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
  yytype_int16 yyss;
  YYSTYPE yyvs;
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
# define YYSTACK_RELOCATE(Stack)					\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack, Stack, yysize);				\
	Stack = &yyptr->Stack;						\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  3
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   1827

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  75
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  101
/* YYNRULES -- Number of rules.  */
#define YYNRULES  255
/* YYNRULES -- Number of states.  */
#define YYNSTATES  481

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   308

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,    72,    62,    55,     2,
      66,    67,    61,    59,    69,    60,     2,    63,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    68,    65,
      58,     2,     2,    52,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    73,     2,    74,    54,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    70,    53,    71,    64,     2,     2,     2,
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
      45,    46,    47,    48,    49,    50,    51,    56,    57
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     5,     9,    10,    11,    13,    18,    20,
      22,    23,    25,    27,    29,    31,    33,    35,    36,    37,
      47,    51,    53,    55,    57,    60,    63,    65,    69,    70,
      71,    77,    78,    86,    88,    90,    92,    95,    98,   100,
     101,   103,   106,   108,   111,   114,   118,   120,   121,   123,
     126,   128,   132,   133,   136,   139,   144,   146,   147,   149,
     153,   156,   161,   166,   168,   170,   172,   173,   174,   180,
     183,   188,   192,   196,   198,   202,   203,   206,   209,   212,
     214,   216,   218,   220,   222,   224,   226,   229,   232,   233,
     240,   241,   250,   251,   262,   264,   266,   268,   270,   274,
     275,   284,   285,   287,   289,   291,   292,   303,   306,   309,
     310,   314,   320,   323,   325,   327,   331,   335,   339,   343,
     347,   351,   355,   359,   363,   367,   371,   375,   379,   383,
     387,   389,   392,   395,   398,   400,   404,   406,   409,   413,
     417,   423,   427,   431,   435,   439,   443,   447,   451,   455,
     459,   463,   467,   471,   475,   479,   483,   487,   490,   493,
     496,   499,   502,   505,   508,   511,   513,   515,   517,   519,
     521,   523,   526,   530,   531,   533,   536,   538,   541,   543,
     547,   548,   550,   553,   555,   559,   563,   565,   567,   570,
     572,   574,   576,   578,   579,   585,   589,   596,   604,   613,
     621,   627,   634,   640,   645,   647,   651,   653,   654,   661,
     665,   671,   676,   681,   686,   688,   692,   693,   697,   705,
     715,   716,   720,   721,   725,   727,   729,   733,   737,   739,
     742,   746,   747,   751,   752,   758,   759,   765,   772,   779,
     780,   786,   787,   793,   794,   802,   803,   812,   816,   820,
     822,   825,   829,   833,   840,   841
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
      76,     0,    -1,    77,    -1,    77,    85,    78,    -1,    -1,
      -1,    65,    -1,   103,    36,   161,    65,    -1,     5,    -1,
       4,    -1,    -1,    61,    -1,   109,    -1,    65,    -1,     1,
      -1,     8,    -1,     9,    -1,    -1,    -1,   104,    82,    84,
      86,    66,   101,    67,    87,    83,    -1,   104,   107,    65,
      -1,    79,    -1,    93,    -1,    88,    -1,   103,    68,    -1,
      82,    84,    -1,    89,    -1,    89,    69,    90,    -1,    -1,
      -1,    91,    98,    92,    90,    65,    -1,    -1,   103,    48,
      84,    70,    94,    91,    71,    -1,     9,    -1,     8,    -1,
       6,    -1,    48,     8,    -1,    48,     9,    -1,    96,    -1,
      -1,    96,    -1,    97,    44,    -1,    98,    -1,    98,   138,
      -1,    99,    82,    -1,    99,    82,    95,    -1,    95,    -1,
      -1,   102,    -1,   102,    26,    -1,   100,    -1,   102,    69,
     100,    -1,    -1,     7,   103,    -1,   103,   106,    -1,    66,
      98,    82,    67,    -1,    98,    -1,    -1,   108,    -1,   108,
      69,   107,    -1,    82,    84,    -1,    82,    84,    13,   139,
      -1,    70,   111,   117,    71,    -1,   109,    -1,   123,    -1,
     127,    -1,    -1,    -1,   111,    98,   112,   116,    65,    -1,
      82,    95,    -1,    82,    95,    13,   139,    -1,    99,    82,
      95,    -1,   114,    13,   139,    -1,   113,    -1,   113,    69,
     116,    -1,    -1,   118,   117,    -1,     1,    65,    -1,   137,
      65,    -1,   174,    -1,   119,    -1,   121,    -1,   131,    -1,
     140,    -1,   110,    -1,    65,    -1,    32,    65,    -1,    33,
      65,    -1,    -1,    27,    66,   137,    67,   120,   118,    -1,
      -1,    28,   122,   118,    27,    66,   137,    67,    65,    -1,
      -1,    29,    66,   130,    65,   129,    65,   129,    67,   124,
     118,    -1,     8,    -1,   114,    -1,     9,    -1,   125,    -1,
     125,    69,   125,    -1,    -1,    30,    66,   126,    31,   139,
      67,   128,   118,    -1,    -1,   137,    -1,   129,    -1,   115,
      -1,    -1,    22,    66,   137,    67,   132,    70,   111,   134,
     133,    71,    -1,   134,   133,    -1,   118,   133,    -1,    -1,
      23,   135,    68,    -1,    23,   135,    25,   135,    68,    -1,
      24,    68,    -1,   136,    -1,   161,    -1,   136,    53,   136,
      -1,   136,    54,   136,    -1,   136,    55,   136,    -1,   136,
      57,   136,    -1,   136,    56,   136,    -1,   136,    18,   136,
      -1,   136,    58,   136,    -1,   136,    16,   136,    -1,   136,
      17,   136,    -1,   136,    59,   136,    -1,   136,    60,   136,
      -1,   136,    61,   136,    -1,   136,    62,   136,    -1,   136,
      63,   136,    -1,    66,   136,    67,    -1,     4,    -1,    60,
       4,    -1,    19,     4,    -1,    64,     4,    -1,   139,    -1,
     137,    69,   139,    -1,    45,    -1,   138,   147,    -1,   147,
      13,   139,    -1,     1,    13,   139,    -1,   139,    52,   139,
      68,   139,    -1,   139,    15,   139,    -1,   139,    14,   139,
      -1,   139,    53,   139,    -1,   139,    54,   139,    -1,   139,
      55,   139,    -1,   139,    57,   139,    -1,   139,    56,   139,
      -1,   139,    18,   139,    -1,   139,    58,   139,    -1,   139,
      16,   139,    -1,   139,    17,   139,    -1,   139,    59,   139,
      -1,   139,    60,   139,    -1,   139,    61,   139,    -1,   139,
      62,   139,    -1,   139,    63,   139,    -1,   105,   139,    -1,
      11,   147,    -1,    12,   147,    -1,    19,   139,    -1,    64,
     139,    -1,    60,   139,    -1,   147,    11,    -1,   147,    12,
      -1,   149,    -1,   155,    -1,   156,    -1,   157,    -1,    81,
      -1,    80,    -1,    34,    65,    -1,    34,   137,    65,    -1,
      -1,   143,    -1,   143,    69,    -1,   139,    -1,   139,    26,
      -1,   142,    -1,   143,    69,   142,    -1,    -1,   145,    -1,
     145,    69,    -1,   146,    -1,   145,    69,   146,    -1,   139,
      68,   139,    -1,   149,    -1,    41,    -1,    40,   172,    -1,
     165,    -1,     8,    -1,     9,    -1,    50,    -1,    -1,    72,
      66,   150,   137,    67,    -1,   149,    35,    84,    -1,   149,
      73,   137,    25,   137,    74,    -1,   149,    73,    58,   137,
      25,   137,    74,    -1,   149,    73,    58,   137,    25,    58,
     137,    74,    -1,   149,    73,   137,    25,    58,   137,    74,
      -1,   149,    73,   137,    25,    74,    -1,   149,    73,    58,
     137,    25,    74,    -1,   149,    73,    58,   137,    74,    -1,
     149,    73,   137,    74,    -1,   160,    -1,    66,   137,    67,
      -1,   153,    -1,    -1,     6,   151,    66,   101,    67,   109,
      -1,   148,    68,    67,    -1,   148,    69,   143,    68,    67,
      -1,    40,   137,    68,    67,    -1,    39,   144,    74,    67,
      -1,    38,   141,    71,    67,    -1,   109,    -1,    66,   137,
      67,    -1,    -1,    43,   154,   152,    -1,    42,    66,   139,
      69,   139,   159,    67,    -1,    46,    66,   139,    69,   139,
      69,   139,   159,    67,    -1,    -1,    47,   158,   152,    -1,
      -1,    69,   147,   159,    -1,   162,    -1,   162,    -1,    66,
     161,    67,    -1,   161,    59,   161,    -1,     3,    -1,   162,
       3,    -1,    84,    68,   139,    -1,    -1,   164,    69,   163,
      -1,    -1,   172,    66,   166,   141,    67,    -1,    -1,    49,
      66,   167,   141,    67,    -1,    49,    66,    48,     8,   164,
      67,    -1,    49,    66,    48,     9,   164,    67,    -1,    -1,
       8,    66,   168,   141,    67,    -1,    -1,   173,    66,   169,
     141,    67,    -1,    -1,   149,    35,    84,    66,   170,   141,
      67,    -1,    -1,    66,    61,   137,    67,    66,   171,   141,
      67,    -1,    10,    37,    84,    -1,    10,    37,    49,    -1,
       9,    -1,    37,    84,    -1,     6,    37,    84,    -1,    84,
      37,    84,    -1,    20,    66,   137,    67,   118,   175,    -1,
      -1,    21,   118,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   212,   212,   220,   226,   232,   234,   244,   314,   322,
     331,   335,   343,   351,   356,   364,   369,   374,   400,   373,
     458,   465,   466,   467,   470,   488,   502,   503,   506,   509,
     508,   518,   517,   598,   599,   617,   618,   635,   651,   653,
     660,   661,   669,   670,   678,   685,   694,   708,   713,   714,
     733,   745,   760,   764,   774,   783,   791,   793,   800,   801,
     805,   831,   887,   897,   897,   897,   901,   907,   906,   928,
     940,   975,   987,  1020,  1026,  1038,  1042,  1049,  1057,  1070,
    1071,  1072,  1073,  1074,  1075,  1081,  1086,  1109,  1123,  1122,
    1138,  1137,  1153,  1152,  1178,  1200,  1211,  1229,  1235,  1247,
    1246,  1268,  1272,  1276,  1282,  1292,  1291,  1326,  1333,  1341,
    1349,  1357,  1372,  1389,  1401,  1418,  1423,  1428,  1433,  1438,
    1443,  1452,  1457,  1462,  1467,  1472,  1477,  1482,  1487,  1492,
    1497,  1502,  1507,  1512,  1520,  1525,  1533,  1537,  1564,  1591,
    1597,  1622,  1629,  1636,  1662,  1667,  1691,  1714,  1729,  1774,
    1812,  1817,  1822,  1987,  2082,  2163,  2168,  2264,  2286,  2308,
    2331,  2341,  2353,  2378,  2401,  2423,  2424,  2425,  2426,  2427,
    2428,  2432,  2439,  2461,  2465,  2470,  2478,  2483,  2491,  2498,
    2512,  2517,  2522,  2530,  2541,  2560,  2568,  2676,  2677,  2686,
    2687,  2730,  2747,  2753,  2752,  2784,  2809,  2817,  2822,  2830,
    2838,  2843,  2848,  2892,  2945,  2946,  2951,  2953,  2952,  3009,
    3043,  3133,  3152,  3157,  3165,  3170,  3179,  3178,  3194,  3204,
    3216,  3215,  3231,  3237,  3252,  3261,  3262,  3267,  3275,  3276,
    3283,  3295,  3299,  3310,  3309,  3325,  3324,  3339,  3375,  3395,
    3394,  3465,  3464,  3538,  3537,  3591,  3590,  3622,  3648,  3664,
    3665,  3680,  3696,  3712,  3747,  3752
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "L_STRING", "L_NUMBER", "L_REAL",
  "L_BASIC_TYPE", "L_TYPE_MODIFIER", "L_DEFINED_NAME", "L_IDENTIFIER",
  "L_EFUN", "L_INC", "L_DEC", "L_ASSIGN", "L_LAND", "L_LOR", "L_LSH",
  "L_RSH", "L_ORDER", "L_NOT", "L_IF", "L_ELSE", "L_SWITCH", "L_CASE",
  "L_DEFAULT", "L_RANGE", "L_DOT_DOT_DOT", "L_WHILE", "L_DO", "L_FOR",
  "L_FOREACH", "L_IN", "L_BREAK", "L_CONTINUE", "L_RETURN", "L_ARROW",
  "L_INHERIT", "L_COLON_COLON", "L_ARRAY_OPEN", "L_MAPPING_OPEN",
  "L_FUNCTION_OPEN", "L_NEW_FUNCTION_OPEN", "L_SSCANF", "L_CATCH",
  "L_ARRAY", "L_REF", "L_PARSE_COMMAND", "L_TIME_EXPRESSION", "L_CLASS",
  "L_NEW", "L_PARAMETER", "LOWER_THAN_ELSE", "'?'", "'|'", "'^'", "'&'",
  "L_NE", "L_EQ", "'<'", "'+'", "'-'", "'*'", "'%'", "'/'", "'~'", "';'",
  "'('", "')'", "':'", "','", "'{'", "'}'", "'$'", "'['", "']'", "$accept",
  "all", "program", "possible_semi_colon", "inheritance", "real", "number",
  "optional_star", "block_or_semi", "identifier", "def", "@1", "@2",
  "modifier_change", "member_name", "member_name_list", "member_list",
  "@3", "type_decl", "@4", "new_local_name", "atomic_type",
  "opt_atomic_type", "basic_type", "arg_type", "new_arg", "argument",
  "argument_list", "type_modifier_list", "type", "cast", "opt_basic_type",
  "name_list", "new_name", "block", "decl_block", "local_declarations",
  "@5", "new_local_def", "single_new_local_def",
  "single_new_local_def_with_init", "local_name_list", "statements",
  "statement", "while", "@6", "do", "@7", "for", "@8", "foreach_var",
  "foreach_vars", "foreach", "@9", "for_expr", "first_for_expr", "switch",
  "@10", "switch_block", "case", "case_label", "constant", "comma_expr",
  "ref", "expr0", "return", "expr_list", "expr_list_node", "expr_list2",
  "expr_list3", "expr_list4", "assoc_pair", "lvalue",
  "l_new_function_open", "expr4", "@11", "@12", "expr_or_block", "catch",
  "@13", "sscanf", "parse_command", "time_expression", "@14",
  "lvalue_list", "string", "string_con1", "string_con2", "class_init",
  "opt_class_init", "function_call", "@15", "@16", "@17", "@18", "@19",
  "@20", "efun_override", "function_name", "cond", "optional_else_part", 0
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
     305,   306,    63,   124,    94,    38,   307,   308,    60,    43,
      45,    42,    37,    47,   126,    59,    40,    41,    58,    44,
     123,   125,    36,    91,    93
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    75,    76,    77,    77,    78,    78,    79,    80,    81,
      82,    82,    83,    83,    83,    84,    84,    86,    87,    85,
      85,    85,    85,    85,    88,    89,    90,    90,    91,    92,
      91,    94,    93,    95,    95,    96,    96,    96,    97,    97,
      98,    98,    99,    99,   100,   100,   100,   101,   101,   101,
     102,   102,   103,   103,   104,   105,   106,   106,   107,   107,
     108,   108,   109,   110,   110,   110,   111,   112,   111,   113,
     113,   114,   115,   116,   116,   117,   117,   117,   118,   118,
     118,   118,   118,   118,   118,   118,   118,   118,   120,   119,
     122,   121,   124,   123,   125,   125,   125,   126,   126,   128,
     127,   129,   129,   130,   130,   132,   131,   133,   133,   133,
     134,   134,   134,   135,   135,   136,   136,   136,   136,   136,
     136,   136,   136,   136,   136,   136,   136,   136,   136,   136,
     136,   136,   136,   136,   137,   137,   138,   139,   139,   139,
     139,   139,   139,   139,   139,   139,   139,   139,   139,   139,
     139,   139,   139,   139,   139,   139,   139,   139,   139,   139,
     139,   139,   139,   139,   139,   139,   139,   139,   139,   139,
     139,   140,   140,   141,   141,   141,   142,   142,   143,   143,
     144,   144,   144,   145,   145,   146,   147,   148,   148,   149,
     149,   149,   149,   150,   149,   149,   149,   149,   149,   149,
     149,   149,   149,   149,   149,   149,   149,   151,   149,   149,
     149,   149,   149,   149,   152,   152,   154,   153,   155,   156,
     158,   157,   159,   159,   160,   161,   161,   161,   162,   162,
     163,   164,   164,   166,   165,   167,   165,   165,   165,   168,
     165,   169,   165,   170,   165,   171,   165,   172,   172,   173,
     173,   173,   173,   174,   175,   175
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     3,     0,     0,     1,     4,     1,     1,
       0,     1,     1,     1,     1,     1,     1,     0,     0,     9,
       3,     1,     1,     1,     2,     2,     1,     3,     0,     0,
       5,     0,     7,     1,     1,     1,     2,     2,     1,     0,
       1,     2,     1,     2,     2,     3,     1,     0,     1,     2,
       1,     3,     0,     2,     2,     4,     1,     0,     1,     3,
       2,     4,     4,     1,     1,     1,     0,     0,     5,     2,
       4,     3,     3,     1,     3,     0,     2,     2,     2,     1,
       1,     1,     1,     1,     1,     1,     2,     2,     0,     6,
       0,     8,     0,    10,     1,     1,     1,     1,     3,     0,
       8,     0,     1,     1,     1,     0,    10,     2,     2,     0,
       3,     5,     2,     1,     1,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       1,     2,     2,     2,     1,     3,     1,     2,     3,     3,
       5,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     2,     2,     2,
       2,     2,     2,     2,     2,     1,     1,     1,     1,     1,
       1,     2,     3,     0,     1,     2,     1,     2,     1,     3,
       0,     1,     2,     1,     3,     3,     1,     1,     2,     1,
       1,     1,     1,     0,     5,     3,     6,     7,     8,     7,
       5,     6,     5,     4,     1,     3,     1,     0,     6,     3,
       5,     4,     4,     4,     1,     3,     0,     3,     7,     9,
       0,     3,     0,     3,     1,     1,     3,     3,     1,     2,
       3,     0,     3,     0,     5,     0,     5,     6,     6,     0,
       5,     0,     5,     0,     7,     0,     8,     3,     3,     1,
       2,     3,     3,     6,     0,     2
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       4,     0,    52,     1,    52,    21,     5,    23,    22,    57,
      10,    53,     6,     3,    35,     0,     0,    24,    40,     0,
      56,    54,    11,     0,     0,    58,   228,     0,     0,   225,
      36,    37,     0,    41,    15,    16,    60,    20,    10,     0,
       0,     7,   229,    31,     0,     0,     0,    59,   226,   227,
      28,     0,     9,     8,   207,   190,   191,     0,     0,     0,
       0,     0,     0,     0,     0,   187,     0,   216,   136,     0,
     220,     0,   192,     0,     0,     0,     0,   170,   169,     0,
       0,     0,    61,     0,     0,   165,   206,   166,   167,   168,
     204,   224,   189,     0,     0,    39,    60,    39,     0,     0,
       0,   239,     0,     0,   158,   186,   159,   160,   250,   176,
       0,   178,   174,     0,     0,   181,   183,     0,   134,   188,
       0,     0,     0,     0,   235,   162,   161,    35,     0,     0,
      10,     0,   193,     0,   157,   137,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   163,   164,     0,     0,     0,     0,     0,
     233,   241,    34,    33,    46,    42,    10,    50,     0,    48,
      32,    29,   139,   251,    39,     0,   248,   247,   177,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    66,   214,
     217,     0,   221,     0,     0,    36,    37,     0,     0,   205,
       0,   252,   142,   141,   150,   151,   148,     0,   143,   144,
     145,   147,   146,   149,   152,   153,   154,   155,   156,   138,
     209,     0,   195,     0,     0,     0,     0,    43,    44,    18,
      49,    39,    10,     0,     0,   213,   179,   185,   212,   184,
     211,   135,     0,     0,     0,     0,   231,   231,     0,     0,
      55,     0,     0,     0,     0,   243,     0,     0,   203,     0,
       0,    45,     0,    51,     0,    26,     0,     0,   240,   222,
     215,     0,     0,     0,     0,    90,     0,     0,     0,     0,
       0,    85,    67,    63,    84,     0,     0,    80,    81,    64,
      65,    82,     0,    83,    79,     0,     0,     0,   236,   245,
     194,   140,   210,     0,     0,   202,     0,   200,     0,   234,
     242,    14,    13,    19,    12,    25,    10,    30,   208,     0,
       0,    77,     0,     0,     0,     0,     0,    39,    86,    87,
     171,     0,    10,    62,    76,    78,     0,   237,     0,   238,
       0,     0,     0,   201,     0,     0,   196,    27,   222,   218,
       0,     0,     0,     0,    10,     0,   104,   103,     0,   102,
      94,    96,    95,    97,     0,   172,     0,    73,     0,   222,
       0,   232,     0,   244,     0,   197,   199,   223,     0,   105,
      88,     0,     0,     0,     0,    39,     0,    69,    10,    68,
       0,     0,   246,   198,   254,     0,     0,     0,    71,    72,
       0,    98,     0,     0,    74,   219,   230,     0,   253,    66,
      89,     0,     0,    99,    70,   255,    39,     0,     0,     0,
       0,     0,     0,    91,    92,   100,   130,     0,     0,     0,
       0,     0,   113,   114,   112,     0,     0,     0,     0,   132,
     131,   133,     0,     0,   110,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   108,
     106,   107,    93,   129,     0,     0,   122,   123,   120,   115,
     116,   117,   119,   118,   121,   124,   125,   126,   127,   128,
     111
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,     2,    13,     5,    77,    78,   264,   313,    79,
       6,    45,   262,     7,   265,   266,    97,   232,     8,    50,
     164,    18,    19,   165,   166,   167,   168,   169,     9,    10,
      80,    21,    24,    25,   283,   284,   244,   332,   367,   362,
     356,   368,   285,   435,   287,   396,   288,   325,   289,   438,
     363,   364,   290,   419,   357,   358,   291,   395,   436,   437,
     431,   432,   292,    81,   118,   293,   110,   111,   112,   114,
     115,   116,    83,    84,    85,   200,   100,   190,    86,   121,
      87,    88,    89,   123,   320,    90,    39,    91,   371,   296,
      92,   225,   194,   175,   226,   303,   340,    93,    94,   294,
     408
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -343
static const yytype_int16 yypact[] =
{
    -343,    50,   128,  -343,    53,  -343,     7,  -343,  -343,    90,
      79,  -343,  -343,  -343,  -343,    48,    30,  -343,    99,   115,
    -343,  -343,  -343,   141,   125,   154,  -343,    48,    66,   236,
     182,   190,   211,  -343,  -343,  -343,    27,  -343,    79,   -10,
      48,  -343,  -343,  -343,  1619,   234,   141,  -343,  -343,  -343,
    -343,   290,  -343,  -343,   276,     9,    10,   301,   296,   296,
    1619,   141,  1127,   485,  1619,  -343,   277,  -343,  -343,   284,
    -343,   293,  -343,  1619,  1619,   915,   295,  -343,  -343,   326,
    1619,   296,  1023,   316,   132,    42,  -343,  -343,  -343,  -343,
    -343,   236,  -343,   305,   307,   124,   354,    16,  1619,   141,
     320,  -343,    35,  1199,  -343,     1,  -343,  -343,  -343,   954,
     310,  -343,   318,   381,   314,   321,  -343,   174,  1023,   305,
    1619,     3,  1619,     3,   341,  -343,  -343,    28,   357,  1619,
      79,   104,  -343,   141,  -343,  -343,  1619,  1619,  1619,  1619,
    1619,  1619,  1619,  1619,  1619,  1619,  1619,  1619,  1619,  1619,
    1619,  1619,  1619,  -343,  -343,  1619,   324,  1619,   141,  1269,
    -343,  -343,  -343,  -343,  -343,   347,    79,  -343,   327,     2,
    -343,  -343,  1023,  -343,   124,  1339,  -343,  -343,  -343,   334,
    1055,  1619,   335,   557,   336,  1619,  1656,  1619,  -343,  -343,
    -343,  1678,  -343,   361,  1339,  -343,  -343,   114,   337,  -343,
    1619,  -343,  1166,  1094,   171,   171,   224,   525,   261,  1374,
     136,  1100,  1100,   224,   246,   246,  -343,  -343,  -343,  1023,
    -343,   311,   342,  1619,    94,  1339,  1339,  -343,   375,  -343,
    -343,   196,    79,   340,   343,  -343,  -343,  1023,  -343,  -343,
    -343,  1023,  1619,   169,   629,  1619,  -343,  -343,   344,   346,
    -343,   181,  1619,   353,  1619,  -343,    96,   216,  -343,   359,
     360,  -343,    15,  -343,   141,   362,   328,   376,  -343,  1706,
    -343,    14,   364,   379,   382,  -343,   391,   395,   348,   399,
    1409,  -343,  -343,  -343,  -343,   394,   773,  -343,  -343,  -343,
    -343,  -343,   147,  -343,  -343,  1728,   203,   206,  -343,  -343,
    -343,  1023,  -343,  1339,   413,  -343,  1619,  -343,    88,  -343,
    -343,  -343,  -343,  -343,  -343,  -343,    79,  -343,  -343,   296,
     380,  -343,  1619,  1619,  1619,   845,   985,   201,  -343,  -343,
    -343,   149,    79,  -343,  -343,  -343,  1619,  -343,   141,  -343,
    1339,   400,  1619,  -343,    95,   105,  -343,  -343,   397,  -343,
     222,   226,   229,   445,    79,   461,  -343,  -343,   410,   407,
    -343,  -343,  -343,   409,   449,  -343,   375,   412,   417,  1706,
     415,  -343,   425,  -343,   111,  -343,  -343,  -343,   845,  -343,
    -343,   418,   375,  1619,  1479,   201,  1619,   486,    79,  -343,
     431,  1619,  -343,  -343,   479,   432,   845,  1619,  -343,  1023,
     436,  -343,   883,  1619,  -343,  -343,  1023,   845,  -343,  -343,
    -343,   282,  1549,  -343,  1023,  -343,   223,   438,   450,   845,
      63,   448,   701,  -343,  -343,  -343,  -343,   514,   516,   517,
      63,    20,  1236,   470,  -343,   701,   462,   701,   845,  -343,
    -343,  -343,   452,    63,  -343,   118,   118,   118,   118,   118,
     118,   118,   118,   118,   118,   118,   118,   118,   118,  -343,
    -343,  -343,  -343,  -343,   468,   118,   294,   294,   315,  1305,
    1444,  1514,  1172,  1172,   315,   279,   279,  -343,  -343,  -343,
    -343
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -343,  -343,  -343,  -343,  -343,  -343,  -343,    -6,  -343,   -13,
    -343,  -343,  -343,  -343,  -343,   221,  -343,  -343,  -343,  -343,
    -215,  -343,  -343,    -7,  -307,   313,   372,  -343,   534,  -343,
    -343,  -343,   509,  -343,  -106,  -343,   139,  -343,  -343,   227,
    -343,   162,   266,  -230,  -343,  -343,  -343,  -343,  -343,  -343,
     170,  -343,  -343,  -343,  -342,  -343,  -343,  -343,   -77,   138,
     113,  1362,   -12,   405,   -39,  -343,  -164,  -162,   414,  -343,
    -343,   389,   -52,  -343,   -50,  -343,  -343,   441,  -343,  -343,
    -343,  -343,  -343,  -343,  -311,  -343,   -14,   -15,  -343,   345,
    -343,  -343,  -343,  -343,  -343,  -343,  -343,   510,  -343,  -343,
    -343
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -250
static const yytype_int16 yytable[] =
{
      29,    28,    20,    32,    23,    82,   104,   106,   105,   105,
      36,   234,    29,   261,   286,   189,   311,   189,   236,   354,
     354,   107,    14,   109,   113,    29,    49,    98,   230,   135,
     248,   105,    46,    96,   125,   126,   158,   377,    30,    31,
      44,   134,   400,    34,    35,   443,   -15,   -16,   108,    40,
       3,    26,   117,  -186,  -186,  -186,   286,    48,   390,   172,
       4,   259,   260,   131,   128,    99,    26,   426,   130,   187,
     418,   231,    12,   188,   159,   101,  -249,   158,   354,   321,
     312,   186,   427,   191,   176,   188,   173,   170,   444,   177,
     171,   131,   236,   -17,  -207,   353,    14,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,    27,   159,   219,   197,   109,   257,
     201,   304,   426,   428,   198,    40,    15,   429,    -2,   430,
      14,    41,   162,   163,   -39,     4,   109,   427,    16,   341,
      22,   109,   237,   -38,   113,   222,   241,   224,   394,    34,
      35,   387,   138,   139,   140,   109,   314,   185,    17,    33,
     228,   318,   346,   185,   185,   185,   410,   398,   258,   375,
     305,   199,   128,   185,   185,   243,   372,   415,   428,   376,
     185,   249,   429,   185,   465,   393,   109,   109,   251,   425,
      37,   -47,   145,   146,   147,   148,   149,   150,   151,   152,
     156,   157,    14,   269,   162,   163,   295,    14,   462,   360,
     361,   256,   335,   301,   365,   109,   185,    51,   185,    26,
      52,    53,    54,    38,    55,    56,    57,    58,    59,    14,
     148,   149,   150,   151,   152,    60,   270,   282,   185,    42,
     138,   139,   184,   185,   128,   308,   420,   421,   300,   128,
     185,   315,   -15,    61,    62,    63,    64,    65,    66,    67,
     -16,    68,    69,    70,   109,    71,    72,   348,   331,   105,
     337,   128,   338,   339,   306,   338,    73,   138,   139,   140,
      74,    43,    75,   148,   149,   150,   151,   152,    76,   378,
     307,   185,   344,   379,   345,   185,   380,   369,   185,    26,
      95,   109,    54,    98,    55,    56,    57,   150,   151,   152,
     350,   351,   352,    99,   359,   143,   144,   145,   146,   147,
     148,   149,   150,   151,   152,   370,   366,   153,   154,   155,
     374,   445,   446,    61,    62,    63,    64,    65,   102,    67,
     456,   457,   458,   120,   399,    71,    72,   402,   382,   417,
     122,   185,   406,   454,   455,   456,   457,   458,   459,   124,
     461,   132,   103,   133,   414,   195,   196,    44,    76,   246,
     247,   160,   359,   161,   454,   455,   456,   457,   458,   253,
     254,   179,   366,   162,   163,   411,   174,   180,   182,   193,
     183,   220,    68,   317,   229,   136,   137,   138,   139,   140,
     359,   235,   238,   240,   250,    29,   433,   267,   255,   282,
     268,   298,   299,   328,    51,    29,    26,    52,    53,    54,
     302,    55,    56,    57,    58,    59,   309,   310,    29,   433,
     322,   316,    60,   141,   142,   143,   144,   145,   146,   147,
     148,   149,   150,   151,   152,   323,   188,   349,   324,   181,
      61,    62,    63,    64,    65,    66,    67,   326,    68,    69,
      70,   327,    71,    72,   329,   333,   319,   373,   445,   446,
     447,   342,   381,    73,   383,   384,   185,    74,   385,    75,
     386,   388,   389,   391,   397,    76,    51,   343,    26,    52,
      53,    54,   392,    55,    56,    57,    58,    59,   405,   403,
     407,   412,   409,   423,    60,   448,   449,   450,   451,   452,
     453,   454,   455,   456,   457,   458,   434,   424,   439,   463,
     440,   441,    61,    62,    63,    64,    65,    66,    67,    40,
      68,    69,    70,   460,    71,    72,   480,   347,    11,   136,
     137,   138,   139,   140,   263,    73,   233,    47,   416,    74,
     404,    75,   334,   355,   422,   401,   464,    76,    51,  -180,
      26,    52,    53,    54,   192,    55,    56,    57,    58,    59,
     227,   221,   239,     0,   119,     0,    60,   141,   142,   143,
     144,   145,   146,   147,   148,   149,   150,   151,   152,     0,
       0,     0,   297,   252,    61,    62,    63,    64,    65,    66,
      67,     0,    68,    69,    70,     0,    71,    72,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    73,     0,     0,
       0,    74,     0,    75,     0,     0,     0,     0,     0,    76,
     271,  -182,    26,    52,    53,   127,     0,    55,    56,    57,
      58,    59,     0,     0,     0,     0,     0,     0,    60,   272,
       0,   273,     0,     0,     0,     0,   274,   275,   276,   277,
       0,   278,   279,   280,     0,     0,    61,    62,    63,    64,
      65,    66,    67,   -39,    68,    69,    70,   128,    71,    72,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    73,
       0,     0,     0,    74,   281,    75,     0,     0,     0,   188,
     -75,    76,    51,     0,    26,    52,    53,    54,     0,    55,
      56,    57,    58,    59,     0,     0,     0,     0,     0,     0,
      60,   272,     0,   273,   420,   421,     0,     0,   274,   275,
     276,   277,     0,   278,   279,   280,     0,     0,    61,    62,
      63,    64,    65,    66,    67,     0,    68,    69,    70,     0,
      71,    72,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    73,     0,     0,     0,    74,   281,    75,     0,     0,
       0,   188,  -109,    76,   271,     0,    26,    52,    53,    54,
       0,    55,    56,    57,    58,    59,     0,     0,     0,     0,
       0,     0,    60,   272,     0,   273,     0,     0,     0,     0,
     274,   275,   276,   277,     0,   278,   279,   280,     0,     0,
      61,    62,    63,    64,    65,    66,    67,     0,    68,    69,
      70,     0,    71,    72,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    73,     0,     0,     0,    74,   281,    75,
       0,     0,     0,   188,   -75,    76,    51,     0,    26,    52,
      53,    54,     0,    55,    56,    57,    58,    59,     0,     0,
       0,     0,     0,     0,    60,   272,     0,   273,     0,     0,
       0,     0,   274,   275,   276,   277,     0,   278,   279,   280,
       0,     0,    61,    62,    63,    64,    65,    66,    67,     0,
      68,    69,    70,     0,    71,    72,     0,   136,   137,   138,
     139,   140,     0,     0,     0,    73,     0,     0,     0,    74,
     281,    75,     0,     0,     0,   188,    51,    76,    26,    52,
      53,   127,     0,    55,    56,    57,    58,    59,     0,     0,
       0,     0,     0,     0,    60,   141,   142,   143,   144,   145,
     146,   147,   148,   149,   150,   151,   152,     0,     0,     0,
     413,     0,    61,    62,    63,    64,    65,    66,    67,   -39,
      68,    69,    70,   128,    71,    72,     0,     0,   136,   137,
     138,   139,   140,     0,     0,    73,   129,     0,     0,    74,
     178,    75,     0,     0,     0,     0,    51,    76,    26,    52,
      53,   127,     0,    55,    56,    57,    58,    59,     0,     0,
       0,     0,     0,     0,    60,     0,   141,   142,   143,   144,
     145,   146,   147,   148,   149,   150,   151,   152,     0,     0,
       0,     0,    61,    62,    63,    64,    65,    66,    67,   -39,
      68,    69,    70,   128,    71,    72,     0,   136,   137,   138,
     139,   140,     0,     0,     0,    73,     0,     0,     0,    74,
    -101,    75,     0,     0,     0,     0,    51,    76,    26,    52,
      53,    54,     0,    55,    56,    57,    58,    59,     0,     0,
       0,     0,     0,     0,    60,   141,   142,   143,   144,   145,
     146,   147,   148,   149,   150,   151,   152,     0,     0,     0,
       0,     0,    61,    62,    63,    64,    65,    66,    67,     0,
      68,    69,    70,     0,    71,    72,     0,     0,   136,     0,
     138,   139,   140,     0,     0,    73,   138,   139,   140,    74,
       0,    75,  -175,     0,     0,     0,  -175,    76,    51,     0,
      26,    52,    53,    54,     0,    55,    56,    57,    58,    59,
       0,     0,     0,     0,     0,     0,    60,   142,   143,   144,
     145,   146,   147,   148,   149,   150,   151,   152,   147,   148,
     149,   150,   151,   152,    61,    62,    63,    64,    65,    66,
      67,     0,    68,    69,    70,     0,    71,    72,     0,     0,
       0,     0,   138,   139,   140,     0,     0,    73,   445,   446,
     447,    74,     0,    75,     0,     0,     0,     0,  -173,    76,
      51,     0,    26,    52,    53,    54,     0,    55,    56,    57,
      58,    59,     0,     0,     0,     0,     0,     0,    60,   142,
     143,   144,   145,   146,   147,   148,   149,   150,   151,   152,
     453,   454,   455,   456,   457,   458,    61,    62,    63,    64,
      65,    66,    67,     0,    68,    69,    70,     0,    71,    72,
       0,     0,   445,   446,   447,     0,     0,     0,     0,    73,
     129,     0,     0,    74,     0,    75,     0,     0,     0,     0,
      51,    76,    26,    52,    53,    54,     0,    55,    56,    57,
      58,    59,     0,     0,     0,     0,     0,     0,    60,   448,
     449,   450,   451,   452,   453,   454,   455,   456,   457,   458,
       0,     0,     0,     0,     0,     0,    61,    62,    63,    64,
      65,    66,    67,     0,    68,    69,    70,     0,    71,    72,
       0,   445,   446,   447,     0,     0,     0,   223,     0,    73,
       0,     0,     0,    74,     0,    75,     0,     0,     0,     0,
      51,    76,    26,    52,    53,    54,     0,    55,    56,    57,
      58,    59,     0,     0,     0,     0,     0,     0,    60,   449,
     450,   451,   452,   453,   454,   455,   456,   457,   458,     0,
       0,     0,     0,     0,     0,     0,    61,    62,    63,    64,
      65,    66,    67,     0,    68,    69,    70,     0,    71,    72,
     138,   139,   140,     0,     0,     0,     0,     0,     0,    73,
       0,     0,     0,    74,     0,    75,  -173,     0,     0,     0,
      51,    76,    26,    52,    53,    54,     0,    55,    56,    57,
      58,    59,     0,     0,     0,     0,     0,     0,    60,   144,
     145,   146,   147,   148,   149,   150,   151,   152,     0,     0,
       0,     0,     0,     0,     0,     0,    61,    62,    63,    64,
      65,    66,    67,     0,    68,    69,    70,     0,    71,    72,
     445,   446,   447,     0,     0,     0,     0,     0,     0,    73,
       0,     0,     0,    74,   330,    75,     0,     0,     0,     0,
      51,    76,    26,    52,    53,    54,     0,    55,    56,    57,
      58,    59,     0,     0,     0,     0,     0,     0,    60,   450,
     451,   452,   453,   454,   455,   456,   457,   458,     0,     0,
       0,     0,     0,     0,     0,     0,    61,    62,    63,    64,
      65,    66,    67,     0,    68,    69,    70,     0,    71,    72,
     445,   446,   447,     0,     0,     0,     0,     0,     0,    73,
       0,     0,     0,    74,  -101,    75,     0,     0,     0,     0,
      51,    76,    26,    52,    53,    54,     0,    55,    56,    57,
      58,    59,     0,     0,     0,     0,     0,     0,    60,     0,
     451,   452,   453,   454,   455,   456,   457,   458,     0,     0,
       0,     0,     0,     0,     0,     0,    61,    62,    63,    64,
      65,    66,    67,     0,    68,    69,    70,     0,    71,    72,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    73,
       0,     0,     0,    74,     0,    75,  -101,     0,     0,     0,
      51,    76,    26,    52,    53,    54,     0,    55,    56,    57,
      58,    59,     0,     0,     0,     0,     0,     0,    60,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    61,    62,    63,    64,
      65,    66,    67,     0,    68,    69,    70,     0,    71,    72,
     136,   137,   138,   139,   140,     0,     0,     0,     0,    73,
       0,     0,     0,    74,     0,    75,     0,     0,     0,     0,
       0,    76,   136,   137,   138,   139,   140,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   141,   142,
     143,   144,   145,   146,   147,   148,   149,   150,   151,   152,
     136,   137,   138,   139,   140,   242,     0,     0,     0,     0,
     141,   142,   143,   144,   145,   146,   147,   148,   149,   150,
     151,   152,   136,   137,   138,   139,   140,   245,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   141,   142,
     143,   144,   145,   146,   147,   148,   149,   150,   151,   152,
       0,     0,     0,     0,     0,   319,     0,     0,     0,     0,
     141,   142,   143,   144,   145,   146,   147,   148,   149,   150,
     151,   152,   442,     0,     0,     0,     0,   336,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   466,   467,   468,
     469,   470,   471,   472,   473,   474,   475,   476,   477,   478,
     479,     0,     0,     0,     0,     0,     0,   442
};

static const yytype_int16 yycheck[] =
{
      15,    15,     9,    16,    10,    44,    58,    59,    58,    59,
      23,   175,    27,   228,   244,   121,     1,   123,   180,   326,
     327,    60,     6,    62,    63,    40,    40,    13,    26,    81,
     194,    81,    38,    46,    73,    74,    35,   348,     8,     9,
      13,    80,   384,     8,     9,    25,    37,    37,    61,    59,
       0,     3,    64,    11,    12,    13,   286,    67,   369,    98,
       7,   225,   226,    75,    48,    37,     3,     4,    75,    66,
     412,    69,    65,    70,    73,    66,    66,    35,   385,    65,
      65,   120,    19,   122,    49,    70,    99,    71,    68,   102,
      97,   103,   254,    66,    66,   325,     6,   136,   137,   138,
     139,   140,   141,   142,   143,   144,   145,   146,   147,   148,
     149,   150,   151,   152,    66,    73,   155,   129,   157,    25,
     133,    25,     4,    60,   130,    59,    36,    64,     0,    66,
       6,    65,     8,     9,    44,     7,   175,    19,    48,   303,
      61,   180,   181,    44,   183,   158,   185,   159,   378,     8,
       9,   366,    16,    17,    18,   194,   262,    69,    68,    44,
     166,   267,    74,    69,    69,    69,   396,   382,    74,    74,
      74,    67,    48,    69,    69,   187,   340,   407,    60,    74,
      69,    67,    64,    69,    66,    74,   225,   226,   200,   419,
      65,    67,    56,    57,    58,    59,    60,    61,    62,    63,
      68,    69,     6,   242,     8,     9,   245,     6,   438,     8,
       9,   223,    65,   252,    65,   254,    69,     1,    69,     3,
       4,     5,     6,    69,     8,     9,    10,    11,    12,     6,
      59,    60,    61,    62,    63,    19,    67,   244,    69,     3,
      16,    17,    68,    69,    48,   257,    23,    24,    67,    48,
      69,   264,    70,    37,    38,    39,    40,    41,    42,    43,
      70,    45,    46,    47,   303,    49,    50,   319,   280,   319,
      67,    48,    69,    67,    58,    69,    60,    16,    17,    18,
      64,    70,    66,    59,    60,    61,    62,    63,    72,    67,
      74,    69,   304,    67,   306,    69,    67,   336,    69,     3,
      66,   340,     6,    13,     8,     9,    10,    61,    62,    63,
     322,   323,   324,    37,   326,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    63,   338,   332,    11,    12,    13,
     342,    16,    17,    37,    38,    39,    40,    41,    37,    43,
      61,    62,    63,    66,   383,    49,    50,   386,   354,    67,
      66,    69,   391,    59,    60,    61,    62,    63,   435,    66,
     437,    66,    66,    37,   403,     8,     9,    13,    72,     8,
       9,    66,   384,    66,    59,    60,    61,    62,    63,    68,
      69,    71,   388,     8,     9,   397,    66,    69,    74,    48,
      69,    67,    45,    65,    67,    14,    15,    16,    17,    18,
     412,    67,    67,    67,    67,   420,   420,    67,    66,   416,
      67,    67,    66,    65,     1,   430,     3,     4,     5,     6,
      67,     8,     9,    10,    11,    12,    67,    67,   443,   443,
      66,    69,    19,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    66,    70,    67,    66,    68,
      37,    38,    39,    40,    41,    42,    43,    66,    45,    46,
      47,    66,    49,    50,    65,    71,    69,    67,    16,    17,
      18,    58,    27,    60,    13,    65,    69,    64,    69,    66,
      31,    69,    65,    68,    66,    72,     1,    74,     3,     4,
       5,     6,    67,     8,     9,    10,    11,    12,    67,    13,
      21,    65,    70,    65,    19,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    68,    67,     4,    67,
       4,     4,    37,    38,    39,    40,    41,    42,    43,    59,
      45,    46,    47,    71,    49,    50,    68,   316,     4,    14,
      15,    16,    17,    18,   231,    60,   174,    38,   409,    64,
     388,    66,   286,   326,   416,   385,   443,    72,     1,    74,
       3,     4,     5,     6,   123,     8,     9,    10,    11,    12,
     165,   157,   183,    -1,    64,    -1,    19,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    -1,
      -1,    -1,   247,    68,    37,    38,    39,    40,    41,    42,
      43,    -1,    45,    46,    47,    -1,    49,    50,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    60,    -1,    -1,
      -1,    64,    -1,    66,    -1,    -1,    -1,    -1,    -1,    72,
       1,    74,     3,     4,     5,     6,    -1,     8,     9,    10,
      11,    12,    -1,    -1,    -1,    -1,    -1,    -1,    19,    20,
      -1,    22,    -1,    -1,    -1,    -1,    27,    28,    29,    30,
      -1,    32,    33,    34,    -1,    -1,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    60,
      -1,    -1,    -1,    64,    65,    66,    -1,    -1,    -1,    70,
      71,    72,     1,    -1,     3,     4,     5,     6,    -1,     8,
       9,    10,    11,    12,    -1,    -1,    -1,    -1,    -1,    -1,
      19,    20,    -1,    22,    23,    24,    -1,    -1,    27,    28,
      29,    30,    -1,    32,    33,    34,    -1,    -1,    37,    38,
      39,    40,    41,    42,    43,    -1,    45,    46,    47,    -1,
      49,    50,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    60,    -1,    -1,    -1,    64,    65,    66,    -1,    -1,
      -1,    70,    71,    72,     1,    -1,     3,     4,     5,     6,
      -1,     8,     9,    10,    11,    12,    -1,    -1,    -1,    -1,
      -1,    -1,    19,    20,    -1,    22,    -1,    -1,    -1,    -1,
      27,    28,    29,    30,    -1,    32,    33,    34,    -1,    -1,
      37,    38,    39,    40,    41,    42,    43,    -1,    45,    46,
      47,    -1,    49,    50,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    60,    -1,    -1,    -1,    64,    65,    66,
      -1,    -1,    -1,    70,    71,    72,     1,    -1,     3,     4,
       5,     6,    -1,     8,     9,    10,    11,    12,    -1,    -1,
      -1,    -1,    -1,    -1,    19,    20,    -1,    22,    -1,    -1,
      -1,    -1,    27,    28,    29,    30,    -1,    32,    33,    34,
      -1,    -1,    37,    38,    39,    40,    41,    42,    43,    -1,
      45,    46,    47,    -1,    49,    50,    -1,    14,    15,    16,
      17,    18,    -1,    -1,    -1,    60,    -1,    -1,    -1,    64,
      65,    66,    -1,    -1,    -1,    70,     1,    72,     3,     4,
       5,     6,    -1,     8,     9,    10,    11,    12,    -1,    -1,
      -1,    -1,    -1,    -1,    19,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    -1,    -1,    -1,
      67,    -1,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    -1,    -1,    14,    15,
      16,    17,    18,    -1,    -1,    60,    61,    -1,    -1,    64,
      26,    66,    -1,    -1,    -1,    -1,     1,    72,     3,     4,
       5,     6,    -1,     8,     9,    10,    11,    12,    -1,    -1,
      -1,    -1,    -1,    -1,    19,    -1,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    -1,    -1,
      -1,    -1,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    -1,    14,    15,    16,
      17,    18,    -1,    -1,    -1,    60,    -1,    -1,    -1,    64,
      65,    66,    -1,    -1,    -1,    -1,     1,    72,     3,     4,
       5,     6,    -1,     8,     9,    10,    11,    12,    -1,    -1,
      -1,    -1,    -1,    -1,    19,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    -1,    -1,    -1,
      -1,    -1,    37,    38,    39,    40,    41,    42,    43,    -1,
      45,    46,    47,    -1,    49,    50,    -1,    -1,    14,    -1,
      16,    17,    18,    -1,    -1,    60,    16,    17,    18,    64,
      -1,    66,    67,    -1,    -1,    -1,    71,    72,     1,    -1,
       3,     4,     5,     6,    -1,     8,     9,    10,    11,    12,
      -1,    -1,    -1,    -1,    -1,    -1,    19,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    58,    59,
      60,    61,    62,    63,    37,    38,    39,    40,    41,    42,
      43,    -1,    45,    46,    47,    -1,    49,    50,    -1,    -1,
      -1,    -1,    16,    17,    18,    -1,    -1,    60,    16,    17,
      18,    64,    -1,    66,    -1,    -1,    -1,    -1,    71,    72,
       1,    -1,     3,     4,     5,     6,    -1,     8,     9,    10,
      11,    12,    -1,    -1,    -1,    -1,    -1,    -1,    19,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      58,    59,    60,    61,    62,    63,    37,    38,    39,    40,
      41,    42,    43,    -1,    45,    46,    47,    -1,    49,    50,
      -1,    -1,    16,    17,    18,    -1,    -1,    -1,    -1,    60,
      61,    -1,    -1,    64,    -1,    66,    -1,    -1,    -1,    -1,
       1,    72,     3,     4,     5,     6,    -1,     8,     9,    10,
      11,    12,    -1,    -1,    -1,    -1,    -1,    -1,    19,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      -1,    -1,    -1,    -1,    -1,    -1,    37,    38,    39,    40,
      41,    42,    43,    -1,    45,    46,    47,    -1,    49,    50,
      -1,    16,    17,    18,    -1,    -1,    -1,    58,    -1,    60,
      -1,    -1,    -1,    64,    -1,    66,    -1,    -1,    -1,    -1,
       1,    72,     3,     4,     5,     6,    -1,     8,     9,    10,
      11,    12,    -1,    -1,    -1,    -1,    -1,    -1,    19,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    37,    38,    39,    40,
      41,    42,    43,    -1,    45,    46,    47,    -1,    49,    50,
      16,    17,    18,    -1,    -1,    -1,    -1,    -1,    -1,    60,
      -1,    -1,    -1,    64,    -1,    66,    67,    -1,    -1,    -1,
       1,    72,     3,     4,     5,     6,    -1,     8,     9,    10,
      11,    12,    -1,    -1,    -1,    -1,    -1,    -1,    19,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    37,    38,    39,    40,
      41,    42,    43,    -1,    45,    46,    47,    -1,    49,    50,
      16,    17,    18,    -1,    -1,    -1,    -1,    -1,    -1,    60,
      -1,    -1,    -1,    64,    65,    66,    -1,    -1,    -1,    -1,
       1,    72,     3,     4,     5,     6,    -1,     8,     9,    10,
      11,    12,    -1,    -1,    -1,    -1,    -1,    -1,    19,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    37,    38,    39,    40,
      41,    42,    43,    -1,    45,    46,    47,    -1,    49,    50,
      16,    17,    18,    -1,    -1,    -1,    -1,    -1,    -1,    60,
      -1,    -1,    -1,    64,    65,    66,    -1,    -1,    -1,    -1,
       1,    72,     3,     4,     5,     6,    -1,     8,     9,    10,
      11,    12,    -1,    -1,    -1,    -1,    -1,    -1,    19,    -1,
      56,    57,    58,    59,    60,    61,    62,    63,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    37,    38,    39,    40,
      41,    42,    43,    -1,    45,    46,    47,    -1,    49,    50,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    60,
      -1,    -1,    -1,    64,    -1,    66,    67,    -1,    -1,    -1,
       1,    72,     3,     4,     5,     6,    -1,     8,     9,    10,
      11,    12,    -1,    -1,    -1,    -1,    -1,    -1,    19,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    37,    38,    39,    40,
      41,    42,    43,    -1,    45,    46,    47,    -1,    49,    50,
      14,    15,    16,    17,    18,    -1,    -1,    -1,    -1,    60,
      -1,    -1,    -1,    64,    -1,    66,    -1,    -1,    -1,    -1,
      -1,    72,    14,    15,    16,    17,    18,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      14,    15,    16,    17,    18,    69,    -1,    -1,    -1,    -1,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    14,    15,    16,    17,    18,    69,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      -1,    -1,    -1,    -1,    -1,    69,    -1,    -1,    -1,    -1,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,   430,    -1,    -1,    -1,    -1,    69,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   445,   446,   447,
     448,   449,   450,   451,   452,   453,   454,   455,   456,   457,
     458,    -1,    -1,    -1,    -1,    -1,    -1,   465
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    76,    77,     0,     7,    79,    85,    88,    93,   103,
     104,   103,    65,    78,     6,    36,    48,    68,    96,    97,
      98,   106,    61,    82,   107,   108,     3,    66,   161,   162,
       8,     9,    84,    44,     8,     9,    84,    65,    69,   161,
      59,    65,     3,    70,    13,    86,    82,   107,    67,   161,
      94,     1,     4,     5,     6,     8,     9,    10,    11,    12,
      19,    37,    38,    39,    40,    41,    42,    43,    45,    46,
      47,    49,    50,    60,    64,    66,    72,    80,    81,    84,
     105,   138,   139,   147,   148,   149,   153,   155,   156,   157,
     160,   162,   165,   172,   173,    66,    84,    91,    13,    37,
     151,    66,    37,    66,   147,   149,   147,   139,    84,   139,
     141,   142,   143,   139,   144,   145,   146,   137,   139,   172,
      66,   154,    66,   158,    66,   139,   139,     6,    48,    61,
      98,   137,    66,    37,   139,   147,    14,    15,    16,    17,
      18,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    11,    12,    13,    68,    69,    35,    73,
      66,    66,     8,     9,    95,    98,    99,   100,   101,   102,
      71,    98,   139,    84,    66,   168,    49,    84,    26,    71,
      69,    68,    74,    69,    68,    69,   139,    66,    70,   109,
     152,   139,   152,    48,   167,     8,     9,   137,    82,    67,
     150,    84,   139,   139,   139,   139,   139,   139,   139,   139,
     139,   139,   139,   139,   139,   139,   139,   139,   139,   139,
      67,   143,    84,    58,   137,   166,   169,   138,    82,    67,
      26,    69,    92,   101,   141,    67,   142,   139,    67,   146,
      67,   139,    69,   137,   111,    69,     8,     9,   141,    67,
      67,   137,    68,    68,    69,    66,   137,    25,    74,   141,
     141,    95,    87,   100,    82,    89,    90,    67,    67,   139,
      67,     1,    20,    22,    27,    28,    29,    30,    32,    33,
      34,    65,    98,   109,   110,   117,   118,   119,   121,   123,
     127,   131,   137,   140,   174,   139,   164,   164,    67,    66,
      67,   139,    67,   170,    25,    74,    58,    74,   137,    67,
      67,     1,    65,    83,   109,    84,    69,    65,   109,    69,
     159,    65,    66,    66,    66,   122,    66,    66,    65,    65,
      65,   137,   112,    71,   117,    65,    69,    67,    69,    67,
     171,   141,    58,    74,   137,   137,    74,    90,   147,    67,
     137,   137,   137,   118,    99,   114,   115,   129,   130,   137,
       8,     9,   114,   125,   126,    65,    82,   113,   116,   139,
      84,   163,   141,    67,   137,    74,    74,   159,    67,    67,
      67,    27,    82,    13,    65,    69,    31,    95,    69,    65,
     159,    68,    67,    74,   118,   132,   120,    66,    95,   139,
     129,   125,   139,    13,   116,    67,   139,    21,   175,    70,
     118,   137,    65,    67,   139,   118,   111,    67,   129,   128,
      23,    24,   134,    65,    67,   118,     4,    19,    60,    64,
      66,   135,   136,   161,    68,   118,   133,   134,   124,     4,
       4,     4,   136,    25,    68,    16,    17,    18,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,   133,
      71,   133,   118,    67,   135,    66,   136,   136,   136,   136,
     136,   136,   136,   136,   136,   136,   136,   136,   136,   136,
      68
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
   Once GCC version 2 has supplanted version 1, this can go.  */

#define YYFAIL		goto yyerrlab

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
# if YYLTYPE_IS_TRIVIAL
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
yy_stack_print (yytype_int16 *bottom, yytype_int16 *top)
#else
static void
yy_stack_print (bottom, top)
    yytype_int16 *bottom;
    yytype_int16 *top;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; bottom <= top; ++bottom)
    YYFPRINTF (stderr, " %d", *bottom);
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
      fprintf (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      fprintf (stderr, "\n");
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



/* The look-ahead symbol.  */
int yychar;

/* The semantic value of the look-ahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;



/*----------.
| yyparse.  |
`----------*/

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
  int yyn;
  int yyresult;
  /* Number of tokens to shift before error messages enabled.  */
  int yyerrstatus;
  /* Look-ahead token as an internal (translated) token number.  */
  int yytoken = 0;
#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

  /* Three stacks and their tools:
     `yyss': related to states,
     `yyvs': related to semantic values,
     `yyls': related to locations.

     Refer to the stacks thru separate pointers, to allow yyoverflow
     to reallocate them elsewhere.  */

  /* The state stack.  */
  yytype_int16 yyssa[YYINITDEPTH];
  yytype_int16 *yyss = yyssa;
  yytype_int16 *yyssp;

  /* The semantic value stack.  */
  YYSTYPE yyvsa[YYINITDEPTH];
  YYSTYPE *yyvs = yyvsa;
  YYSTYPE *yyvsp;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  YYSIZE_T yystacksize = YYINITDEPTH;

  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;


  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY;		/* Cause a token to be read.  */

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
	YYSTACK_RELOCATE (yyss);
	YYSTACK_RELOCATE (yyvs);

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

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     look-ahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to look-ahead token.  */
  yyn = yypact[yystate];
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a look-ahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid look-ahead symbol.  */
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

  if (yyn == YYFINAL)
    YYACCEPT;

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the look-ahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token unless it is eof.  */
  if (yychar != YYEOF)
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
        case 2:
#line 213 "grammar.y"
    {
#line 229 "grammar.y.pre"
	    comp_trees[TREE_MAIN] = (yyval.node);
	}
    break;

  case 3:
#line 221 "grammar.y"
    {
#line 236 "grammar.y.pre"
	    CREATE_TWO_VALUES((yyval.node), 0, (yyvsp[(1) - (3)].node), (yyvsp[(2) - (3)].node));
	}
    break;

  case 4:
#line 226 "grammar.y"
    {
#line 240 "grammar.y.pre"
	    (yyval.node) = 0;
	}
    break;

  case 6:
#line 235 "grammar.y"
    {
#line 248 "grammar.y.pre"

		yywarn("Extra ';'. Ignored.");
	    }
    break;

  case 7:
#line 245 "grammar.y"
    {
#line 257 "grammar.y.pre"
		object_t *ob;
		inherit_t inherit;
		int initializer;
		
		(yyvsp[(1) - (4)].type) |= global_modifiers;

		
		if (!((yyvsp[(1) - (4)].type) & DECL_ACCESS)) (yyvsp[(1) - (4)].type) |= DECL_PUBLIC;
		
		if (var_defined)
		    yyerror("Illegal to inherit after defining global variables.");
		ob = find_object2((yyvsp[(3) - (4)].string));
		if (ob == 0) {
		    inherit_file = alloc_cstring((yyvsp[(3) - (4)].string), "inherit");
		    /* Return back to load_object() */
		    YYACCEPT;
		}
		scratch_free((yyvsp[(3) - (4)].string));
		inherit.prog = ob->prog;

		if (mem_block[A_INHERITS].current_size){
		    inherit_t *prev_inherit = INHERIT(NUM_INHERITS - 1);
		    
		    inherit.function_index_offset 
			= prev_inherit->function_index_offset
			+ prev_inherit->prog->num_functions_defined
			+ prev_inherit->prog->last_inherited;
		    if (prev_inherit->prog->num_functions_defined &&
			prev_inherit->prog->function_table[prev_inherit->prog->num_functions_defined - 1].name[0] == '#')
			inherit.function_index_offset--;
		} else inherit.function_index_offset = 0;
		
		inherit.variable_index_offset =
		    mem_block[A_VAR_TEMP].current_size /
		    sizeof (variable_t);
		inherit.type_mod = (yyvsp[(1) - (4)].type);
		add_to_mem_block(A_INHERITS, (char *)&inherit, sizeof inherit);

		/* The following has to come before copy_vars - Sym */
		copy_structures(ob->prog);
		copy_variables(ob->prog, (yyvsp[(1) - (4)].type));
		initializer = copy_functions(ob->prog, (yyvsp[(1) - (4)].type));
		if (initializer >= 0) {
		    parse_node_t *node, *newnode;
		    /* initializer is an index into the object we're
		       inheriting's function table; this finds the
		       appropriate entry in our table and generates
		       a call to it */
		    node = new_node_no_line();
		    node->kind = NODE_CALL_2;
		    node->r.expr = 0;
		    node->v.number = F_CALL_INHERITED;
		    node->l.number = initializer | ((NUM_INHERITS - 1) << 16);
		    node->type = TYPE_ANY;
		    
		    /* The following illustrates a distinction between */
		    /* macros and funcs...newnode is needed here - Sym */
		    newnode = comp_trees[TREE_INIT];
		    CREATE_TWO_VALUES(comp_trees[TREE_INIT],0, newnode, node);
		    comp_trees[TREE_INIT] = pop_value(comp_trees[TREE_INIT]);
		    
		} 
		(yyval.node) = 0;
	    }
    break;

  case 8:
#line 315 "grammar.y"
    {
#line 342 "grammar.y.pre"
		CREATE_REAL((yyval.node), (yyvsp[(1) - (1)].real));
	    }
    break;

  case 9:
#line 323 "grammar.y"
    {
#line 349 "grammar.y.pre"
		CREATE_NUMBER((yyval.node), (yyvsp[(1) - (1)].number));
	    }
    break;

  case 10:
#line 331 "grammar.y"
    {
#line 356 "grammar.y.pre"
		(yyval.type) = 0;
	    }
    break;

  case 11:
#line 336 "grammar.y"
    {
#line 360 "grammar.y.pre"
		(yyval.type) = TYPE_MOD_ARRAY;
	    }
    break;

  case 12:
#line 344 "grammar.y"
    {
#line 367 "grammar.y.pre"
		(yyval.node) = (yyvsp[(1) - (1)].decl).node;
		if (!(yyval.node)) {
		    CREATE_RETURN((yyval.node), 0);
		}
            }
    break;

  case 13:
#line 352 "grammar.y"
    {
#line 374 "grammar.y.pre"
		(yyval.node) = 0;
	    }
    break;

  case 14:
#line 357 "grammar.y"
    {
#line 378 "grammar.y.pre"
		(yyval.node) = 0;
	    }
    break;

  case 15:
#line 365 "grammar.y"
    {
#line 385 "grammar.y.pre"
		(yyval.string) = scratch_copy((yyvsp[(1) - (1)].ihe)->name);
	    }
    break;

  case 17:
#line 374 "grammar.y"
    {
#line 393 "grammar.y.pre"
		int flags;
		
		flags = ((yyvsp[(1) - (3)].type) >> 16);
		
		flags |= global_modifiers;


		if (!(flags & DECL_ACCESS)) flags |= DECL_PUBLIC;
                (yyvsp[(1) - (3)].type) = (flags << 16) | ((yyvsp[(1) - (3)].type) & 0xffff);
		/* Handle type checking here so we know whether to typecheck
		   'argument' */
		if ((yyvsp[(1) - (3)].type) & 0xffff) {
		    exact_types = ((yyvsp[(1) - (3)].type)& 0xffff) | (yyvsp[(2) - (3)].type);
		} else {
		    if (pragmas & PRAGMA_STRICT_TYPES) {
			if (strcmp((yyvsp[(3) - (3)].string), "create") != 0)
			    yyerror("\"#pragma strict_types\" requires type of function");
			else
			    exact_types = TYPE_VOID; /* default for create() */
		    } else
			exact_types = 0;
		}
	    }
    break;

  case 18:
#line 400 "grammar.y"
    {
#line 444 "grammar.y.pre"
		char *p = (yyvsp[(3) - (7)].string);
		(yyvsp[(3) - (7)].string) = make_shared_string((yyvsp[(3) - (7)].string));
		scratch_free(p);

		/* If we had nested functions, we would need to check */
		/* here if we have enough space for locals */
		
		/*
		 * Define a prototype. If it is a real function, then the
		 * prototype will be replaced below.
		 */

		(yyval.number) = FUNC_PROTOTYPE;
		if ((yyvsp[(6) - (7)].argument).flags & ARG_IS_VARARGS) {
		    (yyval.number) |= (FUNC_TRUE_VARARGS | FUNC_VARARGS);
		}
		(yyval.number) |= ((yyvsp[(1) - (7)].type) >> 16);

		define_new_function((yyvsp[(3) - (7)].string), (yyvsp[(6) - (7)].argument).num_arg, 0, (yyval.number), ((yyvsp[(1) - (7)].type) & 0xffff)| (yyvsp[(2) - (7)].type));
		/* This is safe since it is guaranteed to be in the
		   function table, so it can't be dangling */
		free_string((yyvsp[(3) - (7)].string)); 
		context = 0;
	    }
    break;

  case 19:
#line 427 "grammar.y"
    {
#line 470 "grammar.y.pre"
		/* Either a prototype or a block */
		if ((yyvsp[(9) - (9)].node)) {
		    int fun;

		    (yyvsp[(8) - (9)].number) &= ~FUNC_PROTOTYPE;
		    if ((yyvsp[(9) - (9)].node)->kind != NODE_RETURN &&
			((yyvsp[(9) - (9)].node)->kind != NODE_TWO_VALUES
			 || (yyvsp[(9) - (9)].node)->r.expr->kind != NODE_RETURN)) {
			parse_node_t *replacement;
			CREATE_STATEMENTS(replacement, (yyvsp[(9) - (9)].node), 0);
			CREATE_RETURN(replacement->r.expr, 0);
			(yyvsp[(9) - (9)].node) = replacement;
		    }

		    fun = define_new_function((yyvsp[(3) - (9)].string), (yyvsp[(6) - (9)].argument).num_arg, 
					      max_num_locals - (yyvsp[(6) - (9)].argument).num_arg,
					      (yyvsp[(8) - (9)].number), ((yyvsp[(1) - (9)].type) & 0xffff) | (yyvsp[(2) - (9)].type));
		    if (fun != -1) {
			(yyval.node) = new_node_no_line();
			(yyval.node)->kind = NODE_FUNCTION;
			(yyval.node)->v.number = fun;
			(yyval.node)->l.number = max_num_locals;
			(yyval.node)->r.expr = (yyvsp[(9) - (9)].node);
		    } else 
			(yyval.node) = 0;
		} else
		    (yyval.node) = 0;
		free_all_local_names(!!(yyvsp[(9) - (9)].node));
	    }
    break;

  case 20:
#line 459 "grammar.y"
    {
#line 501 "grammar.y.pre"
		if (!((yyvsp[(1) - (3)].type) & ~(DECL_MODS)) && (pragmas & PRAGMA_STRICT_TYPES))
		    yyerror("Missing type for global variable declaration");
		(yyval.node) = 0;
	    }
    break;

  case 24:
#line 471 "grammar.y"
    {
#line 512 "grammar.y.pre"
		if (!(yyvsp[(1) - (2)].type)) 
		    yyerror("modifier list may not be empty.");
		
		if ((yyvsp[(1) - (2)].type) & FUNC_VARARGS) {
		    yyerror("Illegal modifier 'varargs' in global modifier list.");
		    (yyvsp[(1) - (2)].type) &= ~FUNC_VARARGS;
		}

		if (!((yyvsp[(1) - (2)].type) & DECL_ACCESS)) (yyvsp[(1) - (2)].type) |= DECL_PUBLIC;
		global_modifiers = (yyvsp[(1) - (2)].type);
		(yyval.node) = 0;
	    }
    break;

  case 25:
#line 489 "grammar.y"
    {
#line 529 "grammar.y.pre"
		/* At this point, the current_type here is only a basic_type */
		/* and cannot be unused yet - Sym */
		
		if (current_type == TYPE_VOID)
		    yyerror("Illegal to declare class member of type void.");
		add_local_name((yyvsp[(2) - (2)].string), current_type | (yyvsp[(1) - (2)].type));
		scratch_free((yyvsp[(2) - (2)].string));
	    }
    break;

  case 29:
#line 509 "grammar.y"
    {
#line 548 "grammar.y.pre"
	      current_type = (yyvsp[(2) - (2)].type);
	  }
    break;

  case 31:
#line 518 "grammar.y"
    {
#line 556 "grammar.y.pre"
		ident_hash_elem_t *ihe;

		ihe = find_or_add_ident(
			   PROG_STRING((yyval.number) = store_prog_string((yyvsp[(3) - (4)].string))),
			   FOA_GLOBAL_SCOPE);
		if (ihe->dn.class_num == -1) {
		    ihe->sem_value++;
		    ihe->dn.class_num = mem_block[A_CLASS_DEF].current_size / sizeof(class_def_t);
		    if (ihe->dn.class_num > CLASS_NUM_MASK){
			char buf[256];
			char *p;

			p = buf;
			sprintf(p, "Too many classes, max is %d.\n", CLASS_NUM_MASK + 1);
			yyerror(buf);
		    }

		    scratch_free((yyvsp[(3) - (4)].string));
		    (yyvsp[(2) - (4)].ihe) = 0;
		}
		else {
		    (yyvsp[(2) - (4)].ihe) = ihe;
		}
	    }
    break;

  case 32:
#line 545 "grammar.y"
    {
#line 582 "grammar.y.pre"
		class_def_t *sd;
		class_member_entry_t *sme;
		int i, raise_error = 0;
		
		/* check for a redefinition */
		if ((yyvsp[(2) - (7)].ihe) != 0) {
		    sd = CLASS((yyvsp[(2) - (7)].ihe)->dn.class_num);
		    if (sd->size != current_number_of_locals)
			raise_error = 1;
		    else {
			i = sd->size;
			sme = (class_member_entry_t *)mem_block[A_CLASS_MEMBER].block + sd->index;
			while (i--) {
			    /* check for matching names and types */
			    if (strcmp(PROG_STRING(sme[i].name), locals_ptr[i].ihe->name) != 0 ||
				sme[i].type != (type_of_locals_ptr[i] & ~LOCAL_MODS)) {
				raise_error = 1;
				break;
			    }
			}
		    }
		}

		if (raise_error) {
		    char buf[256];
		    char *end = EndOf(buf);
		    char *p;

		    p = strput(buf, end, "Illegal to redefine class ");
		    p = strput(p, end, PROG_STRING((yyval.number)));
		    yyerror(buf);
		} else {
		    sd = (class_def_t *)allocate_in_mem_block(A_CLASS_DEF, sizeof(class_def_t));
		    i = sd->size = current_number_of_locals;
		    sd->index = mem_block[A_CLASS_MEMBER].current_size / sizeof(class_member_entry_t);
		    sd->name = (yyvsp[(5) - (7)].number);

		    sme = (class_member_entry_t *)allocate_in_mem_block(A_CLASS_MEMBER, sizeof(class_member_entry_t) * current_number_of_locals);

		    while (i--) {
			sme[i].name = store_prog_string(locals_ptr[i].ihe->name);
			sme[i].type = type_of_locals_ptr[i] & ~LOCAL_MODS;
		    }
		}

		free_all_local_names(0);
		(yyval.node) = 0;
	    }
    break;

  case 34:
#line 600 "grammar.y"
    {
#line 636 "grammar.y.pre"
		if ((yyvsp[(1) - (1)].ihe)->dn.local_num != -1) {
		    char buff[256];
		    char *end = EndOf(buff);
		    char *p;
		    
		    p = strput(buff, end, "Illegal to redeclare local name '");
		    p = strput(p, end, (yyvsp[(1) - (1)].ihe)->name);
		    p = strput(p, end, "'");
		    yyerror(buff);
		}
		(yyval.string) = scratch_copy((yyvsp[(1) - (1)].ihe)->name);
	    }
    break;

  case 36:
#line 619 "grammar.y"
    {
#line 654 "grammar.y.pre"
		if ((yyvsp[(2) - (2)].ihe)->dn.class_num == -1) {
		    char buf[256];
		    char *end = EndOf(buf);
		    char *p;
		    
		    p = strput(buf, end, "Undefined class '");
		    p = strput(p, end, (yyvsp[(2) - (2)].ihe)->name);
		    p = strput(p, end, "'");
		    yyerror(buf);
		    (yyval.type) = TYPE_ANY;
		} else {
		    (yyval.type) = (yyvsp[(2) - (2)].ihe)->dn.class_num | TYPE_MOD_CLASS;
		}
	    }
    break;

  case 37:
#line 636 "grammar.y"
    {
#line 670 "grammar.y.pre"
		char buf[256];
		char *end = EndOf(buf);
		char *p;

		p = strput(buf, end, "Undefined class '");
		p = strput(p, end, (yyvsp[(2) - (2)].string));
		p = strput(p, end, "'");
		yyerror(buf);
		(yyval.type) = TYPE_ANY;
	    }
    break;

  case 39:
#line 653 "grammar.y"
    {
#line 687 "grammar.y.pre"
		(yyval.type) = TYPE_ANY;
	    }
    break;

  case 41:
#line 662 "grammar.y"
    {
#line 697 "grammar.y.pre"
		(yyval.type) = (yyvsp[(1) - (2)].type) | TYPE_MOD_ARRAY;
	    }
    break;

  case 43:
#line 671 "grammar.y"
    {
#line 707 "grammar.y.pre"
		(yyval.type) = (yyvsp[(1) - (2)].type) | LOCAL_MOD_REF;
	    }
    break;

  case 44:
#line 679 "grammar.y"
    {
#line 715 "grammar.y.pre"
                (yyval.number) = (yyvsp[(1) - (2)].type) | (yyvsp[(2) - (2)].type);
		if ((yyvsp[(1) - (2)].type) != TYPE_VOID)
		    add_local_name("", (yyvsp[(1) - (2)].type) | (yyvsp[(2) - (2)].type));
            }
    break;

  case 45:
#line 686 "grammar.y"
    {
#line 721 "grammar.y.pre"
		if ((yyvsp[(1) - (3)].type) == TYPE_VOID)
		    yyerror("Illegal to declare argument of type void.");
                add_local_name((yyvsp[(3) - (3)].string), (yyvsp[(1) - (3)].type) | (yyvsp[(2) - (3)].type));
		scratch_free((yyvsp[(3) - (3)].string));
                (yyval.number) = (yyvsp[(1) - (3)].type) | (yyvsp[(2) - (3)].type);
	    }
    break;

  case 46:
#line 695 "grammar.y"
    {
#line 729 "grammar.y.pre"
		if (exact_types) {
		    yyerror("Missing type for argument");
		}
		add_local_name((yyvsp[(1) - (1)].string), TYPE_ANY);
		scratch_free((yyvsp[(1) - (1)].string));
		(yyval.number) = TYPE_ANY;
            }
    break;

  case 47:
#line 708 "grammar.y"
    {
#line 741 "grammar.y.pre"
		(yyval.argument).num_arg = 0;
                (yyval.argument).flags = 0;
	    }
    break;

  case 49:
#line 715 "grammar.y"
    {
#line 747 "grammar.y.pre"
		int x = type_of_locals_ptr[max_num_locals-1];
		int lt = x & ~LOCAL_MODS;
		
		(yyval.argument) = (yyvsp[(1) - (2)].argument);
		(yyval.argument).flags |= ARG_IS_VARARGS;

		if (x & LOCAL_MOD_REF) {
		    yyerror("Variable to hold remainder of args may not be a reference");
		    x &= ~LOCAL_MOD_REF;
		}
		if (lt != TYPE_ANY && !(lt & TYPE_MOD_ARRAY))
		    yywarn("Variable to hold remainder of arguments should be an array.");
	    }
    break;

  case 50:
#line 734 "grammar.y"
    {
#line 765 "grammar.y.pre"
		if (((yyvsp[(1) - (1)].number) & TYPE_MASK) == TYPE_VOID && !((yyvsp[(1) - (1)].number) & TYPE_MOD_CLASS)) {
		    if ((yyvsp[(1) - (1)].number) & ~TYPE_MASK)
			yyerror("Illegal to declare argument of type void.");
		    (yyval.argument).num_arg = 0;
		} else {
		    (yyval.argument).num_arg = 1;
		}
                (yyval.argument).flags = 0;
	    }
    break;

  case 51:
#line 746 "grammar.y"
    {
#line 776 "grammar.y.pre"
		if (!(yyval.argument).num_arg)    /* first arg was void w/no name */
		    yyerror("argument of type void must be the only argument.");
		if (((yyvsp[(3) - (3)].number) & TYPE_MASK) == TYPE_VOID && !((yyvsp[(3) - (3)].number) & TYPE_MOD_CLASS))
		    yyerror("Illegal to declare argument of type void.");

                (yyval.argument) = (yyvsp[(1) - (3)].argument);
		(yyval.argument).num_arg++;
	    }
    break;

  case 52:
#line 760 "grammar.y"
    {
#line 789 "grammar.y.pre"
		(yyval.type) = 0;
	    }
    break;

  case 53:
#line 765 "grammar.y"
    {
#line 793 "grammar.y.pre"
		
		(yyval.type) = (yyvsp[(1) - (2)].type) | (yyvsp[(2) - (2)].type);
		
	    }
    break;

  case 54:
#line 775 "grammar.y"
    {
#line 819 "grammar.y.pre"
		(yyval.type) = ((yyvsp[(1) - (2)].type) << 16) | (yyvsp[(2) - (2)].type);
		current_type = (yyval.type);
	    }
    break;

  case 55:
#line 784 "grammar.y"
    {
#line 827 "grammar.y.pre"
		(yyval.type) = (yyvsp[(2) - (4)].type) | (yyvsp[(3) - (4)].type);
	    }
    break;

  case 57:
#line 793 "grammar.y"
    {
#line 835 "grammar.y.pre"
		(yyval.type) = TYPE_UNKNOWN;
	    }
    break;

  case 60:
#line 806 "grammar.y"
    {
#line 847 "grammar.y.pre"
		if (current_type & (FUNC_VARARGS << 16)){
		    yyerror("Illegal to declare varargs variable.");
		    current_type &= ~(FUNC_VARARGS << 16);
		}
		/* Now it is ok to merge the two
		 * remember that class_num and varargs was the reason for above
		 * Do the merging once only per row of decls
		 */

		if (current_type & 0xffff0000){
		    current_type = (current_type >> 16) | (current_type & 0xffff);
		}

		current_type |= global_modifiers;

		if (!(current_type & DECL_ACCESS)) current_type |= DECL_PUBLIC;

		if ((current_type & ~DECL_MODS) == TYPE_VOID)
		    yyerror("Illegal to declare global variable of type void.");

		define_new_variable((yyvsp[(2) - (2)].string), current_type | (yyvsp[(1) - (2)].type));
		scratch_free((yyvsp[(2) - (2)].string));
	    }
    break;

  case 61:
#line 832 "grammar.y"
    {
#line 872 "grammar.y.pre"
		parse_node_t *expr, *newnode;
		int type;

		if (current_type & (FUNC_VARARGS << 16)){
		    yyerror("Illegal to declare varargs variable.");
		    current_type &= ~(FUNC_VARARGS << 16);
		}
		
		if (current_type & 0xffff0000){
		    current_type = (current_type >> 16) | (current_type & 0xffff);
		}

		current_type |= global_modifiers;

		if (!(current_type & DECL_ACCESS)) current_type |= DECL_PUBLIC;

		if ((current_type & ~DECL_MODS) == TYPE_VOID)
		    yyerror("Illegal to declare global variable of type void.");

		if ((yyvsp[(3) - (4)].number) != F_ASSIGN)
		    yyerror("Only '=' is legal in initializers.");

		/* ignore current_type == 0, which gets a missing type error
		   later anyway */
		if (current_type) {
		    type = (current_type | (yyvsp[(1) - (4)].type)) & ~DECL_MODS;
		    if ((current_type & ~DECL_MODS) == TYPE_VOID)
			yyerror("Illegal to declare global variable of type void.");
		    if (!compatible_types(type, (yyvsp[(4) - (4)].node)->type)) {
			char buff[256];
			char *end = EndOf(buff);
			char *p;
			
			p = strput(buff, end, "Type mismatch ");
			p = get_two_types(p, end, type, (yyvsp[(4) - (4)].node)->type);
			p = strput(p, end, " when initializing ");
			p = strput(p, end, (yyvsp[(2) - (4)].string));
			yyerror(buff);
		    }
		}
		(yyvsp[(4) - (4)].node) = do_promotions((yyvsp[(4) - (4)].node), type);

		CREATE_BINARY_OP(expr, F_VOID_ASSIGN, 0, (yyvsp[(4) - (4)].node), 0);
		CREATE_OPCODE_1(expr->r.expr, F_GLOBAL_LVALUE, 0,
				define_new_variable((yyvsp[(2) - (4)].string), current_type | (yyvsp[(1) - (4)].type)));
		newnode = comp_trees[TREE_INIT];
		CREATE_TWO_VALUES(comp_trees[TREE_INIT], 0,
				  newnode, expr);
		scratch_free((yyvsp[(2) - (4)].string));
	    }
    break;

  case 62:
#line 888 "grammar.y"
    {
#line 927 "grammar.y.pre"
		if ((yyvsp[(2) - (4)].decl).node && (yyvsp[(3) - (4)].node)) {
		    CREATE_STATEMENTS((yyval.decl).node, (yyvsp[(2) - (4)].decl).node, (yyvsp[(3) - (4)].node));
		} else (yyval.decl).node = ((yyvsp[(2) - (4)].decl).node ? (yyvsp[(2) - (4)].decl).node : (yyvsp[(3) - (4)].node));
                (yyval.decl).num = (yyvsp[(2) - (4)].decl).num;
            }
    break;

  case 66:
#line 901 "grammar.y"
    {
#line 939 "grammar.y.pre"
                (yyval.decl).node = 0;
                (yyval.decl).num = 0;
            }
    break;

  case 67:
#line 907 "grammar.y"
    {
#line 944 "grammar.y.pre"
		if ((yyvsp[(2) - (2)].type) == TYPE_VOID)
		    yyerror("Illegal to declare local variable of type void.");
                /* can't do this in basic_type b/c local_name_list contains
                 * expr0 which contains cast which contains basic_type
                 */
                current_type = (yyvsp[(2) - (2)].type);
            }
    break;

  case 68:
#line 917 "grammar.y"
    {
#line 953 "grammar.y.pre"
                if ((yyvsp[(1) - (5)].decl).node && (yyvsp[(4) - (5)].decl).node) {
		    CREATE_STATEMENTS((yyval.decl).node, (yyvsp[(1) - (5)].decl).node, (yyvsp[(4) - (5)].decl).node);
                } else (yyval.decl).node = ((yyvsp[(1) - (5)].decl).node ? (yyvsp[(1) - (5)].decl).node : (yyvsp[(4) - (5)].decl).node);
                (yyval.decl).num = (yyvsp[(1) - (5)].decl).num + (yyvsp[(4) - (5)].decl).num;
            }
    break;

  case 69:
#line 929 "grammar.y"
    {
#line 964 "grammar.y.pre"
		if (current_type & LOCAL_MOD_REF) {
		    yyerror("Illegal to declare local variable as reference");
		    current_type &= ~LOCAL_MOD_REF;
		}
		add_local_name((yyvsp[(2) - (2)].string), current_type | (yyvsp[(1) - (2)].type) | LOCAL_MOD_UNUSED);

		scratch_free((yyvsp[(2) - (2)].string));
		(yyval.node) = 0;
	    }
    break;

  case 70:
#line 941 "grammar.y"
    {
#line 975 "grammar.y.pre"
		int type = (current_type | (yyvsp[(1) - (4)].type)) & ~DECL_MODS;

		if (current_type & LOCAL_MOD_REF) {
		    yyerror("Illegal to declare local variable as reference");
		    current_type &= ~LOCAL_MOD_REF;
		    type &= ~LOCAL_MOD_REF;
		}

		if ((yyvsp[(3) - (4)].number) != F_ASSIGN)
		    yyerror("Only '=' is allowed in initializers.");
		if (!compatible_types((yyvsp[(4) - (4)].node)->type, type)) {
		    char buff[256];
		    char *end = EndOf(buff);
		    char *p;
		    
		    p = strput(buff, end, "Type mismatch ");
		    p = get_two_types(p, end, type, (yyvsp[(4) - (4)].node)->type);
		    p = strput(p, end, " when initializing ");
		    p = strput(p, end, (yyvsp[(2) - (4)].string));

		    yyerror(buff);
		}
		
		(yyvsp[(4) - (4)].node) = do_promotions((yyvsp[(4) - (4)].node), type);

		CREATE_UNARY_OP_1((yyval.node), F_VOID_ASSIGN_LOCAL, 0, (yyvsp[(4) - (4)].node),
				  add_local_name((yyvsp[(2) - (4)].string), current_type | (yyvsp[(1) - (4)].type) | LOCAL_MOD_UNUSED));
		scratch_free((yyvsp[(2) - (4)].string));
	    }
    break;

  case 71:
#line 976 "grammar.y"
    {
#line 1009 "grammar.y.pre"
		if ((yyvsp[(1) - (3)].type) == TYPE_VOID)
		    yyerror("Illegal to declare local variable of type void.");

		(yyval.number) = add_local_name((yyvsp[(3) - (3)].string), (yyvsp[(1) - (3)].type) | (yyvsp[(2) - (3)].type));
		scratch_free((yyvsp[(3) - (3)].string));
	    }
    break;

  case 72:
#line 988 "grammar.y"
    {
#line 1020 "grammar.y.pre"
                int type = type_of_locals_ptr[(yyvsp[(1) - (3)].number)];

		if (type & LOCAL_MOD_REF) {
		    yyerror("Illegal to declare local variable as reference");
		    type_of_locals_ptr[(yyvsp[(1) - (3)].number)] &= ~LOCAL_MOD_REF;
		}
		type &= ~LOCAL_MODS;

		if ((yyvsp[(2) - (3)].number) != F_ASSIGN)
		    yyerror("Only '=' is allowed in initializers.");
		if (!compatible_types((yyvsp[(3) - (3)].node)->type, type)) {
		    char buff[256];
		    char *end = EndOf(buff);
		    char *p;
		    
		    p = strput(buff, end, "Type mismatch ");
		    p = get_two_types(p, end, type, (yyvsp[(3) - (3)].node)->type);
		    p = strput(p, end, " when initializing.");
		    yyerror(buff);
		}

		(yyvsp[(3) - (3)].node) = do_promotions((yyvsp[(3) - (3)].node), type);

		/* this is an expression */
		CREATE_BINARY_OP((yyval.node), F_ASSIGN, 0, (yyvsp[(3) - (3)].node), 0);
                CREATE_OPCODE_1((yyval.node)->r.expr, F_LOCAL_LVALUE, 0, (yyvsp[(1) - (3)].number));
	    }
    break;

  case 73:
#line 1021 "grammar.y"
    {
#line 1052 "grammar.y.pre"
                (yyval.decl).node = (yyvsp[(1) - (1)].node);
                (yyval.decl).num = 1;
            }
    break;

  case 74:
#line 1027 "grammar.y"
    {
#line 1057 "grammar.y.pre"
                if ((yyvsp[(1) - (3)].node) && (yyvsp[(3) - (3)].decl).node) {
		    CREATE_STATEMENTS((yyval.decl).node, (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].decl).node);
                } else (yyval.decl).node = ((yyvsp[(1) - (3)].node) ? (yyvsp[(1) - (3)].node) : (yyvsp[(3) - (3)].decl).node);
                (yyval.decl).num = 1 + (yyvsp[(3) - (3)].decl).num;
            }
    break;

  case 75:
#line 1038 "grammar.y"
    {
#line 1067 "grammar.y.pre"
		(yyval.node) = 0;
	    }
    break;

  case 76:
#line 1043 "grammar.y"
    {
#line 1071 "grammar.y.pre"
		if ((yyvsp[(1) - (2)].node) && (yyvsp[(2) - (2)].node)) {
		    CREATE_STATEMENTS((yyval.node), (yyvsp[(1) - (2)].node), (yyvsp[(2) - (2)].node));
		} else (yyval.node) = ((yyvsp[(1) - (2)].node) ? (yyvsp[(1) - (2)].node) : (yyvsp[(2) - (2)].node));
            }
    break;

  case 77:
#line 1050 "grammar.y"
    {
#line 1077 "grammar.y.pre"
		(yyval.node) = 0;
            }
    break;

  case 78:
#line 1058 "grammar.y"
    {
#line 1084 "grammar.y.pre"
		(yyval.node) = pop_value((yyvsp[(1) - (2)].node));
#ifdef DEBUG
		{
		    parse_node_t *replacement;
		    CREATE_STATEMENTS(replacement, (yyval.node), 0);
		    CREATE_OPCODE(replacement->r.expr, F_BREAK_POINT, 0);
		    (yyval.node) = replacement;
		}
#endif
	    }
    break;

  case 84:
#line 1076 "grammar.y"
    {
#line 1101 "grammar.y.pre"
                (yyval.node) = (yyvsp[(1) - (1)].decl).node;
                pop_n_locals((yyvsp[(1) - (1)].decl).num);
            }
    break;

  case 85:
#line 1082 "grammar.y"
    {
#line 1106 "grammar.y.pre"
		(yyval.node) = 0;
	    }
    break;

  case 86:
#line 1087 "grammar.y"
    {
#line 1110 "grammar.y.pre"
		if (context & SPECIAL_CONTEXT) {
		    yyerror("Cannot break out of catch { } or time_expression { }");
		    (yyval.node) = 0;
		} else
		if (context & SWITCH_CONTEXT) {
		    CREATE_CONTROL_JUMP((yyval.node), CJ_BREAK_SWITCH);
		} else
		if (context & LOOP_CONTEXT) {
		    CREATE_CONTROL_JUMP((yyval.node), CJ_BREAK);
		    if (context & LOOP_FOREACH) {
			parse_node_t *replace;
			CREATE_STATEMENTS(replace, 0, (yyval.node));
			CREATE_OPCODE(replace->l.expr, F_EXIT_FOREACH, 0);
			(yyval.node) = replace;
		    }
		} else {
		    yyerror("break statement outside loop");
		    (yyval.node) = 0;
		}
	    }
    break;

  case 87:
#line 1110 "grammar.y"
    {
#line 1132 "grammar.y.pre"
		if (context & SPECIAL_CONTEXT)
		    yyerror("Cannot continue out of catch { } or time_expression { }");
		else
		if (!(context & LOOP_CONTEXT))
		    yyerror("continue statement outside loop");
		CREATE_CONTROL_JUMP((yyval.node), CJ_CONTINUE);
	    }
    break;

  case 88:
#line 1123 "grammar.y"
    {
#line 1144 "grammar.y.pre"
		(yyvsp[(1) - (4)].number) = context;
		context = LOOP_CONTEXT;
	    }
    break;

  case 89:
#line 1129 "grammar.y"
    {
#line 1149 "grammar.y.pre"
		CREATE_LOOP((yyval.node), 1, (yyvsp[(6) - (6)].node), 0, optimize_loop_test((yyvsp[(3) - (6)].node)));
		context = (yyvsp[(1) - (6)].number);
	    }
    break;

  case 90:
#line 1138 "grammar.y"
    {
#line 1157 "grammar.y.pre"
		(yyvsp[(1) - (1)].number) = context;
		context = LOOP_CONTEXT;
	    }
    break;

  case 91:
#line 1144 "grammar.y"
    {
#line 1162 "grammar.y.pre"
		CREATE_LOOP((yyval.node), 0, (yyvsp[(3) - (8)].node), 0, optimize_loop_test((yyvsp[(6) - (8)].node)));
		context = (yyvsp[(1) - (8)].number);
	    }
    break;

  case 92:
#line 1153 "grammar.y"
    {
#line 1170 "grammar.y.pre"
		(yyvsp[(3) - (8)].decl).node = pop_value((yyvsp[(3) - (8)].decl).node);
		(yyvsp[(1) - (8)].number) = context;
		context = LOOP_CONTEXT;
	    }
    break;

  case 93:
#line 1160 "grammar.y"
    {
#line 1176 "grammar.y.pre"
		(yyval.decl).num = (yyvsp[(3) - (10)].decl).num; /* number of declarations (0/1) */
		
		(yyvsp[(7) - (10)].node) = pop_value((yyvsp[(7) - (10)].node));
		if ((yyvsp[(7) - (10)].node) && IS_NODE((yyvsp[(7) - (10)].node), NODE_UNARY_OP, F_INC)
		    && IS_NODE((yyvsp[(7) - (10)].node)->r.expr, NODE_OPCODE_1, F_LOCAL_LVALUE)) {
		    int lvar = (yyvsp[(7) - (10)].node)->r.expr->l.number;
		    CREATE_OPCODE_1((yyvsp[(7) - (10)].node), F_LOOP_INCR, 0, lvar);
		}

		CREATE_STATEMENTS((yyval.decl).node, (yyvsp[(3) - (10)].decl).node, 0);
		CREATE_LOOP((yyval.decl).node->r.expr, 1, (yyvsp[(10) - (10)].node), (yyvsp[(7) - (10)].node), optimize_loop_test((yyvsp[(5) - (10)].node)));

		context = (yyvsp[(1) - (10)].number);
	      }
    break;

  case 94:
#line 1179 "grammar.y"
    {
#line 1194 "grammar.y.pre"
		if ((yyvsp[(1) - (1)].ihe)->dn.local_num != -1) {
		    CREATE_OPCODE_1((yyval.decl).node, F_LOCAL_LVALUE, 0, (yyvsp[(1) - (1)].ihe)->dn.local_num);
		    type_of_locals_ptr[(yyvsp[(1) - (1)].ihe)->dn.local_num] &= ~LOCAL_MOD_UNUSED;
		} else
		if ((yyvsp[(1) - (1)].ihe)->dn.global_num != -1) {
		    CREATE_OPCODE_1((yyval.decl).node, F_GLOBAL_LVALUE, 0, (yyvsp[(1) - (1)].ihe)->dn.global_num);
		} else {
		    char buf[256];
		    char *end = EndOf(buf);
		    char *p;

		    p = strput(buf, end, "'");
		    p = strput(p, end, (yyvsp[(1) - (1)].ihe)->name);
		    p = strput(p, end, "' is not a local or a global variable.");
		    yyerror(buf);
		    CREATE_OPCODE_1((yyval.decl).node, F_GLOBAL_LVALUE, 0, 0);
		}
		(yyval.decl).num = 0;
	    }
    break;

  case 95:
#line 1201 "grammar.y"
    {
#line 1215 "grammar.y.pre"
		if (type_of_locals_ptr[(yyvsp[(1) - (1)].number)] & LOCAL_MOD_REF) {
		    CREATE_OPCODE_1((yyval.decl).node, F_REF_LVALUE, 0, (yyvsp[(1) - (1)].number));
		} else {
		    CREATE_OPCODE_1((yyval.decl).node, F_LOCAL_LVALUE, 0, (yyvsp[(1) - (1)].number));
		    type_of_locals_ptr[(yyvsp[(1) - (1)].number)] &= ~LOCAL_MOD_UNUSED;
		}
		(yyval.decl).num = 1;
            }
    break;

  case 96:
#line 1212 "grammar.y"
    {
#line 1225 "grammar.y.pre"
		char buf[256];
		char *end = EndOf(buf);
		char *p;
		
		p = strput(buf, end, "'");
		p = strput(p, end, (yyvsp[(1) - (1)].string));
		p = strput(p, end, "' is not a local or a global variable.");
		yyerror(buf);
		CREATE_OPCODE_1((yyval.decl).node, F_GLOBAL_LVALUE, 0, 0);
		scratch_free((yyvsp[(1) - (1)].string));
		(yyval.decl).num = 0;
	    }
    break;

  case 97:
#line 1230 "grammar.y"
    {
#line 1242 "grammar.y.pre"
		CREATE_FOREACH((yyval.decl).node, (yyvsp[(1) - (1)].decl).node, 0);
		(yyval.decl).num = (yyvsp[(1) - (1)].decl).num;
            }
    break;

  case 98:
#line 1236 "grammar.y"
    {
#line 1247 "grammar.y.pre"
		CREATE_FOREACH((yyval.decl).node, (yyvsp[(1) - (3)].decl).node, (yyvsp[(3) - (3)].decl).node);
		(yyval.decl).num = (yyvsp[(1) - (3)].decl).num + (yyvsp[(3) - (3)].decl).num;
		if ((yyvsp[(1) - (3)].decl).node->v.number == F_REF_LVALUE)
		    yyerror("Mapping key may not be a reference in foreach()");
            }
    break;

  case 99:
#line 1247 "grammar.y"
    {
#line 1257 "grammar.y.pre"
		(yyvsp[(3) - (6)].decl).node->v.expr = (yyvsp[(5) - (6)].node);
		(yyvsp[(1) - (6)].number) = context;
		context = LOOP_CONTEXT | LOOP_FOREACH;
            }
    break;

  case 100:
#line 1254 "grammar.y"
    {
#line 1263 "grammar.y.pre"
		(yyval.decl).num = (yyvsp[(3) - (8)].decl).num;

		CREATE_STATEMENTS((yyval.decl).node, (yyvsp[(3) - (8)].decl).node, 0);
		CREATE_LOOP((yyval.decl).node->r.expr, 2, (yyvsp[(8) - (8)].node), 0, 0);
		CREATE_OPCODE((yyval.decl).node->r.expr->r.expr, F_NEXT_FOREACH, 0);
		
		context = (yyvsp[(1) - (8)].number);
	    }
    break;

  case 101:
#line 1268 "grammar.y"
    {
#line 1276 "grammar.y.pre"
		(yyval.node) = 0;
	    }
    break;

  case 103:
#line 1277 "grammar.y"
    {
#line 1284 "grammar.y.pre"
	 	(yyval.decl).node = (yyvsp[(1) - (1)].node);
		(yyval.decl).num = 0;
	    }
    break;

  case 104:
#line 1283 "grammar.y"
    {
#line 1289 "grammar.y.pre"
		(yyval.decl).node = (yyvsp[(1) - (1)].node);
		(yyval.decl).num = 1;
	    }
    break;

  case 105:
#line 1292 "grammar.y"
    {
#line 1297 "grammar.y.pre"
                (yyvsp[(1) - (4)].number) = context;
                context &= LOOP_CONTEXT;
                context |= SWITCH_CONTEXT;
                (yyvsp[(2) - (4)].number) = mem_block[A_CASES].current_size;
            }
    break;

  case 106:
#line 1300 "grammar.y"
    {
#line 1304 "grammar.y.pre"
                parse_node_t *node1, *node2;

                if ((yyvsp[(9) - (10)].node)) {
		    CREATE_STATEMENTS(node1, (yyvsp[(8) - (10)].node), (yyvsp[(9) - (10)].node));
                } else node1 = (yyvsp[(8) - (10)].node);

                if (context & SWITCH_STRINGS) {
                    NODE_NO_LINE(node2, NODE_SWITCH_STRINGS);
                } else if (context & SWITCH_RANGES) {
		    NODE_NO_LINE(node2, NODE_SWITCH_RANGES);
		} else {
                    NODE_NO_LINE(node2, NODE_SWITCH_NUMBERS);
                }

                node2->l.expr = (yyvsp[(3) - (10)].node);
                node2->r.expr = node1;
                prepare_cases(node2, (yyvsp[(2) - (10)].number));
                context = (yyvsp[(1) - (10)].number);
		(yyval.node) = node2;
		pop_n_locals((yyvsp[(7) - (10)].decl).num);
            }
    break;

  case 107:
#line 1327 "grammar.y"
    {
#line 1330 "grammar.y.pre"
               if ((yyvsp[(2) - (2)].node)){
		   CREATE_STATEMENTS((yyval.node), (yyvsp[(1) - (2)].node), (yyvsp[(2) - (2)].node));
               } else (yyval.node) = (yyvsp[(1) - (2)].node);
           }
    break;

  case 108:
#line 1334 "grammar.y"
    {
#line 1336 "grammar.y.pre"
               if ((yyvsp[(2) - (2)].node)){
		   CREATE_STATEMENTS((yyval.node), (yyvsp[(1) - (2)].node), (yyvsp[(2) - (2)].node));
               } else (yyval.node) = (yyvsp[(1) - (2)].node);
           }
    break;

  case 109:
#line 1341 "grammar.y"
    {
#line 1342 "grammar.y.pre"
               (yyval.node) = 0;
           }
    break;

  case 110:
#line 1350 "grammar.y"
    {
#line 1350 "grammar.y.pre"
                (yyval.node) = (yyvsp[(2) - (3)].node);
                (yyval.node)->v.expr = 0;

                add_to_mem_block(A_CASES, (char *)&((yyvsp[(2) - (3)].node)), sizeof((yyvsp[(2) - (3)].node)));
            }
    break;

  case 111:
#line 1358 "grammar.y"
    {
#line 1357 "grammar.y.pre"
                if ( (yyvsp[(2) - (5)].node)->kind != NODE_CASE_NUMBER
                    || (yyvsp[(4) - (5)].node)->kind != NODE_CASE_NUMBER )
                    yyerror("String case labels not allowed as range bounds");
                if ((yyvsp[(2) - (5)].node)->r.number > (yyvsp[(4) - (5)].node)->r.number) break;

		context |= SWITCH_RANGES;

                (yyval.node) = (yyvsp[(2) - (5)].node);
                (yyval.node)->v.expr = (yyvsp[(4) - (5)].node);

                add_to_mem_block(A_CASES, (char *)&((yyvsp[(2) - (5)].node)), sizeof((yyvsp[(2) - (5)].node)));
            }
    break;

  case 112:
#line 1373 "grammar.y"
    {
#line 1371 "grammar.y.pre"
                if (context & SWITCH_DEFAULT) {
                    yyerror("Duplicate default");
                    (yyval.node) = 0;
                    break;
                }
		(yyval.node) = new_node();
		(yyval.node)->kind = NODE_DEFAULT;
                (yyval.node)->v.expr = 0;
                add_to_mem_block(A_CASES, (char *)&((yyval.node)), sizeof((yyval.node)));
                context |= SWITCH_DEFAULT;
            }
    break;

  case 113:
#line 1390 "grammar.y"
    {
#line 1387 "grammar.y.pre"
                if ((context & SWITCH_STRINGS) && (yyvsp[(1) - (1)].pointer_int))
                    yyerror("Mixed case label list not allowed");

                if ((yyvsp[(1) - (1)].pointer_int)) context |= SWITCH_NUMBERS;

		(yyval.node) = new_node();
		(yyval.node)->kind = NODE_CASE_NUMBER;
                (yyval.node)->r.expr = (parse_node_t *)(yyvsp[(1) - (1)].pointer_int);
            }
    break;

  case 114:
#line 1402 "grammar.y"
    {
#line 1398 "grammar.y.pre"
		int str;
		
		str = store_prog_string((yyvsp[(1) - (1)].string));
                scratch_free((yyvsp[(1) - (1)].string));
                if (context & SWITCH_NUMBERS)
                    yyerror("Mixed case label list not allowed");
                context |= SWITCH_STRINGS;
		(yyval.node) = new_node();
		(yyval.node)->kind = NODE_CASE_STRING;
                (yyval.node)->r.number = str;
            }
    break;

  case 115:
#line 1419 "grammar.y"
    {
#line 1414 "grammar.y.pre"
                (yyval.pointer_int) = (yyvsp[(1) - (3)].pointer_int) | (yyvsp[(3) - (3)].pointer_int);
            }
    break;

  case 116:
#line 1424 "grammar.y"
    {
#line 1418 "grammar.y.pre"
                (yyval.pointer_int) = (yyvsp[(1) - (3)].pointer_int) ^ (yyvsp[(3) - (3)].pointer_int);
            }
    break;

  case 117:
#line 1429 "grammar.y"
    {
#line 1422 "grammar.y.pre"
                (yyval.pointer_int) = (yyvsp[(1) - (3)].pointer_int) & (yyvsp[(3) - (3)].pointer_int);
            }
    break;

  case 118:
#line 1434 "grammar.y"
    {
#line 1426 "grammar.y.pre"
                (yyval.pointer_int) = (yyvsp[(1) - (3)].pointer_int) == (yyvsp[(3) - (3)].pointer_int);
            }
    break;

  case 119:
#line 1439 "grammar.y"
    {
#line 1430 "grammar.y.pre"
                (yyval.pointer_int) = (yyvsp[(1) - (3)].pointer_int) != (yyvsp[(3) - (3)].pointer_int);
            }
    break;

  case 120:
#line 1444 "grammar.y"
    {
#line 1434 "grammar.y.pre"
                switch((yyvsp[(2) - (3)].number)){
                    case F_GE: (yyval.pointer_int) = (yyvsp[(1) - (3)].pointer_int) >= (yyvsp[(3) - (3)].pointer_int); break;
                    case F_LE: (yyval.pointer_int) = (yyvsp[(1) - (3)].pointer_int) <= (yyvsp[(3) - (3)].pointer_int); break;
                    case F_GT: (yyval.pointer_int) = (yyvsp[(1) - (3)].pointer_int) >  (yyvsp[(3) - (3)].pointer_int); break;
                }
            }
    break;

  case 121:
#line 1453 "grammar.y"
    {
#line 1442 "grammar.y.pre"
                (yyval.pointer_int) = (yyvsp[(1) - (3)].pointer_int) < (yyvsp[(3) - (3)].pointer_int);
            }
    break;

  case 122:
#line 1458 "grammar.y"
    {
#line 1446 "grammar.y.pre"
                (yyval.pointer_int) = (yyvsp[(1) - (3)].pointer_int) << (yyvsp[(3) - (3)].pointer_int);
            }
    break;

  case 123:
#line 1463 "grammar.y"
    {
#line 1450 "grammar.y.pre"
                (yyval.pointer_int) = (yyvsp[(1) - (3)].pointer_int) >> (yyvsp[(3) - (3)].pointer_int);
            }
    break;

  case 124:
#line 1468 "grammar.y"
    {
#line 1454 "grammar.y.pre"
                (yyval.pointer_int) = (yyvsp[(1) - (3)].pointer_int) + (yyvsp[(3) - (3)].pointer_int);
            }
    break;

  case 125:
#line 1473 "grammar.y"
    {
#line 1458 "grammar.y.pre"
                (yyval.pointer_int) = (yyvsp[(1) - (3)].pointer_int) - (yyvsp[(3) - (3)].pointer_int);
            }
    break;

  case 126:
#line 1478 "grammar.y"
    {
#line 1462 "grammar.y.pre"
                (yyval.pointer_int) = (yyvsp[(1) - (3)].pointer_int) * (yyvsp[(3) - (3)].pointer_int);
            }
    break;

  case 127:
#line 1483 "grammar.y"
    {
#line 1466 "grammar.y.pre"
                if ((yyvsp[(3) - (3)].pointer_int)) (yyval.pointer_int) = (yyvsp[(1) - (3)].pointer_int) % (yyvsp[(3) - (3)].pointer_int); else yyerror("Modulo by zero");
            }
    break;

  case 128:
#line 1488 "grammar.y"
    {
#line 1470 "grammar.y.pre"
                if ((yyvsp[(3) - (3)].pointer_int)) (yyval.pointer_int) = (yyvsp[(1) - (3)].pointer_int) / (yyvsp[(3) - (3)].pointer_int); else yyerror("Division by zero");
            }
    break;

  case 129:
#line 1493 "grammar.y"
    {
#line 1474 "grammar.y.pre"
                (yyval.pointer_int) = (yyvsp[(2) - (3)].pointer_int);
            }
    break;

  case 130:
#line 1498 "grammar.y"
    {
#line 1478 "grammar.y.pre"
		(yyval.pointer_int) = (yyvsp[(1) - (1)].number);
	    }
    break;

  case 131:
#line 1503 "grammar.y"
    {
#line 1482 "grammar.y.pre"
                (yyval.pointer_int) = -(yyvsp[(2) - (2)].number);
            }
    break;

  case 132:
#line 1508 "grammar.y"
    {
#line 1486 "grammar.y.pre"
                (yyval.pointer_int) = !(yyvsp[(2) - (2)].number);
            }
    break;

  case 133:
#line 1513 "grammar.y"
    {
#line 1490 "grammar.y.pre"
                (yyval.pointer_int) = ~(yyvsp[(2) - (2)].number);
            }
    break;

  case 134:
#line 1521 "grammar.y"
    {
#line 1497 "grammar.y.pre"
		(yyval.node) = (yyvsp[(1) - (1)].node);
	    }
    break;

  case 135:
#line 1526 "grammar.y"
    {
#line 1501 "grammar.y.pre"
		CREATE_TWO_VALUES((yyval.node), (yyvsp[(3) - (3)].node)->type, pop_value((yyvsp[(1) - (3)].node)), (yyvsp[(3) - (3)].node));
	    }
    break;

  case 137:
#line 1538 "grammar.y"
    {
#line 1518 "grammar.y.pre"
		int op;

		if (!(context & ARG_LIST))
		    yyerror("ref illegal outside function argument list");
		else
		    num_refs++;
		
		switch ((yyvsp[(2) - (2)].node)->kind) {
		case NODE_PARAMETER_LVALUE:
		    op = F_LOCAL_LVALUE;
		    break;
		case NODE_TERNARY_OP:
		case NODE_OPCODE_1:
		case NODE_UNARY_OP_1:
		case NODE_BINARY_OP:
		    op = (yyvsp[(2) - (2)].node)->v.number;
		    if (op > F_RINDEX_LVALUE) {
			yyerror("Illegal to make reference to range");
			break;
		    }
		}
		CREATE_UNARY_OP_1((yyval.node), F_MAKE_REF, TYPE_ANY, (yyvsp[(2) - (2)].node), op);
	    }
    break;

  case 138:
#line 1565 "grammar.y"
    {
#line 1545 "grammar.y.pre"
	        parse_node_t *l = (yyvsp[(1) - (3)].node), *r = (yyvsp[(3) - (3)].node);
		/* set this up here so we can change it below */
		/* assignments are backwards; rhs is evaluated before
		   lhs, so put the RIGHT hand side on the LEFT hand
		   side of the tree node. */
		CREATE_BINARY_OP((yyval.node), (yyvsp[(2) - (3)].number), r->type, r, l);

		if (exact_types && !compatible_types(r->type, l->type) &&
		    !((yyvsp[(2) - (3)].number) == F_ADD_EQ
		      && r->type == TYPE_STRING && 
		      COMP_TYPE(l->type, TYPE_NUMBER))) {
		    char buf[256];
		    char *end = EndOf(buf);
		    char *p;
		    
		    p = strput(buf, end, "Bad assignment ");
		    p = get_two_types(p, end, l->type, r->type);
		    p = strput(p, end, ".");
		    yyerror(buf);
		}
		
		if ((yyvsp[(2) - (3)].number) == F_ASSIGN)
		    (yyval.node)->l.expr = do_promotions(r, l->type);
	    }
    break;

  case 139:
#line 1592 "grammar.y"
    {
#line 1571 "grammar.y.pre"
		yyerror("Illegal LHS");
		CREATE_ERROR((yyval.node));
	    }
    break;

  case 140:
#line 1598 "grammar.y"
    {
#line 1576 "grammar.y.pre"
		parse_node_t *p1 = (yyvsp[(3) - (5)].node), *p2 = (yyvsp[(5) - (5)].node);

		if (exact_types && !compatible_types2(p1->type, p2->type)) {
		    char buf[256];
		    char *end = EndOf(buf);
		    char *p;
		    
		    p = strput(buf, end, "Types in ?: do not match ");
		    p = get_two_types(p, end, p1->type, p2->type);
		    p = strput(p, end, ".");
		    yywarn(buf);
		}

		/* optimize if last expression did F_NOT */
		if (IS_NODE((yyvsp[(1) - (5)].node), NODE_UNARY_OP, F_NOT)) {
		    /* !a ? b : c  --> a ? c : b */
		    CREATE_IF((yyval.node), (yyvsp[(1) - (5)].node)->r.expr, p2, p1);
		} else {
		    CREATE_IF((yyval.node), (yyvsp[(1) - (5)].node), p1, p2);
		}
		(yyval.node)->type = ((p1->type == p2->type) ? p1->type : TYPE_ANY);
	    }
    break;

  case 141:
#line 1623 "grammar.y"
    {
#line 1600 "grammar.y.pre"
		CREATE_LAND_LOR((yyval.node), F_LOR, (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node));
		if (IS_NODE((yyvsp[(1) - (3)].node), NODE_LAND_LOR, F_LOR))
		    (yyvsp[(1) - (3)].node)->kind = NODE_BRANCH_LINK;
	    }
    break;

  case 142:
#line 1630 "grammar.y"
    {
#line 1606 "grammar.y.pre"
		CREATE_LAND_LOR((yyval.node), F_LAND, (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node));
		if (IS_NODE((yyvsp[(1) - (3)].node), NODE_LAND_LOR, F_LAND))
		    (yyvsp[(1) - (3)].node)->kind = NODE_BRANCH_LINK;
	    }
    break;

  case 143:
#line 1637 "grammar.y"
    {
#line 1612 "grammar.y.pre"
		int t1 = (yyvsp[(1) - (3)].node)->type, t3 = (yyvsp[(3) - (3)].node)->type;
		
		if (is_boolean((yyvsp[(1) - (3)].node)) && is_boolean((yyvsp[(3) - (3)].node)))
		    yywarn("bitwise operation on boolean values.");
		if ((t1 & TYPE_MOD_ARRAY) || (t3 & TYPE_MOD_ARRAY)) {
		    if (t1 != t3) {
			if ((t1 != TYPE_ANY) && (t3 != TYPE_ANY) &&
			    !(t1 & t3 & TYPE_MOD_ARRAY)) {
			    char buf[256];
			    char *end = EndOf(buf);
			    char *p;

			    p = strput(buf, end, "Incompatible types for | ");
			    p = get_two_types(p, end, t1, t3);
			    p = strput(p, end, ".");
			    yyerror(buf);
			}
			t1 = TYPE_ANY | TYPE_MOD_ARRAY;
		    }
		    CREATE_BINARY_OP((yyval.node), F_OR, t1, (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node));
		}
		else (yyval.node) = binary_int_op((yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node), F_OR, "|");		
	    }
    break;

  case 144:
#line 1663 "grammar.y"
    {
#line 1637 "grammar.y.pre"
		(yyval.node) = binary_int_op((yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node), F_XOR, "^");
	    }
    break;

  case 145:
#line 1668 "grammar.y"
    {
#line 1641 "grammar.y.pre"
		int t1 = (yyvsp[(1) - (3)].node)->type, t3 = (yyvsp[(3) - (3)].node)->type;
		if (is_boolean((yyvsp[(1) - (3)].node)) && is_boolean((yyvsp[(3) - (3)].node)))
		    yywarn("bitwise operation on boolean values.");
		if ((t1 & TYPE_MOD_ARRAY) || (t3 & TYPE_MOD_ARRAY)) {
		    if (t1 != t3) {
			if ((t1 != TYPE_ANY) && (t3 != TYPE_ANY) &&
			    !(t1 & t3 & TYPE_MOD_ARRAY)) {
			    char buf[256];
			    char *end = EndOf(buf);
			    char *p;
			    
			    p = strput(buf, end, "Incompatible types for & ");
			    p = get_two_types(p, end, t1, t3);
			    p = strput(p, end, ".");
			    yyerror(buf);
			}
			t1 = TYPE_ANY | TYPE_MOD_ARRAY;
		    } 
		    CREATE_BINARY_OP((yyval.node), F_AND, t1, (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node));
		} else (yyval.node) = binary_int_op((yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node), F_AND, "&");
	    }
    break;

  case 146:
#line 1692 "grammar.y"
    {
#line 1664 "grammar.y.pre"
		if (exact_types && !compatible_types2((yyvsp[(1) - (3)].node)->type, (yyvsp[(3) - (3)].node)->type)){
		    char buf[256];
		    char *end = EndOf(buf);
		    char *p;
		    
		    p = strput(buf, end, "== always false because of incompatible types ");
		    p = get_two_types(p, end, (yyvsp[(1) - (3)].node)->type, (yyvsp[(3) - (3)].node)->type);
		    p = strput(p, end, ".");
		    yyerror(buf);
		}
		/* x == 0 -> !x */
		if (IS_NODE((yyvsp[(1) - (3)].node), NODE_NUMBER, 0)) {
		    CREATE_UNARY_OP((yyval.node), F_NOT, TYPE_NUMBER, (yyvsp[(3) - (3)].node));
		} else
		if (IS_NODE((yyvsp[(3) - (3)].node), NODE_NUMBER, 0)) {
		    CREATE_UNARY_OP((yyval.node), F_NOT, TYPE_NUMBER, (yyvsp[(1) - (3)].node));
		} else {
		    CREATE_BINARY_OP((yyval.node), F_EQ, TYPE_NUMBER, (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node));
		}
	    }
    break;

  case 147:
#line 1715 "grammar.y"
    {
#line 1686 "grammar.y.pre"
		if (exact_types && !compatible_types2((yyvsp[(1) - (3)].node)->type, (yyvsp[(3) - (3)].node)->type)){
		    char buf[256];
		    char *end = EndOf(buf);
		    char *p;

		    p = strput(buf, end, "!= always true because of incompatible types ");
		    p = get_two_types(p, end, (yyvsp[(1) - (3)].node)->type, (yyvsp[(3) - (3)].node)->type);
		    p = strput(p, end, ".");
		    yyerror(buf);
		}
                CREATE_BINARY_OP((yyval.node), F_NE, TYPE_NUMBER, (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node));
	    }
    break;

  case 148:
#line 1730 "grammar.y"
    {
#line 1700 "grammar.y.pre"
		if (exact_types) {
		    int t1 = (yyvsp[(1) - (3)].node)->type;
		    int t3 = (yyvsp[(3) - (3)].node)->type;

		    if (!COMP_TYPE(t1, TYPE_NUMBER) 
			&& !COMP_TYPE(t1, TYPE_STRING)) {
			char buf[256];
			char *end = EndOf(buf);
			char *p;
			
			p = strput(buf, end, "Bad left argument to '");
			p = strput(p, end, query_instr_name((yyvsp[(2) - (3)].number)));
			p = strput(p, end, "' : \"");
			p = get_type_name(p, end, t1);
			p = strput(p, end, "\"");
			yyerror(buf);
		    } else if (!COMP_TYPE(t3, TYPE_NUMBER) 
			       && !COMP_TYPE(t3, TYPE_STRING)) {
                        char buf[256];
			char *end = EndOf(buf);
			char *p;
			
                        p = strput(buf, end, "Bad right argument to '");
                        p = strput(p, end, query_instr_name((yyvsp[(2) - (3)].number)));
                        p = strput(p, end, "' : \"");
                        p = get_type_name(p, end, t3);
			p = strput(p, end, "\"");
			yyerror(buf);
		    } else if (!compatible_types2(t1,t3)) {
			char buf[256];
			char *end = EndOf(buf);
			char *p;
			
			p = strput(buf, end, "Arguments to ");
			p = strput(p, end, query_instr_name((yyvsp[(2) - (3)].number)));
			p = strput(p, end, " do not have compatible types : ");
			p = get_two_types(p, end, t1, t3);
			yyerror(buf);
		    }
		}
                CREATE_BINARY_OP((yyval.node), (yyvsp[(2) - (3)].number), TYPE_NUMBER, (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node));
	    }
    break;

  case 149:
#line 1775 "grammar.y"
    {
#line 1744 "grammar.y.pre"
                if (exact_types) {
                    int t1 = (yyvsp[(1) - (3)].node)->type, t3 = (yyvsp[(3) - (3)].node)->type;

                    if (!COMP_TYPE(t1, TYPE_NUMBER) 
			&& !COMP_TYPE(t1, TYPE_STRING)) {
                        char buf[256];
			char *end = EndOf(buf);
			char *p;
			
			p = strput(buf, end, "Bad left argument to '<' : \"");
                        p = get_type_name(p, end, t1);
			p = strput(p, end, "\"");
                        yyerror(buf);
                    } else if (!COMP_TYPE(t3, TYPE_NUMBER)
			       && !COMP_TYPE(t3, TYPE_STRING)) {
                        char buf[200];
			char *end = EndOf(buf);
			char *p;
			
                        p = strput(buf, end, "Bad right argument to '<' : \"");
                        p = get_type_name(p, end, t3);
                        p = strput(p, end, "\"");
                        yyerror(buf);
                    } else if (!compatible_types2(t1,t3)) {
                        char buf[256];
			char *end = EndOf(buf);
			char *p;
			
			p = strput(buf, end, "Arguments to < do not have compatible types : ");
			p = get_two_types(p, end, t1, t3);
                        yyerror(buf);
                    }
                }
                CREATE_BINARY_OP((yyval.node), F_LT, TYPE_NUMBER, (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node));
            }
    break;

  case 150:
#line 1813 "grammar.y"
    {
#line 1781 "grammar.y.pre"
		(yyval.node) = binary_int_op((yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node), F_LSH, "<<");
	    }
    break;

  case 151:
#line 1818 "grammar.y"
    {
#line 1785 "grammar.y.pre"
		(yyval.node) = binary_int_op((yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node), F_RSH, ">>");
	    }
    break;

  case 152:
#line 1823 "grammar.y"
    {
#line 1789 "grammar.y.pre"
		int result_type;

		if (exact_types) {
		    int t1 = (yyvsp[(1) - (3)].node)->type, t3 = (yyvsp[(3) - (3)].node)->type;

		    if (t1 == t3){
#ifdef CAST_CALL_OTHERS
			if (t1 == TYPE_UNKNOWN){
			    yyerror("Bad arguments to '+' (unknown vs unknown)");
			    result_type = TYPE_ANY;
			} else
#endif
			    result_type = t1;
		    }
		    else if (t1 == TYPE_ANY) {
			if (t3 == TYPE_FUNCTION) {
			    yyerror("Bad right argument to '+' (function)");
			    result_type = TYPE_ANY;
			} else result_type = t3;
		    } else if (t3 == TYPE_ANY) {
			if (t1 == TYPE_FUNCTION) {
			    yyerror("Bad left argument to '+' (function)");
			    result_type = TYPE_ANY;
			} else result_type = t1;
		    } else {
			switch(t1) {
			    case TYPE_STRING:
			    {
				if (t3 == TYPE_REAL || t3 == TYPE_NUMBER){
				    result_type = TYPE_STRING;
				} else goto add_error;
				break;
			    }
			    case TYPE_NUMBER:
			    {
				if (t3 == TYPE_REAL || t3 == TYPE_STRING)
				    result_type = t3;
				else goto add_error;
				break;
			    }
			case TYPE_REAL:
			    {
				if (t3 == TYPE_NUMBER) result_type = TYPE_REAL;
				else if (t3 == TYPE_STRING) result_type = TYPE_STRING;
				else goto add_error;
				break;
			    }
			    default:
			    {
				if (t1 & t3 & TYPE_MOD_ARRAY) {
				    result_type = TYPE_ANY|TYPE_MOD_ARRAY;
				    break;
				}
add_error:
				{
				    char buf[256];
				    char *end = EndOf(buf);
				    char *p;
				    
				    p = strput(buf, end, "Invalid argument types to '+' ");
				    p = get_two_types(p, end, t1, t3);
				    yyerror(buf);
				    result_type = TYPE_ANY;
				}
			    }
			}
		    }
		} else 
		    result_type = TYPE_ANY;

		/* TODO: perhaps we should do (string)+(number) and
		 * (number)+(string) constant folding as well.
		 *
		 * codefor string x = "foo" + 1;
		 *
		 * 0000: push string 13, number 1
		 * 0004: +
		 * 0005: (void)assign_local LV0
		 */
		switch ((yyvsp[(1) - (3)].node)->kind) {
		case NODE_NUMBER:
		    /* 0 + X */
		    if ((yyvsp[(1) - (3)].node)->v.number == 0 &&
			((yyvsp[(3) - (3)].node)->type == TYPE_NUMBER || (yyvsp[(3) - (3)].node)->type == TYPE_REAL)) {
			(yyval.node) = (yyvsp[(3) - (3)].node);
			break;
		    }
		    if ((yyvsp[(3) - (3)].node)->kind == NODE_NUMBER) {
			(yyval.node) = (yyvsp[(1) - (3)].node);
			(yyvsp[(1) - (3)].node)->v.number += (yyvsp[(3) - (3)].node)->v.number;
			break;
		    }
		    if ((yyvsp[(3) - (3)].node)->kind == NODE_REAL) {
			(yyval.node) = (yyvsp[(3) - (3)].node);
			(yyvsp[(3) - (3)].node)->v.real += (yyvsp[(1) - (3)].node)->v.number;
			break;
		    }
		    /* swapping the nodes may help later constant folding */
		    if ((yyvsp[(3) - (3)].node)->type != TYPE_STRING && (yyvsp[(3) - (3)].node)->type != TYPE_ANY)
			CREATE_BINARY_OP((yyval.node), F_ADD, result_type, (yyvsp[(3) - (3)].node), (yyvsp[(1) - (3)].node));
		    else
			CREATE_BINARY_OP((yyval.node), F_ADD, result_type, (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node));
		    break;
		case NODE_REAL:
		    if ((yyvsp[(3) - (3)].node)->kind == NODE_NUMBER) {
			(yyval.node) = (yyvsp[(1) - (3)].node);
			(yyvsp[(1) - (3)].node)->v.real += (yyvsp[(3) - (3)].node)->v.number;
			break;
		    }
		    if ((yyvsp[(3) - (3)].node)->kind == NODE_REAL) {
			(yyval.node) = (yyvsp[(1) - (3)].node);
			(yyvsp[(1) - (3)].node)->v.real += (yyvsp[(3) - (3)].node)->v.real;
			break;
		    }
		    /* swapping the nodes may help later constant folding */
		    if ((yyvsp[(3) - (3)].node)->type != TYPE_STRING && (yyvsp[(3) - (3)].node)->type != TYPE_ANY)
			CREATE_BINARY_OP((yyval.node), F_ADD, result_type, (yyvsp[(3) - (3)].node), (yyvsp[(1) - (3)].node));
		    else
			CREATE_BINARY_OP((yyval.node), F_ADD, result_type, (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node));
		    break;
		case NODE_STRING:
		    if ((yyvsp[(3) - (3)].node)->kind == NODE_STRING) {
			/* Combine strings */
			int n1, n2;
			char *new, *s1, *s2;
			int l;

			n1 = (yyvsp[(1) - (3)].node)->v.number;
			n2 = (yyvsp[(3) - (3)].node)->v.number;
			s1 = PROG_STRING(n1);
			s2 = PROG_STRING(n2);
			new = (char *)DXALLOC( (l = strlen(s1))+strlen(s2)+1, TAG_COMPILER, "combine string" );
			strcpy(new, s1);
			strcat(new + l, s2);
			/* free old strings (ordering may help shrink table) */
			if (n1 > n2) {
			    free_prog_string(n1); free_prog_string(n2);
			} else {
			    free_prog_string(n2); free_prog_string(n1);
			}
			(yyval.node) = (yyvsp[(1) - (3)].node);
			(yyval.node)->v.number = store_prog_string(new);
			FREE(new);
			break;
		    }
		    /* Yes, this can actually happen for absurd code like:
		     * (int)"foo" + 0
		     * for which I guess we ought to generate (int)"foo"
		     * in order to be consistent.  Then shoot the coder.
		     */
		    /* FALLTHROUGH */
		default:
		    /* X + 0 */
		    if (IS_NODE((yyvsp[(3) - (3)].node), NODE_NUMBER, 0) &&
			((yyvsp[(1) - (3)].node)->type == TYPE_NUMBER || (yyvsp[(1) - (3)].node)->type == TYPE_REAL)) {
			(yyval.node) = (yyvsp[(1) - (3)].node);
			break;
		    }
		    CREATE_BINARY_OP((yyval.node), F_ADD, result_type, (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node));
		    break;
		}
	    }
    break;

  case 153:
#line 1988 "grammar.y"
    {
#line 1953 "grammar.y.pre"
		int result_type;

		if (exact_types) {
		    int t1 = (yyvsp[(1) - (3)].node)->type, t3 = (yyvsp[(3) - (3)].node)->type;

		    if (t1 == t3){
			switch(t1){
			    case TYPE_ANY:
			    case TYPE_NUMBER:
			    case TYPE_REAL:
			        result_type = t1;
				break;
			    default:
				if (!(t1 & TYPE_MOD_ARRAY)){
				    type_error("Bad argument number 1 to '-'", t1);
				    result_type = TYPE_ANY;
				} else result_type = t1;
			}
		    } else if (t1 == TYPE_ANY){
			switch(t3){
			    case TYPE_REAL:
			    case TYPE_NUMBER:
			        result_type = t3;
				break;
			    default:
				if (!(t3 & TYPE_MOD_ARRAY)){
				    type_error("Bad argument number 2 to '-'", t3);
				    result_type = TYPE_ANY;
				} else result_type = t3;
			}
		    } else if (t3 == TYPE_ANY){
			switch(t1){
			    case TYPE_REAL:
			    case TYPE_NUMBER:
			        result_type = t1;
				break;
			    default:
				if (!(t1 & TYPE_MOD_ARRAY)){
				    type_error("Bad argument number 1 to '-'", t1);
				    result_type = TYPE_ANY;
				} else result_type = t1;
			}
		    } else if ((t1 == TYPE_REAL && t3 == TYPE_NUMBER) ||
			       (t3 == TYPE_REAL && t1 == TYPE_NUMBER)){
			result_type = TYPE_REAL;
		    } else if (t1 & t3 & TYPE_MOD_ARRAY){
			result_type = TYPE_MOD_ARRAY|TYPE_ANY;
		    } else {
			char buf[256];
			char *end = EndOf(buf);
			char *p;
			
			p = strput(buf, end, "Invalid types to '-' ");
			p = get_two_types(p, end, t1, t3);
			yyerror(buf);
			result_type = TYPE_ANY;
		    }
		} else result_type = TYPE_ANY;
		
		switch ((yyvsp[(1) - (3)].node)->kind) {
		case NODE_NUMBER:
		    if ((yyvsp[(1) - (3)].node)->v.number == 0) {
			CREATE_UNARY_OP((yyval.node), F_NEGATE, (yyvsp[(3) - (3)].node)->type, (yyvsp[(3) - (3)].node));
		    } else if ((yyvsp[(3) - (3)].node)->kind == NODE_NUMBER) {
			(yyval.node) = (yyvsp[(1) - (3)].node);
			(yyvsp[(1) - (3)].node)->v.number -= (yyvsp[(3) - (3)].node)->v.number;
		    } else if ((yyvsp[(3) - (3)].node)->kind == NODE_REAL) {
			(yyval.node) = (yyvsp[(3) - (3)].node);
			(yyvsp[(3) - (3)].node)->v.real = (yyvsp[(1) - (3)].node)->v.number - (yyvsp[(3) - (3)].node)->v.real;
		    } else {
			CREATE_BINARY_OP((yyval.node), F_SUBTRACT, result_type, (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node));
		    }
		    break;
		case NODE_REAL:
		    if ((yyvsp[(3) - (3)].node)->kind == NODE_NUMBER) {
			(yyval.node) = (yyvsp[(1) - (3)].node);
			(yyvsp[(1) - (3)].node)->v.real -= (yyvsp[(3) - (3)].node)->v.number;
		    } else if ((yyvsp[(3) - (3)].node)->kind == NODE_REAL) {
			(yyval.node) = (yyvsp[(1) - (3)].node);
			(yyvsp[(1) - (3)].node)->v.real -= (yyvsp[(3) - (3)].node)->v.real;
		    } else {
			CREATE_BINARY_OP((yyval.node), F_SUBTRACT, result_type, (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node));
		    }
		    break;
		default:
		    /* optimize X-0 */
		    if (IS_NODE((yyvsp[(3) - (3)].node), NODE_NUMBER, 0)) {
			(yyval.node) = (yyvsp[(1) - (3)].node);
		    } 
		    CREATE_BINARY_OP((yyval.node), F_SUBTRACT, result_type, (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node));
		}
	    }
    break;

  case 154:
#line 2083 "grammar.y"
    {
#line 2047 "grammar.y.pre"
		int result_type;

		if (exact_types){
		    int t1 = (yyvsp[(1) - (3)].node)->type, t3 = (yyvsp[(3) - (3)].node)->type;

		    if (t1 == t3){
			switch(t1){
			    case TYPE_MAPPING:
			    case TYPE_ANY:
			    case TYPE_NUMBER:
			    case TYPE_REAL:
			        result_type = t1;
				break;
			default:
				type_error("Bad argument number 1 to '*'", t1);
				result_type = TYPE_ANY;
			}
		    } else if (t1 == TYPE_ANY || t3 == TYPE_ANY){
			int t = (t1 == TYPE_ANY) ? t3 : t1;
			switch(t){
			    case TYPE_NUMBER:
			    case TYPE_REAL:
			    case TYPE_MAPPING:
			        result_type = t;
				break;
			    default:
				type_error((t1 == TYPE_ANY) ?
					   "Bad argument number 2 to '*'" :
					   "Bad argument number 1 to '*'",
					   t);
				result_type = TYPE_ANY;
			}
		    } else if ((t1 == TYPE_NUMBER && t3 == TYPE_REAL) ||
			       (t1 == TYPE_REAL && t3 == TYPE_NUMBER)){
			result_type = TYPE_REAL;
		    } else {
			char buf[256];
			char *end = EndOf(buf);
			char *p;
			
			p = strput(buf, end, "Invalid types to '*' ");
			p = get_two_types(p, end, t1, t3);
			yyerror(buf);
			result_type = TYPE_ANY;
		    }
		} else result_type = TYPE_ANY;

		switch ((yyvsp[(1) - (3)].node)->kind) {
		case NODE_NUMBER:
		    if ((yyvsp[(3) - (3)].node)->kind == NODE_NUMBER) {
			(yyval.node) = (yyvsp[(1) - (3)].node);
			(yyval.node)->v.number *= (yyvsp[(3) - (3)].node)->v.number;
			break;
		    }
		    if ((yyvsp[(3) - (3)].node)->kind == NODE_REAL) {
			(yyval.node) = (yyvsp[(3) - (3)].node);
			(yyvsp[(3) - (3)].node)->v.real *= (yyvsp[(1) - (3)].node)->v.number;
			break;
		    }
		    CREATE_BINARY_OP((yyval.node), F_MULTIPLY, result_type, (yyvsp[(3) - (3)].node), (yyvsp[(1) - (3)].node));
		    break;
		case NODE_REAL:
		    if ((yyvsp[(3) - (3)].node)->kind == NODE_NUMBER) {
			(yyval.node) = (yyvsp[(1) - (3)].node);
			(yyvsp[(1) - (3)].node)->v.real *= (yyvsp[(3) - (3)].node)->v.number;
			break;
		    }
		    if ((yyvsp[(3) - (3)].node)->kind == NODE_REAL) {
			(yyval.node) = (yyvsp[(1) - (3)].node);
			(yyvsp[(1) - (3)].node)->v.real *= (yyvsp[(3) - (3)].node)->v.real;
			break;
		    }
		    CREATE_BINARY_OP((yyval.node), F_MULTIPLY, result_type, (yyvsp[(3) - (3)].node), (yyvsp[(1) - (3)].node));
		    break;
		default:
		    CREATE_BINARY_OP((yyval.node), F_MULTIPLY, result_type, (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node));
		}
	    }
    break;

  case 155:
#line 2164 "grammar.y"
    {
#line 2127 "grammar.y.pre"
		(yyval.node) = binary_int_op((yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node), F_MOD, "%");
	    }
    break;

  case 156:
#line 2169 "grammar.y"
    {
#line 2131 "grammar.y.pre"
		int result_type;

		if (exact_types){
		    int t1 = (yyvsp[(1) - (3)].node)->type, t3 = (yyvsp[(3) - (3)].node)->type;

		    if (t1 == t3){
			switch(t1){
			    case TYPE_NUMBER:
			    case TYPE_REAL:
			case TYPE_ANY:
			        result_type = t1;
				break;
			    default:
				type_error("Bad argument 1 to '/'", t1);
				result_type = TYPE_ANY;
			}
		    } else if (t1 == TYPE_ANY || t3 == TYPE_ANY){
			int t = (t1 == TYPE_ANY) ? t3 : t1;
			if (t == TYPE_REAL || t == TYPE_NUMBER)
			    result_type = t; 
			else {
			    type_error(t1 == TYPE_ANY ?
				       "Bad argument 2 to '/'" :
				       "Bad argument 1 to '/'", t);
			    result_type = TYPE_ANY;
			}
		    } else if ((t1 == TYPE_NUMBER && t3 == TYPE_REAL) ||
			       (t1 == TYPE_REAL && t3 == TYPE_NUMBER)) {
			result_type = TYPE_REAL;
		    } else {
			char buf[256];
			char *end = EndOf(buf);
			char *p;
			
			p = strput(buf, end, "Invalid types to '/' ");
			p = get_two_types(p, end, t1, t3);
			yyerror(buf);
			result_type = TYPE_ANY;
		    }
		} else result_type = TYPE_ANY;		    

		/* constant expressions */
		switch ((yyvsp[(1) - (3)].node)->kind) {
		case NODE_NUMBER:
		    if ((yyvsp[(3) - (3)].node)->kind == NODE_NUMBER) {
			if ((yyvsp[(3) - (3)].node)->v.number == 0) {
			    yyerror("Divide by zero in constant");
			    (yyval.node) = (yyvsp[(1) - (3)].node);
			    break;
			}
			(yyval.node) = (yyvsp[(1) - (3)].node);
			(yyvsp[(1) - (3)].node)->v.number /= (yyvsp[(3) - (3)].node)->v.number;
			break;
		    }
		    if ((yyvsp[(3) - (3)].node)->kind == NODE_REAL) {
			if ((yyvsp[(3) - (3)].node)->v.real == 0.0) {
			    yyerror("Divide by zero in constant");
			    (yyval.node) = (yyvsp[(1) - (3)].node);
			    break;
			}
			(yyval.node) = (yyvsp[(3) - (3)].node);
			(yyvsp[(3) - (3)].node)->v.real = ((yyvsp[(1) - (3)].node)->v.number / (yyvsp[(3) - (3)].node)->v.real);
			break;
		    }
		    CREATE_BINARY_OP((yyval.node), F_DIVIDE, result_type, (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node));
		    break;
		case NODE_REAL:
		    if ((yyvsp[(3) - (3)].node)->kind == NODE_NUMBER) {
			if ((yyvsp[(3) - (3)].node)->v.number == 0) {
			    yyerror("Divide by zero in constant");
			    (yyval.node) = (yyvsp[(1) - (3)].node);
			    break;
			}
			(yyval.node) = (yyvsp[(1) - (3)].node);
			(yyvsp[(1) - (3)].node)->v.real /= (yyvsp[(3) - (3)].node)->v.number;
			break;
		    }
		    if ((yyvsp[(3) - (3)].node)->kind == NODE_REAL) {
			if ((yyvsp[(3) - (3)].node)->v.real == 0.0) {
			    yyerror("Divide by zero in constant");
			    (yyval.node) = (yyvsp[(1) - (3)].node);
			    break;
			}
			(yyval.node) = (yyvsp[(1) - (3)].node);
			(yyvsp[(1) - (3)].node)->v.real /= (yyvsp[(3) - (3)].node)->v.real;
			break;
		    }
		    CREATE_BINARY_OP((yyval.node), F_DIVIDE, result_type, (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node));
		    break;
		default:
		    CREATE_BINARY_OP((yyval.node), F_DIVIDE, result_type, (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node));
		}
	    }
    break;

  case 157:
#line 2265 "grammar.y"
    {
#line 2226 "grammar.y.pre"
		(yyval.node) = (yyvsp[(2) - (2)].node);
		(yyval.node)->type = (yyvsp[(1) - (2)].type);

		if (exact_types &&
		    (yyvsp[(2) - (2)].node)->type != (yyvsp[(1) - (2)].type) &&
		    (yyvsp[(2) - (2)].node)->type != TYPE_ANY && 
		    (yyvsp[(2) - (2)].node)->type != TYPE_UNKNOWN &&
		    (yyvsp[(1) - (2)].type) != TYPE_VOID) {
		    char buf[256];
		    char *end = EndOf(buf);
		    char *p;
		    
		    p = strput(buf, end, "Cannot cast ");
		    p = get_type_name(p, end, (yyvsp[(2) - (2)].node)->type);
		    p = strput(p, end, "to ");
		    p = get_type_name(p, end, (yyvsp[(1) - (2)].type));
		    yyerror(buf);
		}
	    }
    break;

  case 158:
#line 2287 "grammar.y"
    {
#line 2247 "grammar.y.pre"
		CREATE_UNARY_OP((yyval.node), F_PRE_INC, 0, (yyvsp[(2) - (2)].node));
                if (exact_types){
                    switch((yyvsp[(2) - (2)].node)->type){
                        case TYPE_NUMBER:
                        case TYPE_ANY:
                        case TYPE_REAL:
                        {
                            (yyval.node)->type = (yyvsp[(2) - (2)].node)->type;
                            break;
                        }

                        default:
                        {
                            (yyval.node)->type = TYPE_ANY;
                            type_error("Bad argument 1 to ++x", (yyvsp[(2) - (2)].node)->type);
                        }
                    }
                } else (yyval.node)->type = TYPE_ANY;
	    }
    break;

  case 159:
#line 2309 "grammar.y"
    {
#line 2268 "grammar.y.pre"
		CREATE_UNARY_OP((yyval.node), F_PRE_DEC, 0, (yyvsp[(2) - (2)].node));
                if (exact_types){
                    switch((yyvsp[(2) - (2)].node)->type){
                        case TYPE_NUMBER:
                        case TYPE_ANY:
                        case TYPE_REAL:
                        {
                            (yyval.node)->type = (yyvsp[(2) - (2)].node)->type;
                            break;
                        }

                        default:
                        {
                            (yyval.node)->type = TYPE_ANY;
                            type_error("Bad argument 1 to --x", (yyvsp[(2) - (2)].node)->type);
                        }
                    }
                } else (yyval.node)->type = TYPE_ANY;

	    }
    break;

  case 160:
#line 2332 "grammar.y"
    {
#line 2290 "grammar.y.pre"
		if ((yyvsp[(2) - (2)].node)->kind == NODE_NUMBER) {
		    (yyval.node) = (yyvsp[(2) - (2)].node);
		    (yyval.node)->v.number = !((yyval.node)->v.number);
		} else {
		    CREATE_UNARY_OP((yyval.node), F_NOT, TYPE_NUMBER, (yyvsp[(2) - (2)].node));
		}
	    }
    break;

  case 161:
#line 2342 "grammar.y"
    {
#line 2299 "grammar.y.pre"
		if (exact_types && !IS_TYPE((yyvsp[(2) - (2)].node)->type, TYPE_NUMBER))
		    type_error("Bad argument to ~", (yyvsp[(2) - (2)].node)->type);
		if ((yyvsp[(2) - (2)].node)->kind == NODE_NUMBER) {
		    (yyval.node) = (yyvsp[(2) - (2)].node);
		    (yyval.node)->v.number = ~(yyval.node)->v.number;
		} else {
		    CREATE_UNARY_OP((yyval.node), F_COMPL, TYPE_NUMBER, (yyvsp[(2) - (2)].node));
		}
	    }
    break;

  case 162:
#line 2354 "grammar.y"
    {
#line 2310 "grammar.y.pre"
		int result_type;
                if (exact_types){
		    int t = (yyvsp[(2) - (2)].node)->type;
		    if (!COMP_TYPE(t, TYPE_NUMBER)){
			type_error("Bad argument to unary '-'", t);
			result_type = TYPE_ANY;
		    } else result_type = t;
		} else result_type = TYPE_ANY;

		switch ((yyvsp[(2) - (2)].node)->kind) {
		case NODE_NUMBER:
		    (yyval.node) = (yyvsp[(2) - (2)].node);
		    (yyval.node)->v.number = -(yyval.node)->v.number;
		    break;
		case NODE_REAL:
		    (yyval.node) = (yyvsp[(2) - (2)].node);
		    (yyval.node)->v.real = -(yyval.node)->v.real;
		    break;
		default:
		    CREATE_UNARY_OP((yyval.node), F_NEGATE, result_type, (yyvsp[(2) - (2)].node));
		}
	    }
    break;

  case 163:
#line 2379 "grammar.y"
    {
#line 2334 "grammar.y.pre"
		CREATE_UNARY_OP((yyval.node), F_POST_INC, 0, (yyvsp[(1) - (2)].node));
		(yyval.node)->v.number = F_POST_INC;
                if (exact_types){
                    switch((yyvsp[(1) - (2)].node)->type){
                        case TYPE_NUMBER:
		    case TYPE_ANY:
                        case TYPE_REAL:
                        {
                            (yyval.node)->type = (yyvsp[(1) - (2)].node)->type;
                            break;
                        }

                        default:
                        {
                            (yyval.node)->type = TYPE_ANY;
                            type_error("Bad argument 1 to x++", (yyvsp[(1) - (2)].node)->type);
                        }
                    }
                } else (yyval.node)->type = TYPE_ANY;
	    }
    break;

  case 164:
#line 2402 "grammar.y"
    {
#line 2356 "grammar.y.pre"
		CREATE_UNARY_OP((yyval.node), F_POST_DEC, 0, (yyvsp[(1) - (2)].node));
                if (exact_types){
                    switch((yyvsp[(1) - (2)].node)->type){
		    case TYPE_NUMBER:
		    case TYPE_ANY:
		    case TYPE_REAL:
		    {
			(yyval.node)->type = (yyvsp[(1) - (2)].node)->type;
			break;
		    }

		    default:
		    {
			(yyval.node)->type = TYPE_ANY;
			type_error("Bad argument 1 to x--", (yyvsp[(1) - (2)].node)->type);
		    }
                    }
                } else (yyval.node)->type = TYPE_ANY;
	    }
    break;

  case 171:
#line 2433 "grammar.y"
    {
#line 2386 "grammar.y.pre"
		if (exact_types && !IS_TYPE(exact_types, TYPE_VOID))
		    yywarn("Non-void functions must return a value.");
		CREATE_RETURN((yyval.node), 0);
	    }
    break;

  case 172:
#line 2440 "grammar.y"
    {
#line 2392 "grammar.y.pre"
		if (exact_types && !compatible_types((yyvsp[(2) - (3)].node)->type, exact_types)) {
		    char buf[256];
		    char *end = EndOf(buf);
		    char *p;
		    
		    p = strput(buf, end, "Type of returned value doesn't match function return type ");
		    p = get_two_types(p, end, (yyvsp[(2) - (3)].node)->type, exact_types);
		    yyerror(buf);
		}
		if (IS_NODE((yyvsp[(2) - (3)].node), NODE_NUMBER, 0)) {
		    CREATE_RETURN((yyval.node), 0);
		} else {
		    CREATE_RETURN((yyval.node), (yyvsp[(2) - (3)].node));
		}
	    }
    break;

  case 173:
#line 2461 "grammar.y"
    {
#line 2412 "grammar.y.pre"
		CREATE_EXPR_LIST((yyval.node), 0);
	    }
    break;

  case 174:
#line 2466 "grammar.y"
    {
#line 2416 "grammar.y.pre"
		CREATE_EXPR_LIST((yyval.node), (yyvsp[(1) - (1)].node));
	    }
    break;

  case 175:
#line 2471 "grammar.y"
    {
#line 2420 "grammar.y.pre"
		CREATE_EXPR_LIST((yyval.node), (yyvsp[(1) - (2)].node));
	    }
    break;

  case 176:
#line 2479 "grammar.y"
    {
#line 2427 "grammar.y.pre"
		CREATE_EXPR_NODE((yyval.node), (yyvsp[(1) - (1)].node), 0);
	    }
    break;

  case 177:
#line 2484 "grammar.y"
    {
#line 2431 "grammar.y.pre"
		CREATE_EXPR_NODE((yyval.node), (yyvsp[(1) - (2)].node), 1);
	    }
    break;

  case 178:
#line 2492 "grammar.y"
    {
#line 2438 "grammar.y.pre"
		(yyvsp[(1) - (1)].node)->kind = 1;

		(yyval.node) = (yyvsp[(1) - (1)].node);
	    }
    break;

  case 179:
#line 2499 "grammar.y"
    {
#line 2444 "grammar.y.pre"
		(yyvsp[(3) - (3)].node)->kind = 0;

		(yyval.node) = (yyvsp[(1) - (3)].node);
		(yyval.node)->kind++;
		(yyval.node)->l.expr->r.expr = (yyvsp[(3) - (3)].node);
		(yyval.node)->l.expr = (yyvsp[(3) - (3)].node);
	    }
    break;

  case 180:
#line 2512 "grammar.y"
    {
#line 2456 "grammar.y.pre"
		/* this is a dummy node */
		CREATE_EXPR_LIST((yyval.node), 0);
	    }
    break;

  case 181:
#line 2518 "grammar.y"
    {
#line 2461 "grammar.y.pre"
		CREATE_EXPR_LIST((yyval.node), (yyvsp[(1) - (1)].node));
	    }
    break;

  case 182:
#line 2523 "grammar.y"
    {
#line 2465 "grammar.y.pre"
		CREATE_EXPR_LIST((yyval.node), (yyvsp[(1) - (2)].node));
	    }
    break;

  case 183:
#line 2531 "grammar.y"
    {
#line 2472 "grammar.y.pre"
		(yyval.node) = new_node_no_line();
		(yyval.node)->kind = 2;
		(yyval.node)->v.expr = (yyvsp[(1) - (1)].node);
		(yyval.node)->r.expr = 0;
		(yyval.node)->type = 0;
		/* we keep track of the end of the chain in the left nodes */
		(yyval.node)->l.expr = (yyval.node);
            }
    break;

  case 184:
#line 2542 "grammar.y"
    {
#line 2482 "grammar.y.pre"
		parse_node_t *expr;

		expr = new_node_no_line();
		expr->kind = 0;
		expr->v.expr = (yyvsp[(3) - (3)].node);
		expr->r.expr = 0;
		expr->type = 0;
		
		(yyvsp[(1) - (3)].node)->l.expr->r.expr = expr;
		(yyvsp[(1) - (3)].node)->l.expr = expr;
		(yyvsp[(1) - (3)].node)->kind += 2;
		(yyval.node) = (yyvsp[(1) - (3)].node);
	    }
    break;

  case 185:
#line 2561 "grammar.y"
    {
#line 2500 "grammar.y.pre"
		CREATE_TWO_VALUES((yyval.node), 0, (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node));
            }
    break;

  case 186:
#line 2569 "grammar.y"
    {
#line 2507 "grammar.y.pre"
#define LV_ILLEGAL 1
#define LV_RANGE 2
#define LV_INDEX 4
                /* Restrictive lvalues, but I think they make more sense :) */
                (yyval.node) = (yyvsp[(1) - (1)].node);
                switch((yyval.node)->kind) {
		default:
		    yyerror("Illegal lvalue");
		    break;
		case NODE_PARAMETER:
		    (yyval.node)->kind = NODE_PARAMETER_LVALUE;
		    break;
		case NODE_TERNARY_OP:
		    (yyval.node)->v.number = (yyval.node)->r.expr->v.number;
		case NODE_OPCODE_1:
		case NODE_UNARY_OP_1:
		case NODE_BINARY_OP:
		    if ((yyval.node)->v.number >= F_LOCAL && (yyval.node)->v.number <= F_MEMBER)
			(yyval.node)->v.number++; /* make it an lvalue */
		    else if ((yyval.node)->v.number >= F_INDEX 
			     && (yyval.node)->v.number <= F_RE_RANGE) {
                        parse_node_t *node = (yyval.node);
                        int flag = 0;
                        do {
                            switch(node->kind) {
			    case NODE_PARAMETER:
				node->kind = NODE_PARAMETER_LVALUE;
				flag |= LV_ILLEGAL;
				break;
			    case NODE_TERNARY_OP:
				node->v.number = node->r.expr->v.number;
			    case NODE_OPCODE_1:
			    case NODE_UNARY_OP_1:
			    case NODE_BINARY_OP:
				if (node->v.number >= F_LOCAL 
				    && node->v.number <= F_MEMBER) {
				    node->v.number++;
				    flag |= LV_ILLEGAL;
				    break;
				} else if (node->v.number == F_INDEX ||
					 node->v.number == F_RINDEX) {
				    node->v.number++;
				    flag |= LV_INDEX;
				    break;
				} else if (node->v.number >= F_ADD_EQ
					   && node->v.number <= F_ASSIGN) {
				    if (!(flag & LV_INDEX)) {
					yyerror("Illegal lvalue, a possible lvalue is (x <assign> y)[a]");
				    }
				    if (node->r.expr->kind == NODE_BINARY_OP||
					node->r.expr->kind == NODE_TERNARY_OP){
					if (node->r.expr->v.number >= F_NN_RANGE_LVALUE && node->r.expr->v.number <= F_NR_RANGE_LVALUE)
					    yyerror("Illegal to have (x[a..b] <assign> y) to be the beginning of an lvalue");
				    }
				    flag = LV_ILLEGAL;
				    break;
				} else if (node->v.number >= F_NN_RANGE
					 && node->v.number <= F_RE_RANGE) {
				    if (flag & LV_RANGE) {
					yyerror("Can't do range lvalue of range lvalue.");
					flag |= LV_ILLEGAL;
					break;
				    }
                                    if (flag & LV_INDEX){
					yyerror("Can't do indexed lvalue of range lvalue.");
					flag |= LV_ILLEGAL;
					break;
				    }
				    if (node->v.number == F_NE_RANGE) {
					/* x[foo..] -> x[foo..<1] */
					parse_node_t *rchild = node->r.expr;
					node->kind = NODE_TERNARY_OP;
					CREATE_BINARY_OP(node->r.expr,
							 F_NR_RANGE_LVALUE,
							 0, 0, rchild);
					CREATE_NUMBER(node->r.expr->l.expr, 1);
				    } else if (node->v.number == F_RE_RANGE) {
					/* x[<foo..] -> x[<foo..<1] */
					parse_node_t *rchild = node->r.expr;
					node->kind = NODE_TERNARY_OP;
					CREATE_BINARY_OP(node->r.expr,
							 F_RR_RANGE_LVALUE,
							 0, 0, rchild);
					CREATE_NUMBER(node->r.expr->l.expr, 1);
				    } else
					node->r.expr->v.number++;
				    flag |= LV_RANGE;
				    node = node->r.expr->r.expr;
				    continue;
				}
			    default:
				yyerror("Illegal lvalue");
				flag = LV_ILLEGAL;
				break;
			    }   
                            if ((flag & LV_ILLEGAL) || !(node = node->r.expr)) break;
                        } while (1);
                        break;
		    } else 
			yyerror("Illegal lvalue");
		    break;
                }
            }
    break;

  case 188:
#line 2678 "grammar.y"
    {
#line 2615 "grammar.y.pre"
		(yyval.number) = ((yyvsp[(2) - (2)].number) << 8) | FP_EFUN;
	    }
    break;

  case 190:
#line 2688 "grammar.y"
    {
#line 2647 "grammar.y.pre"
              int i;
              if ((i = (yyvsp[(1) - (1)].ihe)->dn.local_num) != -1) {
		  type_of_locals_ptr[i] &= ~LOCAL_MOD_UNUSED;
		  if (type_of_locals_ptr[i] & LOCAL_MOD_REF)
		      CREATE_OPCODE_1((yyval.node), F_REF, type_of_locals_ptr[i] & ~LOCAL_MOD_REF,i & 0xff);
		  else
		      CREATE_OPCODE_1((yyval.node), F_LOCAL, type_of_locals_ptr[i], i & 0xff);
		  if (current_function_context)
		      current_function_context->num_locals++;
              } else
		  if ((i = (yyvsp[(1) - (1)].ihe)->dn.global_num) != -1) {
		      if (current_function_context)
			  current_function_context->bindable = FP_NOT_BINDABLE;
                          CREATE_OPCODE_1((yyval.node), F_GLOBAL,
				      VAR_TEMP(i)->type & ~DECL_MODS, i);
		      if (VAR_TEMP(i)->type & DECL_HIDDEN) {
			  char buf[256];
			  char *end = EndOf(buf);
			  char *p;

			  p = strput(buf, end, "Illegal to use private variable '");
			  p = strput(p, end, (yyvsp[(1) - (1)].ihe)->name);
			  p = strput(p, end, "'");
			  yyerror(buf);
		      }
		  } else {
		      char buf[256];
		      char *end = EndOf(buf);
		      char *p;
		      
		      p = strput(buf, end, "Undefined variable '");
		      p = strput(p, end, (yyvsp[(1) - (1)].ihe)->name);
		      p = strput(p, end, "'");
		      if (current_number_of_locals < CFG_MAX_LOCAL_VARIABLES) {
			  add_local_name((yyvsp[(1) - (1)].ihe)->name, TYPE_ANY);
		      }
		      CREATE_ERROR((yyval.node));
		      yyerror(buf);
		  }
	    }
    break;

  case 191:
#line 2731 "grammar.y"
    {
#line 2689 "grammar.y.pre"
		char buf[256];
		char *end = EndOf(buf);
		char *p;
		
		p = strput(buf, end, "Undefined variable '");
		p = strput(p, end, (yyvsp[(1) - (1)].string));
		p = strput(p, end, "'");
                if (current_number_of_locals < CFG_MAX_LOCAL_VARIABLES) {
                    add_local_name((yyvsp[(1) - (1)].string), TYPE_ANY);
                }
                CREATE_ERROR((yyval.node));
                yyerror(buf);
                scratch_free((yyvsp[(1) - (1)].string));
            }
    break;

  case 192:
#line 2748 "grammar.y"
    {
#line 2705 "grammar.y.pre"
		CREATE_PARAMETER((yyval.node), TYPE_ANY, (yyvsp[(1) - (1)].number));
            }
    break;

  case 193:
#line 2753 "grammar.y"
    {
#line 2709 "grammar.y.pre"
		(yyval.contextp) = current_function_context;
		/* already flagged as an error */
		if (current_function_context)
		    current_function_context = current_function_context->parent;
            }
    break;

  case 194:
#line 2761 "grammar.y"
    {
#line 2716 "grammar.y.pre"
		parse_node_t *node;

		current_function_context = (yyvsp[(3) - (5)].contextp);

		if (!current_function_context || current_function_context->num_parameters == -2) {
		    /* This was illegal, and error'ed when the '$' token
		     * was returned.
		     */
		    CREATE_ERROR((yyval.node));
		} else {
		    CREATE_OPCODE_1((yyval.node), F_LOCAL, (yyvsp[(4) - (5)].node)->type,
				    current_function_context->values_list->kind++);

		    node = new_node_no_line();
		    node->type = 0;
		    current_function_context->values_list->l.expr->r.expr = node;
		    current_function_context->values_list->l.expr = node;
		    node->r.expr = 0;
		    node->v.expr = (yyvsp[(4) - (5)].node);
		}
	    }
    break;

  case 195:
#line 2785 "grammar.y"
    {
#line 2739 "grammar.y.pre"
		if ((yyvsp[(1) - (3)].node)->type == TYPE_ANY) {
		    int cmi;
		    unsigned char tp;
		    
		    if ((cmi = lookup_any_class_member((yyvsp[(3) - (3)].string), &tp)) != -1) {
			CREATE_UNARY_OP_1((yyval.node), F_MEMBER, tp, (yyvsp[(1) - (3)].node), 0);
			(yyval.node)->l.number = cmi;
		    } else {
			CREATE_ERROR((yyval.node));
		    }
		} else if (!IS_CLASS((yyvsp[(1) - (3)].node)->type)) {
		    yyerror("Left argument of -> is not a class");
		    CREATE_ERROR((yyval.node));
		} else {
		    CREATE_UNARY_OP_1((yyval.node), F_MEMBER, 0, (yyvsp[(1) - (3)].node), 0);
		    (yyval.node)->l.number = lookup_class_member(CLASS_IDX((yyvsp[(1) - (3)].node)->type),
						       (yyvsp[(3) - (3)].string),
						       &((yyval.node)->type));
		}
		    
		scratch_free((yyvsp[(3) - (3)].string));
            }
    break;

  case 196:
#line 2810 "grammar.y"
    {
#line 2763 "grammar.y.pre"
                if ((yyvsp[(1) - (6)].node)->type != TYPE_MAPPING && 
		    (yyvsp[(5) - (6)].node)->kind == NODE_NUMBER && (yyvsp[(5) - (6)].node)->v.number < 0)
		    yywarn("A negative constant as the second element of arr[x..y] no longer means indexing from the end.  Use arr[x..<y]");
                (yyval.node) = make_range_node(F_NN_RANGE, (yyvsp[(1) - (6)].node), (yyvsp[(3) - (6)].node), (yyvsp[(5) - (6)].node));
            }
    break;

  case 197:
#line 2818 "grammar.y"
    {
#line 2772 "grammar.y.pre"
                (yyval.node) = make_range_node(F_RN_RANGE, (yyvsp[(1) - (7)].node), (yyvsp[(4) - (7)].node), (yyvsp[(6) - (7)].node));
            }
    break;

  case 198:
#line 2823 "grammar.y"
    {
#line 2776 "grammar.y.pre"
		if ((yyvsp[(7) - (8)].node)->kind == NODE_NUMBER && (yyvsp[(7) - (8)].node)->v.number <= 1)
		    (yyval.node) = make_range_node(F_RE_RANGE, (yyvsp[(1) - (8)].node), (yyvsp[(4) - (8)].node), 0);
		else
		    (yyval.node) = make_range_node(F_RR_RANGE, (yyvsp[(1) - (8)].node), (yyvsp[(4) - (8)].node), (yyvsp[(7) - (8)].node));
            }
    break;

  case 199:
#line 2831 "grammar.y"
    {
#line 2783 "grammar.y.pre"
		if ((yyvsp[(6) - (7)].node)->kind == NODE_NUMBER && (yyvsp[(6) - (7)].node)->v.number <= 1)
		    (yyval.node) = make_range_node(F_NE_RANGE, (yyvsp[(1) - (7)].node), (yyvsp[(3) - (7)].node), 0);
		else
		    (yyval.node) = make_range_node(F_NR_RANGE, (yyvsp[(1) - (7)].node), (yyvsp[(3) - (7)].node), (yyvsp[(6) - (7)].node));
            }
    break;

  case 200:
#line 2839 "grammar.y"
    {
#line 2790 "grammar.y.pre"
                (yyval.node) = make_range_node(F_NE_RANGE, (yyvsp[(1) - (5)].node), (yyvsp[(3) - (5)].node), 0);
            }
    break;

  case 201:
#line 2844 "grammar.y"
    {
#line 2794 "grammar.y.pre"
                (yyval.node) = make_range_node(F_RE_RANGE, (yyvsp[(1) - (6)].node), (yyvsp[(4) - (6)].node), 0);
            }
    break;

  case 202:
#line 2849 "grammar.y"
    {
#line 2798 "grammar.y.pre"
                if (IS_NODE((yyvsp[(1) - (5)].node), NODE_CALL, F_AGGREGATE)
		    && (yyvsp[(4) - (5)].node)->kind == NODE_NUMBER) {
                    int i = (yyvsp[(4) - (5)].node)->v.number;
                    if (i < 1 || i > (yyvsp[(1) - (5)].node)->l.number)
                        yyerror("Illegal index to array constant.");
                    else {
                        parse_node_t *node = (yyvsp[(1) - (5)].node)->r.expr;
                        i = (yyvsp[(1) - (5)].node)->l.number - i;
                        while (i--)
                            node = node->r.expr;
                        (yyval.node) = node->v.expr;
                        break;
                    }
                }
		CREATE_BINARY_OP((yyval.node), F_RINDEX, 0, (yyvsp[(4) - (5)].node), (yyvsp[(1) - (5)].node));
                if (exact_types) {
		    switch((yyvsp[(1) - (5)].node)->type) {
		    case TYPE_MAPPING:
			yyerror("Illegal index for mapping.");
		    case TYPE_ANY:
			(yyval.node)->type = TYPE_ANY;
			break;
		    case TYPE_STRING:
		    case TYPE_BUFFER:
			(yyval.node)->type = TYPE_NUMBER;
			if (!IS_TYPE((yyvsp[(4) - (5)].node)->type,TYPE_NUMBER))
			    type_error("Bad type of index", (yyvsp[(4) - (5)].node)->type);
			break;
			
		    default:
			if ((yyvsp[(1) - (5)].node)->type & TYPE_MOD_ARRAY) {
			    (yyval.node)->type = (yyvsp[(1) - (5)].node)->type & ~TYPE_MOD_ARRAY;
			    if (!IS_TYPE((yyvsp[(4) - (5)].node)->type,TYPE_NUMBER))
				type_error("Bad type of index", (yyvsp[(4) - (5)].node)->type);
			} else {
			    type_error("Value indexed has a bad type ", (yyvsp[(1) - (5)].node)->type);
			    (yyval.node)->type = TYPE_ANY;
			}
		    }
		} else (yyval.node)->type = TYPE_ANY;
            }
    break;

  case 203:
#line 2893 "grammar.y"
    {
#line 2841 "grammar.y.pre"
		/* Something stupid like ({ 1, 2, 3 })[1]; we take the
		 * time to optimize this because people who don't understand
		 * the preprocessor often write things like:
		 *
		 * #define MY_ARRAY ({ "foo", "bar", "bazz" })
		 * ...
		 * ... MY_ARRAY[1] ...
		 *
		 * which of course expands to the above.
		 */
                if (IS_NODE((yyvsp[(1) - (4)].node), NODE_CALL, F_AGGREGATE) && (yyvsp[(3) - (4)].node)->kind == NODE_NUMBER) {
                    int i = (yyvsp[(3) - (4)].node)->v.number;
                    if (i < 0 || i >= (yyvsp[(1) - (4)].node)->l.number)
                        yyerror("Illegal index to array constant.");
                    else {
                        parse_node_t *node = (yyvsp[(1) - (4)].node)->r.expr;
                        while (i--)
                            node = node->r.expr;
                        (yyval.node) = node->v.expr;
                        break;
                    }
                }
                if ((yyvsp[(3) - (4)].node)->kind == NODE_NUMBER && (yyvsp[(3) - (4)].node)->v.number < 0)
		    yywarn("A negative constant in arr[x] no longer means indexing from the end.  Use arr[<x]");
                CREATE_BINARY_OP((yyval.node), F_INDEX, 0, (yyvsp[(3) - (4)].node), (yyvsp[(1) - (4)].node));
                if (exact_types) {
		    switch((yyvsp[(1) - (4)].node)->type) {
		    case TYPE_MAPPING:
		    case TYPE_ANY:
			(yyval.node)->type = TYPE_ANY;
			break;
		    case TYPE_STRING:
		    case TYPE_BUFFER:
			(yyval.node)->type = TYPE_NUMBER;
			if (!IS_TYPE((yyvsp[(3) - (4)].node)->type,TYPE_NUMBER))
			    type_error("Bad type of index", (yyvsp[(3) - (4)].node)->type);
			break;
			
		    default:
			if ((yyvsp[(1) - (4)].node)->type & TYPE_MOD_ARRAY) {
			    (yyval.node)->type = (yyvsp[(1) - (4)].node)->type & ~TYPE_MOD_ARRAY;
			    if (!IS_TYPE((yyvsp[(3) - (4)].node)->type,TYPE_NUMBER))
				type_error("Bad type of index", (yyvsp[(3) - (4)].node)->type);
			} else {
			    type_error("Value indexed has a bad type ", (yyvsp[(1) - (4)].node)->type);
			    (yyval.node)->type = TYPE_ANY;
			}
                    }
                } else (yyval.node)->type = TYPE_ANY;
            }
    break;

  case 205:
#line 2947 "grammar.y"
    {
#line 2896 "grammar.y.pre"
		(yyval.node) = (yyvsp[(2) - (3)].node);
	    }
    break;

  case 207:
#line 2953 "grammar.y"
    {
#line 2904 "grammar.y.pre"
	        if ((yyvsp[(1) - (1)].type) != TYPE_FUNCTION) yyerror("Reserved type name unexpected.");
		(yyval.func_block).num_local = current_number_of_locals;
		(yyval.func_block).max_num_locals = max_num_locals;
		(yyval.func_block).context = context;
		(yyval.func_block).save_current_type = current_type;
		(yyval.func_block).save_exact_types = exact_types;
	        if (type_of_locals_ptr + max_num_locals + CFG_MAX_LOCAL_VARIABLES >= &type_of_locals[type_of_locals_size])
		    reallocate_locals();
		deactivate_current_locals();
		locals_ptr += current_number_of_locals;
		type_of_locals_ptr += max_num_locals;
		max_num_locals = current_number_of_locals = 0;
		push_function_context();
		current_function_context->num_parameters = -1;
		exact_types = TYPE_ANY;
		context = 0;
            }
    break;

  case 208:
#line 2973 "grammar.y"
    {
#line 2923 "grammar.y.pre"
		if ((yyvsp[(4) - (6)].argument).flags & ARG_IS_VARARGS) {
		    yyerror("Anonymous varargs functions aren't implemented");
		}
		if (!(yyvsp[(6) - (6)].decl).node) {
		    CREATE_RETURN((yyvsp[(6) - (6)].decl).node, 0);
		} else if ((yyvsp[(6) - (6)].decl).node->kind != NODE_RETURN &&
			   ((yyvsp[(6) - (6)].decl).node->kind != NODE_TWO_VALUES || (yyvsp[(6) - (6)].decl).node->r.expr->kind != NODE_RETURN)) {
		    parse_node_t *replacement;
		    CREATE_STATEMENTS(replacement, (yyvsp[(6) - (6)].decl).node, 0);
		    CREATE_RETURN(replacement->r.expr, 0);
		    (yyvsp[(6) - (6)].decl).node = replacement;
		}
		
		(yyval.node) = new_node();
		(yyval.node)->kind = NODE_ANON_FUNC;
		(yyval.node)->type = TYPE_FUNCTION;
		(yyval.node)->l.number = (max_num_locals - (yyvsp[(4) - (6)].argument).num_arg);
		(yyval.node)->r.expr = (yyvsp[(6) - (6)].decl).node;
		(yyval.node)->v.number = (yyvsp[(4) - (6)].argument).num_arg;
		if (current_function_context->bindable)
		    (yyval.node)->v.number |= 0x10000;
		free_all_local_names(1);
		
		current_number_of_locals = (yyvsp[(2) - (6)].func_block).num_local;
		max_num_locals = (yyvsp[(2) - (6)].func_block).max_num_locals;
		context = (yyvsp[(2) - (6)].func_block).context;
		current_type = (yyvsp[(2) - (6)].func_block).save_current_type;
		exact_types = (yyvsp[(2) - (6)].func_block).save_exact_types;
		pop_function_context();
		
		locals_ptr -= current_number_of_locals;
		type_of_locals_ptr -= max_num_locals;
		reactivate_current_locals();
	    }
    break;

  case 209:
#line 3010 "grammar.y"
    {
#line 2963 "grammar.y.pre"
		(yyval.node) = new_node();
		(yyval.node)->kind = NODE_FUNCTION_CONSTRUCTOR;
		(yyval.node)->type = TYPE_FUNCTION;
		(yyval.node)->r.expr = 0;
		switch ((yyvsp[(1) - (3)].number) & 0xff) {
		case FP_L_VAR:
		    yyerror("Illegal to use local variable in a functional.");
		    CREATE_NUMBER((yyval.node)->l.expr, 0);
		    (yyval.node)->l.expr->r.expr = 0;
		    (yyval.node)->l.expr->l.expr = 0;
		    (yyval.node)->v.number = FP_FUNCTIONAL;
		    break;
		case FP_G_VAR:
		    CREATE_OPCODE_1((yyval.node)->l.expr, F_GLOBAL, 0, (yyvsp[(1) - (3)].number) >> 8);
		    (yyval.node)->v.number = FP_FUNCTIONAL | FP_NOT_BINDABLE;
		    if (VAR_TEMP((yyval.node)->l.expr->l.number)->type & DECL_HIDDEN) {
			char buf[256];
			char *end = EndOf(buf);
			char *p;
			
			p = strput(buf, end, "Illegal to use private variable '");
			p = strput(p, end, VAR_TEMP((yyval.node)->l.expr->l.number)->name);
			p = strput(p, end, "'");
			yyerror(buf);
		    }
		    break;
		default:
		    (yyval.node)->v.number = (yyvsp[(1) - (3)].number);
		    break;
		}
	    }
    break;

  case 210:
#line 3044 "grammar.y"
    {
#line 2996 "grammar.y.pre"
		(yyval.node) = new_node();
		(yyval.node)->kind = NODE_FUNCTION_CONSTRUCTOR;
		(yyval.node)->type = TYPE_FUNCTION;
		(yyval.node)->v.number = (yyvsp[(1) - (5)].number);
		(yyval.node)->r.expr = (yyvsp[(3) - (5)].node);
		
		switch ((yyvsp[(1) - (5)].number) & 0xff) {
		case FP_EFUN: {
		    int *argp;
		    int f = (yyvsp[(1) - (5)].number) >>8;
		    int num = (yyvsp[(3) - (5)].node)->kind;
		    int max_arg = predefs[f].max_args;
		    
		    if (num > max_arg && max_arg != -1) {
			parse_node_t *pn = (yyvsp[(3) - (5)].node);
			
			while (pn) {
			    if (pn->type & 1) break;
			    pn = pn->r.expr;
			}
			
			if (!pn) {
			    char bff[256];
			    char *end = EndOf(bff);
			    char *p;
			    
			    p = strput(bff, end, "Too many arguments to ");
			    p = strput(p, end, predefs[f].word);
			    yyerror(bff);
			}
		    } else if (max_arg != -1 && exact_types) {
			/*
			 * Now check all types of arguments to efuns.
			 */
			int i, argn, tmp;
			parse_node_t *enode = (yyvsp[(3) - (5)].node);
			argp = &efun_arg_types[predefs[f].arg_index];
			
			for (argn = 0; argn < num; argn++) {
			    if (enode->type & 1) break;
			    
			    tmp = enode->v.expr->type;
			    for (i=0; !compatible_types(tmp, argp[i])
				 && argp[i] != 0; i++)
				;
			    if (argp[i] == 0) {
				char buf[256];
				char *end = EndOf(buf);
				char *p;

				p = strput(buf, end, "Bad argument ");
				p = strput_int(p, end, argn+1);
				p = strput(p, end, " to efun ");
				p = strput(p, end, predefs[f].word);
				p = strput(p, end, "()");
				yyerror(buf);
			    } else {
				/* this little section necessary b/c in the
				   case float | int we dont want to do
				   promoting. */
				if (tmp == TYPE_NUMBER && argp[i] == TYPE_REAL) {
				    for (i++; argp[i] && argp[i] != TYPE_NUMBER; i++)
					;
				    if (!argp[i])
					enode->v.expr = promote_to_float(enode->v.expr);
				}
				if (tmp == TYPE_REAL && argp[i] == TYPE_NUMBER) {
				    for (i++; argp[i] && argp[i] != TYPE_REAL; i++)
					;
				    if (!argp[i])
					enode->v.expr = promote_to_int(enode->v.expr);
				}
			    }
			    while (argp[i] != 0)
				i++;
			    argp += i + 1;
			    enode = enode->r.expr;
			}
		    }
		    break;
		}
		case FP_L_VAR:
		case FP_G_VAR:
		    yyerror("Can't give parameters to functional.");
		    break;
		}
	    }
    break;

  case 211:
#line 3134 "grammar.y"
    {
#line 3085 "grammar.y.pre"
		 if (current_function_context->num_locals)
		     yyerror("Illegal to use local variable in functional.");
		 if (current_function_context->values_list->r.expr)
		     current_function_context->values_list->r.expr->kind = current_function_context->values_list->kind;
		 
		 (yyval.node) = new_node();
		 (yyval.node)->kind = NODE_FUNCTION_CONSTRUCTOR;
		 (yyval.node)->type = TYPE_FUNCTION;
		 (yyval.node)->l.expr = (yyvsp[(2) - (4)].node);
		 if ((yyvsp[(2) - (4)].node)->kind == NODE_STRING)
		     yywarn("Function pointer returning string constant is NOT a function call");
		 (yyval.node)->r.expr = current_function_context->values_list->r.expr;
		 (yyval.node)->v.number = FP_FUNCTIONAL + current_function_context->bindable
		     + (current_function_context->num_parameters << 8);
		 pop_function_context();
             }
    break;

  case 212:
#line 3153 "grammar.y"
    {
#line 3103 "grammar.y.pre"
		CREATE_CALL((yyval.node), F_AGGREGATE_ASSOC, TYPE_MAPPING, (yyvsp[(2) - (4)].node));
	    }
    break;

  case 213:
#line 3158 "grammar.y"
    {
#line 3107 "grammar.y.pre"
		CREATE_CALL((yyval.node), F_AGGREGATE, TYPE_ANY | TYPE_MOD_ARRAY, (yyvsp[(2) - (4)].node));
	    }
    break;

  case 214:
#line 3166 "grammar.y"
    {
#line 3114 "grammar.y.pre"
		(yyval.node) = (yyvsp[(1) - (1)].decl).node;
	    }
    break;

  case 215:
#line 3171 "grammar.y"
    {
#line 3118 "grammar.y.pre"
		(yyval.node) = insert_pop_value((yyvsp[(2) - (3)].node));
	    }
    break;

  case 216:
#line 3179 "grammar.y"
    {
#line 3125 "grammar.y.pre"
		(yyval.number) = context;
		context = SPECIAL_CONTEXT;
	    }
    break;

  case 217:
#line 3185 "grammar.y"
    {
#line 3130 "grammar.y.pre"
		CREATE_CATCH((yyval.node), (yyvsp[(3) - (3)].node));
		context = (yyvsp[(2) - (3)].number);
	    }
    break;

  case 218:
#line 3195 "grammar.y"
    {
#line 3154 "grammar.y.pre"
		int p = (yyvsp[(6) - (7)].node)->v.number;
		CREATE_LVALUE_EFUN((yyval.node), TYPE_NUMBER, (yyvsp[(6) - (7)].node));
		CREATE_BINARY_OP_1((yyval.node)->l.expr, F_SSCANF, 0, (yyvsp[(3) - (7)].node), (yyvsp[(5) - (7)].node), p);
	    }
    break;

  case 219:
#line 3205 "grammar.y"
    {
#line 3163 "grammar.y.pre"
		int p = (yyvsp[(8) - (9)].node)->v.number;
		CREATE_LVALUE_EFUN((yyval.node), TYPE_NUMBER, (yyvsp[(8) - (9)].node));
		CREATE_TERNARY_OP_1((yyval.node)->l.expr, F_PARSE_COMMAND, 0, 
				    (yyvsp[(3) - (9)].node), (yyvsp[(5) - (9)].node), (yyvsp[(7) - (9)].node), p);
	    }
    break;

  case 220:
#line 3216 "grammar.y"
    {
#line 3173 "grammar.y.pre"
		(yyval.number) = context;
		context = SPECIAL_CONTEXT;
	    }
    break;

  case 221:
#line 3222 "grammar.y"
    {
#line 3178 "grammar.y.pre"
		CREATE_TIME_EXPRESSION((yyval.node), (yyvsp[(3) - (3)].node));
		context = (yyvsp[(2) - (3)].number);
	    }
    break;

  case 222:
#line 3231 "grammar.y"
    {
#line 3186 "grammar.y.pre"
	        (yyval.node) = new_node_no_line();
		(yyval.node)->r.expr = 0;
	        (yyval.node)->v.number = 0;
	    }
    break;

  case 223:
#line 3238 "grammar.y"
    {
#line 3192 "grammar.y.pre"
		parse_node_t *insert;
		
		(yyval.node) = (yyvsp[(3) - (3)].node);
		insert = new_node_no_line();
		insert->r.expr = (yyvsp[(3) - (3)].node)->r.expr;
		insert->l.expr = (yyvsp[(2) - (3)].node);
		(yyvsp[(3) - (3)].node)->r.expr = insert;
		(yyval.node)->v.number++;
	    }
    break;

  case 224:
#line 3253 "grammar.y"
    {
#line 3206 "grammar.y.pre"
		CREATE_STRING((yyval.node), (yyvsp[(1) - (1)].string));
		scratch_free((yyvsp[(1) - (1)].string));
	    }
    break;

  case 226:
#line 3263 "grammar.y"
    {
#line 3215 "grammar.y.pre"
		(yyval.string) = (yyvsp[(2) - (3)].string);
	    }
    break;

  case 227:
#line 3268 "grammar.y"
    {
#line 3219 "grammar.y.pre"
		(yyval.string) = scratch_join((yyvsp[(1) - (3)].string), (yyvsp[(3) - (3)].string));
	    }
    break;

  case 229:
#line 3277 "grammar.y"
    {
#line 3227 "grammar.y.pre"
		(yyval.string) = scratch_join((yyvsp[(1) - (2)].string), (yyvsp[(2) - (2)].string));
	    }
    break;

  case 230:
#line 3284 "grammar.y"
    {
#line 3233 "grammar.y.pre"
	(yyval.node) = new_node();
	(yyval.node)->l.expr = (parse_node_t *)(yyvsp[(1) - (3)].string);
	(yyval.node)->v.expr = (yyvsp[(3) - (3)].node);
	(yyval.node)->r.expr = 0;
    }
    break;

  case 231:
#line 3295 "grammar.y"
    {
#line 3243 "grammar.y.pre"
	(yyval.node) = 0;
    }
    break;

  case 232:
#line 3300 "grammar.y"
    {
#line 3247 "grammar.y.pre"
	(yyval.node) = (yyvsp[(3) - (3)].node);
	(yyval.node)->r.expr = (yyvsp[(1) - (3)].node);
    }
    break;

  case 233:
#line 3310 "grammar.y"
    {
#line 3256 "grammar.y.pre"
		(yyval.number) = context;
		(yyvsp[(2) - (2)].number) = num_refs;
		context |= ARG_LIST; 
	    }
    break;

  case 234:
#line 3317 "grammar.y"
    {
#line 3262 "grammar.y.pre"
		context = (yyvsp[(3) - (5)].number);
		(yyval.node) = validate_efun_call((yyvsp[(1) - (5)].number),(yyvsp[(4) - (5)].node));
		(yyval.node) = check_refs(num_refs - (yyvsp[(2) - (5)].number), (yyvsp[(4) - (5)].node), (yyval.node));
		num_refs = (yyvsp[(2) - (5)].number);
	    }
    break;

  case 235:
#line 3325 "grammar.y"
    {
#line 3269 "grammar.y.pre"
		(yyval.number) = context;
		(yyvsp[(2) - (2)].number) = num_refs;
		context |= ARG_LIST;
	    }
    break;

  case 236:
#line 3332 "grammar.y"
    {
#line 3275 "grammar.y.pre"
		context = (yyvsp[(3) - (5)].number);
		(yyval.node) = validate_efun_call(new_efun, (yyvsp[(4) - (5)].node));
		(yyval.node) = check_refs(num_refs - (yyvsp[(2) - (5)].number), (yyvsp[(4) - (5)].node), (yyval.node));
		num_refs = (yyvsp[(2) - (5)].number);
            }
    break;

  case 237:
#line 3340 "grammar.y"
    {
#line 3282 "grammar.y.pre"
		parse_node_t *node;
		
		if ((yyvsp[(4) - (6)].ihe)->dn.class_num == -1) {
		    char buf[256];
		    char *end = EndOf(buf);
		    char *p;
		    
		    p = strput(buf, end, "Undefined class '");
		    p = strput(p, end, (yyvsp[(4) - (6)].ihe)->name);
		    p = strput(p, end, "'");
		    yyerror(buf);
		    CREATE_ERROR((yyval.node));
		    node = (yyvsp[(5) - (6)].node);
		    while (node) {
			scratch_free((char *)node->l.expr);
			node = node->r.expr;
		    }
		} else {
		    int type = (yyvsp[(4) - (6)].ihe)->dn.class_num | TYPE_MOD_CLASS;
		    
		    if ((node = (yyvsp[(5) - (6)].node))) {
			CREATE_TWO_VALUES((yyval.node), type, 0, 0);
			(yyval.node)->l.expr = reorder_class_values((yyvsp[(4) - (6)].ihe)->dn.class_num,
							node);
			CREATE_OPCODE_1((yyval.node)->r.expr, F_NEW_CLASS,
					type, (yyvsp[(4) - (6)].ihe)->dn.class_num);
			
		    } else {
			CREATE_OPCODE_1((yyval.node), F_NEW_EMPTY_CLASS,
					type, (yyvsp[(4) - (6)].ihe)->dn.class_num);
		    }
		}
            }
    break;

  case 238:
#line 3376 "grammar.y"
    {
#line 3317 "grammar.y.pre"
		parse_node_t *node;
		char buf[256];
		char *end = EndOf(buf);
		char *p;

		p = strput(buf, end, "Undefined class '");
		p = strput(p, end, (yyvsp[(4) - (6)].string));
		p = strput(p, end, "'");
		yyerror(buf);
		CREATE_ERROR((yyval.node));
		node = (yyvsp[(5) - (6)].node);
		while (node) {
		    scratch_free((char *)node->l.expr);
		    node = node->r.expr;
		}
	    }
    break;

  case 239:
#line 3395 "grammar.y"
    {
#line 3335 "grammar.y.pre"
		(yyval.number) = context;
		(yyvsp[(2) - (2)].number) = num_refs;
		context |= ARG_LIST;
	    }
    break;

  case 240:
#line 3402 "grammar.y"
    {
#line 3341 "grammar.y.pre"
		int f;
		
		context = (yyvsp[(3) - (5)].number);
		(yyval.node) = (yyvsp[(4) - (5)].node);
		if ((f = (yyvsp[(1) - (5)].ihe)->dn.function_num) != -1) {
		    if (current_function_context)
			current_function_context->bindable = FP_NOT_BINDABLE;
		    
		    (yyval.node)->kind = NODE_CALL_1;
		    (yyval.node)->v.number = F_CALL_FUNCTION_BY_ADDRESS;
		    (yyval.node)->l.number = f;
		    (yyval.node)->type = validate_function_call(f, (yyvsp[(4) - (5)].node)->r.expr);
		} else if ((f=(yyvsp[(1) - (5)].ihe)->dn.simul_num) != -1) {
		    (yyval.node)->kind = NODE_CALL_1;
		    (yyval.node)->v.number = F_SIMUL_EFUN;
		    (yyval.node)->l.number = f;
		    (yyval.node)->type = (SIMUL(f)->type) & ~DECL_MODS;
		} else if ((f=(yyvsp[(1) - (5)].ihe)->dn.efun_num) != -1) {
		    (yyval.node) = validate_efun_call(f, (yyvsp[(4) - (5)].node));
		} else {
		    /* This here is a really nasty case that only occurs with
		     * exact_types off.  The user has done something gross like:
		     *
		     * func() { int f; f(); } // if f was prototyped we wouldn't
		     * f() { }                // need this case
		     *
		     * Don't complain, just grok it.
		     */
		    int f;
		    
		    if (current_function_context)
			current_function_context->bindable = FP_NOT_BINDABLE;
		    
		    f = define_new_function((yyvsp[(1) - (5)].ihe)->name, 0, 0, 
					    DECL_PUBLIC|FUNC_UNDEFINED, TYPE_ANY);
		    (yyval.node)->kind = NODE_CALL_1;
		    (yyval.node)->v.number = F_CALL_FUNCTION_BY_ADDRESS;
		    (yyval.node)->l.number = f;
		    (yyval.node)->type = TYPE_ANY; /* just a guess */
		    if (exact_types) {
			char buf[256];
			char *end = EndOf(buf);
			char *p;
			char *n = (yyvsp[(1) - (5)].ihe)->name;
			if (*n == ':') n++;
			/* prevent some errors; by making it look like an
			 * inherited function we prevent redeclaration errors
			 * if it shows up later
			 */
			
			FUNCTION_FLAGS(f) &= ~FUNC_UNDEFINED;
			FUNCTION_FLAGS(f) |= (FUNC_INHERITED | FUNC_VARARGS);
			p = strput(buf, end, "Undefined function ");
			p = strput(p, end, n);
			yyerror(buf);
		    }
		}
		(yyval.node) = check_refs(num_refs - (yyvsp[(2) - (5)].number), (yyvsp[(4) - (5)].node), (yyval.node));
		num_refs = (yyvsp[(2) - (5)].number);
	    }
    break;

  case 241:
#line 3465 "grammar.y"
    {
#line 3403 "grammar.y.pre"
		(yyval.number) = context;
		(yyvsp[(2) - (2)].number) = num_refs;
		context |= ARG_LIST;
	    }
    break;

  case 242:
#line 3472 "grammar.y"
    {
#line 3409 "grammar.y.pre"
	      char *name = (yyvsp[(1) - (5)].string);

	      context = (yyvsp[(3) - (5)].number);
	      (yyval.node) = (yyvsp[(4) - (5)].node);
	      
	      if (current_function_context)
		  current_function_context->bindable = FP_NOT_BINDABLE;

	      if (*name == ':') {
		  int f;
		  
		  if ((f = arrange_call_inherited(name + 1, (yyval.node))) != -1)
		      /* Can't do this; f may not be the correct function
			 entry.  It might be overloaded.
			 
		      validate_function_call(f, $$->r.expr)
		      */
		      ;
	      } else {
		  int f;
		  ident_hash_elem_t *ihe;
		  
		  f = (ihe = lookup_ident(name)) ? ihe->dn.function_num : -1;
		  (yyval.node)->kind = NODE_CALL_1;
		  (yyval.node)->v.number = F_CALL_FUNCTION_BY_ADDRESS;
		  if (f!=-1) {
		      /* The only way this can happen is if function_name
		       * below made the function name.  The lexer would
		       * return L_DEFINED_NAME instead.
		       */
		      (yyval.node)->type = validate_function_call(f, (yyvsp[(4) - (5)].node)->r.expr);
		  } else {
		      f = define_new_function(name, 0, 0, 
					      DECL_PUBLIC|FUNC_UNDEFINED, TYPE_ANY);
		  }
		  (yyval.node)->l.number = f;
		  /*
		   * Check if this function has been defined.
		   * But, don't complain yet about functions defined
		   * by inheritance.
		   */
		  if (exact_types && (FUNCTION_FLAGS(f) & FUNC_UNDEFINED)) {
		      char buf[256];
		      char *end = EndOf(buf);
		      char *p;
		      char *n = (yyvsp[(1) - (5)].string);
		      if (*n == ':') n++;
		      /* prevent some errors */
		      FUNCTION_FLAGS(f) &= ~FUNC_UNDEFINED;
		      FUNCTION_FLAGS(f) |= (FUNC_INHERITED | FUNC_VARARGS);
		      p = strput(buf, end, "Undefined function ");
		      p = strput(p, end, n);
		      yyerror(buf);
		  }
		  if (!(FUNCTION_FLAGS(f) & FUNC_UNDEFINED))
		      (yyval.node)->type = FUNCTION_DEF(f)->type;
		  else
		      (yyval.node)->type = TYPE_ANY;  /* Just a guess */
	      }
	      (yyval.node) = check_refs(num_refs - (yyvsp[(2) - (5)].number), (yyvsp[(4) - (5)].node), (yyval.node));
	      num_refs = (yyvsp[(2) - (5)].number);
	      scratch_free(name);
	  }
    break;

  case 243:
#line 3538 "grammar.y"
    {
#line 3474 "grammar.y.pre"
		(yyval.number) = context;
		(yyvsp[(4) - (4)].number) = num_refs;
		context |= ARG_LIST;
	    }
    break;

  case 244:
#line 3545 "grammar.y"
    {
#line 3480 "grammar.y.pre"
		ident_hash_elem_t *ihe;
		int f;
		parse_node_t *pn1, *pn2;
		
		(yyvsp[(6) - (7)].node)->v.number += 2;

		pn1 = new_node_no_line();
		pn1->type = 0;
		pn1->v.expr = (yyvsp[(1) - (7)].node);
		pn1->kind = (yyvsp[(6) - (7)].node)->v.number;
		
		pn2 = new_node_no_line();
		pn2->type = 0;
		CREATE_STRING(pn2->v.expr, (yyvsp[(3) - (7)].string));
		scratch_free((yyvsp[(3) - (7)].string));
		
		/* insert the two nodes */
		pn2->r.expr = (yyvsp[(6) - (7)].node)->r.expr;
		pn1->r.expr = pn2;
		(yyvsp[(6) - (7)].node)->r.expr = pn1;
		
		if (!(yyvsp[(6) - (7)].node)->l.expr) (yyvsp[(6) - (7)].node)->l.expr = pn2;
		    
		context = (yyvsp[(5) - (7)].number);
		ihe = lookup_ident("call_other");

		if ((f = ihe->dn.simul_num) != -1) {
		    (yyval.node) = (yyvsp[(6) - (7)].node);
		    (yyval.node)->kind = NODE_CALL_1;
		    (yyval.node)->v.number = F_SIMUL_EFUN;
		    (yyval.node)->l.number = f;
		    (yyval.node)->type = (SIMUL(f)->type) & ~DECL_MODS;
		} else {
		    (yyval.node) = validate_efun_call(arrow_efun, (yyvsp[(6) - (7)].node));
#ifdef CAST_CALL_OTHERS
		    (yyval.node)->type = TYPE_UNKNOWN;
#else
		    (yyval.node)->type = TYPE_ANY;
#endif		  
		}
		(yyval.node) = check_refs(num_refs - (yyvsp[(4) - (7)].number), (yyvsp[(6) - (7)].node), (yyval.node));
		num_refs = (yyvsp[(4) - (7)].number);
	    }
    break;

  case 245:
#line 3591 "grammar.y"
    {
#line 3525 "grammar.y.pre"
		(yyval.number) = context;
		(yyvsp[(5) - (5)].number) = num_refs;
		context |= ARG_LIST;
	    }
    break;

  case 246:
#line 3598 "grammar.y"
    {
#line 3531 "grammar.y.pre"
	        parse_node_t *expr;

		context = (yyvsp[(6) - (8)].number);
		(yyval.node) = (yyvsp[(7) - (8)].node);
		(yyval.node)->kind = NODE_EFUN;
		(yyval.node)->l.number = (yyval.node)->v.number + 1;
		(yyval.node)->v.number = predefs[evaluate_efun].token;
#ifdef CAST_CALL_OTHERS
		(yyval.node)->type = TYPE_UNKNOWN;
#else
		(yyval.node)->type = TYPE_ANY;
#endif
		expr = new_node_no_line();
		expr->type = 0;
		expr->v.expr = (yyvsp[(3) - (8)].node);
		expr->r.expr = (yyval.node)->r.expr;
		(yyval.node)->r.expr = expr;
		(yyval.node) = check_refs(num_refs - (yyvsp[(5) - (8)].number), (yyvsp[(7) - (8)].node), (yyval.node));
		num_refs = (yyvsp[(5) - (8)].number);
	    }
    break;

  case 247:
#line 3622 "grammar.y"
    {
#line 3554 "grammar.y.pre"
	svalue_t *res;
	ident_hash_elem_t *ihe;

	(yyval.number) = (ihe = lookup_ident((yyvsp[(3) - (3)].string))) ? ihe->dn.efun_num : -1;
	if ((yyval.number) == -1) {
	    char buf[256];
	    char *end = EndOf(buf);
	    char *p;
	    
	    p = strput(buf, end, "Unknown efun: ");
	    p = strput(p, end, (yyvsp[(3) - (3)].string));
	    yyerror(buf);
	} else {
	    push_malloced_string(the_file_name(current_file));
	    share_and_push_string((yyvsp[(3) - (3)].string));
	    push_malloced_string(add_slash(main_file_name()));
	    res = safe_apply_master_ob(APPLY_VALID_OVERRIDE, 3);
	    if (!MASTER_APPROVED(res)) {
		yyerror("Invalid simulated efunction override");
		(yyval.number) = -1;
	    }
	}
	scratch_free((yyvsp[(3) - (3)].string));
      }
    break;

  case 248:
#line 3648 "grammar.y"
    {
#line 3579 "grammar.y.pre"
	svalue_t *res;
	
	push_malloced_string(the_file_name(current_file));
	push_constant_string("new");
	push_malloced_string(add_slash(main_file_name()));
	res = safe_apply_master_ob(APPLY_VALID_OVERRIDE, 3);
	if (!MASTER_APPROVED(res)) {
	    yyerror("Invalid simulated efunction override");
	    (yyval.number) = -1;
	} else (yyval.number) = new_efun;
      }
    break;

  case 250:
#line 3666 "grammar.y"
    {
#line 3596 "grammar.y.pre"
		int l = strlen((yyvsp[(2) - (2)].string)) + 1;
		char *p;
		/* here we be a bit cute.  we put a : on the front so we
		 * don't have to strchr for it.  Here we do:
		 * "name" -> ":::name"
		 */
		(yyval.string) = scratch_realloc((yyvsp[(2) - (2)].string), l + 3);
		p = (yyval.string) + l;
		while (p--,l--)
		    *(p+3) = *p;
		strncpy((yyval.string), ":::", 3);
	    }
    break;

  case 251:
#line 3681 "grammar.y"
    {
#line 3610 "grammar.y.pre"
		int z, l = strlen((yyvsp[(3) - (3)].string)) + 1;
		char *p;
		/* <type> and "name" -> ":type::name" */
		z = strlen(compiler_type_names[(yyvsp[(1) - (3)].type)]) + 3; /* length of :type:: */
		(yyval.string) = scratch_realloc((yyvsp[(3) - (3)].string), l + z);
		p = (yyval.string) + l;
		while (p--,l--)
		    *(p+z) = *p;
		(yyval.string)[0] = ':';
		strncpy((yyval.string) + 1, compiler_type_names[(yyvsp[(1) - (3)].type)], z - 3);
		(yyval.string)[z-2] = ':';
		(yyval.string)[z-1] = ':';
	    }
    break;

  case 252:
#line 3697 "grammar.y"
    {
#line 3625 "grammar.y.pre"
		int l = strlen((yyvsp[(1) - (3)].string));
		/* "ob" and "name" -> ":ob::name" */
		(yyval.string) = scratch_alloc(l + strlen((yyvsp[(3) - (3)].string)) + 4);
		*((yyval.string)) = ':';
		strcpy((yyval.string) + 1, (yyvsp[(1) - (3)].string));
		strcpy((yyval.string) + l + 1, "::");
		strcpy((yyval.string) + l + 3, (yyvsp[(3) - (3)].string));
		scratch_free((yyvsp[(1) - (3)].string));
		scratch_free((yyvsp[(3) - (3)].string));
	    }
    break;

  case 253:
#line 3713 "grammar.y"
    {
#line 3640 "grammar.y.pre"
		/* x != 0 -> x */
		if (IS_NODE((yyvsp[(3) - (6)].node), NODE_BINARY_OP, F_NE)) {
		    if (IS_NODE((yyvsp[(3) - (6)].node)->r.expr, NODE_NUMBER, 0))
			(yyvsp[(3) - (6)].node) = (yyvsp[(3) - (6)].node)->l.expr;
		    else if (IS_NODE((yyvsp[(3) - (6)].node)->l.expr, NODE_NUMBER, 0))
			     (yyvsp[(3) - (6)].node) = (yyvsp[(3) - (6)].node)->r.expr;
		}

		/* TODO: should optimize if (0), if (1) here.  
		 * Also generalize this.
		 */

		if ((yyvsp[(5) - (6)].node) == 0) {
		    if ((yyvsp[(6) - (6)].node) == 0) {
			/* if (x) ; -> x; */
			(yyval.node) = pop_value((yyvsp[(3) - (6)].node));
			break;
		    } else {
			/* if (x) {} else y; -> if (!x) y; */
			parse_node_t *repl;
			
			CREATE_UNARY_OP(repl, F_NOT, TYPE_NUMBER, (yyvsp[(3) - (6)].node));
			(yyvsp[(3) - (6)].node) = repl;
			(yyvsp[(5) - (6)].node) = (yyvsp[(6) - (6)].node);
			(yyvsp[(6) - (6)].node) = 0;
		    }
		}
		CREATE_IF((yyval.node), (yyvsp[(3) - (6)].node), (yyvsp[(5) - (6)].node), (yyvsp[(6) - (6)].node));
	    }
    break;

  case 254:
#line 3748 "grammar.y"
    {
#line 3674 "grammar.y.pre"
		(yyval.node) = 0;
	    }
    break;

  case 255:
#line 3753 "grammar.y"
    {
#line 3678 "grammar.y.pre"
		(yyval.node) = (yyvsp[(2) - (2)].node);
            }
    break;


/* Line 1267 of yacc.c.  */
#line 6120 "y.tab.c"
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
      /* If just tried and failed to reuse look-ahead token after an
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

  /* Else will try to reuse look-ahead token after shifting the error
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

  if (yyn == YYFINAL)
    YYACCEPT;

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

#ifndef yyoverflow
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEOF && yychar != YYEMPTY)
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


#line 3758 "grammar.y"



#line 3683 "grammar.y.pre"

