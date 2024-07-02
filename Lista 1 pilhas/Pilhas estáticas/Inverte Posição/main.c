#include "pilha.c"

int main() {
    Pilha p;
    TipoItem item;
    
    Inicializa(&p);

    for (int i = 1; i <= 5; ++i) {
        item.Chave = i;
        Empilha(item, &p);
    }

    printf("Pilha original:\n");
    ImprimePilha(p);

    InvertePilha(&p);

    printf("\nPilha invertida:\n");
    ImprimePilha(p);

    return 0;
}