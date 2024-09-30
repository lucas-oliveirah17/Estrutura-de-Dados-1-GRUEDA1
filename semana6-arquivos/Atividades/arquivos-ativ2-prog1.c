/*
• Utilizando o formato da estrutura dos exercícios de uma aula anterior (abaixo), faça um programa que
  receba 5 funcionários como entrada, armazene-os em um vetor de estruturas e em seguida salve-o em
  um arquivo binário.

    struct funcionario {
        int ID;
        char nome[30];
        int idade;
        float salario;
    };

• Gere um segundo programa que leia no arquivo e imprima apenas o terceiro elemento, lendo
  diretamente do arquivo salvo anteriormente, e sem carregar o vetor totalmente na memória. Lembrese você precisará de 2 programas: um para gerar o arquivo e outro para ler o dado do arquivo gerado
  pelo primeiro.
*/
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

typedef struct {
        int ID;
        char nome[30];
        int idade;
        float salario;
    } FUNCIONARIO;

void cadastrar_funcionarios(FUNCIONARIO funcionario[], int quantidade);
void salvar_arquivo(FUNCIONARIO funcionarios[]);

int main() {
    FUNCIONARIO funcionarios[5];

    setlocale(LC_ALL,"");
    printf("Atividade 2 - Arquivos - Programa 1\n\n");

    // Cadastrando Funcionários
    cadastrar_funcionarios(funcionarios, 5);

    // Verificando cadastro dos funcionários
    printf("\nVerificando o cadastro:");
    for(int i = 0; i < 5; i++) {
        printf("\n\nFuncionario %d", i + 1);
        printf("\nID: %d", funcionarios[i].ID);
        printf("\nNome: %s", funcionarios[i].nome);
        printf("\nIdade: %d", funcionarios[i].idade);
        printf("\nSalario: %.2f", funcionarios[i].salario);
    }
    // Salvando os dados em um arquivo
    salvar_arquivo(funcionarios);
    printf("\n\n");
    system("pause");
    return 0;
}

void cadastrar_funcionarios(FUNCIONARIO funcionario[], int quantidade) {
    puts("Cadastro de funcionários:");
    for(int i = 0; i < quantidade; i++) {
        printf("\nFuncionário %d:\n", i + 1);
        printf("ID = ");
        scanf(" %d", &funcionario[i].ID);
        printf("Nome = ");
        scanf(" %29[^\n]", &funcionario[i].nome);
        printf("Idade = ");
        scanf(" %d", &funcionario[i].idade);
        printf("Salario = ");
        scanf(" %f", &funcionario[i].salario);
    }
}

void salvar_arquivo(FUNCIONARIO funcionarios[]) {
    FILE *arquivo;

    arquivo = fopen("funcionarios.bin", "wb");
    if(arquivo == NULL) {
        printf("Erro na abertura!\n");
        system("pause");
        exit(1);
    }
    fwrite(funcionarios, sizeof(FUNCIONARIO), 5, arquivo);
    fclose(arquivo);
    puts("\n\n\Gravacao concluida!");
}
