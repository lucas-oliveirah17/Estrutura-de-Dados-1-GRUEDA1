/*
• Escreva um programa que implemente os dois módulos apresentados ao abaixo (cálculo de vantagens
  e deduções). As variáveis a serem utilizadas nos módulos, devem ser globais obrigatoriamente
  (somente as que recebem atribuições dentro dos módulos);
• O programa deve recolher os dados do usuário, armazená-los nas variáveis locais correspondentes no
  main(), e, em seguida passar os dados aos módulos, para que estes executem os cálculos;
• Imprima na tela os resultados obtidos pelos módulos. A rotina de impressão deve ficar fora dos
  módulos de cálculo, ou seja deve ficar no main(). Entregue no Moodle como Atividade 1.

  Módulo calculaVantagens(parâmetros para cálculo)
        salarioBruto = numeroHoras * salarioHora;
        salarioFamilia = numeroFilhos * valorPorFilho;
        vantagens = salarioBruto + salarioFamilia;
  fim cálculoVantagens

  Módulo calculoDeduções(parâmentros para cálculo)
        INSS = salarioBruto * 0,08;
        IRPF = salarioBruto * taxaIR;
        Deduções = INSS + IPRF;
  fim calculoDeduções
*/
#include<stdio.h>
#include<stdlib.h>
// Declaração das variáveis globais
float vantagens, salarioBruto, salarioFamilia, deducoes, INSS, IRPF;
void calcVantagens(int numeroHoras, float salarioHora, int numeroFilhos, float valorPorFilho);
void calcDeducoes(float taxaIR);

int main() {
    // Declaração das variáveis locais
    float numeroHoras, salarioHora, valorPorFilho, taxaIR;
    int numeroFilhos;

    printf("Atividade 1 - Programação Estrutura ou Modular\n\n");
    // Coleta de dados
    printf("Numero de horas trabalhada: ");
    scanf(" %f", &numeroHoras);
    printf("Salario hora: ");
    scanf(" %f", &salarioHora);
    printf("Numero de filhos: ");
    scanf(" %d", &numeroFilhos);
    printf("Valor por filho: ");
    scanf(" %f", &valorPorFilho);
    printf("Taxa do IR: ");
    scanf(" %f", &taxaIR);
    printf("\n\n");
    // Chamada de funções
    calcVantagens(numeroHoras, salarioHora, numeroFilhos, valorPorFilho);
    calcDeducoes(taxaIR);
    // Impressão dos resultados
    printf("Resultados:\n");
    printf("Salario Bruto = R$%.2f\n", salarioBruto);
    printf("Salario Familia = R$%.2f\n", salarioFamilia);
    printf("Vantagens = R$%.2f\n", vantagens);
    printf("INSS = R$%.2f\n", INSS);
    printf("IRPF = R$%.2f\n", IRPF);
    printf("Deducoes = R$%.2f\n", deducoes);

    printf("\n\n");
    system("pause");
    return 0;
}

void calcVantagens(int numeroHoras, float salarioHora, int numeroFilhos, float valorPorFilho) {
    salarioBruto = numeroHoras * salarioHora;
    salarioFamilia = numeroFilhos * valorPorFilho;
    vantagens = salarioBruto + salarioFamilia;

}

void calcDeducoes(float taxaIR) {
    INSS = salarioBruto * 0.08;
    IRPF = salarioBruto * taxaIR;
    deducoes = INSS + IRPF;
}


