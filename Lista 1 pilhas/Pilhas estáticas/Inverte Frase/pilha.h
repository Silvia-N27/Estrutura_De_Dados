#define MAX 100
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
int Tamanho(Pilha p);
void Empilha(TipoItem x, Pilha *p);
void Desempilha(Pilha *p, TipoItem *Item);
void ImprimePilha(Pilha p);
