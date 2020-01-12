/* original parser id follows */
/* yysccsid[] = "@(#)yaccpar	1.9 (Berkeley) 02/21/93" */
/* (use YYMAJOR/YYMINOR for ifdefs dependent on parser version) */

#define YYBYACC 1
#define YYMAJOR 1
#define YYMINOR 9
#define YYPATCH 20190617

#define YYEMPTY        (-1)
#define yyclearin      (yychar = YYEMPTY)
#define yyerrok        (yyerrflag = 0)
#define YYRECOVERING() (yyerrflag != 0)
#define YYENOMEM       (-2)
#define YYEOF          0
#define YYPREFIX "yy"

#define YYPURE 0

#line 2 "grammar/c_syn.y"
	#include<stdio.h>
	#include "headers/defs.h"
	#include "headers/y.tab.h"
	#include "headers/ast.h"

	#include <stdlib.h>
	int for_depth_counter_var = 0;
	int direct_declarator_var = 0;
	int current_type_var = -1;
	int can_use_un = 0;
#ifdef YYSTYPE
#undef  YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
#endif
#ifndef YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
#line 13 "grammar/c_syn.y"
typedef union{
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

} YYSTYPE;
#endif /* !YYSTYPE_IS_DECLARED */
#line 58 "y.tab.c"

/* compatibility with bison */
#ifdef YYPARSE_PARAM
/* compatibility with FreeBSD */
# ifdef YYPARSE_PARAM_TYPE
#  define YYPARSE_DECL() yyparse(YYPARSE_PARAM_TYPE YYPARSE_PARAM)
# else
#  define YYPARSE_DECL() yyparse(void *YYPARSE_PARAM)
# endif
#else
# define YYPARSE_DECL() yyparse(void)
#endif

/* Parameters sent to lex. */
#ifdef YYLEX_PARAM
# define YYLEX_DECL() yylex(void *YYLEX_PARAM)
# define YYLEX yylex(YYLEX_PARAM)
#else
# define YYLEX_DECL() yylex(void)
# define YYLEX yylex()
#endif

#if !(defined(yylex) || defined(YYSTATE))
int YYLEX_DECL();
#endif

/* Parameters sent to yyerror. */
#ifndef YYERROR_DECL
#define YYERROR_DECL() yyerror(const char *s)
#endif
#ifndef YYERROR_CALL
#define YYERROR_CALL(msg) yyerror(msg)
#endif

extern int YYPARSE_DECL();

