// Função iterativa para contagem regressiva
void contagem_regressiva_iterativa(int valor) {
    printf("\nContagem regressiva (Iterativa): ");
    for (int i = valor; i >= 0; i--) {
        printf("%d ", i);
    }
    printf("\n");
}

// Função recursiva para contagem regressiva
void contagem_regressiva_recursiva(int valor) {
    if (valor < 0) {
        printf("\n");
        return; // Caso base: quando n for menor que 0, termina a recursão
    }
    printf("%d ", valor);
    contagem_regressiva_recursiva(valor - 1); // Chama a função novamente com n - 1
}
