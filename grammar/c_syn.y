%{
	#include<stdio.h>
	#include "headers/defs.h"
	#include "headers/y.tab.h"
	#include "headers/ast.h"

	#include <stdlib.h>
	int for_depth_counter_var = 0;
	int direct_declarator_var = 0;
	int current_type_var = -1;
	int can_use_un = 0;
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

		struct ast* _ast;
		char * string_exp;
	}vv;

}
%token INT VOID FLOAT
%token FOR WHILE DO IF ELSE RETURN BREAK GOTO HASH INCLUDE
%token CONST_Q //type qualifier  const int...
%token <vv> CONST_INT CONST_FLOAT IDENTIFIER STRING CONST PRINTF
%token '='
%token '(' ')' ';' '}' '{' ']' '[' '/' '*' '+' '-' '<' '>' '%'
%token AND_OP OR_OP LE_OP GE_OP EQ_OP NE_OP INC DEC LEFT_OP RIGHT_OP
%type <vv> type_specifier declaration_specifiers primary_expression expression  compound_statement statement_list declaration_list identifier_list
%type <vv> selection_statement pointer direct_declarator declarator init_declarator declaration init_declarator_list initializer initializer_list statement postfix_expression
%type <vv> jump_statement iteration_statement multiplicative_expression additive_expression shift_expression relational_expression equality_expression unary_expression assignment_expression
%type <vv> include_elm include_list parameter_declaration parameter_list external_declaration function_definition translation_unit expression_statement and_expression exclusive_or_expression inclusive_or_expression logical_or_expression logical_and_expression assignment_operator
%start start
%%

//==================================START-EXTERNAL======================================================================
start : translation_unit {
		printf("-->\n%s\n",$1.string_exp);
		    char * inc = "#include <cblas.h>"
                                 "#include <primitives.h>";
		FILE* d = fopen(file_out, "a");
		char* tot = malloc(strlen($1.string_exp)+100);
		memset(tot,0,strlen($1.string_exp)+100);
		snprintf(tot,strlen($1.string_exp)+100,"%s\n%s",inc,$1.string_exp);
		printf("%s\n",tot);
		fprintf(d,"%s",tot);
		free($1.string_exp);
		free(tot);
}
     | include_list translation_unit {
     		int len1 = strlen($1.string_exp);
     		int len2 = strlen($2.string_exp);
    		char* res = malloc(len1+len2+100);
	    	char * inc = "#include \"cblas.h\"\n"
			 "#include \"primitives.h\"";
		snprintf(res,len1+len2+100, "%s\n%s\n%s",inc,$1.string_exp,$2.string_exp);

		printf("-->\n%s\n",res);
		FILE* d = fopen(file_out, "w");
		fprintf(d,"%s",res);
		free($1.string_exp);
		free($2.string_exp);
     }
include_list:
            include_list include_elm {
            	int len1 = strlen($1.string_exp);
		int len2 = strlen($2.string_exp);
		$$.string_exp = malloc(len1+len2+2);
		snprintf($$.string_exp,len1+len2+2, "%s\n%s",$1.string_exp,$2.string_exp);
            	free($1.string_exp);
            	free($2.string_exp);
            }
	    | include_elm {
	    	$$.string_exp = $1.string_exp;
	    }
	    ;
include_elm : HASH INCLUDE STRING {
	int len = strlen($3.string_val)+10;
	$$.string_exp = malloc(len);
	snprintf($$.string_exp,len,"#include %s",$3.string_val);
}


translation_unit
	: external_declaration {
		$$.string_exp = $1.string_exp;
	}
	| translation_unit external_declaration {
		int len1 = strlen($1.string_exp);
		int len2 = strlen($2.string_exp);
		$$.string_exp = malloc(len1+len2+2);
		snprintf($$.string_exp,len1+len2+2, "%s\n%s",$1.string_exp,$2.string_exp);
		free($1.string_exp);
		free($2.string_exp);
	}
	;

external_declaration
	: function_definition {
			$$.string_exp = $1.string_exp;
	}
	| declaration {
		$$.string_exp = $1.string_exp;
	}
	;
