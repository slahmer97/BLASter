//
// Created by slahmer on 12/28/19.
//

#ifndef BLASTER_AST_H
#define BLASTER_AST_H
typedef enum ast_type { AST_ID, AST_NUMBER,AST_FLOAT, AST_ADD, AST_MUL,AST_LIST,AST_ARR_ACCESS,AST_FUNC_CALL,AST_INC,AST_DEC } ast_type;

typedef struct ast {
    ast_type type;
    union {
        int i_number;
        float f_number;
        char* id;
        struct {
            struct ast* left;
            struct ast* right;
        };
        struct {
            struct ast* unary_ast;
        };
    };
} ast;

ast* ast_new_operation(ast_type, ast*, ast*);
ast* ast_new_unary_operation(ast_type type, ast* op);
ast* ast_new_number(int);
ast* ast_new_float(float);
ast* ast_new_id(char*);
void ast_free(ast*);
void ast_print(ast*, int);
#endif //BLASTER_AST_H
