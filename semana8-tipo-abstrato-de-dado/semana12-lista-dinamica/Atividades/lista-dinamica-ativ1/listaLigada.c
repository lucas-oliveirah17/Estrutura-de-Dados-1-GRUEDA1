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
    /*Armazenará o endereço do início do bloco alocado,
    e será devolvido ao main()*/
    li = (Lista*) malloc(sizeof(Lista));
    /*Se alocação ok, preenche o conteúdo que foi
    alocado com NULL*/
    if(li != NULL) {
        *li = NULL;
    }
    return li;
}

void abortaPrograma(){
    /*Em cada função que acessa diretamente a lista, é
    absolutamente necessário testar se a mesma foi
    alocada*/
    printf("ERRO! Lista nao foi alocada, ");
    printf("programa sera encerrado...\n\n\n");
    system("PAUSE");
    exit(1);
}

void apagaLista(Lista *li){
    /*Recebe o endereço da lista na memória*/
    /*Lista será válida se li for diferente de NULL*/
    if(li != NULL){
        ELEM *no;
        /*Enquanto o primeiro elemento da lista não
        for diferente de NULL, a lista não estará vazia.
        while: executa este conjunto de instruções, até
        que a cabeça da lista aponte para NULL, e assim a
        lista estará vazia.*/
        while((*li) != NULL){
            no = *li;
            /*Inicio da lista, aponta para próximo elemento
            da lista*/
            *li = (*li)->prox;
            free(no);
        }
        /*Ao final, libera a cabeça da lista (ponteiro especial)
        que aponta para o ínicio*/
        free(li);
    }
}

int tamanhoLista(Lista *li) {
    if(li == NULL){
        abortaPrograma();
    }
    int acum = 0;
    /*nó é um ponteiro auxiliar e recebe o 1º elemento da
    Lista. nó foi criado para se preservar o inicio da
    lista, porque se andarmos com a cabeça da lista,
    perderemos seu endereço de início. Sempre percorremos
    uma lista com elementos auxiliares, para não perdermos
    informações*/
    ELEM *no = *li;
    while(no != NULL){
        /*Enquanto nó não for NULL, incrementa o acumulador e
        se desloca para o próximo nó.*/
        acum++;
        no = no->prox;
    }
    /*acum retorna a quantidade de elementos que existem
    na lista.*/
    return acum;
}

int listaCheia(Lista *li){
    /*• Em Listas Ligadas (dinâmicas encadeadas), não
    existe o conceito de lista cheia.
    Esta função é mantida apenas por questões de
    compatibilidade com outras estruturas do tipo
    Lista.*/
    if(li == NULL){
        abortaPrograma();
    }
    return 0;
}

int listaVazia(Lista *li){
    if(li == NULL){
        /*Se a lista não foi alocada, ou seja, li for igual
        a NULL o programa é então abortado.*/
        abortaPrograma();
    }
    /*Se no endereço que *li aponta, estiver armazenado NULL,
    ainda não existe nenhum elemento dentro da lista.*/
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
    /*Resolve inserção no início da lista e em uma lista vazia*/
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
    /*Se lista vazia, insere no início*/
    if((*li) == NULL){
        *li = no;
    }else{
        /*Busca onde inserir*/
        ELEM *aux = *li;
        /*Percorre a lista com um ponteiro auxiliar para
        preservar a cabeça da lista*/
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
        /*Insere se estiver na primeira posição*/
        if(atual == *li){
            no->prox = (*li);
            *li = no;
        }else{
            /*Insere em qualquer outra posição*/
            no->prox = ant->prox;
            ant->prox = no;
        }
        return al.matricula;
    }
}
