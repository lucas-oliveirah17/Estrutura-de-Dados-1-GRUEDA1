/*
� O objetivo agora � substituir vari�veis globais por ponteiros.
� Reescreva o programa da atividade 1, e agora n�o utilize mais vari�veis globais, utilize
  somente vari�veis locais e a passagem por refer�ncia nos dois m�dulos. Todas as vari�veis
  devem ser declaradas dentro do main(), e somente as vari�veis que receber�o valores dentro
  das fun��es (que receber�o atribui��es, ou seja, o resultado dos c�lculos), dever�o ter seus
  endere�os passados por refer�ncia. As demais vari�veis que s� entregam valores para c�lculo,
  devem ter sua passagem de forma normal, ou seja, por c�pia.
� Entregue no Moodle com atividade 2.

  M�dulo calculaVantagens(par�metros para c�lculo)
        salarioBruto = numeroHoras * salarioHora;
        salarioFamilia = numeroFilhos * valorPorFilho;
        vantagens = salarioBruto + salarioFamilia;
  fim c�lculoVantagens

  M�dulo calculoDedu��es(par�mentros para c�lculo)
        INSS = salarioBruto * 0,08;
        IRPF = salarioBruto * taxaIR;
        Dedu��es = INSS + IPRF;
  fim calculoDedu��es
*/
#include <stdio.h>
#include <stdlib.h>
// Declara��o das vari�veis globais
void calcVantagens(int numeroHoras, float salarioHora, int numeroFilhos, float valorPorFilho, float *salarioBruto, float*salarioFamilia, float *vantagens);
void calcDeducoes(float salarioBruto, float taxaIR, float *INSS, float *IPRF, float *deducoes);

int main() {
    // Declara��o das vari�veis locais para recebimento de dados
    float numeroHoras, salarioHora, valorPorFilho, taxaIR;
    int numeroFilhos;
    // Declara��o das vari�veis que receber�o os resultados
    float salarioBruto, salarioFamilia, vantagens, INSS, IRPF, deducoes;

    printf("Atividade 1 - Programa��o Estrutura ou Modular\n\n");
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
    // Chamada de fun��es
    calcVantagens(numeroHoras, salarioHora, numeroFilhos, valorPorFilho, &salarioBruto, &salarioFamilia, &vantagens);
    calcDeducoes(salarioBruto, taxaIR, &INSS, &IRPF, &deducoes);
    // Impress�o dos resultados
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
