#include "fila.c"

int main() {
    Fila fila;
    int opcao;
    TipoChave chave;
    Registro r;

    InicializarFila(&fila);

    do {
        printf("\nMenu:\n");
        printf("1 Inserir item na fila\n");
        printf("2 Remover item da fila\n");
        printf("3 Listar dados da fila\n");
        printf("4 Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                printf("Digite um número inteiro: ");
                scanf("%d", &chave);
                r.chave = chave;
                if (Enfileirar(&fila, r)) {
                    printf("item %d inserido com sucesso\n", chave);
                }
                else {
                    printf("Erro! a fila está cheia\n");
                }
                break;
            case 2:
                if (Desenfileirar(&fila, &r)) {
                    printf("item %d removido com sucesso\n", r.chave);
                }
                else {
                    printf("Erro! a fila está vazia\n");
                }
                break;
            case 3:
                ImprimirFila(&fila);
                break;
            case 4:
                printf("Saindo...\n");
                break;
            default:
                printf("Opção inválida. Tente novamente\n");
        }
    } while (opcao != 4);

    ReinicializarFila(&fila);
    return 0;
}