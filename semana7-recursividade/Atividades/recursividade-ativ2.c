#include <stdio.h>
#include <locale.h>

int func(int valor);
int func_iterativa(int valor);

int main() {
    int valor, escolha, resultado;

    setlocale(LC_ALL, "");
    printf("Atividade 2 - Recursividade\n\n");

    // Solicita o n�mero ao usu�rio
    printf("Digite um n�mero inteiro positivo: ");
    scanf(" %d", &valor);

    // Escolha entre recursivo ou iterativo
    printf("Escolha o m�todo de c�lculo:\n");
    printf("1 - M�todo Recursivo\n");
    printf("2 - M�todo Iterativo\n");
    printf("Digite sua escolha: ");
    scanf(" %d", &escolha);

    // Executa o m�todo escolhido
    if(escolha == 1) {
        resultado = func(valor);
        printf("\nResultado usando a fun��o recursiva: %d\n", resultado);
    } else if(escolha == 2) {
        resultado = func_iterativa(valor);
        printf("\nResultado usando a fun��o iterativa: %d\n", resultado);
    } else {
        printf("Escolha inv�lida.\n");
    }

    return 0;
}

// Fun��o recursiva
int func(int valor) {
    if(valor == 0) {
        return 0;
    }
    return (valor + func(valor - 1));
}

// Fun��o iterativa
int func_iterativa(int valor) {
    int soma = 0;
    for(int i = 1; i <= valor; i++) {
        soma += i;
    }
    return soma;
}
