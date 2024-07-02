#include "pilha.c"

int main() {
    Pilha P1, P2;
    InicializarPilha(&P1);
    InicializarPilha(&P2);

    Registro r1, r2, r3;
    r1.chave = 10;
    r2.chave = 20;
    r3.chave = 30;

    PUSH(&P1, r1);
    PUSH(&P1, r2);
    PUSH(&P1, r3);

    PUSH(&P2, r1);
    PUSH(&P2, r2);

    printf("Pilha P1:");
    ImprimirPilha(&P1);

    printf("Pilha P2:");
    ImprimirPilha(&P2);

    if (CompararPilhas(&P1, &P2)) {
        printf("P1 tem mais elementos que P2\n");
    }
    else {
        printf("P1 tem menos elementos que P2\n");
    }

    return 0;
}