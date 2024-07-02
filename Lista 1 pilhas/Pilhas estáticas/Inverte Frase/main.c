#include "pilha.c"

void InverteFrase(char *str) {
    Pilha pilha;
    TipoItem item;
    int len = strlen(str);

    Inicializa(&pilha);
    
    for (int i = 0; i <= len; ++i) {
        if (str[i] == ' ' || str[i] == '\0') {
            while (!Vazia(pilha)) {
                Desempilha(&pilha, &item);
                printf("%c", item.Chave);
            }
            if (str[i] != '\0') {
                printf(" ");
            }
        }
        else {
            TipoItem letra;
            letra.Chave = str[i];
            Empilha(letra, &pilha);
        }
    }
    printf("\n");
}

int main() {
    char str[MAX] = "ESTE EXERCICIO E MUITO FACIL";
    
    printf("Original: %s\n", str);
    printf("Invertido: ");
    InverteFrase(str);

    return 0;
}