function_definition
	: declaration_specifiers declarator declaration_list compound_statement {
		int len1 = strlen($1.string_exp);
		int len2 = strlen($2.string_exp);
		int len3 = strlen($3.string_exp);
		int len4 = strlen($4.string_exp);
		$$.string_exp = malloc(len1+len2+len3+len4+4);
		snprintf($$.string_exp,len1+len2+len3+len4+4, "%s %s\n%s\n%s",$1.string_exp,$2.string_exp,$3.string_exp,$4.string_exp);
		free($1.string_exp);
		free($2.string_exp);
		free($3.string_exp);
		free($4.string_exp);
	}
	| declaration_specifiers declarator compound_statement {
		int len1 = strlen($1.string_exp);
		int len2 = strlen($2.string_exp);
		int len3 = strlen($3.string_exp);
		$$.string_exp = malloc(len1+len2+len3+3);
		snprintf($$.string_exp,len1+len2+len3+3, "%s %s\n%s",$1.string_exp,$2.string_exp,$3.string_exp);
		free($1.string_exp);
		free($2.string_exp);
		free($3.string_exp);
	}
	| declarator declaration_list compound_statement {
		int len1 = strlen($1.string_exp);
		int len2 = strlen($2.string_exp);
		int len3 = strlen($3.string_exp);
		$$.string_exp = malloc(len1+len2+len3+3);
		snprintf($$.string_exp,len1+len2+2, "%s\n%s\n%s",$1.string_exp,$2.string_exp,$3.string_exp);
		free($1.string_exp);
		free($2.string_exp);
		free($3.string_exp);
	}
	| declarator compound_statement {
		int len1 = strlen($1.string_exp);
		int len2 = strlen($2.string_exp);
		$$.string_exp = malloc(len1+len2+2);
		snprintf($$.string_exp,len1+len2+2, "%s\n%s",$1.string_exp,$2.string_exp);
		free($1.string_exp);
		free($2.string_exp);
	}
	;

jump_statement
	: GOTO IDENTIFIER ';' {
		int len1 = strlen($2.string_val);
		$$.string_exp = malloc(len1+8);
		snprintf($$.string_exp,len1+8, "goto %s ;",$2.string_val);
	}
	| BREAK ';' {
		$$.string_exp = malloc(7);
		snprintf($$.string_exp,7, "break;");
	}
	| RETURN ';' {
		$$.string_exp = malloc(8);
		snprintf($$.string_exp,8, "return;");
	}
	| RETURN expression ';' {
		int len1 = strlen($2.string_exp);
		$$.string_exp = malloc(len1+10);
		snprintf($$.string_exp,len1+10, "return %s ;",$2.string_exp);
		free($2.string_exp);
	}
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
		//ast_print($2._ast,0);

	  	 $$._ast = $2._ast;


	}
	| '{' declaration_list '}' {
		int len1 = strlen($2.string_exp);
		$$.string_exp = malloc(len1+3);
		snprintf($$.string_exp,len1+3, "{%s}",$2.string_exp);
		free($2.string_exp);

	   	$$._ast = $2._ast;



	}
	| '{' declaration_list statement_list '}' {
		int len1 = strlen($2.string_exp);
		int len2 = strlen($3.string_exp);
		$$.string_exp = malloc(len1+len2+6);
		snprintf($$.string_exp,len1+len2+6, "{\n%s\n%s\n}",$2.string_exp,$3.string_exp);
		free($2.string_exp);
		free($3.string_exp);

		//ast_print($2._ast,0);
		//printf("---------------------------\n");
		//ast_print($3._ast,0);


	}
	;

//=====================================EXTERNAL-END=====================================================================

//=====================================statement-START==================================================================

statement_list
	: statement {
		   $$.string_exp = $1.string_exp;
		   $$._ast = $1._ast;
	}
	| statement_list statement {
                int len1 = strlen($1.string_exp);
		int len2 = strlen($2.string_exp);
		$$.string_exp = malloc(len1+len2+2);
		snprintf($$.string_exp,len1+len2+2, "%s\n%s",$1.string_exp,$2.string_exp);
		free($1.string_exp);
		free($2.string_exp);
		$$._ast = ast_new_operation(AST_STATE_LIST,$1._ast,$2._ast);
	}
statement
	: //labeled_statement
	  compound_statement {
	 $$.string_exp = $1.string_exp;
	 $$._ast = $1._ast;

	  }
	| expression_statement {
         $$.string_exp = $1.string_exp;
	 //$$._ast = $1._ast;

	}
	| selection_statement {

		$$.string_exp = $1.string_exp;
	}
	| iteration_statement {
		$$.string_exp = $1.string_exp;
		$$._ast = $1._ast;
	}
	| jump_statement{
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

		$$._ast = $1._ast;
	}
	| PRINTF {
		int len = strlen($1.string_val);
		$$.string_exp = malloc(len+2);
		snprintf($$.string_exp,len+2,"%s\n",$1.string_val);
		free($1.string_val);

		$$._ast = ast_new_print();
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
	}
