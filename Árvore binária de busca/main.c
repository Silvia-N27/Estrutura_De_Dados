#include "arvore_binaria.c"

int main() {
    No* raiz = NULL;
    int opcao, chave;
    No* resultado;

    do {
        printf("\nMenu:\n");
        printf("1. Inserir chave\n");
        printf("2. Buscar chave\n");
        printf("3. Remover chave\n");
        printf("4. Imprimir pré-ordem\n");
        printf("5. Imprimir em ordem\n");
        printf("6. Imprimir pós-ordem\n");
        printf("7. Encontrar predecessor\n");
        printf("8. Encontrar sucessor\n");
        printf("9. Encontrar mínimo\n");
        printf("10. Encontrar máximo\n");
        printf("0. Sair\n");
        printf("Escolha uma opção:");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                printf("Digite a chave:");
                scanf("%d", &chave);
                raiz = inserir(raiz, chave);
                break;

            case 2:
                printf("Digite a chave:");
                scanf("%d", &chave);
                resultado = busca_chave(raiz, chave);
                if (resultado != NULL) {
                    printf("Chave encontrada\n");
                }
                else {
                    printf("Chave não encontrada\n");
                }
                break;

            case 3:
                printf("Digite a chave:");
                scanf("%d", &chave);
                raiz = remover(raiz, chave);
                break;

            case 4:
                printf("Árvore em pré-ordem:");
                pre_ordem(raiz);
                printf("\n");
                break;

            case 5:
                printf("Árvore em ordem:");
                em_ordem(raiz);
                printf("\n");
                break;

            case 6:
                printf("Árvore em pós-ordem:");
                pos_ordem(raiz);
                printf("\n");
                break;

            case 7:
                printf("Digite a chave:");
                scanf("%d", &chave);
                resultado = predecessor(raiz, chave);
                if (resultado != NULL) {
                    printf("Predecessor de %d é %d\n", chave, resultado->chave);
                }
                else {
                    printf("%d não tem predecessor\n", chave);
                }
                break;

            case 8:
                printf("Digite a chave:");
                scanf("%d", &chave);
                resultado = sucessor(raiz, chave);
                if (resultado != NULL) {
                    printf("Sucessor de %d é %d\n", chave, resultado->chave);
                }
                else {
                    printf("%d não tem sucessor\n", chave);
                }
                break;

            case 9:
                resultado = minimo(raiz);
                if (resultado != NULL) {
                    printf("Mínimo: %d\n", resultado->chave);
                }
                else {
                    printf("ERRO!!! árvore está vazia\n");
                }
                break;

            case 10:
                resultado = maximo(raiz);
                if (resultado != NULL) {
                    printf("Máximo: %d\n", resultado->chave);
                }
                else {
                    printf("ERRO!!! árvore está vazia\n");
                }
                break;

            case 0:
                printf("Saindo do programa\n");
                break;

            default:
                printf("ERRO!!!Opção inválida\n");
                break;
        }
    } while (opcao != 0);

    return 0;
}