//
// Created by Lucas on 9/27/2016.
//

#include <iostream>
#include <string.h>
#include "lexico.h"

int main(int argc, char *argv[]) {

    std::cout << argc << std::endl;
    std::cout << argv[1] << std::endl;

    FILE *f = fopen(argv[1], "rt");

    inicializa(f);

    Token t = getToken();
    printf("\nToken.valor >%s<", t.valor);

    while(strcmp(".", t.valor)){
        t = getToken();
        printf("\nToken.valor>%s<", t.valor);
    }


    printf("FIM");

    fclose(f);
    return 0;
}

