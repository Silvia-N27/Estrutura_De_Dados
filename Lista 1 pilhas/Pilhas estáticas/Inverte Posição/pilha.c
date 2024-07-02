#include "pilha.h"

void Inicializa(Pilha *p) {
    p->Topo = -1;
}

int Vazia(Pilha p) {
    return p.Topo == -1;
}

void Empilha(TipoItem x, Pilha *p) {
    if (p->Topo == MAX - 1) {
        printf("Pilha cheia\n");
    }
    else {
        p->Topo = p->Topo + 1;
        p->Item[p->Topo] = x;
    }
}

void Desempilha(Pilha *p, TipoItem *Item) {
    if (Vazia(*p)) {
        printf("Pilha vazia\n");
    }
    else {
        *Item = p->Item[p->Topo];
        p->Topo = p->Topo - 1;
    }
}

void ImprimePilha(Pilha p) {
    if (Vazia(p)) {
        printf("Pilha vazia\n");
    }
    else {
        for (int i = p.Topo; i >= 0; --i) {
            printf("%d\n", p.Item[i].Chave);
        }
    }
}

void InvertePilha(Pilha *p) {
    Pilha aux1, aux2;
    TipoItem item;
    
    Inicializa(&aux1);
    Inicializa(&aux2);
    
    if (Vazia(*p)){
        return;
    }

    while (!Vazia(*p)) {
        Desempilha(p, &item);
        Empilha(item, &aux1);
    }

    while (!Vazia(aux1)) {
        Desempilha(&aux1, &item);
        Empilha(item, &aux2);
    }

    while (!Vazia(aux2)) {
        Desempilha(&aux2, &item);
        Empilha(item, p);
    }
}