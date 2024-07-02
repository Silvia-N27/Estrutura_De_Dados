#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <locale.h>

#define MAX 10

typedef int TipoChave;

typedef struct {
    TipoChave chave;
} Registro;

typedef struct {
    Registro elementos[MAX];
    int inicio;
    int fim;
    int tamanho;
} Fila;

void InicializarFila(Fila *f);
int TamanhoFila(Fila *f);
bool FilaVazia(Fila *f);
bool FilaCheia(Fila *f);
void ImprimirFila(Fila *f);
bool Enfileirar(Fila *f, Registro r);
bool Desenfileirar(Fila *f, Registro *r);
void ReinicializarFila(Fila *f);