/*
• Utilizando exemplos anteriores, codifique um programa que receba via teclado um pequeno
  texto e em seguida salve-o gerando um arquivo chamado “arq1.txt”. Visualize-o com um
  editor de textos (bloco de notas).
• Em seguida baseado no exemplo anterior, modifique seu programa para que depois de
  recolhido o pequeno texto, todos os seus caracteres sejam modificados para letras
  maiúsculas e seja salvo com o nome de “arq2.txt”.
• Imprima os dois arquivos em tela.
• Devem ser entregues como atividade 1, os seguintes arquivos (compactados ou “zipados”):
• Seu programa, somente o código fonte “.c”;
• Os dois arquivos de texto gerados, “arq1.txt” e “arq2.txt”.
*/
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <locale.h>
#include <string.h>

void nome_arquivo(char *nome_arquivo, int tamanho);
void salvar_arquivo(const char *nome_arquivo, const char *texto);
void imprimir_arquivo(const char *nome_arquivo);
void converter_maiusculas(char *texto);

int main() {
    char texto[256], nome_arquivo1[50], nome_arquivo2[50];

    setlocale(LC_ALL,"");
    printf("Atividade 1 - Arquivos\n\n");

    // Define o nome do primeiro arquivo
    puts("Arquivo 1");
    nome_arquivo(nome_arquivo1, sizeof(nome_arquivo1)); // Inserir essa função só para me testar

    // Escreve o texto
    printf("Digite um texto para inserir no arquivo:\n");
    fgets(texto, sizeof(texto), stdin);

    // Salva o texto original em um arquivo .txt
    salvar_arquivo(nome_arquivo1, texto);

    // Converta o texto para maiúscula
    converter_maiusculas(texto);
    printf("\nTexto convertido:\n%s", texto);


    // Define o nome do segundo arquivo
    puts("\nArquivo 2");
    nome_arquivo(nome_arquivo2, sizeof(nome_arquivo2));
    // Salva o texto convertido em um arquivo .txt
    salvar_arquivo(nome_arquivo2, texto);

    // Impressão dos arquivos
    puts("\nLeitura dos dois arquivos");
    puts("Arquivo 1:");
    imprimir_arquivo(nome_arquivo1);
    // Impressão dos arquivos
    puts("\nArquivo 2:");
    imprimir_arquivo(nome_arquivo2);

    system("pause");
    return 0;
}

void nome_arquivo(char *nome_arquivo, int tamanho) {
    printf("Digite o nome para o arquivo (.txt):\n");
    fgets(nome_arquivo, tamanho, stdin);
    // Remove a nova linha que pode ser adicionada pelo fgets
    nome_arquivo[strcspn(nome_arquivo, "\n")] = 0;
    // Verifica se termina com ".txt"
    if (strlen(nome_arquivo) < 4 ||
        strcmp(&nome_arquivo[strlen(nome_arquivo)- 4], ".txt") != 0) {
            strcat(nome_arquivo, ".txt");
    }
}

void salvar_arquivo(const char *nome_arquivo, const char *texto) {
    FILE *arquivo;
    arquivo = fopen(nome_arquivo, "w");
    if(arquivo == NULL) {
        printf("Erro na abertura!\n");
        system("pause");
        exit(1);
    }
    fprintf(arquivo, "%s", texto);
    fclose(arquivo);
}

void converter_maiusculas(char *texto) {
    int i;
    for(i = 0; i < strlen(texto); i++){
        texto[i] = toupper(texto[i]);
    }
}

void imprimir_arquivo(const char *nome_arquivo) {
    char caractere;
    FILE *arquivo;
    arquivo = fopen(nome_arquivo, "r");
    if(arquivo == NULL) {
        printf("Erro na abertura!\n");
        system("pause");
        exit(1);
    }
    caractere = fgetc(arquivo);
    while(caractere != EOF) {
        printf("%c", caractere);
        caractere = fgetc(arquivo);
    }
    fclose(arquivo);
}
