%{
	#include<stdio.h>
	#include<defs.h>
	#include<y.tab.h>

%}

%token FOR WHILE DO IF ELSE RETURN
%token INT VOID FLOAT
%token CONST STRING
%token '='
%token IDENTIFIER
%token '(' ')' ';' '}' '{' ']' '['
%token AND_OP OR_OP LE_OP GE_OP EQ_OP NE_OP

%start declaration_list
%%


declaration_list
	: declaration
	| declaration_list declaration
	;//=================================================USED
declaration
	: declaration_specifiers ';'
	| declaration_specifiers init_declarator_list ';'
	; //==========================================================USED

declaration_specifiers
	:
	type_specifier
	| type_specifier declaration_specifiers
	;
//| type_qualifier
//| type_qualifier declaration_specifiers
//| storage_class_specifier
//| storage_class_specifier declaration_specifiers
//=======================================================USED
type_specifier
	: VOID
	| INT
	| FLOAT
	;

init_declarator_list
	: init_declarator
	| init_declarator_list ',' init_declarator
	;

init_declarator
	: declarator
	;
//| declarator '=' initializer



declarator
	: pointer direct_declarator
	| direct_declarator
	;

direct_declarator
	: IDENTIFIER
        | direct_declarator '[' ']'
        ;
//| direct_declarator '[' constant_expression ']'
//| '(' declarator ')'
//| direct_declarator '(' parameter_type_list ')'
//| direct_declarator '(' identifier_list ')'
//| direct_declarator '(' ')'

pointer
	: '*'
	| '*' type_qualifier_list
	| '*' pointer
	| '*' type_qualifier_list pointer
	;
type_qualifier_list
	: type_qualifier
	| type_qualifier_list type_qualifier
	;
type_qualifier
	: CONST
	;






%%

int yyerror(const char *str)
{
	printf("error : %s\n",str);
	return -1;
}

int yywrap()
{
return 1;
}