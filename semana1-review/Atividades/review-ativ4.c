/*
� Codifique o programa do exemplo anterior e teste seu funcionamento;
� Modifique-o para que imprima em tela os 2 vetores em linhas separadas identificando-os com seu
  nome na impress�o. Em seguida exiba as posi��es em que possuem valores comuns ou se n�o possuem
  (dica: use uma vari�vel para indicar se houve coincid�ncia);
� Entregue somente o arquivo fonte (.c ) na plataforma Moodle, na entrada �Atividade 4�.
*/
#include <stdio.h>
#include <stdlib.h>

int main() {
    // Declara��o dos vetores com 5 posi��es:
    int v1[5], v2[5];
    int i = 0, j = 0, coincide = 0;

    printf("Atividade 4 - Review\n");

    // Preenchendo vetor 1
    for(i = 0; i < 5; i++) {
        printf("\nInforme o valor do elemento %d do vetor 1: ", i + 1);
        //Leitura e inser��o do valor em cada posi��o do vetor:
        scanf(" %d", &v1[i]);
    }

    // Preenchendo vetor 2
    for(j = 0; j < 5; j++) {
        printf("\nInforme o valor do elemento %d do vetor 2: ", j + 1);
        // Leitura e inser��o do valor em cada posi��o do vetor:
        scanf(" %d", &v2[j]);
    }

    // Imprimindo vetor 1
    printf("\nVetor 1: ");
    for(i = 0; i < 5; i++) {
        printf("%d ", v1[i]);
    }

    // Imprimindo vetor 2
    printf("\nVetor 2: ");
    for(j = 0; j < 5; j++) {
        printf("%d ", v2[j]);
    }

    // Verificando coincid�ncia de valores
    printf("\n\nVerificando coincidencias...\n");
    for(i = 0; i < 5; i++) {
        for(j = 0; j < 5; j++) {
            // Exibindo valores que s�o comuns aos dois vetores:
            if(v1[i] == v2[j]) {
                printf("\nValores iguais na posicao: %d e %d\n", i +1, j + 1);
                coincide = 1; // Indicando que houve coincid�ncia
            }
        }
    }

    // Se n�o houver coincid�ncias
    if(!coincide) {
        printf("\nNenhuma coincidencia encontrada.");
    }

    printf("\n\n");
    system("pause");
    return 0;
}
