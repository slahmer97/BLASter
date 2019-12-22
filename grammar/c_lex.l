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
    yylval.vv.string_val = strdup(yytext);
    int ret = add_symbol_entry(&id_s);
    symbol_p tmp = 0;
    int rep = lookup_symbol_entry(yytext,&tmp);
    if(rep != 1)
            printf("ERROR_ID ");
    yylval.vv.sentry = tmp;
    return(IDENTIFIER);
}

0{D}+{IS}? {
    //TODO unsigned long
    yylval.vv.string_val = strdup(yytext);
    printf("CONST_UNSIGNED ");
    return(CONST_INT);
}

{D}+{IS}? {
    yylval.vv.val = atoi(yytext);
    printf("CONST_D_INT_1 ");
    yylval.vv.string_val = strdup(yytext);

    return(CONST_INT);
}

L?'(\\.|[^\\'])+' {
    printf("CONST ");
    return(CONST);
    yylval.vv.string_val = strdup(yytext);
}

{D}+{E}{FS}? {
    yylval.vv.val = atoi(yytext);
    printf("CONST_INT_2 ");
    yylval.vv.string_val = strdup(yytext);
    return(CONST);
}

{D}*"."{D}+({E})?{FS}? {
    printf("CONST_D.D.FS ");
    yylval.vv.string_val = strdup(yytext);
    return(CONST_FLOAT);
}

{D}+"."{D}*({E})?{FS}? {
    //TODO float con = to_float( yytext );
    //TODO yyval = con;
    yylval.vv.string_val = strdup(yytext);
    printf("CONST_D.D.E.FS ");
    return(CONST_FLOAT);
}

L?\"(\\.|[^\\"])*\"	{
    printf("STRING ");
    yylval.vv.string_val = strdup(yytext);
    return(STRING);
}

"++" {
    printf("++ ");

    return (INC);
}
"--" {
    printf("--");

    return (DEC);
}
"&&" {
    printf("&& ");
    return(AND_OP);
}

"||" {
    printf("|| ");
    return(OR_OP);
}

"<=" {
    printf("<= ");
    return(LE_OP);
}
"<" {
    printf("< ");
    return('<');
}
">" {
    printf("> ");
    return('>');
}
">=" {
    printf(">= ");
    return(GE_OP);
}
"<<" {
    printf("<< ");
    return(LEFT_OP);
}
">>" {
    printf(">> ");
    return(RIGHT_OP);
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
    printf("= ");
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

"%"	{
    printf("% ");
    return('%');
}


"-"	{
    printf("- ");
    return('-');
}

"+"	{
    printf("+ ");
    return('+');
}

"*"	{
    printf("* ");
    return('*');
}

"/" {
    printf("/ ");
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
