#include <stdio.h>

#include "alg_lin.h"

int main(void) {
    Matriz matriz1, matriz2, matriz3;

    inicializa_matriz(&matriz1, 3, 3);
    inicializa_matriz(&matriz2, 3, 3);
    inicializa_matriz(&matriz3, 3, 3);
    
    set_matriz(&matriz1, 0, 0, 1);
    set_matriz(&matriz1, 1, 0, 4);
    set_matriz(&matriz1, 2, 0, 4);

    set_matriz(&matriz1, 0, 1, 2);
    set_matriz(&matriz1, 1, 1, 4);
    set_matriz(&matriz1, 2, 1, 6);

    set_matriz(&matriz1, 0, 2, 2);
    set_matriz(&matriz1, 1, 2, 2);
    set_matriz(&matriz1, 2, 2, 4);


    set_matriz(&matriz2, 0, 0, 0);
    set_matriz(&matriz2, 1, 0, 1);
    set_matriz(&matriz2, 2, 0, 2);

    set_matriz(&matriz2, 0, 1, 3);
    set_matriz(&matriz2, 1, 1, 4);
    set_matriz(&matriz2, 2, 1, 5);

    set_matriz(&matriz2, 0, 1, 6);
    set_matriz(&matriz2, 1, 1, 7);
    set_matriz(&matriz2, 2, 1, 8);
    
    soma_matriz(&matriz1, &matriz2, &matriz3);

    // print_matriz(&matriz1);

    transforma_lu_matriz(&matriz1);

    // set_zero_matriz(&matriz3);
    print_matriz(&matriz1);

    transforma_u_matriz(&matriz1);
    print_matriz(&matriz1);

    free_matriz(&matriz1);
    free_matriz(&matriz2);
    free_matriz(&matriz3);

    return 0;
}