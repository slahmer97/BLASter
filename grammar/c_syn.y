%{
	#include<stdio.h>
	#include<defs.h>
	#include<y.tab.h>

	int for_depth_counter_var = 0;
	int direct_declarator_var = 0;
	int current_type_var = 0;
%}
%union{
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
	}vv;

}

%token FOR WHILE DO IF ELSE RETURN
%token INT VOID FLOAT
%token CONST_Q //type qualifier  const int...
%token <vv> CONST_INT CONST_FLOAT IDENTIFIER STRING CONST
%token '='
%token '(' ')' ';' '}' '{' ']' '[' '/' '*' '+' '-' '<' '>'
%token AND_OP OR_OP LE_OP GE_OP EQ_OP NE_OP INC DEC
%type <vv> type_specifier declaration_specifiers primary_expression
%type <vv> pointer direct_declarator declarator init_declarator
%start translation_unit
%%

//==================================START-EXTERNAL======================================================================
translation_unit
	: compound_statement
	| translation_unit compound_statement
	;
compound_statement
	: '{' '}'
	| '{' statement_list '}'
	| '{' declaration_list '}'
	| '{' declaration_list statement_list '}'
	;

//=====================================EXTERNAL-END=====================================================================

//=====================================statement-START==================================================================

statement_list
	: statement
	| statement_list statement
statement
	: //labeled_statement
	  compound_statement
	| expression_statement
	| selection_statement
	| iteration_statement
	;

expression_statement
	: ';'
	| expression ';'
	;

//=======================================Statement-END==================================================================

//=======================================LOOP-Conditional-EXR================================================================
selection_statement
	: IF '(' expression ')' compound_statement
	| IF '(' expression ')' compound_statement ELSE compound_statement

iteration_statement :
	 WHILE {printf("START-WHILE\n ");}'(' expression ')' compound_statement {printf("END-WHILE\n ");}

	| FOR {printf("for ");}'(' expression_statement expression_statement expression')' compound_statement {printf("END-FOR\n ");}

//=======================================CONDITIONAL-EXPR-END===========================================================

//==================================START-ASSIGNEMENT===================================================================
expression:
 	assignment_expression
	| expression ',' assignment_expression
	;

postfix_expression
	: primary_expression
	| postfix_expression '[' expression ']'
	| postfix_expression '(' ')'
	| postfix_expression INC
	| postfix_expression DEC

unary_expression
	: postfix_expression
	| INC unary_expression
	| DEC unary_expression
	;


multiplicative_expression
	: unary_expression
	| multiplicative_expression '*' unary_expression
	| multiplicative_expression '/' unary_expression
	//| multiplicative_expression '%' unary_expression
	;

additive_expression
	: multiplicative_expression
	| additive_expression '+' multiplicative_expression
	| additive_expression '-' multiplicative_expression
	;

assignment_expression :
	additive_expression
	| unary_expression '=' assignment_expression
	;

assignment_operator
	: '='
	;
//====================================ASSIGNEMENT-END=================================================================
declaration_list
	: declaration
	| declaration_list declaration
	;//=================================================USED
declaration :
	//: declaration_specifiers ';' // long; or int;
	//we have type in declaration_specifiers
	// check if declaration_specifier type fits into all items of init_declarator_list
	{ printf("After type : %d",current_type_var);}
	declaration_specifiers init_declarator_list ';' {
	//restore the current type variable to -1
	 current_type_var = 0;
	}
	; //==========================================================USED

declaration_specifiers
	:
	type_specifier {
		 //$$.type = $1.type; INT or FLAT ...
		 //store the current type in a global variable....TODO
		 //TODO check composed types=====!
		 current_type_var = $1.type;
		 printf("current type : %d",current_type_var);
	}
	//| type_specifier declaration_specifiers // int ..
	//| type_qualifier declaration_specifiers //const int ...
	;
//| storage_class_specifier
//| storage_class_specifier declaration_specifiers
//=======================================================USED
type_specifier
	: VOID {
		$$.type = VOID;
		//printf("TYPE : %d",$$);
	}
	| INT  {
		$$.type = INT;
		//printf("TYPE : %d",$$);
	}
	| FLOAT {
		$$.type = FLOAT;
		//printf("TYPE : %d",$$);
	}
	;
init_declarator_list
	: init_declarator {
		symbol_p varp = (symbol_p) $1.sentry;
		int countp = $1.count_p; //TODO maybe 0
		int countm = $1.count_m;
		if(countp > 0 || countm > 0){
			varp->type = VAR_ARR;
			varp->arr.dimention_m = countm;
			varp->arr.dimention_p = countp;
			for(int pp = 0;pp<4;pp++)
				varp->arr.size[pp] = $1.t[pp];

		}


	}
	| init_declarator_list ',' init_declarator
	;
init_declarator
	: declarator {
		for(int l = 0;l<4;l++)
			$$.t[l] = $1.t[l];
		$$.sentry = $1.sentry;
		$$.count_p  = $1.count_p; //TODO maybe 0
		$$.count_m  = $1.count_m;
	}
	| declarator '=' initializer {
		for(int l = 0;l<4;l++){
			$$.t[l] = $1.t[l];
		}
		$$.sentry = $1.sentry;
		$$.count_p  = $1.count_p; //TODO maybe 0
		$$.count_m  = $1.count_m;
	}
	;
declarator
	: pointer direct_declarator {
		//printf("SIZE(%d) ",$1+$2);
		for(int l = 0;l<4;l++)
			$$.t[l] = $2.t[l];
		$$.sentry = $2.sentry;
		$$.count_p  = $1.count_p;
		$$.count_m  = $2.count_m;

	}
	| direct_declarator {
		for(int l = 0;l<4;l++)
			$$.t[l] = $1.t[l];
		$$.sentry = $1.sentry;
		$$.count_p  = $1.count_p; //TODO maybe 0
		$$.count_m  = $1.count_m;
		//printf("SIZE(%d) ",$1);

	}
	;
direct_declarator
	: IDENTIFIER {
		$$.count_p  = 0;
		$$.count_m  = 0;
		direct_declarator_var = 0;
		$$.sentry = $1.sentry;
	}
        //| direct_declarator '[' ']' {
        // 	$$.count_p = $1.count_p +1;
       // 	// TODO maybe add the array size
        //}
        | direct_declarator '[' CONST_INT ']' {
         	//$$ = $1 +1;
        	$$.t[direct_declarator_var] = $3.val;
         	direct_declarator_var++;
		$$.count_m = direct_declarator_var;

        }
        | direct_declarator '(' ')'

        | direct_declarator '(' identifier_list ')'


        ;

pointer
	: '*'{
		$$.count_p = 1;
	}
	//| '*' type_qualifier_list
	| '*' pointer {
	 	$$.count_p = $2.count_p +1;
	}
	//| '*' type_qualifier_list pointer
	;


initializer
	: assignment_expression
	| '{' initializer_list '}'
	| '{' initializer_list ',' '}'
	;
initializer_list
	: initializer
	| initializer_list ',' initializer
	;
primary_expression
	: IDENTIFIER {
		$$.type = IDENTIFIER;

	}
	| CONST_INT {
		$$.type = CONST_INT;

	}
	| CONST_FLOAT {
		$$.type = CONST_FLOAT;
	}
	//| STRING {
	//TODO Not implemented yet
	//}
	| '(' expression ')' {
		$$.type = EXPR;
	}
	;

identifier_list
	: IDENTIFIER
	| identifier_list ',' IDENTIFIER
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