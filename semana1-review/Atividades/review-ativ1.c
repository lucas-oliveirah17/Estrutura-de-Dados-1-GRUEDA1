/*
• Codifique os exemplos apresentados do slides 16 ao 27, e verifique o funcionamento de todos e faça
  experimentos com valores diferentes onde for possível.
• Entregue somente os arquivos de código fonte (.c) compactados (zipados), na plataforma Moodle,
como atividade 1.
*/
#include <stdio.h>
#include <stdlib.h>

int main() {
    // Declaração das variáveis
    int a, b, i, j = 5;
    char escolha, letra ='A';
    // Codigo pagina 16 - pg.19: if else
    printf("Atividade 1 - Review\n\n");
    printf ("Codigo pg16 - pg.19: if e else \n\n");
    printf("Informe dois numeros: \n");
    scanf(" %d %d", &a, &b);
    if(a == b) {
        printf("Os numeros sao iguais \n\n\n");
    }
    else {
        if(a > b) {
            printf("O primeiro e maior \n\n\n");
        }
        else {
            printf("O segundo e maior \n\n\n");
        }

    }

    // Codigo pagina 20: operador ternário - ?
    a = 0, b = 0; // Limpando variáveis
    printf("Codigo pg20: operador ternário - ? \n\n");
    printf("Informe um numero: \n");
    scanf(" %d", &a);
    b = (a > 12) ? 100 : 200;
    printf("Valor de b: %d \n\n\n", b);

    // Codigo pagina 21: switch case
    printf("Codigo pg21: switch case \n\n");
    printf("Quer continuar? [sim -s / nao - n]: \n");
    scanf(" %c", &escolha);
    switch(escolha) {
    case 's':
        printf("Voce quer continuar");
        break;
    case 'n':
        printf("Voce quer parar");
        break;
    default:
        printf("Escolha invalida!");
        break;
    }
    printf("\n\n\n");

    // Codigo pagina 22: for
    printf("Codigo pg22: for \n\n");
    for(i = 0; i < 26; i++) {
        printf(" %c", letra);
        letra++;
    }
    printf("\n\n\n");

    // Codigo pagina 23: while
    i = 0; // Limpando variável
    printf("Codigo pg23: while \n\n");
    while(i <= 10) {
        printf("Valor de i: %d \n", i);
        i++;
    }
    printf("\n\n\n");

    // Codigo pagina 24: do/while
    printf("Codigo pg24: do/while \n\n");
    i = 395;
    do {
        printf("Valor de i: %d \n", i);
        i++;
    } while(i <= 10);
    printf("\n\n\n");

    // Codigo pagina 25: continue
    printf("Codigo pg25: continue \n\n");
    for(i = 0; i < 10; i++) {
        if(i == 5) {
            printf("\n\n\t\t captura de i em: %d \n\n", i);
            continue;
            printf("Observe que esta msg não será impressa!!");
        }
        printf("Valor de i: %d \n", i);
    }
    printf("\n\n\n");

    // Codigo pagina 26: break
    printf("Codigo pg26: break \n\n");
    for(i = 0; i < 10; i++) {
        if(i == 5) {
            printf("\n\n\t\t captura de i em: %d \n\n", i);
            break;
            printf("Observe que esta msg não será impressa!!");
        }
        printf("Valor de i: %d \n", i);
    }
    printf("\n\n\n");

    // Codigo pagina 27: goto
    printf("Codigo pg27: goto \n\n");
    if(j == 5) {
        j++;
        goto imprime;
    }
    j = 1350; //esta atribuição será ignorada
    imprime:
        printf("Valor de j: %d", j);
    printf("\n\n\n");

    system ("pause");
    return 0;
}
