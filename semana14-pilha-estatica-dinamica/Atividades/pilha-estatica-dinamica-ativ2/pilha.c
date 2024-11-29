// Arquivo pilha.c - PILHA DINÃMICA
#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"

// Definição do tipo PILHA
struct elemento{
    ALUNO dados;
    struct elemento *prox;
};
/*struct pilha{ // Versão PDF
    ALUNO dados;
    struct pilha *prox;
};*/
/*######################################
// VERSÃO PILHA ESTÁTICA
// Definição do tipo PILHA
struct pilha{
    int qtd;
    ALUNO dados[MAX];
};
######################################*/

/*Apenas para não digitar muito a todo instante...*/
typedef struct elemento ELEM;
//typedef struct pilha ELEM; // Versão PDF

PILHA *criaPilha(){
    PILHA *pi = (PILHA*) malloc(sizeof(PILHA));
    if(pi != NULL){
       *pi = NULL;
    }
    return pi;
}
/*######################################
// VERSÃO PILHA ESTÁTICA
PILHA *criaPilha(){
    PILHA *pi;
    pi = (PILHA*) malloc(sizeof(PILHA));
    if(pi != NULL){
       pi->qtd = 0;
    }
    return pi;
}
######################################*/

void liberaPilha(PILHA *pi){
    if(pi != NULL){
        ELEM *no;
        while((*pi) != NULL){
            /*Recebe o 1º elemento da Pilha*/
            no = *pi;
            /*O topo recebe o próximo elemento da
            pilha.*/
            *pi = (*pi)->prox;
            /*Libera o antigo topo da Pilha.*/
            free(no);
        }
        // Remove topo.
        free(pi);
    }
}
/*######################################
// VERSÃO PILHA ESTÁTICA
void liberaPilha(PILHA *pi){
    free(pi);
}
######################################*/
void abortaPrograma(){
    printf("ERRO! Pilha nao foi alocada, ");
    printf("programa sera encerrado...\n\n\n");
    system("PAUSE");
    exit(1);
}

int tamanhoPilha(PILHA *pi){
    if(pi == NULL){
        abortaPrograma();
        //return -1; // Valor de retorno arbitrário para evitar warnings
    }
    int acum = 0;
    ELEM *no = *pi;
    while(no != NULL){
        acum++;
        no = no->prox;
    }
    return acum;
}
/*######################################
// VERSÃO PILHA ESTÁTICA
int tamanhoPilha(PILHA *pi){
    if(pi == NULL){
        abortaPrograma();
        return -1; // Valor de retorno arbitrário para evitar warnings
    }else{
        return pi->qtd;
    }
}
######################################*/

int pilhaCheia(PILHA *pi){
    return 0;
}
/*######################################
// VERSÃO PILHA ESTÁTICA
int pilhaCheia(PILHA *pi){
    if(pi == NULL){
        abortaPrograma();
        return -1; // Valor de retorno arbitrário para evitar warnings
    }else{
        return (pi->qtd == MAX);
    }
}
######################################*/

int pilhaVazia(PILHA *pi){
    if(pi == NULL){
        abortaPrograma();
        //return -1; // Valor de retorno arbitrário para evitar warnings
    }
    if(*pi == NULL){ //Pilha existe, mas sem elementos
        return 1;
    }
    return 0;
}
/*######################################
// VERSÃO PILHA ESTÁTICA
int pilhaVazia(PILHA *pi){
    if(pi == NULL){
        abortaPrograma();
        return -1; // Valor de retorno arbitrário para evitar warnings
    }else{
        return (pi->qtd == 0);
    }
}
######################################*/

int inserePilha(PILHA *pi, ALUNO al){
    if(pi == NULL){
        abortaPrograma();
    }
    ELEM *no = (ELEM*) malloc(sizeof(ELEM));
    if(no == NULL){
        return 0;
    }
    no->dados = al;
    no->prox = (*pi);
    *pi = no;
    return al.matricula;
}
/*######################################
// VERSÃO PILHA ESTÁTICA
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
######################################*/

int removePilha(PILHA *pi){
    int matricula;
    if(pi == NULL){ // Se pilha não alocada
        abortaPrograma();
    }
    if((*pi) == NULL){ // Se pilha vazia
        return 0;
    }
    ELEM *no = *pi;
    *pi = no->prox;
    matricula = (*no).dados.matricula;
    free(no);
    return matricula;
}
/*######################################
// VERSÃO PILHA ESTÁTICA
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
######################################*/

int acessaTopoPilha(PILHA *pi, ALUNO *al){
    if(pi == NULL){
        abortaPrograma();
    }
    if((*pi) == NULL){
        return 0;
    }
    *al = (*pi)->dados;
    return 1;
}
/*######################################
// VERSÃO PILHA ESTÁTICA
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
######################################*/
