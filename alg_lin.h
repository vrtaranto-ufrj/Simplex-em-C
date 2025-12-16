#pragma once

#include <stdlib.h>

#include "utils.h"

typedef struct VetorStruct Vetor;
typedef struct MatrizStruct Matriz;

struct VetorStruct {
    float *dados;
    size_t tamanho;
};

struct MatrizStruct {
    float *dados;
    size_t linhas;
    size_t colunas;
};

erro inicializa_vetor(Vetor *vetor, size_t tamanho);
void free_vetor(Vetor *vetor);

erro inicializa_matriz(Matriz *matriz, size_t linhas, size_t colunas);
void free_matriz(Matriz *matriz);
