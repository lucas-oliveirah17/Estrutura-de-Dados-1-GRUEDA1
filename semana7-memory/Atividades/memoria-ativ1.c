#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main() {
    // Declaração das variáveis e ponteiro
    int n_impares, *vetor, numero = 1;

    setlocale(LC_ALL, "");
    printf("Atividade 1 - Alocação de Memória\n\n");

    // Solicita a quantidade de números ímpares que o usuário deseja armazenar
    printf("Digite a quantidade de números ímpares: ");
    scanf("%d", &n_impares);

    // Aloca memória dinamicamente para o vetor
    vetor = (int*) malloc(n_impares * sizeof(int));
    if (vetor == NULL) {
        printf("ERRO: Sem memória!\n");
        exit (1);
    }

    // Preenche o vetor com números ímpares
    for (int i = 0; i < n_impares; i++) {
        vetor[i] = numero;
        numero += 2; // Gera o próximo número ímpar
    }

    // Imprime o vetor de números ímpares
    printf("Vetor de números ímpares:\n");
    for (int i = 0; i < n_impares; i++) {
        printf("%d ", vetor[i]);
    }
    printf("\n");

    // Libera a memória alocada
    free(vetor);

    return 0;
}

