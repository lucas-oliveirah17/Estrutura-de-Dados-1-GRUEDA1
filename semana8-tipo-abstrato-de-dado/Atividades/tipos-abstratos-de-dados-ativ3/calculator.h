// Arquivo calculator - Atividade 3
// Atribui novo nome para struct de sa�da de dados
typedef struct valuesOUT calcOUT;

// Aloca e retorna um calcOUT
calcOUT *createCalcOUT();

// Libera a mem�ria alocada para um calcOUT
void freeCalcOUT(calcOUT *p);

// Fun��o para realizar a operacao
double calculate(calcOUT *p, double e1, double e2, char o);

// Fun��o para retorna o valor da �ltima opera��o
double last_result(calcOUT *p);