iteration_statement :
	 WHILE '(' expression ')' compound_statement {
		 	ast *while_ast = ast_new_operation(AST_WHILE, $3._ast, $5._ast);
			ast_print(while_ast, 0);
			$$._ast = while_ast;

	 		int len1 = strlen($3.string_exp);
         		int len2 = strlen($5.string_exp);
         		$$.string_exp = malloc(len1+len2+9);
         		snprintf($$.string_exp,len1+len2+9, "while(%s)\n%s",$3.string_exp,$5.string_exp);
         		free($3.string_exp);
         		free($5.string_exp);
	 }

	| iter_counter FOR '(' expression_statement expression_statement expression')' compound_statement {

		ast* fora = ast_new_for($4._ast,$5._ast,$6._ast,$8._ast);
		ast_print(fora,0);
		$$._ast = fora;
		//printf("\n[+] S->for_depth_counter_var : %d\n",for_depth_counter_var);
		int len1 = strlen($4.string_exp);
		int len2 = strlen($5.string_exp);
		int len3 = strlen($6.string_exp);
		int len4 = strlen($8.string_exp);
		char *result = malloc(len1+len2+len3+len4+9);
		snprintf(result,len1+len2+len3+len4+9, "for(%s %s %s)\n%s",$4.string_exp,$5.string_exp,$6.string_exp,$8.string_exp);
		$$.string_exp = result;
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
			   //printf("\n--------------BLAST GOT RESULT %d---------\n",globalData.symbol->optimized);
			   if(globalData.symbol->optimized == 1){
				int lenm = globalData.symbol->bytes_count;
			   	//printf("[+] reading optimizer output count(%d)\n",lenm);
			        fptr = fopen(OPTIMIZER_FILE,"r");
			   	char* op_res = malloc(lenm);
			   	memset(op_res,0,lenm);
			   	char *r = fgets(op_res,lenm,fptr);
				
				if (r != NULL) {
					perror("fgets error 363\n");
				}

			   	free($$.string_exp);
			   	$$.string_exp = op_res;
			   }

		}


		for_depth_counter_var--;
		//printf("\n[+] S->for_depth_counter_var : %d\n",for_depth_counter_var);

	}
iter_counter : {for_depth_counter_var++;}
//=======================================CONDITIONAL-EXPR-END===========================================================

//==================================START-ASSIGNEMENT===================================================================
expression:
 	assignment_expression {
 		$$.string_exp = $1.string_exp;
 		$$._ast = $1._ast;
 	}
	| expression ',' assignment_expression {

		int len1 = strlen($1.string_exp);
		int len2 = strlen($3.string_exp);
		$$.string_exp = malloc(len1+len2+2);
		snprintf($$.string_exp,len1+len2+2, "%s,%s",$1.string_exp,$3.string_exp);
		free($1.string_exp);
		free($3.string_exp);
		$$._ast = ast_new_operation(AST_EXPR_LIST,$1._ast,$3._ast);
	}
	;
postfix_expression
	: primary_expression {
		$$.string_exp = $1.string_exp;
		$$._ast = $1._ast;
	}
	| postfix_expression '[' expression ']' {
		int len1 = strlen($1.string_exp);
		int len2 = strlen($3.string_exp);
		$$.string_exp = malloc(len1+len2+3);
		snprintf($$.string_exp,len1+len2+3, "%s[%s]",$1.string_exp,$3.string_exp);
		free($1.string_exp);
		free($3.string_exp);

		$$._ast = ast_new_operation(AST_ARR_ACCESS,$1._ast,$3._ast);
	}
	| postfix_expression '(' ')' {
		int len1 = strlen($1.string_exp);
		$$.string_exp = malloc(len1+3);
		snprintf($$.string_exp,len1+3, "%s()",$1.string_exp);
		free($1.string_exp);

		$$._ast = ast_new_operation(AST_FUNC_CALL,$1._ast,0);
	}
	| postfix_expression INC {
		int len1 = strlen($1.string_exp);
		$$.string_exp = malloc(len1+3);
		snprintf($$.string_exp,len1+3, "%s++",$1.string_exp);
		free($1.string_exp);

		$$._ast = ast_new_operation(AST_INC,$1._ast,0);
	}
	| postfix_expression DEC {
		int len1 = strlen($1.string_exp);
		$$.string_exp = malloc(len1+3);
		snprintf($$.string_exp,len1+3, "%s--",$1.string_exp);
		free($1.string_exp);

		$$._ast = ast_new_operation(AST_DEC,$1._ast,0);
	}

unary_expression
	: postfix_expression {
		$$.string_exp = $1.string_exp;
		$$._ast = $1._ast;
	}
	| INC unary_expression {
		int len2 = strlen($2.string_exp);
		$$.string_exp = malloc(len2+3);
		snprintf($$.string_exp,len2+3, "++%s",$2.string_exp);
		free($2.string_exp);
		$$._ast = ast_new_operation(AST_INC,0,$2._ast);

	}
	| DEC unary_expression {
		int len2 = strlen($2.string_exp);
		$$.string_exp = malloc(len2+3);
		snprintf($$.string_exp,len2+3, "--%s",$2.string_exp);
		free($2.string_exp);
		$$._ast = ast_new_operation(AST_DEC,0,$2._ast);
	}

