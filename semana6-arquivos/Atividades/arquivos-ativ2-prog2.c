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

void ler_terceiro_funcionario();
//void ler_arquivo(FUNCIONARIO funcionarios[]);

int main() {
    FUNCIONARIO funcionarios[5];

    setlocale(LC_ALL,"");
    printf("Atividade 2 - Arquivos - Programa 2\n\n");
    // Ler o arquivo
    ler_terceiro_funcionario();

    printf("\n\n");
    system("pause");
    return 0;
}

void ler_terceiro_funcionario() {
    FILE *arquivo;
    FUNCIONARIO funcionario;

    arquivo = fopen("funcionarios.bin", "rb");
    if(arquivo == NULL) {
        printf("Erro na abertura!\n");
        system("pause");
        exit(1);
    }

    // Posiciona o arquivo para ler o terceiro funcionario
    fseek(arquivo, 2 * sizeof(FUNCIONARIO), SEEK_SET);
    fread(&funcionario, sizeof(FUNCIONARIO), 1, arquivo);

    // Leitura dos dados do funcionário 3
    printf("\Funcionario 3:");
    printf("\nID: %d", funcionario.ID);
    printf("\nNome: %s", funcionario.nome);
    printf("\nIdade: %d", funcionario.idade);
    printf("\nSalario: %.2f", funcionario.salario);

    fclose(arquivo);
}
/*void ler_arquivo(FUNCIONARIO funcionarios[]) {
    FILE *arquivo;

    arquivo = fopen("funcionarios.bin", "rb");
    if(arquivo == NULL) {
        printf("Erro na abertura!\n");
        system("pause");
        exit(1);
    }
    fread(funcionarios, sizeof(FUNCIONARIO), 5, arquivo);
    fclose(arquivo);
}*/

