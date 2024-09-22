/*
� Escreva um programa que implemente os dois m�dulos apresentados ao abaixo (c�lculo de vantagens
  e dedu��es). As vari�veis a serem utilizadas nos m�dulos, devem ser globais obrigatoriamente
  (somente as que recebem atribui��es dentro dos m�dulos);
� O programa deve recolher os dados do usu�rio, armazen�-los nas vari�veis locais correspondentes no
  main(), e, em seguida passar os dados aos m�dulos, para que estes executem os c�lculos;
� Imprima na tela os resultados obtidos pelos m�dulos. A rotina de impress�o deve ficar fora dos
  m�dulos de c�lculo, ou seja deve ficar no main(). Entregue no Moodle como Atividade 1.

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
#include<stdio.h>
#include<stdlib.h>
// Declara��o das vari�veis globais
float vantagens, salarioBruto, salarioFamilia, deducoes, INSS, IRPF;
void calcVantagens(int numeroHoras, float salarioHora, int numeroFilhos, float valorPorFilho);
void calcDeducoes(float taxaIR);

int main() {
    // Declara��o das vari�veis locais
    float numeroHoras, salarioHora, valorPorFilho, taxaIR;
    int numeroFilhos;

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
    calcVantagens(numeroHoras, salarioHora, numeroFilhos, valorPorFilho);
    calcDeducoes(taxaIR);
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


