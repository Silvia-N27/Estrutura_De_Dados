#include "pilha.c"

int main() {
    char parenteses1[] = "(())((()))((()))";
    char parenteses2[] = ")((())((";

    if (VerificaParenteses(parenteses1)) {
        printf("%s está correto\n", parenteses1);
    }
    else {
        printf("%s está incorreto\n", parenteses1);
    }

    if (VerificaParenteses(parenteses2)) {
        printf("%s está correto\n", parenteses2);
    }
    else {
        printf("%s está incorreto\n", parenteses2);
    }

    return 0;
}