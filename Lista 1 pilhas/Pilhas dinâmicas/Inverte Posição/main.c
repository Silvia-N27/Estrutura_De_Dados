#include "pilha.c"

int main() {
    Pilha P;
    Registro r1, r2, r3;

    InicializarPilha(&P);
    
    r1.chave = 10;
    r2.chave = 20;
    r3.chave = 30;

    PUSH(&P, r1);
    PUSH(&P, r2);
    PUSH(&P, r3);

    printf("Pilha P antes da inversão:");
    ImprimirPilha(&P);

    InverterPilha(&P);

    printf("Pilha P após a inversão:");
    ImprimirPilha(&P);

    return 0;
}