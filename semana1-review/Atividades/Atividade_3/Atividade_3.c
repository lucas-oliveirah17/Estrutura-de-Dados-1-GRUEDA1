#include <stdio.h>
#include <stdlib.h>

int main() {
    char numero;
    printf("Atividade 3\n");
    printf("Entrada: ");
    scanf(" %c", &numero);
    if (numero == '1') {
        numero = 'A';
        printf("Retorno: %c\n", numero);
    }else {
        if (numero == '2') {
            numero = 'B';
            printf("Retorno: %c\n", numero);
        }else {
            if (numero == '3') {
                numero = 'C';
                printf("Retorno: %c\n", numero);
            } else {
                if (numero == '4') {
                    numero = 'D';
                    printf("Retorno: %c\n", numero);
                } else {
                    numero = '0';
                    printf("Retorno: %c\n", numero);
                }
            }
        }
    }
    system("pause");
    return 0;
}
