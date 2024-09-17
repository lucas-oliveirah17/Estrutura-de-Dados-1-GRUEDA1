#include <stdio.h>
#include <stdlib.h>

int main()
{
    printf("Atividade 1 - Programa Pg. 27\n");
    int j = 5;

    if (j == 5){
        j++;
        goto imprime;
    }

    j = 1350; //esta atribuição será ignorada

    imprime:
        printf("Valor de j: %d", j);

    printf("\n\n");
    system("pause");
    return 0;
}
