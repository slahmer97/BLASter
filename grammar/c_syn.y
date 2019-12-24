%{
	#include<stdio.h>
	#include "headers/defs.h"
	#include "headers/y.tab.h"

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
%type <vv> type_specifier declaration_specifiers primary_expression expression  compound_statement statement_list declaration_list identifier_list
%type <vv> selection_statement pointer direct_declarator declarator init_declarator declaration init_declarator_list initializer initializer_list statement postfix_expression
%type <vv> iteration_statement multiplicative_expression additive_expression shift_expression relational_expression equality_expression unary_expression assignment_expression
%type <vv> expression_statement and_expression exclusive_or_expression inclusive_or_expression logical_or_expression logical_and_expression assignment_operator
%start translation_unit
%%

//==================================START-EXTERNAL======================================================================
translation_unit
	: compound_statement {
		printf("-->\n%s\n",$1.string_exp);
	}
	//| translation_unit compound_statement
	;
compound_statement
	: '{' '}' {
		$$.string_exp = malloc(4);
		snprintf($$.string_exp,4, "{ }");
	}
	| '{' statement_list '}' {
		int len1 = strlen($2.string_exp);
		$$.string_exp = malloc(len1+3);
		snprintf($$.string_exp,len1+3, "{%s}",$2.string_exp);
		free($2.string_exp);
	}
	| '{' declaration_list '}' {
		int len1 = strlen($2.string_exp);
		$$.string_exp = malloc(len1+3);
		snprintf($$.string_exp,len1+3, "{%s}",$2.string_exp);
		free($2.string_exp);
	}
	| '{' declaration_list statement_list '}' {
		int len1 = strlen($2.string_exp);
		int len2 = strlen($3.string_exp);
		$$.string_exp = malloc(len1+len2+6);
		snprintf($$.string_exp,len1+len2+6, "{\n%s\n%s\n}",$2.string_exp,$3.string_exp);
		free($2.string_exp);
		free($3.string_exp);

	}
	;

//=====================================EXTERNAL-END=====================================================================

//=====================================statement-START==================================================================

statement_list
	: statement {
		   $$.string_exp = $1.string_exp;
	}
	| statement_list statement {
                int len1 = strlen($1.string_exp);
		int len2 = strlen($2.string_exp);
		$$.string_exp = malloc(len1+len2+2);
		snprintf($$.string_exp,len1+len2+2, "%s\n%s",$1.string_exp,$2.string_exp);
		free($1.string_exp);
		free($2.string_exp);
	}
statement
	: //labeled_statement
	  compound_statement {
	  	 $$.string_exp = $1.string_exp;
	  }
	| expression_statement {
	 	$$.string_exp = $1.string_exp;
	}
	| selection_statement {

		$$.string_exp = $1.string_exp;
	}
	| iteration_statement {
			$$.string_exp = $1.string_exp;
	}
	;
expression_statement
	: ';' {
		$$.string_exp = malloc(2);
		snprintf($$.string_exp,2, ";");

	}
	| expression ';' {
			int len = strlen($1.string_exp);
			$$.string_exp = malloc(len+2);
        		snprintf($$.string_exp,len+2, "%s;",$1.string_exp);
			//printf("\n---------TEST777------ | %s |---------\n",$1.string_exp);
			free($1.string_exp);
	}
	;

//=======================================Statement-END==================================================================

//=======================================LOOP-Conditional-EXR================================================================
selection_statement
	: IF '(' expression ')' compound_statement {
		int len1 = strlen($3.string_exp);
		int len2 = strlen($5.string_exp);
		$$.string_exp = malloc(len1+len2+6);
		snprintf($$.string_exp,len1+len2+6, "if(%s)\n%s",$3.string_exp,$5.string_exp);
		free($3.string_exp);
		free($5.string_exp);
		printf("\n---------TEST-IF--- |%s|\n",$$.string_exp );
	}
	| IF '(' expression ')' compound_statement ELSE compound_statement {
		int len1 = strlen($3.string_exp);
		int len2 = strlen($5.string_exp);
		int len3 = strlen($7.string_exp);
		$$.string_exp = malloc(len1+len2+len3+11);
		snprintf($$.string_exp,len1+len2+len3+11, "if(%s)\n%s\nelse%s",$3.string_exp,$5.string_exp,$7.string_exp);
		free($3.string_exp);
		free($5.string_exp);
		free($7.string_exp);
		printf("\n---------TEST-IF-ELSE--- |\n%s\n|\n",$$.string_exp );

	}
iteration_statement :
	 WHILE {printf("START-WHILE\n ");}'(' expression ')' compound_statement {printf("END-WHILE\n ");}

	| iter_counter FOR '(' expression_statement expression_statement expression')' compound_statement {
		printf("\n[+] S->for_depth_counter_var : %d\n",for_depth_counter_var);

		int len1 = strlen($4.string_exp);
		int len2 = strlen($5.string_exp);
		int len3 = strlen($6.string_exp);
		int len4 = strlen($8.string_exp);
		char *result = malloc(len1+len2+len3+len4+9);
		snprintf(result,len1+len2+len3+len4+9, "for(%s %s %s)\n%s",$4.string_exp,$5.string_exp,$6.string_exp,$8.string_exp);
		if(for_depth_counter_var == 1){
			printf("\n--------------Optimizer Call------------\n");
			   FILE *fptr;
                           fptr = fopen(OPTIMIZER_REQUEST,"w");
                           if(fptr == NULL)
                           {
                              perror("File open error!");
                              exit(1);
                           }
                           fprintf(fptr,"%s",result);
                           fclose(fptr);
			   sem_post(globalData.sem_prod_cons);
			   printf("\n--------------BLAST waitting------------\n");
			   sem_wait(globalData.sem_symbol);
			   printf("\n--------------BLAST GOT RESULT---------\n");
		}

		$$.string_exp = result;

		for_depth_counter_var--;
		printf("\n[+] S->for_depth_counter_var : %d\n",for_depth_counter_var);

	}
iter_counter : {for_depth_counter_var++;}
//=======================================CONDITIONAL-EXPR-END===========================================================

//==================================START-ASSIGNEMENT===================================================================
expression:
 	assignment_expression {
 		$$.string_exp = $1.string_exp;
 		//printf("\n---------TEST145--- |%s|\n",$$.string_exp );
 	}
	| expression ',' assignment_expression {

		int len1 = strlen($1.string_exp);
		int len2 = strlen($3.string_exp);
		$$.string_exp = malloc(len1+len2+2);
		snprintf($$.string_exp,len1+len2+2, "%s,%s",$1.string_exp,$3.string_exp);
		free($1.string_exp);
		free($3.string_exp);
		//printf("\n---------TEST145+1--- |%s|\n",$$.string_exp );
	}
	;
postfix_expression
	: primary_expression {
		$$.string_exp = $1.string_exp;
		//printf("\n---TEST1-%s------------\n",$$.string_exp);
	}
	| postfix_expression '[' expression ']' {
		int len1 = strlen($1.string_exp);
		int len2 = strlen($3.string_exp);
		$$.string_exp = malloc(len1+len2+3);
		snprintf($$.string_exp,len1+len2+3, "%s[%s]",$1.string_exp,$3.string_exp);
		free($1.string_exp);
		free($3.string_exp);
	}
	| postfix_expression '(' ')' {
		int len1 = strlen($1.string_exp);
		$$.string_exp = malloc(len1+3);
		snprintf($$.string_exp,len1+3, "%s()",$1.string_exp);
		free($1.string_exp);
	}
	| postfix_expression INC {
		int len1 = strlen($1.string_exp);
		$$.string_exp = malloc(len1+3);
		snprintf($$.string_exp,len1+3, "%s++",$1.string_exp);
		free($1.string_exp);
	}
	| postfix_expression DEC {
		int len1 = strlen($1.string_exp);
		$$.string_exp = malloc(len1+3);
		snprintf($$.string_exp,len1+3, "%s--",$1.string_exp);
		free($1.string_exp);
	}

unary_expression
	: postfix_expression {
		$$.string_exp = $1.string_exp;
		//printf("\n--------TEST999----| %s |----\n",$$.string_exp);
	}
	| INC unary_expression {
		int len2 = strlen($2.string_exp);
		$$.string_exp = malloc(len2+3);
		snprintf($$.string_exp,len2+3, "++%s",$2.string_exp);
		free($2.string_exp);
	}
	| DEC unary_expression {
		int len2 = strlen($2.string_exp);
		$$.string_exp = malloc(len2+3);
		snprintf($$.string_exp,len2+3, "--%s",$2.string_exp);
		free($2.string_exp);
	}
	;
multiplicative_expression
	: unary_expression {
		$$.string_exp = $1.string_exp;
		//printf("\n---TEST10---%s\n",$$.string_exp);
	}
	| multiplicative_expression '*' unary_expression {


		int len1 = strlen($1.string_exp);
		int len2 = strlen($3.string_exp);
		$$.string_exp = malloc(len1+len2+2);
		snprintf($$.string_exp,len1+len2+2, "%s*%s",$1.string_exp,$3.string_exp);
		free($1.string_exp);
		free($3.string_exp);

	}
	| multiplicative_expression '/' unary_expression {

			int len1 = strlen($1.string_exp);
			int len2 = strlen($3.string_exp);
			$$.string_exp = malloc(len1+len2+2);
			snprintf($$.string_exp,len1+len2+2, "%s/%s",$1.string_exp,$3.string_exp);
			free($1.string_exp);
			free($3.string_exp);

	}
	| multiplicative_expression '%' unary_expression {

			int len1 = strlen($1.string_exp);
			int len2 = strlen($3.string_exp);
			$$.string_exp = malloc(len1+len2+4);
			snprintf($$.string_exp,len1+len2+4, "%s%%%s",$1.string_exp,$3.string_exp);
			free($1.string_exp);
			free($3.string_exp);

	}
	;
additive_expression
	: multiplicative_expression {

		$$.string_exp = $1.string_exp;
	}
	| additive_expression '+' multiplicative_expression {

		int len1 = strlen($1.string_exp);
		int len2 = strlen($3.string_exp);
		$$.string_exp = malloc(len1+len2+2);
		snprintf($$.string_exp,len1+len2+2, "%s+%s",$1.string_exp,$3.string_exp);
		free($1.string_exp);
		free($3.string_exp);
	}
	| additive_expression '-' multiplicative_expression {

		int len1 = strlen($1.string_exp);
		int len2 = strlen($3.string_exp);
		$$.string_exp = malloc(len1+len2+2);
		snprintf($$.string_exp,len1+len2+2, "%s-%s",$1.string_exp,$3.string_exp);
		free($1.string_exp);
		free($3.string_exp);
	}
	;
shift_expression
	: additive_expression {

		$$.string_exp = $1.string_exp;
	}
	| shift_expression LEFT_OP additive_expression {
		int len1 = strlen($1.string_exp);
		int len2 = strlen($3.string_exp);
		$$.string_exp = malloc(len1+len2+3);
		snprintf($$.string_exp,len1+len2+3, "%s<<%s",$1.string_exp,$3.string_exp);
		free($1.string_exp);
		free($3.string_exp);
	}
	| shift_expression RIGHT_OP additive_expression {
		int len1 = strlen($1.string_exp);
		int len2 = strlen($3.string_exp);
		$$.string_exp = malloc(len1+len2+3);
		snprintf($$.string_exp,len1+len2+3, "%s>>%s",$1.string_exp,$3.string_exp);
		free($1.string_exp);
		free($3.string_exp);
	}
	;
relational_expression
	: shift_expression{

		$$.string_exp = $1.string_exp;
	}
	| relational_expression '<' shift_expression {
		int len1 = strlen($1.string_exp);
		int len2 = strlen($3.string_exp);
		$$.string_exp = malloc(len1+len2+2);
		snprintf($$.string_exp,len1+len2+2, "%s<%s",$1.string_exp,$3.string_exp);
		free($1.string_exp);
		free($3.string_exp);
	}
	| relational_expression '>' shift_expression {
		int len1 = strlen($1.string_exp);
		int len2 = strlen($3.string_exp);
		$$.string_exp = malloc(len1+len2+2);
		snprintf($$.string_exp,len1+len2+2, "%s>%s",$1.string_exp,$3.string_exp);
		free($1.string_exp);
		free($3.string_exp);
	}
	| relational_expression LE_OP shift_expression{
		int len1 = strlen($1.string_exp);
		int len2 = strlen($3.string_exp);
		$$.string_exp = malloc(len1+len2+3);
		snprintf($$.string_exp,len1+len2+3, "%s<=%s",$1.string_exp,$3.string_exp);
		free($1.string_exp);
		free($3.string_exp);
	}
	| relational_expression GE_OP shift_expression {
		int len1 = strlen($1.string_exp);
		int len2 = strlen($3.string_exp);
		$$.string_exp = malloc(len1+len2+3);
		snprintf($$.string_exp,len1+len2+3, "%s>=%s",$1.string_exp,$3.string_exp);
		free($1.string_exp);
		free($3.string_exp);
	}
	;
equality_expression
	: relational_expression{

		$$.string_exp = $1.string_exp;
	}
	| equality_expression EQ_OP relational_expression {
		int len1 = strlen($1.string_exp);
		int len2 = strlen($3.string_exp);
		$$.string_exp = malloc(len1+len2+3);
		snprintf($$.string_exp,len1+len2+3, "%s==%s",$1.string_exp,$3.string_exp);
		free($1.string_exp);
		free($3.string_exp);
	}
	| equality_expression NE_OP relational_expression {
		int len1 = strlen($1.string_exp);
		int len2 = strlen($3.string_exp);
		$$.string_exp = malloc(len1+len2+3);
		snprintf($$.string_exp,len1+len2+3, "%s!=%s",$1.string_exp,$3.string_exp);
		free($1.string_exp);
		free($3.string_exp);
	}
	;
and_expression
	: equality_expression {

		$$.string_exp = $1.string_exp;
	}
	| and_expression '&' equality_expression {
		int len1 = strlen($1.string_exp);
		int len2 = strlen($3.string_exp);
		$$.string_exp = malloc(len1+len2+2);
		snprintf($$.string_exp,len1+len2+2, "%s&%s",$1.string_exp,$3.string_exp);
		free($1.string_exp);
		free($3.string_exp);
	}
	;
exclusive_or_expression
	: and_expression{

		$$.string_exp = $1.string_exp;
	}
	| exclusive_or_expression '^' and_expression {
		int len1 = strlen($1.string_exp);
		int len2 = strlen($3.string_exp);
		$$.string_exp = malloc(len1+len2+2);
		snprintf($$.string_exp,len1+len2+2, "%s^%s",$1.string_exp,$3.string_exp);
		free($1.string_exp);
		free($3.string_exp);
	}
	;
inclusive_or_expression
	: exclusive_or_expression {

		$$.string_exp = $1.string_exp;
	}
	| inclusive_or_expression '|' exclusive_or_expression {
		int len1 = strlen($1.string_exp);
		int len2 = strlen($3.string_exp);
		$$.string_exp = malloc(len1+len2+2);
		snprintf($$.string_exp,len1+len2+2, "%s|%s",$1.string_exp,$3.string_exp);
		free($1.string_exp);
		free($3.string_exp);
	}
	;
logical_and_expression
	: inclusive_or_expression {

		$$.string_exp = $1.string_exp;
	}
	| logical_and_expression AND_OP inclusive_or_expression {
		int len1 = strlen($1.string_exp);
		int len2 = strlen($3.string_exp);
		$$.string_exp = malloc(len1+len2+3);
		snprintf($$.string_exp,len1+len2+3, "%s&&%s",$1.string_exp,$3.string_exp);
		free($1.string_exp);
		free($3.string_exp);
	}
	;
logical_or_expression
	: logical_and_expression {

		$$.string_exp = $1.string_exp;
	}
	| logical_or_expression OR_OP logical_and_expression {
		int len1 = strlen($1.string_exp);
		int len2 = strlen($3.string_exp);
		$$.string_exp = malloc(len1+len2+3);
		snprintf($$.string_exp,len1+len2+3, "%s||%s",$1.string_exp,$3.string_exp);
		free($1.string_exp);
		free($3.string_exp);
	}
	;
//TODO add conditional assignement

assignment_expression :
	logical_and_expression {
		$$.string_exp = $1.string_exp;
	}
	| unary_expression assignment_operator assignment_expression {
		int len1 = strlen($1.string_exp);
		int len2 = strlen($3.string_exp);
		$$.string_exp = malloc(len1+len2+2);
		//printf("\n-------TEST88--- |%s| |%s| \n",$1.string_exp,$3.string_exp);
		snprintf($$.string_exp,len1+len2+2, "%s=%s",$1.string_exp,$3.string_exp);
		//printf("\n-------TEST88+1--- |%s| \n",$$.string_exp);
		free($1.string_exp);
		free($2.string_exp);
		free($3.string_exp);
	}
	;
assignment_operator
	: '=' {
		$$.string_exp = malloc(2);
		snprintf($$.string_exp,2, "=");
	}
	;
//====================================ASSIGNEMENT-END=================================================================
//DONE TODO================================================
declaration_list
	: declaration {
		$$.string_exp = $1.string_exp;
		//printf("\n===============\n%s\n================\n",$1.string_exp);
	}
	| declaration_list declaration {

		int len1 = strlen($1.string_exp);
		int len2 = strlen($2.string_exp);
		$$.string_exp = malloc(len1+len2+2);
		snprintf($$.string_exp,len1+len2+2, "%s %s",$1.string_exp,$2.string_exp);
		free($1.string_exp);
		free($2.string_exp);

	}
	;//=================================================USED

//DONE
declaration :
	//: declaration_specifiers ';' // long; or int;
	//we have type in declaration_specifiers
	// check if declaration_specifier type fits into all items of init_declarator_list
	//{ printf("After type : %d",current_type_var);}
	declaration_specifiers init_declarator_list ';' {
		//restore the current type variable to -1
		 current_type_var = -1;

		//COPY
		// TODO Probelem here segfault!!!!!

		int len1 = strlen($1.string_exp);
		int len2 = strlen($2.string_exp);
		$$.string_exp = malloc(len1+len2+3);
		snprintf($$.string_exp,len1+len2+3, "%s %s;",$1.string_exp,$2.string_exp);
		free($1.string_exp);
		free($2.string_exp);

	}
	; //==========================================================USED

//DONE
declaration_specifiers
	:
	type_specifier {
		 //$$.type = $1.type; INT or FLAT ...
		 //store the current type in a global variable....TODO
		 //TODO check composed types=====!
		 current_type_var = $1.type;
		 printf("current type : %d",current_type_var);

		 $$.string_exp = $1.string_exp;
	}
	//| type_specifier declaration_specifiers // int ..
	//| type_qualifier declaration_specifiers //const int ...
	;
//=======================================================USED
//DONE
type_specifier
	: VOID {
		$$.type = VOID;
		//printf("TYPE : %d",$$);

		$$.string_exp = malloc(5);
		snprintf($$.string_exp,5, "void");

	}
	| INT  {
		$$.type = INT;
		//printf("TYPE : %d",$$);

		$$.string_exp = malloc(4);
		snprintf($$.string_exp,4, "int");
	}
	| FLOAT {
		$$.type = FLOAT;
		printf("TYPE : %d",$$);

		$$.string_exp = malloc(6);
		snprintf($$.string_exp,6, "float");
	}
	;
//DONE
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

		$$.string_exp = $1.string_exp;

	}
	| init_declarator_list ',' init_declarator {


	//COPY
	int len1 = strlen($1.string_exp);
	int len2 = strlen($3.string_exp);
	$$.string_exp = malloc(len1+len2+2);
	snprintf($$.string_exp,len1+len2+2, "%s,%s",$1.string_exp,$3.string_exp);
	free($1.string_exp);
	free($3.string_exp);

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
	 	$$.string_exp = $1.string_exp;
		//snprintf($$.string_exp,8, "ass_exp");

	}
	| '{' initializer_list '}' {
		int len1 = strlen($2.string_exp);
		$$.string_exp = malloc(len1+3);
		snprintf($$.string_exp,len1+3, "{%s}",$2.string_exp);
		free($2.string_exp);
	}
	;
