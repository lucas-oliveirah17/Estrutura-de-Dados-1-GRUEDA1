/*
2 – Escreva um programa que receba três strings para o nome de uma pessoa (nome e
    sobrenomes), concatene formatando estas strings para apresentação do nome em tela.
*/
#include <stdio.h>
#include <string.h>
#include <locale.h>

int main() {
    // Criação de variáveis e vetores
    char nome_primeiro[60], nome_meio[20], nome_final[20];
    char espaco[] = " ";

    setlocale(LC_ALL, "pt_BR.UTF-8");
    printf("Atividade 2 - Strings\n\n");
    // Coleta de dados
    printf("Nome: ");
    scanf(" %s", &nome_primeiro);
    printf("Sobrenome: ");
    getchar();
    scanf(" %s", &nome_meio);
    printf("Sobrenome: ");
    getchar();
    scanf(" %s", &nome_final);
    // Manipulação de dados
    strcat(nome_primeiro, espaco);
    strcat(nome_primeiro, nome_meio);
    strcat(nome_primeiro, espaco);
    strcat(nome_primeiro, nome_final);
    // Impressão dos dados
    printf("\nNome completo: %s\n\n", nome_primeiro);
    system("PAUSE");
    return 0;
}
