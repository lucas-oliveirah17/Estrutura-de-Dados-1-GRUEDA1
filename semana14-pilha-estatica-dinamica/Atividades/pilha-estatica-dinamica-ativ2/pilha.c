// Arquivo pilha.c - PILHA DIN�MICA
#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"

// Defini��o do tipo PILHA
struct elemento{
    ALUNO dados;
    struct elemento *prox;
};
/*struct pilha{ // Vers�o PDF
    ALUNO dados;
    struct pilha *prox;
};*/
/*######################################
// VERS�O PILHA EST�TICA
// Defini��o do tipo PILHA
struct pilha{
    int qtd;
    ALUNO dados[MAX];
};
######################################*/

/*Apenas para n�o digitar muito a todo instante...*/
typedef struct elemento ELEM;
//typedef struct pilha ELEM; // Vers�o PDF

PILHA *criaPilha(){
    PILHA *pi = (PILHA*) malloc(sizeof(PILHA));
    if(pi != NULL){
       *pi = NULL;
    }
    return pi;
}
/*######################################
// VERS�O PILHA EST�TICA
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
            /*Recebe o 1� elemento da Pilha*/
            no = *pi;
            /*O topo recebe o pr�ximo elemento da
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
// VERS�O PILHA EST�TICA
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
        //return -1; // Valor de retorno arbitr�rio para evitar warnings
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
// VERS�O PILHA EST�TICA
int tamanhoPilha(PILHA *pi){
    if(pi == NULL){
        abortaPrograma();
        return -1; // Valor de retorno arbitr�rio para evitar warnings
    }else{
        return pi->qtd;
    }
}
######################################*/

int pilhaCheia(PILHA *pi){
    return 0;
}
/*######################################
// VERS�O PILHA EST�TICA
int pilhaCheia(PILHA *pi){
    if(pi == NULL){
        abortaPrograma();
        return -1; // Valor de retorno arbitr�rio para evitar warnings
    }else{
        return (pi->qtd == MAX);
    }
}
######################################*/

int pilhaVazia(PILHA *pi){
    if(pi == NULL){
        abortaPrograma();
        //return -1; // Valor de retorno arbitr�rio para evitar warnings
    }
    if(*pi == NULL){ //Pilha existe, mas sem elementos
        return 1;
    }
    return 0;
}
/*######################################
// VERS�O PILHA EST�TICA
int pilhaVazia(PILHA *pi){
    if(pi == NULL){
        abortaPrograma();
        return -1; // Valor de retorno arbitr�rio para evitar warnings
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
// VERS�O PILHA EST�TICA
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
    if(pi == NULL){ // Se pilha n�o alocada
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
// VERS�O PILHA EST�TICA
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
// VERS�O PILHA EST�TICA
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