#define INT 257
#define VOID 258
#define FLOAT 259
#define FOR 260
#define WHILE 261
#define DO 262
#define IF 263
#define ELSE 264
#define RETURN 265
#define BREAK 266
#define GOTO 267
#define HASH 268
#define INCLUDE 269
#define CONST_Q 270
#define CONST_INT 271
#define CONST_FLOAT 272
#define IDENTIFIER 273
#define STRING 274
#define CONST 275
#define PRINTF 276
#define AND_OP 277
#define OR_OP 278
#define LE_OP 279
#define GE_OP 280
#define EQ_OP 281
#define NE_OP 282
#define INC 283
#define DEC 284
#define LEFT_OP 285
#define RIGHT_OP 286
#define YYERRCODE 256
typedef short YYINT;
static const YYINT yylhs[] = {                           -1,
    0,    0,   30,   30,   29,   35,   35,   33,   33,   34,
   34,   34,   34,   20,   20,   20,   20,    5,    5,    5,
    5,    6,    6,   18,   18,   18,   18,   18,   36,   36,
   36,    9,    9,   21,   21,   43,    4,    4,   19,   19,
   19,   19,   19,   27,   27,   27,   22,   22,   22,   22,
   23,   23,   23,   24,   24,   24,   25,   25,   25,   25,
   25,   26,   26,   26,   37,   37,   38,   38,   39,   39,
   41,   41,   40,   40,   28,   28,   42,    7,    7,   14,
    2,    1,    1,    1,   15,   15,   13,   13,   12,   12,
   11,   11,   11,   11,   11,   32,   32,   31,   10,   10,
   16,   16,   17,   17,    3,    3,    3,    3,    3,    8,
    8,
};
static const YYINT yylen[] = {                            2,
    1,    2,    2,    1,    3,    1,    2,    1,    1,    4,
    3,    3,    2,    3,    2,    2,    3,    2,    3,    3,
    4,    1,    2,    1,    1,    1,    1,    1,    1,    2,
    1,    5,    7,    5,    8,    0,    1,    3,    1,    4,
    3,    2,    2,    1,    2,    2,    1,    3,    3,    3,
    1,    3,    3,    1,    3,    3,    1,    3,    3,    3,
    3,    1,    3,    3,    1,    3,    1,    3,    1,    3,
    1,    3,    1,    3,    1,    3,    1,    1,    2,    3,
    1,    1,    1,    1,    1,    3,    1,    3,    2,    1,
    1,    4,    3,    4,    4,    1,    3,    2,    1,    2,
    1,    3,    1,    3,    1,    1,    1,    3,    1,    1,
    3,
};
static const YYINT yydefred[] = {                         0,
   83,   82,   84,    0,   91,    0,    0,   81,    0,    0,
    0,    0,    9,    4,    0,    6,    8,    0,    0,  100,
    0,   85,    0,    0,    0,    0,    0,    0,   13,    0,
   78,    3,    0,    7,    5,    0,   11,    0,   80,    0,
  110,   93,    0,    0,   96,    0,    0,    0,    0,    0,
    0,    0,  106,  107,  105,  109,   31,    0,   29,   18,
    0,    0,   39,    0,   24,    0,    0,   26,   22,    0,
   28,   27,    0,    0,    0,    0,    0,    0,   37,   25,
    0,    0,    0,    0,    0,    0,    0,   12,   79,    0,
   88,  101,   10,   86,   98,   94,    0,   95,    0,   92,
    0,    0,   16,    0,   15,    0,    0,   45,   46,   30,
    0,   19,   23,   20,    0,    0,    0,   42,   43,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,   77,    0,    0,    0,    0,    0,    0,    0,
  103,    0,  111,   97,    0,    0,   17,   14,  108,   38,
   21,   41,    0,   49,   48,   50,    0,   47,    0,    0,
    0,    0,    0,    0,    0,    0,    0,   76,    0,    0,
    0,    0,    0,    0,  102,    0,    0,    0,   40,    0,
  104,   34,    0,    0,    0,    0,   33,    0,   35,
};
static const YYINT yydgoto[] = {                          7,
    8,   28,   63,   64,   65,   66,   30,   44,   68,   10,
   11,   12,   22,   13,   23,   91,  142,   69,   70,   71,
   72,   73,   74,   75,   76,   77,   78,   79,   14,   15,
   45,   46,   16,   17,   18,   80,   81,   82,   83,   84,
   85,  134,   86,
};
static const YYINT yysindex[] = {                       371,
    0,    0,    0, -260,    0,  -13,    0,    0,  -15, -234,
   -8,  -49,    0,    0,  371,    0,    0,  280, -233,    0,
  -59,    0,   -9,   -8,  -38, -196,   67,  -15,    0,  -49,
    0,    0,  280,    0,    0,   73,    0,  -49,    0,  -15,
    0,    0,  -15,    8,    0,  114,   21,   45,   49,  144,
   62, -155,    0,    0,    0,    0,    0,  226,    0,    0,
  226,  226,    0,   47,    0,  283,  138,    0,    0,  -14,
    0,    0,   90,  193, -176,  110, -120,   70,    0,    0,
  107,   75,   14,  -99,  -90,  -71,  146,    0,    0,   73,
    0,    0,    0,    0,    0,    0,  -55,    0,  -64,    0,
  226,  226,    0,  105,    0,  173,  132,    0,    0,    0,
  226,    0,    0,    0,  309,  196,  226,    0,    0,  226,
  226,  226,  226,  226,  226,  226,  226,  226,  226,  226,
  226,  226,    0,  226,  226,  226,  226,  226,  226,  210,
    0,  -24,    0,    0,  136,  160,    0,    0,    0,    0,
    0,    0,    3,    0,    0,    0,   90,    0,   90,  193,
  193, -176, -176, -176, -176,  110,  110,    0, -120,  107,
   75,  -90,   14,  108,    0,   73,  134,  134,    0,  108,
    0,    0,   -2,  226,  134,  183,    0,  134,    0,
};
static const YYINT yyrindex[] = {                         0,
    0,    0,    0,    0,    0,   -6,    0,    0,    0,    0,
  668,    0,    0,    0,    0,    0,    0,  264,    0,    0,
  112,    0,    0,  672,    0,    0,   11,    0,    0,    0,
    0,    0,  268,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,   11,   11,    0,    0,  -37,
    0,    0,   -1,   22,  382,  409,  572,  -26,    0,    0,
  599,   98,  582,  676,  122,    0,  112,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,   11,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,   10,    0,   35,   81,
   92,  392,  399,  470,  527,  484,  560,    0,  574,  660,
  109,  667,  662,    0,    0,    0,    0,    0,    0,    0,
    0,    0,  206,    0,    0,    0,    0,    0,    0,
};
static const YYINT yygindex[] = {                         0,
    0,   13,    0,  181,  756,  205,   44,    0,    0,  267,
  265,   77,  234,  827,    0,  -76,    0,   -4,    0,    0,
    0,   59,  100,   84,   97,  151,  695,   54,  278,    0,
  195,    0,   12,    0,  282,  -72,  169,  172,  167,    0,
  180,    0,    0,
};
#define YYTABLESIZE 945
static const YYINT yytable[] = {                         44,
   44,   36,   42,   44,   44,   44,   44,   44,   19,   44,
   47,   47,    9,  141,   47,   47,   47,   47,   47,  176,
   47,   44,   44,   44,   44,  116,    6,    9,    6,   34,
    9,   25,   47,   47,   40,   47,   51,   43,    5,   51,
   35,   51,   51,   51,   34,    9,  111,   52,   96,   39,
   52,   97,   52,   52,   52,   44,   44,   51,   51,   54,
   51,  113,   54,   27,   38,   54,   47,   47,   52,   52,
   67,   52,   53,   27,   47,   53,  117,   53,   53,   53,
   54,   54,   26,   54,  101,   21,   44,   44,  102,   92,
  111,   51,   51,   53,   53,  179,   53,   47,   47,  181,
  175,  180,   52,   52,   87,  110,   58,  184,  125,  126,
  113,   43,   58,  100,   54,   54,   87,  106,   55,   95,
  105,   55,   51,   51,   55,   59,  122,   53,   53,   56,
  133,  121,   56,   52,   52,   56,  120,  137,   69,   55,
   55,   69,   55,   92,  135,   54,   54,   58,  111,   70,
   56,   56,   70,   56,   98,   87,   69,   99,   53,   53,
  131,  132,   73,  147,  150,   73,   59,   70,  136,  127,
   87,  128,  149,   55,   55,  111,  177,   58,  138,  111,
   73,  157,  159,   58,   56,   56,  139,  168,  140,   27,
   69,   60,    1,    2,    3,   90,   59,    1,    2,    3,
  178,   70,  103,  111,   55,   55,   36,    1,    2,    3,
  162,  163,  164,  165,   73,   56,   56,  143,    1,    2,
    3,   69,   69,  188,  160,  161,  111,  166,  167,   92,
  104,  148,   70,   70,   41,  123,  152,  124,  107,   44,
   44,   44,   44,   44,   44,   32,   73,   44,   44,  174,
   47,   47,   47,   47,   47,   47,   27,    5,   47,   47,
   27,  185,  114,    1,   32,   58,   99,    2,  118,  119,
   36,  115,   20,   94,   24,   51,   51,   51,   51,   51,
   51,  145,  146,   51,   51,  169,   52,   52,   52,   52,
   52,   52,   32,  144,   52,   52,   33,  153,   54,   54,
   54,   54,   54,   54,  170,  173,   54,   54,  171,    0,
    0,   53,   53,   53,   53,   53,   53,  172,    0,   53,
   53,    6,   58,    1,    2,    3,    0,   48,   32,   49,
   32,   50,   51,   52,    0,    0,    0,   53,   54,   55,
   56,   59,   57,   53,   54,   55,   56,    0,   58,   61,
   62,    0,    0,    0,    0,   61,   62,   55,   55,   55,
   55,   55,   55,    0,  186,   55,   55,   59,   56,   56,
   56,   56,   56,   56,   69,   69,   56,   56,   53,   54,
   55,   56,    0,   57,    0,   70,   70,    0,  129,  130,
   61,   62,    0,    0,    1,    2,    3,    0,   48,   73,
   49,    0,   50,   51,   52,   27,    0,  112,   53,   54,
   55,   56,    6,   57,   53,   54,   55,   56,    0,   57,
   61,   62,   57,    0,    0,   57,   61,   62,    0,   58,
    0,   27,   58,  151,    0,   58,   59,    0,    0,   59,
   57,   57,   59,   57,    0,    0,   62,    0,    0,   62,
   58,   58,   62,   58,    0,    0,    0,   59,   59,    0,
   59,    0,    0,    0,    0,   32,   32,   62,   32,    0,
   32,   32,   32,    0,   57,   57,   32,   32,   32,   32,
    0,   32,    0,    0,   58,   58,    0,    0,   32,   32,
    0,   59,   59,    0,    0,    0,   53,   54,   55,   56,
    0,   62,   62,    0,    0,   57,   57,   60,   61,   62,
   60,    0,    0,   60,    0,   58,   58,    0,    0,    0,
    0,   63,   59,   59,   63,    0,    0,   63,   60,   60,
    0,   60,   62,   62,    0,    0,    1,    2,    3,    0,
    0,    0,   63,   48,    0,   49,    0,   50,   51,   52,
    0,    0,    5,   53,   54,   55,   56,    0,   57,    0,
    0,    0,   60,   60,   61,   61,   62,   61,    0,   48,
   61,   49,    0,   50,   51,   52,   63,   63,    0,   53,
   54,   55,   56,    0,   57,   61,   61,    0,   61,    0,
    0,   61,   62,   60,   60,    0,    0,   64,    0,    0,
   64,    0,    0,   64,    0,    0,    0,   63,   63,   65,
    0,   66,   65,    0,   66,   65,    0,   66,   64,   61,
   61,    0,   71,    0,    0,   71,    0,    1,    2,    3,
   65,    0,   66,    0,    0,    0,    0,    0,    4,   67,
   71,    0,   67,    5,    0,    0,    0,    0,    0,    0,
   61,   61,   64,   64,    0,    0,    0,   67,   57,   57,
   57,   57,   57,   57,   65,   65,   66,   66,   58,   58,
   58,   58,   58,   58,   71,   59,   59,   59,   59,   59,
   59,    0,    0,   64,   64,   62,   62,    0,    0,   62,
   62,   67,   67,    0,    0,   65,   65,   66,   66,    0,
   68,    0,   72,   68,    0,   72,   71,   74,   90,    0,
   74,   90,   89,    0,    0,   89,   75,    0,   68,   75,
   72,    0,   67,   67,    0,   74,   90,    0,   90,    0,
   89,    0,   89,    0,   75,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,   60,   60,   60,   60,
   60,   60,   68,   68,   72,  108,  109,    0,    0,   74,
   63,   63,    0,    0,   63,   63,    0,   29,   75,    0,
    0,    0,    0,    0,    0,    0,   37,    0,    0,    0,
    0,    0,    0,   68,   68,   88,   72,    0,    0,    0,
   90,   74,    0,   93,   89,    0,    0,    0,    0,    0,
   75,    0,    0,   61,   61,   61,   61,   61,   61,    0,
    0,    0,    0,    0,  154,  155,  156,  158,  158,  158,
  158,  158,  158,  158,  158,  158,  158,    0,    0,  158,
  158,  158,  158,  158,    0,    0,   64,   64,   31,    0,
   64,   64,    0,    0,    0,    0,    0,   31,   65,   65,
   66,   66,    0,   31,    0,    0,   89,    0,   71,   71,
    0,    0,    0,    0,   89,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,   67,   67,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,   89,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,   90,   90,   90,    0,   89,   89,
   89,    0,  182,  183,    0,    0,   68,   68,   72,   72,
  187,    0,    0,  189,   74,
};
static const YYINT yycheck[] = {                         37,
   38,   61,   41,   41,   42,   43,   44,   45,  269,   47,
   37,   38,    0,   90,   41,   42,   43,   44,   45,   44,
   47,   59,   60,   61,   62,   40,   42,   15,   42,   18,
   18,   40,   59,   60,   44,   62,   38,   25,  273,   41,
  274,   43,   44,   45,   33,   33,   44,   38,   41,   59,
   41,   44,   43,   44,   45,   93,   94,   59,   60,   38,
   62,   66,   41,  123,   21,   44,   93,   94,   59,   60,
   27,   62,   38,  123,  271,   41,   91,   43,   44,   45,
   59,   60,   91,   62,   40,    9,  124,  125,   40,   36,
   44,   93,   94,   59,   60,   93,   62,  124,  125,  176,
  125,  174,   93,   94,   28,   59,   40,  180,  285,  286,
  115,   99,   40,   93,   93,   94,   40,  273,   38,   43,
   59,   41,  124,  125,   44,   59,   37,   93,   94,   38,
   61,   42,   41,  124,  125,   44,   47,  124,   41,   59,
   60,   44,   62,   90,   38,  124,  125,   40,   44,   41,
   59,   60,   44,   62,   41,   44,   59,   44,  124,  125,
  281,  282,   41,   59,  111,   44,   59,   59,   94,   60,
   59,   62,   41,   93,   94,   44,   41,   40,  278,   44,
   59,  123,  124,   40,   93,   94,  277,  134,  260,  123,
   93,  125,  257,  258,  259,  123,   59,  257,  258,  259,
   41,   93,   59,   44,  124,  125,   61,  257,  258,  259,
  127,  128,  129,  130,   93,  124,  125,  273,  257,  258,
  259,  124,  125,   41,  125,  126,   44,  131,  132,  176,
   50,   59,  124,  125,  273,   43,   41,   45,   58,  277,
  278,  279,  280,  281,  282,   40,  125,  285,  286,   40,
  277,  278,  279,  280,  281,  282,  123,  273,  285,  286,
  123,  264,  125,    0,   59,   40,  273,    0,  283,  284,
  260,   67,    6,   40,   10,  277,  278,  279,  280,  281,
  282,  101,  102,  285,  286,  135,  277,  278,  279,  280,
  281,  282,   15,   99,  285,  286,   15,  117,  277,  278,
  279,  280,  281,  282,  136,  139,  285,  286,  137,   -1,
   -1,  277,  278,  279,  280,  281,  282,  138,   -1,  285,
  286,   42,   40,  257,  258,  259,   -1,  261,  123,  263,
  125,  265,  266,  267,   -1,   -1,   -1,  271,  272,  273,
  274,   59,  276,  271,  272,  273,  274,   -1,   40,  283,
  284,   -1,   -1,   -1,   -1,  283,  284,  277,  278,  279,
  280,  281,  282,   -1,  184,  285,  286,   59,  277,  278,
  279,  280,  281,  282,  277,  278,  285,  286,  271,  272,
  273,  274,   -1,  276,   -1,  277,  278,   -1,  279,  280,
  283,  284,   -1,   -1,  257,  258,  259,   -1,  261,  278,
  263,   -1,  265,  266,  267,  123,   -1,  125,  271,  272,
  273,  274,   42,  276,  271,  272,  273,  274,   -1,   38,
  283,  284,   41,   -1,   -1,   44,  283,  284,   -1,   38,
   -1,  123,   41,  125,   -1,   44,   38,   -1,   -1,   41,
   59,   60,   44,   62,   -1,   -1,   38,   -1,   -1,   41,
   59,   60,   44,   62,   -1,   -1,   -1,   59,   60,   -1,
   62,   -1,   -1,   -1,   -1,  260,  261,   59,  263,   -1,
  265,  266,  267,   -1,   93,   94,  271,  272,  273,  274,
   -1,  276,   -1,   -1,   93,   94,   -1,   -1,  283,  284,
   -1,   93,   94,   -1,   -1,   -1,  271,  272,  273,  274,
   -1,   93,   94,   -1,   -1,  124,  125,   38,  283,  284,
   41,   -1,   -1,   44,   -1,  124,  125,   -1,   -1,   -1,
   -1,   38,  124,  125,   41,   -1,   -1,   44,   59,   60,
   -1,   62,  124,  125,   -1,   -1,  257,  258,  259,   -1,
   -1,   -1,   59,  261,   -1,  263,   -1,  265,  266,  267,
   -1,   -1,  273,  271,  272,  273,  274,   -1,  276,   -1,
   -1,   -1,   93,   94,   38,  283,  284,   41,   -1,  261,
   44,  263,   -1,  265,  266,  267,   93,   94,   -1,  271,
  272,  273,  274,   -1,  276,   59,   60,   -1,   62,   -1,
   -1,  283,  284,  124,  125,   -1,   -1,   38,   -1,   -1,
   41,   -1,   -1,   44,   -1,   -1,   -1,  124,  125,   38,
   -1,   38,   41,   -1,   41,   44,   -1,   44,   59,   93,
   94,   -1,   41,   -1,   -1,   44,   -1,  257,  258,  259,
   59,   -1,   59,   -1,   -1,   -1,   -1,   -1,  268,   41,
   59,   -1,   44,  273,   -1,   -1,   -1,   -1,   -1,   -1,
  124,  125,   93,   94,   -1,   -1,   -1,   59,  277,  278,
  279,  280,  281,  282,   93,   94,   93,   94,  277,  278,
  279,  280,  281,  282,   93,  277,  278,  279,  280,  281,
  282,   -1,   -1,  124,  125,  277,  278,   -1,   -1,  281,
  282,   93,   94,   -1,   -1,  124,  125,  124,  125,   -1,
   41,   -1,   41,   44,   -1,   44,  125,   41,   41,   -1,
   44,   44,   41,   -1,   -1,   44,   41,   -1,   59,   44,
   59,   -1,  124,  125,   -1,   59,   59,   -1,   61,   -1,
   59,   -1,   61,   -1,   59,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,  277,  278,  279,  280,
  281,  282,   93,   94,   93,   61,   62,   -1,   -1,   93,
  277,  278,   -1,   -1,  281,  282,   -1,   12,   93,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   21,   -1,   -1,   -1,
   -1,   -1,   -1,  124,  125,   30,  125,   -1,   -1,   -1,
  123,  125,   -1,   38,  123,   -1,   -1,   -1,   -1,   -1,
  125,   -1,   -1,  277,  278,  279,  280,  281,  282,   -1,
   -1,   -1,   -1,   -1,  120,  121,  122,  123,  124,  125,
  126,  127,  128,  129,  130,  131,  132,   -1,   -1,  135,
  136,  137,  138,  139,   -1,   -1,  277,  278,   12,   -1,
  281,  282,   -1,   -1,   -1,   -1,   -1,   21,  277,  278,
  277,  278,   -1,   27,   -1,   -1,   30,   -1,  277,  278,
   -1,   -1,   -1,   -1,   38,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,  277,  278,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   67,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,  257,  258,  259,   -1,  257,  258,
  259,   -1,  177,  178,   -1,   -1,  277,  278,  277,  278,
  185,   -1,   -1,  188,  278,
};
#define YYFINAL 7
#ifndef YYDEBUG
#define YYDEBUG 0
#endif
#define YYMAXTOKEN 286
#define YYUNDFTOKEN 332
#define YYTRANSLATE(a) ((a) > YYMAXTOKEN ? YYUNDFTOKEN : (a))
#if YYDEBUG
static const char *const yyname[] = {

"end-of-file",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,"'%'","'&'",0,"'('","')'","'*'","'+'","','","'-'",0,"'/'",0,0,0,0,0,0,0,0,
0,0,0,"';'","'<'","'='","'>'",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,"'['",0,"']'","'^'",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,"'{'","'|'","'}'",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"INT","VOID","FLOAT","FOR","WHILE",
"DO","IF","ELSE","RETURN","BREAK","GOTO","HASH","INCLUDE","CONST_Q","CONST_INT",
"CONST_FLOAT","IDENTIFIER","STRING","CONST","PRINTF","AND_OP","OR_OP","LE_OP",
"GE_OP","EQ_OP","NE_OP","INC","DEC","LEFT_OP","RIGHT_OP",0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
"illegal-symbol",
};
static const char *const yyrule[] = {
"$accept : start",
"start : translation_unit",
"start : include_list translation_unit",
"include_list : include_list include_elm",
"include_list : include_elm",
"include_elm : HASH INCLUDE STRING",
"translation_unit : external_declaration",
"translation_unit : translation_unit external_declaration",
"external_declaration : function_definition",
"external_declaration : declaration",
"function_definition : declaration_specifiers declarator declaration_list compound_statement",
"function_definition : declaration_specifiers declarator compound_statement",
"function_definition : declarator declaration_list compound_statement",
"function_definition : declarator compound_statement",
"jump_statement : GOTO IDENTIFIER ';'",
"jump_statement : BREAK ';'",
"jump_statement : RETURN ';'",
"jump_statement : RETURN expression ';'",
"compound_statement : '{' '}'",
"compound_statement : '{' statement_list '}'",
"compound_statement : '{' declaration_list '}'",
"compound_statement : '{' declaration_list statement_list '}'",
"statement_list : statement",
"statement_list : statement_list statement",
"statement : compound_statement",
"statement : expression_statement",
"statement : selection_statement",
"statement : iteration_statement",
"statement : jump_statement",
"expression_statement : ';'",
"expression_statement : expression ';'",
"expression_statement : PRINTF",
"selection_statement : IF '(' expression ')' compound_statement",
"selection_statement : IF '(' expression ')' compound_statement ELSE compound_statement",
"iteration_statement : WHILE '(' expression ')' compound_statement",
"iteration_statement : iter_counter FOR '(' expression_statement expression_statement expression ')' compound_statement",
"iter_counter :",
"expression : assignment_expression",
"expression : expression ',' assignment_expression",
"postfix_expression : primary_expression",
"postfix_expression : postfix_expression '[' expression ']'",
"postfix_expression : postfix_expression '(' ')'",
"postfix_expression : postfix_expression INC",
"postfix_expression : postfix_expression DEC",
"unary_expression : postfix_expression",
"unary_expression : INC unary_expression",
"unary_expression : DEC unary_expression",
"multiplicative_expression : unary_expression",
"multiplicative_expression : multiplicative_expression '*' unary_expression",
"multiplicative_expression : multiplicative_expression '/' unary_expression",
"multiplicative_expression : multiplicative_expression '%' unary_expression",
"additive_expression : multiplicative_expression",
"additive_expression : additive_expression '+' multiplicative_expression",
"additive_expression : additive_expression '-' multiplicative_expression",
"shift_expression : additive_expression",
"shift_expression : shift_expression LEFT_OP additive_expression",
"shift_expression : shift_expression RIGHT_OP additive_expression",
"relational_expression : shift_expression",
"relational_expression : relational_expression '<' shift_expression",
"relational_expression : relational_expression '>' shift_expression",
"relational_expression : relational_expression LE_OP shift_expression",
"relational_expression : relational_expression GE_OP shift_expression",
"equality_expression : relational_expression",
"equality_expression : equality_expression EQ_OP relational_expression",
"equality_expression : equality_expression NE_OP relational_expression",
"and_expression : equality_expression",
"and_expression : and_expression '&' equality_expression",
"exclusive_or_expression : and_expression",
"exclusive_or_expression : exclusive_or_expression '^' and_expression",
"inclusive_or_expression : exclusive_or_expression",
"inclusive_or_expression : inclusive_or_expression '|' exclusive_or_expression",
"logical_and_expression : inclusive_or_expression",
"logical_and_expression : logical_and_expression AND_OP inclusive_or_expression",
"logical_or_expression : logical_and_expression",
"logical_or_expression : logical_or_expression OR_OP logical_and_expression",
"assignment_expression : logical_or_expression",
"assignment_expression : unary_expression assignment_operator assignment_expression",
"assignment_operator : '='",
"declaration_list : declaration",
"declaration_list : declaration_list declaration",
"declaration : declaration_specifiers init_declarator_list ';'",
"declaration_specifiers : type_specifier",
"type_specifier : VOID",
"type_specifier : INT",
"type_specifier : FLOAT",
"init_declarator_list : init_declarator",
"init_declarator_list : init_declarator_list ',' init_declarator",
"init_declarator : declarator",
"init_declarator : declarator '=' initializer",
"declarator : pointer direct_declarator",
"declarator : direct_declarator",
"direct_declarator : IDENTIFIER",
"direct_declarator : direct_declarator '[' CONST_INT ']'",
"direct_declarator : direct_declarator '(' ')'",
"direct_declarator : direct_declarator '(' identifier_list ')'",
"direct_declarator : direct_declarator '(' parameter_list ')'",
"parameter_list : parameter_declaration",
"parameter_list : parameter_list ',' parameter_declaration",
"parameter_declaration : declaration_specifiers declarator",
"pointer : '*'",
"pointer : '*' pointer",
"initializer : assignment_expression",
"initializer : '{' initializer_list '}'",
"initializer_list : initializer",
"initializer_list : initializer_list ',' initializer",
"primary_expression : IDENTIFIER",
"primary_expression : CONST_INT",
"primary_expression : CONST_FLOAT",
"primary_expression : '(' expression ')'",
"primary_expression : STRING",
"identifier_list : IDENTIFIER",
"identifier_list : identifier_list ',' IDENTIFIER",

};
#endif

