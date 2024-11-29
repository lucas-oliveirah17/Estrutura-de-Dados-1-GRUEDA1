// Arquivo pilha.h - PILHA DIN�MICA
typedef struct aluno{
    int matricula;
    float n1, n2, n3;
}ALUNO;

typedef struct elemento* PILHA;
// typedef struct pilha PILHA; // Vers�o PDF

PILHA *criaPilha();

void liberaPilha(PILHA *pi);

int tamanhoPilha(PILHA *pi);

int pilhaCheia(PILHA *pi);

int pilhaVazia(PILHA *pi);

int inserePilha(PILHA *pi, ALUNO al);

int removePilha(PILHA *pi);

int acessaTopoPilha(PILHA *pi, ALUNO *al);
