#include <stdio.h>
#include <locale.h>

void contagem_regressiva_iterativa(int valor);
void contagem_regressiva_recursiva(int valor);

int main() {
    int valor;

    setlocale(LC_ALL, "");
    printf("Atividade 1 - Recursividade\n\n");

    // Solicita o valor de n ao usu�rio
    printf("Digite um valor para iniciar a contagem regressiva: ");
    scanf(" %d", &valor);

    // Executa a contagem regressiva iterativa
    contagem_regressiva_iterativa(valor);

    // Executa a contagem regressiva recursiva
    printf("\nContagem regressiva (Recursiva): ");
    contagem_regressiva_recursiva(valor);

    return 0;
}

// Fun��o iterativa para contagem regressiva
void contagem_regressiva_iterativa(int valor) {
    printf("\nContagem regressiva (Iterativa): ");
    for (int i = valor; i >= 0; i--) {
        printf("%d ", i);
    }
    printf("\n");
}

// Fun��o recursiva para contagem regressiva
void contagem_regressiva_recursiva(int valor) {
    if (valor < 0) {
        printf("\n");
        return; // Caso base: quando n for menor que 0, termina a recurs�o
    }
    printf("%d ", valor);
    contagem_regressiva_recursiva(valor - 1); // Chama a fun��o novamente com n - 1
}
