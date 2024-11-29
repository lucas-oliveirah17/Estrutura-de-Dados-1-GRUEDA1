/*
• Monte o programa Pilha dinâmica, posicionando as
  chamadas das funções no main(), para manipulação
  da Pilha, de forma que apresentem o funcionamento e
  as mensagens iguais ao exemplo ao lado.

 EXEMPLO DE TELA ESPERADA:
    O tamanho da Pilha e: 0
    A Pilha nao esta cheia.
    A Pilha esta vazia!
    Elemento 100 inserido com sucesso!
    Elemento 110 inserido com sucesso!
    Elemento 120 inserido com sucesso!
    O tamanho da Pilha e: 3
    Consulta realizada com sucesso:
    Matricula: 120
    Nota 1:    6,30
    Nota 2:    6,40
    Nota 3:    6,50
    Elemento 120 removido com sucesso!
    Consulta realizada com sucesso:
    Matricula: 110
    Nota 1:    7,30
    Nota 2:    7,40
    Nota 3:    7,50
*/
// Arquivo main.c - PILHA DINÃMICA
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "pilha.h"

int main(){
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

    // Ponteiro para o topo da pilha
    PILHA *pi = NULL;

    setlocale(LC_ALL, "");
    printf("Atividade 2 - Pilha Dinâmica\n");

    pi = criaPilha();

    x = tamanhoPilha(pi);
    printf("\nO tamanho da Pilha e: %d", x);

    x = pilhaCheia(pi);
    if(x){
        printf("\nA Pilha esta cheia!");
    }else{
        printf("\nA Pilha nao esta cheia.");
    }

    x = pilhaVazia(pi);
    if(x){
        printf("\nA Pilha esta vazia!");
    }else{
        printf("\nA Pilha nao esta vazia.");
    }

    x = inserePilha(pi, al1);
    if(x){
        printf("\nElemento %d inserido com sucesso!", x);
    }else{
        printf("\nErro, elemento nao inserido.");
    }

    x = inserePilha(pi, al2);
    if(x){
        printf("\nElemento %d inserido com sucesso!", x);
    }else{
        printf("\nErro, elemento nao inserido.");
    }

    x = inserePilha(pi, al3);
    if(x){
        printf("\nElemento %d inserido com sucesso!", x);
    }else{
        printf("\nErro, elemento nao inserido.");
    }

    x = tamanhoPilha(pi);
    printf("\nO tamanho da Pilha e: %d", x);

    x = acessaTopoPilha(pi, &al_consulta);
    if(x){
        printf("\nConsulta realizada com sucesso:");
        printf("\nMatricula: %d", al_consulta.matricula);
        printf("\nNota 1:    %.2f", al_consulta.n1);
        printf("\nNota 2:    %.2f", al_consulta.n2);
        printf("\nNota 3:    %.2f", al_consulta.n3);
    }else{
        printf("\nErro, consulta nao realizada.");
    }

    x = removePilha(pi);
    if(x){
        printf("\nElemento %d removido com sucesso!", x);
    }else{
        printf("\nErro, elemento nao removido.");
    }

    x = acessaTopoPilha(pi, &al_consulta);
    if(x){
        printf("\nConsulta realizada com sucesso:");
        printf("\nMatricula: %d", al_consulta.matricula);
        printf("\nNota 1:    %.2f", al_consulta.n1);
        printf("\nNota 2:    %.2f", al_consulta.n2);
        printf("\nNota 3:    %.2f", al_consulta.n3);
    }else{
        printf("\nErro, consulta nao realizada.");
    }

    liberaPilha(pi);

    printf("\n\n");
    system("PAUSE");
    return 0;
}

/*
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

    // Ponteiro para o topo da pilha
    PILHA *pi = NULL;

    setlocale(LC_ALL, "");
    printf("Atividade 1 - Fila Sequencial Estática\n");

    pi = criaPilha();

    x = tamanhoPilha(pi);
    printf("\nO tamanho da Pilha e: %d", x);

    x = pilhaCheia(pi);
    if(x){
        printf("\nA Pilha esta cheia!");
    }else{
        printf("\nA Pilha nao esta cheia.");
    }

    x = pilhaVazia(pi);
    if(x){
        printf("\nA Pilha esta vazia!");
    }else{
        printf("\nA Pilha nao esta vazia.");
    }

    x = inserePilha(pi, al1);
    if(x){
        printf("\nElemento %d inserido com sucesso!", x);
    }else{
        printf("\nErro, elemento nao inserido.");
    }

    x = removePilha(pi);
    if(x){
        printf("\nElemento %d removido com sucesso!", x);
    }else{
        printf("\nErro, elemento nao removido.");
    }

    x = acessaTopoPilha(pi, &al_consulta);
    if(x){
        printf("\nConsulta realizada com sucesso:");
        printf("\nMatricula: %d", al_consulta.matricula);
        printf("\nNota 1:    %.2f", al_consulta.n1);
        printf("\nNota 2:    %.2f", al_consulta.n2);
        printf("\nNota 3:    %.2f", al_consulta.n3);
    }else{
        printf("\nErro, consulta nao realizada.");
    }


    liberaPilha(pi);

    printf("\n\n");
    system("PAUSE");
    return 0;
}
*/
