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

    printf("\n%s\n", t.valor);
    if(!strcmp("BEGIN", t.valor))
        printf("\nSUCESSO\n");

    t = getToken();
    printf("\n%s\n", t.valor);
    if(!strcmp("END", t.valor))
        printf("\nSUCESSO\n");


    printf("FIM");

    fclose(f);
    return 0;
}

