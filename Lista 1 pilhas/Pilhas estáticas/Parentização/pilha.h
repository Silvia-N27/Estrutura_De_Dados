#define MAX 100
#include <stdio.h>
#include <stdlib.h>

typedef char TipoChave;

typedef struct {
    TipoChave Chave;
} TipoItem;

typedef struct {
    TipoItem Item[MAX];
    int Topo;
} Pilha;

void Inicializa(Pilha *p);
int Vazia(Pilha p);
void Empilha(TipoItem x, Pilha *p);
void Desempilha(Pilha *p, TipoItem *Item);
int VerificaParenteses(char *expressao);