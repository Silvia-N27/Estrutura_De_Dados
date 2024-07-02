#include "pilha.c"

int main() {
    char str[100];

    printf("Digite uma frase:");
    fgets(str, 100, stdin);
    str[strcspn(str, "\n")] = 0; //remover o caractere de quebra de linha (\n) de uma string

    if (Palindromo(str)) {
        printf("é um palíndromo.\n");
    }
    else {
        printf("não é um palíndromo.\n");
    }

    return 0;
}
