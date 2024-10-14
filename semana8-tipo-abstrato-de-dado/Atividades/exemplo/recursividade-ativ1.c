#include <stdio.h>
#include <locale.h>
#include "my_lib.h"

int main() {
    int valor;

    setlocale(LC_ALL, "");
    printf("Atividade 1 - Recursividade\n\n");

    // Solicita o valor de n ao usuário
    printf("Digite um valor para iniciar a contagem regressiva: ");
    scanf(" %d", &valor);

    // Executa a contagem regressiva iterativa
    contagem_regressiva_iterativa(valor);

    // Executa a contagem regressiva recursiva
    printf("\nContagem regressiva (Recursiva): ");
    contagem_regressiva_recursiva(valor);

    return 0;
}
