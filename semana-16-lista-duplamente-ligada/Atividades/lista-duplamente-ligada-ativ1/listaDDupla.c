// Arquivo listaDDupla.c

#include <stdio.h>
#include <stdlib.h>
#include "listaDDupla.h"

struct elemento{
    struct elemento *ant;
    struct elemento *prox;
    ALUNO dados;
};

typedef struct elemento ELEM;

LISTA *criaLista(){
    LISTA *li = (LISTA*) malloc(sizeof(LISTA));
    if(li != NULL){
        *li = NULL;
    }
    return li;
}

void apagaLista(LISTA *li){
    if(li != NULL){
        ELEM *no;
        while((*li) != NULL){
            no = *li;
            // Não é necessário trabalhar com o ponteiro "ant", somente o "prox",
            // igual a lista ligada.
            *li = (*li)->prox;
            free(no);
        }
        free(li);
    }
}

void abortaPrograma(){
    printf("ERRO! Lista nao foi alocada, ");
    printf("programa sera encerrado...\n\n\n");
    system("PAUSE");
    exit(1);
}

int tamanhoLista(LISTA *li){
    // Se o ponteiro li, contém NULL, significa que a Lista não foi alocada, então
    // o programa é abortado
    if(li == NULL){
        abortaPrograma();
    }
    int acum = 0;
    ELEM *no = *li;
    // O nó auxiliar recebe o primeiro elemento da lista e a percorre até encontrar
    // seu final (NULL) contando a cada deslocamento, quantos nós existem seguindo
    // para o próximo elemento
    while(no != NULL){
        acum++;
        no = no->prox;
    }
    return acum;
}

int listaCheia(LISTA *li){
    // Uma Lista Dinâmica, somente será considerada cheia quando não houver mais
    // espaço de memória disponível para alocar novos elementos...
    return 0;
}

int listaVazia(LISTA *li){
    if(li == NULL){ // Não existe Lista
        abortaPrograma();
    }
    if(*li == NULL){ // Lista está vazia
        // Uma Lista dinâmica é considerada vazia, sempre que o conteúdo de sua
        // "cabeça" ou "inicio" apontar para a constante "NULL".
        return 1;
    }
    return 0;
}

int insereInicio(LISTA *li, ALUNO al){
    if(li == NULL){
        abortaPrograma();
    }
    ELEM *no = (ELEM*) malloc(sizeof(ELEM));
    if(no == NULL){
        return 0;
    }
    no->dados = al;
    no->prox = *li;
    no->ant = NULL;
    // Se a lista não estava vazia, o atual 1º nó (que então passará a ser o segundo),
    // em sua parte "ant", passa a apontar para o novo nó que será inserido na
    // 1º posição. Por fim a cabeça, ou ponteiro início, recebe o endereço do novo nó
    // inserido.
    if(*li != NULL){
        (*li)->ant = no;
    }
    *li = no;
    return al.matricula;
}

int insereFinal(LISTA *li, ALUNO al){
    if(li == NULL){
        abortaPrograma();
    }
    ELEM *no = (ELEM*) malloc(sizeof(ELEM));
    if(no == NULL){
        return 0;
    }
    no->dados = al;
    // Como será o último nó, já recebe NULL
    no->prox = NULL;
    // Se lista vazia, inserção se dá no início
    if((*li) == NULL){
        no->ant = NULL;
        *li = no;
    }else{
        ELEM *aux = *li;
        // Ponteiro auxiliar para percorrer a lista. Enquanto o campo prox != NULL,
        // continua se deslocando na lista
        while(aux->prox != NULL){
            aux = aux->prox;
        }
        // O atual último elemento passa a apontar para o novo último elemento
        aux->prox = no;
        // O novo último elemento, em seu campo "ant", passa a apontar para o antigo
        // último elemento
        no->ant = aux;
    }
    return al.matricula;
}

