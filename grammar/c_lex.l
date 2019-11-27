D			[0-9]
L			[a-zA-Z_]
H			[a-fA-F0-9]
E			[Ee][+-]?{D}+
FS			(f|F|l|L)
IS			(u|U|l|L)*
%{
	#include<stdlib.h>
	#include<string.h>
    #include "y.tab.h"
	#include "defs.h"

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

"const" {
    printf("CONST_Q ");
    return (CONST_Q);
}

"void" {
    return(VOID);
}

"while" {
    return(WHILE);
}

{L}({L}|{D})* {
    printf("ID ");
    symbol id_s;
    copy_name(&id_s,yytext,strlen(yytext));
    int ret = add_symbol_entry(&id_s);
    return(IDENTIFIER);
}

0[xX]{H}+{IS}? {
    //TODO Hex to int
    printf("CONST ");
    return(CONST);
}

0{D}+{IS}? {
    //TODO unsigned long
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
    printf("CONST ");
    return(CONST);
}

{D}+"."{D}*({E})?{FS}? {
    //TODO float con = to_float(yytext);
    //TODOyyval = con;
    printf("CONST ");
    return(CONST);
}

L?\"(\\.|[^\\"])*\"	{
    printf("STRING ");
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
    printf("END_INSRT\n");
    return(';');
}

("{"|"<%") {
    printf("{ ");
    return('{');
}

("}"|"%>") {
    printf("} ");
    return('}');
}

"," {
    printf(", ");
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
    printf("PTR ");
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
	while ((c = input()) != '*' && c != 0);
		//putchar(c);

	if ((c1 = input()) != '/' && c != 0)
	{
		unput(c1);
		goto loop;
	}

	//if (c != 0)
		//putchar(c1);

}
