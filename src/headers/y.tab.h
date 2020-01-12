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
#ifdef YYSTYPE
#undef  YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
#endif
#ifndef YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
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
extern YYSTYPE yylval;