multiplicative_expression
	: unary_expression {
		$$.string_exp = $1.string_exp;
		$$._ast = $1._ast;
	}
	| multiplicative_expression '*' unary_expression {


		int len1 = strlen($1.string_exp);
		int len2 = strlen($3.string_exp);
		$$.string_exp = malloc(len1+len2+2);
		snprintf($$.string_exp,len1+len2+2, "%s*%s",$1.string_exp,$3.string_exp);
		free($1.string_exp);
		free($3.string_exp);

		$$._ast = ast_new_operation(AST_MUL,$1._ast,$3._ast);

	}
	| multiplicative_expression '/' unary_expression {

		int len1 = strlen($1.string_exp);
		int len2 = strlen($3.string_exp);
		$$.string_exp = malloc(len1+len2+2);
		snprintf($$.string_exp,len1+len2+2, "%s/%s",$1.string_exp,$3.string_exp);
		free($1.string_exp);
		free($3.string_exp);

		$$._ast = ast_new_operation(AST_DIV,$1._ast,$3._ast);
	}
	| multiplicative_expression '%' unary_expression {

		int len1 = strlen($1.string_exp);
		int len2 = strlen($3.string_exp);
		$$.string_exp = malloc(len1+len2+4);
		snprintf($$.string_exp,len1+len2+4, "%s%%%s",$1.string_exp,$3.string_exp);
		free($1.string_exp);
		free($3.string_exp);

		$$._ast = ast_new_operation(AST_MOD,$1._ast,$3._ast);


	}
	;
additive_expression
	: multiplicative_expression {

		$$.string_exp = $1.string_exp;
		$$._ast = $1._ast;
	}
	| additive_expression '+' multiplicative_expression {

		int len1 = strlen($1.string_exp);
		int len2 = strlen($3.string_exp);
		$$.string_exp = malloc(len1+len2+2);
		snprintf($$.string_exp,len1+len2+2, "%s+%s",$1.string_exp,$3.string_exp);
		free($1.string_exp);
		free($3.string_exp);

		$$._ast = ast_new_operation(AST_ADD,$1._ast,$3._ast);

	}
	| additive_expression '-' multiplicative_expression {

		int len1 = strlen($1.string_exp);
		int len2 = strlen($3.string_exp);
		$$.string_exp = malloc(len1+len2+2);
		snprintf($$.string_exp,len1+len2+2, "%s-%s",$1.string_exp,$3.string_exp);
		free($1.string_exp);
		free($3.string_exp);

		$$._ast = ast_new_operation(AST_SUB,$1._ast,$3._ast);

	}
	;
shift_expression
	: additive_expression {

		$$.string_exp = $1.string_exp;
		$$._ast = $1._ast;

	}
	| shift_expression LEFT_OP additive_expression {
		int len1 = strlen($1.string_exp);
		int len2 = strlen($3.string_exp);
		$$.string_exp = malloc(len1+len2+3);
		snprintf($$.string_exp,len1+len2+3, "%s<<%s",$1.string_exp,$3.string_exp);
		free($1.string_exp);
		free($3.string_exp);

		$$._ast = ast_new_operation(AST_LEFT_OP,$1._ast,$3._ast);

	}
	| shift_expression RIGHT_OP additive_expression {
		int len1 = strlen($1.string_exp);
		int len2 = strlen($3.string_exp);
		$$.string_exp = malloc(len1+len2+3);
		snprintf($$.string_exp,len1+len2+3, "%s>>%s",$1.string_exp,$3.string_exp);
		free($1.string_exp);
		free($3.string_exp);


		$$._ast = ast_new_operation(AST_RIGHT_OP,$1._ast,$3._ast);
	}
	;
