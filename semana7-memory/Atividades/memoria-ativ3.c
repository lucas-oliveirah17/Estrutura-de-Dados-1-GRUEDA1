#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main() {
    int **matriz1, **matriz2, **soma;
    int linhas, colunas;

    setlocale(LC_ALL, "");
    printf("Atividade 3 - Alocação de Memória\n\n");

    // Solicita as dimensões da matriz
    printf("Digite o número de linhas das matrizes: ");
    scanf("%d", &linhas);
    printf("Digite o número de colunas das matrizes: ");
    scanf("%d", &colunas);

    // Alocação dinâmica para matriz1
    matriz1 = (int**) malloc(linhas * sizeof(int*));
    for (int i = 0; i < linhas; i++) {
        matriz1[i] = (int*) malloc(colunas * sizeof(int));
    }

    // Alocação dinâmica para matriz2
    matriz2 = (int**) malloc(linhas * sizeof(int*));
    for (int i = 0; i < linhas; i++) {
        matriz2[i] = (int*) malloc(colunas * sizeof(int));
    }

    // Alocação dinâmica para matriz de soma
    soma = (int**) malloc(linhas * sizeof(int*));
    for (int i = 0; i < linhas; i++) {
        soma[i] = (int*) malloc(colunas * sizeof(int));
    }

    // Coleta os elementos da matriz1
    printf("\nDigite os elementos da primeira matriz (%dx%d):\n", linhas, colunas);
    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            printf("Elemento [%d][%d]: ", i, j);
            scanf("%d", &matriz1[i][j]);
        }
    }

    // Coleta os elementos da matriz2
    printf("\nDigite os elementos da segunda matriz (%dx%d):\n", linhas, colunas);
    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            printf("Elemento [%d][%d]: ", i, j);
            scanf("%d", &matriz2[i][j]);
        }
    }

    // Calcula a soma das duas matrizes
    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            soma[i][j] = matriz1[i][j] + matriz2[i][j];
        }
    }

    //Impressão das duas matrizes
    printf("\nMatriz 1 + Matriz 2 (%dx%d):\n\n", linhas, colunas);
    for(int i = 0; i < linhas; i++) {
            for (int j = 0; j < colunas; j++) {
            printf("%4d ", matriz1[i][j]);
        }
            printf("\t");
            for (int j = 0; j < colunas; j++) {
                printf("%4d ", matriz2[i][j]);
        }
        printf("\n");
    }

    // Imprime a matriz resultante (soma)
    printf("\nMatriz resultante da soma (%dx%d):\n\n", linhas, colunas);
    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            printf("%4d ", soma[i][j]);
        }
        printf("\n");
    }

    // Libera a memória alocada para as três matrizes
    for (int i = 0; i < linhas; i++) {
        free(matriz1[i]);
        free(matriz2[i]);
        free(soma[i]);
    }
    free(matriz1);
    free(matriz2);
    free(soma);

    return 0;
}
