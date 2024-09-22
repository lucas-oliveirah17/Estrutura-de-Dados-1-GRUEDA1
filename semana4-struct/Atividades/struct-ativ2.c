/*
• Modifique o programa da Atividade 1 para que o registro se torne um “tipo” e dessa forma ser
  possível a declaração direta do registro, para isso utilize o comando typedef;
• Crie duas funções.
• A primeira para coletar os dados fornecidos via teclado, que não receberá parâmetro algum, mas
  retornará uma estrutura completa e preenchida, ou seja, retornará um FUNCIONARIO;
• E a segunda, que gerará as impressões na tela. Esta deve receber o vetor[] e a quantidade de elementos
  desse vetor;
• Crie um procedimento (função void que não retorna valor), onde o salário do funcionário sofrerá um
  reajuste de 10%. Nesta função, somente o campo salário da estrutura funcionário deverá ser passado
  como parâmetro, e terá obrigatoriamente que ser por referência, utilizando-se o endereço do campo
  (ponteiro) – ver slide 19, funções 3 e 4 como exemplo.
• Gere uma impressão em tela onde será exibido somente o nome do funcionário e o novo valor de
  salário, a rotina de impressão deverá ficar em outra função chamada rel_salario_corrigido();
• Entregue no Moodle como Atividade 2.
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int id;
    char nome[30];
    int idade;
    float salario;
}FUNCIONARIO;

FUNCIONARIO coletaDados();
void imprimaFuncionarios(FUNCIONARIO f[], int quantidade);
void reajustaSalario(float *salario);
void rel_salario_corrigido(FUNCIONARIO f[], int quantidade);

int main() {
    FUNCIONARIO f[5];
    int i;
    printf("Atividade 1 - Estruturas Heterogeneas - Structs\n\n");
    // Coleta de dados
    for(i = 0; i < 5; i++) {
        printf("Dados Funcionario %d\n", i + 1);
        f[i] = coletaDados();
    }
    // Impressão das informações iniciais dos funcionários
    imprimaFuncionarios(f, 5);
    // Reajustar salarios
    for(i = 0; i < 5; i++) {
        reajustaSalario(&f[i].salario);
    }
    // Impressão dos salários corrigidos
    rel_salario_corrigido(f, 5);

    printf("\n\n");
    system("pause");
    return 0;
}
// Função para coleta de dados
FUNCIONARIO coletaDados() {
    FUNCIONARIO f;
    printf("ID: ");
    scanf(" %d", &f.id);
    printf("Nome: ");
    getchar();
    fgets(f.nome, 29, stdin);
    printf("Idade: ");
    scanf(" %d", &f.idade);
    printf("Salario: R$");
    scanf(" %f", &f.salario);
    printf("\n");
    return f;
}

void imprimaFuncionarios(FUNCIONARIO f[], int quantidade) {
    int i;
    printf("\nRelatorio de Funcionarios:\n");
    for(i = 0; i < quantidade; i++) {
        printf("Dados Funcionario %d\n", i + 1);
        printf("ID ....: %d \n", f[i].id);
        printf("Nome ..: %s", f[i].nome);
        printf("Idade .: %d \n", f[i].idade);
        printf("Salario: R$%.2f \n", f[i].salario);
        printf("\n");
    }
}

void reajustaSalario (float *salario){
    *salario = *salario * 1.1;
}

void rel_salario_corrigido(FUNCIONARIO f[], int quantidade) {
    int i;
    printf("\nSalario corrigido:\n");
    for(i = 0; i < quantidade; i++) {
        printf("Funcionario %d\n", i +1);
        printf("Nome: %s", f[i].nome);
        printf("Novo Salario: R$%.2f\n", f[i].salario);
        printf("\n");
    }
}
