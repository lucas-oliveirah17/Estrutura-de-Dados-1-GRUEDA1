/*
5 � Escreva um programa que leia uma string do teclado e converta todos os seus caracteres em
    mai�scula. N�o utilize nenhuma fun��o da biblioteca <ctype.h>, subtraia o valor 32 dos
    caracteres. Consulte a tabela ASCII para isso
*/
#include <stdio.h>

int main() {
    // Cria��o de vari�veis e vetores
    char frase[100];
    int i;

    printf("Atividade 5 - Strings\n\n");
    // Entrada de dados
    puts("Escreva uma frase: ");
    scanf(" %99[^\n]", &frase);
    // Modifica��o da frase
    for(i = 0; frase[i] != '\0'; i++) {
        if(frase[i] >= 'a' && frase[i] <= 'z')
            frase[i] -= 32;
    }
    printf("Resultado:\n%s\n\n", frase);

    system("PAUSE");
    return 0;
}
