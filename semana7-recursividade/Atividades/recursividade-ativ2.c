#include <stdio.h>
#include <locale.h>

int func(int valor);
int func_iterativa(int valor);

int main() {
    int valor, escolha, resultado;

    setlocale(LC_ALL, "");
    printf("Atividade 2 - Recursividade\n\n");

    // Solicita o número ao usuário
    printf("Digite um número inteiro positivo: ");
    scanf(" %d", &valor);

    // Escolha entre recursivo ou iterativo
    printf("Escolha o método de cálculo:\n");
    printf("1 - Método Recursivo\n");
    printf("2 - Método Iterativo\n");
    printf("Digite sua escolha: ");
    scanf(" %d", &escolha);

    // Executa o método escolhido
    if(escolha == 1) {
        resultado = func(valor);
        printf("\nResultado usando a função recursiva: %d\n", resultado);
    } else if(escolha == 2) {
        resultado = func_iterativa(valor);
        printf("\nResultado usando a função iterativa: %d\n", resultado);
    } else {
        printf("Escolha inválida.\n");
    }

    return 0;
}

// Função recursiva
int func(int valor) {
    if(valor == 0) {
        return 0;
    }
    return (valor + func(valor - 1));
}

// Função iterativa
int func_iterativa(int valor) {
    int soma = 0;
    for(int i = 1; i <= valor; i++) {
        soma += i;
    }
    return soma;
}
