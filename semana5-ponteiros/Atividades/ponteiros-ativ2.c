/*
• Escreva um programa que contenha duas variáveis inteiras. Leia essas variáveis do teclado.
  Em seguida, compare seus endereços e exiba o maior endereço e o conteúdo da variável que
  este endereço aponta.
• Exemplo:
• Endereço da variável xyz: 0x....
• Conteúdo da variável xyz: xxx...
• Entregue no Moodle como atividade 2
*/
#include <stdio.h>
#include <stdlib.h>

int main() {
    // Declaração das variáveis e ponteiros
    int a, b, *pa, *pb;

    // Receber os valores para cada variável
    printf("Atividade 2 - Ponteiros\n\n");
    printf("Digite valor para a variavel A: ");
    scanf("%d", &a);
    printf("Digite valor para a variavel B: ");
    scanf("%d", &b);

    //Inicializando os ponteiros com o endereço das variavéis
    pa = &a;
    pb = &b;

    // Comparação dos endereços dos ponteiros e apresentação de seu endereço e valor
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
