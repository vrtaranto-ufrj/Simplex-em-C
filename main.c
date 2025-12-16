#include <stdio.h>

#include "alg_lin.h"

int main(void) {
    Matriz matriz1, matriz2, matriz3;

    inicializa_matriz(&matriz1, 3, 3);
    inicializa_matriz(&matriz2, 3, 2);
    inicializa_matriz(&matriz3, 3, 2);
    
    set_matriz(&matriz1, 0, 0, 1);
    set_matriz(&matriz1, 1, 0, 2);
    set_matriz(&matriz1, 2, 0, 3);

    set_matriz(&matriz1, 0, 1, 4);
    set_matriz(&matriz1, 1, 1, 5);
    set_matriz(&matriz1, 2, 1, 6);

    set_matriz(&matriz1, 0, 2, 7);
    set_matriz(&matriz1, 1, 2, 8);
    set_matriz(&matriz1, 2, 2, 9);


    set_matriz(&matriz2, 0, 0, 0);
    set_matriz(&matriz2, 1, 0, 1);
    set_matriz(&matriz2, 2, 0, 2);

    set_matriz(&matriz2, 0, 1, 3);
    set_matriz(&matriz2, 1, 1, 4);
    set_matriz(&matriz2, 2, 1, 5);
    
    multiplica_matriz(&matriz1, &matriz2, &matriz3);

    print_matriz(&matriz3);

    free_matriz(&matriz1);
    free_matriz(&matriz2);
    free_matriz(&matriz3);

    return 0;
}