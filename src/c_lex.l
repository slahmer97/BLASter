D			[0-9]
L			[a-zA-Z_]
H			[a-fA-F0-9]
E			[Ee][+-]?{D}+
FS			(f|F|l|L)
IS			(u|U|l|L)*

%{
#include <stdio.h>
#include "defs.h"
void comment(void);
int yywrap(void);

%}

%%
"/*"		{comment(); }

"do"		{return(DO); }
"else"		{return(ELSE); }
"float"		{return(FLOAT); }
"for"		{return(FOR); }
"if"		{return(IF); }
"int"		{return(INT); }
"return"	{return(RETURN); }
"void"		{return(VOID); }
"while"		{return(WHILE); }

{L}({L}|{D})*		{return(IDENTIFIER);}

0[xX]{H}+{IS}?		{return(CONSTANT); }
0{D}+{IS}?		    {return(CONSTANT); }
{D}+{IS}?		    {return(CONSTANT); }
L?'(\\.|[^\\'])+'	{return(CONSTANT); }

{D}+{E}{FS}?		{return(CONSTANT); }
{D}*"."{D}+({E})?{FS}?	{return(CONSTANT); }
{D}+"."{D}*({E})?{FS}?	{return(CONSTANT); }

L?\"(\\.|[^\\"])*\"	{return(STRING);}



"&&"			{return(AND_OP); }
"||"			{return(OR_OP); }
"<="			{return(LE_OP); }
">="			{return(GE_OP); }
"=="			{return(EQ_OP); }
"!="			{return(NE_OP); }

";"			{return(';'); }
("{"|"<%")	{return('{'); }
("}"|"%>")	{return('}'); }
","			{return(','); }
"="			{return('='); }
"("			{return('('); }
")"			{return(')'); }
("["|"<:")	{return('['); }
("]"|":>")	{return(']'); }
"."			{return('.'); }
"-"			{return('-'); }
"+"			{return('+'); }
"*"			{return('*'); }
"/"			{return('/'); }

[ \t\v\n\f]		{}
.			{ /* ignore bad characters */ }

%%

int main()
{


yylex();
    return 0;
}
void comment(void)
{
	char c, c1;

loop:
	while ((c = input()) != '*' && c != 0)
		putchar(c);

	if ((c1 = input()) != '/' && c != 0)
	{
		unput(c1);
		goto loop;
	}

	if (c != 0)
		putchar(c1);

}
int yywrap(void)
{
	return 1;
}