#if YYDEBUG
int      yydebug;
#endif

int      yyerrflag;
int      yychar;
YYSTYPE  yyval;
YYSTYPE  yylval;
int      yynerrs;

/* define the initial stack-sizes */
#ifdef YYSTACKSIZE
#undef YYMAXDEPTH
#define YYMAXDEPTH  YYSTACKSIZE
#else
#ifdef YYMAXDEPTH
#define YYSTACKSIZE YYMAXDEPTH
#else
#define YYSTACKSIZE 10000
#define YYMAXDEPTH  10000
#endif
#endif

#define YYINITSTACKSIZE 200

typedef struct {
    unsigned stacksize;
    YYINT    *s_base;
    YYINT    *s_mark;
    YYINT    *s_last;
    YYSTYPE  *l_base;
    YYSTYPE  *l_mark;
} YYSTACKDATA;
/* variables for the parser stack */
static YYSTACKDATA yystack;
#line 1241 "grammar/c_syn.y"

int yyerror(const char *str)
{
	printf("error : %s\tline : %d\n",str,line_counter+1);
	return -1;
}

int yywrap()
{
return 1;
}
#line 615 "y.tab.c"

#if YYDEBUG
#include <stdio.h>	/* needed for printf */
#endif

#include <stdlib.h>	/* needed for malloc, etc */
#include <string.h>	/* needed for memset */

/* allocate initial stack or double stack size, up to YYMAXDEPTH */
static int yygrowstack(YYSTACKDATA *data)
{
    int i;
    unsigned newsize;
    YYINT *newss;
    YYSTYPE *newvs;

    if ((newsize = data->stacksize) == 0)
        newsize = YYINITSTACKSIZE;
    else if (newsize >= YYMAXDEPTH)
        return YYENOMEM;
    else if ((newsize *= 2) > YYMAXDEPTH)
        newsize = YYMAXDEPTH;

    i = (int) (data->s_mark - data->s_base);
    newss = (YYINT *)realloc(data->s_base, newsize * sizeof(*newss));
    if (newss == 0)
        return YYENOMEM;

    data->s_base = newss;
    data->s_mark = newss + i;

    newvs = (YYSTYPE *)realloc(data->l_base, newsize * sizeof(*newvs));
    if (newvs == 0)
        return YYENOMEM;

    data->l_base = newvs;
    data->l_mark = newvs + i;

    data->stacksize = newsize;
    data->s_last = data->s_base + newsize - 1;
    return 0;
}

#if YYPURE || defined(YY_NO_LEAKS)
static void yyfreestack(YYSTACKDATA *data)
{
    free(data->s_base);
    free(data->l_base);
    memset(data, 0, sizeof(*data));
}
#else
#define yyfreestack(data) /* nothing */
#endif

#define YYABORT  goto yyabort
#define YYREJECT goto yyabort
#define YYACCEPT goto yyaccept
#define YYERROR  goto yyerrlab

int
YYPARSE_DECL()
{
    int yym, yyn, yystate;
#if YYDEBUG
    const char *yys;

    if ((yys = getenv("YYDEBUG")) != 0)
    {
        yyn = *yys;
        if (yyn >= '0' && yyn <= '9')
            yydebug = yyn - '0';
    }
#endif

    yym = 0;
    yyn = 0;
    yynerrs = 0;
    yyerrflag = 0;
    yychar = YYEMPTY;
    yystate = 0;

#if YYPURE
    memset(&yystack, 0, sizeof(yystack));
#endif

    if (yystack.s_base == NULL && yygrowstack(&yystack) == YYENOMEM) goto yyoverflow;
    yystack.s_mark = yystack.s_base;
    yystack.l_mark = yystack.l_base;
    yystate = 0;
    *yystack.s_mark = 0;

yyloop:
    if ((yyn = yydefred[yystate]) != 0) goto yyreduce;
    if (yychar < 0)
    {
        yychar = YYLEX;
        if (yychar < 0) yychar = YYEOF;
#if YYDEBUG
        if (yydebug)
        {
            if ((yys = yyname[YYTRANSLATE(yychar)]) == NULL) yys = yyname[YYUNDFTOKEN];
            printf("%sdebug: state %d, reading %d (%s)\n",
                    YYPREFIX, yystate, yychar, yys);
        }
#endif
    }
    if (((yyn = yysindex[yystate]) != 0) && (yyn += yychar) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == (YYINT) yychar)
    {
#if YYDEBUG
        if (yydebug)
            printf("%sdebug: state %d, shifting to state %d\n",
                    YYPREFIX, yystate, yytable[yyn]);
#endif
        if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack) == YYENOMEM) goto yyoverflow;
        yystate = yytable[yyn];
        *++yystack.s_mark = yytable[yyn];
        *++yystack.l_mark = yylval;
        yychar = YYEMPTY;
        if (yyerrflag > 0)  --yyerrflag;
        goto yyloop;
    }
    if (((yyn = yyrindex[yystate]) != 0) && (yyn += yychar) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == (YYINT) yychar)
    {
        yyn = yytable[yyn];
        goto yyreduce;
    }
    if (yyerrflag != 0) goto yyinrecovery;

    YYERROR_CALL("syntax error");

    goto yyerrlab; /* redundant goto avoids 'unused label' warning */
yyerrlab:
    ++yynerrs;

yyinrecovery:
    if (yyerrflag < 3)
    {
        yyerrflag = 3;
        for (;;)
        {
            if (((yyn = yysindex[*yystack.s_mark]) != 0) && (yyn += YYERRCODE) >= 0 &&
                    yyn <= YYTABLESIZE && yycheck[yyn] == (YYINT) YYERRCODE)
            {
#if YYDEBUG
                if (yydebug)
                    printf("%sdebug: state %d, error recovery shifting\
 to state %d\n", YYPREFIX, *yystack.s_mark, yytable[yyn]);
#endif
                if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack) == YYENOMEM) goto yyoverflow;
                yystate = yytable[yyn];
                *++yystack.s_mark = yytable[yyn];
                *++yystack.l_mark = yylval;
                goto yyloop;
            }
            else
            {
#if YYDEBUG
                if (yydebug)
                    printf("%sdebug: error recovery discarding state %d\n",
                            YYPREFIX, *yystack.s_mark);
#endif
                if (yystack.s_mark <= yystack.s_base) goto yyabort;
                --yystack.s_mark;
                --yystack.l_mark;
            }
        }
    }
    else
    {
        if (yychar == YYEOF) goto yyabort;
#if YYDEBUG
        if (yydebug)
        {
            if ((yys = yyname[YYTRANSLATE(yychar)]) == NULL) yys = yyname[YYUNDFTOKEN];
            printf("%sdebug: state %d, error recovery discards token %d (%s)\n",
                    YYPREFIX, yystate, yychar, yys);
        }
#endif
        yychar = YYEMPTY;
        goto yyloop;
    }

yyreduce:
#if YYDEBUG
    if (yydebug)
        printf("%sdebug: state %d, reducing by rule %d (%s)\n",
                YYPREFIX, yystate, yyn, yyrule[yyn]);
