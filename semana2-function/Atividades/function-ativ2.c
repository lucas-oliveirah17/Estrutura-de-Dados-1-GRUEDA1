/*
• O objetivo agora é substituir variáveis globais por ponteiros.
• Reescreva o programa da atividade 1, e agora não utilize mais variáveis globais, utilize
  somente variáveis locais e a passagem por referência nos dois módulos. Todas as variáveis
  devem ser declaradas dentro do main(), e somente as variáveis que receberão valores dentro
  das funções (que receberão atribuições, ou seja, o resultado dos cálculos), deverão ter seus
  endereços passados por referência. As demais variáveis que só entregam valores para cálculo,
  devem ter sua passagem de forma normal, ou seja, por cópia.
• Entregue no Moodle com atividade 2.

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
#include <stdio.h>
#include <stdlib.h>
// Declaração das variáveis globais
void calcVantagens(int numeroHoras, float salarioHora, int numeroFilhos, float valorPorFilho, float *salarioBruto, float*salarioFamilia, float *vantagens);
void calcDeducoes(float salarioBruto, float taxaIR, float *INSS, float *IPRF, float *deducoes);

int main() {
    // Declaração das variáveis locais para recebimento de dados
    float numeroHoras, salarioHora, valorPorFilho, taxaIR;
    int numeroFilhos;
    // Declaração das variáveis que receberão os resultados
    float salarioBruto, salarioFamilia, vantagens, INSS, IRPF, deducoes;

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
    calcVantagens(numeroHoras, salarioHora, numeroFilhos, valorPorFilho, &salarioBruto, &salarioFamilia, &vantagens);
    calcDeducoes(salarioBruto, taxaIR, &INSS, &IRPF, &deducoes);
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

void calcVantagens(int numeroHoras, float salarioHora, int numeroFilhos, float valorPorFilho, float *salarioBruto, float*salarioFamilia, float *vantagens) {
    *salarioBruto = numeroHoras * salarioHora;
    *salarioFamilia = numeroFilhos * valorPorFilho;
    *vantagens = *salarioBruto + *salarioFamilia;

}

void calcDeducoes(float salarioBruto, float taxaIR, float *INSS, float *IRPF, float *deducoes) {
    *INSS = salarioBruto * 0.08;
    *IRPF = salarioBruto * taxaIR;
    *deducoes = *INSS + *IRPF;
}
