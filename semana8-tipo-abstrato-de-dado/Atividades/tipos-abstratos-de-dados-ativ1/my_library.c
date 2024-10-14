#include "my_library.h"
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
