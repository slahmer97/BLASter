D			[0-9]
L			[a-zA-Z_]
H			[a-fA-F0-9]
E			[Ee][+-]?{D}+
FS			(f|F|l|L)
IS			(u|U|l|L)*
%{
	#include<stdlib.h>
	#include<string.h>
    #include "headers/y.tab.h"
	#include "headers/defs.h"
 	void comment(void);
 	char* print_detect(void);
%}

%%

"/*" {
    comment();
}
"break" {
    return(BREAK);
}
"goto" {
    return(GOTO);
}
"#" {
    return(HASH);
}
"include" {
    return(INCLUDE);
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
    return(INT);
}

"return" {
    return(RETURN);
}

"const" {
    return (CONST_Q);
}

"void" {
    return(VOID);
}

"while" {
    return(WHILE);
}

{L}({L}|{D})* {
    //printf("ID ");
    symbol id_s;
    copy_name(&id_s,yytext,strlen(yytext));
    yylval.vv.string_val = strdup(yytext);
    add_symbol_entry(&id_s);
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
    return(CONST_INT);
}

{D}+{IS}? {
    yylval.vv.val = atoi(yytext);
    yylval.vv.string_val = strdup(yytext);

    return(CONST_INT);
}

L?'(\\.|[^\\'])+' {
    return(CONST);
    yylval.vv.string_val = strdup(yytext);
}

{D}+{E}{FS}? {
    yylval.vv.val = atoi(yytext);
    yylval.vv.string_val = strdup(yytext);
    return(CONST);
}

{D}*"."{D}+({E})?{FS}? {
    yylval.vv.string_val = strdup(yytext);
    return(CONST_FLOAT);
}

{D}+"."{D}*({E})?{FS}? {

    yylval.vv.string_val = strdup(yytext);
    return(CONST_FLOAT);
}

L?\"(\\.|[^\\"])*\"	{
    yylval.vv.string_val = strdup(yytext);
    return(STRING);
}

"++" {

    return (INC);
}
"--" {

    return (DEC);
}
"&&" {
    return(AND_OP);
}

"||" {
    printf("|| ");
    return(OR_OP);
}

"<=" {
    return(LE_OP);
}
"<" {
    return('<');
}
">" {
    return('>');
}
">=" {
    return(GE_OP);
}
"<<" {
    return(LEFT_OP);
}
">>" {
    return(RIGHT_OP);
}

"==" {
    return(EQ_OP);
}
"!=" {
    return(NE_OP);
}

";" {
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
    return('=');
}

"("	{
    return('(');
}

")"	{
    return(')');
}

("["|"<:") {
    return('[');
}

("]"|":>") {
    return(']');
}

"."	{
    return('.');
}

"%"	{
    return('%');
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
"printf(\"" {

    yylval.vv.string_val = print_detect();
    return PRINTF;
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

	if ((c1 = input()) != '/' && c != 0)
	{
		unput(c1);
		goto loop;
	}


}


char* print_detect(void){
	char c, c1;
    char * ret = malloc(100);
    ret[0] = 'p';ret[1] = 'r';
    ret[2] = 'i';ret[3] = 'n';
    ret[4] = 't';ret[5] = 'f';
    ret[6] = '(';ret[7] = '"';
    int i=8;
loop:
	while ((c = input()) != ')' && c != 0){
	    ret[i++] = c;
	}

	if ((c1 = input()) != ';' && c != 0)
	{
		unput(c1);
		goto loop;
	}
	ret[i++] = ')';
	ret[i++] = ';';
	ret[i] = 0;

	return ret;
}