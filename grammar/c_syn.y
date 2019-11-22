%{
	#include<stdio.h>
	#include<defs.h>
	#include<y.tab.h>

%}

%token FOR WHILE DO IF ELSE RETURN
%token INT VOID FLOAT
%token CONST_Q //type qualifier  const int...
%token CONST STRING IDENTIFIER //const = 10 ...etc
%token '='
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
	| type_specifier declaration_specifiers // int ..
	| type_qualifier declaration_specifiers //const int ...
	;
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
	| declarator '=' initializer
	;

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
	: CONST_Q
	;


initializer
	:primary_expression
	//: assignment_expression TODO change later
	| '{' initializer_list '}'
	//| '{' initializer_list ',' '}'
	;
initializer_list
	: initializer
	| initializer_list ',' initializer
	;
primary_expression
	: IDENTIFIER
	| CONST
	| STRING
	//| '(' expression ')'
	;





%%

int yyerror(const char *str)
{
	printf("error : %s\tline : %d\n",str,line_counter);
	return -1;
}

int yywrap()
{
return 1;
}