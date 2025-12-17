#include "alg_lin.h"

typedef enum SimplexResultEnum SimplexResult;

enum SimplexResultEnum {
    OTIMO,
    ILIMITADO,
    INVIAVEL
};


erro simplex(
    Matriz *A,
    Vetor *x,
    Vetor *b,
    Vetor *c,
    float *valor_funcao_obj,
    SimplexResult *resultado
);
