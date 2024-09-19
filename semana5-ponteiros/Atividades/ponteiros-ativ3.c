/*
� Crie um programa que contenha um vetor de float contendo dez elementos. Imprima na
  tela o endere�o de cada posi��o desse vetor. Depois fa�a o mesmo com um vetor do tipo
  double de mesmo tamanho.
� Exemplo:
� Posi��o 0: 0x....
� Posi��o 1: 0x....
� Posi��o 2: 0x....
� E assim por diante.
� Entregue no Moodle como atividade 3
*/
#include <stdio.h>
#include <stdlib.h>

int main() {
    // Declara��o dos vetores, vari�veis e ponteiros
    float vfloat[10], *pvfloat;
    double vdouble[10], *pvdouble;
    int i;

    printf("Atividade 3 - Ponteiros\n\n");

    // Inicializando os ponteiros com o endere�o inicial dos vetores
    pvfloat = vfloat;
    pvdouble = vdouble;

    // Leitura dos endere�os do vetor float
    printf("Enderecos do vetor float:\n");
    for(i = 0; i < 10; i++) {
        printf("Posicao [%d] = %p\n", i, pvfloat);
        pvfloat++;
    }

    // Leitura dos endere�os do vetor double
    printf("\nEnderecos do vetor double:\n");
    for(i = 0; i < 10; i++) {
        printf("Posicao [%d] = %p\n", i, pvdouble);
        pvdouble++;
    }
    printf("\n\n");

    system("pause");
    return 0;
}
