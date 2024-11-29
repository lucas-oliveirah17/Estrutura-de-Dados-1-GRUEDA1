// Arquivo pilha.c - PILHA ESTÁTICA
#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"

// Definição do tipo PILHA
struct pilha{
    int qtd;
    ALUNO dados[MAX];
};

PILHA *criaPilha(){
    PILHA *pi;
    pi = (PILHA*) malloc(sizeof(PILHA));
    if(pi != NULL){
       pi->qtd = 0;
    }
    return pi;
}

void liberaPilha(PILHA *pi){
    free(pi);
}

void abortaPrograma(){
    printf("ERRO! Pilha nao foi alocada, ");
    printf("programa sera encerrado...\n\n\n");
    system("PAUSE");
    exit(1);
}

int tamanhoPilha(PILHA *pi){
    if(pi == NULL){
        abortaPrograma();
        return -1; // Valor de retorno arbitrário para evitar warnings
    }else{
        return pi->qtd;
    }
}

int pilhaCheia(PILHA *pi){
    if(pi == NULL){
        abortaPrograma();
        return -1; // Valor de retorno arbitrário para evitar warnings
    }else{
        return (pi->qtd == MAX);
    }
}

int pilhaVazia(PILHA *pi){
    if(pi == NULL){
        abortaPrograma();
        return -1; // Valor de retorno arbitrário para evitar warnings
    }else{
        return (pi->qtd == 0);
    }
}

int inserePilha(PILHA *pi, ALUNO al){
    if(pi == NULL){
        abortaPrograma();
    }
    if(pi->qtd == MAX){
        return 0;
    }
    pi->dados[pi->qtd] = al;
    pi->qtd++;
    return al.matricula;
}

int removePilha(PILHA *pi){
    int matricula;
    if(pi == NULL){
        abortaPrograma();
    }
    if(pi->qtd == 0){
        return 0;
    }
    matricula = pi->dados[pi->qtd - 1].matricula;
    pi->qtd--;
    return matricula;
}

int acessaTopoPilha(PILHA *pi, ALUNO *al){
    if(pi == NULL){
        abortaPrograma();
    }
    if(pi->qtd == 0){
        return 0;
    }
    *al = pi->dados[pi->qtd - 1];
    return 1;
}
