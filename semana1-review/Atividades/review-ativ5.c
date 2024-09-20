/*
• Codifique o programa matrizes 5 x 5, em todas as suas etapas exemplificada anteriormente;
• Complete o programa adicionando um bloco de código para a rotina de impressão afim de visualizar a
  matriz no console (tela do terminal). Este bloco deve imprimir o conteúdo da matriz em tela, no
  formato de uma matriz, ou seja, com linhas e colunas;
• Entregue o arquivo fonte (.c ) na plataforma Moodle, na entrada atividade 5.
*/
#include<stdio.h>
#include<stdlib.h>

int main() {
    // Declaração da matriz com 5 linhas e 5 colunas:
    int mtrx[5] [5], v[10];
    int i = 0, j = 0, soma = 0;

    for(i = 0; i < 5; i++) {
        for (j = 0; j < 5; j++) {
            printf("Digite os valores da matriz na posicao: %d e %d: ", i, j);
            // Efetura a leitura de todos os campos da matriz
            scanf("%d", &mtrx[i] [j]);
        }
    }

    /* Somas as linhas da matriz, percorre por todas as colunas
       através do "j" e por todas as linhas através do "i".
    */
    printf("\n\nTotal por linha:\n\n");
    for (i = 0; i < 5; i++) {
        for (j = 0; j < 5; j++) {
            soma = soma + mtrx[i] [j];
        }
        printf("\nLinha %d : soma = %d\n", i + 1, soma);
        v[i] = soma;
        soma = 0;
    }

    /* Soma as colunas da matriz, percorre todas as linhas
       através do "i" e todas as colunas através do "j"
    */
    printf("\n\nTotal por coluna:\n\n");
    for (j = 0; j < 5; j++) {
        for (i = 0; i < 5; i++) {
            soma = soma + mtrx[i] [j];
        }
        printf("\nColuna %d : soma = %d\n", j + 1, soma);
        v[j + 5] = soma;
        soma = 0;
    }

    // Totalização linhas e colunas
    for (i = 0; i < 5; i++) {
        printf("\nOs valores da soma da linha %d sao: %d\n", i + 1, v[i]);
        printf("\nOs valores da soma da coluna %d sao: %d\n", i +  1, v[i + 5]);
    }

    // Imprimindo a matriz
    printf("\nMatriz 1:\n\n\t");
    for(i = 0; i < 5; i++) {
        for(j = 0; j < 5; j++) {
            printf("%d ", mtrx[i] [j]);
        }
        printf("\n\t");
    }

    printf("\n\n\n");
    system("pause");
    return 0;
}
