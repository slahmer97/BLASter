//
// Created by slahmer on 12/28/19.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "headers/ast.h"

ast* ast_new_operation(ast_type type, ast* left, ast* right) {
    ast* new = malloc(sizeof(ast));
    new->type = type;
    new->left = left;
    new->right = right;
    return new;
}
ast* ast_new_number(int number) {
    ast* new = malloc(sizeof(ast));
    new->type = AST_NUMBER;
    new->i_number = number;
    return new;
}
ast* ast_new_for(struct ast* ass,struct ast* cond,struct ast* inc,struct ast* core){
    ast* new = malloc(sizeof(ast));
    new->type = AST_FOR;
    new->inc = inc;
    new->assign = ass;
    new->core = core;
    new->cond = cond;
    return new;
}

ast* ast_new_print(){
    ast* new = malloc(sizeof(ast));
    new->type = AST_PRINTF;
    return new;
}


ast* ast_new_float(float number) {
    ast* new = malloc(sizeof(ast));
    new->type = AST_FLOAT;
    new->f_number = number;
    return new;
}
ast* ast_new_id(char* id) {
    ast* new = malloc(sizeof(ast));
    new->type = AST_ID;
    new->id = strdup(id);
    return new;
}

void ast_free(ast* ast) {
    switch (ast->type) {
        case AST_NUMBER:
            break;
        case AST_ID:
            free(ast->id);
            break;
        case AST_ADD:
        case AST_SUB:
        case AST_MUL:
        case AST_DIV:
        case AST_MOD:
        case AST_FLOAT:
        case AST_LEFT_OP:
        case AST_RIGHT_OP:
        case AST_LOWER_EQUAL:
        case AST_GREATER_EQUAL:
        case AST_GREATER:
        case AST_LOWER:
        case AST_NOT_EQUAL:
        case AST_EQUAL:
        case AST_AND:
        case AST_EOR:
        case AST_IOR:
        case AST_AND_OP:
        case AST_OR_OP:
        case AST_INIT_LIST:
        case AST_EXPR_LIST:
        case AST_ASSIGN:
        case AST_STATE_LIST:
            ast_free(ast->left);
            ast_free(ast->right);
            break;
        case AST_LIST:
            ast_free(ast->left);
            ast_free(ast->right);
            break;
        case AST_ARR_ACCESS:
            break;
        case AST_FUNC_CALL:
            break;
        case AST_INC:
            break;
        case AST_DEC:
        case AST_DEC_LIST:
            break;

        case AST_FOR:
            break;
        case AST_PRINTF:
            break;
    }
    free(ast);
}

void ast_print(ast* ast, int indent) {
    for (int i = 0; i < indent; i++)
        printf("    ");
    switch(ast->type) {
        case AST_ID:
            printf("ID (%s)\n", ast->id);
            break;
        case AST_NUMBER:
            printf("NUM_I (%d)\n", ast->i_number);
            break;
        case AST_ADD:
            printf("+\n");
            ast_print(ast->left, indent + 1);
            ast_print(ast->right, indent + 1);
            break;
        case AST_MUL:
            printf("*\n");
            ast_print(ast->left, indent + 1);
            ast_print(ast->right, indent + 1);
            break;
        case AST_FLOAT:
            if( ast->f_number <= 0.000001){
                printf("ADDR : %p\n",ast);
                printf("HERE\n");
            }
            printf("NUM_F (%f)\n", ast->f_number);
            break;
        case AST_LIST:
        case AST_EXPR_LIST:
        case AST_INIT_LIST:
        case AST_STATE_LIST:
            printf(",\n");
            ast_print(ast->left, indent + 1);
            ast_print(ast->right, indent + 1);
            break;
        case AST_ARR_ACCESS:
            printf("ACC\n");
            ast_print(ast->left, indent + 1);
            ast_print(ast->right, indent + 1);
            break;
        case AST_FUNC_CALL:
            printf("CALL\n");
            ast_print(ast->left, indent + 1);
            break;
        case AST_INC:
            printf("INC\n");
            if(ast->left == 0)
                ast_print(ast->right, indent + 1);
            else
                ast_print(ast->left, indent + 1);
            break;
        case AST_DEC:
            printf("DEC\n");
            if(ast->left == 0)
                ast_print(ast->right, indent + 1);
            else
                ast_print(ast->left, indent + 1);
            break;
        case AST_DIV:
            printf("/\n");
            ast_print(ast->left, indent + 1);
            ast_print(ast->right, indent + 1);
            break;
        case AST_MOD:
            printf("%%\n");
            ast_print(ast->left, indent + 1);
            ast_print(ast->right, indent + 1);
            break;
        case AST_SUB:
            printf("-\n");
            ast_print(ast->left, indent + 1);
            ast_print(ast->right, indent + 1);
            break;
        case AST_LEFT_OP:
            printf("<<\n");
            ast_print(ast->left, indent + 1);
            ast_print(ast->right, indent + 1);
            break;
        case AST_RIGHT_OP:
            printf(">>\n");
            ast_print(ast->left, indent + 1);
            ast_print(ast->right, indent + 1);
            break;
        case AST_LOWER_EQUAL:
            printf("<=\n");
            ast_print(ast->left, indent + 1);
            ast_print(ast->right, indent + 1);
            break;
        case AST_GREATER_EQUAL:
            printf("<=\n");
            ast_print(ast->left, indent + 1);
            ast_print(ast->right, indent + 1);
            break;
        case AST_GREATER:
            printf(">\n");
            ast_print(ast->left, indent + 1);
            ast_print(ast->right, indent + 1);
            break;
        case AST_LOWER:
            printf("<\n");
            ast_print(ast->left, indent + 1);
            ast_print(ast->right, indent + 1);
            break;
        case AST_NOT_EQUAL:
            printf("!=\n");
            ast_print(ast->left, indent + 1);
            ast_print(ast->right, indent + 1);
            break;
        case AST_EQUAL:
            printf("==\n");
            ast_print(ast->left, indent + 1);
            ast_print(ast->right, indent + 1);
            break;
        case AST_AND:
            printf("&\n");
            ast_print(ast->left, indent + 1);
            ast_print(ast->right, indent + 1);
            break;
        case AST_EOR:
            printf("|\n");
            ast_print(ast->left, indent + 1);
            ast_print(ast->right, indent + 1);
            break;
        case AST_IOR:
            printf("^\n");
            ast_print(ast->left, indent + 1);
            ast_print(ast->right, indent + 1);
            break;
        case AST_AND_OP:
            printf("&&\n");
            ast_print(ast->left, indent + 1);
            ast_print(ast->right, indent + 1);
            break;
        case AST_OR_OP:
            printf("||\n");
            ast_print(ast->left, indent + 1);
            ast_print(ast->right, indent + 1);
            break;
        case AST_ASSIGN:
            printf("=\n");
            ast_print(ast->left, indent + 1);
            ast_print(ast->right, indent + 1);
            break;
        case AST_DEC_LIST:
            printf("DEC\n");
            ast_print(ast->right, indent + 1);
            break;
        case AST_FOR:
            printf("FOR\n");
            ast_print(ast->assign, indent + 1);
            ast_print(ast->cond, indent + 1);
            ast_print(ast->inc, indent + 1);
            ast_print(ast->core, indent + 1);
            break;
        case AST_PRINTF:
            printf("PRINTF()\n");
            break;
    };
}