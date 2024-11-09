/*
• Monte todos os módulos e funções deste tipo de lista, chamando todas as funções de forma
  coerente. Utilize as variáveis de dados sugeridas no slide 22, somente para teste de inserções,
  buscas e remoções no programa principal - main().
• Crie uma nova função para coleta de dados de novos alunos. Os dados serão informados pelo
  teclado (usuário vai inserir). Esta função não recebe nenhum parâmetro, e devolve uma
  estrutura aluno pronta e preenchida, que em seguida será passada à função de inserção
  ordenada que já está pronta.
• Gere entrada para 10 alunos novos, além dos já inseridos inicialmente para teste (os 3
  primeiros)
*/
// Arquivo principal - main ()
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include "listaSequencial.h"

int main() {
    int x; // Será usado para código de erro
    Lista *li;
    // Será usado na busca por um elemento específico
    int mat = 110, posicao = 1;
    struct aluno al, al2, al3, dados_aluno;
    // Será usado na inserção no início
    al.matricula = 100;
    al.n1 = 5.3;
    al.n2 = 6.9;
    al.n3 = 7.4;
    // Será usado na inserção no final
    al2.matricula = 120;
    al2.n1 = 4;
    al2.n2 = 2.9;
    al2.n3 = 8.4;
    // Será usado na inserção ordenada
    al3.matricula = 110;
    al3.n1 = 1.3;
    al3.n2 = 2.9;
    al3.n3 = 3.4;

    setlocale(LC_ALL, "");
    printf("Atividade 1 - Lista Estatica\n");
    printf("\n\nTESTE DAS FUNÇÕES DA LISTA:");

    // Cria lista
    printf("\n\nCriando uma lista...");
    li = cria_lista();
    if(li != NULL) printf("\nSucesso na criação da lista!");
    else printf("\nFalha na criação da lista!");

    //Verifica lista vazia
    printf("\n\nVerificando se lista está vazia...");
    x = lista_vazia(li);
    if(x){
        printf("\nLista esta vazia!");
    }else{
        printf("\nLista nao esta vazia!");
    }

    //Inserção de dados no final da lista
    printf("\n\nInserindo aluno al2 no final da lista...");
    x = insere_lista_final(li, al2);
    if(x){
        printf("\nAluno inserido com sucesso!");
    }else{
        printf("\nErro! Aluno nao inserido!");
    }
    // Verifica tamanho da lista
    printf("\nVerificando tamanho da lista...");
    x = tamanho_lista(li);
    printf("\nTamanho da lista e: %d", x);

    //Inserção de dados no inicio da lista
    printf("\n\nInserindo aluno al no inicio da lista...");
    x = insere_lista_inicio(li, al);
    if(x){
        printf("\nAluno inserido com sucesso!");
    }else{
        printf("\nErro! Aluno nao inserido!");
    }
    // Verifica tamanho da lista
    printf("\nVerificando tamanho da lista...");
    x = tamanho_lista(li);
    printf("\nTamanho da lista e: %d", x);

    //Inserção de dados ordenado na lista
    printf("\n\nInserindo aluno al3 em uma posição ordenada da lista...");
    x = insere_lista_ordenada(li, al3);
    if(x){
        printf("\nAluno inserido com sucesso!");
    }else{
        printf("\nErro! Aluno nao inserido!");
    }
    // Verifica tamanho da lista
    printf("\nVerificando tamanho da lista...");
    x = tamanho_lista(li);
    printf("\nTamanho da lista e: %d", x);

    // Verifica lista cheia
    printf("\n\nVerificando se lista está cheia...");
    x = lista_cheia(li);
    if(x){
        printf("\nLista cheia!");
    }else{
        printf("\nLista nao esta cheia!");
    }

    //Busca por posição
    printf("\n\nBusca por posição na lista do aluno na posição 1...");
    x = consulta_lista_pos(li, posicao, &dados_aluno);
    if(x){
        printf("\nConsulta por posicao realizada com sucesso!");
        printf("\nMatricula: %d", dados_aluno.matricula);
        printf("\nNota 1: %.2f", dados_aluno.n1);
        printf("\nNota 2: %.2f", dados_aluno.n2);
        printf("\nNota 3: %.2f", dados_aluno.n3);
    }else{
        printf("\nNao foi possivel consulta na posicao especifica!");
    }

    //Busca por conteúdo
    printf("\n\nBusca por conteúdo na lista do aluno com matrícula 110...");
    x = consulta_lista_mat(li, mat, &dados_aluno);
    if(x){
        printf("\nConsulta por matricula realizada com sucesso!");
        printf("\nMatricula: %d", dados_aluno.matricula);
        printf("\nNota 1: %.2f", dados_aluno.n1);
        printf("\nNota 2: %.2f", dados_aluno.n2);
        printf("\nNota 3: %.2f", dados_aluno.n3);
    }else{
        printf("\nNao foi possivel consulta na matricula especifica!");
    }

    //Remorção de dados ordenado na lista
    printf("\n\nRemovendo dados de uma matrícula específica da lista...");
    x = remove_lista(li, mat);
    if(x){
        printf("\nAluno removido na posicao especifica com sucesso!");
    }else{
        printf("\nErro! Aluno nao removido na posicao especifica!");
    }
    // Verifica tamanho da lista
    printf("\nVerificando tamanho da lista...");
    x = tamanho_lista(li);
    printf("\nTamanho da lista e: %d", x);

    //Remorção de dados no final da lista
    printf("\n\nRemovendo dados do final da lista...");
    x = remove_lista_final(li);
    if(x){
        printf("\nAluno removido no final com sucesso!");
    }else{
        printf("\nErro! Aluno nao removido!");
    }
    // Verifica tamanho da lista
    printf("\nVerificando tamanho da lista...");
    x = tamanho_lista(li);
    printf("\nTamanho da lista e: %d", x);

    //Remorção de dados no inicio da lista
    printf("\n\nRemovendo dados do inicio da lista...");
    x = remove_lista_inicio(li);
    if(x){
        printf("\nAluno removido do inicio com sucesso!");
    }else{
        printf("\nErro! Aluno nao removido!");
    }
    // Verifica tamanho da lista
    printf("\nVerificando tamanho da lista...");
    x = tamanho_lista(li);
    printf("\nTamanho da lista e: %d", x);

    // Excluir a lista
    printf("\n\nExcluindo lista...");
    libera_lista(li);
    printf("\nVerificando se lista foi excluída ao usar a função de checar tamanho da lista...");
    // Verifica tamanho da lista
    printf("\nVerificando tamanho da lista...");
    x = tamanho_lista(li);
    printf("\nTamanho da lista e: %d", x);

    printf("\n\nFIM DOS TESTES DAS FUNÇÕES");

    // Cria lista
    printf("\n\nCriando uma lista...");
    li = cria_lista();
    if(li != NULL) printf("\nSucesso na criação da lista!");
    else printf("\nFalha na criação da lista!");

    printf("\n\nAdicionando novamente os 3 alunos do inicio do programa...");
    printf("\n\nInserindo aluno al em uma posição ordenada da lista...");
    x = insere_lista_ordenada(li, al);
    if(x){
        printf("\nAluno inserido com sucesso!");
    }else{
        printf("\nErro! Aluno nao inserido!");
    }
    printf("\n\nInserindo aluno al2 em uma posição ordenada da lista...");
    x = insere_lista_ordenada(li, al2);
    if(x){
        printf("\nAluno inserido com sucesso!");
    }else{
        printf("\nErro! Aluno nao inserido!");
    }
    printf("\n\nInserindo aluno al3 em uma posição ordenada da lista...");
    x = insere_lista_ordenada(li, al3);
    if(x){
        printf("\nAluno inserido com sucesso!");
    }else{
        printf("\nErro! Aluno nao inserido!");
    }

    // Verifica tamanho da lista
    printf("\nVerificando tamanho da lista...");
    x = tamanho_lista(li);
    printf("\nTamanho da lista e: %d", x);

    printf("\n\nInserção de 10 novos alunos pelo usuário:");
    for(int i = 0; i < 10; i++){
        printf("\n\nALUNO %02d:", i + 1);
        x = insere_lista_ordenada(li, coletar_dados_aluno());
        if(x){
        printf("Aluno cadastrado com sucesso!");
        }else{
            printf("Erro! Aluno não cadastrado!");
        }
    }

    // Verifica tamanho da lista
    printf("\n\nVerificando tamanho da lista...");
    x = tamanho_lista(li);
    printf("\nTamanho da lista e: %d", x);


    printf("\nConsultando todos os alunos da lista...");

    for(int i = 0; i < tamanho_lista(li); i++){
        printf("\n\nALUNO %02d:", i + 1);
        x = consulta_lista_pos(li, i + 1, &dados_aluno);
        if(x){
            printf("\nConsulta por posicao realizada com sucesso!");
            printf("\nMatricula: %d", dados_aluno.matricula);
            printf("\nNota 1: %.2f", dados_aluno.n1);
            printf("\nNota 2: %.2f", dados_aluno.n2);
            printf("\nNota 3: %.2f", dados_aluno.n3);
        }else{
            printf("\nNao foi possivel consulta na posicao especifica!");
        }

    }

    libera_lista(li);

    printf("\n\n");
    system("PAUSE");
}
/*
int main()
{
    int x; // Será usado para código de erro
    Lista *li;

    // Será usado na busca por um elemento específico
    int mat = 110, posicao = 1;
    struct aluno al, al2, al3, dados_aluno;
    // Será usado na inserção no início
    al.matricula = 100;
    al.n1 = 5.3;
    al.n2 = 6.9;
    al.n3 = 7.4;
    // Será usado na inserção no final
    al2.matricula = 120;
    al2.n1 = 4;
    al2.n2 = 2.9;
    al2.n3 = 8.4;
    // Será usado na inserção ordenada
    al3.matricula = 110;
    al3.n1 = 1.3;
    al3.n2 = 2.9;
    al3.n3 = 3.4;

    // Cria lista
    li = cria_lista();

    // Verifica tamanho da lista
    x = tamanho_lista(li);
    printf("\nTamanho da lista e: %d", x);

    // Verifica lista cheia
    x = lista_cheia(li);
    if(x){
        printf("\nLista cheia!");
    }else{
        printf("\nLista nao esta cheia!");
    }

    //Verifica lista vazia
    x = lista_vazia(li);
    if(x){
        printf("\nLista esta vazia!");
    }else{
        printf("\nLista nao esta vazia!");
    }

    //Inserção de dados no final da lista
    x = insere_lista_final(li, al2);
    if(x){
        printf("\nAluno inserido com sucesso!");
    }else{
        printf("\nErro! Aluno nao inserido!");
    }

    //Inserção de dados no final da lista
    x = insere_lista_inicio(li, al);
    if(x){
        printf("\nAluno inserido com sucesso!");
    }else{
        printf("\nErro! Aluno nao inserido!");
    }

    //Inserção de dados ordenado na lista
    x = insere_lista_ordenada(li, al3);
    if(x){
        printf("\nAluno inserido com sucesso!");
    }else{
        printf("\nErro! Aluno nao inserido!");
    }

    //Remorção de dados no final da lista
    x = remove_lista_final(li);
    if(x){
        printf("\nAluno removido no final com sucesso!");
    }else{
        printf("\nErro! Aluno nao removido!");
    }

    //Remorção de dados no inicio da lista
    x = remove_lista_inicio(li);
    if(x){
        printf("\nAluno removido do inicio com sucesso!");
    }else{
        printf("\nErro! Aluno nao removido!");
    }

    //Remorção de dados ordenado na lista
    x = remove_lista(li, mat);
    if(x){
        printf("\nAluno removido na posicao especifica com sucesso!");
    }else{
        printf("\nErro! Aluno nao removido na posicao especifica!");
    }

    //Busca por posição
    x = consulta_lista_pos(li, posicao, &dados_aluno);
    if(x){
        printf("\nConsulta por posicao realizada com sucesso!");
        printf("\nMatricula: %d", dados_aluno.matricula);
        printf("\nNota 1: %.2f", dados_aluno.n1);
        printf("\nNota 2: %.2f", dados_aluno.n2);
        printf("\nNota 3: %.2f", dados_aluno.n3);
    }else{
        printf("\nNao foi possivel consulta na posicao especifica!");
    }

    //Busca por conteúdo
    x = consulta_lista_mat(li, mat, &dados_aluno);
    if(x){
        printf("\nConsulta por matricula realizada com sucesso!");
        printf("\nMatricula: %d", dados_aluno.matricula);
        printf("\nNota 1: %.2f", dados_aluno.n1);
        printf("\nNota 2: %.2f", dados_aluno.n2);
        printf("\nNota 3: %.2f", dados_aluno.n3);
    }else{
        printf("\nNao foi possivel consulta na matricula especifica!");
    }

    printf("\nTamanho da lista e: %d", x);

    libera_lista(li);
}
*/
