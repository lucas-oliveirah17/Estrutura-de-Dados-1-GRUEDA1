/*
� Reescreva o programa do exemplo anterior substituindo a
  estrutura �pessoa� pela estrutura �funcion�rio� ao lado;
� Modifique o programa para que o usu�rio possa fornecer os
  dados necess�rios relativos aos funcion�rios de uma
  empresa fict�cia. Voc� deve gerar entradas para 5
  funcion�rios;
� Imprima todo o vetor com todos os dados funcion�rios na
  tela no estilo de um relat�rio;
� Entregue no Moodle como Atividade 1.
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct funcionario {
    int id;
    char nome[30];
    int idade;
    float salario;
};

int main() {
    struct funcionario f[5];
    int i;
    printf("Atividade 1 - Estruturas Heterogeneas - Structs\n\n");
    // Coleta de dados
    for(i = 0; i < 5; i++) {
        printf("Funcionario %d\n", i + 1);
        printf("ID: ");
        scanf(" %d", &f[i].id);
        printf("Nome: ");
        getchar();
        fgets(f[i].nome, 29, stdin);
        printf("Idade: ");
        scanf(" %d", &f[i].idade);
        printf("Salario: R$");
        scanf(" %f", &f[i].salario);
        printf("\n");
    }
    // Impress�o dos resultados
    printf("\nRelatorio de Funcionarios:\n");
    for (i = 0; i < 5; i++) {
        printf("Dados Funcionario %d\n", i + 1);
        printf("ID ....: %d \n", f[i].id);
        printf("Nome ..: %s", f[i].nome);
        printf("Idade .: %d \n", f[i].idade);
        printf("Salario: R$%.2f \n", f[i].salario);
        printf("\n");
    }

    printf("\n\n");
    system("pause");
    return 0;
}
