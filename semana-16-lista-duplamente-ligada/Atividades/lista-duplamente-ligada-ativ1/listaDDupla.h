// Arquivo listaDDupla.h

typedef struct aluno{
    int matricula;
    float n1, n2, n3;
}ALUNO;

typedef struct elemento *LISTA;

LISTA *criaLista();

void apagaLista(LISTA *li);

void abortaPrograma();

int tamanhoLista(LISTA *li);

int listaCheia(LISTA *li);

int listaVazia(LISTA *li);

int insereInicio(LISTA *li, ALUNO al);

int insereFinal(LISTA *li, ALUNO al);

int insereOrdenado(LISTA *li, ALUNO al);

int removeInicio(LISTA *li);

int removeFinal(LISTA *li);

int removeOrdenado(LISTA *li, int mat);

int consultaPosicao(LISTA *li, int pos, ALUNO *al);

int consultaMatricula(LISTA *li, int mat, ALUNO *al);
