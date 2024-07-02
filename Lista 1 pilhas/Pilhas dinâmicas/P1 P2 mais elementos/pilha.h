#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <locale.h>

typedef int TipoChave;

typedef struct{
    TipoChave chave;
} Registro;

typedef struct aux{
    Registro r;
    struct aux* prox;
} Elemento;

typedef Elemento *PONT;

typedef struct{
    PONT topo;
} Pilha;

void InicializarPilha(Pilha *p);
int Tamanho(Pilha *p);
bool PilhaVazia(Pilha *p);
void ImprimirPilha(Pilha *p);
bool PUSH(Pilha *p, Registro r);
bool POP(Pilha *p, Registro *r);
void ReinicializarPilha(Pilha *p);
void TransferirPilha(Pilha *P1, Pilha *P2);
bool CompararPilhas(Pilha *P1, Pilha *P2);