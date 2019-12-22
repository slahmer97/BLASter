%{
	#include<stdio.h>
	#include<defs.h>
	#include<y.tab.h>

	int for_depth_counter_var = 0;
	int direct_declarator_var = 0;
	int current_type_var = -1;
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


		char * string_exp;
	}vv;

}

%token FOR WHILE DO IF ELSE RETURN
%token INT VOID FLOAT
%token CONST_Q //type qualifier  const int...
%token <vv> CONST_INT CONST_FLOAT IDENTIFIER STRING CONST
%token '='
%token '(' ')' ';' '}' '{' ']' '[' '/' '*' '+' '-' '<' '>' '%'
%token AND_OP OR_OP LE_OP GE_OP EQ_OP NE_OP INC DEC LEFT_OP RIGHT_OP
%type <vv> type_specifier declaration_specifiers primary_expression expression identifier_list
%type <vv> pointer direct_declarator declarator init_declarator declaration init_declarator_list initializer initializer_list
//%type <vv> multiplicative_expression additive_expression shift_expression relational_expression equality_expression
//%type <vv> and_expression exclusive_or_expression inclusive_or_expression logical_or_expression logical_and_expression
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
 	assignment_expression {
 		$$.string_exp = malloc(10);
 		memcpy($$.string_exp,"expressio",9);
 	}
	| expression ',' assignment_expression {

		$$.string_exp = malloc(10);
		memcpy($$.string_exp,"expressio",9);

	}
	;

postfix_expression
	: primary_expression {
		printf("\n----%s------------\n",$1.string_exp);
	}
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
	| multiplicative_expression '%' unary_expression
	;

additive_expression
	: multiplicative_expression
	| additive_expression '+' multiplicative_expression
	| additive_expression '-' multiplicative_expression
	;
shift_expression
	: additive_expression
	| shift_expression LEFT_OP additive_expression
	| shift_expression RIGHT_OP additive_expression
	;
relational_expression
	: shift_expression
	| relational_expression '<' shift_expression
	| relational_expression '>' shift_expression
	| relational_expression LE_OP shift_expression
	| relational_expression GE_OP shift_expression
	;

equality_expression
	: relational_expression
	| equality_expression EQ_OP relational_expression
	| equality_expression NE_OP relational_expression
	;
and_expression
	: equality_expression
	| and_expression '&' equality_expression
	;

exclusive_or_expression
	: and_expression
	| exclusive_or_expression '^' and_expression
	;

inclusive_or_expression
	: exclusive_or_expression
	| inclusive_or_expression '|' exclusive_or_expression
	;

logical_and_expression
	: inclusive_or_expression
	| logical_and_expression AND_OP inclusive_or_expression
	;
logical_or_expression
	: logical_and_expression
	| logical_or_expression OR_OP logical_and_expression
	;
//TODO add conditional assignement

assignment_expression :
	logical_and_expression
	| unary_expression '=' assignment_expression
	;

assignment_operator
	: '='
	;
//====================================ASSIGNEMENT-END=================================================================
declaration_list
	: declaration {
		//printf("\n===============\n%s\n================\n",$1.string_exp);
	}
	| declaration_list declaration
	;//=================================================USED
declaration :
	//: declaration_specifiers ';' // long; or int;
	//we have type in declaration_specifiers
	// check if declaration_specifier type fits into all items of init_declarator_list
	{ printf("After type : %d",current_type_var);}
	declaration_specifiers init_declarator_list ';' {
	//restore the current type variable to -1
	 current_type_var = -1;

	//COPY
	//int len1 = strlen($1.string_exp);
	//int len2 = strlen($2.string_exp);
	//$$.string_exp = malloc(len1+len2+1);
	//snprintf($$.string_exp,len1+len2+1, "%sinit_dec_list;",$1.string_exp); TODO $2.string_exp
	//free($1.string_exp);
	//free($2.string_exp);
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


		 //$$.string_exp = $1.string_exp;
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

		//$$.string_exp = malloc(5);
		//snprintf($$.string_exp,4, "void");

	}
	| INT  {
		$$.type = INT;
		//printf("TYPE : %d",$$);

		//$$.string_exp = malloc(4);
		//snprintf($$.string_exp,3, "int");
	}
	| FLOAT {
		$$.type = FLOAT;
		//printf("TYPE : %d",$$);

		//$$.string_exp = malloc(5);
		//snprintf($$.string_exp,4, "float");
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

		//DELETE
		//$$.string_exp = $1.string_exp;
	}
	| init_declarator_list ',' init_declarator {


	//COPY
	/*	int len1 = strlen($1.string_exp);
		int len2 = strlen($3.string_exp);
		$$.string_exp = malloc(len1+len2+2);
		memset($$.string_exp,0,len1+len2+2);
		snprintf($$.string_exp,len1+len2+4, "%s,%s",$1.string_exp,$3.string_exp);
		printf("\nPS : %s\n",$$.string_exp);
		free($1.string_exp);
		free($3.string_exp);
		*/
	}
	;

