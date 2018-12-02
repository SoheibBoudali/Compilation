/* A Bison parser, made by GNU Bison 2.1.  */

/* Skeleton parser for Yacc-like parsing with Bison,
   Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005 Free Software Foundation, Inc.

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

/* As a special exception, when this file is copied by Bison into a
   Bison output file, you may use that output file without restriction.
   This special exception was added by the Free Software Foundation
   in version 1.24 of Bison.  */

/* Written by Richard Stallman by simplifying the original so called
   ``semantic'' parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "2.1"

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
     Programme = 258,
     While = 259,
     EXECUT = 260,
     IF = 261,
     Real = 262,
     Integer = 263,
     BOUCLE = 264,
     TAB = 265,
     Calcul = 266,
     CONST = 267,
     EGAL = 268,
     SEP = 269,
     IDF = 270,
     OPR = 271,
     ENTIER = 272,
     REEL = 273
   };
#endif
/* Tokens.  */
#define Programme 258
#define While 259
#define EXECUT 260
#define IF 261
#define Real 262
#define Integer 263
#define BOUCLE 264
#define TAB 265
#define Calcul 266
#define CONST 267
#define EGAL 268
#define SEP 269
#define IDF 270
#define OPR 271
#define ENTIER 272
#define REEL 273




/* Copy the first part of user declarations.  */
#line 1 "TP.y"

#include<stdio.h>
extern FILE* yyin;
extern int NL,NC;
#include"TableS.h"
#include"Quad.c"
#include"Pile.c"
struct ENTITE *TS;
struct  BIB *TB;
char Type[10]="";
char CurrentType[10]="";
struct QUAD *Q=NULL;
int num=1;
int temp=1;
char * tempc;
struct PILE *Pile;


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

#if ! defined (YYSTYPE) && ! defined (YYSTYPE_IS_DECLARED)
#line 19 "TP.y"
typedef union YYSTYPE {
char *chaine;
int entier;
float reel;
struct s {char * val; int type;}s;
} YYSTYPE;
/* Line 196 of yacc.c.  */
#line 146 "TP.tab.c"
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 219 of yacc.c.  */
#line 158 "TP.tab.c"

#if ! defined (YYSIZE_T) && defined (__SIZE_TYPE__)
# define YYSIZE_T __SIZE_TYPE__
#endif
#if ! defined (YYSIZE_T) && defined (size_t)
# define YYSIZE_T size_t
#endif
#if ! defined (YYSIZE_T) && (defined (__STDC__) || defined (__cplusplus))
# include <stddef.h> /* INFRINGES ON USER NAME SPACE */
# define YYSIZE_T size_t
#endif
#if ! defined (YYSIZE_T)
# define YYSIZE_T unsigned int
#endif

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

#if ! defined (yyoverflow) || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if defined (__STDC__) || defined (__cplusplus)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     define YYINCLUDED_STDLIB_H
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning. */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2005 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM ((YYSIZE_T) -1)
#  endif
#  ifdef __cplusplus
extern "C" {
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if (! defined (malloc) && ! defined (YYINCLUDED_STDLIB_H) \
	&& (defined (__STDC__) || defined (__cplusplus)))
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if (! defined (free) && ! defined (YYINCLUDED_STDLIB_H) \
	&& (defined (__STDC__) || defined (__cplusplus)))
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifdef __cplusplus
}
#  endif
# endif
#endif /* ! defined (yyoverflow) || YYERROR_VERBOSE */


#if (! defined (yyoverflow) \
     && (! defined (__cplusplus) \
	 || (defined (YYSTYPE_IS_TRIVIAL) && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  short int yyss;
  YYSTYPE yyvs;
  };

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (short int) + sizeof (YYSTYPE))			\
      + YYSTACK_GAP_MAXIMUM)

/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined (__GNUC__) && 1 < __GNUC__
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
      while (0)
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
    while (0)

#endif

#if defined (__STDC__) || defined (__cplusplus)
   typedef signed char yysigned_char;
#else
   typedef short int yysigned_char;
#endif

/* YYFINAL -- State number of the termination state. */
#define YYFINAL  7
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   78

