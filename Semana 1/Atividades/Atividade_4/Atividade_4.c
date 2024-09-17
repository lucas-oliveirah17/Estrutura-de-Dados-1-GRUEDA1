#include <stdio.h>
#include <stdlib.h>

int main() {
    printf("Atividade 4:\n");
    // Declaração dos vetores com 5 posições:
    int v1[5], v2[5];
    int i, j;

    // Preenchendo vetor v1
    for (i = 0; i < 5; i++) {
        printf("\nInforme o valor do elemento %d do vetor 1: ", i + 1);
        // Leitura e inserção do valor em cada posição do vetor:
        scanf("%d", &v1[i]);
    }

    // Preenchendo vetor v2
    for (j = 0; j < 5; j++) {
        printf("\nInforme o valor do elemento %d do vetor 2: ", j + 1);
        // Leitura e inserção do valor em cada posição do vetor:
        scanf("%d", &v2[j]);
    }

    for (i = 0; i < 5; i++) {
        for (j = 0; j < 5; j++) {
            // Exibindo valores que são comuns aos dois vetores:
            if (v1[i] == v2[j]) {
                printf("\nValores iguais na posicao: %d e %d\n", i + 1, j + 1);
            }
        }
    }

    printf("\nVetor v1: ");
    for (i = 0; i < 5; i++) {
        printf("%d ", v1[i]);
    }

    printf("\nVetor v2: ");
    for (j = 0; j < 5; j++) {
        printf("%d ", v2[j]);
    }
    printf("\n");
    printf("\nVetor v1: %d", v1);
    printf("\nVetor v2: %d\n", v2);
    system("pause");
    return 0;
}
