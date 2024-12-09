// Arquivo main.c

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "listaDDupla.h"

int main()
{
    int x, matricula = 110, pos =3;
    ALUNO al, al1, al2, al3;
    al1.matricula = 100;
    al1.n1 = 8.3;
    al1.n2 = 8.4;
    al1.n3 = 8.5;

    al2.matricula = 110;
    al2.n1 = 7.3;
    al2.n2 = 7.4;
    al2.n3 = 7.5;

    al3.matricula = 120;
    al3.n1 = 6.3;
    al3.n2 = 6.4;
    al3.n3 = 6.5;

    LISTA *li; // ponteiro para ponteiro

    setlocale(LC_ALL, "");
    printf("Atividade 1 - Lista Duplamente Ligada\n");

    li = criaLista();

    x = tamanhoLista(li);
    printf("\nO tamanho da Lista e: %d", x);

    x = listaCheia(li);
    if(x){
        printf("\nA Lista esta cheia!");
    }else{
        printf("\nA Lista nao esta cheia.");
    }

    x = listaVazia(li);
    if(x){
        printf("\nA Lista esta vazia!");
    }else{
        printf("\nA Lista nao esta vazia.");
    }

    x = insereInicio(li, al1);
    if(x){
        printf("\nAluno %d inserido no inicio com sucesso!", x);
    }else{
        printf("\nErro! Aluno nao inserido.");
    }

    x = insereFinal(li, al3);
    if(x){
        printf("\nAluno %d inserido no final com sucesso!", x);
    }else{
        printf("\nErro! Aluno nao inserido.");
    }

    x = insereOrdenado(li, al2);
    if(x){
        printf("\nAluno %d inserido ordenadamente com sucesso!", x);
    }else{
        printf("\nErro! Aluno nao inserido.");
    }

    x = tamanhoLista(li);
    printf("\nO tamanho da Lista e: %d", x);

    x = consultaPosicao(li, pos, &al);
    if(x){
        printf("\n\nConsulta realizada com sucesso:");
        printf("\nMatrícula:  %d", al.matricula);
        printf("\nNota 1:     %.2f", al.n1);
        printf("\nNota 2:     %.2f", al.n2);
        printf("\nNota 3:     %.2f", al.n3);
    }else{
        printf("\nErro, consulta nao realizada.");
    }

    x = consultaMatricula(li, matricula, &al);
    if(x){
        printf("\n\nConsulta realizada com sucesso:");
        printf("\nMatrícula:  %d", al.matricula);
        printf("\nNota 1:     %.2f", al.n1);
        printf("\nNota 2:     %.2f", al.n2);
        printf("\nNota 3:     %.2f", al.n3);
    }else{
        printf("\nErro, consulta nao realizada.");
    }

    x = removeOrdenado(li, matricula);
    if(x){
        printf("\nElemento %d removido com sucesso!", x);
    }else{
        printf("\nErro! Elemento nao removido.");
    }

    x = removeInicio(li);
    if(x){
        printf("\nElemento %d removido no inicio com sucesso!", x);
    }else{
        printf("\nErro! Elemento nao removido.");
    }

    x = removeFinal(li);
    if(x){
        printf("\nElemento %d removido no final com sucesso!", x);
    }else{
        printf("\nErro! Elemento nao removido.");
    }

    apagaLista(li);

    printf("\n\n");
    system("PAUSE");
    return 0;
}
/*
int main()
{
    int x, matricula = 110, pos =3;
    ALUNO al, al1, al2, al3;
    al1.matricula = 100;
    al1.n1 = 8.3;
    al1.n2 = 8.4;
    al1.n3 = 8.5;

    al2.matricula = 110;
    al2.n1 = 7.3;
    al2.n2 = 7.4;
    al2.n3 = 7.5;

    al3.matricula = 120;
    al3.n1 = 6.3;
    al3.n2 = 6.4;
    al3.n3 = 6.5;

    LISTA *li; // ponteiro para ponteiro

    li = criaLista();

    x = tamanhoLista(li);
    printf("\nO tamanho da Lista e: %d", x);

    x = listaCheia(li);
    if(x){
        printf("\nA Lista esta cheia!");
    }else{
        printf("\nA Lista nao esta cheia.");
    }

    x = listaVazia(li);
    if(x){
        printf("\nA Lista esta vazia!");
    }else{
        printf("\nA Lista nao esta vazia.");
    }

    x = insereInicio(li, al1);
    if(x){
        printf("\nAluno %d inserido no inicio com sucesso!", x);
    }else{
        printf("\nErro! Aluno nao inserido.");
    }

    x = insereFinal(li, al3);
    if(x){
        printf("\nAluno %d inserido no final com sucesso!", x);
    }else{
        printf("\nErro! Aluno nao inserido.");
    }

    x = insereOrdenado(li, al2);
    if(x){
        printf("\nAluno %d inserido ordenadamente com sucesso!", x);
    }else{
        printf("\nErro! Aluno nao inserido.");
    }

    x = removeInicio(li);
    if(x){
        printf("\nElemento %d removido no inicio com sucesso!", x);
    }else{
        printf("\nErro! Elemento nao removido.");
    }

    x = removeFinal(li);
    if(x){
        printf("\nElemento %d removido no final com sucesso!", x);
    }else{
        printf("\nErro! Elemento nao removido.");
    }

    x = removeOrdenado(li, matricula);
    if(x){
        printf("\nElemento %d removido com sucesso!", x);
    }else{
        printf("\nErro! Elemento nao removido.");
    }

    x = consultaPosicao(li, pos, &al);
    if(x){
        printf("\n\nConsulta realizada com sucesso:");
        printf("\nMatrícula:  %d", al.matricula);
        printf("\nNota 1:     %.2f", al.n1);
        printf("\nNota 2:     %.2f", al.n2);
        printf("\nNota 3:     %.2f", al.n3);
    }else{
        printf("\nErro, consulta nao realizada.");
    }

    x = consultaMatricula(li, matricula, &al);
    if(x){
        printf("\n\nConsulta realizada com sucesso:");
        printf("\nMatrícula:  %d", al.matricula);
        printf("\nNota 1:     %.2f", al.n1);
        printf("\nNota 2:     %.2f", al.n2);
        printf("\nNota 3:     %.2f", al.n3);
    }else{
        printf("\nErro, consulta nao realizada.");
    }

    apagaLista(li);

    printf("\n\n");
    system("PAUSE");
    return 0;
}
*/
