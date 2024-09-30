/*
3 – Leia uma string do teclado e conte quantas vogais (a, e, i, o, u) ela possui no total (não
    individual). Entre com uma consoante (escolhida via teclado), e substitua todas as vogais da string
    coletada, por essa consoante. Por fim imprima em tela esta nova string.

*/
#include <stdio.h>
#include <locale.h>

int main() {
    // Criação de variáveis e vetores
    char frase[100];
    char consoante;
    int contador_vogais = 0, i;

    setlocale(LC_ALL, "pt_BR.UTF-8");
    printf("Atividade 3 - Strings\n\n");

    // Entrada de dados
    printf("Escreva uma frase:\n");
    fgets(frase, sizeof(frase), stdin);
    // Contando vogais
    for(i = 0; frase[i] != '\0'; i++) {
        if(frase[i] == 'a' || frase[i] == 'A' ||
           frase[i] == 'e' || frase[i] == 'E' ||
           frase[i] == 'i' || frase[i] == 'I' ||
           frase[i] == 'o' || frase[i] == 'O' ||
           frase[i] == 'u' || frase[i] == 'U') {
            contador_vogais++;
        }
    }
    printf("A string possui %d vogais\n\n", contador_vogais);
    // Substituindo as vogais pela consoante
    printf("Digite uma consoante: ");
    scanf(" %c", &consoante);
    for(i = 0; frase[i] != '\0'; i++) {
        if(frase[i] == 'a' || frase[i] == 'A' ||
           frase[i] == 'e' || frase[i] == 'E' ||
           frase[i] == 'i' || frase[i] == 'I' ||
           frase[i] == 'o' || frase[i] == 'O' ||
           frase[i] == 'u' || frase[i] == 'U') {
            frase[i] = consoante;
        }
    }
    printf("Nova frase: \n%s\n\n", frase);

    system("PAUSE");
    return 0;
}