initializer_list
	: initializer {
		$$.string_exp = $1.string_exp;
	}
	| initializer_list ',' initializer {

		int len1 = strlen($1.string_exp);
		int len2 = strlen($3.string_exp);
		$$.string_exp = malloc(len1+len2+2);
		snprintf($$.string_exp,len1+len2+2, "%s,%s",$1.string_exp,$3.string_exp);
		free($1.string_exp);
		free($3.string_exp);

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
		$$.string_exp = malloc(len+1);
		snprintf($$.string_exp,len+1, "%s",curr_var_name_tmp);

	}
	| CONST_INT {
		$$.type = CONST_INT;


		char * curr_var_name_tmp = $1.string_val;
		int len = strlen(curr_var_name_tmp);
		$$.string_exp = malloc(len+1);
		snprintf($$.string_exp,len+1, "%s",curr_var_name_tmp);

	}
	| CONST_FLOAT {
		$$.type = CONST_FLOAT;

		char * curr_var_name_tmp = $1.string_val;
		int len = strlen(curr_var_name_tmp);
		$$.string_exp = malloc(len+1);
		snprintf($$.string_exp,len+1, "%s",curr_var_name_tmp);
	}
	//| STRING {
	//TODO Not implemented yet
	//}
	| '(' expression ')' {

		$$.type = EXPR;
		char * curr_var_name_tmp = $2.string_exp;
		int len = strlen(curr_var_name_tmp);
		$$.string_exp = malloc(len+3);
		snprintf($$.string_exp,len+4, "(%s)",$2.string_exp);
		free($2.string_exp);
		//printf("\n---------TEST766------ | %s |---------\n",$$.string_exp);

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