// Arquivo listaSequencial.h
#define MAX 100 // Macro definindo tamanho máximo da lista

/*Dado que será guardado dentro da lista*/
struct aluno{
    int matricula;
    float n1, n2, n3;
};

/*Esse "tipo" fica oculto do programa principal através
do encapsulamento. O usuário/programador só o acessa por
meio de funções disponibilizadas pelo TAD*/
typedef struct lista Lista;

Lista *cria_lista(); //

void libera_lista(Lista *li); //

int tamanho_lista(Lista *li); //

int lista_cheia(Lista *li); //

int lista_vazia(Lista *li); //

int insere_lista_final(Lista *li, struct aluno al); //

int insere_lista_inicio(Lista *li, struct aluno al); //

int insere_lista_ordenada(Lista *li, struct aluno al); //

int remove_lista_final(Lista *li);

int remove_lista_inicio(Lista *li);

int remove_lista(Lista *li, int matricula);

int consulta_lista_pos(Lista *li, int pos, struct aluno *al);

int consulta_lista_mat(Lista *li, int mat, struct aluno *al);

struct aluno coletar_dados_aluno();
