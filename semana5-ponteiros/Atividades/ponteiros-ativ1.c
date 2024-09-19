/*
        Atividade 1
• Elabore um programa com 3 variáveis do tipo int e 3 ponteiros para o tipo int;
• Receba via teclado os valores de cada variável do tipo int;
• Faça com que os ponteiros apontem para as variáveis recebidas;
• Modifique os valores contidos nos endereços variáveis recebidas através dos ponteiros,
  somando 100 ao seu valor inicial. Faça isso passando os ponteiros como argumento para a
  função que será do tipo void;
• Imprima os valores finais de cada variável;
• Entregue no Moodle como atividade 1.
*/
#include <stdio.h>
#include <stdlib.h>

void somap(int *pa, int *pb, int *pc);

int main() {
    // Declaração das variáveis e ponteiros
    int a, b, c, *pa, *pb, *pc;

    // Receber os valores para cada variável
    printf("Atividade 1 - Ponteiros\n\n");
    printf("Digite valor para a variavel A: ");
    scanf("%d", &a);
    printf("Digite valor para a variavel B: ");
    scanf("%d", &b);
    printf("Digite valor para a variavel C: ");
    scanf("%d", &c);

    //Inicializando os ponteiros com o endereço das variavéis
    pa = &a;
    pb = &b;
    pc = &c;

    // Função que soma 100 aos valores iniciais de cada ponteiro
    somap(pa, pb, pc);

    // Imprime os valores finais de cada variável
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
