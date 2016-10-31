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
FILE *file;
char caracterAtual;

char separadores[] = {'=', '.', EOF};
char separadoresDescartaveis[] = {'\n', ' ', '\t'};

void readChar() {
    caracterAtual = fgetc(file);
}

int caracterAtualEhUmSeparadorDescartavel() {
    int tamanho = sizeof(separadoresDescartaveis);
    for (int i = 0; i < tamanho; ++i)
        if (separadoresDescartaveis[i] == caracterAtual)
            return 1;

    return 0;
}

int caracterAtualEhUmSeparador() {
    int tamanho = sizeof(separadores);
    for (int i = 0; i < tamanho; ++i)
        if (separadores[i] == caracterAtual || EOF == caracterAtual)
            return 1;

    return 0;
}

char *toString(char caracter) {
    char retorno[2];
    retorno[0] = caracter;
    retorno[1] = '\0';

    return retorno;
}

void adicionaCaracterAoToken() {
    if (tokenAtual->valor == NULL)
        tokenAtual->valor = "";

    char *a = tokenAtual->valor;

    char b[2];
    b[0] = !caracterAtualEhUmSeparadorDescartavel() ? caracterAtual : '\000';
    b[1] = '\0';

    size_t ta = strlen(a) + strlen(b) + 1;
    char *r = (char *) malloc(ta);
    strcpy(r, a);
    strcat(r, b);

    tokenAtual->valor = r;
}

void readToken() {
    if(caracterAtual == '\000')
        readChar();

    while (caracterAtualEhUmSeparadorDescartavel())
        readChar();

    if(caracterAtualEhUmSeparador()) {
        adicionaCaracterAoToken();
        readChar();
        return;
    }

    while (!caracterAtualEhUmSeparador() && !caracterAtualEhUmSeparadorDescartavel()) {
        adicionaCaracterAoToken();
        readChar();
    }

}

Token getToken() {
    tokenAtual = (Token *) malloc(sizeof(Token));
    readToken();
    return *tokenAtual;
}

void inicializa(FILE *f) {
    file = f;
}
