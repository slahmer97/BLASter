/* A Bison parser, made by GNU Bison 3.3.2.  */

/* Bison interface for Yacc-like parsers in C

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

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

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
#line 13 "grammar/c_syn.y" /* yacc.c:1921  */

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


#line 141 "y.tab.h" /* yacc.c:1921  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
