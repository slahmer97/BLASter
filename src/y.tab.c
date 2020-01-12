/* A Bison parser, made by GNU Bison 3.3.2.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2019 Free Software Foundation,
   Inc.

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

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.3.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "grammar/c_syn.y" /* yacc.c:337  */

	#include<stdio.h>
	#include "headers/defs.h"
	#include "headers/y.tab.h"
	#include "headers/ast.h"

	#include <stdlib.h>
	int for_depth_counter_var = 0;
	int direct_declarator_var = 0;
	int current_type_var = -1;
	int can_use_un = 0;

#line 83 "y.tab.c" /* yacc.c:337  */
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* In a future release of Bison, this section will be replaced
   by #include "y.tab.h".  */
#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    INT = 258,
    VOID = 259,
    FLOAT = 260,
    FOR = 261,
    WHILE = 262,
    DO = 263,
    IF = 264,
    ELSE = 265,
    RETURN = 266,
    BREAK = 267,
    GOTO = 268,
    HASH = 269,
    INCLUDE = 270,
    CONST_Q = 271,
    CONST_INT = 272,
    CONST_FLOAT = 273,
    IDENTIFIER = 274,
    STRING = 275,
    CONST = 276,
    PRINTF = 277,
    AND_OP = 278,
    OR_OP = 279,
    LE_OP = 280,
    GE_OP = 281,
    EQ_OP = 282,
    NE_OP = 283,
    INC = 284,
    DEC = 285,
    LEFT_OP = 286,
    RIGHT_OP = 287
  };
#endif
/* Tokens.  */
#define INT 258
#define VOID 259
#define FLOAT 260
#define FOR 261
#define WHILE 262
#define DO 263
#define IF 264
#define ELSE 265
#define RETURN 266
#define BREAK 267
#define GOTO 268
#define HASH 269
#define INCLUDE 270
#define CONST_Q 271
#define CONST_INT 272
#define CONST_FLOAT 273
#define IDENTIFIER 274
#define STRING 275
#define CONST 276
#define PRINTF 277
#define AND_OP 278
#define OR_OP 279
#define LE_OP 280
#define GE_OP 281
#define EQ_OP 282
#define NE_OP 283
#define INC 284
#define DEC 285
#define LEFT_OP 286
#define RIGHT_OP 287

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 13 "grammar/c_syn.y" /* yacc.c:352  */

	struct {
		int count_p;
		int count_m;
		int type;
		int size;
		int val;
		float fval;
		void * sentry;
		int t[4];
		char* string_val;
		int type_counter;

		struct ast* _ast;
		char * string_exp;
	}vv;


#line 209 "y.tab.c" /* yacc.c:352  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */



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
#else
typedef signed char yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && ! defined __ICC && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
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
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
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
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
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

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  21
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   286

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  52
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  45
/* YYNRULES -- Number of rules.  */
#define YYNRULES  112
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  191

#define YYUNDEFTOK  2
#define YYMAXUTOK   287

/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                                \
  ((unsigned) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,    37,    49,     2,
      24,    25,    32,    33,    48,    34,     2,    31,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    26,
      35,    23,    36,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    30,     2,    29,    50,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    28,    51,    27,     2,     2,     2,     2,
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
      15,    16,    17,    18,    19,    20,    21,    22,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    46,    46,    59,    74,    82,    86,    94,    97,   108,
     111,   116,   128,   138,   148,   159,   164,   168,   172,   180,
     184,   195,   207,   228,   232,   243,   248,   253,   257,   261,
     266,   271,   280,   294,   302,   313,   326,   377,   382,   386,
     398,   402,   412,   420,   428,   438,   442,   450,   459,   463,
     476,   487,   502,   507,   519,   533,   539,   550,   563,   569,
     578,   587,   597,   608,   614,   625,   636,   641,   653,   659,
     670,   676,   687,   693,   705,   711,   724,   729,   742,   750,
     754,   771,   793,   805,   812,   818,   827,   843,   859,   872,
     914,   935,   952,   987,  1008,  1021,  1035,  1052,  1055,  1066,
    1078,  1089,  1103,  1110,  1121,  1125,  1141,  1164,  1179,  1195,
    1207,  1220,  1230
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "INT", "VOID", "FLOAT", "FOR", "WHILE",
  "DO", "IF", "ELSE", "RETURN", "BREAK", "GOTO", "HASH", "INCLUDE",
  "CONST_Q", "CONST_INT", "CONST_FLOAT", "IDENTIFIER", "STRING", "CONST",
  "PRINTF", "'='", "'('", "')'", "';'", "'}'", "'{'", "']'", "'['", "'/'",
  "'*'", "'+'", "'-'", "'<'", "'>'", "'%'", "AND_OP", "OR_OP", "LE_OP",
  "GE_OP", "EQ_OP", "NE_OP", "INC", "DEC", "LEFT_OP", "RIGHT_OP", "','",
  "'&'", "'^'", "'|'", "$accept", "start", "include_list", "include_elm",
  "translation_unit", "external_declaration", "function_definition",
  "jump_statement", "compound_statement", "statement_list", "statement",
  "expression_statement", "selection_statement", "iteration_statement",
  "iter_counter", "expression", "postfix_expression", "unary_expression",
  "multiplicative_expression", "additive_expression", "shift_expression",
  "relational_expression", "equality_expression", "and_expression",
  "exclusive_or_expression", "inclusive_or_expression",
  "logical_and_expression", "logical_or_expression",
  "assignment_expression", "assignment_operator", "declaration_list",
  "declaration", "declaration_specifiers", "type_specifier",
  "init_declarator_list", "init_declarator", "declarator",
  "direct_declarator", "parameter_list", "parameter_declaration",
  "pointer", "initializer", "initializer_list", "primary_expression",
  "identifier_list", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,    61,    40,    41,    59,   125,   123,    93,
      91,    47,    42,    43,    45,    60,    62,    37,   278,   279,
     280,   281,   282,   283,   284,   285,   286,   287,    44,    38,
      94,   124
};
# endif

#define YYPACT_NINF -144

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-144)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     116,  -144,  -144,  -144,    21,  -144,   -12,    16,   116,  -144,
     133,  -144,  -144,  -144,     8,  -144,    19,    47,    26,    49,
    -144,  -144,  -144,   133,  -144,   -14,  -144,   251,    39,  -144,
      19,  -144,     8,   142,    56,    47,  -144,  -144,     8,   136,
    -144,    19,    55,    61,   216,    87,    96,  -144,  -144,  -144,
    -144,  -144,   228,  -144,  -144,   228,   228,  -144,  -144,   165,
    -144,  -144,  -144,  -144,   120,    34,   213,   118,    44,   233,
     222,   159,   234,    90,    94,   106,   121,   127,  -144,   105,
    -144,  -144,  -144,   145,  -144,  -144,     8,   -17,  -144,   -15,
     146,  -144,   136,  -144,  -144,  -144,   228,   228,  -144,    38,
    -144,   164,     1,  -144,  -144,  -144,  -144,   147,  -144,   228,
     161,   228,  -144,  -144,  -144,   228,   228,   228,   228,   228,
     228,   228,   228,   228,   228,   228,   228,   228,   228,   228,
     228,   228,   228,   228,  -144,   194,  -144,  -144,   193,  -144,
     183,  -144,  -144,   131,    14,    86,  -144,  -144,  -144,   206,
    -144,  -144,   140,  -144,  -144,  -144,  -144,  -144,    44,    44,
     233,   233,   222,   222,   222,   222,   159,   159,   234,    90,
      94,   106,   121,  -144,  -144,  -144,  -144,   136,   176,   176,
     206,  -144,  -144,  -144,   198,   228,   176,   103,  -144,   176,
    -144
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,    84,    83,    85,     0,    92,   100,     0,     0,     5,
       2,     7,     9,    10,     0,    82,     0,    91,     0,     0,
     101,     1,     4,     3,     8,     0,    86,    88,    37,    14,
       0,    79,     0,     0,     0,    90,     6,    81,     0,     0,
      12,     0,     0,     0,     0,     0,     0,   107,   108,   106,
     110,    32,     0,    30,    19,     0,     0,    29,    25,    37,
      23,    26,    27,    28,     0,     0,    45,    48,    52,    55,
      58,    63,    66,    68,    70,    72,    74,    76,    38,    37,
      40,    13,    80,    88,   111,    94,     0,     0,    97,     0,
       0,    87,     0,   102,    89,    11,     0,     0,    17,     0,
      16,     0,     0,    46,    47,    20,    24,     0,    31,     0,
       0,     0,    43,    44,    78,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    21,    37,    99,    96,     0,    95,
       0,    93,   104,     0,     0,     0,    18,    15,   109,     0,
      39,    42,     0,    77,    50,    49,    51,    48,    53,    54,
      56,    57,    59,    60,    61,    62,    64,    65,    67,    69,
      71,    73,    75,    22,    98,   112,   103,     0,     0,     0,
       0,    41,   105,    35,    33,     0,     0,     0,    34,     0,
      36
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -144,  -144,  -144,   207,   209,    64,  -144,  -144,   -16,   148,
     -55,  -143,  -144,  -144,  -144,   -43,  -144,   -26,   151,   160,
     139,   156,   100,    89,   110,    99,   111,  -144,   -37,  -144,
     258,    -9,     5,  -144,  -144,   211,     3,   235,  -144,   137,
     253,   -89,  -144,  -144,  -144
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     7,     8,     9,    10,    11,    12,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    67,    68,    69,
      70,    71,    72,    73,    74,    75,    76,    77,    78,   115,
      30,    13,    32,    15,    25,    26,    16,    17,    87,    88,
      18,    94,   143,    80,    89
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      29,    99,    93,   142,   106,    14,   180,    31,   137,   102,
     139,    40,    37,    14,    81,    14,    21,    27,    31,    31,
       6,    82,     1,     2,     3,    95,   148,     5,    14,   103,
     104,   138,    82,   140,    38,    83,    19,   185,    86,   178,
       6,    83,     1,     2,     3,     5,    42,    28,    43,   109,
      44,    45,    46,   144,   145,    93,    47,    48,    49,    50,
     108,    51,   109,    52,   146,    53,    54,    28,   152,    36,
      82,    33,   150,    90,    24,   116,   117,    34,   153,    96,
     106,   118,   109,    55,    56,    97,   109,    24,   182,   136,
     154,   155,   156,   157,   157,   157,   157,   157,   157,   157,
     157,   157,   157,   157,   157,   157,   157,   157,     1,     2,
       3,   179,    42,   100,    43,   101,    44,    45,    46,     1,
       2,     3,    47,    48,    49,    50,   107,    51,   189,    52,
       4,    53,   134,    28,   109,     5,     1,     2,     3,   129,
      93,   114,   187,    86,   130,     1,     2,     3,     6,    55,
      56,   109,     5,    47,    48,    49,    50,   131,   176,   132,
      52,    84,   183,   184,    92,     6,   133,    85,    39,   181,
     188,   149,    42,   190,    43,   141,    44,    45,    46,   177,
      55,    56,    47,    48,    49,    50,   151,    51,   109,    52,
     147,    53,   105,    28,   123,   124,     1,     2,     3,   125,
     126,    42,   175,    43,    28,    44,    45,    46,   186,    55,
      56,    47,    48,    49,    50,    22,    51,    23,    52,   169,
      53,   173,    28,    47,    48,    49,    50,   135,    51,   168,
      52,   171,    53,    47,    48,    49,    50,   110,    55,    56,
      52,   170,    98,   111,   172,    47,    48,    49,    50,    91,
      55,    56,    52,    35,     1,     2,     3,   112,   113,    20,
      55,    56,   162,   163,   164,   165,   119,   120,   121,   122,
     158,   159,    55,    56,    39,   174,   127,   128,     0,    28,
       0,   160,   161,   166,   167,    41,    79
};

