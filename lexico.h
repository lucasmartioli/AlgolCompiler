//
// Created by eduardo.sutil on 17/10/16.
//

#ifndef ALGOLCOMPILER_LEXICO_H
#define ALGOLCOMPILER_LEXICO_H

struct token
{
    char *nome;
    char *valor;
};
typedef struct token Token;


Token getToken();

#endif //ALGOLCOMPILER_LEXICO_H
