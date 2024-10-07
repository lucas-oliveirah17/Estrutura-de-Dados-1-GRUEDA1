#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main() {
    // Declara��o das vari�veis e ponteiro
    int n_impares, *vetor, numero = 1;

    setlocale(LC_ALL, "");
    printf("Atividade 1 - Aloca��o de Mem�ria\n\n");

    // Solicita a quantidade de n�meros �mpares que o usu�rio deseja armazenar
    printf("Digite a quantidade de n�meros �mpares: ");
    scanf("%d", &n_impares);

    // Aloca mem�ria dinamicamente para o vetor
    vetor = (int*) malloc(n_impares * sizeof(int));
    if (vetor == NULL) {
        printf("ERRO: Sem mem�ria!\n");
        exit (1);
    }

    // Preenche o vetor com n�meros �mpares
    for (int i = 0; i < n_impares; i++) {
        vetor[i] = numero;
        numero += 2; // Gera o pr�ximo n�mero �mpar
    }

    // Imprime o vetor de n�meros �mpares
    printf("Vetor de n�meros �mpares:\n");
    for (int i = 0; i < n_impares; i++) {
        printf("%d ", vetor[i]);
    }
    printf("\n");

    // Libera a mem�ria alocada
    free(vetor);

    return 0;
}

