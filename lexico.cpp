//
// Created by eduardo.sutil on 17/10/16.
//

#include <malloc.h>
#include <string.h>
#include "lexico.h"

/**
 * receber um ponteiro de arquivo,
 * identificar o próximo token
 * e enviar.
 * @return
 */

int linha;
int coluna;
Token *tokenAtual;
FILE * file;
char caracterAtual;

char separadores[] = {'='};

void readChar(){
    caracterAtual = fgetc(file);
}

int caracterAtualEhUmSeparador(){
    int tamanho = sizeof(separadores);
    for (int i = 0; i < tamanho; ++i)
        if(separadores[i] == caracterAtual || EOF == caracterAtual)
            return 1;

    return 0;
}

void adicionaCaracterAoToken(){
    if(tokenAtual->valor == NULL)
        tokenAtual->valor = &caracterAtual;

    else{
        //concatenar caracterAtual na string
    }


}

void readToken(){
    while(!caracterAtualEhUmSeparador()){
        readChar();
        adicionaCaracterAoToken();
    }
}

Token getToken(){
    Token *token = (Token *) malloc(sizeof(Token));
    readToken();
    return *token;
}

void inicializa(FILE * f){
    file = f;
    tokenAtual = (Token *) malloc(sizeof(Token));
}
