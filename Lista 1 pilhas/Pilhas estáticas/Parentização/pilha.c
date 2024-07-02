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

int VerificaParenteses(char *parenteses) {
    Pilha pilha;
    Inicializa(&pilha);
    TipoItem item;

    for (int i = 0; parenteses[i] != '\0'; i++) {
        if (parenteses[i] == '(') {
            item.Chave = '(';
            Empilha(item, &pilha);
        }
        else if (parenteses[i] == ')') {
            if (Vazia(pilha)) {
                return 0;
            }
            Desempilha(&pilha, &item);
        }
    }

    return Vazia(pilha);
}