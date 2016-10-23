//
// Created by Lucas on 9/27/2016.
//

#include <iostream>
#include "lexico.h"

int main(int argc, char *argv[]) {

    std::cout << argc << std::endl;
    std::cout << argv[1] << std::endl;

    FILE *f = fopen(argv[1], "rt");

    inicializa(f);

    Token t = getToken();

    std::cout << t.valor << std::endl;
    if(t.valor != "BEGIN")
        std::cout << "ERRO. Eu esperava um BEGIN." << std::endl;

    std::cout << "FIM!" << std::endl;

    fclose(f);
    return 0;
}

