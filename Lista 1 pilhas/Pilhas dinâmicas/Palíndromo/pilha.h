#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <locale.h>
#include <ctype.h>

typedef char TipoChave;

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
bool PilhasIguais(Pilha *P1, Pilha *P2);
bool Palindromo(const char* str);