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

    PUSH(&P2, r3);
    PUSH(&P2, r2);
    PUSH(&P2, r1);

    printf("Pilha P1:");
    ImprimirPilha(&P1);

    printf("Pilha P2:");
    ImprimirPilha(&P2);

    if (PilhasIguais(&P1, &P2)) {
        printf("P1 e P2 são iguais\n");
    }
    else {
        printf("P1 e P2 não são iguais\n");
    }

    return 0;
}