//DONE
init_declarator
	: declarator {
		for(int l = 0;l<4;l++)
			$$.t[l] = $1.t[l];
		$$.sentry = $1.sentry;
		$$.count_p  = $1.count_p; //TODO maybe 0
		$$.count_m  = $1.count_m;

		printf("\n--TEST------%s-----\n",$1.string_exp);
		$$.string_exp = $1.string_exp;

	}
	| declarator '=' initializer {
		for(int l = 0;l<4;l++){
			$$.t[l] = $1.t[l];
		}
		$$.sentry = $1.sentry;
		$$.count_p  = $1.count_p; //TODO maybe 0
		$$.count_m  = $1.count_m;




		int len1 = strlen($1.string_exp);
		int len2 = strlen($3.string_exp);
		$$.string_exp = malloc(len1+len2+2);
		snprintf($$.string_exp,len1+len2+2, "%s=%s",$1.string_exp,$3.string_exp);
		free($1.string_exp);
		free($3.string_exp);
		printf("\n--TEST2------%s-----\n",$$.string_exp);


	}

	;

//DONE
declarator
	: pointer direct_declarator {
		//printf("SIZE(%d) ",$1+$2);
		for(int l = 0;l<4;l++)
			$$.t[l] = $2.t[l];
		$$.sentry = $2.sentry;
		$$.count_p  = $1.count_p;
		$$.count_m  = $2.count_m;
		$$.string_val = $1.string_val;



		int len1 = strlen($1.string_exp);
		int len2 = strlen($2.string_exp);
		$$.string_exp = malloc(len1+len2+1);
		snprintf($$.string_exp,len1+len2+1, "%s%s",$1.string_exp,$2.string_exp);
		free($1.string_exp);
		free($2.string_exp);



	}
	| direct_declarator {

		for(int l = 0;l<4;l++)
			$$.t[l] = $1.t[l];
		$$.sentry = $1.sentry;
		$$.count_p  = $1.count_p; //TODO maybe 0
		$$.count_m  = $1.count_m;
		//printf("SIZE(%d) ",$1);
	//COPY
		$$.string_exp = $1.string_exp;

	}
	;

// DONE
direct_declarator
	: IDENTIFIER {
		$$.count_p  = 0;
		$$.count_m  = 0;
		direct_declarator_var = 0;
		$$.sentry = $1.sentry;
		$$.string_val = $1.string_val;

		//set is_dec bit for the current variable;
		char * curr_var_name_tmp = $1.string_val;
		if(current_type_var != -1){
		    symbol_p tttt;
		    int rep = lookup_symbol_entry(curr_var_name_tmp,&tttt);
		    if(tttt->is_dec == 1){
			printf("error : Redeclaration of variable %s\tat line : %d\n",curr_var_name_tmp,line_counter+1);
			return -1;
		    }
		    //not yet declared...so set is_dec bit
		    tttt->is_dec = 1;
		}

		int len = strlen(curr_var_name_tmp);
		$$.string_exp = malloc(len+1);
		snprintf($$.string_exp,len+1, "%s",curr_var_name_tmp);

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
		$$.string_val = $1.string_val;



		int len1 = strlen($1.string_exp);
		int len2 = strlen($3.string_val);
		$$.string_exp = malloc(len1+len2+3);
		snprintf($$.string_exp,len1+len2+4, "%s[%s]",$1.string_exp,$3.string_val);
		free($1.string_exp);



        }
        //| direct_declarator '(' ')'

        //| direct_declarator '(' identifier_list ')'


        ;
