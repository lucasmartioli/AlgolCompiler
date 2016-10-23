//
// Created by eduardo.sutil on 17/10/16.
//

#ifndef ALGOLCOMPILER_LEXICO_H
#define ALGOLCOMPILER_LEXICO_H

struct token
{
    char *nome;
    char *valor;
    int linha;
    int coluna;
};
typedef struct token Token;

void inicializa(FILE * file);

Token getToken();

#endif //ALGOLCOMPILER_LEXICO_H
