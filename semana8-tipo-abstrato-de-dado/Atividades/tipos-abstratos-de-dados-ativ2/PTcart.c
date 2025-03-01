#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "PTcart.h" // inclui os prototipos

// Defini��o de tipos de dados- este modelo n�o � exportado
struct pontoCartesiano{
    float x;
    float y;
};

// Aloca e retorna um PTcart com coordenadas "x" e "y"
PTcart *criaPTcart(float x, float y) {
    PTcart *p = (PTcart*) malloc(sizeof(PTcart));
    if(p != NULL) {
        p->x = x;
        p->y = y;
    }
    return p;
}

// Libera a mem�ria alocada para um PTcart
void liberaPTcart(PTcart *p) {
    free(p);
}

// Recupera, por refer�ncia, o valor de um PTcart
void acessaPTcart(PTcart *p, float *x, float *y) {
    *x = p->x;
    *y = p->y;
}

// Atribui a um PTcart as coordenadas "x" e "y"
void atribuiPTcart(PTcart *p, float x, float y) {
    p->x = x;
    p->y = y;
}

// Calcula a dist�ncia entre dois PTcarts
float distanciaPTcart(PTcart *p1, PTcart *p2) {
    float dx = p1->x - p2->x;
    float dy = p1->y - p2->y;
    return sqrt(dx * dx + dy * dy);
}
