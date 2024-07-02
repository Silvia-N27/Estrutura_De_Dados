#include "fila.h"

void InicializarFila(Fila* f) {
    f->inicio = 0;
    f->fim = 0;
    f->tamanho = 0;
}

int TamanhoFila(Fila* f) {
    return f->tamanho;
}

bool FilaVazia(Fila* f) {
    return (f->tamanho == 0);
}

bool FilaCheia(Fila* f) {
    return (f->tamanho == MAX);
}

void ImprimirFila(Fila* f) {
    printf("\t\nFILA\n\n");
    for (int i = 0; i < f->tamanho; i++) {
        int aux = (f->inicio + i) % MAX; //calcular a posição correta de um elemento numa fila circular
        printf("\t %d \n", f->elementos[aux].chave);
    }
}

bool Enfileirar(Fila* f, Registro r) {
    if (FilaCheia(f)) {
        return false;
    }
    f->elementos[f->fim] = r;
    f->fim = (f->fim + 1) % MAX; //atualiza o fim da fila de maneira circular para que permaneça dentro do limite do array
    f->tamanho++;
    return true;
}

bool Desenfileirar(Fila* f, Registro* r) {
    if (FilaVazia(f)) {
        return false;
    }
    *r = f->elementos[f->inicio];
    f->inicio = (f->inicio + 1) % MAX; //atualiza o inicio da fila de maneira circular para que permaneça dentro do limite do array
    f->tamanho--;
    return true;
}

void ReinicializarFila(Fila* f) {
    InicializarFila(f);
}