static const yytype_int16 yycheck[] =
{
      16,    44,    39,    92,    59,     0,   149,    16,    25,    52,
      25,    27,    26,     8,    30,    10,     0,    14,    27,    28,
      32,    30,     3,     4,     5,    41,    25,    19,    23,    55,
      56,    48,    41,    48,    48,    32,    15,   180,    33,    25,
      32,    38,     3,     4,     5,    19,     7,    28,     9,    48,
      11,    12,    13,    96,    97,    92,    17,    18,    19,    20,
      26,    22,    48,    24,    26,    26,    27,    28,   111,    20,
      79,    24,   109,    17,    10,    31,    32,    30,   115,    24,
     135,    37,    48,    44,    45,    24,    48,    23,   177,    86,
     116,   117,   118,   119,   120,   121,   122,   123,   124,   125,
     126,   127,   128,   129,   130,   131,   132,   133,     3,     4,
       5,    25,     7,    26,     9,    19,    11,    12,    13,     3,
       4,     5,    17,    18,    19,    20,     6,    22,    25,    24,
      14,    26,    27,    28,    48,    19,     3,     4,     5,    49,
     177,    23,   185,   138,    50,     3,     4,     5,    32,    44,
      45,    48,    19,    17,    18,    19,    20,    51,    27,    38,
      24,    19,   178,   179,    28,    32,    39,    25,    23,    29,
     186,    24,     7,   189,     9,    29,    11,    12,    13,    48,
      44,    45,    17,    18,    19,    20,    25,    22,    48,    24,
      26,    26,    27,    28,    35,    36,     3,     4,     5,    40,
      41,     7,    19,     9,    28,    11,    12,    13,    10,    44,
      45,    17,    18,    19,    20,     8,    22,     8,    24,   130,
      26,    27,    28,    17,    18,    19,    20,    79,    22,   129,
      24,   132,    26,    17,    18,    19,    20,    24,    44,    45,
      24,   131,    26,    30,   133,    17,    18,    19,    20,    38,
      44,    45,    24,    18,     3,     4,     5,    44,    45,     6,
      44,    45,   123,   124,   125,   126,    33,    34,    46,    47,
     119,   120,    44,    45,    23,   138,    42,    43,    -1,    28,
      -1,   121,   122,   127,   128,    27,    28
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,     4,     5,    14,    19,    32,    53,    54,    55,
      56,    57,    58,    83,    84,    85,    88,    89,    92,    15,
      92,     0,    55,    56,    57,    86,    87,    88,    28,    60,
      82,    83,    84,    24,    30,    89,    20,    26,    48,    23,
      60,    82,     7,     9,    11,    12,    13,    17,    18,    19,
      20,    22,    24,    26,    27,    44,    45,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    68,    69,    70,    71,
      72,    73,    74,    75,    76,    77,    78,    79,    80,    82,
      95,    60,    83,    88,    19,    25,    84,    90,    91,    96,
      17,    87,    28,    80,    93,    60,    24,    24,    26,    67,
      26,    19,    67,    69,    69,    27,    62,     6,    26,    48,
      24,    30,    44,    45,    23,    81,    31,    32,    37,    33,
      34,    46,    47,    35,    36,    40,    41,    42,    43,    49,
      50,    51,    38,    39,    27,    61,    88,    25,    48,    25,
      48,    29,    93,    94,    67,    67,    26,    26,    25,    24,
      80,    25,    67,    80,    69,    69,    69,    69,    70,    70,
      71,    71,    72,    72,    72,    72,    73,    73,    74,    75,
      76,    77,    78,    27,    91,    19,    27,    48,    25,    25,
      63,    29,    93,    60,    60,    63,    10,    67,    60,    25,
      60
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    52,    53,    53,    54,    54,    55,    56,    56,    57,
      57,    58,    58,    58,    58,    59,    59,    59,    59,    60,
      60,    60,    60,    61,    61,    62,    62,    62,    62,    62,
      63,    63,    63,    64,    64,    65,    65,    66,    67,    67,
      68,    68,    68,    68,    68,    69,    69,    69,    70,    70,
      70,    70,    71,    71,    71,    72,    72,    72,    73,    73,
      73,    73,    73,    74,    74,    74,    75,    75,    76,    76,
      77,    77,    78,    78,    79,    79,    80,    80,    81,    82,
      82,    83,    84,    85,    85,    85,    86,    86,    87,    87,
      88,    88,    89,    89,    89,    89,    89,    90,    90,    91,
      92,    92,    93,    93,    94,    94,    95,    95,    95,    95,
      95,    96,    96
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     2,     2,     1,     3,     1,     2,     1,
       1,     4,     3,     3,     2,     3,     2,     2,     3,     2,
       3,     3,     4,     1,     2,     1,     1,     1,     1,     1,
       1,     2,     1,     5,     7,     5,     8,     0,     1,     3,
       1,     4,     3,     2,     2,     1,     2,     2,     1,     3,
       3,     3,     1,     3,     3,     1,     3,     3,     1,     3,
       3,     3,     3,     1,     3,     3,     1,     3,     1,     3,
       1,     3,     1,     3,     1,     3,     1,     3,     1,     1,
       2,     3,     1,     1,     1,     1,     1,     3,     1,     3,
       2,     1,     1,     4,     3,     4,     4,     1,     3,     2,
       1,     2,     1,     3,     1,     3,     1,     1,     1,     3,
       1,     1,     3
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YYUSE (yyoutput);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyo, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyo, yytype, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  unsigned long yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &yyvsp[(yyi + 1) - (yynrhs)]
                                              );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
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
#ifndef YYINITDEPTH
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
static YYSIZE_T
yystrlen (const char *yystr)
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
static char *
yystpcpy (char *yydest, const char *yysrc)
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
            else
              goto append;

          append:
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

  return (YYSIZE_T) (yystpcpy (yyres, yystr) - yyres);
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
                    yysize = yysize1;
                  else
                    return 2;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
    default: /* Avoid compiler warnings. */
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
      yysize = yysize1;
    else
      return 2;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
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
  int yytoken = 0;
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

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yynewstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  *yyssp = (yytype_int16) yystate;

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    goto yyexhaustedlab;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = (YYSIZE_T) (yyssp - yyss + 1);

# if defined yyoverflow
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
# else /* defined YYSTACK_RELOCATE */
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
# undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
                  (unsigned long) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */

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
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
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
      if (yytable_value_is_error (yyn))
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
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

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
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

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
#line 46 "grammar/c_syn.y" /* yacc.c:1652  */
    {
		printf("-->\n%s\n",(yyvsp[0].vv).string_exp);
		    char * inc = "#include <cblas.h>"
                                 "#include <primitives.h>";
		FILE* d = fopen(file_out, "a");
		char* tot = malloc(strlen((yyvsp[0].vv).string_exp)+100);
		memset(tot,0,strlen((yyvsp[0].vv).string_exp)+100);
		snprintf(tot,strlen((yyvsp[0].vv).string_exp)+100,"%s\n%s",inc,(yyvsp[0].vv).string_exp);
		printf("%s\n",tot);
		fprintf(d,"%s",tot);
		free((yyvsp[0].vv).string_exp);
		free(tot);
}
#line 1482 "y.tab.c" /* yacc.c:1652  */
    break;

  case 3:
#line 59 "grammar/c_syn.y" /* yacc.c:1652  */
    {
     		int len1 = strlen((yyvsp[-1].vv).string_exp);
     		int len2 = strlen((yyvsp[0].vv).string_exp);
    		char* res = malloc(len1+len2+100);
	    	char * inc = "#include \"cblas.h\"\n"
			 "#include \"primitives.h\"";
		snprintf(res,len1+len2+100, "%s\n%s\n%s",inc,(yyvsp[-1].vv).string_exp,(yyvsp[0].vv).string_exp);

		printf("-->\n%s\n",res);
		FILE* d = fopen(file_out, "w");
		fprintf(d,"%s",res);
		free((yyvsp[-1].vv).string_exp);
		free((yyvsp[0].vv).string_exp);
     }
#line 1501 "y.tab.c" /* yacc.c:1652  */
    break;

  case 4:
#line 74 "grammar/c_syn.y" /* yacc.c:1652  */
    {
            	int len1 = strlen((yyvsp[-1].vv).string_exp);
		int len2 = strlen((yyvsp[0].vv).string_exp);
		(yyval.vv).string_exp = malloc(len1+len2+2);
		snprintf((yyval.vv).string_exp,len1+len2+2, "%s\n%s",(yyvsp[-1].vv).string_exp,(yyvsp[0].vv).string_exp);
            	free((yyvsp[-1].vv).string_exp);
            	free((yyvsp[0].vv).string_exp);
            }
#line 1514 "y.tab.c" /* yacc.c:1652  */
    break;

  case 5:
#line 82 "grammar/c_syn.y" /* yacc.c:1652  */
    {
	    	(yyval.vv).string_exp = (yyvsp[0].vv).string_exp;
	    }
#line 1522 "y.tab.c" /* yacc.c:1652  */
    break;

  case 6:
#line 86 "grammar/c_syn.y" /* yacc.c:1652  */
    {
	int len = strlen((yyvsp[0].vv).string_val)+10;
	(yyval.vv).string_exp = malloc(len);
	snprintf((yyval.vv).string_exp,len,"#include %s",(yyvsp[0].vv).string_val);
}
#line 1532 "y.tab.c" /* yacc.c:1652  */
    break;

  case 7:
#line 94 "grammar/c_syn.y" /* yacc.c:1652  */
    {
		(yyval.vv).string_exp = (yyvsp[0].vv).string_exp;
	}
#line 1540 "y.tab.c" /* yacc.c:1652  */
    break;

  case 8:
#line 97 "grammar/c_syn.y" /* yacc.c:1652  */
    {
		int len1 = strlen((yyvsp[-1].vv).string_exp);
		int len2 = strlen((yyvsp[0].vv).string_exp);
		(yyval.vv).string_exp = malloc(len1+len2+2);
		snprintf((yyval.vv).string_exp,len1+len2+2, "%s\n%s",(yyvsp[-1].vv).string_exp,(yyvsp[0].vv).string_exp);
		free((yyvsp[-1].vv).string_exp);
		free((yyvsp[0].vv).string_exp);
	}
#line 1553 "y.tab.c" /* yacc.c:1652  */
    break;

  case 9:
#line 108 "grammar/c_syn.y" /* yacc.c:1652  */
    {
			(yyval.vv).string_exp = (yyvsp[0].vv).string_exp;
	}