#endif
    yym = yylen[yyn];
    if (yym > 0)
        yyval = yystack.l_mark[1-yym];
    else
        memset(&yyval, 0, sizeof yyval);

    switch (yyn)
    {
case 1:
#line 46 "grammar/c_syn.y"
	{
		printf("-->\n%s\n",yystack.l_mark[0].vv.string_exp);
		    char * inc = "#include <cblas.h>"
                                 "#include <primitives.h>";
		FILE* d = fopen(file_out, "a");
		char* tot = malloc(strlen(yystack.l_mark[0].vv.string_exp)+100);
		memset(tot,0,strlen(yystack.l_mark[0].vv.string_exp)+100);
		snprintf(tot,strlen(yystack.l_mark[0].vv.string_exp)+100,"%s\n%s",inc,yystack.l_mark[0].vv.string_exp);
		printf("%s\n",tot);
		fprintf(d,"%s",tot);
		free(yystack.l_mark[0].vv.string_exp);
		free(tot);
}
break;
case 2:
#line 59 "grammar/c_syn.y"
	{
     		int len1 = strlen(yystack.l_mark[-1].vv.string_exp);
     		int len2 = strlen(yystack.l_mark[0].vv.string_exp);
    		char* res = malloc(len1+len2+100);
	    	char * inc = "#include \"cblas.h\"\n"
			 "#include \"primitives.h\"";
		snprintf(res,len1+len2+100, "%s\n%s\n%s",inc,yystack.l_mark[-1].vv.string_exp,yystack.l_mark[0].vv.string_exp);

		printf("-->\n%s\n",res);
		FILE* d = fopen(file_out, "w");
		fprintf(d,"%s",res);
		free(yystack.l_mark[-1].vv.string_exp);
		free(yystack.l_mark[0].vv.string_exp);
     }
break;
case 3:
#line 74 "grammar/c_syn.y"
	{
            	int len1 = strlen(yystack.l_mark[-1].vv.string_exp);
		int len2 = strlen(yystack.l_mark[0].vv.string_exp);
		yyval.vv.string_exp = malloc(len1+len2+2);
		snprintf(yyval.vv.string_exp,len1+len2+2, "%s\n%s",yystack.l_mark[-1].vv.string_exp,yystack.l_mark[0].vv.string_exp);
            	free(yystack.l_mark[-1].vv.string_exp);
            	free(yystack.l_mark[0].vv.string_exp);
            }
break;
case 4:
#line 82 "grammar/c_syn.y"
	{
	    	yyval.vv.string_exp = yystack.l_mark[0].vv.string_exp;
	    }
break;
case 5:
#line 86 "grammar/c_syn.y"
	{
	int len = strlen(yystack.l_mark[0].vv.string_val)+10;
	yyval.vv.string_exp = malloc(len);
	snprintf(yyval.vv.string_exp,len,"#include %s",yystack.l_mark[0].vv.string_val);
}
break;
case 6:
#line 94 "grammar/c_syn.y"
	{
		yyval.vv.string_exp = yystack.l_mark[0].vv.string_exp;
	}
break;
case 7:
#line 97 "grammar/c_syn.y"
	{
		int len1 = strlen(yystack.l_mark[-1].vv.string_exp);
		int len2 = strlen(yystack.l_mark[0].vv.string_exp);
		yyval.vv.string_exp = malloc(len1+len2+2);
		snprintf(yyval.vv.string_exp,len1+len2+2, "%s\n%s",yystack.l_mark[-1].vv.string_exp,yystack.l_mark[0].vv.string_exp);
		free(yystack.l_mark[-1].vv.string_exp);
		free(yystack.l_mark[0].vv.string_exp);
	}
break;
case 8:
#line 108 "grammar/c_syn.y"
	{
			yyval.vv.string_exp = yystack.l_mark[0].vv.string_exp;
	}
break;
case 9:
#line 111 "grammar/c_syn.y"
	{
		yyval.vv.string_exp = yystack.l_mark[0].vv.string_exp;
	}
break;
case 10:
#line 116 "grammar/c_syn.y"
	{
		int len1 = strlen(yystack.l_mark[-3].vv.string_exp);
		int len2 = strlen(yystack.l_mark[-2].vv.string_exp);
		int len3 = strlen(yystack.l_mark[-1].vv.string_exp);
		int len4 = strlen(yystack.l_mark[0].vv.string_exp);
		yyval.vv.string_exp = malloc(len1+len2+len3+len4+4);
		snprintf(yyval.vv.string_exp,len1+len2+len3+len4+4, "%s %s\n%s\n%s",yystack.l_mark[-3].vv.string_exp,yystack.l_mark[-2].vv.string_exp,yystack.l_mark[-1].vv.string_exp,yystack.l_mark[0].vv.string_exp);
		free(yystack.l_mark[-3].vv.string_exp);
		free(yystack.l_mark[-2].vv.string_exp);
		free(yystack.l_mark[-1].vv.string_exp);
		free(yystack.l_mark[0].vv.string_exp);
	}
break;
case 11:
#line 128 "grammar/c_syn.y"
	{
		int len1 = strlen(yystack.l_mark[-2].vv.string_exp);
		int len2 = strlen(yystack.l_mark[-1].vv.string_exp);
		int len3 = strlen(yystack.l_mark[0].vv.string_exp);
		yyval.vv.string_exp = malloc(len1+len2+len3+3);
		snprintf(yyval.vv.string_exp,len1+len2+len3+3, "%s %s\n%s",yystack.l_mark[-2].vv.string_exp,yystack.l_mark[-1].vv.string_exp,yystack.l_mark[0].vv.string_exp);
		free(yystack.l_mark[-2].vv.string_exp);
		free(yystack.l_mark[-1].vv.string_exp);
		free(yystack.l_mark[0].vv.string_exp);
	}
break;
case 12:
#line 138 "grammar/c_syn.y"
	{
		int len1 = strlen(yystack.l_mark[-2].vv.string_exp);
		int len2 = strlen(yystack.l_mark[-1].vv.string_exp);
		int len3 = strlen(yystack.l_mark[0].vv.string_exp);
		yyval.vv.string_exp = malloc(len1+len2+len3+3);
		snprintf(yyval.vv.string_exp,len1+len2+2, "%s\n%s\n%s",yystack.l_mark[-2].vv.string_exp,yystack.l_mark[-1].vv.string_exp,yystack.l_mark[0].vv.string_exp);
		free(yystack.l_mark[-2].vv.string_exp);
		free(yystack.l_mark[-1].vv.string_exp);
		free(yystack.l_mark[0].vv.string_exp);
	}
break;
case 13:
#line 148 "grammar/c_syn.y"
	{
		int len1 = strlen(yystack.l_mark[-1].vv.string_exp);
		int len2 = strlen(yystack.l_mark[0].vv.string_exp);
		yyval.vv.string_exp = malloc(len1+len2+2);
		snprintf(yyval.vv.string_exp,len1+len2+2, "%s\n%s",yystack.l_mark[-1].vv.string_exp,yystack.l_mark[0].vv.string_exp);
		free(yystack.l_mark[-1].vv.string_exp);
		free(yystack.l_mark[0].vv.string_exp);
	}
break;
case 14:
#line 159 "grammar/c_syn.y"
	{
		int len1 = strlen(yystack.l_mark[-1].vv.string_val);
		yyval.vv.string_exp = malloc(len1+8);
		snprintf(yyval.vv.string_exp,len1+8, "goto %s ;",yystack.l_mark[-1].vv.string_val);
	}
break;
case 15:
#line 164 "grammar/c_syn.y"
	{
		yyval.vv.string_exp = malloc(7);
		snprintf(yyval.vv.string_exp,7, "break;");
	}
break;
case 16:
#line 168 "grammar/c_syn.y"
	{
		yyval.vv.string_exp = malloc(8);
		snprintf(yyval.vv.string_exp,8, "return;");
	}
break;
case 17:
#line 172 "grammar/c_syn.y"
	{
		int len1 = strlen(yystack.l_mark[-1].vv.string_exp);
		yyval.vv.string_exp = malloc(len1+10);
		snprintf(yyval.vv.string_exp,len1+10, "return %s ;",yystack.l_mark[-1].vv.string_exp);
		free(yystack.l_mark[-1].vv.string_exp);
	}
break;
case 18:
#line 180 "grammar/c_syn.y"
	{
		yyval.vv.string_exp = malloc(4);
		snprintf(yyval.vv.string_exp,4, "{ }");
	}
break;
case 19:
#line 184 "grammar/c_syn.y"
	{
		int len1 = strlen(yystack.l_mark[-1].vv.string_exp);
		yyval.vv.string_exp = malloc(len1+3);
		snprintf(yyval.vv.string_exp,len1+3, "{%s}",yystack.l_mark[-1].vv.string_exp);
		free(yystack.l_mark[-1].vv.string_exp);
		/*ast_print($2._ast,0);*/

	  	 yyval.vv._ast = yystack.l_mark[-1].vv._ast;


	}
break;
case 20:
#line 195 "grammar/c_syn.y"
	{
		int len1 = strlen(yystack.l_mark[-1].vv.string_exp);
		yyval.vv.string_exp = malloc(len1+3);
		snprintf(yyval.vv.string_exp,len1+3, "{%s}",yystack.l_mark[-1].vv.string_exp);
		free(yystack.l_mark[-1].vv.string_exp);

	   	yyval.vv._ast = yystack.l_mark[-1].vv._ast;



	}
break;
case 21:
#line 206 "grammar/c_syn.y"
	{
		int len1 = strlen(yystack.l_mark[-2].vv.string_exp);
		int len2 = strlen(yystack.l_mark[-1].vv.string_exp);
		yyval.vv.string_exp = malloc(len1+len2+6);
		snprintf(yyval.vv.string_exp,len1+len2+6, "{\n%s\n%s\n}",yystack.l_mark[-2].vv.string_exp,yystack.l_mark[-1].vv.string_exp);
		free(yystack.l_mark[-2].vv.string_exp);
		free(yystack.l_mark[-1].vv.string_exp);

		/*ast_print($2._ast,0);*/
		/*printf("---------------------------\n");*/
		/*ast_print($3._ast,0);*/


	}
break;
case 22:
#line 227 "grammar/c_syn.y"
	{
		   yyval.vv.string_exp = yystack.l_mark[0].vv.string_exp;
		   yyval.vv._ast = yystack.l_mark[0].vv._ast;
	}
break;
case 23:
#line 231 "grammar/c_syn.y"
	{
                int len1 = strlen(yystack.l_mark[-1].vv.string_exp);
		int len2 = strlen(yystack.l_mark[0].vv.string_exp);
		yyval.vv.string_exp = malloc(len1+len2+2);
		snprintf(yyval.vv.string_exp,len1+len2+2, "%s\n%s",yystack.l_mark[-1].vv.string_exp,yystack.l_mark[0].vv.string_exp);
		free(yystack.l_mark[-1].vv.string_exp);
		free(yystack.l_mark[0].vv.string_exp);
		yyval.vv._ast = ast_new_operation(AST_STATE_LIST,yystack.l_mark[-1].vv._ast,yystack.l_mark[0].vv._ast);
	}
break;
case 24:
#line 242 "grammar/c_syn.y"
	{
	 yyval.vv.string_exp = yystack.l_mark[0].vv.string_exp;
	 yyval.vv._ast = yystack.l_mark[0].vv._ast;

	  }
break;
case 25:
#line 247 "grammar/c_syn.y"
	{
         yyval.vv.string_exp = yystack.l_mark[0].vv.string_exp;
	 /*$$._ast = $1._ast;*/

	}
break;
case 26:
#line 252 "grammar/c_syn.y"
	{

		yyval.vv.string_exp = yystack.l_mark[0].vv.string_exp;
	}
break;
case 27:
#line 256 "grammar/c_syn.y"
	{
		yyval.vv.string_exp = yystack.l_mark[0].vv.string_exp;
		yyval.vv._ast = yystack.l_mark[0].vv._ast;
	}
break;
case 28:
#line 260 "grammar/c_syn.y"
	{
		yyval.vv.string_exp = yystack.l_mark[0].vv.string_exp;
	}
break;
case 29:
#line 265 "grammar/c_syn.y"
	{
		yyval.vv.string_exp = malloc(2);
		snprintf(yyval.vv.string_exp,2, ";");

	}
break;
case 30:
#line 270 "grammar/c_syn.y"
	{
		int len = strlen(yystack.l_mark[-1].vv.string_exp);
		yyval.vv.string_exp = malloc(len+2);
		snprintf(yyval.vv.string_exp,len+2, "%s;",yystack.l_mark[-1].vv.string_exp);
		/*printf("\n---------TEST777------ | %s |---------\n",$1.string_exp);*/
		free(yystack.l_mark[-1].vv.string_exp);

		yyval.vv._ast = yystack.l_mark[-1].vv._ast;
	}
break;
case 31:
#line 279 "grammar/c_syn.y"
	{
		int len = strlen(yystack.l_mark[0].vv.string_val);
		yyval.vv.string_exp = malloc(len+2);
		snprintf(yyval.vv.string_exp,len+2,"%s\n",yystack.l_mark[0].vv.string_val);
		free(yystack.l_mark[0].vv.string_val);

		yyval.vv._ast = ast_new_print();
	}
break;
case 32:
#line 293 "grammar/c_syn.y"
	{
		int len1 = strlen(yystack.l_mark[-2].vv.string_exp);
		int len2 = strlen(yystack.l_mark[0].vv.string_exp);
		yyval.vv.string_exp = malloc(len1+len2+6);
		snprintf(yyval.vv.string_exp,len1+len2+6, "if(%s)\n%s",yystack.l_mark[-2].vv.string_exp,yystack.l_mark[0].vv.string_exp);
		free(yystack.l_mark[-2].vv.string_exp);
		free(yystack.l_mark[0].vv.string_exp);
	}
break;
case 33:
#line 301 "grammar/c_syn.y"
	{
		int len1 = strlen(yystack.l_mark[-4].vv.string_exp);
		int len2 = strlen(yystack.l_mark[-2].vv.string_exp);
		int len3 = strlen(yystack.l_mark[0].vv.string_exp);
		yyval.vv.string_exp = malloc(len1+len2+len3+11);
		snprintf(yyval.vv.string_exp,len1+len2+len3+11, "if(%s)\n%s\nelse%s",yystack.l_mark[-4].vv.string_exp,yystack.l_mark[-2].vv.string_exp,yystack.l_mark[0].vv.string_exp);
		free(yystack.l_mark[-4].vv.string_exp);
		free(yystack.l_mark[-2].vv.string_exp);
		free(yystack.l_mark[0].vv.string_exp);
	}
break;
case 34:
#line 312 "grammar/c_syn.y"
	{
		 	ast *while_ast = ast_new_operation(AST_WHILE, yystack.l_mark[-2].vv._ast, yystack.l_mark[0].vv._ast);
			ast_print(while_ast, 0);
			yyval.vv._ast = while_ast;

	 		int len1 = strlen(yystack.l_mark[-2].vv.string_exp);
         		int len2 = strlen(yystack.l_mark[0].vv.string_exp);
         		yyval.vv.string_exp = malloc(len1+len2+9);
         		snprintf(yyval.vv.string_exp,len1+len2+9, "while(%s)\n%s",yystack.l_mark[-2].vv.string_exp,yystack.l_mark[0].vv.string_exp);
         		free(yystack.l_mark[-2].vv.string_exp);
         		free(yystack.l_mark[0].vv.string_exp);
	 }
break;
case 35:
#line 325 "grammar/c_syn.y"
	{

		ast* fora = ast_new_for(yystack.l_mark[-4].vv._ast,yystack.l_mark[-3].vv._ast,yystack.l_mark[-2].vv._ast,yystack.l_mark[0].vv._ast);
		ast_print(fora,0);
		yyval.vv._ast = fora;
		/*printf("\n[+] S->for_depth_counter_var : %d\n",for_depth_counter_var);*/
		int len1 = strlen(yystack.l_mark[-4].vv.string_exp);
		int len2 = strlen(yystack.l_mark[-3].vv.string_exp);
		int len3 = strlen(yystack.l_mark[-2].vv.string_exp);
		int len4 = strlen(yystack.l_mark[0].vv.string_exp);
		char *result = malloc(len1+len2+len3+len4+9);
		snprintf(result,len1+len2+len3+len4+9, "for(%s %s %s)\n%s",yystack.l_mark[-4].vv.string_exp,yystack.l_mark[-3].vv.string_exp,yystack.l_mark[-2].vv.string_exp,yystack.l_mark[0].vv.string_exp);
		yyval.vv.string_exp = result;
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
			   /*printf("\n--------------BLAST GOT RESULT %d---------\n",globalData.symbol->optimized);*/
			   if(globalData.symbol->optimized == 1){
				int lenm = globalData.symbol->bytes_count;
			   	/*printf("[+] reading optimizer output count(%d)\n",lenm);*/
			        fptr = fopen(OPTIMIZER_FILE,"r");
			   	char* op_res = malloc(lenm);
			   	memset(op_res,0,lenm);
			   	char *r = fgets(op_res,lenm,fptr);
				
				if (r != NULL) {
					perror("fgets error 363\n");
				}

			   	free(yyval.vv.string_exp);
			   	yyval.vv.string_exp = op_res;
			   }

		}


		for_depth_counter_var--;
		/*printf("\n[+] S->for_depth_counter_var : %d\n",for_depth_counter_var);*/

	}