relational_expression
	: shift_expression{

		$$.string_exp = $1.string_exp;
		$$._ast = $1._ast;

	}
	| relational_expression '<' shift_expression {
		int len1 = strlen($1.string_exp);
		int len2 = strlen($3.string_exp);
		$$.string_exp = malloc(len1+len2+2);
		snprintf($$.string_exp,len1+len2+2, "%s<%s",$1.string_exp,$3.string_exp);
		free($1.string_exp);
		free($3.string_exp);
		$$._ast = ast_new_operation(AST_LOWER,$1._ast,$3._ast);
	}
	| relational_expression '>' shift_expression {
		int len1 = strlen($1.string_exp);
		int len2 = strlen($3.string_exp);
		$$.string_exp = malloc(len1+len2+2);
		snprintf($$.string_exp,len1+len2+2, "%s>%s",$1.string_exp,$3.string_exp);
		free($1.string_exp);
		free($3.string_exp);
		$$._ast = ast_new_operation(AST_GREATER,$1._ast,$3._ast);
	}
	| relational_expression LE_OP shift_expression{
		int len1 = strlen($1.string_exp);
		int len2 = strlen($3.string_exp);
		$$.string_exp = malloc(len1+len2+3);
		snprintf($$.string_exp,len1+len2+3, "%s<=%s",$1.string_exp,$3.string_exp);
		free($1.string_exp);
		free($3.string_exp);
		$$._ast = ast_new_operation(AST_LOWER_EQUAL,$1._ast,$3._ast);

	}
	| relational_expression GE_OP shift_expression {
		int len1 = strlen($1.string_exp);
		int len2 = strlen($3.string_exp);
		$$.string_exp = malloc(len1+len2+3);
		snprintf($$.string_exp,len1+len2+3, "%s>=%s",$1.string_exp,$3.string_exp);
		free($1.string_exp);
		free($3.string_exp);
		$$._ast = ast_new_operation(AST_GREATER_EQUAL,$1._ast,$3._ast);
	}
	;
equality_expression
	: relational_expression{

		$$.string_exp = $1.string_exp;
		$$._ast = $1._ast;

	}
	| equality_expression EQ_OP relational_expression {
		int len1 = strlen($1.string_exp);
		int len2 = strlen($3.string_exp);
		$$.string_exp = malloc(len1+len2+3);
		snprintf($$.string_exp,len1+len2+3, "%s==%s",$1.string_exp,$3.string_exp);
		free($1.string_exp);
		free($3.string_exp);

		$$._ast = ast_new_operation(AST_EQUAL,$1._ast,$3._ast);

	}
	| equality_expression NE_OP relational_expression {
		int len1 = strlen($1.string_exp);
		int len2 = strlen($3.string_exp);
		$$.string_exp = malloc(len1+len2+3);
		snprintf($$.string_exp,len1+len2+3, "%s!=%s",$1.string_exp,$3.string_exp);
		free($1.string_exp);
		free($3.string_exp);
		$$._ast = ast_new_operation(AST_NOT_EQUAL,$1._ast,$3._ast);
	}
	;
and_expression
	: equality_expression {
		$$.string_exp = $1.string_exp;
		$$._ast = $1._ast;

	}
	| and_expression '&' equality_expression {
		int len1 = strlen($1.string_exp);
		int len2 = strlen($3.string_exp);
		$$.string_exp = malloc(len1+len2+2);
		snprintf($$.string_exp,len1+len2+2, "%s&%s",$1.string_exp,$3.string_exp);
		free($1.string_exp);
		free($3.string_exp);

		$$._ast = ast_new_operation(AST_AND,$1._ast,$3._ast);
	}
	;
exclusive_or_expression
	: and_expression{

		$$.string_exp = $1.string_exp;
		$$._ast = $1._ast;

	}
	| exclusive_or_expression '^' and_expression {
		int len1 = strlen($1.string_exp);
		int len2 = strlen($3.string_exp);
		$$.string_exp = malloc(len1+len2+2);
		snprintf($$.string_exp,len1+len2+2, "%s^%s",$1.string_exp,$3.string_exp);
		free($1.string_exp);
		free($3.string_exp);
		$$._ast = ast_new_operation(AST_EOR,$1._ast,$3._ast);
	}
	;
inclusive_or_expression
	: exclusive_or_expression {

		$$.string_exp = $1.string_exp;
		$$._ast = $1._ast;

	}
	| inclusive_or_expression '|' exclusive_or_expression {
		int len1 = strlen($1.string_exp);
		int len2 = strlen($3.string_exp);
		$$.string_exp = malloc(len1+len2+2);
		snprintf($$.string_exp,len1+len2+2, "%s|%s",$1.string_exp,$3.string_exp);
		free($1.string_exp);
		free($3.string_exp);
		$$._ast = ast_new_operation(AST_IOR,$1._ast,$3._ast);
	}
	;
logical_and_expression
	: inclusive_or_expression {

		$$.string_exp = $1.string_exp;
		$$._ast = $1._ast;

	}
	| logical_and_expression AND_OP inclusive_or_expression {
		int len1 = strlen($1.string_exp);
		int len2 = strlen($3.string_exp);
		$$.string_exp = malloc(len1+len2+3);
		snprintf($$.string_exp,len1+len2+3, "%s&&%s",$1.string_exp,$3.string_exp);
		free($1.string_exp);
		free($3.string_exp);

		$$._ast = ast_new_operation(AST_AND_OP,$1._ast,$3._ast);
	}
	;
