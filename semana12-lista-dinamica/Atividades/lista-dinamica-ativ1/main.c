/*
Monte o programa com todas as fun��es apresentadas pertencente � lista ligada.
� Implemente nesta lista a mesma fun��o coletadados(), do exerc�cio lista est�tica, e
 descarte as inser��es via c�digo (as 3 inser��es de teste).
� Crie um menu que funcione ininterruptamente com 4 op��es:
� Incluir um elemento de forma ordenada utilizando a fun��o coletadados();
� Buscar um elemento por conte�do (matr�cula);
� Excluir um elemento de forma ordenada, e;
� Encerrar o programa.
*/
// Arquivo main()
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "listaLigada.h"

int main(){
    Lista *li = NULL;
    int x; // Para c�digo de erro
    int entrada = 0; // Para receber a entrada do usu�rio
    int matricula = 120, posicao = 2; // Para testes de busca

    ALUNO al_consulta;
    ALUNO al1, al2, al3; //

    // al1 ser� usado na inser��o no in�cio
    al1.matricula = 110;
    al1.n1 = 5.6;
    al1.n2 = 6.3;
    al1.n3 = 7.9;

    // al2 ser� usado na inser��o no final
    al2.matricula = 130;
    al2.n1 = 9.2;
    al2.n2 = 3.5;
    al2.n3 = 8.1;

    // a3 ser� usado na inser��o ordenada
    al3.matricula = 120;
    al3.n1 = 6.6;
    al3.n2 = 2.1;
    al3.n3 = 9.2;

    setlocale(LC_ALL, "");
    printf("Atividade 1 - Lista Sequencial Din�mica");

    printf("\n\n\tTESTES\n");

    // Cria Lista
    if((li = criaLista()) == NULL) {
        //Se n�o poss�vel alocar o bloco de mem�ria, o programa
        // ser� ent�o abortado
        abortaPrograma();
    }
    // Verifica tamanho da lista
    x = tamanhoLista(li);
    printf("\nO tamanho da lista �: %d", x);

    // Verifica se lista est� cheia
    if(listaCheia(li)){
        printf("\nLista est� cheia!");
    }else{
        printf("\nLista n�o est� cheia.");
    }

    // Verifica se lista est� vazia
    if(listaVazia(li)){
        printf("\nLista est� vazia.");
    }else{
        printf("\nLista n�o est� vazia.");
    }

    // Insere aluno 110 no inicio da lista
    x = insereInicio(li, al1);
    if(x){
        printf("\nAluno %d inserido no inicio com sucesso!", x);
    }else{
        printf("\nN�o foi poss�vel inserir no inicio.");
    }

    // Verifica se lista est� vazia
    if(listaVazia(li)){
        printf("\nLista est� vazia.");
    }else{
        printf("\nLista n�o est� vazia.");
    }

    // Insere aluno 130 no final da lista
    x = insereFinal(li, al2);
    if(x){
        printf("\nAluno %d inserido no final com sucesso!", x);
    }else{
        printf("\nN�o foi poss�vel inserir no final.");
    }

    // Insere aluno 120 ordenadamente na lista
    x = insereOrdenado(li, al3);
    if(x){
        printf("\nAluno %d inserido ordenadamente com sucesso!", x);
    }else{
        printf("\nN�o foi poss�vel inserir ordenadamente.");
    }

    // Verifica tamanho da lista
    x = tamanhoLista(li);
    printf("\n\nO tamanho da lista �: %d", x);

    // Consulta aluno na posi��o 2
    x = consultaPosicao(li, posicao, &al_consulta);
    if(x){
        printf("\n\nConsulta na posi��o %d", posicao);
        printf("\nMatr�cula:  %d", al_consulta.matricula);
        printf("\nNota 1:     %.2f", al_consulta.n1);
        printf("\nNota 2:     %.2f", al_consulta.n2);
        printf("\nNota 3:     %.2f", al_consulta.n3);
    }else{
        printf("\n\nPosi��o %d n�o existe", posicao);
    }

    // Consulta aluno na posi��o 4
    x = consultaPosicao(li, 4, &al_consulta);
    if(x){
        printf("\n\nConsulta na posi��o %d", posicao);
        printf("\nMatr�cula:  %d", al_consulta.matricula);
        printf("\nNota 1:     %.2f", al_consulta.n1);
        printf("\nNota 2:     %.2f", al_consulta.n2);
        printf("\nNota 3:     %.2f", al_consulta.n3);
    }else{
        printf("\n\nPosi��o %d n�o existe", 4);
    }

    // Consulta aluno com matr�cula 120
    x = consultaMatricula(li, matricula, &al_consulta);
    if(x){
        printf("\n\nConsulta aluno de matricula %d", matricula);
        printf("\nMatr�cula:  %d", al_consulta.matricula);
        printf("\nNota 1:     %.2f", al_consulta.n1);
        printf("\nNota 2:     %.2f", al_consulta.n2);
        printf("\nNota 3:     %.2f", al_consulta.n3);
    }else{
        printf("\n\nMatricula %d n�o encontrada", matricula);
    }

    // Remove ordenadamente aluno de matricula 120
    x = removeOrdenado(li, matricula);
    if(x){
        printf("\n\nAluno %d removido ordenadamente com sucesso!", x);
    }else{
        printf("\n\nN�o foi poss�vel remover do final.");
    }

    // Consulta aluno com matr�cula 120
    x = consultaMatricula(li, matricula, &al_consulta);
    if(x){
        printf("\n\nConsulta aluno de matricula %d", matricula);
        printf("\nMatr�cula:  %d", al_consulta.matricula);
        printf("\nNota 1:     %.2f", al_consulta.n1);
        printf("\nNota 2:     %.2f", al_consulta.n2);
        printf("\nNota 3:     %.2f", al_consulta.n3);
    }else{
        printf("\n\nMatricula %d n�o encontrada", matricula);
    }

    // Consulta aluno na posi��o 2
    x = consultaPosicao(li, posicao, &al_consulta);
    if(x){
        printf("\n\nConsulta na posi��o %d", posicao);
        printf("\nMatr�cula:  %d", al_consulta.matricula);
        printf("\nNota 1:     %.2f", al_consulta.n1);
        printf("\nNota 2:     %.2f", al_consulta.n2);
        printf("\nNota 3:     %.2f", al_consulta.n3);
    }else{
        printf("\n\nPosi��o %d n�o existe", posicao);
    }

    // Consulta aluno na posi��o 2
    x = consultaPosicao(li, 3, &al_consulta);
    if(x){
        printf("\n\nConsulta na posi��o %d", posicao);
        printf("\nMatr�cula:  %d", al_consulta.matricula);
        printf("\nNota 1:     %.2f", al_consulta.n1);
        printf("\nNota 2:     %.2f", al_consulta.n2);
        printf("\nNota 3:     %.2f", al_consulta.n3);
    }else{
        printf("\n\nPosi��o %d n�o existe", 3);
    }

    // Remover aluno do final da lista
    x = removeFinal(li);
    if(x){
        printf("\nAluno %d removido do final com sucesso!", x);
    }else{
        printf("\nN�o foi poss�vel remover do final.");
    }

    // Remover aluno do in�cio da lista
    x = removeInicio(li);
    if(x){
        printf("\nAluno %d removido do in�cio com sucesso!", x);
    }else{
        printf("\nN�o foi poss�vel remover do in�cio.");
    }

    printf("\n\n");
    system("PAUSE");
    system("cls");

    do{
        printf("\tMENU");
        printf("\n[1] - Adicionar aluno");
        printf("\n[2] - Buscar aluno (Matr�cula)");
        printf("\n[3] - Excluir aluno");
        printf("\n[4] - Encerrar o programa.\n");
        printf("\n[5] - Buscar todos os alunos.\n"); // Op��o para teste
        printf("\nEntrada: ");
        scanf("%d", &entrada);

        switch(entrada){
            case 1: // Adicionar Aluno
                printf("\n\nAdicionando novo aluno a lista...");
                x = insereOrdenado(li, coletar_dados_aluno());
                if(x){
                printf("Aluno cadastrado com sucesso!");
                }else{
                    printf("Erro! Aluno n�o cadastrado!");
                }
                printf("\n\n");
                system("PAUSE");
                system("cls");
                break;

            case 2: // Buscar aluno (Matr�cula)
                printf("\nMatr�cula do aluno para buscar: ");
                scanf("%d", &matricula);
                x = consultaMatricula(li, matricula, &al_consulta);
                if(x){
                    printf("\n\nConsulta aluno de matricula %d", matricula);
                    printf("\nMatr�cula:  %d", al_consulta.matricula);
                    printf("\nNota 1:     %.2f", al_consulta.n1);
                    printf("\nNota 2:     %.2f", al_consulta.n2);
                    printf("\nNota 3:     %.2f", al_consulta.n3);
                }else{
                    printf("\n\nMatricula %d n�o encontrada", matricula);
                }
                printf("\n\n");
                system("PAUSE");
                system("cls");
                break;

            case 3: // Excluir aluno
                printf("\nMatr�cula do aluno para excluir: ");
                scanf("%d", &matricula);
                x = removeOrdenado(li, matricula);
                if(x){
                    printf("\nAluno %d removido ordenadamente com sucesso!", x);
                }else{
                    printf("\nN�o foi poss�vel remover do final.");
                }
                printf("\n\n");
                system("PAUSE");
                system("cls");
                break;

            case 4: // Encerrar programa
                apagaLista(li);
                printf("\nPROGRAMA ENCERRADO\n\n");
                break;

            case 5: // Case para teste. Buscar todos os alunos
                printf("\nConsultando todos os alunos da lista...");
                for(int i = 0; i < tamanhoLista(li); i++){
                    printf("\n\nALUNO %02d:", i + 1);
                    x = consultaPosicao(li, i + 1, &al_consulta);
                    if(x){
                        printf("\nConsulta por posicao realizada com sucesso!");
                        printf("\nMatricula: %d", al_consulta.matricula);
                        printf("\nNota 1: %.2f", al_consulta.n1);
                        printf("\nNota 2: %.2f", al_consulta.n2);
                        printf("\nNota 3: %.2f", al_consulta.n3);
                    }else{
                        printf("\nNao foi possivel consulta na posicao especifica!");
                    }
                }
                if(tamanhoLista(li) == 0)
                    printf("\nLista est� vazia.");
                printf("\n\n");
                system("PAUSE");
                system("cls");
                break;

            default:
                printf("\nEntrada inv�lida!");
                printf("\n\n");
                system("PAUSE");
                system("cls");
                break;
        }
    }while(entrada != 4);

    system("PAUSE");
    return 0;
}
/*
int main()
{
    // Ponteiro para ponteiro. Parte est� no arquivo
    // listaLigada.h
    Lista *li = NULL;
    // C�digo de erro. x receber� o c�digo de erro como
    // retorno das fun��es membro do Tipo Abstrato.
    int x;
    // Para as buscas
    //matricula ser� usada na busca por um elemento espec�fico
    // posicao ser� usado na busca por um elemento em uma
    // determinada posicao
    int matricula = 120, posicao = 2;
    // Para popular a lista e al para consulta
    // al_consulta - estrura aluno ficar� vazia e ser� utilizada
    // para retorno de informa��es das buscas na lista
    ALUNO al_consulta, al1, al2, al3;

    // al1 ser� usado na inser��o no in�cio
    al1.matricula = 110;
    al1.n1 = 5.6;
    al1.n2 = 6.3;
    al1.n3 = 7.9;

    // al2 ser� usado na inser��o no final
    al2.matricula = 130;
    al2.n1 = 9.2;
    al2.n2 = 3.5;
    al2.n3 = 8.1;

    // a3 ser� usado na inser��o ordenada
    al3.matricula = 120;
    al3.n1 = 6.6;
    al3.n2 = 2.1;
    al3.n3 = 9.2;

    setlocale(LC_ALL, "");
    printf("Atividade 1 - Lista Sequencial Din�mica\n");

    if((li = criaLista()) == NULL) {
        //Se n�o poss�vel alocar o bloco de mem�ria, o programa
        // ser� ent�o abortado
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

    x = removeInicio(li);
    if(x){
        printf("\nAluno %d removido do in�cio com sucesso!", x);
    }else{
        printf("\nN�o foi poss�vel remover do in�cio.");
    }

    x = removeFinal(li);
    if(x){
        printf("\nAluno %d removido do final com sucesso!", x);
    }else{
        printf("\nN�o foi poss�vel remover do final.");
    }

    x = removeOrdenado(li, matricula);
    if(x){
        printf("\nAluno %d removido ordenadamente com sucesso!", x);
    }else{
        printf("\nN�o foi poss�vel remover do final.");
    }

    x = consultaPosicao(li, posicao, &al_consulta);
    if(x){
        printf("\n\nConsulta na posi��o %d", posicao);
        printf("\nMatr�cula:  %d", al_consulta.matricula);
        printf("\nNota 1:     %.2f", al_consulta.n1);
        printf("\nNota 2:     %.2f", al_consulta.n2);
        printf("\nNota 3:     %.2f", al_consulta.n3);
    }else{
        printf("\nPosi��o %d n�o existe", posicao);
    }

    x = consultaMatricula(li, matricula, &al_consulta);
    if(x){
        printf("\n\nConsulta aluno de matricula %d", matricula);
        printf("\nMatr�cula:  %d", al_consulta.matricula);
        printf("\nNota 1:     %.2f", al_consulta.n1);
        printf("\nNota 2:     %.2f", al_consulta.n2);
        printf("\nNota 3:     %.2f", al_consulta.n3);
    }else{
        printf("\nMatricula %d n�o encontrada", matricula);
    }

    apagaLista(li);

    printf("\n\n");
    system("PAUSE");
    return 0;
}
*/
