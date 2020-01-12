//
// Created by slahmer on 12/28/19.
//

#ifndef BLASTER_AST_H
#define BLASTER_AST_H
typedef enum ast_type { AST_ID,AST_ASSIGN, AST_NUMBER,AST_FLOAT, AST_ADD,AST_SUB, AST_MUL,AST_DIV,
                        AST_MOD,AST_LIST,AST_ARR_ACCESS,AST_FUNC_CALL,AST_INC,AST_DEC, AST_WHILE,
                        AST_LEFT_OP,AST_RIGHT_OP,AST_LOWER_EQUAL,AST_GREATER_EQUAL,AST_FOR,AST_PRINTF,
                        AST_GREATER,AST_LOWER,AST_NOT_EQUAL,AST_EQUAL,AST_AND,AST_EOR,AST_IOR,
                        AST_AND_OP,AST_OR_OP,AST_EXPR_LIST,AST_INIT_LIST,AST_DEC_LIST,AST_STATE_LIST} ast_type;

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
            struct ast* assign;
            struct ast* cond;
            struct ast* inc;
            struct ast* core;
        };
    };
} ast;

ast* ast_new_operation(ast_type, ast*, ast*);
ast* ast_new_number(int);
ast* ast_new_float(float);
ast* ast_new_id(char*);
ast* ast_new_for(struct ast*,struct ast*,struct ast*,struct ast*);
ast* ast_new_print();
void ast_free(ast*);
void ast_print(ast*, int);
#endif //BLASTER_AST_H
