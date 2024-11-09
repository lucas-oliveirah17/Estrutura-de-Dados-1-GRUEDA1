/*
� Monte todos os m�dulos e fun��es deste tipo de lista, chamando todas as fun��es de forma
  coerente. Utilize as vari�veis de dados sugeridas no slide 22, somente para teste de inser��es,
  buscas e remo��es no programa principal - main().
� Crie uma nova fun��o para coleta de dados de novos alunos. Os dados ser�o informados pelo
  teclado (usu�rio vai inserir). Esta fun��o n�o recebe nenhum par�metro, e devolve uma
  estrutura aluno pronta e preenchida, que em seguida ser� passada � fun��o de inser��o
  ordenada que j� est� pronta.
� Gere entrada para 10 alunos novos, al�m dos j� inseridos inicialmente para teste (os 3
  primeiros)
*/
// Arquivo principal - main ()
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include "listaSequencial.h"

int main() {
    int x; // Ser� usado para c�digo de erro
    Lista *li;
    // Ser� usado na busca por um elemento espec�fico
    int mat = 110, posicao = 1;
    struct aluno al, al2, al3, dados_aluno;
    // Ser� usado na inser��o no in�cio
    al.matricula = 100;
    al.n1 = 5.3;
    al.n2 = 6.9;
    al.n3 = 7.4;
    // Ser� usado na inser��o no final
    al2.matricula = 120;
    al2.n1 = 4;
    al2.n2 = 2.9;
    al2.n3 = 8.4;
    // Ser� usado na inser��o ordenada
    al3.matricula = 110;
    al3.n1 = 1.3;
    al3.n2 = 2.9;
    al3.n3 = 3.4;

    setlocale(LC_ALL, "");
    printf("Atividade 1 - Lista Estatica\n");
    printf("\n\nTESTE DAS FUN��ES DA LISTA:");

    // Cria lista
    printf("\n\nCriando uma lista...");
    li = cria_lista();
    if(li != NULL) printf("\nSucesso na cria��o da lista!");
    else printf("\nFalha na cria��o da lista!");

    //Verifica lista vazia
    printf("\n\nVerificando se lista est� vazia...");
    x = lista_vazia(li);
    if(x){
        printf("\nLista esta vazia!");
    }else{
        printf("\nLista nao esta vazia!");
    }

    //Inser��o de dados no final da lista
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

    //Inser��o de dados no inicio da lista
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

    //Inser��o de dados ordenado na lista
    printf("\n\nInserindo aluno al3 em uma posi��o ordenada da lista...");
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
    printf("\n\nVerificando se lista est� cheia...");
    x = lista_cheia(li);
    if(x){
        printf("\nLista cheia!");
    }else{
        printf("\nLista nao esta cheia!");
    }

    //Busca por posi��o
    printf("\n\nBusca por posi��o na lista do aluno na posi��o 1...");
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

    //Busca por conte�do
    printf("\n\nBusca por conte�do na lista do aluno com matr�cula 110...");
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

    //Remor��o de dados ordenado na lista
    printf("\n\nRemovendo dados de uma matr�cula espec�fica da lista...");
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

    //Remor��o de dados no final da lista
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

    //Remor��o de dados no inicio da lista
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
    printf("\nVerificando se lista foi exclu�da ao usar a fun��o de checar tamanho da lista...");
    // Verifica tamanho da lista
    printf("\nVerificando tamanho da lista...");
    x = tamanho_lista(li);
    printf("\nTamanho da lista e: %d", x);

    printf("\n\nFIM DOS TESTES DAS FUN��ES");

    // Cria lista
    printf("\n\nCriando uma lista...");
    li = cria_lista();
    if(li != NULL) printf("\nSucesso na cria��o da lista!");
    else printf("\nFalha na cria��o da lista!");

    printf("\n\nAdicionando novamente os 3 alunos do inicio do programa...");
    printf("\n\nInserindo aluno al em uma posi��o ordenada da lista...");
    x = insere_lista_ordenada(li, al);
    if(x){
        printf("\nAluno inserido com sucesso!");
    }else{
        printf("\nErro! Aluno nao inserido!");
    }
    printf("\n\nInserindo aluno al2 em uma posi��o ordenada da lista...");
    x = insere_lista_ordenada(li, al2);
    if(x){
        printf("\nAluno inserido com sucesso!");
    }else{
        printf("\nErro! Aluno nao inserido!");
    }
    printf("\n\nInserindo aluno al3 em uma posi��o ordenada da lista...");
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

    printf("\n\nInser��o de 10 novos alunos pelo usu�rio:");
    for(int i = 0; i < 10; i++){
        printf("\n\nALUNO %02d:", i + 1);
        x = insere_lista_ordenada(li, coletar_dados_aluno());
        if(x){
        printf("Aluno cadastrado com sucesso!");
        }else{
            printf("Erro! Aluno n�o cadastrado!");
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
    int x; // Ser� usado para c�digo de erro
    Lista *li;

    // Ser� usado na busca por um elemento espec�fico
    int mat = 110, posicao = 1;
    struct aluno al, al2, al3, dados_aluno;
    // Ser� usado na inser��o no in�cio
    al.matricula = 100;
    al.n1 = 5.3;
    al.n2 = 6.9;
    al.n3 = 7.4;
    // Ser� usado na inser��o no final
    al2.matricula = 120;
    al2.n1 = 4;
    al2.n2 = 2.9;
    al2.n3 = 8.4;
    // Ser� usado na inser��o ordenada
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

    //Inser��o de dados no final da lista
    x = insere_lista_final(li, al2);
    if(x){
        printf("\nAluno inserido com sucesso!");
    }else{
        printf("\nErro! Aluno nao inserido!");
    }

    //Inser��o de dados no final da lista
    x = insere_lista_inicio(li, al);
    if(x){
        printf("\nAluno inserido com sucesso!");
    }else{
        printf("\nErro! Aluno nao inserido!");
    }

    //Inser��o de dados ordenado na lista
    x = insere_lista_ordenada(li, al3);
    if(x){
        printf("\nAluno inserido com sucesso!");
    }else{
        printf("\nErro! Aluno nao inserido!");
    }

    //Remor��o de dados no final da lista
    x = remove_lista_final(li);
    if(x){
        printf("\nAluno removido no final com sucesso!");
    }else{
        printf("\nErro! Aluno nao removido!");
    }

    //Remor��o de dados no inicio da lista
    x = remove_lista_inicio(li);
    if(x){
        printf("\nAluno removido do inicio com sucesso!");
    }else{
        printf("\nErro! Aluno nao removido!");
    }

    //Remor��o de dados ordenado na lista
    x = remove_lista(li, mat);
    if(x){
        printf("\nAluno removido na posicao especifica com sucesso!");
    }else{
        printf("\nErro! Aluno nao removido na posicao especifica!");
    }

    //Busca por posi��o
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

    //Busca por conte�do
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
