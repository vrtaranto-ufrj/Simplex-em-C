#include <stdlib.h>
#include <assert.h>
#include <stdio.h>
#include <string.h>

#include "utils.h"
#include "alg_lin.h"

erro inicializa_matriz(
    Matriz *matriz,
    size_t linhas,
    size_t colunas
) {
    matriz->dados = (float *) calloc(linhas * colunas, sizeof(float));
    if (matriz->dados == NULL) {
        return MALLOC;
    }
    
    matriz->linhas = linhas;
    matriz->colunas = colunas;

    return SUCESSO;
}

void free_matriz(Matriz *matriz) {
    free(matriz->dados);
}

void set_zero_matriz(Matriz *matriz) {
    memset(
        matriz->dados,
        0,
        matriz->linhas * matriz->colunas * sizeof(float)
    );
}

void copia_matriz(Matriz *destino, Matriz *origem) {
    assert(origem->linhas == destino->linhas);
    assert(origem->colunas == destino->colunas);

    memcpy(destino->dados, origem->dados, origem->linhas * origem->colunas * sizeof(float));
}

float get_matriz(Matriz *matriz, size_t x, size_t y) {
    return matriz->dados[y + x * matriz->colunas];
}

void set_matriz(Matriz *matriz, size_t x, size_t y, float valor) {
    matriz->dados[y + x * matriz->colunas] = valor;
}

void set_soma_matriz(Matriz *matriz, size_t x, size_t y, float valor) {
    matriz->dados[y + x * matriz->colunas] += valor;
}

void multiplica_matriz(Matriz *matriz1, Matriz *matriz2, Matriz *matriz_resultado) {
    assert(matriz1->colunas == matriz2->linhas);

    for (size_t j = 0; j < matriz2->colunas; j++) {
        for (size_t k = 0; k < matriz1->colunas; k++) {
            for (size_t i = 0; i < matriz1->linhas; i++) {
                set_soma_matriz(
                    matriz_resultado,
                    i,
                    j, 
                    get_matriz(matriz1, i, k) * get_matriz(matriz2, k, j)
                );
            }
        }
    }
    
}

void soma_matriz(Matriz *matriz1, Matriz *matriz2, Matriz *matriz_resultado) {
    assert(matriz1->linhas == matriz2->linhas);
    assert(matriz1->colunas == matriz2->colunas);

    for (size_t j = 0; j < matriz1->colunas; j++) {
        for (size_t i = 0; i < matriz1->linhas; i++) {
            set_soma_matriz(
                matriz_resultado,
                i,
                j, 
                get_matriz(matriz1, i, j) + get_matriz(matriz2, i, j)
            );
        }
    } 
}

void subtrai_matriz(Matriz *matriz1, Matriz *matriz2, Matriz *matriz_resultado) {
    assert(matriz1->linhas == matriz2->linhas);
    assert(matriz1->colunas == matriz2->colunas);

    for (size_t j = 0; j < matriz1->colunas; j++) {
        for (size_t i = 0; i < matriz1->linhas; i++) {
            set_soma_matriz(
                matriz_resultado,
                i,
                j, 
                get_matriz(matriz1, i, j) - get_matriz(matriz2, i, j)
            );
        }
    } 
}

void transforma_lu_matriz(Matriz *A) {
    size_t n = A->linhas;

    for (size_t k = 0; k < n - 1; k++) {
        for (size_t i = k + 1; i < n; i++) {
            set_matriz(
                A,
                i,
                k,
                get_matriz(A, i, k) / get_matriz(A, k, k)
            );
        }
        for (size_t i = k + 1; i < n; i++) {
            for (size_t j = k + 1; j < n; j++) {
                set_matriz(
                    A,
                    i,
                    j,
                    get_matriz(A, i, j) - get_matriz(A, i, k) * get_matriz(A, k, j)
                );
            } 
        }
    }
}

void transforma_l_matriz(Matriz *LU) {
    for (size_t j = 0; j < LU->colunas; j++) {
        for (size_t i = 0; i < LU->linhas; i++) {
            float valor;

            if (i == j) {
                valor = 1;
            } else if (j > i) {
                valor = 0;
            } else {
                valor = get_matriz(LU, i, j);
            }
            
            set_matriz(
                LU,
                i,
                j,
                valor
            );
        }
    }
}

void transforma_u_matriz(Matriz *LU) {
    for (size_t j = 0; j < LU->colunas; j++) {
        for (size_t i = 0; i < LU->linhas; i++) {
            float valor;

            if (i > j) {
                valor = 0;
            } else {
                valor = get_matriz(LU, i, j);
            }
            
            set_matriz(
                LU,
                i,
                j,
                valor
            );
        }
    }
}

void resolve_l(Matriz *L, Vetor *x, Vetor *b) {
    size_t n = x->linhas;

    set_matriz(
        x,
        0,
        0,
        get_matriz(b, 0, 0) / get_matriz(L, 0, 0)
    );

    for (size_t i = 1; i < n; i++) {
        float soma = 0;
        for (size_t j = 0; j < i; j++) {
            soma += get_matriz(L, i, j) * get_matriz(x, j, 0);
        }
        set_matriz(
            x,
            i,
            0,
            (get_matriz(b, i, 0) - soma)
        ); 
    }
}

void resolve_u(Matriz *U, Vetor *x, Vetor *b) {
    size_t n = x->linhas;

    set_matriz(
        x,
        n - 1,
        0,
        get_matriz(b, n - 1, 0) / get_matriz(U, n - 1, n - 1)
    );

    for (size_t i = n - 1; i-- > 0; ) {
        float soma = 0;
        for (size_t j = i + 1; j < n; j++) {
            soma += get_matriz(U, i, j) * get_matriz(x, j, 0);
        }
        set_matriz(
            x,
            i,
            0,
            (get_matriz(b, i, 0) - soma)  / get_matriz(U, i, i)
        ); 
    }
}

void print_matriz(Matriz *matriz) {
    for (size_t i = 0; i < matriz->linhas; i++) {
        for (size_t j = 0; j < matriz->colunas; j++) {
            printf("%.2f ", get_matriz(matriz, i, j));
        }
        printf("\n");
    }
}
