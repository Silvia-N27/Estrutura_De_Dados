#define MAX 100
#include <stdio.h>
#include <stdlib.h>

typedef int TipoChave;

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
void InvertePilha(Pilha *p);
void ImprimePilha(Pilha p);