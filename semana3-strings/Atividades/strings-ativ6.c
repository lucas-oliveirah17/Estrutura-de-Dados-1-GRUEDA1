/*
5 � Utilizando agora as fun��es dispon�veis na biblioteca <ctype.h>, leia do teclado uma string e
    inverta a caixa dos seus caracteres. Se o caractere for mai�sculo, transforme-o em min�sculo. Se
    for min�sculo, modifique-o para mai�sculo. No mesmo programa implemente as fun��es (escreva
    o c�digo delas) strupr() e strlwr(), apresentadas no final dos slides e efetue a mesma opera��o de
    invers�o mai�sculas/min�sculas.
*/
#include <stdio.h>
#include <ctype.h>

int main() {
    // Cria��o de vari�veis e vetores
    char frase[100];
    int i;

    printf("Atividade 6 - Strings\n\n");
    // Entrada de dados
    puts("Escreva uma frase: ");
    scanf(" %99[^\n]", &frase);
    // Modifica��o da frase
    for(i = 0; frase[i] != '\0'; i++) {
        if(frase[i] >= 'a' && frase[i] <= 'z')
            frase[i] = toupper(frase[i]);
        else if(frase[i] >= 'A' && frase[i] <= 'Z')
            frase[i] = tolower(frase[i]);
    }
    printf("Resultado Invertendo as caixas:\n%s\n\n", frase);

    for(i = 0; frase[i] != '\0'; i++) {
        if(frase[i] >= 'a' && frase[i] <= 'z')
            frase[i] = toupper(frase[i]);
    }
    printf("Resultado caixa alta (simulando a funcao strupr()):\n%s\n\n", frase);

    for(i = 0; frase[i] != '\0'; i++) {
        if(frase[i] >= 'A' && frase[i] <= 'Z')
            frase[i] = tolower(frase[i]);
    }
    printf("Resultado caixas baixa (simulando a funcao strlwr()):\n%s\n\n", frase);

    system("PAUSE");
    return 0;
}