logical_or_expression
	: logical_and_expression {

		$$.string_exp = $1.string_exp;
		$$._ast = $1._ast;

	}
	| logical_or_expression OR_OP logical_and_expression {
		int len1 = strlen($1.string_exp);
		int len2 = strlen($3.string_exp);
		$$.string_exp = malloc(len1+len2+3);
		snprintf($$.string_exp,len1+len2+3, "%s||%s",$1.string_exp,$3.string_exp);
		free($1.string_exp);
		free($3.string_exp);
		$$._ast = ast_new_operation(AST_OR_OP,$1._ast,$3._ast);
	}
	;
//TODO add conditional assignement

assignment_expression :
	logical_or_expression {
		$$.string_exp = $1.string_exp;
		$$._ast = $1._ast;

	}
	| unary_expression assignment_operator assignment_expression {
		int len1 = strlen($1.string_exp);
		int len2 = strlen($3.string_exp);
		$$.string_exp = malloc(len1+len2+2);
		snprintf($$.string_exp,len1+len2+2, "%s=%s",$1.string_exp,$3.string_exp);
		free($1.string_exp);
		free($2.string_exp);
		free($3.string_exp);

		$$._ast = ast_new_operation(AST_ASSIGN,$1._ast,$3._ast);
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
		$$._ast = $1._ast;
	}
	| declaration_list declaration {

		int len1 = strlen($1.string_exp);
		int len2 = strlen($2.string_exp);
		$$.string_exp = malloc(len1+len2+2);
		snprintf($$.string_exp,len1+len2+2, "%s %s",$1.string_exp,$2.string_exp);
		free($1.string_exp);
		free($2.string_exp);

		//$$._ast = ast_new_operation(AST_DEC_LIST,$1._ast,$2._ast);


	}
	;//=================================================USED

//DONE
declaration :
	declaration_specifiers init_declarator_list ';' {
		//restore the current type variable to -1
		 current_type_var = -1;

		//COP
		int len1 = strlen($1.string_exp);
		int len2 = strlen($2.string_exp);
		$$.string_exp = malloc(len1+len2+3);
		snprintf($$.string_exp,len1+len2+3, "%s %s;",$1.string_exp,$2.string_exp);
		free($1.string_exp);
		free($2.string_exp);

		//===========================CHECK HERE DECLARATION AST
		$$._ast = ast_new_operation(AST_DEC_LIST,0,$2._ast);
		ast_print($$._ast,0);

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

		 $$.string_exp = $1.string_exp;
	}
	;
//=======================================================USED
//DONE
type_specifier
	: VOID {
		$$.type = VOID;

		$$.string_exp = malloc(5);
		snprintf($$.string_exp,5, "void");

	}
	| INT  {
		$$.type = INT;

		$$.string_exp = malloc(4);
		snprintf($$.string_exp,4, "int");
	}
	| FLOAT {
		$$.type = FLOAT;
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
			varp->type = TYPE_ARRAY;
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
		symbol_p e= $$.sentry;
		e->glob_type = current_type_var;

		$$._ast = $1._ast;
	}
	| declarator '=' initializer {
		for(int l = 0;l<4;l++){
			$$.t[l] = $1.t[l];
		}
		$$.sentry = $1.sentry;
		$$.count_p  = $1.count_p; //TODO maybe 0
		$$.count_m  = $1.count_m;

		symbol_p e = $1.sentry;
		e->is_init = 1;
		e->glob_type = current_type_var;

		if(e->type == TYPE_VARIABLE && $3.type != 1){
			printf("error :VAR Assignement bad type line: %d\n",line_counter+1);
			return -1;
		}
		if(e->type == TYPE_ARRAY && $3.type != 0){
			printf("error :ARR Assignement bad type line: %d\n",line_counter+1);
			return -1;
		}
		if(e->type == TYPE_FUNCTION){
			printf("error :Functions can't be assigned line: %d\n",line_counter+1);
			return -1;
		}


		int len1 = strlen($1.string_exp);
		int len2 = strlen($3.string_exp);
		$$.string_exp = malloc(len1+len2+2);
		snprintf($$.string_exp,len1+len2+2, "%s=%s",$1.string_exp,$3.string_exp);
		free($1.string_exp);
		free($3.string_exp);

		$$._ast = ast_new_operation(AST_ASSIGN,$1._ast,$3._ast);


	}

	;

//DONE
declarator
	: pointer direct_declarator {
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



		$$._ast = $2._ast;
	}
	| direct_declarator {

		for(int l = 0;l<4;l++)
			$$.t[l] = $1.t[l];
		$$.sentry = $1.sentry;
		$$.count_p  = $1.count_p; //TODO maybe 0
		$$.count_m  = $1.count_m;
	//COPY
		$$.string_exp = $1.string_exp;

		$$._ast = $1._ast;

	}
	;

