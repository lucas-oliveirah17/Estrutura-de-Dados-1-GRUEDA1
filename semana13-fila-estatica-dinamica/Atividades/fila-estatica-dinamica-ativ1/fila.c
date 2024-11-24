// Arquivo fila.c - FILA EST�TICA
#include <stdio.h>
#include <stdlib.h>
#include "fila.h"

// Defini��o do tipo FILA
struct fila{
    int inicio, fim, qtd;
    /*Por est� definido dentro do arquivo fila.c, os
    campos dessa estrutura, n�o s�o vis�veis pelo main(),
    apenas seu outro nome FILA que foi definido no
    arquivo fila.h. main() pode apenar declarar ponteiros
    para este tipo de dado, que deve ser inicializado com
    NULL para a detec��o de aloca��o.*/
    ALUNO dados[MAX];
};

FILA *criaFila(){
    FILA *fi;
    fi = (FILA*) malloc(sizeof(FILA));
    if(fi != NULL){
        fi->inicio = 0;
        fi->fim = 0;
        fi->qtd = 0;
    }
}

void liberaFila(FILA *fi){
    free(fi);
}

void abortaPrograma(){
    printf("ERRO! Fila na foi alocada, ");
    printf("programa sera encerrado...\n\n\n");
    system("PAUSE");
    exit(1);
}

int tamanhoFila(FILA *fi){
    if(fi == NULL){
        abortaPrograma();
    }
    return fi->qtd;
}

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

int insereFila(FILA *fi, ALUNO al){
    if(fi == NULL){
        abortaPrograma();
    }
    if(fi->qtd == MAX){
        return 0;
    }
    fi->dados[fi->fim] = al;
    /*Utilizamos o resto da divis�o no c�lculo do novo
    final da Fila. Isso � feio para simular uma Fila
    circular. Dessa forma, ao chegar na posi��o MAX (que n�o
    existe no array), o final da fila ser� colocado na
    posi��o ZERO, de modo que as posi��es no come�o do array
    que ficarem vagas, a medida que elementos s�o inseridos e
    removidos da fila, poder�o tamb�m ser utilizadas.*/
    fi->fim = (fi->fim + 1) % MAX;
    fi->qtd++;
    return al.matricula;
}

int removeFila(FILA *fi){
    int matricula;
    if(fi == NULL){
        abortaPrograma();
    }
    if(fi->qtd == 0){
        return 0;
    }
    matricula = fi->dados[fi->inicio].matricula;
    /*Utilizamos o resto da divis�o no c�lculo do novo inicio da
    Fila. Isso � feito para simular uma filar circular. Dessa forma,
    ao chegar na posi��o MAX (que n�o existe no array), o inicio
    da fila ser� colocado na posi��o ZERO, de modo que as posi��es
    no come�o do array que ficarem vagas, a medida que elementos s�o
    inseridos e removidos da fila, poder�o tamb�m ser utilizadas.*/
    fi->inicio = (fi->inicio + 1) %MAX;
    fi->qtd--;
    return matricula;
}

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
