#include <stdio.h>
#include <stdlib.h>

int main() {
    char numero;
    printf("Atividade 2\n");
    printf("Digite um numero: ");
    scanf(" %c", &numero);
    switch (numero){
        case '1':
            numero = 'A';
            printf("Retorno: %c\n", numero);
            break;
        case '2':
            numero = 'B';
            printf("Retorno: %c\n", numero);
            break;
        case '3':
            numero = 'C';
            printf("Retorno: %c\n", numero);
            break;
        case '4':
            numero = 'D';
            printf("Retorno: %c\n", numero);
            break;
        default:
            numero = '0';
            printf("Retorno: %c\n", numero);
            break;
    }
    system("pause");
    return 0;
}
