#include "pilha.c"

int main() {
    Pilha P1, P2;
    TipoItem item1, item2, item3;

    Inicializa(&P1);
    Inicializa(&P2);

    item1.Chave = 10;
    item2.Chave = 20;
    item3.Chave = 30;

    Empilha(item1, &P1);
    Empilha(item2, &P1);
    Empilha(item3, &P1);

    CopiaPilha(P1, &P2);

    printf("P1:\n");
    ImprimePilha(P1);

    printf("\nP2 (cópia de P1):\n");
    ImprimePilha(P2);

    return 0;
}