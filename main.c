/*

expression → digit | ’(’ expression operator expression ’)’
operator → ’+’ | ’ * ’
digit → ’0’ | ’1’ | ’2’ | ’3’ | ’4’ | ’5’ | ’6’ | ’7’ | ’8’ | ’9’

 */


#include <stdio.h>

#include "parser.h"
#include "backend.h"
#include "error.h"


int main() {

    AST_node* icode;

    printf(">");

    if(!parse_program(&icode)){
        error("No top-level expression");
    }

    printf("code:\n");
    process(icode);

    printf("execute:\n");

    execute(icode);

    return 0;
}
