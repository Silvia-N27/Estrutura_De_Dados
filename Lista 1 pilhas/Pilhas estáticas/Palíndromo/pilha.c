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

int VerificaPalindromo(char *palavra) {
    Pilha pilha;
    TipoItem item;
    int len = strlen(palavra);
    
    Inicializa(&pilha);

    for (int i = 0; i < len / 2; ++i) {
        TipoItem letra;
        letra.Chave = palavra[i];
        Empilha(letra, &pilha);
    }

    for (int i = (len + 1) / 2; i < len; ++i) {
        Desempilha(&pilha, &item);
        if (item.Chave != palavra[i]) {
            return 0;
        }
    }

    return 1;
}