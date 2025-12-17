#pragma once

#include <stdlib.h>

#include "utils.h"

typedef struct MatrizStruct Matriz;

struct MatrizStruct {
    float *dados;
    size_t linhas;
    size_t colunas;
};

erro inicializa_matriz(Matriz *matriz, size_t linhas, size_t colunas);
void free_matriz(Matriz *matriz);
void set_zero_matriz(Matriz *matriz);
void copia_matriz(Matriz *destino, Matriz *origem);

float get_matriz(Matriz *matriz, size_t x, size_t y);
void set_soma_matriz(Matriz *matriz, size_t x, size_t y, float valor);
void set_matriz(Matriz *matriz, size_t x, size_t y, float valor);

void multiplica_matriz(Matriz *matriz1, Matriz *matriz2, Matriz *matriz_resultado);
void soma_matriz(Matriz *matriz1, Matriz *matriz2, Matriz *matriz_resultado);
void subtrai_matriz(Matriz *matriz1, Matriz *matriz2, Matriz *matriz_resultado);

void transforma_lu_matriz(Matriz *A);
void transforma_l_matriz(Matriz *LU);
void transforma_u_matriz(Matriz *LU);

void print_matriz(Matriz *matriz);