break;
case 36:
#line 376 "grammar/c_syn.y"
	{for_depth_counter_var++;}
break;
case 37:
#line 381 "grammar/c_syn.y"
	{
 		yyval.vv.string_exp = yystack.l_mark[0].vv.string_exp;
 		yyval.vv._ast = yystack.l_mark[0].vv._ast;
 	}
break;
case 38:
#line 385 "grammar/c_syn.y"
	{

		int len1 = strlen(yystack.l_mark[-2].vv.string_exp);
		int len2 = strlen(yystack.l_mark[0].vv.string_exp);
		yyval.vv.string_exp = malloc(len1+len2+2);
		snprintf(yyval.vv.string_exp,len1+len2+2, "%s,%s",yystack.l_mark[-2].vv.string_exp,yystack.l_mark[0].vv.string_exp);
		free(yystack.l_mark[-2].vv.string_exp);
		free(yystack.l_mark[0].vv.string_exp);
		yyval.vv._ast = ast_new_operation(AST_EXPR_LIST,yystack.l_mark[-2].vv._ast,yystack.l_mark[0].vv._ast);
	}
break;
case 39:
#line 397 "grammar/c_syn.y"
	{
		yyval.vv.string_exp = yystack.l_mark[0].vv.string_exp;
		yyval.vv._ast = yystack.l_mark[0].vv._ast;
	}
break;
case 40:
#line 401 "grammar/c_syn.y"
	{
		int len1 = strlen(yystack.l_mark[-3].vv.string_exp);
		int len2 = strlen(yystack.l_mark[-1].vv.string_exp);
		yyval.vv.string_exp = malloc(len1+len2+3);
		snprintf(yyval.vv.string_exp,len1+len2+3, "%s[%s]",yystack.l_mark[-3].vv.string_exp,yystack.l_mark[-1].vv.string_exp);
		free(yystack.l_mark[-3].vv.string_exp);
		free(yystack.l_mark[-1].vv.string_exp);

		yyval.vv._ast = ast_new_operation(AST_ARR_ACCESS,yystack.l_mark[-3].vv._ast,yystack.l_mark[-1].vv._ast);
	}
break;
case 41:
#line 411 "grammar/c_syn.y"
	{
		int len1 = strlen(yystack.l_mark[-2].vv.string_exp);
		yyval.vv.string_exp = malloc(len1+3);
		snprintf(yyval.vv.string_exp,len1+3, "%s()",yystack.l_mark[-2].vv.string_exp);
		free(yystack.l_mark[-2].vv.string_exp);

		yyval.vv._ast = ast_new_operation(AST_FUNC_CALL,yystack.l_mark[-2].vv._ast,0);
	}
break;
case 42:
#line 419 "grammar/c_syn.y"
	{
		int len1 = strlen(yystack.l_mark[-1].vv.string_exp);
		yyval.vv.string_exp = malloc(len1+3);
		snprintf(yyval.vv.string_exp,len1+3, "%s++",yystack.l_mark[-1].vv.string_exp);
		free(yystack.l_mark[-1].vv.string_exp);

		yyval.vv._ast = ast_new_operation(AST_INC,yystack.l_mark[-1].vv._ast,0);
	}
break;
case 43:
#line 427 "grammar/c_syn.y"
	{
		int len1 = strlen(yystack.l_mark[-1].vv.string_exp);
		yyval.vv.string_exp = malloc(len1+3);
		snprintf(yyval.vv.string_exp,len1+3, "%s--",yystack.l_mark[-1].vv.string_exp);
		free(yystack.l_mark[-1].vv.string_exp);

		yyval.vv._ast = ast_new_operation(AST_DEC,yystack.l_mark[-1].vv._ast,0);
	}
break;
case 44:
#line 437 "grammar/c_syn.y"
	{
		yyval.vv.string_exp = yystack.l_mark[0].vv.string_exp;
		yyval.vv._ast = yystack.l_mark[0].vv._ast;
	}
break;
case 45:
#line 441 "grammar/c_syn.y"
	{
		int len2 = strlen(yystack.l_mark[0].vv.string_exp);
		yyval.vv.string_exp = malloc(len2+3);
		snprintf(yyval.vv.string_exp,len2+3, "++%s",yystack.l_mark[0].vv.string_exp);
		free(yystack.l_mark[0].vv.string_exp);
		yyval.vv._ast = ast_new_operation(AST_INC,0,yystack.l_mark[0].vv._ast);

	}
break;
case 46:
#line 449 "grammar/c_syn.y"
	{
		int len2 = strlen(yystack.l_mark[0].vv.string_exp);
		yyval.vv.string_exp = malloc(len2+3);
		snprintf(yyval.vv.string_exp,len2+3, "--%s",yystack.l_mark[0].vv.string_exp);
		free(yystack.l_mark[0].vv.string_exp);
		yyval.vv._ast = ast_new_operation(AST_DEC,0,yystack.l_mark[0].vv._ast);
	}
break;
case 47:
#line 458 "grammar/c_syn.y"
	{
		yyval.vv.string_exp = yystack.l_mark[0].vv.string_exp;
		yyval.vv._ast = yystack.l_mark[0].vv._ast;
	}
break;
case 48:
#line 462 "grammar/c_syn.y"
	{


		int len1 = strlen(yystack.l_mark[-2].vv.string_exp);
		int len2 = strlen(yystack.l_mark[0].vv.string_exp);
		yyval.vv.string_exp = malloc(len1+len2+2);
		snprintf(yyval.vv.string_exp,len1+len2+2, "%s*%s",yystack.l_mark[-2].vv.string_exp,yystack.l_mark[0].vv.string_exp);
		free(yystack.l_mark[-2].vv.string_exp);
		free(yystack.l_mark[0].vv.string_exp);

		yyval.vv._ast = ast_new_operation(AST_MUL,yystack.l_mark[-2].vv._ast,yystack.l_mark[0].vv._ast);

	}
break;
case 49:
#line 475 "grammar/c_syn.y"
	{

		int len1 = strlen(yystack.l_mark[-2].vv.string_exp);
		int len2 = strlen(yystack.l_mark[0].vv.string_exp);
		yyval.vv.string_exp = malloc(len1+len2+2);
		snprintf(yyval.vv.string_exp,len1+len2+2, "%s/%s",yystack.l_mark[-2].vv.string_exp,yystack.l_mark[0].vv.string_exp);
		free(yystack.l_mark[-2].vv.string_exp);
		free(yystack.l_mark[0].vv.string_exp);

		yyval.vv._ast = ast_new_operation(AST_DIV,yystack.l_mark[-2].vv._ast,yystack.l_mark[0].vv._ast);
	}
break;
case 50:
#line 486 "grammar/c_syn.y"
	{

		int len1 = strlen(yystack.l_mark[-2].vv.string_exp);
		int len2 = strlen(yystack.l_mark[0].vv.string_exp);
		yyval.vv.string_exp = malloc(len1+len2+4);
		snprintf(yyval.vv.string_exp,len1+len2+4, "%s%%%s",yystack.l_mark[-2].vv.string_exp,yystack.l_mark[0].vv.string_exp);
		free(yystack.l_mark[-2].vv.string_exp);
		free(yystack.l_mark[0].vv.string_exp);

		yyval.vv._ast = ast_new_operation(AST_MOD,yystack.l_mark[-2].vv._ast,yystack.l_mark[0].vv._ast);


	}
break;
case 51:
#line 501 "grammar/c_syn.y"
	{

		yyval.vv.string_exp = yystack.l_mark[0].vv.string_exp;
		yyval.vv._ast = yystack.l_mark[0].vv._ast;
	}
break;
case 52:
#line 506 "grammar/c_syn.y"
	{

		int len1 = strlen(yystack.l_mark[-2].vv.string_exp);
		int len2 = strlen(yystack.l_mark[0].vv.string_exp);
		yyval.vv.string_exp = malloc(len1+len2+2);
		snprintf(yyval.vv.string_exp,len1+len2+2, "%s+%s",yystack.l_mark[-2].vv.string_exp,yystack.l_mark[0].vv.string_exp);
		free(yystack.l_mark[-2].vv.string_exp);
		free(yystack.l_mark[0].vv.string_exp);

		yyval.vv._ast = ast_new_operation(AST_ADD,yystack.l_mark[-2].vv._ast,yystack.l_mark[0].vv._ast);

	}