#line 1561 "y.tab.c" /* yacc.c:1652  */
    break;

  case 10:
#line 111 "grammar/c_syn.y" /* yacc.c:1652  */
    {
		(yyval.vv).string_exp = (yyvsp[0].vv).string_exp;
	}
#line 1569 "y.tab.c" /* yacc.c:1652  */
    break;

  case 11:
#line 116 "grammar/c_syn.y" /* yacc.c:1652  */
    {
		int len1 = strlen((yyvsp[-3].vv).string_exp);
		int len2 = strlen((yyvsp[-2].vv).string_exp);
		int len3 = strlen((yyvsp[-1].vv).string_exp);
		int len4 = strlen((yyvsp[0].vv).string_exp);
		(yyval.vv).string_exp = malloc(len1+len2+len3+len4+4);
		snprintf((yyval.vv).string_exp,len1+len2+len3+len4+4, "%s %s\n%s\n%s",(yyvsp[-3].vv).string_exp,(yyvsp[-2].vv).string_exp,(yyvsp[-1].vv).string_exp,(yyvsp[0].vv).string_exp);
		free((yyvsp[-3].vv).string_exp);
		free((yyvsp[-2].vv).string_exp);
		free((yyvsp[-1].vv).string_exp);
		free((yyvsp[0].vv).string_exp);
	}
#line 1586 "y.tab.c" /* yacc.c:1652  */
    break;

  case 12:
#line 128 "grammar/c_syn.y" /* yacc.c:1652  */
    {
		int len1 = strlen((yyvsp[-2].vv).string_exp);
		int len2 = strlen((yyvsp[-1].vv).string_exp);
		int len3 = strlen((yyvsp[0].vv).string_exp);
		(yyval.vv).string_exp = malloc(len1+len2+len3+3);
		snprintf((yyval.vv).string_exp,len1+len2+len3+3, "%s %s\n%s",(yyvsp[-2].vv).string_exp,(yyvsp[-1].vv).string_exp,(yyvsp[0].vv).string_exp);
		free((yyvsp[-2].vv).string_exp);
		free((yyvsp[-1].vv).string_exp);
		free((yyvsp[0].vv).string_exp);
	}
#line 1601 "y.tab.c" /* yacc.c:1652  */
    break;

  case 13:
#line 138 "grammar/c_syn.y" /* yacc.c:1652  */
    {
		int len1 = strlen((yyvsp[-2].vv).string_exp);
		int len2 = strlen((yyvsp[-1].vv).string_exp);
		int len3 = strlen((yyvsp[0].vv).string_exp);
		(yyval.vv).string_exp = malloc(len1+len2+len3+3);
		snprintf((yyval.vv).string_exp,len1+len2+2, "%s\n%s\n%s",(yyvsp[-2].vv).string_exp,(yyvsp[-1].vv).string_exp,(yyvsp[0].vv).string_exp);
		free((yyvsp[-2].vv).string_exp);
		free((yyvsp[-1].vv).string_exp);
		free((yyvsp[0].vv).string_exp);
	}
#line 1616 "y.tab.c" /* yacc.c:1652  */
    break;

  case 14:
#line 148 "grammar/c_syn.y" /* yacc.c:1652  */
    {
		int len1 = strlen((yyvsp[-1].vv).string_exp);
		int len2 = strlen((yyvsp[0].vv).string_exp);
		(yyval.vv).string_exp = malloc(len1+len2+2);
		snprintf((yyval.vv).string_exp,len1+len2+2, "%s\n%s",(yyvsp[-1].vv).string_exp,(yyvsp[0].vv).string_exp);
		free((yyvsp[-1].vv).string_exp);
		free((yyvsp[0].vv).string_exp);
	}
#line 1629 "y.tab.c" /* yacc.c:1652  */
    break;

  case 15:
#line 159 "grammar/c_syn.y" /* yacc.c:1652  */
    {
		int len1 = strlen((yyvsp[-1].vv).string_val);
		(yyval.vv).string_exp = malloc(len1+8);
		snprintf((yyval.vv).string_exp,len1+8, "goto %s ;",(yyvsp[-1].vv).string_val);
	}
#line 1639 "y.tab.c" /* yacc.c:1652  */
    break;

  case 16:
#line 164 "grammar/c_syn.y" /* yacc.c:1652  */
    {
		(yyval.vv).string_exp = malloc(7);
		snprintf((yyval.vv).string_exp,7, "break;");
	}
#line 1648 "y.tab.c" /* yacc.c:1652  */
    break;

  case 17:
#line 168 "grammar/c_syn.y" /* yacc.c:1652  */
    {
		(yyval.vv).string_exp = malloc(8);
		snprintf((yyval.vv).string_exp,8, "return;");
	}
#line 1657 "y.tab.c" /* yacc.c:1652  */
    break;

  case 18:
#line 172 "grammar/c_syn.y" /* yacc.c:1652  */
    {
		int len1 = strlen((yyvsp[-1].vv).string_exp);
		(yyval.vv).string_exp = malloc(len1+10);
		snprintf((yyval.vv).string_exp,len1+10, "return %s ;",(yyvsp[-1].vv).string_exp);
		free((yyvsp[-1].vv).string_exp);
	}
#line 1668 "y.tab.c" /* yacc.c:1652  */
    break;

  case 19:
#line 180 "grammar/c_syn.y" /* yacc.c:1652  */
    {
		(yyval.vv).string_exp = malloc(4);
		snprintf((yyval.vv).string_exp,4, "{ }");
	}
#line 1677 "y.tab.c" /* yacc.c:1652  */
    break;

  case 20:
#line 184 "grammar/c_syn.y" /* yacc.c:1652  */
    {
		int len1 = strlen((yyvsp[-1].vv).string_exp);
		(yyval.vv).string_exp = malloc(len1+3);
		snprintf((yyval.vv).string_exp,len1+3, "{%s}",(yyvsp[-1].vv).string_exp);
		free((yyvsp[-1].vv).string_exp);
		//ast_print($2._ast,0);

	  	 (yyval.vv)._ast = (yyvsp[-1].vv)._ast;


	}
#line 1693 "y.tab.c" /* yacc.c:1652  */
    break;

  case 21:
#line 195 "grammar/c_syn.y" /* yacc.c:1652  */
    {
		int len1 = strlen((yyvsp[-1].vv).string_exp);
		(yyval.vv).string_exp = malloc(len1+3);
		snprintf((yyval.vv).string_exp,len1+3, "{%s}",(yyvsp[-1].vv).string_exp);
		free((yyvsp[-1].vv).string_exp);

	   	(yyval.vv)._ast = (yyvsp[-1].vv)._ast;

		//ast_print($2._ast,0);


	}
#line 1710 "y.tab.c" /* yacc.c:1652  */
    break;

  case 22:
#line 207 "grammar/c_syn.y" /* yacc.c:1652  */
    {
		int len1 = strlen((yyvsp[-2].vv).string_exp);
		int len2 = strlen((yyvsp[-1].vv).string_exp);
		(yyval.vv).string_exp = malloc(len1+len2+6);
		snprintf((yyval.vv).string_exp,len1+len2+6, "{\n%s\n%s\n}",(yyvsp[-2].vv).string_exp,(yyvsp[-1].vv).string_exp);
		free((yyvsp[-2].vv).string_exp);
		free((yyvsp[-1].vv).string_exp);

		//ast_print($2._ast,0);
		printf("---------------------------\n");
		//ast_print($3._ast,0);


	}
#line 1729 "y.tab.c" /* yacc.c:1652  */
    break;

  case 23:
#line 228 "grammar/c_syn.y" /* yacc.c:1652  */
    {
		   (yyval.vv).string_exp = (yyvsp[0].vv).string_exp;
		   (yyval.vv)._ast = (yyvsp[0].vv)._ast;
	}
#line 1738 "y.tab.c" /* yacc.c:1652  */
    break;

  case 24:
#line 232 "grammar/c_syn.y" /* yacc.c:1652  */
    {
                int len1 = strlen((yyvsp[-1].vv).string_exp);
		int len2 = strlen((yyvsp[0].vv).string_exp);
		(yyval.vv).string_exp = malloc(len1+len2+2);
		snprintf((yyval.vv).string_exp,len1+len2+2, "%s\n%s",(yyvsp[-1].vv).string_exp,(yyvsp[0].vv).string_exp);
		free((yyvsp[-1].vv).string_exp);
		free((yyvsp[0].vv).string_exp);
		(yyval.vv)._ast = ast_new_operation(AST_STATE_LIST,(yyvsp[-1].vv)._ast,(yyvsp[0].vv)._ast);
	}
#line 1752 "y.tab.c" /* yacc.c:1652  */
    break;

  case 25:
#line 243 "grammar/c_syn.y" /* yacc.c:1652  */
    {
	 (yyval.vv).string_exp = (yyvsp[0].vv).string_exp;
	 (yyval.vv)._ast = (yyvsp[0].vv)._ast;

	  }
#line 1762 "y.tab.c" /* yacc.c:1652  */
    break;

  case 26:
#line 248 "grammar/c_syn.y" /* yacc.c:1652  */
    {
         (yyval.vv).string_exp = (yyvsp[0].vv).string_exp;
	 //$$._ast = $1._ast;

	}
#line 1772 "y.tab.c" /* yacc.c:1652  */
    break;

  case 27:
#line 253 "grammar/c_syn.y" /* yacc.c:1652  */
    {

		(yyval.vv).string_exp = (yyvsp[0].vv).string_exp;
	}
#line 1781 "y.tab.c" /* yacc.c:1652  */
    break;

  case 28:
#line 257 "grammar/c_syn.y" /* yacc.c:1652  */
    {
		(yyval.vv).string_exp = (yyvsp[0].vv).string_exp;
		(yyval.vv)._ast = (yyvsp[0].vv)._ast;
	}
#line 1790 "y.tab.c" /* yacc.c:1652  */
    break;

  case 29:
#line 261 "grammar/c_syn.y" /* yacc.c:1652  */
    {
		(yyval.vv).string_exp = (yyvsp[0].vv).string_exp;
	}
#line 1798 "y.tab.c" /* yacc.c:1652  */
    break;

  case 30:
#line 266 "grammar/c_syn.y" /* yacc.c:1652  */
    {
		(yyval.vv).string_exp = malloc(2);
		snprintf((yyval.vv).string_exp,2, ";");

	}
#line 1808 "y.tab.c" /* yacc.c:1652  */
    break;

  case 31:
#line 271 "grammar/c_syn.y" /* yacc.c:1652  */
    {
		int len = strlen((yyvsp[-1].vv).string_exp);
		(yyval.vv).string_exp = malloc(len+2);
		snprintf((yyval.vv).string_exp,len+2, "%s;",(yyvsp[-1].vv).string_exp);
		//printf("\n---------TEST777------ | %s |---------\n",$1.string_exp);
		free((yyvsp[-1].vv).string_exp);

		(yyval.vv)._ast = (yyvsp[-1].vv)._ast;
	}
#line 1822 "y.tab.c" /* yacc.c:1652  */
    break;

  case 32:
