#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main() {
    int n_alunos;
    float *notas, soma = 0.0, media;

    setlocale(LC_ALL, "");
    printf("Atividade 2 - Alocação de Memória\n\n");

    // Solicita a quantidade de alunos
    printf("Digite a quantidade de alunos: ");
    scanf("%d", &n_alunos);

    // Aloca memória dinamicamente para armazenar as notas
    notas = (float*) malloc(n_alunos * sizeof(float));
    if (notas == NULL) {
        printf("ERRO: Sem memória!!\n");
        return 1;
    }

    // Coleta as notas dos alunos
    for (int i = 0; i < n_alunos; i++) {
        printf("Digite a nota do aluno %d: ", i + 1);
        scanf("%f", &notas[i]);
        soma += notas[i]; // Soma as notas para o cálculo da média
    }

    // Calcula a média aritmética
    media = soma / n_alunos;

    // Imprime as notas dos alunos
    printf("\nNotas dos alunos:\n");
    for (int i = 0; i < n_alunos; i++) {
        printf("Aluno %d: %.2f\n", i + 1, notas[i]);
    }

    // Imprime a média aritmética
    printf("\nMédia da turma: %.2f\n", media);

    // Libera a memória alocada
    free(notas);

    return 0;
}

