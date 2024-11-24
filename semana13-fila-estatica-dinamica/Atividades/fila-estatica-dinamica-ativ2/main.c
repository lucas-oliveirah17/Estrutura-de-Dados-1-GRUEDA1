/*
• Monte o programa Fila dinâmica,
 posicionando as chamadas das funções no
 main(), para manipulação da Pilha, de
 forma que apresentem o funcionamento e
 as mensagens iguais ao exemplo ao lado.

  EXEMPLO DE TELA ESPERADA:
        O tamanho da Fila e: 0
        A Fila nao esta cheia.
        A Fila esta vazia!
        Elemento 100 inserido com sucesso!
        Elemento 110 inserido com sucesso!
        Elemento 120 inserido com sucesso!
        O tamanho da Fila e: 3
        Consulta realizada com sucesso:
        Matricula: 100
        Nota 1:    8,30
        Nota 2:    8,40
        Nota 3:    8,50
        Elemento 100 removido com sucesso!
        Consulta realizada com sucesso:
        Matricula: 110
        Nota 1:    7,30
        Nota 2:    7,40
        Nota 3:    7,50
*/
// Arquivo main.c - FILA DINÂMICA
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "fila.h"

int main()
{
    int x; // para os códigos de erro
    ALUNO al_consulta, al1, al2, al3;
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

    FILA *fi = NULL;

    setlocale(LC_ALL, "");
    printf("Atividade 2 - Fila Sequencial Dinâmica\n");

    fi = criaFila();

    x = tamanhoFila(fi);
    printf("\nO tamanho da Fila e: %d", x);

    x = filaCheia(fi);
    if(x){
        printf("\nA Fila esta cheia!");
    }else{
        printf("\nA Fila nao esta cheia.");
    }

    x = filaVazia(fi);
    if(x){
        printf("\nA Fila esta vazia!");
    }else{
        printf("\nA Fila nao esta vazia.");
    }

    x = insereFila(fi, al1);
    if(x){
        printf("\nElemento %d inserido com sucesso!", x);
    }else{
        printf("\nErro, elemento nao inserido.");
    }

    x = insereFila(fi, al2);
    if(x){
        printf("\nElemento %d inserido com sucesso!", x);
    }else{
        printf("\nErro, elemento nao inserido.");
    }

    x = insereFila(fi, al3);
    if(x){
        printf("\nElemento %d inserido com sucesso!", x);
    }else{
        printf("\nErro, elemento nao inserido.");
    }

    x = tamanhoFila(fi);
    printf("\nO tamanho da Fila e: %d", x);

    x = consultaFila(fi, &al_consulta);
    if(x){
        printf("\nConsulta realizada com sucesso:");
        printf("\nMatricula: %d", al_consulta.matricula);
        printf("\nNota 1:    %.2f", al_consulta.n1);
        printf("\nNota 2:    %.2f", al_consulta.n2);
        printf("\nNota 3:    %.2f", al_consulta.n3);
    }else{
        printf("\nErro, consulta nao realizada.");
    }

    x = removeFila(fi);
    if(x){
        printf("\nElemento %d removido com sucesso!", x);
    }else{
        printf("\nErro, elemento nao removido.");
    }

    x = consultaFila(fi, &al_consulta);
    if(x){
        printf("\nConsulta realizada com sucesso:");
        printf("\nMatricula: %d", al_consulta.matricula);
        printf("\nNota 1:    %.2f", al_consulta.n1);
        printf("\nNota 2:    %.2f", al_consulta.n2);
        printf("\nNota 3:    %.2f", al_consulta.n3);
    }else{
        printf("\nErro, consulta nao realizada.");
    }

    liberaFila(fi);

    printf("\n\n");
    system("PAUSE");
    return 0;
}
