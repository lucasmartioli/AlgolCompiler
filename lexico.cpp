//
// Created by eduardo.sutil on 17/10/16.
//

#include <malloc.h>
#include "lexico.h"

/**
 * receber um ponteiro de arquivo,
 * identificar o próximo token
 * e enviar.
 * @return
 */

Token getToken(){
    Token *token = (Token *) malloc(sizeof(Token));
    return *token;
}