/* YYNTOKENS -- Number of terminals. */
#define YYNTOKENS  32
/* YYNNTS -- Number of nonterminals. */
#define YYNNTS  23
/* YYNRULES -- Number of rules. */
#define YYNRULES  43
/* YYNRULES -- Number of states. */
#define YYNSTATES  87

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   273

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const unsigned char yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       5,     6,    11,    10,     9,    12,     2,    13,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     7,     8,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    14,     2,    15,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     3,     2,     4,     2,     2,     2,     2,
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
       2,     2,     2,     2,     2,     2,     1,     2,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const unsigned char yyprhs[] =
{
       0,     0,     3,    11,    14,    16,    18,    20,    22,    26,
      29,    31,    33,    36,    40,    43,    47,    50,    56,    58,
      60,    63,    65,    67,    69,    71,    76,    80,    84,    86,
      90,    94,    96,    98,   103,   105,   107,   109,   114,   119,
     126,   129,   131,   139
};

/* YYRHS -- A `-1'-separated list of the rules' RHS. */
static const yysigned_char yyrhs[] =
{
      33,     0,    -1,    34,    16,    28,     3,    36,    42,     4,
      -1,    35,    34,    -1,    35,    -1,    24,    -1,    23,    -1,
      22,    -1,    41,    37,    36,    -1,    41,    37,    -1,    38,
      -1,    40,    -1,    25,    39,    -1,    28,    27,    38,    -1,
      28,     8,    -1,    28,    27,    39,    -1,    28,     8,    -1,
      28,    14,    30,    15,     8,    -1,    20,    -1,    21,    -1,
      43,    42,    -1,    43,    -1,    49,    -1,    51,    -1,    44,
      -1,    48,    26,    45,     8,    -1,    45,    10,    46,    -1,
      45,    12,    46,    -1,    46,    -1,    46,    11,    47,    -1,
      46,    13,    47,    -1,    47,    -1,    28,    -1,    28,    14,
      30,    15,    -1,    30,    -1,    31,    -1,    28,    -1,    28,
      14,    30,    15,    -1,    50,     3,    42,     4,    -1,    17,
       5,    45,    29,    45,     6,    -1,    52,    53,    -1,    18,
      -1,    54,    19,     5,    45,    29,    45,     6,    -1,    42,
      -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const unsigned short int yyrline[] =
{
       0,    34,    34,    36,    37,    40,    44,    48,    54,    55,
      58,    59,    60,    63,    69,    77,    83,    91,    99,   100,
     103,   104,   107,   108,   109,   112,   118,   125,   132,   135,
     142,   149,   152,   160,   174,   182,   192,   196,   208,   217,
     244,   246,   252,   284
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals. */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "'{'", "'}'", "'('", "')'", "':'", "';'",
  "','", "'+'", "'*'", "'-'", "'/'", "'['", "']'", "Programme", "While",
  "EXECUT", "IF", "Real", "Integer", "BOUCLE", "TAB", "Calcul", "CONST",
  "EGAL", "SEP", "IDF", "OPR", "ENTIER", "REEL", "$accept", "Start",
  "Bibliotheque", "Bib", "DECLARATION", "Val", "DecVar", "DecConst",
  "DecTab", "TYPE", "INSTRUCTION", "TypeInstruction", "AFFECTATION", "EXP",
  "EXPPRIO", "AFF", "IDFA", "LOOP", "A", "CONDITION", "execut",
  "condition", "DebutInst", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const unsigned short int yytoknum[] =
{
       0,   256,   257,   123,   125,    40,    41,    58,    59,    44,
      43,    42,    45,    47,    91,    93,   258,   259,   260,   261,
     262,   263,   264,   265,   266,   267,   268,   269,   270,   271,
     272,   273
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const unsigned char yyr1[] =
{
       0,    32,    33,    34,    34,    35,    35,    35,    36,    36,
      37,    37,    37,    38,    38,    39,    39,    40,    41,    41,
      42,    42,    43,    43,    43,    44,    45,    45,    45,    46,
      46,    46,    47,    47,    47,    47,    48,    48,    49,    50,
      51,    52,    53,    54
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const unsigned char yyr2[] =
{
       0,     2,     7,     2,     1,     1,     1,     1,     3,     2,
       1,     1,     2,     3,     2,     3,     2,     5,     1,     1,
       2,     1,     1,     1,     1,     4,     3,     3,     1,     3,
       3,     1,     1,     4,     1,     1,     1,     4,     4,     6,
       2,     1,     7,     1
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const unsigned char yydefact[] =
{
       0,     7,     6,     5,     0,     0,     4,     1,     0,     3,
       0,     0,    18,    19,     0,     0,     0,    41,    36,     0,
      21,    24,     0,    22,     0,    23,     0,     0,     0,     9,
      10,    11,     0,     0,     2,    20,     0,     0,    43,    40,
       0,     0,    12,    14,     0,     0,     8,    32,    34,    35,
       0,    28,    31,     0,     0,     0,     0,    16,     0,     0,
       0,    13,     0,     0,     0,     0,     0,     0,    37,    25,
      38,     0,    15,     0,     0,    26,    27,     0,    29,    30,
       0,    17,    33,    39,     0,     0,    42
};

/* YYDEFGOTO[NTERM-NUM]. */
static const yysigned_char yydefgoto[] =
{
      -1,     4,     5,     6,    14,    29,    30,    42,    31,    15,
      19,    20,    21,    50,    51,    52,    22,    23,    24,    25,
      26,    39,    40
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -37
static const yysigned_char yypact[] =
{
      28,   -37,   -37,   -37,    23,    20,    28,   -37,    18,   -37,
      44,    -2,   -37,   -37,    -1,    17,    48,   -37,    35,    50,
      -1,   -37,    29,   -37,    53,   -37,    -1,    30,    -7,    -2,
     -37,   -37,    10,    31,   -37,   -37,    10,    -1,   -37,   -37,
      38,    -5,   -37,   -37,    32,    36,   -37,    45,   -37,   -37,
      -8,     0,   -37,    51,     2,    56,    58,   -37,    30,    52,
      -3,   -37,    39,    10,    10,    10,    10,    10,   -37,   -37,
     -37,    10,   -37,    57,    55,     0,     0,    22,   -37,   -37,
      -4,   -37,   -37,   -37,    10,    27,   -37
};

/* YYPGOTO[NTERM-NUM].  */
static const yysigned_char yypgoto[] =
{
     -37,   -37,    62,   -37,    42,   -37,    33,    14,   -37,   -37,
     -11,   -37,   -37,   -36,   -33,   -23,   -37,   -37,   -37,   -37,
     -37,   -37,   -37
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const unsigned char yytable[] =
{
      54,    43,    63,    57,    64,    43,    63,    44,    64,    35,
      69,    66,    63,    67,    64,    38,    16,    17,    12,    13,
      45,    65,    58,     7,    45,    84,    55,    18,    83,    77,
      75,    76,    63,    86,    64,    80,     8,    63,    47,    64,
      48,    49,    27,    78,    79,    28,    10,    11,    85,    33,
       1,     2,     3,    32,    34,    36,    37,    56,    41,    62,
      70,    53,    59,    71,    60,    81,    68,    73,     9,    74,
      82,    46,    72,     0,     0,     0,     0,     0,    61
};

static const yysigned_char yycheck[] =
{
      36,     8,    10,     8,    12,     8,    10,    14,    12,    20,
       8,    11,    10,    13,    12,    26,    17,    18,    20,    21,
      27,    29,    27,     0,    27,    29,    37,    28,     6,    65,
      63,    64,    10,     6,    12,    71,    16,    10,    28,    12,
      30,    31,    25,    66,    67,    28,    28,     3,    84,    14,
      22,    23,    24,     5,     4,    26,     3,    19,    28,    14,
       4,    30,    30,     5,    28,     8,    15,    15,     6,    30,
      15,    29,    58,    -1,    -1,    -1,    -1,    -1,    45
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const unsigned char yystos[] =
{
       0,    22,    23,    24,    33,    34,    35,     0,    16,    34,
      28,     3,    20,    21,    36,    41,    17,    18,    28,    42,
      43,    44,    48,    49,    50,    51,    52,    25,    28,    37,
      38,    40,     5,    14,     4,    42,    26,     3,    42,    53,
      54,    28,    39,     8,    14,    27,    36,    28,    30,    31,
      45,    46,    47,    30,    45,    42,    19,     8,    27,    30,
      28,    38,    14,    10,    12,    29,    11,    13,    15,     8,
       4,     5,    39,    15,    30,    46,    46,    45,    47,    47,
      45,     8,    15,     6,    29,    45,     6
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
      YYPOPSTACK;						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (0)


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (N)								\
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
    while (0)
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
} while (0)

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)		\
do {								\
  if (yydebug)							\
    {								\
      YYFPRINTF (stderr, "%s ", Title);				\
      yysymprint (stderr,					\
                  Type, Value);	\
      YYFPRINTF (stderr, "\n");					\
    }								\
} while (0)

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if defined (__STDC__) || defined (__cplusplus)
static void
yy_stack_print (short int *bottom, short int *top)
#else
static void
yy_stack_print (bottom, top)
    short int *bottom;
    short int *top;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (/* Nothing. */; bottom <= top; ++bottom)
    YYFPRINTF (stderr, " %d", *bottom);
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if defined (__STDC__) || defined (__cplusplus)
static void
yy_reduce_print (int yyrule)
#else
static void
yy_reduce_print (yyrule)
    int yyrule;
#endif
{
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu), ",
             yyrule - 1, yylno);
  /* Print the symbols being reduced, and their result.  */
  for (yyi = yyprhs[yyrule]; 0 <= yyrhs[yyi]; yyi++)
    YYFPRINTF (stderr, "%s ", yytname[yyrhs[yyi]]);
  YYFPRINTF (stderr, "-> %s\n", yytname[yyr1[yyrule]]);
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (Rule);		\
} while (0)

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
#  if defined (__GLIBC__) && defined (_STRING_H)
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
#   if defined (__STDC__) || defined (__cplusplus)
yystrlen (const char *yystr)
#   else
yystrlen (yystr)
     const char *yystr;
#   endif
{
  const char *yys = yystr;

  while (*yys++ != '\0')
    continue;

  return yys - yystr - 1;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined (__GLIBC__) && defined (_STRING_H) && defined (_GNU_SOURCE)
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
#   if defined (__STDC__) || defined (__cplusplus)
yystpcpy (char *yydest, const char *yysrc)
#   else
yystpcpy (yydest, yysrc)
     char *yydest;
     const char *yysrc;
#   endif
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
      size_t yyn = 0;
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

#endif /* YYERROR_VERBOSE */



#if YYDEBUG
/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if defined (__STDC__) || defined (__cplusplus)
static void
yysymprint (FILE *yyoutput, int yytype, YYSTYPE *yyvaluep)
#else
static void
yysymprint (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  /* Pacify ``unused variable'' warnings.  */
  (void) yyvaluep;

  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);


# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  switch (yytype)
    {
      default:
        break;
    }
  YYFPRINTF (yyoutput, ")");
}

#endif /* ! YYDEBUG */
/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

#if defined (__STDC__) || defined (__cplusplus)
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
  /* Pacify ``unused variable'' warnings.  */
  (void) yyvaluep;

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
# if defined (__STDC__) || defined (__cplusplus)
int yyparse (void *YYPARSE_PARAM);
# else
int yyparse ();
# endif
#else /* ! YYPARSE_PARAM */
#if defined (__STDC__) || defined (__cplusplus)
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
# if defined (__STDC__) || defined (__cplusplus)
int yyparse (void *YYPARSE_PARAM)
# else
int yyparse (YYPARSE_PARAM)
  void *YYPARSE_PARAM;
# endif
#else /* ! YYPARSE_PARAM */
#if defined (__STDC__) || defined (__cplusplus)
int
yyparse (void)
#else
int
yyparse ()
    ;
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

  /* Three stacks and their tools:
     `yyss': related to states,
     `yyvs': related to semantic values,
     `yyls': related to locations.

     Refer to the stacks thru separate pointers, to allow yyoverflow
     to reallocate them elsewhere.  */

  /* The state stack.  */
  short int yyssa[YYINITDEPTH];
  short int *yyss = yyssa;
  short int *yyssp;

  /* The semantic value stack.  */
  YYSTYPE yyvsa[YYINITDEPTH];
  YYSTYPE *yyvs = yyvsa;
  YYSTYPE *yyvsp;



#define YYPOPSTACK   (yyvsp--, yyssp--)

  YYSIZE_T yystacksize = YYINITDEPTH;

  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;


  /* When reducing, the number of symbols on the RHS of the reduced
     rule.  */
  int yylen;

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
     have just been pushed. so pushing a state here evens the stacks.
     */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
	/* Give user a chance to reallocate the stack. Use copies of
	   these so that the &'s don't force the real ones into
	   memory.  */
	YYSTYPE *yyvs1 = yyvs;
	short int *yyss1 = yyss;


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
	short int *yyss1 = yyss;
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

/* Do appropriate processing given the current state.  */
/* Read a look-ahead token if we need one and don't already have one.  */
/* yyresume: */

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

  /* Shift the look-ahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the token being shifted unless it is eof.  */
  if (yychar != YYEOF)
    yychar = YYEMPTY;

  *++yyvsp = yylval;


  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  yystate = yyn;
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
#line 34 "TP.y"
    {printf("Programme  syntaxiquement correct\n");ShowQ(&Q);;}
    break;

  case 5:
#line 40 "TP.y"
    { if(SearchB(&TB,"Calcul")){printf("Erreur a la ligne %d : Bibliotheque  Calcul déja declarée  \n", NL); 
                }else
                InsertBib(&TB,"Calcul",NL);   
              ;}
    break;

  case 6:
#line 44 "TP.y"
    { if(SearchB(&TB,"TAB")) {printf("Erreur a la ligne %d : Bibliotheque TAB déja declarée \n",NL); 
                }else
                InsertBib(&TB,"TAB",NL);   
              ;}
    break;

  case 7:
#line 48 "TP.y"
    { if(SearchB(&TB,"BOUCLE")) {printf("Erreur a la ligne %d : Bibliotheque BOUCLE déja declarée \n",NL);
                }else
                InsertBib(&TB,"BOUCLE",NL);
              ;}
    break;

  case 11:
#line 59 "TP.y"
    { if(!SearchB(&TB,"TAB")) printf("Erreur a la ligne %d : Bibliothéque TAB non Déclarée!\n",NL); ;}
    break;

  case 13:
#line 63 "TP.y"
    { if(!Search(&TS,(yyvsp[-2].chaine))) Insert(&TS,(yyvsp[-2].chaine),Type,1,"VAR",NL); 
                          else{ 
                            if(GetLine(&TS,(yyvsp[-2].chaine))==NL) printf("Erreur a la ligne %d : Double declaration d'IDF dans la meme ligne %d \n",NL,NL);
                            else printf("Erreur a la ligne %d : IDF deja declaré a la ligne %d \n",NL,GetLine(&TS,(yyvsp[-2].chaine)));
                          }
                        ;}
    break;

  case 14:
#line 69 "TP.y"
    { if(!Search(&TS,(yyvsp[-1].chaine))) Insert(&TS,(yyvsp[-1].chaine),Type,1,"VAR",NL); 
                      else{ 
                        if(GetLine(&TS,(yyvsp[-1].chaine))==NL) printf("Erreur a la ligne %d : Double declaration d'IDF dans la meme ligne %d \n",NL,NL);
                        else printf("Erreur a la ligne %d : IDF deja declaré a la ligne %d \n",NL,GetLine(&TS,(yyvsp[-1].chaine)));
                      }
                  ;}
    break;

  case 15:
#line 77 "TP.y"
    { if(!Search(&TS,(yyvsp[-2].chaine))) Insert(&TS,(yyvsp[-2].chaine),Type,1,"CONST",NL);
                              else{
                                if(GetLine(&TS,(yyvsp[-2].chaine))==NL) printf("Erreur a la ligne %d : Double declaration de la Constate dans la meme ligne %d \n",NL,NL);
                                else printf("Erreur a la ligne %d : Constate deja definie a la ligne %d \n",NL,GetLine(&TS,(yyvsp[-2].chaine)));
                              }
                            ;}
    break;

  case 16:
#line 83 "TP.y"
    { if(!Search(&TS,(yyvsp[-1].chaine))) Insert(&TS,(yyvsp[-1].chaine),Type,1,"CONST",NL);
                    else{
                      if(GetLine(&TS,(yyvsp[-1].chaine))==NL) printf("Erreur a la ligne %d : Double declaration de la Constate dans la meme ligne %d \n",NL,NL);
                      else printf("Erreur a la ligne %d : Constate deja definiea la ligne %d \n",NL,GetLine(&TS,(yyvsp[-1].chaine)));
                    }
                  ;}
    break;

  case 17:
#line 91 "TP.y"
    { if(!Search(&TS,(yyvsp[-4].chaine))) Insert(&TS,(yyvsp[-4].chaine),Type,(yyvsp[-2].entier),"TAB",NL);
                                  else{
                                    if(GetLine(&TS,(yyvsp[-4].chaine))==NL) printf("Erreur a la ligne %d : Double declaration du tableau dans la meme ligne %d \n",NL,NL);
                                    else  printf("Erreur a la ligne %d : Tableau deja declaré\n",NL);
                                  }
                                ;}
    break;

  case 18:
#line 99 "TP.y"
    {strcpy(Type,"Real");;}
    break;

  case 19:
#line 100 "TP.y"
    {strcpy(Type,"Integer");;}
    break;

  case 22:
#line 107 "TP.y"
    { if(!SearchB(&TB,"BOUCLE")) printf("Erreur a la ligne %d : Bibliothéque BOUCLE non Déclarée!\n",NL);;}
    break;

  case 24:
#line 109 "TP.y"
    { if(!SearchB(&TB,"Calcul")) printf("Erreur a la ligne %d : Bibliothéque Calcul non Déclarée!\n",NL);;}
    break;

  case 25:
#line 112 "TP.y"
    { strcpy(CurrentType,"");
                                  InsertQ(&Q,"=",(yyvsp[-1].s).val,"",(yyvsp[-3].s).val,num);
                                  num++;
                                ;}
    break;

  case 26:
#line 118 "TP.y"
    { char* tempc=malloc(sizeof(10));
                          sprintf(tempc,"T%d",temp);
                          temp++;
                          InsertQ(&Q,"+",(yyvsp[-2].s).val,(yyvsp[0].s).val,tempc,num);
                          num++;
                          strcpy((yyval.s).val,tempc);
                        ;}
    break;

  case 27:
#line 125 "TP.y"
    {  char* tempc=malloc(sizeof(10));   
                          sprintf(tempc,"T%d",temp);
                          temp++; 
                          InsertQ(&Q,"-",(yyvsp[-2].s).val,(yyvsp[0].s).val,tempc,num);
                          num++;  
                          strcpy((yyval.s).val,tempc);
                        ;}
    break;

  case 28:
#line 132 "TP.y"
    { strcpy((yyval.s).val,(yyvsp[0].s).val); ;}
    break;

  case 29:
#line 135 "TP.y"
    { char* tempc=malloc(sizeof(10));   
                            sprintf(tempc,"T%d",temp);
                            temp++; 
                            InsertQ(&Q,"*",(yyvsp[-2].s).val,(yyvsp[0].s).val,tempc,num);
                            num++;  
                            strcpy((yyval.s).val,tempc);
                          ;}
    break;

  case 30:
#line 142 "TP.y"
    { char* tempc=malloc(sizeof(10));   
                            sprintf(tempc,"T%d",temp);
                            temp++; 
                            InsertQ(&Q,"/",(yyvsp[-2].s).val,(yyvsp[0].s).val,tempc,num);
                            num++;  
                            strcpy((yyval.s).val,tempc);
                          ;}
    break;

  case 31:
#line 149 "TP.y"
    { strcpy((yyval.s).val,(yyvsp[0].s).val);;}
    break;

  case 32:
#line 152 "TP.y"
    { if(!Search(&TS,(yyvsp[0].chaine))) printf("Erreur a la ligne %d : IDF non declaré\n " ,NL); 
            if(strcmp(CurrentType,"")!=0){
              if(strcmp(CurrentType,GetType(&TS,(yyvsp[0].chaine)))!=0) {printf("Erreur a la ligne %d : Incompatibilité de type \n",NL);}
            }else{
              strcpy(CurrentType,GetType(&TS,(yyvsp[0].chaine)));
            } 
            strcpy((yyval.s).val,(yyvsp[0].chaine));
          ;}
    break;

  case 33:
#line 160 "TP.y"
    { if(!Search(&TS,(yyvsp[-3].chaine))) {
                            printf("Erreur a la ligne %d :IDF non declaré\n",NL);
                          }else{
                            if(!CheckTab(&TS,(yyvsp[-3].chaine))) printf("Erreur a la ligne %d : IDF n'est pas un tableau\n",NL);
                          }
                          if((yyvsp[-1].entier)>CheckTabSize(&TS,(yyvsp[-3].chaine))) printf("Erreur a la ligne %d : Debordement \n",NL);
                          if(strcmp(CurrentType,"")!=0){
                            if(strcmp(CurrentType,GetType(&TS,(yyvsp[-3].chaine)))!=0) printf("Erreur a la ligne %d : Incompatibilité de type \n",NL);
                          }else{
                            strcpy(CurrentType,GetType(&TS,(yyvsp[-3].chaine)));
                          }
                          (yyval.s).val=malloc(20*sizeof(char));
                          sprintf((yyval.s).val,"%s [ %d ]",(yyvsp[-3].chaine),(yyvsp[-1].entier));
                        ;}
    break;

  case 34:
#line 174 "TP.y"
    { if(strcmp(CurrentType,"")!=0) {
                  if(strcmp(CurrentType,"Integer")!=0) {printf("Erreur a la ligne %d : Incompatibilité de type \n",NL);}
                }else{
                  strcpy(CurrentType,"Integer");
                }
                (yyval.s).val=malloc(20*sizeof(char));
                sprintf((yyval.s).val,"%d",(yyvsp[0].entier));  
              ;}
    break;

  case 35:
#line 182 "TP.y"
    { if(strcmp(CurrentType,"")!=0) {
                if(strcmp(CurrentType,"Real")!=0) {printf("Erreur a la ligne %d : Incompatibilité de type \n",NL);}
                }else{
                  strcpy(CurrentType,"Real");
              }
              (yyval.s).val=malloc(20*sizeof(char));
              sprintf((yyval.s).val,"%f",(yyvsp[0].reel));  
            ;}
    break;

  case 36:
#line 192 "TP.y"
    { strcpy(CurrentType,GetType(&TS,(yyvsp[0].chaine)));  
            if(!Search(&TS,(yyvsp[0].chaine))) printf("Erreur a la ligne %d : IDF non declaré\n",NL); 
            strcpy((yyval.s).val,(yyvsp[0].chaine));
          ;}
    break;

  case 37:
#line 196 "TP.y"
    { strcpy(CurrentType,GetType(&TS,(yyvsp[-3].chaine))); 
                          if((yyvsp[-1].entier)>CheckTabSize(&TS,(yyvsp[-3].chaine))) printf("Erreur a la ligne %d : Debordement \n",NL);
                          if(!Search(&TS,(yyvsp[-3].chaine))) {
                            printf("Erreur a la ligne %d : IDF non declaré\n",NL);
                          }else{
                            if(!CheckTab(&TS,(yyvsp[-3].chaine))) printf("Erreur a la ligne %d : IDF n'est pas un tableau\n" , NL);
                          }
                          (yyval.s).val=malloc(20*sizeof(char));
                          sprintf((yyval.s).val,"%s [ %d ]",(yyvsp[-3].chaine),(yyvsp[-1].entier));
                        ;}
    break;

  case 38:
#line 208 "TP.y"
    { int x=PULL(&Pile);
                              char *tempc;
                              tempc=malloc(sizeof(10));
                              sprintf(tempc,"%d",x);
                              InsertQ(&Q,"BR",tempc,"","",num);
                              num++;
                              MAJQ(&Q,x,num);
                              ;}
    break;

  case 39:
#line 217 "TP.y"
    {  PUSH(&Pile,num);
                                if(strcmp((yyvsp[-2].chaine),"<")==0){
                                InsertQ(&Q,"BGE","",(yyvsp[-3].s).val,(yyvsp[-1].s).val,num);
                                num++;
                                }
                                if(strcmp((yyvsp[-2].chaine),"==")==0) {
                                  InsertQ(&Q,"BNE","",(yyvsp[-3].s).val,(yyvsp[-1].s).val,num);
                                  num++;
                                }
                                if(strcmp((yyvsp[-2].chaine),"!=")==0) {
                                  InsertQ(&Q,"BE","",(yyvsp[-3].s).val,(yyvsp[-1].s).val,num);  
                                  num++;
                                }
                                if(strcmp((yyvsp[-2].chaine),">")==0){
                                  InsertQ(&Q,"BLE","",(yyvsp[-3].s).val,(yyvsp[-1].s).val,num); 
                                  num++;
                                }
                                if(strcmp((yyvsp[-2].chaine),"<=")==0){
                                  InsertQ(&Q,"BG","",(yyvsp[-3].s).val,(yyvsp[-1].s).val,num);
                                  num++;
                                }
                                if(strcmp((yyvsp[-2].chaine),">=")==0){
                                  InsertQ(&Q,"BL","",(yyvsp[-3].s).val,(yyvsp[-1].s).val,num);
                                  num++;
                                }
                              ;}
    break;

  case 41:
#line 246 "TP.y"
    { InsertQ(&Q,"BR","","","",num);
                  PUSH(&Pile,num);
                  num++;
                  PUSH(&Pile,num);
                ;}
    break;

  case 42:
#line 252 "TP.y"
    {  MAJQ(&Q,PULL(&Pile),num+1);
                                                int x;
                                                x=PULL(&Pile);
                                                char *tempc;
                                                tempc=malloc(sizeof(10));
                                                sprintf(tempc,"%d",x);   
                                                if(strcmp((yyvsp[-2].chaine),"<")==0) {
                                                  InsertQ(&Q,"BL",tempc,(yyvsp[-3].s).val,(yyvsp[-1].s).val,num);
                                                  MAJQ(&Q,PULL(&Pile),num);num++;
                                                }
                                                if(strcmp((yyvsp[-2].chaine),"==")==0) {
                                                  InsertQ(&Q,"BE",tempc,(yyvsp[-3].s).val,(yyvsp[-1].s).val,num);
                                                  MAJQ(&Q,PULL(&Pile),num);num++;
                                                }
                                                if(strcmp((yyvsp[-2].chaine),"!=")==0) {
                                                  InsertQ(&Q,"BNE",tempc,(yyvsp[-3].s).val,(yyvsp[-1].s).val,num);  
                                                  MAJQ(&Q,PULL(&Pile),num);num++;
                                                }
                                                if(strcmp((yyvsp[-2].chaine),">")==0){
                                                  InsertQ(&Q,"BG",tempc,(yyvsp[-3].s).val,(yyvsp[-1].s).val,num); 
                                                  MAJQ(&Q,PULL(&Pile),num);num++;
                                                }
                                                if(strcmp((yyvsp[-2].chaine),"<=")==0){
                                                  InsertQ(&Q,"BNE",tempc,(yyvsp[-3].s).val,(yyvsp[-1].s).val,num);
                                                  MAJQ(&Q,PULL(&Pile),num);num++;
                                                }
                                                if(strcmp((yyvsp[-2].chaine),">=")==0){
                                                  InsertQ(&Q,"BGE",tempc,(yyvsp[-3].s).val,(yyvsp[-1].s).val,num);
                                                  MAJQ(&Q,PULL(&Pile),num);num++;
                                                }
                                              ;}
    break;

  case 43:
#line 284 "TP.y"
    { InsertQ(&Q,"BR","","","",num);
                        PUSH(&Pile,num);
                        num++;
                      ;}
    break;


      default: break;
    }

/* Line 1126 of yacc.c.  */
#line 1550 "TP.tab.c"

  yyvsp -= yylen;
  yyssp -= yylen;


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
#if YYERROR_VERBOSE
      yyn = yypact[yystate];

      if (YYPACT_NINF < yyn && yyn < YYLAST)
	{
	  int yytype = YYTRANSLATE (yychar);
	  YYSIZE_T yysize0 = yytnamerr (0, yytname[yytype]);
	  YYSIZE_T yysize = yysize0;
	  YYSIZE_T yysize1;
	  int yysize_overflow = 0;
	  char *yymsg = 0;
#	  define YYERROR_VERBOSE_ARGS_MAXIMUM 5
	  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
	  int yyx;

#if 0
	  /* This is so xgettext sees the translatable formats that are
	     constructed on the fly.  */
	  YY_("syntax error, unexpected %s");
	  YY_("syntax error, unexpected %s, expecting %s");
	  YY_("syntax error, unexpected %s, expecting %s or %s");
	  YY_("syntax error, unexpected %s, expecting %s or %s or %s");
	  YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s");
#endif
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
	  int yychecklim = YYLAST - yyn;
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
		yysize_overflow |= yysize1 < yysize;
		yysize = yysize1;
		yyfmt = yystpcpy (yyfmt, yyprefix);
		yyprefix = yyor;
	      }

	  yyf = YY_(yyformat);
	  yysize1 = yysize + yystrlen (yyf);
	  yysize_overflow |= yysize1 < yysize;
	  yysize = yysize1;

	  if (!yysize_overflow && yysize <= YYSTACK_ALLOC_MAXIMUM)
	    yymsg = (char *) YYSTACK_ALLOC (yysize);
	  if (yymsg)
	    {
	      /* Avoid sprintf, as that infringes on the user's name space.
		 Don't have undefined behavior even if the translation
		 produced a string with the wrong number of "%s"s.  */
	      char *yyp = yymsg;
	      int yyi = 0;
	      while ((*yyp = *yyf))
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
	      yyerror (yymsg);
	      YYSTACK_FREE (yymsg);
	    }
	  else
	    {
	      yyerror (YY_("syntax error"));
	      goto yyexhaustedlab;
	    }
	}
      else
#endif /* YYERROR_VERBOSE */
	yyerror (YY_("syntax error"));
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
	  yydestruct ("Error: discarding", yytoken, &yylval);
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
  if (0)
     goto yyerrorlab;

yyvsp -= yylen;
  yyssp -= yylen;
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


      yydestruct ("Error: popping", yystos[yystate], yyvsp);
      YYPOPSTACK;
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  if (yyn == YYFINAL)
    YYACCEPT;

  *++yyvsp = yylval;


  /* Shift the error token. */
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
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
		  yystos[*yyssp], yyvsp);
      YYPOPSTACK;
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
  return yyresult;
}


#line 289 "TP.y"

int yyerror(char* msg)
{
printf("Erreur syntaxique a la ligne %d colonne %d\n",NL,NC);
return 1;
}
int main()
{
yyin=fopen("Test.txt","r");
yyparse();
Show(&TS);
ShowB(&TB);
return 0;
}

