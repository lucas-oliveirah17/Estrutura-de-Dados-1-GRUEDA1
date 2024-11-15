// Arquivo listaLigada.h
typedef struct aluno{
    int matricula;
    float n1, n2, n3;
}ALUNO;

/*Ponteiro apontado pelo ponteiro da fun��o main*/
typedef struct elemento* Lista;

Lista *criaLista();

void abortaPrograma();

/*Essa fun��o deve ser a �ltima a ser chamada pelo
main()*/
void apagaLista(Lista *li);

int tamanhoLista(Lista *li);

int listaCheia(Lista *li);

int listaVazia(Lista *li);

int insereInicio(Lista *li, ALUNO al);

int insereFinal(Lista *li, ALUNO al);

int insereOrdenado(Lista *li, ALUNO al);
