/*
� Desenvolva um programa em que o usu�rio insira um n�mero qualquer. Se o n�mero digitado for um
  da tabela abaixo, o programa deve retornar os caracteres indicados, sen�o, o programa deve retornar o
  caractere 0 (zero). Utilize para a sele��o o comando switch.
� Entregue no Moodle como atividade 2, somente o arquivo fonte (.c).
*/
#include <stdio.h>
#include <stdlib.h>

int main() {
    char numero;
    printf("Atividade 2 - Review\n\n");
    printf("Digite um numero: ");
    scanf(" %c", &numero);
    switch (numero){
        case '1':
            numero = 'A';
            printf("Retorno: %c", numero);
            break;
        case '2':
            numero = 'B';
            printf("Retorno: %c", numero);
            break;
        case '3':
            numero = 'C';
            printf("Retorno: %c", numero);
            break;
        case '4':
            numero = 'D';
            printf("Retorno: %c", numero);
            break;
        default:
            numero = '0';
            printf("Retorno: %c", numero);
            break;
    }
    printf("\n\n");
    system("pause");
    return 0;
}
