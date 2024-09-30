/*
1 � Fa�a um programa que leia o nome de um trabalhador, sua idade e seu sal�rio. Imprima em
    tela todos os seus dados, utilizando a formata��o onde for necess�rio.
*/
#include <stdio.h>
#include <locale.h>

int main() {
    // Cria��o de vari�veis e vetores
    char nome[40];
    int idade;
    float salario;

    setlocale(LC_ALL, "pt_BR.UTF-8");
    printf("Atividade 1 - Strings\n\n");
    // Coleta de dados
    printf("Nome do trabalhador: ");
    fgets(nome, sizeof(nome), stdin);
    printf("Idade: ");
    getchar();
    scanf(" %d", &idade);
    printf("Sal�rio: ");
    scanf(" %f", &salario);

    // Impress�o dos dados
    printf("\n\nTrabalhador\n");
    printf("Nome: %s", nome);
    printf("Idade: %d\n", idade);
    printf("Sal�rio: R$%.2f\n", salario);

    system("PAUSE");
    return 0;
}