#line 280 "grammar/c_syn.y" /* yacc.c:1652  */
    {
		int len = strlen((yyvsp[0].vv).string_val);
		(yyval.vv).string_exp = malloc(len+2);
		snprintf((yyval.vv).string_exp,len+2,"%s\n",(yyvsp[0].vv).string_val);
		free((yyvsp[0].vv).string_val);

		(yyval.vv)._ast = ast_new_print();
	}
#line 1835 "y.tab.c" /* yacc.c:1652  */
    break;

  case 33:
#line 294 "grammar/c_syn.y" /* yacc.c:1652  */
    {
		int len1 = strlen((yyvsp[-2].vv).string_exp);
		int len2 = strlen((yyvsp[0].vv).string_exp);
		(yyval.vv).string_exp = malloc(len1+len2+6);
		snprintf((yyval.vv).string_exp,len1+len2+6, "if(%s)\n%s",(yyvsp[-2].vv).string_exp,(yyvsp[0].vv).string_exp);
		free((yyvsp[-2].vv).string_exp);
		free((yyvsp[0].vv).string_exp);
	}
#line 1848 "y.tab.c" /* yacc.c:1652  */
    break;

  case 34:
#line 302 "grammar/c_syn.y" /* yacc.c:1652  */
    {
		int len1 = strlen((yyvsp[-4].vv).string_exp);
		int len2 = strlen((yyvsp[-2].vv).string_exp);
		int len3 = strlen((yyvsp[0].vv).string_exp);
		(yyval.vv).string_exp = malloc(len1+len2+len3+11);
		snprintf((yyval.vv).string_exp,len1+len2+len3+11, "if(%s)\n%s\nelse%s",(yyvsp[-4].vv).string_exp,(yyvsp[-2].vv).string_exp,(yyvsp[0].vv).string_exp);
		free((yyvsp[-4].vv).string_exp);
		free((yyvsp[-2].vv).string_exp);
		free((yyvsp[0].vv).string_exp);
	}
#line 1863 "y.tab.c" /* yacc.c:1652  */
    break;

  case 35:
#line 313 "grammar/c_syn.y" /* yacc.c:1652  */
    {
		 	ast *while_ast = ast_new_operation(AST_WHILE, (yyvsp[-2].vv)._ast, (yyvsp[0].vv)._ast);
			ast_print(while_ast, 0);
			(yyval.vv)._ast = while_ast;

	 		int len1 = strlen((yyvsp[-2].vv).string_exp);
         		int len2 = strlen((yyvsp[0].vv).string_exp);
         		(yyval.vv).string_exp = malloc(len1+len2+9);
         		snprintf((yyval.vv).string_exp,len1+len2+9, "while(%s)\n%s",(yyvsp[-2].vv).string_exp,(yyvsp[0].vv).string_exp);
         		free((yyvsp[-2].vv).string_exp);
         		free((yyvsp[0].vv).string_exp);
	 }
#line 1880 "y.tab.c" /* yacc.c:1652  */
    break;

  case 36:
#line 326 "grammar/c_syn.y" /* yacc.c:1652  */
    {

		ast* fora = ast_new_for((yyvsp[-4].vv)._ast,(yyvsp[-3].vv)._ast,(yyvsp[-2].vv)._ast,(yyvsp[0].vv)._ast);
		ast_print(fora,0);
		(yyval.vv)._ast = fora;
		printf("\n[+] S->for_depth_counter_var : %d\n",for_depth_counter_var);
		int len1 = strlen((yyvsp[-4].vv).string_exp);
		int len2 = strlen((yyvsp[-3].vv).string_exp);
		int len3 = strlen((yyvsp[-2].vv).string_exp);
		int len4 = strlen((yyvsp[0].vv).string_exp);
		char *result = malloc(len1+len2+len3+len4+9);
		snprintf(result,len1+len2+len3+len4+9, "for(%s %s %s)\n%s",(yyvsp[-4].vv).string_exp,(yyvsp[-3].vv).string_exp,(yyvsp[-2].vv).string_exp,(yyvsp[0].vv).string_exp);
		(yyval.vv).string_exp = result;
		if(for_depth_counter_var == 1){
			printf("\n--------------Optimizer Call------------\n");
			   FILE *fptr;
                           fptr = fopen(OPTIMIZER_REQUEST,"w");
                           if(fptr == NULL)
                           {
                              perror("File open error!");
                              exit(1);
                           }
                           fprintf(fptr,"%s",result);
                           fclose(fptr);
			   sem_post(globalData.sem_prod_cons);
			   printf("\n--------------BLAST waitting------------\n");
			   sem_wait(globalData.sem_symbol);
			   printf("\n--------------BLAST GOT RESULT %d---------\n",globalData.symbol->optimized);
			   if(globalData.symbol->optimized == 1){
				int lenm = globalData.symbol->bytes_count;
			   	printf("[+] reading optimizer output count(%d)\n",lenm);
			        fptr = fopen(OPTIMIZER_FILE,"r");
			   	char* op_res = malloc(lenm);
			   	memset(op_res,0,lenm);
			   	char *r = fgets(op_res,lenm,fptr);
				
				if (r != NULL) {
					perror("fgets error 363\n");
				}

			   	free((yyval.vv).string_exp);
			   	(yyval.vv).string_exp = op_res;
			   }

		}


		for_depth_counter_var--;
		printf("\n[+] S->for_depth_counter_var : %d\n",for_depth_counter_var);

	}
#line 1936 "y.tab.c" /* yacc.c:1652  */
    break;

  case 37:
#line 377 "grammar/c_syn.y" /* yacc.c:1652  */
    {for_depth_counter_var++;}
#line 1942 "y.tab.c" /* yacc.c:1652  */
    break;

  case 38:
#line 382 "grammar/c_syn.y" /* yacc.c:1652  */
    {
 		(yyval.vv).string_exp = (yyvsp[0].vv).string_exp;
 		(yyval.vv)._ast = (yyvsp[0].vv)._ast;
 	}
#line 1951 "y.tab.c" /* yacc.c:1652  */
    break;

  case 39:
#line 386 "grammar/c_syn.y" /* yacc.c:1652  */
    {

		int len1 = strlen((yyvsp[-2].vv).string_exp);
		int len2 = strlen((yyvsp[0].vv).string_exp);
		(yyval.vv).string_exp = malloc(len1+len2+2);
		snprintf((yyval.vv).string_exp,len1+len2+2, "%s,%s",(yyvsp[-2].vv).string_exp,(yyvsp[0].vv).string_exp);
		free((yyvsp[-2].vv).string_exp);
		free((yyvsp[0].vv).string_exp);
		(yyval.vv)._ast = ast_new_operation(AST_EXPR_LIST,(yyvsp[-2].vv)._ast,(yyvsp[0].vv)._ast);
	}
#line 1966 "y.tab.c" /* yacc.c:1652  */
    break;

  case 40:
#line 398 "grammar/c_syn.y" /* yacc.c:1652  */
    {
		(yyval.vv).string_exp = (yyvsp[0].vv).string_exp;
		(yyval.vv)._ast = (yyvsp[0].vv)._ast;
	}
#line 1975 "y.tab.c" /* yacc.c:1652  */
    break;

  case 41:
#line 402 "grammar/c_syn.y" /* yacc.c:1652  */
    {
		int len1 = strlen((yyvsp[-3].vv).string_exp);
		int len2 = strlen((yyvsp[-1].vv).string_exp);
		(yyval.vv).string_exp = malloc(len1+len2+3);
		snprintf((yyval.vv).string_exp,len1+len2+3, "%s[%s]",(yyvsp[-3].vv).string_exp,(yyvsp[-1].vv).string_exp);
		free((yyvsp[-3].vv).string_exp);
		free((yyvsp[-1].vv).string_exp);

		(yyval.vv)._ast = ast_new_operation(AST_ARR_ACCESS,(yyvsp[-3].vv)._ast,(yyvsp[-1].vv)._ast);
	}
#line 1990 "y.tab.c" /* yacc.c:1652  */
    break;

  case 42:
#line 412 "grammar/c_syn.y" /* yacc.c:1652  */
    {
		int len1 = strlen((yyvsp[-2].vv).string_exp);
		(yyval.vv).string_exp = malloc(len1+3);
		snprintf((yyval.vv).string_exp,len1+3, "%s()",(yyvsp[-2].vv).string_exp);
		free((yyvsp[-2].vv).string_exp);

		(yyval.vv)._ast = ast_new_operation(AST_FUNC_CALL,(yyvsp[-2].vv)._ast,0);
	}
#line 2003 "y.tab.c" /* yacc.c:1652  */
    break;

  case 43:
#line 420 "grammar/c_syn.y" /* yacc.c:1652  */
    {
		int len1 = strlen((yyvsp[-1].vv).string_exp);
		(yyval.vv).string_exp = malloc(len1+3);
		snprintf((yyval.vv).string_exp,len1+3, "%s++",(yyvsp[-1].vv).string_exp);
		free((yyvsp[-1].vv).string_exp);

		(yyval.vv)._ast = ast_new_operation(AST_INC,(yyvsp[-1].vv)._ast,0);
	}
#line 2016 "y.tab.c" /* yacc.c:1652  */
    break;

  case 44:
#line 428 "grammar/c_syn.y" /* yacc.c:1652  */
    {
		int len1 = strlen((yyvsp[-1].vv).string_exp);
		(yyval.vv).string_exp = malloc(len1+3);
		snprintf((yyval.vv).string_exp,len1+3, "%s--",(yyvsp[-1].vv).string_exp);
		free((yyvsp[-1].vv).string_exp);

		(yyval.vv)._ast = ast_new_operation(AST_DEC,(yyvsp[-1].vv)._ast,0);
	}
#line 2029 "y.tab.c" /* yacc.c:1652  */
    break;

  case 45:
#line 438 "grammar/c_syn.y" /* yacc.c:1652  */
    {
		(yyval.vv).string_exp = (yyvsp[0].vv).string_exp;
		(yyval.vv)._ast = (yyvsp[0].vv)._ast;
	}
#line 2038 "y.tab.c" /* yacc.c:1652  */
    break;

  case 46:
#line 442 "grammar/c_syn.y" /* yacc.c:1652  */
    {
		int len2 = strlen((yyvsp[0].vv).string_exp);
		(yyval.vv).string_exp = malloc(len2+3);
		snprintf((yyval.vv).string_exp,len2+3, "++%s",(yyvsp[0].vv).string_exp);
		free((yyvsp[0].vv).string_exp);
		(yyval.vv)._ast = ast_new_operation(AST_INC,0,(yyvsp[0].vv)._ast);

	}
#line 2051 "y.tab.c" /* yacc.c:1652  */
    break;

  case 47:
#line 450 "grammar/c_syn.y" /* yacc.c:1652  */
    {
		int len2 = strlen((yyvsp[0].vv).string_exp);
		(yyval.vv).string_exp = malloc(len2+3);
		snprintf((yyval.vv).string_exp,len2+3, "--%s",(yyvsp[0].vv).string_exp);
		free((yyvsp[0].vv).string_exp);
		(yyval.vv)._ast = ast_new_operation(AST_DEC,0,(yyvsp[0].vv)._ast);
	}
#line 2063 "y.tab.c" /* yacc.c:1652  */
    break;

  case 48:
