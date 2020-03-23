//
// Created by abdo on 3/23/20.
//

#ifndef SAMPLEEXPR_LEX_H
#define SAMPLEEXPR_LEX_H

/* Define class constants */
/* Values 0-255 are reserved for ASCII characters */

#define EoF ';'
#define DIGIT 257

typedef struct {
    int class;
    char repr;
} Token_type;

extern Token_type Token;
extern void get_next_token();



#endif //SAMPLEEXPR_LEX_H
