//
// Created by abdo on 3/23/20.
//

#include <stdio.h>
#include "lex.h"

/* private */
static int is_layout_char(int ch){
    switch (ch){
        case ' ':
        case '\t':
        case '\n':
            return 1;
        default:
            return 0;
    }
}

/* public */

Token_type Token;

void get_next_token(){
    int ch;

    /* get a non-layout character */
    do{
        ch = getchar();
        if(ch < 0){
            Token.class = EoF;
            Token.repr = '#';
        }
    }while (is_layout_char(ch));

    /* classify it: */
    if(ch >= '0' && ch<= '9'){
        Token.class = DIGIT;
        Token.repr = ch;
    } else{
        Token.class = ch;
        Token.repr = ch;
    }

}


