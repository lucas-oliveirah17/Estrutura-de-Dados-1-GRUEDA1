// Arquivo main()
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "listaLigada.h"

int main()
{
    /*// Ponteiro para ponteiro. Parte está no arquivo
     listaLigada.h*/
    Lista *li = NULL;
    /*Código de erro. x receberá o código de erro como
    retorno das funções membro do Tipo Abstrato.*/
    int x;
    // Para as buscas
    /*matricula será usada na busca por um elemento
    específico
    posicao será usado na busca por um elemento em uma
    determinada posicao*/
    int matricula = 120, posicao = 2;
    // Para popular a lista e al para consulta
    /*al_consulta - estrura aluno ficará vazia e será
    utilizada para retorno de informações das buscas na
    lista*/
    ALUNO al_consulta, al1, al2, al3;

    /*al1 será usado na inserção no início*/
    al1.matricula = 110;
    al1.n1 = 5.6;
    al1.n2 = 6.3;
    al1.n3 = 7.9;

    /*al2 será usado na inserção no final*/
    al2.matricula = 130;
    al2.n1 = 9.2;
    al2.n2 = 3.5;
    al2.n3 = 8.1;

    /*a3 será usado na inserção ordenada*/
    al3.matricula = 120;
    al3.n1 = 6.6;
    al3.n2 = 2.1;
    al3.n3 = 9.2;

    setlocale(LC_ALL, "");
    printf("Atividade 1 - Lista Dinâmica\n");

    if((li = criaLista()) == NULL) {
        /*Se não possível alocar o bloco de memória,
        o programa será então abortado*/
        abortaPrograma();
    }

    x = tamanhoLista(li);
    printf("O tamanho da lista é: %d", x);

    if(listaCheia(li)){
        printf("\nLista está cheia!");
    }else{
        printf("\nLista não está cheia.");
    }

    if(listaVazia(li)){
        printf("\nLista está vazia!");
    }else{
        printf("\nLista não está vazia.");
    }

    x = insereInicio(li, al1);
    if(x){
        printf("\nAluno %d inserido no inicio com sucesso!", x);
    }else{
        printf("\nNão foi possível inserir no inicio.");
    }

    x = insereFinal(li, al2);
    if(x){
        printf("\nAluno %d inserido no final com sucesso!", x);
    }else{
        printf("\nNão foi possível inserir no final.");
    }

    x = insereOrdenado(li, al3);
    if(x){
        printf("\nAluno %d inserido ordenadamente com sucesso!", x);
    }else{
        printf("\nNão foi possível inserir ordenadamente.");
    }


    apagaLista(li);

    system("PAUSE");
    return 0;
}