break;
case 53:
#line 518 "grammar/c_syn.y"
	{

		int len1 = strlen(yystack.l_mark[-2].vv.string_exp);
		int len2 = strlen(yystack.l_mark[0].vv.string_exp);
		yyval.vv.string_exp = malloc(len1+len2+2);
		snprintf(yyval.vv.string_exp,len1+len2+2, "%s-%s",yystack.l_mark[-2].vv.string_exp,yystack.l_mark[0].vv.string_exp);
		free(yystack.l_mark[-2].vv.string_exp);
		free(yystack.l_mark[0].vv.string_exp);

		yyval.vv._ast = ast_new_operation(AST_SUB,yystack.l_mark[-2].vv._ast,yystack.l_mark[0].vv._ast);

	}
break;
case 54:
#line 532 "grammar/c_syn.y"
	{

		yyval.vv.string_exp = yystack.l_mark[0].vv.string_exp;
		yyval.vv._ast = yystack.l_mark[0].vv._ast;

	}
break;
case 55:
#line 538 "grammar/c_syn.y"
	{
		int len1 = strlen(yystack.l_mark[-2].vv.string_exp);
		int len2 = strlen(yystack.l_mark[0].vv.string_exp);
		yyval.vv.string_exp = malloc(len1+len2+3);
		snprintf(yyval.vv.string_exp,len1+len2+3, "%s<<%s",yystack.l_mark[-2].vv.string_exp,yystack.l_mark[0].vv.string_exp);
		free(yystack.l_mark[-2].vv.string_exp);
		free(yystack.l_mark[0].vv.string_exp);

		yyval.vv._ast = ast_new_operation(AST_LEFT_OP,yystack.l_mark[-2].vv._ast,yystack.l_mark[0].vv._ast);

	}
break;
case 56:
#line 549 "grammar/c_syn.y"
	{
		int len1 = strlen(yystack.l_mark[-2].vv.string_exp);
		int len2 = strlen(yystack.l_mark[0].vv.string_exp);
		yyval.vv.string_exp = malloc(len1+len2+3);
		snprintf(yyval.vv.string_exp,len1+len2+3, "%s>>%s",yystack.l_mark[-2].vv.string_exp,yystack.l_mark[0].vv.string_exp);
		free(yystack.l_mark[-2].vv.string_exp);
		free(yystack.l_mark[0].vv.string_exp);


		yyval.vv._ast = ast_new_operation(AST_RIGHT_OP,yystack.l_mark[-2].vv._ast,yystack.l_mark[0].vv._ast);
	}
break;
case 57:
#line 562 "grammar/c_syn.y"
	{

		yyval.vv.string_exp = yystack.l_mark[0].vv.string_exp;
		yyval.vv._ast = yystack.l_mark[0].vv._ast;

	}
break;
case 58:
#line 568 "grammar/c_syn.y"
	{
		int len1 = strlen(yystack.l_mark[-2].vv.string_exp);
		int len2 = strlen(yystack.l_mark[0].vv.string_exp);
		yyval.vv.string_exp = malloc(len1+len2+2);
		snprintf(yyval.vv.string_exp,len1+len2+2, "%s<%s",yystack.l_mark[-2].vv.string_exp,yystack.l_mark[0].vv.string_exp);
		free(yystack.l_mark[-2].vv.string_exp);
		free(yystack.l_mark[0].vv.string_exp);
		yyval.vv._ast = ast_new_operation(AST_LOWER,yystack.l_mark[-2].vv._ast,yystack.l_mark[0].vv._ast);
	}
break;
case 59:
#line 577 "grammar/c_syn.y"
	{
		int len1 = strlen(yystack.l_mark[-2].vv.string_exp);
		int len2 = strlen(yystack.l_mark[0].vv.string_exp);
		yyval.vv.string_exp = malloc(len1+len2+2);
		snprintf(yyval.vv.string_exp,len1+len2+2, "%s>%s",yystack.l_mark[-2].vv.string_exp,yystack.l_mark[0].vv.string_exp);
		free(yystack.l_mark[-2].vv.string_exp);
		free(yystack.l_mark[0].vv.string_exp);
		yyval.vv._ast = ast_new_operation(AST_GREATER,yystack.l_mark[-2].vv._ast,yystack.l_mark[0].vv._ast);
	}
break;
case 60:
#line 586 "grammar/c_syn.y"
	{
		int len1 = strlen(yystack.l_mark[-2].vv.string_exp);
		int len2 = strlen(yystack.l_mark[0].vv.string_exp);
		yyval.vv.string_exp = malloc(len1+len2+3);
		snprintf(yyval.vv.string_exp,len1+len2+3, "%s<=%s",yystack.l_mark[-2].vv.string_exp,yystack.l_mark[0].vv.string_exp);
		free(yystack.l_mark[-2].vv.string_exp);
		free(yystack.l_mark[0].vv.string_exp);
		yyval.vv._ast = ast_new_operation(AST_LOWER_EQUAL,yystack.l_mark[-2].vv._ast,yystack.l_mark[0].vv._ast);

	}
break;
case 61:
#line 596 "grammar/c_syn.y"
	{
		int len1 = strlen(yystack.l_mark[-2].vv.string_exp);
		int len2 = strlen(yystack.l_mark[0].vv.string_exp);
		yyval.vv.string_exp = malloc(len1+len2+3);
		snprintf(yyval.vv.string_exp,len1+len2+3, "%s>=%s",yystack.l_mark[-2].vv.string_exp,yystack.l_mark[0].vv.string_exp);
		free(yystack.l_mark[-2].vv.string_exp);
		free(yystack.l_mark[0].vv.string_exp);
		yyval.vv._ast = ast_new_operation(AST_GREATER_EQUAL,yystack.l_mark[-2].vv._ast,yystack.l_mark[0].vv._ast);
	}
break;
case 62:
#line 607 "grammar/c_syn.y"
	{

		yyval.vv.string_exp = yystack.l_mark[0].vv.string_exp;
		yyval.vv._ast = yystack.l_mark[0].vv._ast;

	}
break;
case 63:
#line 613 "grammar/c_syn.y"
	{
		int len1 = strlen(yystack.l_mark[-2].vv.string_exp);
		int len2 = strlen(yystack.l_mark[0].vv.string_exp);
		yyval.vv.string_exp = malloc(len1+len2+3);
		snprintf(yyval.vv.string_exp,len1+len2+3, "%s==%s",yystack.l_mark[-2].vv.string_exp,yystack.l_mark[0].vv.string_exp);
		free(yystack.l_mark[-2].vv.string_exp);
		free(yystack.l_mark[0].vv.string_exp);

		yyval.vv._ast = ast_new_operation(AST_EQUAL,yystack.l_mark[-2].vv._ast,yystack.l_mark[0].vv._ast);

	}
break;
case 64:
#line 624 "grammar/c_syn.y"
	{
		int len1 = strlen(yystack.l_mark[-2].vv.string_exp);
		int len2 = strlen(yystack.l_mark[0].vv.string_exp);
		yyval.vv.string_exp = malloc(len1+len2+3);
		snprintf(yyval.vv.string_exp,len1+len2+3, "%s!=%s",yystack.l_mark[-2].vv.string_exp,yystack.l_mark[0].vv.string_exp);
		free(yystack.l_mark[-2].vv.string_exp);
		free(yystack.l_mark[0].vv.string_exp);
		yyval.vv._ast = ast_new_operation(AST_NOT_EQUAL,yystack.l_mark[-2].vv._ast,yystack.l_mark[0].vv._ast);
	}
break;
case 65:
#line 635 "grammar/c_syn.y"
	{
		yyval.vv.string_exp = yystack.l_mark[0].vv.string_exp;
		yyval.vv._ast = yystack.l_mark[0].vv._ast;

	}
break;
case 66:
#line 640 "grammar/c_syn.y"
	{
		int len1 = strlen(yystack.l_mark[-2].vv.string_exp);
		int len2 = strlen(yystack.l_mark[0].vv.string_exp);
		yyval.vv.string_exp = malloc(len1+len2+2);
		snprintf(yyval.vv.string_exp,len1+len2+2, "%s&%s",yystack.l_mark[-2].vv.string_exp,yystack.l_mark[0].vv.string_exp);
		free(yystack.l_mark[-2].vv.string_exp);
		free(yystack.l_mark[0].vv.string_exp);

		yyval.vv._ast = ast_new_operation(AST_AND,yystack.l_mark[-2].vv._ast,yystack.l_mark[0].vv._ast);
	}
break;
case 67:
#line 652 "grammar/c_syn.y"
	{

		yyval.vv.string_exp = yystack.l_mark[0].vv.string_exp;
		yyval.vv._ast = yystack.l_mark[0].vv._ast;

	}
break;
case 68:
#line 658 "grammar/c_syn.y"
	{
		int len1 = strlen(yystack.l_mark[-2].vv.string_exp);
		int len2 = strlen(yystack.l_mark[0].vv.string_exp);
		yyval.vv.string_exp = malloc(len1+len2+2);
		snprintf(yyval.vv.string_exp,len1+len2+2, "%s^%s",yystack.l_mark[-2].vv.string_exp,yystack.l_mark[0].vv.string_exp);
		free(yystack.l_mark[-2].vv.string_exp);
		free(yystack.l_mark[0].vv.string_exp);
		yyval.vv._ast = ast_new_operation(AST_EOR,yystack.l_mark[-2].vv._ast,yystack.l_mark[0].vv._ast);
	}
break;
case 69:
#line 669 "grammar/c_syn.y"
	{

		yyval.vv.string_exp = yystack.l_mark[0].vv.string_exp;
		yyval.vv._ast = yystack.l_mark[0].vv._ast;

	}
break;
case 70:
#line 675 "grammar/c_syn.y"
	{
		int len1 = strlen(yystack.l_mark[-2].vv.string_exp);
		int len2 = strlen(yystack.l_mark[0].vv.string_exp);
		yyval.vv.string_exp = malloc(len1+len2+2);
		snprintf(yyval.vv.string_exp,len1+len2+2, "%s|%s",yystack.l_mark[-2].vv.string_exp,yystack.l_mark[0].vv.string_exp);
		free(yystack.l_mark[-2].vv.string_exp);
		free(yystack.l_mark[0].vv.string_exp);
		yyval.vv._ast = ast_new_operation(AST_IOR,yystack.l_mark[-2].vv._ast,yystack.l_mark[0].vv._ast);
	}
break;
case 71:
#line 686 "grammar/c_syn.y"
	{

		yyval.vv.string_exp = yystack.l_mark[0].vv.string_exp;
		yyval.vv._ast = yystack.l_mark[0].vv._ast;

	}
break;
case 72:
#line 692 "grammar/c_syn.y"
	{
		int len1 = strlen(yystack.l_mark[-2].vv.string_exp);
		int len2 = strlen(yystack.l_mark[0].vv.string_exp);
		yyval.vv.string_exp = malloc(len1+len2+3);
		snprintf(yyval.vv.string_exp,len1+len2+3, "%s&&%s",yystack.l_mark[-2].vv.string_exp,yystack.l_mark[0].vv.string_exp);
		free(yystack.l_mark[-2].vv.string_exp);
		free(yystack.l_mark[0].vv.string_exp);

		yyval.vv._ast = ast_new_operation(AST_AND_OP,yystack.l_mark[-2].vv._ast,yystack.l_mark[0].vv._ast);
	}
break;
case 73:
#line 704 "grammar/c_syn.y"
	{

		yyval.vv.string_exp = yystack.l_mark[0].vv.string_exp;
		yyval.vv._ast = yystack.l_mark[0].vv._ast;

	}
break;
case 74:
#line 710 "grammar/c_syn.y"
	{
		int len1 = strlen(yystack.l_mark[-2].vv.string_exp);
		int len2 = strlen(yystack.l_mark[0].vv.string_exp);
		yyval.vv.string_exp = malloc(len1+len2+3);
		snprintf(yyval.vv.string_exp,len1+len2+3, "%s||%s",yystack.l_mark[-2].vv.string_exp,yystack.l_mark[0].vv.string_exp);
		free(yystack.l_mark[-2].vv.string_exp);
		free(yystack.l_mark[0].vv.string_exp);
		yyval.vv._ast = ast_new_operation(AST_OR_OP,yystack.l_mark[-2].vv._ast,yystack.l_mark[0].vv._ast);
	}
