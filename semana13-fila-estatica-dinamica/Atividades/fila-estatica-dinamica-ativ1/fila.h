// Arquivo fila.h - FILA ESTÁTICA

// Número máximo de elementos suportados pela Fila
#define MAX 100

/*Estrutura ALUNO, visível pelo main() que será
armazenada na fila*/
typedef struct aluno{
    int matricula;
    float n1, n2, n3;
}ALUNO;

/*Definição do tipo de dado FILA, que será visível pelo
main()*/
typedef struct fila FILA;

/*Cria a fila em memória e devolve endereço de sua
localização*/
FILA *criaFila();

/*Libera memória alocada para a fila*/
void liberaFila(FILA *fi);

/*Devolve quantos elementos estão na fila*/
int tamanhoFila(FILA *fi);

/*Verifica se fila está cheia*/
int filaCheia(FILA *fi);

/*Verifica se fila está vazia*/
int filaVazia(FILA *fi);

/*Insere na fila, recebe estrutura a inserir*/
int insereFila(FILA *fi, ALUNO al);

/*Remove um elemento da fila*/
int removeFila(FILA *fi);

/*Consulta elemento na fila, recebe endereço da
estrutura*/
int consultaFila(FILA *fi, ALUNO *al);