// DONE
direct_declarator
	: IDENTIFIER {
		$$.count_p  = 0;
		$$.count_m  = 0;
		direct_declarator_var = 0;
		$$.sentry = $1.sentry;
		symbol_p tmp = $$.sentry;
		tmp->type = TYPE_VARIABLE;
		$$.string_val = $1.string_val;

		//set is_dec bit for the current variable;
		char * curr_var_name_tmp = $1.string_val;
		if(current_type_var != -1){
		    symbol_p tttt;
	   	     // int rep = lookup_symbol_entry(curr_var_name_tmp,&tttt);
	   	    // printf("lookinf for %s\n",curr_var_name_tmp);
		    lookup_symbol_entry(curr_var_name_tmp,&tttt);
		    if(tttt->is_dec == 1){
			printf("error : Redeclaration of variable %s\tat line : %d\n",curr_var_name_tmp,line_counter+1);
			return -1;
		    }
		    //not yet declared...so set is_dec bit
		    tttt->is_dec = 1;
		}

		printf("---------------962----------identifier : %s\n",curr_var_name_tmp);

		int len = strlen(curr_var_name_tmp);
		$$.string_exp = malloc(len+1);
		snprintf($$.string_exp,len+1, "%s",curr_var_name_tmp);

		$$._ast = ast_new_id(curr_var_name_tmp);



	}
        | direct_declarator '[' CONST_INT ']' {
         	//$$ = $1 +1;
        	$$.t[direct_declarator_var] = $3.val;
         	direct_declarator_var++;
		$$.count_m = direct_declarator_var;
		$$.string_val = $1.string_val;

		$$.sentry = $1.sentry;
		symbol_p tmp = $$.sentry;
		tmp->type = TYPE_ARRAY;

		int len1 = strlen($1.string_exp);
		int len2 = strlen($3.string_val);
		$$.string_exp = malloc(len1+len2+3);
		snprintf($$.string_exp,len1+len2+4, "%s[%s]",$1.string_exp,$3.string_val);
		free($1.string_exp);

		$$._ast = ast_new_operation(AST_ARR_ACCESS,$1._ast,ast_new_number($3.val));
		current_type_var = -1;

        }
        | direct_declarator '(' ')' {
        		current_type_var = -1;
			printf("TEST940\n");
       			int len1 = strlen($1.string_exp);
        		$$.string_exp = malloc(len1+3);
        		snprintf($$.string_exp,len1+3, "%s()",$1.string_exp);
        		free($1.string_exp);

			$$.sentry = $1.sentry;
			symbol_p tmp = $$.sentry;
			tmp->type = TYPE_FUNCTION;
        }

        | direct_declarator '(' identifier_list ')' {
			current_type_var = -1;
        		printf("TEST941\n");
        		int len1 = strlen($1.string_exp);
			int len2 = strlen($3.string_exp);
			$$.string_exp = malloc(len1+len2+3);
			snprintf($$.string_exp,len1+len2+3, "%s(%s)",$1.string_exp,$3.string_exp);
			free($1.string_exp);
			free($3.string_exp);
			$$.sentry = $1.sentry;
			symbol_p tmp = $$.sentry;
			tmp->type = TYPE_FUNCTION;

        }
	| direct_declarator '(' parameter_list ')' {
		current_type_var = -1;
		$$.sentry = $1.sentry;
		int len1 = strlen($1.string_exp);
		int len2 = strlen($3.string_exp);
		$$.string_exp = malloc(len1+len2+3);
		snprintf($$.string_exp,len1+len2+3, "%s(%s)",$1.string_exp,$3.string_exp);
		free($1.string_exp);
		free($3.string_exp);
		symbol_p tmp = $$.sentry;
		tmp->type = TYPE_FUNCTION;
		//arg number
	}

        ;

parameter_list
	: parameter_declaration {
		$$.string_exp = $1.string_exp;
	}
	| parameter_list ',' parameter_declaration {
		int len1 = strlen($1.string_exp);
		int len2 = strlen($3.string_exp);
		$$.string_exp = malloc(len1+len2+2);
		snprintf($$.string_exp,len1+len2+2, "%s,%s",$1.string_exp,$3.string_exp);
		free($1.string_exp);
		free($3.string_exp);
	}
	;

