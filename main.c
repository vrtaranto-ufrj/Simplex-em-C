#include <stdio.h>

#include "alg_lin.h"

int main(void) {
    Vetor vetor;
    Matriz matriz;

    inicializa_vetor(&vetor, 100000000);
    inicializa_matriz(&matriz, 1000000, 1000000);

    free_vetor(&vetor);
    free_matriz(&matriz);

    return 0;
}