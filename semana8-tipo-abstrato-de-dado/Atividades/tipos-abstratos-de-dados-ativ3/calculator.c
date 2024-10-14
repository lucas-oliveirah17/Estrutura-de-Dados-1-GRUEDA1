#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "calculator.h"
// struct para os valores de saida
struct valuesOUT {
    double last_result;
};

// Aloca a memória para calcOUT
calcOUT *createCalcOUT() {
     calcOUT *p = (calcOUT*) malloc(sizeof(calcOUT));
     if(p != NULL) {
        p->last_result = 0; // Inicializa o ultimo valor com 0
     }
     return p;
}

void freeCalcOUT(calcOUT *p) {
    free(p);
}

// Função para realizar a operacao
double calculate(calcOUT *p, double e1, double e2, char o) {
    if(o == '+') {
        return p->last_result = e1 + e2;
    }
    else if (o == '-') {
        return p->last_result = e1 - e2;
    }
    else if (o == '*') {
        return p->last_result = e1 * e2;
    }
    else if (o == '/') {
        if(e2 == 0) {
            printf("Erro: Divisão por zero!\n\n\n");
            return 0;
        }
        else {
            return p->last_result = e1 / e2;
        }
    }
    return 0; // Operação inválida
}

// Retornar valor anterior
double last_result(calcOUT *p) {
    return p->last_result;
}
