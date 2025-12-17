#include <stdio.h>

#include "alg_lin.h"

int main(void) {
    Matriz A, A_inv;

    inicializa_matriz(&A, 4, 4);
    inicializa_matriz(&A_inv, 4, 4);
    
    // Matriz A (4x4)
    // | 1  2  3  4 |
    // | 2  3  4  1 |
    // | 3  4  1  2 |
    // | 4  1  2  3 |
    set_matriz(&A, 0, 0, 1);
    set_matriz(&A, 0, 1, 2);
    set_matriz(&A, 0, 2, 3);
    set_matriz(&A, 0, 3, 4);

    set_matriz(&A, 1, 0, 2);
    set_matriz(&A, 1, 1, 3);
    set_matriz(&A, 1, 2, 4);
    set_matriz(&A, 1, 3, 1);

    set_matriz(&A, 2, 0, 3);
    set_matriz(&A, 2, 1, 4);
    set_matriz(&A, 2, 2, 1);
    set_matriz(&A, 2, 3, 2);

    set_matriz(&A, 3, 0, 4);
    set_matriz(&A, 3, 1, 1);
    set_matriz(&A, 3, 2, 2);
    set_matriz(&A, 3, 3, 3);

    printf("Matriz Original A:\n");
    print_matriz(&A);
    printf("\n");

    inverte_matriz(&A, &A_inv);

    printf("Matriz Inversa A^(-1):\n");
    print_matriz(&A_inv);
    printf("\n");

    free_matriz(&A);
    free_matriz(&A_inv);

    return 0;
}