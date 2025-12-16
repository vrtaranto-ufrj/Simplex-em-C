#include <stdlib.h>

#include "utils.h"
#include "alg_lin.h"

erro inicializa_vetor(Vetor *vetor, size_t tamanho) {
    vetor->dados = (float *) calloc(tamanho, sizeof(float));
    if (vetor->dados == NULL) {
        return MALLOC;
    }
    vetor->tamanho = tamanho;

    return SUCESSO;
}

void free_vetor(Vetor *vetor) {
    free(vetor->dados);
}

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
