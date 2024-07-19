#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "lista.h"

void InicializarLista(Lista *L) {
    L->No = (PONT)malloc(sizeof(Elemento));
    L->No->prox = L->No;
    L->No->ant = L->No;
}

int RetornarTamanho(Lista *L) {
    PONT aux = L->No->prox;
    int tam = 0;
    while (aux != L->No) {
        tam++;
        aux = aux->prox;
    }
    return tam;
}

void ImprimirLista(Lista *L) {
    PONT aux = L->No->prox;
    while (aux != L->No) {
        printf("%d ", aux->r.chave);
        aux = aux->prox;
    }
    printf("\n");
}

bool InserirChave(Lista *L, Registro r) {
    PONT novo = (PONT)malloc(sizeof(Elemento));
    if (novo == NULL)
        return false;
    novo->r = r;

    PONT atual = L->No->prox;
    PONT anterior = L->No;

    while (atual != L->No && atual->r.chave < r.chave) {
        anterior = atual;
        atual = atual->prox;
    }

    novo->prox = atual;
    novo->ant = anterior;
    anterior->prox = novo;
    atual->ant = novo;

    return true;
}

PONT BuscarChave(Lista *L, Tipo_Chave ch) {
    PONT aux = L->No->prox;
    while (aux != L->No && aux->r.chave != ch) {
        aux = aux->prox;
    }
    if (aux != L->No)
        return aux;
    else
        return NULL;
}

bool RemoverChave(Lista *L, Tipo_Chave ch) {
    PONT remover = BuscarChave(L, ch);
    if (remover == NULL)
        return false;

    remover->ant->prox = remover->prox;
    remover->prox->ant = remover->ant;
    free(remover);

    return true;
}

void ReinicializarLista(Lista *L) {
    PONT aux = L->No->prox;
    while (aux != L->No) {
        PONT remover = aux;
        aux = aux->prox;
        free(remover);
    }
    L->No->prox = L->No;
    L->No->ant = L->No;
}