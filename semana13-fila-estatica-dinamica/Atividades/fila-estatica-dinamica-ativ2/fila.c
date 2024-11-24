// Arquivo fila.c - FILA DIN�MICA
#include <stdio.h>
#include <stdlib.h>
#include "fila.h"

// Defini��o do n� descritor
struct fila{
    struct elemento *inicio;
    struct elemento *fim;
    int qtd;
};

struct elemento{
    ALUNO dados;
    struct elemento *prox;
};
//Apenas para n�o digitar muito a todo instante*
typedef struct elemento Elem;
/*######################################
// VERS�O FILA EST�TICA
// Defini��o do tipo FILA
struct fila{
    int inicio, fim, qtd;
    ALUNO dados[MAX];
};
######################################*/
FILA *criaFila(){
    FILA *fi = (FILA*) malloc(sizeof(FILA));
    if(fi != NULL){
        fi->fim = NULL;
        fi->inicio = NULL;
        fi->qtd = 0;
    }
    return fi;
}
/*######################################
// VERS�O FILA EST�TICA
FILA *criaFila(){
    FILA *fi;
    fi = (FILA*) malloc(sizeof(FILA));
    if(fi != NULL){
        fi->inicio = 0;
        fi->fim = 0;
        fi->qtd = 0;
    }
}
######################################*/
void liberaFila(FILA *fi){
    if(fi != NULL){
        Elem *no;
        while(fi->inicio != NULL){
            no = fi->inicio;
            fi->inicio = fi->inicio->prox;
            free(no);
        }
        free(fi);
    }
}
/*######################################
// VERS�O FILA EST�TICA
void liberaFila(FILA *fi){
    free(fi);
}
######################################*/
/*Fun��o IGUAL a vers�o da Fila Est�tica*/
void abortaPrograma(){
    printf("ERRO! Fila na foi alocada, ");
    printf("programa sera encerrado...\n\n\n");
    system("PAUSE");
    exit(1);
}

/*Fun��o IGUAL a vers�o da Fila Est�tica*/
int tamanhoFila(FILA *fi){
    if(fi == NULL){
        abortaPrograma();
    }
    return fi->qtd;
}

/*Em estruturas alocadas dinamicamente n�o faz sentido
o conceito de "estruturas cheias". Mant�m-se a fun��o
por uma quest�o de padroniza��o e compatibilidade com as
filas est�ticas.*/
int filaCheia(FILA *fi){
    return 0;
}
/*######################################
// VERS�O FILA EST�TICA
int filaCheia(FILA *fi){
    if(fi == NULL){
        abortaPrograma();
    }
    if(fi->qtd == MAX){
        return 1;
    }else{
        return 0;
    }
}
######################################*/
int filaVazia(FILA *fi){
    if(fi == NULL){
        abortaPrograma();
    }
    /*N�o � necess�rio verificar o final da lista*/
    if(fi->inicio == NULL){
        return 1;
    }
    return 0;
}
/*######################################
// VERS�O FILA EST�TICA
int filaVazia(FILA *fi){
    if(fi == NULL){
        abortaPrograma();
    }
    if(fi->qtd == 0){
        return 1;
    }else{
        return 0;
    }
}
######################################*/
int insereFila(FILA *fi, ALUNO al){
    if(fi == NULL){
        abortaPrograma();
    }
    Elem *no = (Elem*) malloc(sizeof(Elem));
    if(no == NULL){
        return 0;
    }
    no->dados = al;
    no->prox = NULL;
    if(fi->fim == NULL){ // Fila vazia
        fi->inicio = no;
    }else{ // Insere no final da fila
        fi->fim->prox = no;
    }
    fi->fim = no; // N� passa a ser novo final da fila
    fi->qtd++;
    return al.matricula;
}
/*######################################
// VERS�O FILA EST�TICA
int insereFila(FILA *fi, ALUNO al){
    if(fi == NULL){
        abortaPrograma();
    }
    if(fi->qtd == MAX){
        return 0;
    }
    fi->dados[fi->fim] = al;
    fi->fim = (fi->fim + 1) % MAX;
    fi->qtd++;
    return al.matricula;
}
######################################*/
int removeFila(FILA *fi){
    int matricula;
    if(fi == NULL){
        abortaPrograma();
    }
    if(fi->inicio == NULL){ // Fila vazia
        return 0;
    }
    matricula = fi->inicio->dados.matricula;
    Elem *no = fi->inicio;
    fi->inicio = fi->inicio->prox;
    if(fi->inicio == NULL){ // Fila ficou vazia
        fi->fim = NULL;
    }
    free(no);
    fi->qtd--;
    return matricula;
}
/*######################################
// VERS�O FILA EST�TICA
int removeFila(FILA *fi){
    int matricula;
    if(fi == NULL){
        abortaPrograma();
    }
    if(fi->qtd == 0){
        return 0;
    }
    matricula = fi->dados[fi->inicio].matricula;
    fi->inicio = (fi->inicio + 1) %MAX;
    fi->qtd--;
    return matricula;
}
######################################*/
int consultaFila(FILA *fi, ALUNO *al){
    if(fi == NULL){
        abortaPrograma();
    }
    if(fi->inicio == NULL){ // Fila vazia
        return 0;
    }
    *al = fi->inicio->dados;
    return 1;
}
/*######################################
// VERS�O FILA EST�TICA
int consultaFila(FILA *fi, ALUNO *al){
    if(fi == NULL){
        abortaPrograma();
    }
    if(fi->qtd == 0){
        return 0;
    }
    *al = fi->dados[fi->inicio];
    return 1;
}
######################################*/

