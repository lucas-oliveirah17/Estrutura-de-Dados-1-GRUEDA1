// Arquivo listaSequencial.c
#include <stdio.h>
#include <stdlib.h>
#include "listaSequencial.h"

/*Tipo de dado opaco que fica oculto, e � manipulado
pelo encapsulamento*/
struct lista{
    int qtd;
    struct aluno dados[MAX];
};

Lista *cria_lista(){
    Lista *li;
    li = (Lista*) malloc(sizeof(struct lista));
    if(li != NULL){
        li->qtd = 0;
    }
    /*Retorna somente  endere�os de mem�ria, ou seja,
    ponteiros*/
    return li;
}

void libera_lista(Lista *li){
    free(li);
}

int tamanho_lista(Lista *li){
    if(li == NULL){
        return -1;
    }else{
        return li->qtd;
    }
}

int lista_cheia(Lista *li){
    if(li == NULL){
        return -1;
    }else{
        /*Esta express�o retorna o resultador:
        Se for verdadeira: 1
        Se for falsa: 0*/
        return (li->qtd == MAX);
    }
}

int lista_vazia(Lista *li){
    if(li == NULL){
        return -1;
    }else{
        /*Esta express�o retorna o resultador:
        Se for verdadeira: 1
        Se for falsa: 0*/
        return (li->qtd == 0);
    }
}

int insere_lista_final(Lista *li, struct aluno al){
    if(li == NULL){
        return 0;
    }
    if(lista_cheia(li)){
        return 0;
    }
    li->dados[li->qtd] = al;
    li->qtd++;
    return 1;
}

int insere_lista_inicio(Lista *li, struct aluno al){
    if(li == NULL){
        return 0;
    }
    if(lista_cheia(li)){
        return 0;
    }
    int i;
    //1� Posi��o vazia dispon�vel
    for(i = li->qtd - 1; i >= 0; i--){
        /* Li->dados[i+1] posi��o a frenet do �ltimo elemento que est� na
        lista, recebe o �ltimo elemento da lista*/
        li->dados[i+1] = li->dados[i];
    }
    li->dados[0] = al; //Insere al no �nicio da lista
    li->qtd++;
    return 1;
}

int insere_lista_ordenada(Lista *li, struct aluno al){
    if(li == NULL){
        return 0;
    }
    if(lista_cheia(li)){
        return 0;
    }
    int k, i = 0;
    /*Enquanto "i" for menor que a quantidade de elementos que est�o
    na lista, e...
    ...as matr�culas que est�o na lista forem menores do que a que
    se quer inserir, incrementa-se i*/
    while(i < li->qtd && li->dados[i].matricula < al.matricula){
        i++;
    }
    /*Este "for", executa o deslocamento para frente, dos elementos que
    ficar�o ap�s o elemento a inserir*/
    for(k = li->qtd - 1; k >= i; k--){
        li->dados[k+1] = li->dados[k];
    }
    li->dados[i] = al; //Dado inserido na posi��o "encontrada" no la�o while
    li->qtd++;
    return 1;
}

int remove_lista_final(Lista *li){
    if(li == NULL){
        return 0;
    }
    if(li->qtd == 0){
        return 0;
    }
    li->qtd--;
    return 1;
}

int remove_lista_inicio(Lista *li){
    if(li == NULL){
        return 0;
    }
    if(li->qtd == 0){
        return 0;
    }
    int k = 0;
    for(k = 0; k < li->qtd-1; k++){
        li->dados[k] = li->dados[k+1];
    }
    li->qtd--;
    return 1;
}

int remove_lista(Lista *li, int matricula){
    if(li == NULL){
        return 0;
    }
    if(li->qtd == 0){
        return 0;
    }
    int k, i = 0;
    /*Se o elemento n�o for encontrado (caso em que i deixar�
    de ser menor do que o campo "qtd"), significa que chegamos
    ao final da lista e "i" ser� igual no campo "qtd", deixando
    de satisfazer a condi��o para que o la�o "while" continue
    a executar seus comandos.*/
    while(i < li->qtd && li->dados[i].matricula != matricula){
        i++;
    }
    if(i == li->qtd){ //Elemento n�o encontrado!
        return 0;
    }
    for(k = i; k < li->qtd-1; k++){
        li->dados[k] = li->dados[k+1];
    }
    li->qtd--;
    return 1;
}

//Busca por posi��o
int consulta_lista_pos(Lista *li, int pos,struct aluno *al){
    if(li == NULL || pos <= 0 || pos > li->qtd){		// if(li == NULL || pos <= 0 || pos >= li->qtd){
        return 0;
    }
    *al = li->dados[pos-1];
    return 1;
}

//Busca por conte�do
int consulta_lista_mat(Lista *li, int mat, struct aluno *al){
    if(li == NULL){
        return 0;
    }
    int i = 0;
    while(i < li->qtd && li->dados[i].matricula != mat){
        i++;
    }
    if(i == li->qtd){ //Elemento n�o encontrado
        return 0;
    }
    *al = li->dados[i];
    return 1;
}

struct aluno coletar_dados_aluno() {
    struct aluno al;
    printf("\nMatr�cula: ");
    scanf("%d", &al.matricula);

    do{
        printf("Nota 1: ");
        scanf("%f", &al.n1);
        if(al.n1 < 0 || al.n1 > 10)
            printf("Valor inv�lido! Somente valor de 0 � 10 s�o aceitos.\n");
    }while(!(al.n1 >= 0 && al.n1 <= 10));

    do{
        printf("Nota 2: ");
        scanf("%f", &al.n2);
        if(al.n2 < 0 || al.n2 > 10)
            printf("Valor inv�lido! Somente valor de 0 � 10 s�o aceitos.\n");
    }while(!(al.n2 >= 0 && al.n2 <= 10));

    do{
        printf("Nota 3: ");
        scanf("%f", &al.n3);
        if(al.n3 < 0 || al.n3 > 10)
            printf("Valor inv�lido! Somente valor de 0 � 10 s�o aceitos.\n");
    }while(!(al.n3 >= 0 && al.n3 <= 10));
    return al;
};
