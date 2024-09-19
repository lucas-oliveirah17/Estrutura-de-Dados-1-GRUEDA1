/*
� Escreva um programa que contenha duas vari�veis inteiras. Leia essas vari�veis do teclado.
  Em seguida, compare seus endere�os e exiba o maior endere�o e o conte�do da vari�vel que
  este endere�o aponta.
� Exemplo:
� Endere�o da vari�vel xyz: 0x....
� Conte�do da vari�vel xyz: xxx...
� Entregue no Moodle como atividade 2
*/
#include <stdio.h>
#include <stdlib.h>

int main() {
    // Declara��o das vari�veis e ponteiros
    int a, b, *pa, *pb;

    // Receber os valores para cada vari�vel
    printf("Atividade 2 - Ponteiros\n\n");
    printf("Digite valor para a variavel A: ");
    scanf("%d", &a);
    printf("Digite valor para a variavel B: ");
    scanf("%d", &b);

    //Inicializando os ponteiros com o endere�o das variav�is
    pa = &a;
    pb = &b;

    // Compara��o dos endere�os dos ponteiros e apresenta��o de seu endere�o e valor
    if(pb < pa) {
        printf("\nEndereco da variavel A e maior.\n");
        printf("Endereco da variavel A = %p\n", pa );
        printf("Conteudo da variavel A = %d\n", *pa);
    }
    else {
        printf("\nEndereco da Variavel B e maior.\n");
        printf("Endereco da variavel B = %p\n", pb);
        printf("Conteudo da variavel B = %d\n", *pb);
    }
    printf("\n\n");

    system("pause");
    return 0;
}
