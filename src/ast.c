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
ast* ast_new_unary_operation(ast_type type, ast* op) {
    ast* new = malloc(sizeof(ast));
    new->type = type;
    new->unary_ast = op;
    return new;
}

ast* ast_new_number(int number) {
    ast* new = malloc(sizeof(ast));
    new->type = AST_NUMBER;
    new->i_number = number;
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
            ast_free(ast->left);
            ast_free(ast->right);
            break;
        case AST_MUL:
        case AST_LIST:
            ast_free(ast->left);
            ast_free(ast->right);
            break;
        case AST_FLOAT:
            break;

        case AST_ARR_ACCESS:
            break;
        case AST_FUNC_CALL:
            break;
        case AST_INC:
            break;
        case AST_DEC:
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
            printf("NUMBER_I (%d)\n", ast->i_number);
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
        case AST_FLOAT:
            printf("NUMBER_F (%f)\n", ast->f_number);
            break;
        case AST_LIST:
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
    };
}