break;
case 75:
#line 723 "grammar/c_syn.y"
	{
		yyval.vv.string_exp = yystack.l_mark[0].vv.string_exp;
		yyval.vv._ast = yystack.l_mark[0].vv._ast;

	}
break;
case 76:
#line 728 "grammar/c_syn.y"
	{
		int len1 = strlen(yystack.l_mark[-2].vv.string_exp);
		int len2 = strlen(yystack.l_mark[0].vv.string_exp);
		yyval.vv.string_exp = malloc(len1+len2+2);
		snprintf(yyval.vv.string_exp,len1+len2+2, "%s=%s",yystack.l_mark[-2].vv.string_exp,yystack.l_mark[0].vv.string_exp);
		free(yystack.l_mark[-2].vv.string_exp);
		free(yystack.l_mark[-1].vv.string_exp);
		free(yystack.l_mark[0].vv.string_exp);

		yyval.vv._ast = ast_new_operation(AST_ASSIGN,yystack.l_mark[-2].vv._ast,yystack.l_mark[0].vv._ast);
	}
break;
case 77:
#line 741 "grammar/c_syn.y"
	{
		yyval.vv.string_exp = malloc(2);
		snprintf(yyval.vv.string_exp,2, "=");
	}
break;
case 78:
#line 749 "grammar/c_syn.y"
	{
		yyval.vv.string_exp = yystack.l_mark[0].vv.string_exp;
		yyval.vv._ast = yystack.l_mark[0].vv._ast;
	}
break;
case 79:
#line 753 "grammar/c_syn.y"
	{

		int len1 = strlen(yystack.l_mark[-1].vv.string_exp);
		int len2 = strlen(yystack.l_mark[0].vv.string_exp);
		yyval.vv.string_exp = malloc(len1+len2+2);
		snprintf(yyval.vv.string_exp,len1+len2+2, "%s %s",yystack.l_mark[-1].vv.string_exp,yystack.l_mark[0].vv.string_exp);
		free(yystack.l_mark[-1].vv.string_exp);
		free(yystack.l_mark[0].vv.string_exp);

		/*$$._ast = ast_new_operation(AST_DEC_LIST,$1._ast,$2._ast);*/


	}
break;
case 80:
#line 770 "grammar/c_syn.y"
	{
		/*restore the current type variable to -1*/
		 current_type_var = -1;

		/*COP*/
		int len1 = strlen(yystack.l_mark[-2].vv.string_exp);
		int len2 = strlen(yystack.l_mark[-1].vv.string_exp);
		yyval.vv.string_exp = malloc(len1+len2+3);
		snprintf(yyval.vv.string_exp,len1+len2+3, "%s %s;",yystack.l_mark[-2].vv.string_exp,yystack.l_mark[-1].vv.string_exp);
		free(yystack.l_mark[-2].vv.string_exp);
		free(yystack.l_mark[-1].vv.string_exp);

		/*===========================CHECK HERE DECLARATION AST*/
		yyval.vv._ast = ast_new_operation(AST_DEC_LIST,0,yystack.l_mark[-1].vv._ast);
		ast_print(yyval.vv._ast,0);

	}
break;
case 81:
#line 792 "grammar/c_syn.y"
	{
		 /*$$.type = $1.type; INT or FLAT ...*/
		 /*store the current type in a global variable....TODO*/
		 /*TODO check composed types=====!*/
		 current_type_var = yystack.l_mark[0].vv.type;

		 yyval.vv.string_exp = yystack.l_mark[0].vv.string_exp;
	}
break;
case 82:
#line 804 "grammar/c_syn.y"
	{
		yyval.vv.type = VOID;

		yyval.vv.string_exp = malloc(5);
		snprintf(yyval.vv.string_exp,5, "void");

	}
break;
case 83:
#line 811 "grammar/c_syn.y"
	{
		yyval.vv.type = INT;

		yyval.vv.string_exp = malloc(4);
		snprintf(yyval.vv.string_exp,4, "int");
	}
break;
case 84:
#line 817 "grammar/c_syn.y"
	{
		yyval.vv.type = FLOAT;
		yyval.vv.string_exp = malloc(6);
		snprintf(yyval.vv.string_exp,6, "float");
	}
break;
case 85:
#line 826 "grammar/c_syn.y"
	{
		symbol_p varp = (symbol_p) yystack.l_mark[0].vv.sentry;
		int countp = yystack.l_mark[0].vv.count_p; /*TODO maybe 0*/
		int countm = yystack.l_mark[0].vv.count_m;
		if(countp > 0 || countm > 0){
			varp->type = TYPE_ARRAY;
			varp->arr.dimention_m = countm;
			varp->arr.dimention_p = countp;
			for(int pp = 0;pp<4;pp++)
				varp->arr.size[pp] = yystack.l_mark[0].vv.t[pp];

		}

		yyval.vv.string_exp = yystack.l_mark[0].vv.string_exp;

	}
break;
case 86:
#line 842 "grammar/c_syn.y"
	{


	/*COPY*/
	int len1 = strlen(yystack.l_mark[-2].vv.string_exp);
	int len2 = strlen(yystack.l_mark[0].vv.string_exp);
	yyval.vv.string_exp = malloc(len1+len2+2);
	snprintf(yyval.vv.string_exp,len1+len2+2, "%s,%s",yystack.l_mark[-2].vv.string_exp,yystack.l_mark[0].vv.string_exp);
	free(yystack.l_mark[-2].vv.string_exp);
	free(yystack.l_mark[0].vv.string_exp);

	}
break;
case 87:
#line 858 "grammar/c_syn.y"
	{
		for(int l = 0;l<4;l++)
			yyval.vv.t[l] = yystack.l_mark[0].vv.t[l];
		yyval.vv.sentry = yystack.l_mark[0].vv.sentry;
		yyval.vv.count_p  = yystack.l_mark[0].vv.count_p; /*TODO maybe 0*/
		yyval.vv.count_m  = yystack.l_mark[0].vv.count_m;

		yyval.vv.string_exp = yystack.l_mark[0].vv.string_exp;
		symbol_p e= yyval.vv.sentry;
		e->glob_type = current_type_var;

		yyval.vv._ast = yystack.l_mark[0].vv._ast;
	}
break;
case 88:
#line 871 "grammar/c_syn.y"
	{
		for(int l = 0;l<4;l++){
			yyval.vv.t[l] = yystack.l_mark[-2].vv.t[l];
		}
		yyval.vv.sentry = yystack.l_mark[-2].vv.sentry;
		yyval.vv.count_p  = yystack.l_mark[-2].vv.count_p; /*TODO maybe 0*/
		yyval.vv.count_m  = yystack.l_mark[-2].vv.count_m;

		symbol_p e = yystack.l_mark[-2].vv.sentry;
		e->is_init = 1;
		e->glob_type = current_type_var;

		if(e->type == TYPE_VARIABLE && yystack.l_mark[0].vv.type != 1){
			printf("error :VAR Assignement bad type line: %d\n",line_counter+1);
			return -1;
		}
		if(e->type == TYPE_ARRAY && yystack.l_mark[0].vv.type != 0){
			printf("error :ARR Assignement bad type line: %d\n",line_counter+1);
			return -1;
		}
		if(e->type == TYPE_FUNCTION){
			printf("error :Functions can't be assigned line: %d\n",line_counter+1);
			return -1;
		}


		int len1 = strlen(yystack.l_mark[-2].vv.string_exp);
		int len2 = strlen(yystack.l_mark[0].vv.string_exp);
		yyval.vv.string_exp = malloc(len1+len2+2);
		snprintf(yyval.vv.string_exp,len1+len2+2, "%s=%s",yystack.l_mark[-2].vv.string_exp,yystack.l_mark[0].vv.string_exp);
		free(yystack.l_mark[-2].vv.string_exp);
		free(yystack.l_mark[0].vv.string_exp);

		yyval.vv._ast = ast_new_operation(AST_ASSIGN,yystack.l_mark[-2].vv._ast,yystack.l_mark[0].vv._ast);


	}
break;
case 89:
#line 913 "grammar/c_syn.y"
	{
		for(int l = 0;l<4;l++)
			yyval.vv.t[l] = yystack.l_mark[0].vv.t[l];
		yyval.vv.sentry = yystack.l_mark[0].vv.sentry;
		yyval.vv.count_p  = yystack.l_mark[-1].vv.count_p;
		yyval.vv.count_m  = yystack.l_mark[0].vv.count_m;
		yyval.vv.string_val = yystack.l_mark[-1].vv.string_val;



		int len1 = strlen(yystack.l_mark[-1].vv.string_exp);
		int len2 = strlen(yystack.l_mark[0].vv.string_exp);
		yyval.vv.string_exp = malloc(len1+len2+1);
		snprintf(yyval.vv.string_exp,len1+len2+1, "%s%s",yystack.l_mark[-1].vv.string_exp,yystack.l_mark[0].vv.string_exp);
		free(yystack.l_mark[-1].vv.string_exp);
		free(yystack.l_mark[0].vv.string_exp);



		yyval.vv._ast = yystack.l_mark[0].vv._ast;
	}
break;
case 90:
#line 934 "grammar/c_syn.y"
	{

		for(int l = 0;l<4;l++)
			yyval.vv.t[l] = yystack.l_mark[0].vv.t[l];
		yyval.vv.sentry = yystack.l_mark[0].vv.sentry;
		yyval.vv.count_p  = yystack.l_mark[0].vv.count_p; /*TODO maybe 0*/
		yyval.vv.count_m  = yystack.l_mark[0].vv.count_m;
	/*COPY*/
		yyval.vv.string_exp = yystack.l_mark[0].vv.string_exp;

		yyval.vv._ast = yystack.l_mark[0].vv._ast;

	}
break;
case 91:
#line 951 "grammar/c_syn.y"
	{
		yyval.vv.count_p  = 0;
		yyval.vv.count_m  = 0;
		direct_declarator_var = 0;
		yyval.vv.sentry = yystack.l_mark[0].vv.sentry;
		symbol_p tmp = yyval.vv.sentry;
		tmp->type = TYPE_VARIABLE;
		yyval.vv.string_val = yystack.l_mark[0].vv.string_val;

		/*set is_dec bit for the current variable;*/
		char * curr_var_name_tmp = yystack.l_mark[0].vv.string_val;
		if(current_type_var != -1){
		    symbol_p tttt;
	   	     /* int rep = lookup_symbol_entry(curr_var_name_tmp,&tttt);*/
	   	    /* printf("lookinf for %s\n",curr_var_name_tmp);*/
		    lookup_symbol_entry(curr_var_name_tmp,&tttt);
		    if(tttt->is_dec == 1){
			printf("error : Redeclaration of variable %s\tat line : %d\n",curr_var_name_tmp,line_counter+1);
			return -1;
		    }
		    /*not yet declared...so set is_dec bit*/
		    tttt->is_dec = 1;
		}

		printf("---------------962----------identifier : %s\n",curr_var_name_tmp);

		int len = strlen(curr_var_name_tmp);
		yyval.vv.string_exp = malloc(len+1);
		snprintf(yyval.vv.string_exp,len+1, "%s",curr_var_name_tmp);

		yyval.vv._ast = ast_new_id(curr_var_name_tmp);



	}
break;
case 92:
#line 986 "grammar/c_syn.y"
	{
         	/*$$ = $1 +1;*/
        	yyval.vv.t[direct_declarator_var] = yystack.l_mark[-1].vv.val;
         	direct_declarator_var++;
		yyval.vv.count_m = direct_declarator_var;
		yyval.vv.string_val = yystack.l_mark[-3].vv.string_val;

		yyval.vv.sentry = yystack.l_mark[-3].vv.sentry;
		symbol_p tmp = yyval.vv.sentry;
		tmp->type = TYPE_ARRAY;

		int len1 = strlen(yystack.l_mark[-3].vv.string_exp);
		int len2 = strlen(yystack.l_mark[-1].vv.string_val);
		yyval.vv.string_exp = malloc(len1+len2+3);
		snprintf(yyval.vv.string_exp,len1+len2+4, "%s[%s]",yystack.l_mark[-3].vv.string_exp,yystack.l_mark[-1].vv.string_val);
		free(yystack.l_mark[-3].vv.string_exp);

		yyval.vv._ast = ast_new_operation(AST_ARR_ACCESS,yystack.l_mark[-3].vv._ast,ast_new_number(yystack.l_mark[-1].vv.val));
		current_type_var = -1;

        }
