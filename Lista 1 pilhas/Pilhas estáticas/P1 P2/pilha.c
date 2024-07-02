#include "pilha.h"

void Inicializa(Pilha *p) {
    p->Topo = -1;
}

int Vazia(Pilha p) {
    return p.Topo == -1;
}

int Tamanho(Pilha p) {
    return p.Topo + 1;
}

void ImprimePilha(Pilha p) {
    if (Vazia(p)) {
        printf("Pilha vazia");
    }
    else {
        for (int i = p.Topo; i >= 0; --i) {
            printf("%d \n", p.Item[i].Chave);
        }
    }
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

void CopiaPilha(Pilha P1, Pilha *P2) {
    Inicializa(P2);
    for (int i = 0; i <= P1.Topo; ++i) {
        Empilha(P1.Item[i], P2);
    }
}