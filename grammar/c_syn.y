%{
	#include<stdio.h>
	#include<defs.h>
	#include<y.tab.h>

%}
%union{
	int type;


	int count;
}

%token FOR WHILE DO IF ELSE RETURN
%token INT VOID FLOAT
%token CONST_Q //type qualifier  const int...
%token CONST STRING IDENTIFIER //const = 10 ...etc
%token '='
%token '(' ')' ';' '}' '{' ']' '['
%token AND_OP OR_OP LE_OP GE_OP EQ_OP NE_OP
%type <type> type_specifier declaration_specifiers
%type <count> pointer direct_declarator
%start declaration_list
%%


declaration_list
	: declaration
	| declaration_list declaration
	;//=================================================USED
declaration
	: declaration_specifiers ';'
	//we have type in declaration_specifiers
	// check if declaration_specifier type fits into all items of init_declarator_list
	| declaration_specifiers init_declarator_list ';'
	; //==========================================================USED

declaration_specifiers
	:
	type_specifier {
	 $$ = $1;
	 //TODO check composed types=====!
	}
	//| type_specifier declaration_specifiers // int ..
	//| type_qualifier declaration_specifiers //const int ...
	;
//| storage_class_specifier
//| storage_class_specifier declaration_specifiers
//=======================================================USED
type_specifier
	: VOID {
	$$ = VOID;
	printf("TYPE : %d",$$);

	}
	| INT  {
	$$ = INT;
	printf("TYPE : %d",$$);
	}
	| FLOAT {

	$$ = FLOAT;
	printf("TYPE : %d",$$);
	}
	;

init_declarator_list
	: init_declarator
	| init_declarator_list ',' init_declarator
	;

init_declarator
	: declarator {

	}
	| declarator '=' initializer {

	}
	;

declarator
	: pointer direct_declarator {
		printf("SIZE(%d) ",$1+$2);
	}
	| direct_declarator {
		printf("SIZE(%d) ",$1);
	}
	;

direct_declarator
	: IDENTIFIER {
		$$  = 0;
		//TODO
	}
        | direct_declarator '[' ']' {
         	$$ = $1 +1;
        	// TODO maybe add the array size
        }
        | direct_declarator '[' CONST ']' {
         	$$ = $1 +1;
         	// TODO maybe add the array size
        }
        ;
//| direct_declarator '[' constant_expression ']'
//| '(' declarator ')'
//| direct_declarator '(' parameter_type_list ')'
//| direct_declarator '(' identifier_list ')'
//| direct_declarator '(' ')'

pointer
	: '*'{
	$$ = 1;
	}
	//| '*' type_qualifier_list
	| '*' pointer {
	 $$ = $2 +1;
	}
	//| '*' type_qualifier_list pointer
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
//type_qualifier_list
//	: type_qualifier
//	| type_qualifier_list type_qualifier
//	;
//type_qualifier
//	: CONST_Q
//	;





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