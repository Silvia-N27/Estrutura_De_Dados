#include "pilha.c"

int main() {
    Pilha P1, P2;
    Registro r1, r2, r3;

    InicializarPilha(&P1);
    InicializarPilha(&P2);
    
    r1.chave = 10;
    r2.chave = 20;
    r3.chave = 30;

    PUSH(&P1, r1);
    PUSH(&P1, r2);
    PUSH(&P1, r3);

    printf("P1 antes da transferência:");
    ImprimirPilha(&P1);

    printf("P2 antes da transferência:");
    ImprimirPilha(&P2);

    TransferirPilha(&P1, &P2);

    printf("P1 depois da transferência:");
    ImprimirPilha(&P1);

    printf("P2 depois da transferência:");
    ImprimirPilha(&P2);

    return 0;
}