#line 459 "grammar/c_syn.y" /* yacc.c:1652  */
    {
		(yyval.vv).string_exp = (yyvsp[0].vv).string_exp;
		(yyval.vv)._ast = (yyvsp[0].vv)._ast;
	}
#line 2072 "y.tab.c" /* yacc.c:1652  */
    break;

  case 49:
#line 463 "grammar/c_syn.y" /* yacc.c:1652  */
    {


		int len1 = strlen((yyvsp[-2].vv).string_exp);
		int len2 = strlen((yyvsp[0].vv).string_exp);
		(yyval.vv).string_exp = malloc(len1+len2+2);
		snprintf((yyval.vv).string_exp,len1+len2+2, "%s*%s",(yyvsp[-2].vv).string_exp,(yyvsp[0].vv).string_exp);
		free((yyvsp[-2].vv).string_exp);
		free((yyvsp[0].vv).string_exp);

		(yyval.vv)._ast = ast_new_operation(AST_MUL,(yyvsp[-2].vv)._ast,(yyvsp[0].vv)._ast);

	}
#line 2090 "y.tab.c" /* yacc.c:1652  */
    break;

  case 50:
#line 476 "grammar/c_syn.y" /* yacc.c:1652  */
    {

		int len1 = strlen((yyvsp[-2].vv).string_exp);
		int len2 = strlen((yyvsp[0].vv).string_exp);
		(yyval.vv).string_exp = malloc(len1+len2+2);
		snprintf((yyval.vv).string_exp,len1+len2+2, "%s/%s",(yyvsp[-2].vv).string_exp,(yyvsp[0].vv).string_exp);
		free((yyvsp[-2].vv).string_exp);
		free((yyvsp[0].vv).string_exp);

		(yyval.vv)._ast = ast_new_operation(AST_DIV,(yyvsp[-2].vv)._ast,(yyvsp[0].vv)._ast);
	}
#line 2106 "y.tab.c" /* yacc.c:1652  */
    break;

  case 51:
#line 487 "grammar/c_syn.y" /* yacc.c:1652  */
    {

		int len1 = strlen((yyvsp[-2].vv).string_exp);
		int len2 = strlen((yyvsp[0].vv).string_exp);
		(yyval.vv).string_exp = malloc(len1+len2+4);
		snprintf((yyval.vv).string_exp,len1+len2+4, "%s%%%s",(yyvsp[-2].vv).string_exp,(yyvsp[0].vv).string_exp);
		free((yyvsp[-2].vv).string_exp);
		free((yyvsp[0].vv).string_exp);

		(yyval.vv)._ast = ast_new_operation(AST_MOD,(yyvsp[-2].vv)._ast,(yyvsp[0].vv)._ast);


	}
#line 2124 "y.tab.c" /* yacc.c:1652  */
    break;

  case 52:
#line 502 "grammar/c_syn.y" /* yacc.c:1652  */
    {

		(yyval.vv).string_exp = (yyvsp[0].vv).string_exp;
		(yyval.vv)._ast = (yyvsp[0].vv)._ast;
	}
#line 2134 "y.tab.c" /* yacc.c:1652  */
    break;

  case 53:
#line 507 "grammar/c_syn.y" /* yacc.c:1652  */
    {

		int len1 = strlen((yyvsp[-2].vv).string_exp);
		int len2 = strlen((yyvsp[0].vv).string_exp);
		(yyval.vv).string_exp = malloc(len1+len2+2);
		snprintf((yyval.vv).string_exp,len1+len2+2, "%s+%s",(yyvsp[-2].vv).string_exp,(yyvsp[0].vv).string_exp);
		free((yyvsp[-2].vv).string_exp);
		free((yyvsp[0].vv).string_exp);

		(yyval.vv)._ast = ast_new_operation(AST_ADD,(yyvsp[-2].vv)._ast,(yyvsp[0].vv)._ast);

	}
#line 2151 "y.tab.c" /* yacc.c:1652  */
    break;

  case 54:
#line 519 "grammar/c_syn.y" /* yacc.c:1652  */
    {

		int len1 = strlen((yyvsp[-2].vv).string_exp);
		int len2 = strlen((yyvsp[0].vv).string_exp);
		(yyval.vv).string_exp = malloc(len1+len2+2);
		snprintf((yyval.vv).string_exp,len1+len2+2, "%s-%s",(yyvsp[-2].vv).string_exp,(yyvsp[0].vv).string_exp);
		free((yyvsp[-2].vv).string_exp);
		free((yyvsp[0].vv).string_exp);

		(yyval.vv)._ast = ast_new_operation(AST_SUB,(yyvsp[-2].vv)._ast,(yyvsp[0].vv)._ast);

	}
#line 2168 "y.tab.c" /* yacc.c:1652  */
    break;

  case 55:
#line 533 "grammar/c_syn.y" /* yacc.c:1652  */
    {

		(yyval.vv).string_exp = (yyvsp[0].vv).string_exp;
		(yyval.vv)._ast = (yyvsp[0].vv)._ast;

	}
#line 2179 "y.tab.c" /* yacc.c:1652  */
    break;

  case 56:
#line 539 "grammar/c_syn.y" /* yacc.c:1652  */
    {
		int len1 = strlen((yyvsp[-2].vv).string_exp);
		int len2 = strlen((yyvsp[0].vv).string_exp);
		(yyval.vv).string_exp = malloc(len1+len2+3);
		snprintf((yyval.vv).string_exp,len1+len2+3, "%s<<%s",(yyvsp[-2].vv).string_exp,(yyvsp[0].vv).string_exp);
		free((yyvsp[-2].vv).string_exp);
		free((yyvsp[0].vv).string_exp);

		(yyval.vv)._ast = ast_new_operation(AST_LEFT_OP,(yyvsp[-2].vv)._ast,(yyvsp[0].vv)._ast);

	}
#line 2195 "y.tab.c" /* yacc.c:1652  */
    break;

  case 57:
#line 550 "grammar/c_syn.y" /* yacc.c:1652  */
    {
		int len1 = strlen((yyvsp[-2].vv).string_exp);
		int len2 = strlen((yyvsp[0].vv).string_exp);
		(yyval.vv).string_exp = malloc(len1+len2+3);
		snprintf((yyval.vv).string_exp,len1+len2+3, "%s>>%s",(yyvsp[-2].vv).string_exp,(yyvsp[0].vv).string_exp);
		free((yyvsp[-2].vv).string_exp);
		free((yyvsp[0].vv).string_exp);


		(yyval.vv)._ast = ast_new_operation(AST_RIGHT_OP,(yyvsp[-2].vv)._ast,(yyvsp[0].vv)._ast);
	}
#line 2211 "y.tab.c" /* yacc.c:1652  */
    break;

  case 58:
#line 563 "grammar/c_syn.y" /* yacc.c:1652  */
    {

		(yyval.vv).string_exp = (yyvsp[0].vv).string_exp;
		(yyval.vv)._ast = (yyvsp[0].vv)._ast;

	}
#line 2222 "y.tab.c" /* yacc.c:1652  */
    break;

  case 59:
#line 569 "grammar/c_syn.y" /* yacc.c:1652  */
    {
		int len1 = strlen((yyvsp[-2].vv).string_exp);
		int len2 = strlen((yyvsp[0].vv).string_exp);
		(yyval.vv).string_exp = malloc(len1+len2+2);
		snprintf((yyval.vv).string_exp,len1+len2+2, "%s<%s",(yyvsp[-2].vv).string_exp,(yyvsp[0].vv).string_exp);
		free((yyvsp[-2].vv).string_exp);
		free((yyvsp[0].vv).string_exp);
		(yyval.vv)._ast = ast_new_operation(AST_LOWER,(yyvsp[-2].vv)._ast,(yyvsp[0].vv)._ast);
	}
#line 2236 "y.tab.c" /* yacc.c:1652  */
    break;

  case 60:
#line 578 "grammar/c_syn.y" /* yacc.c:1652  */
    {
		int len1 = strlen((yyvsp[-2].vv).string_exp);
		int len2 = strlen((yyvsp[0].vv).string_exp);
		(yyval.vv).string_exp = malloc(len1+len2+2);
		snprintf((yyval.vv).string_exp,len1+len2+2, "%s>%s",(yyvsp[-2].vv).string_exp,(yyvsp[0].vv).string_exp);
		free((yyvsp[-2].vv).string_exp);
		free((yyvsp[0].vv).string_exp);
		(yyval.vv)._ast = ast_new_operation(AST_GREATER,(yyvsp[-2].vv)._ast,(yyvsp[0].vv)._ast);
	}
#line 2250 "y.tab.c" /* yacc.c:1652  */
    break;

  case 61:
#line 587 "grammar/c_syn.y" /* yacc.c:1652  */
    {
		int len1 = strlen((yyvsp[-2].vv).string_exp);
		int len2 = strlen((yyvsp[0].vv).string_exp);
		(yyval.vv).string_exp = malloc(len1+len2+3);
		snprintf((yyval.vv).string_exp,len1+len2+3, "%s<=%s",(yyvsp[-2].vv).string_exp,(yyvsp[0].vv).string_exp);
		free((yyvsp[-2].vv).string_exp);
		free((yyvsp[0].vv).string_exp);
		(yyval.vv)._ast = ast_new_operation(AST_LOWER_EQUAL,(yyvsp[-2].vv)._ast,(yyvsp[0].vv)._ast);

	}
#line 2265 "y.tab.c" /* yacc.c:1652  */
    break;

  case 62:
#line 597 "grammar/c_syn.y" /* yacc.c:1652  */
    {
		int len1 = strlen((yyvsp[-2].vv).string_exp);
		int len2 = strlen((yyvsp[0].vv).string_exp);
		(yyval.vv).string_exp = malloc(len1+len2+3);
		snprintf((yyval.vv).string_exp,len1+len2+3, "%s>=%s",(yyvsp[-2].vv).string_exp,(yyvsp[0].vv).string_exp);
		free((yyvsp[-2].vv).string_exp);
		free((yyvsp[0].vv).string_exp);
		(yyval.vv)._ast = ast_new_operation(AST_GREATER_EQUAL,(yyvsp[-2].vv)._ast,(yyvsp[0].vv)._ast);
	}
#line 2279 "y.tab.c" /* yacc.c:1652  */
    break;

  case 63:
#line 608 "grammar/c_syn.y" /* yacc.c:1652  */
    {

		(yyval.vv).string_exp = (yyvsp[0].vv).string_exp;
		(yyval.vv)._ast = (yyvsp[0].vv)._ast;

	}
#line 2290 "y.tab.c" /* yacc.c:1652  */
    break;

  case 64:
#line 614 "grammar/c_syn.y" /* yacc.c:1652  */
    {
		int len1 = strlen((yyvsp[-2].vv).string_exp);
		int len2 = strlen((yyvsp[0].vv).string_exp);
		(yyval.vv).string_exp = malloc(len1+len2+3);
		snprintf((yyval.vv).string_exp,len1+len2+3, "%s==%s",(yyvsp[-2].vv).string_exp,(yyvsp[0].vv).string_exp);
		free((yyvsp[-2].vv).string_exp);
		free((yyvsp[0].vv).string_exp);

		(yyval.vv)._ast = ast_new_operation(AST_EQUAL,(yyvsp[-2].vv)._ast,(yyvsp[0].vv)._ast);

	}
