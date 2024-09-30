/*
4 – Construa um programa que leia duas strings do teclado. Imprima uma mensagem informando
    se a segunda string está contida na primeira.


*/
#include <stdio.h>
#include <string.h>
#include <locale.h>

int main() {
    // Criação de variáveis e vetores
    char frase1[100], frase2[100];
    char *verificador;

    setlocale(LC_ALL, "pt_BR.UTF-8");
    printf("Atividade 4 - Strings\n\n");
    // Coleta de dados
    puts("Digite a primeira frase:");
    scanf(" %99[^\n]", &frase1);
    puts("Digite a segunda frase:");
    getchar();
    scanf(" %99[^\n]", &frase2);
    // Verificando as strings
    verificador = strstr(frase1 , frase2);
    if(verificador == NULL) {
        puts("A segunda frase NAO ESTA contida na primeira.");
    }
    else {
        puts("A segunda frase ESTA contida na primeira.");
    }

    system("PAUSE");
    return 0;
}
