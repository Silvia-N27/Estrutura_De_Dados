#include "pilha.c"

int main() {
    char palavra1[] = "arara";
    char palavra2[] = "amora";

    if(VerificaPalindromo(palavra1)){
        printf("%s: é palíndromo\n",palavra1);
    }
    else{
        printf("%s: não é palíndromo\n",palavra1);
    }

    if(VerificaPalindromo(palavra2)){
        printf("%s: é palíndromo",palavra2);
    }
    else{
        printf("%s: não é palíndromo", palavra2);
    }

    return 0;
}