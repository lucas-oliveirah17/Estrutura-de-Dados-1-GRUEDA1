/*
5 – Utilizando agora as funções disponíveis na biblioteca <ctype.h>, leia do teclado uma string e
    inverta a caixa dos seus caracteres. Se o caractere for maiúsculo, transforme-o em minúsculo. Se
    for minúsculo, modifique-o para maiúsculo. No mesmo programa implemente as funções (escreva
    o código delas) strupr() e strlwr(), apresentadas no final dos slides e efetue a mesma operação de
    inversão maiúsculas/minúsculas.
*/
#include <stdio.h>
#include <ctype.h>

int main() {
    // Criação de variáveis e vetores
    char frase[100];
    int i;

    printf("Atividade 6 - Strings\n\n");
    // Entrada de dados
    puts("Escreva uma frase: ");
    scanf(" %99[^\n]", &frase);
    // Modificação da frase
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
