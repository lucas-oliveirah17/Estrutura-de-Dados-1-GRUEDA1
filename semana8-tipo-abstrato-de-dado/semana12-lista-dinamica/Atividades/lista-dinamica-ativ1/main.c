// Arquivo main()
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "listaLigada.h"

int main()
{
    /*// Ponteiro para ponteiro. Parte est� no arquivo
     listaLigada.h*/
    Lista *li = NULL;
    /*C�digo de erro. x receber� o c�digo de erro como
    retorno das fun��es membro do Tipo Abstrato.*/
    int x;
    // Para as buscas
    /*matricula ser� usada na busca por um elemento
    espec�fico
    posicao ser� usado na busca por um elemento em uma
    determinada posicao*/
    int matricula = 120, posicao = 2;
    // Para popular a lista e al para consulta
    /*al_consulta - estrura aluno ficar� vazia e ser�
    utilizada para retorno de informa��es das buscas na
    lista*/
    ALUNO al_consulta, al1, al2, al3;

    /*al1 ser� usado na inser��o no in�cio*/
    al1.matricula = 110;
    al1.n1 = 5.6;
    al1.n2 = 6.3;
    al1.n3 = 7.9;

    /*al2 ser� usado na inser��o no final*/
    al2.matricula = 130;
    al2.n1 = 9.2;
    al2.n2 = 3.5;
    al2.n3 = 8.1;

    /*a3 ser� usado na inser��o ordenada*/
    al3.matricula = 120;
    al3.n1 = 6.6;
    al3.n2 = 2.1;
    al3.n3 = 9.2;

    setlocale(LC_ALL, "");
    printf("Atividade 1 - Lista Din�mica\n");

    if((li = criaLista()) == NULL) {
        /*Se n�o poss�vel alocar o bloco de mem�ria,
        o programa ser� ent�o abortado*/
        abortaPrograma();
    }

    x = tamanhoLista(li);
    printf("O tamanho da lista �: %d", x);

    if(listaCheia(li)){
        printf("\nLista est� cheia!");
    }else{
        printf("\nLista n�o est� cheia.");
    }

    if(listaVazia(li)){
        printf("\nLista est� vazia!");
    }else{
        printf("\nLista n�o est� vazia.");
    }

    x = insereInicio(li, al1);
    if(x){
        printf("\nAluno %d inserido no inicio com sucesso!", x);
    }else{
        printf("\nN�o foi poss�vel inserir no inicio.");
    }

    x = insereFinal(li, al2);
    if(x){
        printf("\nAluno %d inserido no final com sucesso!", x);
    }else{
        printf("\nN�o foi poss�vel inserir no final.");
    }

    x = insereOrdenado(li, al3);
    if(x){
        printf("\nAluno %d inserido ordenadamente com sucesso!", x);
    }else{
        printf("\nN�o foi poss�vel inserir ordenadamente.");
    }


    apagaLista(li);

    system("PAUSE");
    return 0;
}