#line 2306 "y.tab.c" /* yacc.c:1652  */
    break;

  case 65:
#line 625 "grammar/c_syn.y" /* yacc.c:1652  */
    {
		int len1 = strlen((yyvsp[-2].vv).string_exp);
		int len2 = strlen((yyvsp[0].vv).string_exp);
		(yyval.vv).string_exp = malloc(len1+len2+3);
		snprintf((yyval.vv).string_exp,len1+len2+3, "%s!=%s",(yyvsp[-2].vv).string_exp,(yyvsp[0].vv).string_exp);
		free((yyvsp[-2].vv).string_exp);
		free((yyvsp[0].vv).string_exp);
		(yyval.vv)._ast = ast_new_operation(AST_NOT_EQUAL,(yyvsp[-2].vv)._ast,(yyvsp[0].vv)._ast);
	}
#line 2320 "y.tab.c" /* yacc.c:1652  */
    break;

  case 66:
#line 636 "grammar/c_syn.y" /* yacc.c:1652  */
    {
		(yyval.vv).string_exp = (yyvsp[0].vv).string_exp;
		(yyval.vv)._ast = (yyvsp[0].vv)._ast;

	}
#line 2330 "y.tab.c" /* yacc.c:1652  */
    break;

  case 67:
#line 641 "grammar/c_syn.y" /* yacc.c:1652  */
    {
		int len1 = strlen((yyvsp[-2].vv).string_exp);
		int len2 = strlen((yyvsp[0].vv).string_exp);
		(yyval.vv).string_exp = malloc(len1+len2+2);
		snprintf((yyval.vv).string_exp,len1+len2+2, "%s&%s",(yyvsp[-2].vv).string_exp,(yyvsp[0].vv).string_exp);
		free((yyvsp[-2].vv).string_exp);
		free((yyvsp[0].vv).string_exp);

		(yyval.vv)._ast = ast_new_operation(AST_AND,(yyvsp[-2].vv)._ast,(yyvsp[0].vv)._ast);
	}
#line 2345 "y.tab.c" /* yacc.c:1652  */
    break;

  case 68:
#line 653 "grammar/c_syn.y" /* yacc.c:1652  */
    {

		(yyval.vv).string_exp = (yyvsp[0].vv).string_exp;
		(yyval.vv)._ast = (yyvsp[0].vv)._ast;

	}
#line 2356 "y.tab.c" /* yacc.c:1652  */
    break;

  case 69:
#line 659 "grammar/c_syn.y" /* yacc.c:1652  */
    {
		int len1 = strlen((yyvsp[-2].vv).string_exp);
		int len2 = strlen((yyvsp[0].vv).string_exp);
		(yyval.vv).string_exp = malloc(len1+len2+2);
		snprintf((yyval.vv).string_exp,len1+len2+2, "%s^%s",(yyvsp[-2].vv).string_exp,(yyvsp[0].vv).string_exp);
		free((yyvsp[-2].vv).string_exp);
		free((yyvsp[0].vv).string_exp);
		(yyval.vv)._ast = ast_new_operation(AST_EOR,(yyvsp[-2].vv)._ast,(yyvsp[0].vv)._ast);
	}
#line 2370 "y.tab.c" /* yacc.c:1652  */
    break;

  case 70:
#line 670 "grammar/c_syn.y" /* yacc.c:1652  */
    {

		(yyval.vv).string_exp = (yyvsp[0].vv).string_exp;
		(yyval.vv)._ast = (yyvsp[0].vv)._ast;

	}
#line 2381 "y.tab.c" /* yacc.c:1652  */
    break;

  case 71:
#line 676 "grammar/c_syn.y" /* yacc.c:1652  */
    {
		int len1 = strlen((yyvsp[-2].vv).string_exp);
		int len2 = strlen((yyvsp[0].vv).string_exp);
		(yyval.vv).string_exp = malloc(len1+len2+2);
		snprintf((yyval.vv).string_exp,len1+len2+2, "%s|%s",(yyvsp[-2].vv).string_exp,(yyvsp[0].vv).string_exp);
		free((yyvsp[-2].vv).string_exp);
		free((yyvsp[0].vv).string_exp);
		(yyval.vv)._ast = ast_new_operation(AST_IOR,(yyvsp[-2].vv)._ast,(yyvsp[0].vv)._ast);
	}
#line 2395 "y.tab.c" /* yacc.c:1652  */
    break;

  case 72:
#line 687 "grammar/c_syn.y" /* yacc.c:1652  */
    {

		(yyval.vv).string_exp = (yyvsp[0].vv).string_exp;
		(yyval.vv)._ast = (yyvsp[0].vv)._ast;

	}
#line 2406 "y.tab.c" /* yacc.c:1652  */
    break;

  case 73:
#line 693 "grammar/c_syn.y" /* yacc.c:1652  */
    {
		int len1 = strlen((yyvsp[-2].vv).string_exp);
		int len2 = strlen((yyvsp[0].vv).string_exp);
		(yyval.vv).string_exp = malloc(len1+len2+3);
		snprintf((yyval.vv).string_exp,len1+len2+3, "%s&&%s",(yyvsp[-2].vv).string_exp,(yyvsp[0].vv).string_exp);
		free((yyvsp[-2].vv).string_exp);
		free((yyvsp[0].vv).string_exp);

		(yyval.vv)._ast = ast_new_operation(AST_AND_OP,(yyvsp[-2].vv)._ast,(yyvsp[0].vv)._ast);
	}
#line 2421 "y.tab.c" /* yacc.c:1652  */
    break;

  case 74:
#line 705 "grammar/c_syn.y" /* yacc.c:1652  */
    {

		(yyval.vv).string_exp = (yyvsp[0].vv).string_exp;
		(yyval.vv)._ast = (yyvsp[0].vv)._ast;

	}
#line 2432 "y.tab.c" /* yacc.c:1652  */
    break;

  case 75:
#line 711 "grammar/c_syn.y" /* yacc.c:1652  */
    {
		int len1 = strlen((yyvsp[-2].vv).string_exp);
		int len2 = strlen((yyvsp[0].vv).string_exp);
		(yyval.vv).string_exp = malloc(len1+len2+3);
		snprintf((yyval.vv).string_exp,len1+len2+3, "%s||%s",(yyvsp[-2].vv).string_exp,(yyvsp[0].vv).string_exp);
		free((yyvsp[-2].vv).string_exp);
		free((yyvsp[0].vv).string_exp);
		(yyval.vv)._ast = ast_new_operation(AST_OR_OP,(yyvsp[-2].vv)._ast,(yyvsp[0].vv)._ast);
	}
#line 2446 "y.tab.c" /* yacc.c:1652  */
    break;

  case 76:
#line 724 "grammar/c_syn.y" /* yacc.c:1652  */
    {
		(yyval.vv).string_exp = (yyvsp[0].vv).string_exp;
		(yyval.vv)._ast = (yyvsp[0].vv)._ast;

	}
#line 2456 "y.tab.c" /* yacc.c:1652  */
    break;

  case 77:
#line 729 "grammar/c_syn.y" /* yacc.c:1652  */
    {
		int len1 = strlen((yyvsp[-2].vv).string_exp);
		int len2 = strlen((yyvsp[0].vv).string_exp);
		(yyval.vv).string_exp = malloc(len1+len2+2);
		snprintf((yyval.vv).string_exp,len1+len2+2, "%s=%s",(yyvsp[-2].vv).string_exp,(yyvsp[0].vv).string_exp);
		free((yyvsp[-2].vv).string_exp);
		free((yyvsp[-1].vv).string_exp);
		free((yyvsp[0].vv).string_exp);

		(yyval.vv)._ast = ast_new_operation(AST_ASSIGN,(yyvsp[-2].vv)._ast,(yyvsp[0].vv)._ast);
	}
#line 2472 "y.tab.c" /* yacc.c:1652  */
    break;

  case 78:
#line 742 "grammar/c_syn.y" /* yacc.c:1652  */
    {
		(yyval.vv).string_exp = malloc(2);
		snprintf((yyval.vv).string_exp,2, "=");
	}
#line 2481 "y.tab.c" /* yacc.c:1652  */
    break;

  case 79:
#line 750 "grammar/c_syn.y" /* yacc.c:1652  */
    {
		(yyval.vv).string_exp = (yyvsp[0].vv).string_exp;
		(yyval.vv)._ast = (yyvsp[0].vv)._ast;
	}
#line 2490 "y.tab.c" /* yacc.c:1652  */
    break;

  case 80:
#line 754 "grammar/c_syn.y" /* yacc.c:1652  */
    {

		int len1 = strlen((yyvsp[-1].vv).string_exp);
		int len2 = strlen((yyvsp[0].vv).string_exp);
		(yyval.vv).string_exp = malloc(len1+len2+2);
		snprintf((yyval.vv).string_exp,len1+len2+2, "%s %s",(yyvsp[-1].vv).string_exp,(yyvsp[0].vv).string_exp);
		free((yyvsp[-1].vv).string_exp);
		free((yyvsp[0].vv).string_exp);

		//$$._ast = ast_new_operation(AST_DEC_LIST,$1._ast,$2._ast);


	}
#line 2508 "y.tab.c" /* yacc.c:1652  */
    break;

  case 81:
#line 771 "grammar/c_syn.y" /* yacc.c:1652  */
    {
		//restore the current type variable to -1
		 current_type_var = -1;

		//COP
		int len1 = strlen((yyvsp[-2].vv).string_exp);
		int len2 = strlen((yyvsp[-1].vv).string_exp);
		(yyval.vv).string_exp = malloc(len1+len2+3);
		snprintf((yyval.vv).string_exp,len1+len2+3, "%s %s;",(yyvsp[-2].vv).string_exp,(yyvsp[-1].vv).string_exp);
		free((yyvsp[-2].vv).string_exp);
		free((yyvsp[-1].vv).string_exp);

		//===========================CHECK HERE DECLARATION AST
		(yyval.vv)._ast = ast_new_operation(AST_DEC_LIST,0,(yyvsp[-1].vv)._ast);
		ast_print((yyval.vv)._ast,0);

	}
#line 2530 "y.tab.c" /* yacc.c:1652  */
    break;

  case 82:
#line 793 "grammar/c_syn.y" /* yacc.c:1652  */
    {
		 //$$.type = $1.type; INT or FLAT ...
		 //store the current type in a global variable....TODO
		 //TODO check composed types=====!
		 current_type_var = (yyvsp[0].vv).type;

		 (yyval.vv).string_exp = (yyvsp[0].vv).string_exp;
	}
#line 2543 "y.tab.c" /* yacc.c:1652  */
    break;

  case 83:
#line 805 "grammar/c_syn.y" /* yacc.c:1652  */
    {
		(yyval.vv).type = VOID;

		(yyval.vv).string_exp = malloc(5);
		snprintf((yyval.vv).string_exp,5, "void");

	}
#line 2555 "y.tab.c" /* yacc.c:1652  */
    break;

  case 84:
