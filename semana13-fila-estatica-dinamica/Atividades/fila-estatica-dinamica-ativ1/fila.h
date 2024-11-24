// Arquivo fila.h - FILA EST�TICA

// N�mero m�ximo de elementos suportados pela Fila
#define MAX 100

/*Estrutura ALUNO, vis�vel pelo main() que ser�
armazenada na fila*/
typedef struct aluno{
    int matricula;
    float n1, n2, n3;
}ALUNO;

/*Defini��o do tipo de dado FILA, que ser� vis�vel pelo
main()*/
typedef struct fila FILA;

/*Cria a fila em mem�ria e devolve endere�o de sua
localiza��o*/
FILA *criaFila();

/*Libera mem�ria alocada para a fila*/
void liberaFila(FILA *fi);

/*Devolve quantos elementos est�o na fila*/
int tamanhoFila(FILA *fi);

/*Verifica se fila est� cheia*/
int filaCheia(FILA *fi);

/*Verifica se fila est� vazia*/
int filaVazia(FILA *fi);

/*Insere na fila, recebe estrutura a inserir*/
int insereFila(FILA *fi, ALUNO al);

/*Remove um elemento da fila*/
int removeFila(FILA *fi);

/*Consulta elemento na fila, recebe endere�o da
estrutura*/
int consultaFila(FILA *fi, ALUNO *al);
