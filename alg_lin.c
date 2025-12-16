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

void print_matriz(Matriz *matriz) {
    for (size_t i = 0; i < matriz->linhas; i++) {
        for (size_t j = 0; j < matriz->colunas; j++) {
            printf("%.2f ", get_matriz(matriz, i, j));
        }
        printf("\n");
    }
}