int insereOrdenado(LISTA *li, ALUNO al){
    if(li == NULL){
        abortaPrograma();
    }
    ELEM *no = (ELEM*) malloc(sizeof(ELEM));
    if(no == NULL){
        return 0;
    }
    no->dados = al;
    if(listaVazia(li)){ // Insere em uma Lista vazia
        no->prox = NULL;
        no->ant = NULL;
        *li = no;
        return 1;
    }else{
        ELEM *anterior, *atual = *li;
        // Esse laço while percorre a Lista a procura da posição correta de inserção
        // do elemento
        while(atual != NULL && atual->dados.matricula < al.matricula){
            anterior = atual;
            atual = atual->prox;
        }
        // Insere no ínicio, quando matrícula é menor que todas. Se entrou aqui,
        // significa que atual nunca percorreu a Lista.
        if(atual == *li){
            no->ant = NULL;
            (*li)-> ant = no;
            no->prox = (*li);
            *li = no;
        // Trata qualquer inserção após a primeira posição, inclusive na última
        // posição
        }else{
            no->prox = anterior->prox;
            no->ant = anterior;
            anterior->prox = no;
            if(atual != NULL){
                atual->ant = no;
            }
        }
    }
    return al.matricula;
}

int removeInicio(LISTA *li){
    int matricula;
    if(li == NULL){
        abortaPrograma();
    }
    if(listaVazia(li)){
        return 0;
    }
    ELEM *no = *li;
    *li = no->prox;
    if(no -> prox != NULL){
        no->prox->ant = NULL;
    }
    matricula = no->dados.matricula;
    free(no);
    return matricula;
}

int removeFinal(LISTA *li){
    int matricula;
    if(li == NULL){
        abortaPrograma();
    }
    if((*li) == NULL){
        return 0;
    }
    ELEM *no = *li;
    // Percorre a Lista até que o campo prox do nó aponte para NULL
    while(no->prox != NULL){
        no = no->prox;
    }
    // Remove o primeiro e único elemento da Lista. Para que este "if" seja satisfeito,
    // é necessário termos só 1 elemento na Lista
    if(no->ant == NULL){
        *li = no->prox;
    }else{
        no->ant->prox = NULL;
    }
    matricula = no->dados.matricula;
    free(no);
    return matricula;
}

int removeOrdenado(LISTA *li, int mat){
    int matricula;
    if(li == NULL){
        abortaPrograma();
    }
    ELEM *no = *li;
    while(no != NULL && no->dados.matricula != mat){
        no = no->prox;
    }
    if(no == NULL){ // Não encontrado - chegou ao final
        return 0;   // e não encontrou o elemento
    }
    if(no->ant == NULL){ // Remove o primeiro
        *li = no->prox;
        // no->prox->ant = NULL;
    }else{
        no->ant->prox = no ->prox; // Remove no meio
    }
    if(no->prox != NULL){
        no->prox->ant = no->ant; // Remove o último
    }
    matricula = no->dados.matricula;
    free(no);
    return matricula;
}

int consultaPosicao(LISTA *li, int pos, ALUNO *al){
    if(li == NULL || pos <= 0){
        abortaPrograma();
    }
    ELEM *no = *li;
    int i = 1;
    while(no != NULL && i < pos){
        no = no->prox;
        i++;
    }
    // Se no == NULL, significa que posição infomada é maior que nº elementos
    if(no == NULL){
        return 0;
    // Se no != NULL, o laço while foi interrompido porque elemento foi encontrado
    }else{
        *al = no->dados;
        return 1;
    }
}

int consultaMatricula(LISTA *li, int mat, ALUNO *al){
    if(li == NULL){
        abortaPrograma();
    }
    ELEM *no = *li;
    while(no != NULL && no->dados.matricula != mat){
        no = no->prox;
    }
    // Se no == NULL, significa que matrícula informada não existe
    if(no == NULL){
        return 0;
    // Se no != NULL, o laço while foi interrommpido porque a matrícula foi encontrada
    }else{
        *al = no->dados;
        return 1;
    }
}
