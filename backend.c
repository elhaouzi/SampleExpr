//
// Created by abdo on 3/23/20.
//

#include "backend.h"
#include "parser.h"
#include <stdio.h>


/* private */
static void code_gen_expression(Expression* expr){
    switch (expr->type){
        case 'D':
            printf("PUSH %d\n", expr->value);
            break;
        case 'P':
            code_gen_expression(expr->left);
            code_gen_expression(expr->right);
            switch (expr->oper){
                case '+':
                    printf("ADD\n");
                    break;
                case '*':
                    printf("MUL\n");
                    break;
            }
            break;
    }
}


int interpret_expression(Expression *expr) {
    switch (expr->type){
        case 'D':
            return expr->value;
        case 'P':{
            int e_left = interpret_expression(expr->left);
            int e_right = interpret_expression(expr->right);
            switch (expr->oper){
                case '+':
                    return e_left + e_right;
                case '*':
                    return e_left * e_right;
            }
            break;
        }
    }
}

/* public */


void process(AST_node *icode) {
    code_gen_expression(icode);
    printf("PRINT\n");
}

void execute(AST_node* icode){
    printf("%d\n", interpret_expression(icode));
}
