D			[0-9]
L			[a-zA-Z_]
H			[a-fA-F0-9]
E			[Ee][+-]?{D}+
FS			(f|F|l|L)
IS			(u|U|l|L)*
%{
	#include<stdlib.h>
    #include "y.tab.h"
	#include "defs.h"
	//extern int yylval;

	void comment(void);
%}

%%
"/*" {
    comment();
}

"do" {
    return(DO);
}

"else" {

    return(ELSE);

}

"float" {
    return(FLOAT);
}

"for" {
    return(FOR);
 }

"if" {
    return(IF);
}

"int" {
    printf("INT ");
    return(INT);
}

"return" {
    return(RETURN);
}

"void" {
    return(VOID);
}

"while" {
    return(WHILE);
}

{L}({L}|{D})* {
    printf("ID ");
    return(IDENTIFIER);
}

0[xX]{H}+{IS}? {
    printf("CONST ");
    return(CONST);
}

0{D}+{IS}? {
    printf("CONST ");
    return(CONST);
}

{D}+{IS}? {
    printf("CONST ");
    return(CONST);
}

L?'(\\.|[^\\'])+' {
    printf("CONST ");
    return(CONST);
}

{D}+{E}{FS}? {
    printf("CONST ");
    return(CONST);
}

{D}*"."{D}+({E})?{FS}? {
    return(CONST);
}

{D}+"."{D}*({E})?{FS}? {
    printf("CONST ");
    return(CONST);
}

L?\"(\\.|[^\\"])*\"	{
    return(STRING);
}

"&&" {
    return(AND_OP);
}

"||" {
    return(OR_OP);
}

"<=" {
    return(LE_OP);
}

">=" {
    return(GE_OP);
}

"==" {
    return(EQ_OP);
}
"!=" {
    return(NE_OP);
}

";" {
    printf("END_INSRT ");
    return(';');
}

("{"|"<%") {
    return('{');
}

("}"|"%>") {
    return('}');
}

"," {
    return(',');
}

"="	{
    printf("EQ ");
    return('=');
}

"("	{
    return('(');
}

")"	{
    return(')');
}

("["|"<:") {
    printf("[ ");
    return('[');
}

("]"|":>") {
    printf("] ");
    return(']');
}

"."	{
    return('.');
}

"-"	{
    return('-');
}

"+"	{
    return('+');
}

"*"	{
    return('*');
}

"/" {
    return('/');
}
"!" {
    return ('!');
}

[ \t\v\f]+ {

}
[\n] {
line_counter++;
}
.			{ printf("char was not recognized!\n"); }

%%


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
