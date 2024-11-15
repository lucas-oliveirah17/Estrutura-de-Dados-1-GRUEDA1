// Arquivo listaLigada.c
#include <stdio.h>
#include <stdlib.h>
#include "listaLigada.h"

struct elemento{
    ALUNO dados;
    struct elemento *prox;
};

typedef struct elemento ELEM;

Lista *criaLista(){
    Lista *li;
    /*Armazenar� o endere�o do in�cio do bloco alocado,
    e ser� devolvido ao main()*/
    li = (Lista*) malloc(sizeof(Lista));
    /*Se aloca��o ok, preenche o conte�do que foi
    alocado com NULL*/
    if(li != NULL) {
        *li = NULL;
    }
    return li;
}

void abortaPrograma(){
    /*Em cada fun��o que acessa diretamente a lista, �
    absolutamente necess�rio testar se a mesma foi
    alocada*/
    printf("ERRO! Lista nao foi alocada, ");
    printf("programa sera encerrado...\n\n\n");
    system("PAUSE");
    exit(1);
}

void apagaLista(Lista *li){
    /*Recebe o endere�o da lista na mem�ria*/
    /*Lista ser� v�lida se li for diferente de NULL*/
    if(li != NULL){
        ELEM *no;
        /*Enquanto o primeiro elemento da lista n�o
        for diferente de NULL, a lista n�o estar� vazia.
        while: executa este conjunto de instru��es, at�
        que a cabe�a da lista aponte para NULL, e assim a
        lista estar� vazia.*/
        while((*li) != NULL){
            no = *li;
            /*Inicio da lista, aponta para pr�ximo elemento
            da lista*/
            *li = (*li)->prox;
            free(no);
        }
        /*Ao final, libera a cabe�a da lista (ponteiro especial)
        que aponta para o �nicio*/
        free(li);
    }
}

int tamanhoLista(Lista *li) {
    if(li == NULL){
        abortaPrograma();
    }
    int acum = 0;
    /*n� � um ponteiro auxiliar e recebe o 1� elemento da
    Lista. n� foi criado para se preservar o inicio da
    lista, porque se andarmos com a cabe�a da lista,
    perderemos seu endere�o de in�cio. Sempre percorremos
    uma lista com elementos auxiliares, para n�o perdermos
    informa��es*/
    ELEM *no = *li;
    while(no != NULL){
        /*Enquanto n� n�o for NULL, incrementa o acumulador e
        se desloca para o pr�ximo n�.*/
        acum++;
        no = no->prox;
    }
    /*acum retorna a quantidade de elementos que existem
    na lista.*/
    return acum;
}

int listaCheia(Lista *li){
    /*� Em Listas Ligadas (din�micas encadeadas), n�o
    existe o conceito de lista cheia.
    Esta fun��o � mantida apenas por quest�es de
    compatibilidade com outras estruturas do tipo
    Lista.*/
    if(li == NULL){
        abortaPrograma();
    }
    return 0;
}

int listaVazia(Lista *li){
    if(li == NULL){
        /*Se a lista n�o foi alocada, ou seja, li for igual
        a NULL o programa � ent�o abortado.*/
        abortaPrograma();
    }
    /*Se no endere�o que *li aponta, estiver armazenado NULL,
    ainda n�o existe nenhum elemento dentro da lista.*/
    if(*li == NULL){
        return 1;
    }
    return 0;
}

int insereInicio(Lista *li, ALUNO al){
    if(li == NULL){
        abortaPrograma();
    }
    ELEM *no = (ELEM*) malloc(sizeof(ELEM));
    if(no == NULL){
        return 0;
    }
    /*Resolve inser��o no in�cio da lista e em uma lista vazia*/
    no->dados = al;
    no->prox = (*li);
    *li = no;
    return al.matricula;
}

int insereFinal(Lista *li, ALUNO al){
    if(li == NULL){
        abortaPrograma();
    }
    ELEM *no = (ELEM*) malloc(sizeof(ELEM));
    if(no == NULL){
        return 0;
    }
    /*Insere dados depois de aux*/
    no->dados = al;
    no->prox = NULL;
    /*Se lista vazia, insere no in�cio*/
    if((*li) == NULL){
        *li = no;
    }else{
        /*Busca onde inserir*/
        ELEM *aux = *li;
        /*Percorre a lista com um ponteiro auxiliar para
        preservar a cabe�a da lista*/
        while(aux->prox != NULL){
            aux = aux->prox;
        }
        aux->prox = no;
    }
    return al.matricula;
}

int insereOrdenado(Lista *li, ALUNO al){
    if(li == NULL){
    abortaPrograma();
    }
    ELEM *no = (ELEM*) malloc(sizeof(ELEM));
    if(no == NULL){
        return 0;
    }
    no->dados = al;
    if(listaVazia(li)){
        no->prox = (*li);
        *li = no;
        return al.matricula;
    }else{
        ELEM *ant, *atual = *li;
        while(atual != NULL && atual->dados.matricula < al.matricula){
            ant = atual;
            atual = atual->prox;
        }
        /*Insere se estiver na primeira posi��o*/
        if(atual == *li){
            no->prox = (*li);
            *li = no;
        }else{
            /*Insere em qualquer outra posi��o*/
            no->prox = ant->prox;
            ant->prox = no;
        }
        return al.matricula;
    }
}
