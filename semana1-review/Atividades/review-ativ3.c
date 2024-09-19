/*
• Reescreva o programa anterior utilizando if-else-if.
• Entregue no Moodle como atividade 3, somente o arquivo fonte(.c).
*/
#include <stdio.h>
#include <stdlib.h>

int main() {
    char numero;
    printf("Atividade 3 - Review\n\n");
    printf("Digite um numero: ");
    scanf(" %c", &numero);
    if (numero == '1') {
        numero = 'A';
        printf("Retorno: %c", numero);
    }else {
        if (numero == '2') {
            numero = 'B';
            printf("Retorno: %c", numero);
        }else {
            if (numero == '3') {
                numero = 'C';
                printf("Retorno: %c", numero);
            } else {
                if (numero == '4') {
                    numero = 'D';
                    printf("Retorno: %c", numero);
                } else {
                    numero = '0';
                    printf("Retorno: %c", numero);
                }
            }
        }
    }
    printf("\n\n");
    system("pause");
    return 0;
}