parameter_declaration
	: declaration_specifiers declarator {
		int len1 = strlen($1.string_exp);
		int len2 = strlen($2.string_exp);
		$$.string_exp = malloc(len1+len2+2);
		snprintf($$.string_exp,len1+len2+2, "%s %s",$1.string_exp,$2.string_exp);
		free($1.string_exp);
		free($2.string_exp);
	}


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

	 	$$._ast = $1._ast;
	 	$$.type = 1;//simple

	}
	| '{' initializer_list '}' {
		int len1 = strlen($2.string_exp);
		$$.string_exp = malloc(len1+3);
		snprintf($$.string_exp,len1+3, "{%s}",$2.string_exp);
		free($2.string_exp);
		$$.type = 0;//complex

		$$._ast = $2._ast;
	}
	;
initializer_list
	: initializer {
		$$.string_exp = $1.string_exp;
		$$._ast = $1._ast;
	}
	| initializer_list ',' initializer {

		int len1 = strlen($1.string_exp);
		int len2 = strlen($3.string_exp);
		$$.string_exp = malloc(len1+len2+2);
		snprintf($$.string_exp,len1+len2+2, "%s,%s",$1.string_exp,$3.string_exp);
		free($1.string_exp);
		free($3.string_exp);

		$$._ast = ast_new_operation(AST_INIT_LIST,$1._ast,$3._ast);

	}
	;

//DONE,DONE
primary_expression
	: IDENTIFIER {
		$$.type = IDENTIFIER;
		char * curr_var_name_tmp = $1.string_val;
		if(current_type_var == -1){
		    symbol_p tttt;
		    int rep = lookup_symbol_entry(curr_var_name_tmp,&tttt);
		    if(rep == -1 || tttt->is_dec == 0){
			printf("error : Undeclared variable %s\tat line : %d\n",curr_var_name_tmp,line_counter+1);
			return -1;
		    }

		}

		//printf("------------1138--------Variable %s \n",curr_var_name_tmp);
		int len = strlen(curr_var_name_tmp);
		$$.string_exp = malloc(len+1);
		snprintf($$.string_exp,len+1, "%s",curr_var_name_tmp);

		//printf("CONST_INT : %s\n",curr_var_name_tmp);
		$$._ast = ast_new_id(curr_var_name_tmp);


	}
	| CONST_INT {
		$$.type = CONST_INT;


		char * curr_var_name_tmp = $1.string_val;
		int len = strlen(curr_var_name_tmp);
		$$.string_exp = malloc(len+1);
		snprintf($$.string_exp,len+1, "%s",curr_var_name_tmp);


		int a = atoi(curr_var_name_tmp);
		//printf("CONST_INT : %d\n",a);
		$$._ast = ast_new_number(a);

	}
	| CONST_FLOAT {
		if(current_type_var == INT || current_type_var == STRING){
			printf("incompatible type");
			return -1;
		}
		$$.type = CONST_FLOAT;
		char * curr_var_name_tmp = $1.string_val;
		int len = strlen(curr_var_name_tmp);
		$$.string_exp = malloc(len+1);
		snprintf($$.string_exp,len+1, "%s",curr_var_name_tmp);
		float a = strtof(curr_var_name_tmp, NULL);

		//printf("CONST_FLOAT : %f\n",a);
		$$._ast = ast_new_float(a);

	}
	| '(' expression ')' {

		$$.type = $2.type;
		char * curr_var_name_tmp = $2.string_exp;
		int len = strlen(curr_var_name_tmp);
		$$.string_exp = malloc(len+3);
		snprintf($$.string_exp,len+4, "(%s)",$2.string_exp);
		free($2.string_exp);

		$$._ast = $2._ast;

	}
	| STRING {
		$$.type = STRING;
		char * curr_var_name_tmp = $1.string_val;
		int len = strlen(curr_var_name_tmp);
		$$.string_exp = malloc(len+1);
		snprintf($$.string_exp,len+1, "%s",curr_var_name_tmp);
		$$._ast = ast_new_float(-2);
	}
	;


//DONE,DONE
identifier_list
	: IDENTIFIER {
		char * curr_var_name_tmp = $1.string_val;
		int len = strlen(curr_var_name_tmp);
		$$.string_exp = malloc(len);
		memcpy($$.string_exp,curr_var_name_tmp,len);
		$$._ast = ast_new_id(curr_var_name_tmp);
		printf("-----1210---------------Variable %s \n",curr_var_name_tmp);


	}
	| identifier_list ',' IDENTIFIER {

		char * curr_var_name_tmp = $3.string_exp;
		int len = strlen(curr_var_name_tmp);
		int len2 = strlen($3.string_val);
		$$.string_exp = malloc(len+len2+1);
		snprintf($$.string_exp,len+len2+1,"%s,%s",$1.string_exp,curr_var_name_tmp);
		free($1.string_exp);
		$$._ast = ast_new_operation(AST_LIST,$1._ast,ast_new_id(curr_var_name_tmp)) ;
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