// DONE
pointer
	: '*'{
		$$.count_p = 1;

		$$.string_exp = malloc(2);
		snprintf($$.string_exp,2,"*");




	}
	//| '*' type_qualifier_list
	| '*' pointer {
	 	$$.count_p = $2.count_p +1;


	 	int len1 = strlen($2.string_exp);
	 	$$.string_exp = malloc(len1+3);
		snprintf($$.string_exp,len1+3,"*%s",$2.string_exp);
		free($2.string_exp);

	}
	;


initializer
	: assignment_expression {
	 	$$.string_exp = malloc(8);
		snprintf($$.string_exp,8, "ass_exp");

	}
	| '{' initializer_list '}' {
		int len1 = strlen($2.string_exp);
		$$.string_exp = malloc(len1+3);
		snprintf($$.string_exp,len1+3, "{%s}",$2.string_exp);
	}
	;
initializer_list
	: initializer {
		$$.string_exp = malloc(11);
		snprintf($$.string_exp,11, "ass_exp_lst");
		//$$.string_exp = malloc(11);
	 	//memcpy($$.string_exp,"initializer",11);
	}
	| initializer_list ',' initializer {
		$$.string_exp = malloc(11);
		snprintf($$.string_exp,11, "ass_exp_lst");
		/*
		int len1 = strlen($1.string_exp);
		int len2 = strlen($3.string_exp);
		$$.string_exp = malloc(len1+len2+1);
		memset($$.string_exp,0,len1+len2+1);
		snprintf($$.string_exp,len1+len2+1, "%s,%s",$1.string_exp,$3.string_exp);
		free($1.string_exp);
		free($3.string_exp);
		*/
	}
	;

//DONE
primary_expression
	: IDENTIFIER {
		$$.type = IDENTIFIER;
		//check if identifier is already declared
		// if we are current_type_var == -1 and trying to reference a IDENTIFIER that doesn't exist == ERROR
		// TODO if current_type_var != -1 then have to check in other side of equality if exist ID = VAR_CURR (check if exist above )
		char * curr_var_name_tmp = $1.string_val;
		if(current_type_var == -1){
		    symbol_p tttt;
		    int rep = lookup_symbol_entry(curr_var_name_tmp,&tttt);
		    if(rep == -1 || tttt->is_dec == 0){
			printf("error : Undeclared variable %s\tat line : %d\n",curr_var_name_tmp,line_counter+1);
			return -1;
		    }
		}

		int len = strlen(curr_var_name_tmp);
		$$.string_exp = malloc(len);
		memcpy($$.string_exp,curr_var_name_tmp,len);

	}
	| CONST_INT {
		$$.type = CONST_INT;


		char * curr_var_name_tmp = $1.string_val;
		int len = strlen(curr_var_name_tmp);
		$$.string_exp = malloc(len);
		memcpy($$.string_exp,curr_var_name_tmp,len);

	}
	| CONST_FLOAT {
		$$.type = CONST_FLOAT;

		char * curr_var_name_tmp = $1.string_val;
		int len = strlen(curr_var_name_tmp);
		$$.string_exp = malloc(len);
		memcpy($$.string_exp,curr_var_name_tmp,len);
	}
	//| STRING {
	//TODO Not implemented yet
	//}
	| '(' expression ')' {

		$$.type = EXPR;

		char * curr_var_name_tmp = $2.string_exp;
		int len = strlen(curr_var_name_tmp);
		$$.string_exp = malloc(len+4);
		snprintf($$.string_exp,len+4, "(%s)",$2.string_exp);
	}
	;


//DONE
identifier_list
	: IDENTIFIER {
		char * curr_var_name_tmp = $1.string_val;
		int len = strlen(curr_var_name_tmp);
		$$.string_exp = malloc(len);
		memcpy($$.string_exp,curr_var_name_tmp,len);
	}
	| identifier_list ',' IDENTIFIER {

		char * curr_var_name_tmp = $3.string_exp;
		int len = strlen(curr_var_name_tmp);
		int len2 = strlen($3.string_val);
		$$.string_exp = malloc(len+len2+1);
		snprintf($$.string_exp,len+len2+1,"%s,%s",$1.string_exp,curr_var_name_tmp);
		free($1.string_exp);
	}
	;
%%

int yyerror(const char *str)
{
	printf("error : %s\tline : %d\n",str,line_counter+1);
	return -1;
}

int yywrap()
{
return 1;
}