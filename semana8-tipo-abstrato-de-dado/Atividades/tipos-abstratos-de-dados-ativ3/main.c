#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "calculator.h"

int main()
{
    double in1, in2;
    char option;
    calcOUT *calc = createCalcOUT(); // Aloca a memória;

    setlocale(LC_ALL, "");
    printf("Atividade 3 - Tipo Abstrato de Dado\n\n");


    if (calc == NULL) {
        printf("ERRO ao alocar memória.\n");
        return 1;
    }
    printf("########## CALCULADORA ##########\n");
    do {

        printf("-------------- MENU ---------------\n");
        printf("[+] Soma           | [-] Subtração\n");
        printf("[*] Multiplicação  | [/] Divisão\n");
        printf("[V] Valor Anterior | [S] Sair\n");
        printf("-----------------------------------\n");
        printf("Operacao: ");
        scanf(" %c", &option);
        if (option == '+' || option == '-' || option == '*' || option == '/') {
                printf("Valor 1: ");
                scanf(" %lf", &in1);
                printf("Valor 2: ");
                getchar();
                scanf(" %lf", &in2);
            printf("Resultado = %.2lf\n\n\n", calculate(calc, in1, in2, option));
        }
        else if (option == 'V' || option == 'v') {
            printf("Valor Anterior = %.2lf\n\n\n", last_result(calc));
        }
    } while(option != 'S' && option != 's');
    freeCalcOUT(calc); // Libera a memória
    printf("Programa encerrado!\n\n\n");
    system("PAUSE");
    return 0;
}
