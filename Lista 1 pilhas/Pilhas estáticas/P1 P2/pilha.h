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
int Tamanho(Pilha p);
void Empilha(TipoItem x, Pilha *p);
void Desempilha(Pilha *p, TipoItem *Item);
void CopiaPilha(Pilha P1, Pilha *P2);
void ImprimePilha(Pilha p);