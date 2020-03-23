//
// Created by abdo on 3/23/20.
//

/*

expression → digit | ’(’ expression operator expression ’)’
operator → ’+’ | ’ * ’
digit → ’0’ | ’1’ | ’2’ | ’3’ | ’4’ | ’5’ | ’6’ | ’7’ | ’8’ | ’9’

 */

#include <stdlib.h>
#include "parser.h"
#include "lex.h"
#include "error.h"

/* private */

static Expression* new_expression(){
    return (Expression*)malloc(sizeof(Expression));
}

static void free_expression(Expression* expr){
    free((void*)expr);
}

static int parse_expression(Expression** expr_p);

static int parse_operator(Operator* oper_p);

static int parse_expression(Expression** expr_p) {
    Expression* expr = *expr_p = new_expression();

    /* try to parse a digit: */
    if(Token.class == DIGIT){
        expr->type = 'D';
        expr->value = Token.repr - '0';
        get_next_token();
        return 1;
    }

    /* try to parse a parenthesized expression */
    if(Token.class == '('){
        expr->type = 'P';
        get_next_token();

        if(!parse_expression(&expr->left)){
            error("Missing expression");
        }

        if(!parse_operator(&expr->oper)){
            error("Missing operator");
        }

        if(!parse_expression(&expr->right)){
            error("Missing expression");
        }

        if(Token.class != ')'){
            error("Missing: ')'");
        }
        get_next_token();
        return 1;
    }

    /* failed on both attempts */
    free_expression(expr);
    return 0;
}

static int parse_operator(Operator* oper_p) {
    if(Token.class == '+'){
        *oper_p = '+';
        get_next_token();
        return 1;
    } else if(Token.class == '*'){
        *oper_p = '*';
        get_next_token();
        return 1;
    } else{
        return 0;
    }
}

/* public */

int parse_program(AST_node **icode_p) {
    Expression* expr;

    get_next_token(); /* start the lexical analyzer */
    if(parse_expression(&expr)){
        if(Token.class != EoF){
            error("Garbage after end of program\n");
        }
        *icode_p = expr;
        return 1;
    }
    return 0;
}

