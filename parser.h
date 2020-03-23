//
// Created by abdo on 3/23/20.
//

#ifndef SMPLEEXPR_PARSER_H
#define SMPLEEXPR_PARSER_H

typedef int Operator;

typedef struct _expression{
    char type;
    int value;
    struct _expression* left;
    struct _expression* right;
    Operator oper;
} Expression;

typedef Expression AST_node;

extern int parse_program(AST_node** icode);


#endif //SMPLEEXPR_PARSER_H