#line 812 "grammar/c_syn.y" /* yacc.c:1652  */
    {
		(yyval.vv).type = INT;

		(yyval.vv).string_exp = malloc(4);
		snprintf((yyval.vv).string_exp,4, "int");
	}
#line 2566 "y.tab.c" /* yacc.c:1652  */
    break;

  case 85:
#line 818 "grammar/c_syn.y" /* yacc.c:1652  */
    {
		(yyval.vv).type = FLOAT;
		(yyval.vv).string_exp = malloc(6);
		snprintf((yyval.vv).string_exp,6, "float");
	}
#line 2576 "y.tab.c" /* yacc.c:1652  */
    break;

  case 86:
#line 827 "grammar/c_syn.y" /* yacc.c:1652  */
    {
		symbol_p varp = (symbol_p) (yyvsp[0].vv).sentry;
		int countp = (yyvsp[0].vv).count_p; //TODO maybe 0
		int countm = (yyvsp[0].vv).count_m;
		if(countp > 0 || countm > 0){
			varp->type = TYPE_ARRAY;
			varp->arr.dimention_m = countm;
			varp->arr.dimention_p = countp;
			for(int pp = 0;pp<4;pp++)
				varp->arr.size[pp] = (yyvsp[0].vv).t[pp];

		}

		(yyval.vv).string_exp = (yyvsp[0].vv).string_exp;

	}
#line 2597 "y.tab.c" /* yacc.c:1652  */
    break;

  case 87:
#line 843 "grammar/c_syn.y" /* yacc.c:1652  */
    {


	//COPY
	int len1 = strlen((yyvsp[-2].vv).string_exp);
	int len2 = strlen((yyvsp[0].vv).string_exp);
	(yyval.vv).string_exp = malloc(len1+len2+2);
	snprintf((yyval.vv).string_exp,len1+len2+2, "%s,%s",(yyvsp[-2].vv).string_exp,(yyvsp[0].vv).string_exp);
	free((yyvsp[-2].vv).string_exp);
	free((yyvsp[0].vv).string_exp);

	}
#line 2614 "y.tab.c" /* yacc.c:1652  */
    break;

  case 88:
#line 859 "grammar/c_syn.y" /* yacc.c:1652  */
    {
		for(int l = 0;l<4;l++)
			(yyval.vv).t[l] = (yyvsp[0].vv).t[l];
		(yyval.vv).sentry = (yyvsp[0].vv).sentry;
		(yyval.vv).count_p  = (yyvsp[0].vv).count_p; //TODO maybe 0
		(yyval.vv).count_m  = (yyvsp[0].vv).count_m;

		(yyval.vv).string_exp = (yyvsp[0].vv).string_exp;
		symbol_p e= (yyval.vv).sentry;
		e->glob_type = current_type_var;

		(yyval.vv)._ast = (yyvsp[0].vv)._ast;
	}
#line 2632 "y.tab.c" /* yacc.c:1652  */
    break;

  case 89:
#line 872 "grammar/c_syn.y" /* yacc.c:1652  */
    {
		for(int l = 0;l<4;l++){
			(yyval.vv).t[l] = (yyvsp[-2].vv).t[l];
		}
		(yyval.vv).sentry = (yyvsp[-2].vv).sentry;
		(yyval.vv).count_p  = (yyvsp[-2].vv).count_p; //TODO maybe 0
		(yyval.vv).count_m  = (yyvsp[-2].vv).count_m;

		symbol_p e = (yyvsp[-2].vv).sentry;
		e->is_init = 1;
		e->glob_type = current_type_var;

		if(e->type == TYPE_VARIABLE && (yyvsp[0].vv).type != 1){
			printf("error :VAR Assignement bad type line: %d\n",line_counter+1);
			return -1;
		}
		if(e->type == TYPE_ARRAY && (yyvsp[0].vv).type != 0){
			printf("error :ARR Assignement bad type line: %d\n",line_counter+1);
			return -1;
		}
		if(e->type == TYPE_FUNCTION){
			printf("error :Functions can't be assigned line: %d\n",line_counter+1);
			return -1;
		}


		int len1 = strlen((yyvsp[-2].vv).string_exp);
		int len2 = strlen((yyvsp[0].vv).string_exp);
		(yyval.vv).string_exp = malloc(len1+len2+2);
		snprintf((yyval.vv).string_exp,len1+len2+2, "%s=%s",(yyvsp[-2].vv).string_exp,(yyvsp[0].vv).string_exp);
		free((yyvsp[-2].vv).string_exp);
		free((yyvsp[0].vv).string_exp);

		(yyval.vv)._ast = ast_new_operation(AST_ASSIGN,(yyvsp[-2].vv)._ast,(yyvsp[0].vv)._ast);


	}
#line 2674 "y.tab.c" /* yacc.c:1652  */
    break;

  case 90:
#line 914 "grammar/c_syn.y" /* yacc.c:1652  */
    {
		for(int l = 0;l<4;l++)
			(yyval.vv).t[l] = (yyvsp[0].vv).t[l];
		(yyval.vv).sentry = (yyvsp[0].vv).sentry;
		(yyval.vv).count_p  = (yyvsp[-1].vv).count_p;
		(yyval.vv).count_m  = (yyvsp[0].vv).count_m;
		(yyval.vv).string_val = (yyvsp[-1].vv).string_val;



		int len1 = strlen((yyvsp[-1].vv).string_exp);
		int len2 = strlen((yyvsp[0].vv).string_exp);
		(yyval.vv).string_exp = malloc(len1+len2+1);
		snprintf((yyval.vv).string_exp,len1+len2+1, "%s%s",(yyvsp[-1].vv).string_exp,(yyvsp[0].vv).string_exp);
		free((yyvsp[-1].vv).string_exp);
		free((yyvsp[0].vv).string_exp);



		(yyval.vv)._ast = (yyvsp[0].vv)._ast;
	}
#line 2700 "y.tab.c" /* yacc.c:1652  */
    break;

  case 91:
#line 935 "grammar/c_syn.y" /* yacc.c:1652  */
    {

		for(int l = 0;l<4;l++)
			(yyval.vv).t[l] = (yyvsp[0].vv).t[l];
		(yyval.vv).sentry = (yyvsp[0].vv).sentry;
		(yyval.vv).count_p  = (yyvsp[0].vv).count_p; //TODO maybe 0
		(yyval.vv).count_m  = (yyvsp[0].vv).count_m;
	//COPY
		(yyval.vv).string_exp = (yyvsp[0].vv).string_exp;

		(yyval.vv)._ast = (yyvsp[0].vv)._ast;

	}
#line 2718 "y.tab.c" /* yacc.c:1652  */
    break;

  case 92:
#line 952 "grammar/c_syn.y" /* yacc.c:1652  */
    {
		(yyval.vv).count_p  = 0;
		(yyval.vv).count_m  = 0;
		direct_declarator_var = 0;
		(yyval.vv).sentry = (yyvsp[0].vv).sentry;
		symbol_p tmp = (yyval.vv).sentry;
		tmp->type = TYPE_VARIABLE;
		(yyval.vv).string_val = (yyvsp[0].vv).string_val;

		//set is_dec bit for the current variable;
		char * curr_var_name_tmp = (yyvsp[0].vv).string_val;
		if(current_type_var != -1){
		    symbol_p tttt;
	   	     // int rep = lookup_symbol_entry(curr_var_name_tmp,&tttt);
	   	     printf("lookinf for %s\n",curr_var_name_tmp);
		    lookup_symbol_entry(curr_var_name_tmp,&tttt);
		    if(tttt->is_dec == 1){
			printf("error : Redeclaration of variable %s\tat line : %d\n",curr_var_name_tmp,line_counter+1);
			return -1;
		    }
		    //not yet declared...so set is_dec bit
		    tttt->is_dec = 1;
		}

		printf("---------------962----------identifier : %s\n",curr_var_name_tmp);

		int len = strlen(curr_var_name_tmp);
		(yyval.vv).string_exp = malloc(len+1);
		snprintf((yyval.vv).string_exp,len+1, "%s",curr_var_name_tmp);

		(yyval.vv)._ast = ast_new_id(curr_var_name_tmp);



	}
#line 2758 "y.tab.c" /* yacc.c:1652  */
    break;

  case 93:
#line 987 "grammar/c_syn.y" /* yacc.c:1652  */
    {
         	//$$ = $1 +1;
        	(yyval.vv).t[direct_declarator_var] = (yyvsp[-1].vv).val;
         	direct_declarator_var++;
		(yyval.vv).count_m = direct_declarator_var;
		(yyval.vv).string_val = (yyvsp[-3].vv).string_val;

		(yyval.vv).sentry = (yyvsp[-3].vv).sentry;
		symbol_p tmp = (yyval.vv).sentry;
		tmp->type = TYPE_ARRAY;

		int len1 = strlen((yyvsp[-3].vv).string_exp);
		int len2 = strlen((yyvsp[-1].vv).string_val);
		(yyval.vv).string_exp = malloc(len1+len2+3);
		snprintf((yyval.vv).string_exp,len1+len2+4, "%s[%s]",(yyvsp[-3].vv).string_exp,(yyvsp[-1].vv).string_val);
		free((yyvsp[-3].vv).string_exp);

		(yyval.vv)._ast = ast_new_operation(AST_ARR_ACCESS,(yyvsp[-3].vv)._ast,ast_new_number((yyvsp[-1].vv).val));
		current_type_var = -1;

        }
#line 2784 "y.tab.c" /* yacc.c:1652  */
    break;

  case 94:
#line 1008 "grammar/c_syn.y" /* yacc.c:1652  */
    {
        		current_type_var = -1;
			printf("TEST940\n");
       			int len1 = strlen((yyvsp[-2].vv).string_exp);
        		(yyval.vv).string_exp = malloc(len1+3);
        		snprintf((yyval.vv).string_exp,len1+3, "%s()",(yyvsp[-2].vv).string_exp);
        		free((yyvsp[-2].vv).string_exp);

			(yyval.vv).sentry = (yyvsp[-2].vv).sentry;
			symbol_p tmp = (yyval.vv).sentry;
			tmp->type = TYPE_FUNCTION;
        }
#line 2801 "y.tab.c" /* yacc.c:1652  */
    break;

  case 95:
#line 1021 "grammar/c_syn.y" /* yacc.c:1652  */
    {
			current_type_var = -1;
        		printf("TEST941\n");
        		int len1 = strlen((yyvsp[-3].vv).string_exp);
			int len2 = strlen((yyvsp[-1].vv).string_exp);
			(yyval.vv).string_exp = malloc(len1+len2+3);
			snprintf((yyval.vv).string_exp,len1+len2+3, "%s(%s)",(yyvsp[-3].vv).string_exp,(yyvsp[-1].vv).string_exp);
			free((yyvsp[-3].vv).string_exp);
			free((yyvsp[-1].vv).string_exp);
			(yyval.vv).sentry = (yyvsp[-3].vv).sentry;
			symbol_p tmp = (yyval.vv).sentry;
			tmp->type = TYPE_FUNCTION;

        }
#line 2820 "y.tab.c" /* yacc.c:1652  */
    break;

  case 96:
