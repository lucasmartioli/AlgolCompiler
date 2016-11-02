//
// Created by sutil on 02/11/16.
//

#include "matchers.h"

#include <regex.h>
#include <stddef.h>

char* palavrasReservadas[] = {"BEGIN",
                              "END",
                              "CHAR",
                              "IF",
                              "THEN",
                              "ELSE",
                              "ELIF",
                              "FI",
                              "REAL",
                              "BOOL",
                              "read",
                              "print"};

char* simbolos[] = {"[",
                    "]",
                    ",",
                    ";",
                    "(",
                    ")",
                    ">",
                    "<"};



int isInteiro(char *token){
    char * valor = token;
    regex_t inteiro_pattern;
    if(regcomp(&inteiro_pattern, "[0-9]+", REG_EXTENDED|REG_NOSUB) != 0){
        return 0;
    }

    int result = regexec(&inteiro_pattern, valor, (size_t) 0, NULL, 0);
    regfree(&inteiro_pattern);

    return !result;
}

int isIdentificador(char *valor){
    regex_t identificador_pattern;
    if(regcomp(&identificador_pattern, "", REG_EXTENDED|REG_NOSUB) != 0){
        return 0;
    }

    int result = regexec(&identificador_pattern, valor, (size_t) 0, NULL, 0);
    regfree(&identificador_pattern);

    return !result;
}