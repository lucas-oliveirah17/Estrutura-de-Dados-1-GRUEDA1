/*
Monte o programa com todas as funções apresentadas pertencente à lista ligada.
• Implemente nesta lista a mesma função coletadados(), do exercício lista estática, e
 descarte as inserções via código (as 3 inserções de teste).
• Crie um menu que funcione ininterruptamente com 4 opções:
• Incluir um elemento de forma ordenada utilizando a função coletadados();
• Buscar um elemento por conteúdo (matrícula);
• Excluir um elemento de forma ordenada, e;
• Encerrar o programa.
*/
// Arquivo main()
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "listaLigada.h"

int main(){
    Lista *li = NULL;
    int x; // Para código de erro
    int entrada = 0; // Para receber a entrada do usuário
    int matricula = 120, posicao = 2; // Para testes de busca

    ALUNO al_consulta;
    ALUNO al1, al2, al3; //

    // al1 será usado na inserção no início
    al1.matricula = 110;
    al1.n1 = 5.6;
    al1.n2 = 6.3;
    al1.n3 = 7.9;

    // al2 será usado na inserção no final
    al2.matricula = 130;
    al2.n1 = 9.2;
    al2.n2 = 3.5;
    al2.n3 = 8.1;

    // a3 será usado na inserção ordenada
    al3.matricula = 120;
    al3.n1 = 6.6;
    al3.n2 = 2.1;
    al3.n3 = 9.2;

    setlocale(LC_ALL, "");
    printf("Atividade 1 - Lista Sequencial Dinâmica");

    printf("\n\n\tTESTES\n");

    // Cria Lista
    if((li = criaLista()) == NULL) {
        //Se não possível alocar o bloco de memória, o programa
        // será então abortado
        abortaPrograma();
    }
    // Verifica tamanho da lista
    x = tamanhoLista(li);
    printf("\nO tamanho da lista é: %d", x);

    // Verifica se lista está cheia
    if(listaCheia(li)){
        printf("\nLista está cheia!");
    }else{
        printf("\nLista não está cheia.");
    }

    // Verifica se lista está vazia
    if(listaVazia(li)){
        printf("\nLista está vazia.");
    }else{
        printf("\nLista não está vazia.");
    }

    // Insere aluno 110 no inicio da lista
    x = insereInicio(li, al1);
    if(x){
        printf("\nAluno %d inserido no inicio com sucesso!", x);
    }else{
        printf("\nNão foi possível inserir no inicio.");
    }

    // Verifica se lista está vazia
    if(listaVazia(li)){
        printf("\nLista está vazia.");
    }else{
        printf("\nLista não está vazia.");
    }

    // Insere aluno 130 no final da lista
    x = insereFinal(li, al2);
    if(x){
        printf("\nAluno %d inserido no final com sucesso!", x);
    }else{
        printf("\nNão foi possível inserir no final.");
    }

    // Insere aluno 120 ordenadamente na lista
    x = insereOrdenado(li, al3);
    if(x){
        printf("\nAluno %d inserido ordenadamente com sucesso!", x);
    }else{
        printf("\nNão foi possível inserir ordenadamente.");
    }

    // Verifica tamanho da lista
    x = tamanhoLista(li);
    printf("\n\nO tamanho da lista é: %d", x);

    // Consulta aluno na posição 2
    x = consultaPosicao(li, posicao, &al_consulta);
    if(x){
        printf("\n\nConsulta na posição %d", posicao);
        printf("\nMatrícula:  %d", al_consulta.matricula);
        printf("\nNota 1:     %.2f", al_consulta.n1);
        printf("\nNota 2:     %.2f", al_consulta.n2);
        printf("\nNota 3:     %.2f", al_consulta.n3);
    }else{
        printf("\n\nPosição %d não existe", posicao);
    }

    // Consulta aluno na posição 4
    x = consultaPosicao(li, 4, &al_consulta);
    if(x){
        printf("\n\nConsulta na posição %d", posicao);
        printf("\nMatrícula:  %d", al_consulta.matricula);
        printf("\nNota 1:     %.2f", al_consulta.n1);
        printf("\nNota 2:     %.2f", al_consulta.n2);
        printf("\nNota 3:     %.2f", al_consulta.n3);
    }else{
        printf("\n\nPosição %d não existe", 4);
    }

    // Consulta aluno com matrícula 120
    x = consultaMatricula(li, matricula, &al_consulta);
    if(x){
        printf("\n\nConsulta aluno de matricula %d", matricula);
        printf("\nMatrícula:  %d", al_consulta.matricula);
        printf("\nNota 1:     %.2f", al_consulta.n1);
        printf("\nNota 2:     %.2f", al_consulta.n2);
        printf("\nNota 3:     %.2f", al_consulta.n3);
    }else{
        printf("\n\nMatricula %d não encontrada", matricula);
    }

    // Remove ordenadamente aluno de matricula 120
    x = removeOrdenado(li, matricula);
    if(x){
        printf("\n\nAluno %d removido ordenadamente com sucesso!", x);
    }else{
        printf("\n\nNão foi possível remover do final.");
    }

    // Consulta aluno com matrícula 120
    x = consultaMatricula(li, matricula, &al_consulta);
    if(x){
        printf("\n\nConsulta aluno de matricula %d", matricula);
        printf("\nMatrícula:  %d", al_consulta.matricula);
        printf("\nNota 1:     %.2f", al_consulta.n1);
        printf("\nNota 2:     %.2f", al_consulta.n2);
        printf("\nNota 3:     %.2f", al_consulta.n3);
    }else{
        printf("\n\nMatricula %d não encontrada", matricula);
    }

    // Consulta aluno na posição 2
    x = consultaPosicao(li, posicao, &al_consulta);
    if(x){
        printf("\n\nConsulta na posição %d", posicao);
        printf("\nMatrícula:  %d", al_consulta.matricula);
        printf("\nNota 1:     %.2f", al_consulta.n1);
        printf("\nNota 2:     %.2f", al_consulta.n2);
        printf("\nNota 3:     %.2f", al_consulta.n3);
    }else{
        printf("\n\nPosição %d não existe", posicao);
    }

    // Consulta aluno na posição 2
    x = consultaPosicao(li, 3, &al_consulta);
    if(x){
        printf("\n\nConsulta na posição %d", posicao);
        printf("\nMatrícula:  %d", al_consulta.matricula);
        printf("\nNota 1:     %.2f", al_consulta.n1);
        printf("\nNota 2:     %.2f", al_consulta.n2);
        printf("\nNota 3:     %.2f", al_consulta.n3);
    }else{
        printf("\n\nPosição %d não existe", 3);
    }

    // Remover aluno do final da lista
    x = removeFinal(li);
    if(x){
        printf("\nAluno %d removido do final com sucesso!", x);
    }else{
        printf("\nNão foi possível remover do final.");
    }

    // Remover aluno do início da lista
    x = removeInicio(li);
    if(x){
        printf("\nAluno %d removido do início com sucesso!", x);
    }else{
        printf("\nNão foi possível remover do início.");
    }

    printf("\n\n");
    system("PAUSE");
    system("cls");

    do{
        printf("\tMENU");
        printf("\n[1] - Adicionar aluno");
        printf("\n[2] - Buscar aluno (Matrícula)");
        printf("\n[3] - Excluir aluno");
        printf("\n[4] - Encerrar o programa.\n");
        printf("\n[5] - Buscar todos os alunos.\n"); // Opção para teste
        printf("\nEntrada: ");
        scanf("%d", &entrada);

        switch(entrada){
            case 1: // Adicionar Aluno
                printf("\n\nAdicionando novo aluno a lista...");
                x = insereOrdenado(li, coletar_dados_aluno());
                if(x){
                printf("Aluno cadastrado com sucesso!");
                }else{
                    printf("Erro! Aluno não cadastrado!");
                }
                printf("\n\n");
                system("PAUSE");
                system("cls");
                break;

            case 2: // Buscar aluno (Matrícula)
                printf("\nMatrícula do aluno para buscar: ");
                scanf("%d", &matricula);
                x = consultaMatricula(li, matricula, &al_consulta);
                if(x){
                    printf("\n\nConsulta aluno de matricula %d", matricula);
                    printf("\nMatrícula:  %d", al_consulta.matricula);
                    printf("\nNota 1:     %.2f", al_consulta.n1);
                    printf("\nNota 2:     %.2f", al_consulta.n2);
                    printf("\nNota 3:     %.2f", al_consulta.n3);
                }else{
                    printf("\n\nMatricula %d não encontrada", matricula);
                }
                printf("\n\n");
                system("PAUSE");
                system("cls");
                break;

            case 3: // Excluir aluno
                printf("\nMatrícula do aluno para excluir: ");
                scanf("%d", &matricula);
                x = removeOrdenado(li, matricula);
                if(x){
                    printf("\nAluno %d removido ordenadamente com sucesso!", x);
                }else{
                    printf("\nNão foi possível remover do final.");
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
                    printf("\nLista está vazia.");
                printf("\n\n");
                system("PAUSE");
                system("cls");
                break;

            default:
                printf("\nEntrada inválida!");
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
    // Ponteiro para ponteiro. Parte está no arquivo
    // listaLigada.h
    Lista *li = NULL;
    // Código de erro. x receberá o código de erro como
    // retorno das funções membro do Tipo Abstrato.
    int x;
    // Para as buscas
    //matricula será usada na busca por um elemento específico
    // posicao será usado na busca por um elemento em uma
    // determinada posicao
    int matricula = 120, posicao = 2;
    // Para popular a lista e al para consulta
    // al_consulta - estrura aluno ficará vazia e será utilizada
    // para retorno de informações das buscas na lista
    ALUNO al_consulta, al1, al2, al3;

    // al1 será usado na inserção no início
    al1.matricula = 110;
    al1.n1 = 5.6;
    al1.n2 = 6.3;
    al1.n3 = 7.9;

    // al2 será usado na inserção no final
    al2.matricula = 130;
    al2.n1 = 9.2;
    al2.n2 = 3.5;
    al2.n3 = 8.1;

    // a3 será usado na inserção ordenada
    al3.matricula = 120;
    al3.n1 = 6.6;
    al3.n2 = 2.1;
    al3.n3 = 9.2;

    setlocale(LC_ALL, "");
    printf("Atividade 1 - Lista Sequencial Dinâmica\n");

    if((li = criaLista()) == NULL) {
        //Se não possível alocar o bloco de memória, o programa
        // será então abortado
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

    x = removeInicio(li);
    if(x){
        printf("\nAluno %d removido do início com sucesso!", x);
    }else{
        printf("\nNão foi possível remover do início.");
    }

    x = removeFinal(li);
    if(x){
        printf("\nAluno %d removido do final com sucesso!", x);
    }else{
        printf("\nNão foi possível remover do final.");
    }

    x = removeOrdenado(li, matricula);
    if(x){
        printf("\nAluno %d removido ordenadamente com sucesso!", x);
    }else{
        printf("\nNão foi possível remover do final.");
    }

    x = consultaPosicao(li, posicao, &al_consulta);
    if(x){
        printf("\n\nConsulta na posição %d", posicao);
        printf("\nMatrícula:  %d", al_consulta.matricula);
        printf("\nNota 1:     %.2f", al_consulta.n1);
        printf("\nNota 2:     %.2f", al_consulta.n2);
        printf("\nNota 3:     %.2f", al_consulta.n3);
    }else{
        printf("\nPosição %d não existe", posicao);
    }

    x = consultaMatricula(li, matricula, &al_consulta);
    if(x){
        printf("\n\nConsulta aluno de matricula %d", matricula);
        printf("\nMatrícula:  %d", al_consulta.matricula);
        printf("\nNota 1:     %.2f", al_consulta.n1);
        printf("\nNota 2:     %.2f", al_consulta.n2);
        printf("\nNota 3:     %.2f", al_consulta.n3);
    }else{
        printf("\nMatricula %d não encontrada", matricula);
    }

    apagaLista(li);

    printf("\n\n");
    system("PAUSE");
    return 0;
}
*/