#line 1035 "grammar/c_syn.y" /* yacc.c:1652  */
    {
		current_type_var = -1;
		(yyval.vv).sentry = (yyvsp[-3].vv).sentry;
		int len1 = strlen((yyvsp[-3].vv).string_exp);
		int len2 = strlen((yyvsp[-1].vv).string_exp);
		(yyval.vv).string_exp = malloc(len1+len2+3);
		snprintf((yyval.vv).string_exp,len1+len2+3, "%s(%s)",(yyvsp[-3].vv).string_exp,(yyvsp[-1].vv).string_exp);
		free((yyvsp[-3].vv).string_exp);
		free((yyvsp[-1].vv).string_exp);
		symbol_p tmp = (yyval.vv).sentry;
		tmp->type = TYPE_FUNCTION;
		//arg number
	}
#line 2838 "y.tab.c" /* yacc.c:1652  */
    break;

  case 97:
#line 1052 "grammar/c_syn.y" /* yacc.c:1652  */
    {
		(yyval.vv).string_exp = (yyvsp[0].vv).string_exp;
	}
#line 2846 "y.tab.c" /* yacc.c:1652  */
    break;

  case 98:
#line 1055 "grammar/c_syn.y" /* yacc.c:1652  */
    {
		int len1 = strlen((yyvsp[-2].vv).string_exp);
		int len2 = strlen((yyvsp[0].vv).string_exp);
		(yyval.vv).string_exp = malloc(len1+len2+2);
		snprintf((yyval.vv).string_exp,len1+len2+2, "%s,%s",(yyvsp[-2].vv).string_exp,(yyvsp[0].vv).string_exp);
		free((yyvsp[-2].vv).string_exp);
		free((yyvsp[0].vv).string_exp);
	}
#line 2859 "y.tab.c" /* yacc.c:1652  */
    break;

  case 99:
#line 1066 "grammar/c_syn.y" /* yacc.c:1652  */
    {
		int len1 = strlen((yyvsp[-1].vv).string_exp);
		int len2 = strlen((yyvsp[0].vv).string_exp);
		(yyval.vv).string_exp = malloc(len1+len2+2);
		snprintf((yyval.vv).string_exp,len1+len2+2, "%s %s",(yyvsp[-1].vv).string_exp,(yyvsp[0].vv).string_exp);
		free((yyvsp[-1].vv).string_exp);
		free((yyvsp[0].vv).string_exp);
	}
#line 2872 "y.tab.c" /* yacc.c:1652  */
    break;

  case 100:
#line 1078 "grammar/c_syn.y" /* yacc.c:1652  */
    {
		(yyval.vv).count_p = 1;

		(yyval.vv).string_exp = malloc(2);
		snprintf((yyval.vv).string_exp,2,"*");




	}
#line 2887 "y.tab.c" /* yacc.c:1652  */
    break;

  case 101:
#line 1089 "grammar/c_syn.y" /* yacc.c:1652  */
    {
	 	(yyval.vv).count_p = (yyvsp[0].vv).count_p +1;

	 	int len1 = strlen((yyvsp[0].vv).string_exp);
	 	(yyval.vv).string_exp = malloc(len1+3);
		snprintf((yyval.vv).string_exp,len1+3,"*%s",(yyvsp[0].vv).string_exp);
		free((yyvsp[0].vv).string_exp);


	}
#line 2902 "y.tab.c" /* yacc.c:1652  */
    break;

  case 102:
#line 1103 "grammar/c_syn.y" /* yacc.c:1652  */
    {
	 	(yyval.vv).string_exp = (yyvsp[0].vv).string_exp;

	 	(yyval.vv)._ast = (yyvsp[0].vv)._ast;
	 	(yyval.vv).type = 1;//simple

	}
#line 2914 "y.tab.c" /* yacc.c:1652  */
    break;

  case 103:
#line 1110 "grammar/c_syn.y" /* yacc.c:1652  */
    {
		int len1 = strlen((yyvsp[-1].vv).string_exp);
		(yyval.vv).string_exp = malloc(len1+3);
		snprintf((yyval.vv).string_exp,len1+3, "{%s}",(yyvsp[-1].vv).string_exp);
		free((yyvsp[-1].vv).string_exp);
		(yyval.vv).type = 0;//complex

		(yyval.vv)._ast = (yyvsp[-1].vv)._ast;
	}
#line 2928 "y.tab.c" /* yacc.c:1652  */
    break;

  case 104:
#line 1121 "grammar/c_syn.y" /* yacc.c:1652  */
    {
		(yyval.vv).string_exp = (yyvsp[0].vv).string_exp;
		(yyval.vv)._ast = (yyvsp[0].vv)._ast;
	}
#line 2937 "y.tab.c" /* yacc.c:1652  */
    break;

  case 105:
#line 1125 "grammar/c_syn.y" /* yacc.c:1652  */
    {

		int len1 = strlen((yyvsp[-2].vv).string_exp);
		int len2 = strlen((yyvsp[0].vv).string_exp);
		(yyval.vv).string_exp = malloc(len1+len2+2);
		snprintf((yyval.vv).string_exp,len1+len2+2, "%s,%s",(yyvsp[-2].vv).string_exp,(yyvsp[0].vv).string_exp);
		free((yyvsp[-2].vv).string_exp);
		free((yyvsp[0].vv).string_exp);

		(yyval.vv)._ast = ast_new_operation(AST_INIT_LIST,(yyvsp[-2].vv)._ast,(yyvsp[0].vv)._ast);

	}
#line 2954 "y.tab.c" /* yacc.c:1652  */
    break;

  case 106:
#line 1141 "grammar/c_syn.y" /* yacc.c:1652  */
    {
		(yyval.vv).type = IDENTIFIER;
		char * curr_var_name_tmp = (yyvsp[0].vv).string_val;
		if(current_type_var == -1){
		    symbol_p tttt;
		    int rep = lookup_symbol_entry(curr_var_name_tmp,&tttt);
		    if(rep == -1 || tttt->is_dec == 0){
			printf("error : Undeclared variable %s\tat line : %d\n",curr_var_name_tmp,line_counter+1);
			return -1;
		    }

		}

		printf("------------1138--------Variable %s \n",curr_var_name_tmp);
		int len = strlen(curr_var_name_tmp);
		(yyval.vv).string_exp = malloc(len+1);
		snprintf((yyval.vv).string_exp,len+1, "%s",curr_var_name_tmp);

		//printf("CONST_INT : %s\n",curr_var_name_tmp);
		(yyval.vv)._ast = ast_new_id(curr_var_name_tmp);


	}
#line 2982 "y.tab.c" /* yacc.c:1652  */
    break;

  case 107:
#line 1164 "grammar/c_syn.y" /* yacc.c:1652  */
    {
		(yyval.vv).type = CONST_INT;


		char * curr_var_name_tmp = (yyvsp[0].vv).string_val;
		int len = strlen(curr_var_name_tmp);
		(yyval.vv).string_exp = malloc(len+1);
		snprintf((yyval.vv).string_exp,len+1, "%s",curr_var_name_tmp);


		int a = atoi(curr_var_name_tmp);
		//printf("CONST_INT : %d\n",a);
		(yyval.vv)._ast = ast_new_number(a);

	}
#line 3002 "y.tab.c" /* yacc.c:1652  */
    break;

  case 108:
#line 1179 "grammar/c_syn.y" /* yacc.c:1652  */
    {
		if(current_type_var == INT || current_type_var == STRING){
			printf("incompatible type");
			return -1;
		}
		(yyval.vv).type = CONST_FLOAT;
		char * curr_var_name_tmp = (yyvsp[0].vv).string_val;
		int len = strlen(curr_var_name_tmp);
		(yyval.vv).string_exp = malloc(len+1);
		snprintf((yyval.vv).string_exp,len+1, "%s",curr_var_name_tmp);
		float a = strtof(curr_var_name_tmp, NULL);

		//printf("CONST_FLOAT : %f\n",a);
		(yyval.vv)._ast = ast_new_float(a);

	}
#line 3023 "y.tab.c" /* yacc.c:1652  */
    break;

  case 109:
#line 1195 "grammar/c_syn.y" /* yacc.c:1652  */
    {

		(yyval.vv).type = (yyvsp[-1].vv).type;
		char * curr_var_name_tmp = (yyvsp[-1].vv).string_exp;
		int len = strlen(curr_var_name_tmp);
		(yyval.vv).string_exp = malloc(len+3);
		snprintf((yyval.vv).string_exp,len+4, "(%s)",(yyvsp[-1].vv).string_exp);
		free((yyvsp[-1].vv).string_exp);

		(yyval.vv)._ast = (yyvsp[-1].vv)._ast;

	}
#line 3040 "y.tab.c" /* yacc.c:1652  */
    break;

  case 110:
#line 1207 "grammar/c_syn.y" /* yacc.c:1652  */
    {
		(yyval.vv).type = STRING;
		char * curr_var_name_tmp = (yyvsp[0].vv).string_val;
		int len = strlen(curr_var_name_tmp);
		(yyval.vv).string_exp = malloc(len+1);
		snprintf((yyval.vv).string_exp,len+1, "%s",curr_var_name_tmp);
		(yyval.vv)._ast = ast_new_float(-2);
	}
#line 3053 "y.tab.c" /* yacc.c:1652  */
    break;

  case 111:
#line 1220 "grammar/c_syn.y" /* yacc.c:1652  */
    {
		char * curr_var_name_tmp = (yyvsp[0].vv).string_val;
		int len = strlen(curr_var_name_tmp);
		(yyval.vv).string_exp = malloc(len);
		memcpy((yyval.vv).string_exp,curr_var_name_tmp,len);
		(yyval.vv)._ast = ast_new_id(curr_var_name_tmp);
		printf("-----1210---------------Variable %s \n",curr_var_name_tmp);


	}
#line 3068 "y.tab.c" /* yacc.c:1652  */
    break;

  case 112:
#line 1230 "grammar/c_syn.y" /* yacc.c:1652  */
    {

		char * curr_var_name_tmp = (yyvsp[0].vv).string_exp;
		int len = strlen(curr_var_name_tmp);
		int len2 = strlen((yyvsp[0].vv).string_val);
		(yyval.vv).string_exp = malloc(len+len2+1);
		snprintf((yyval.vv).string_exp,len+len2+1,"%s,%s",(yyvsp[-2].vv).string_exp,curr_var_name_tmp);
		free((yyvsp[-2].vv).string_exp);
		(yyval.vv)._ast = ast_new_operation(AST_LIST,(yyvsp[-2].vv)._ast,ast_new_id(curr_var_name_tmp)) ;
	}
#line 3083 "y.tab.c" /* yacc.c:1652  */
    break;


#line 3087 "y.tab.c" /* yacc.c:1652  */
      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
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
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;

  /* Do not reclaim the symbols of the rule whose action triggered
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
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
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

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


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


#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif


/*-----------------------------------------------------.
| yyreturn -- parsing is finished, return the result.  |
`-----------------------------------------------------*/
yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
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
  return yyresult;
}
#line 1241 "grammar/c_syn.y" /* yacc.c:1918  */


int yyerror(const char *str)
{
	printf("error : %s\tline : %d\n",str,line_counter+1);
	return -1;
}

int yywrap()
{
return 1;
}