break;
case 93:
#line 1007 "grammar/c_syn.y"
	{
        		current_type_var = -1;
			printf("TEST940\n");
       			int len1 = strlen(yystack.l_mark[-2].vv.string_exp);
        		yyval.vv.string_exp = malloc(len1+3);
        		snprintf(yyval.vv.string_exp,len1+3, "%s()",yystack.l_mark[-2].vv.string_exp);
        		free(yystack.l_mark[-2].vv.string_exp);

			yyval.vv.sentry = yystack.l_mark[-2].vv.sentry;
			symbol_p tmp = yyval.vv.sentry;
			tmp->type = TYPE_FUNCTION;
        }
break;
case 94:
#line 1020 "grammar/c_syn.y"
	{
			current_type_var = -1;
        		printf("TEST941\n");
        		int len1 = strlen(yystack.l_mark[-3].vv.string_exp);
			int len2 = strlen(yystack.l_mark[-1].vv.string_exp);
			yyval.vv.string_exp = malloc(len1+len2+3);
			snprintf(yyval.vv.string_exp,len1+len2+3, "%s(%s)",yystack.l_mark[-3].vv.string_exp,yystack.l_mark[-1].vv.string_exp);
			free(yystack.l_mark[-3].vv.string_exp);
			free(yystack.l_mark[-1].vv.string_exp);
			yyval.vv.sentry = yystack.l_mark[-3].vv.sentry;
			symbol_p tmp = yyval.vv.sentry;
			tmp->type = TYPE_FUNCTION;

        }
break;
case 95:
#line 1034 "grammar/c_syn.y"
	{
		current_type_var = -1;
		yyval.vv.sentry = yystack.l_mark[-3].vv.sentry;
		int len1 = strlen(yystack.l_mark[-3].vv.string_exp);
		int len2 = strlen(yystack.l_mark[-1].vv.string_exp);
		yyval.vv.string_exp = malloc(len1+len2+3);
		snprintf(yyval.vv.string_exp,len1+len2+3, "%s(%s)",yystack.l_mark[-3].vv.string_exp,yystack.l_mark[-1].vv.string_exp);
		free(yystack.l_mark[-3].vv.string_exp);
		free(yystack.l_mark[-1].vv.string_exp);
		symbol_p tmp = yyval.vv.sentry;
		tmp->type = TYPE_FUNCTION;
		/*arg number*/
	}
break;
case 96:
#line 1051 "grammar/c_syn.y"
	{
		yyval.vv.string_exp = yystack.l_mark[0].vv.string_exp;
	}
break;
case 97:
#line 1054 "grammar/c_syn.y"
	{
		int len1 = strlen(yystack.l_mark[-2].vv.string_exp);
		int len2 = strlen(yystack.l_mark[0].vv.string_exp);
		yyval.vv.string_exp = malloc(len1+len2+2);
		snprintf(yyval.vv.string_exp,len1+len2+2, "%s,%s",yystack.l_mark[-2].vv.string_exp,yystack.l_mark[0].vv.string_exp);
		free(yystack.l_mark[-2].vv.string_exp);
		free(yystack.l_mark[0].vv.string_exp);
	}
break;
case 98:
#line 1065 "grammar/c_syn.y"
	{
		int len1 = strlen(yystack.l_mark[-1].vv.string_exp);
		int len2 = strlen(yystack.l_mark[0].vv.string_exp);
		yyval.vv.string_exp = malloc(len1+len2+2);
		snprintf(yyval.vv.string_exp,len1+len2+2, "%s %s",yystack.l_mark[-1].vv.string_exp,yystack.l_mark[0].vv.string_exp);
		free(yystack.l_mark[-1].vv.string_exp);
		free(yystack.l_mark[0].vv.string_exp);
	}
break;
case 99:
#line 1077 "grammar/c_syn.y"
	{
		yyval.vv.count_p = 1;

		yyval.vv.string_exp = malloc(2);
		snprintf(yyval.vv.string_exp,2,"*");




	}
break;
case 100:
#line 1088 "grammar/c_syn.y"
	{
	 	yyval.vv.count_p = yystack.l_mark[0].vv.count_p +1;

	 	int len1 = strlen(yystack.l_mark[0].vv.string_exp);
	 	yyval.vv.string_exp = malloc(len1+3);
		snprintf(yyval.vv.string_exp,len1+3,"*%s",yystack.l_mark[0].vv.string_exp);
		free(yystack.l_mark[0].vv.string_exp);


	}
break;
case 101:
#line 1102 "grammar/c_syn.y"
	{
	 	yyval.vv.string_exp = yystack.l_mark[0].vv.string_exp;

	 	yyval.vv._ast = yystack.l_mark[0].vv._ast;
	 	yyval.vv.type = 1;/*simple*/

	}
break;
case 102:
#line 1109 "grammar/c_syn.y"
	{
		int len1 = strlen(yystack.l_mark[-1].vv.string_exp);
		yyval.vv.string_exp = malloc(len1+3);
		snprintf(yyval.vv.string_exp,len1+3, "{%s}",yystack.l_mark[-1].vv.string_exp);
		free(yystack.l_mark[-1].vv.string_exp);
		yyval.vv.type = 0;/*complex*/

		yyval.vv._ast = yystack.l_mark[-1].vv._ast;
	}
break;
case 103:
#line 1120 "grammar/c_syn.y"
	{
		yyval.vv.string_exp = yystack.l_mark[0].vv.string_exp;
		yyval.vv._ast = yystack.l_mark[0].vv._ast;
	}
break;
case 104:
#line 1124 "grammar/c_syn.y"
	{

		int len1 = strlen(yystack.l_mark[-2].vv.string_exp);
		int len2 = strlen(yystack.l_mark[0].vv.string_exp);
		yyval.vv.string_exp = malloc(len1+len2+2);
		snprintf(yyval.vv.string_exp,len1+len2+2, "%s,%s",yystack.l_mark[-2].vv.string_exp,yystack.l_mark[0].vv.string_exp);
		free(yystack.l_mark[-2].vv.string_exp);
		free(yystack.l_mark[0].vv.string_exp);

		yyval.vv._ast = ast_new_operation(AST_INIT_LIST,yystack.l_mark[-2].vv._ast,yystack.l_mark[0].vv._ast);

	}
break;
case 105:
#line 1140 "grammar/c_syn.y"
	{
		yyval.vv.type = IDENTIFIER;
		char * curr_var_name_tmp = yystack.l_mark[0].vv.string_val;
		if(current_type_var == -1){
		    symbol_p tttt;
		    int rep = lookup_symbol_entry(curr_var_name_tmp,&tttt);
		    if(rep == -1 || tttt->is_dec == 0){
			printf("error : Undeclared variable %s\tat line : %d\n",curr_var_name_tmp,line_counter+1);
			return -1;
		    }

		}

		/*printf("------------1138--------Variable %s \n",curr_var_name_tmp);*/
		int len = strlen(curr_var_name_tmp);
		yyval.vv.string_exp = malloc(len+1);
		snprintf(yyval.vv.string_exp,len+1, "%s",curr_var_name_tmp);

		/*printf("CONST_INT : %s\n",curr_var_name_tmp);*/
		yyval.vv._ast = ast_new_id(curr_var_name_tmp);


	}
break;
case 106:
#line 1163 "grammar/c_syn.y"
	{
		yyval.vv.type = CONST_INT;


		char * curr_var_name_tmp = yystack.l_mark[0].vv.string_val;
		int len = strlen(curr_var_name_tmp);
		yyval.vv.string_exp = malloc(len+1);
		snprintf(yyval.vv.string_exp,len+1, "%s",curr_var_name_tmp);


		int a = atoi(curr_var_name_tmp);
		/*printf("CONST_INT : %d\n",a);*/
		yyval.vv._ast = ast_new_number(a);

	}
break;
case 107:
#line 1178 "grammar/c_syn.y"
	{
		if(current_type_var == INT || current_type_var == STRING){
			printf("incompatible type");
			return -1;
		}
		yyval.vv.type = CONST_FLOAT;
		char * curr_var_name_tmp = yystack.l_mark[0].vv.string_val;
		int len = strlen(curr_var_name_tmp);
		yyval.vv.string_exp = malloc(len+1);
		snprintf(yyval.vv.string_exp,len+1, "%s",curr_var_name_tmp);
		float a = strtof(curr_var_name_tmp, NULL);

		/*printf("CONST_FLOAT : %f\n",a);*/
		yyval.vv._ast = ast_new_float(a);

	}
break;
case 108:
#line 1194 "grammar/c_syn.y"
	{

		yyval.vv.type = yystack.l_mark[-1].vv.type;
		char * curr_var_name_tmp = yystack.l_mark[-1].vv.string_exp;
		int len = strlen(curr_var_name_tmp);
		yyval.vv.string_exp = malloc(len+3);
		snprintf(yyval.vv.string_exp,len+4, "(%s)",yystack.l_mark[-1].vv.string_exp);
		free(yystack.l_mark[-1].vv.string_exp);

		yyval.vv._ast = yystack.l_mark[-1].vv._ast;

	}
break;
case 109:
#line 1206 "grammar/c_syn.y"
	{
		yyval.vv.type = STRING;
		char * curr_var_name_tmp = yystack.l_mark[0].vv.string_val;
		int len = strlen(curr_var_name_tmp);
		yyval.vv.string_exp = malloc(len+1);
		snprintf(yyval.vv.string_exp,len+1, "%s",curr_var_name_tmp);
		yyval.vv._ast = ast_new_float(-2);
	}
break;
case 110:
#line 1219 "grammar/c_syn.y"
	{
		char * curr_var_name_tmp = yystack.l_mark[0].vv.string_val;
		int len = strlen(curr_var_name_tmp);
		yyval.vv.string_exp = malloc(len);
		memcpy(yyval.vv.string_exp,curr_var_name_tmp,len);
		yyval.vv._ast = ast_new_id(curr_var_name_tmp);
		printf("-----1210---------------Variable %s \n",curr_var_name_tmp);


	}
break;
case 111:
#line 1229 "grammar/c_syn.y"
	{

		char * curr_var_name_tmp = yystack.l_mark[0].vv.string_exp;
		int len = strlen(curr_var_name_tmp);
		int len2 = strlen(yystack.l_mark[0].vv.string_val);
		yyval.vv.string_exp = malloc(len+len2+1);
		snprintf(yyval.vv.string_exp,len+len2+1,"%s,%s",yystack.l_mark[-2].vv.string_exp,curr_var_name_tmp);
		free(yystack.l_mark[-2].vv.string_exp);
		yyval.vv._ast = ast_new_operation(AST_LIST,yystack.l_mark[-2].vv._ast,ast_new_id(curr_var_name_tmp)) ;
	}
break;
#line 2210 "y.tab.c"
    }
    yystack.s_mark -= yym;
    yystate = *yystack.s_mark;
    yystack.l_mark -= yym;
    yym = yylhs[yyn];
    if (yystate == 0 && yym == 0)
    {
#if YYDEBUG
        if (yydebug)
            printf("%sdebug: after reduction, shifting from state 0 to\
 state %d\n", YYPREFIX, YYFINAL);
#endif
        yystate = YYFINAL;
        *++yystack.s_mark = YYFINAL;
        *++yystack.l_mark = yyval;
        if (yychar < 0)
        {
            yychar = YYLEX;
            if (yychar < 0) yychar = YYEOF;
#if YYDEBUG
            if (yydebug)
            {
                if ((yys = yyname[YYTRANSLATE(yychar)]) == NULL) yys = yyname[YYUNDFTOKEN];
                printf("%sdebug: state %d, reading %d (%s)\n",
                        YYPREFIX, YYFINAL, yychar, yys);
            }
#endif
        }
        if (yychar == YYEOF) goto yyaccept;
        goto yyloop;
    }
    if (((yyn = yygindex[yym]) != 0) && (yyn += yystate) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == (YYINT) yystate)
        yystate = yytable[yyn];
    else
        yystate = yydgoto[yym];
#if YYDEBUG
    if (yydebug)
        printf("%sdebug: after reduction, shifting from state %d \
to state %d\n", YYPREFIX, *yystack.s_mark, yystate);
#endif
    if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack) == YYENOMEM) goto yyoverflow;
    *++yystack.s_mark = (YYINT) yystate;
    *++yystack.l_mark = yyval;
    goto yyloop;

yyoverflow:
    YYERROR_CALL("yacc stack overflow");

yyabort:
    yyfreestack(&yystack);
    return (1);

yyaccept:
    yyfreestack(&yystack);
    return (0);
}
