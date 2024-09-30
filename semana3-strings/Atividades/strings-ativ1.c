/*
1 – Faça um programa que leia o nome de um trabalhador, sua idade e seu salário. Imprima em
    tela todos os seus dados, utilizando a formatação onde for necessário.
*/
#include <stdio.h>
#include <locale.h>

int main() {
    // Criação de variáveis e vetores
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
    printf("Salário: ");
    scanf(" %f", &salario);

    // Impressão dos dados
    printf("\n\nTrabalhador\n");
    printf("Nome: %s", nome);
    printf("Idade: %d\n", idade);
    printf("Salário: R$%.2f\n", salario);

    system("PAUSE");
    return 0;
}
