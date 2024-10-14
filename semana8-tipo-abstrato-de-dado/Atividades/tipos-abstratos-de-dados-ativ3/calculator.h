// Arquivo calculator - Atividade 3
// Atribui novo nome para struct de saída de dados
typedef struct valuesOUT calcOUT;

// Aloca e retorna um calcOUT
calcOUT *createCalcOUT();

// Libera a memória alocada para um calcOUT
void freeCalcOUT(calcOUT *p);

// Função para realizar a operacao
double calculate(calcOUT *p, double e1, double e2, char o);

// Função para retorna o valor da última operação
double last_result(calcOUT *p);
