/*
        Atividade 1
� Elabore um programa com 3 vari�veis do tipo int e 3 ponteiros para o tipo int;
� Receba via teclado os valores de cada vari�vel do tipo int;
� Fa�a com que os ponteiros apontem para as vari�veis recebidas;
� Modifique os valores contidos nos endere�os vari�veis recebidas atrav�s dos ponteiros,
  somando 100 ao seu valor inicial. Fa�a isso passando os ponteiros como argumento para a
  fun��o que ser� do tipo void;
� Imprima os valores finais de cada vari�vel;
� Entregue no Moodle como atividade 1.
*/
#include <stdio.h>
#include <stdlib.h>

void somap(int *pa, int *pb, int *pc);

int main() {
    // Declara��o das vari�veis e ponteiros
    int a, b, c, *pa, *pb, *pc;

    // Receber os valores para cada vari�vel
    printf("Atividade 1 - Ponteiros\n\n");
    printf("Digite valor para a variavel A: ");
    scanf("%d", &a);
    printf("Digite valor para a variavel B: ");
    scanf("%d", &b);
    printf("Digite valor para a variavel C: ");
    scanf("%d", &c);

    //Inicializando os ponteiros com o endere�o das variav�is
    pa = &a;
    pb = &b;
    pc = &c;

    // Fun��o que soma 100 aos valores iniciais de cada ponteiro
    somap(pa, pb, pc);

    // Imprime os valores finais de cada vari�vel
    printf("\nValores Finais:\n");
    printf("Variavel A = %d\n", a);
    printf("Variavel B = %d\n", b);
    printf("Variavel C = %d\n", c);
    printf("\n\n");

    system("pause");
    return 0;
}

void somap(int *pa, int *pb, int *pc) {
    *pa += 100;
    *pb += 100;
    *pc += 100;
}
