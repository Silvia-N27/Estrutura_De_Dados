#include "lista.c"

void menu() {
    printf("Escolha uma das opções abaixo:\n");
    printf("1. Inicializar lista\n");
    printf("2. Retornar tamanho da lista\n");
    printf("3. Imprimir lista\n");
    printf("4. Inserir chave\n");
    printf("5. Buscar por chave\n");
    printf("6. Remover por chave\n");
    printf("7. Reinicializar lista\n");
    printf("0. Sair\n");
}

int main() {
    Lista L;
    Registro r;
    Tipo_Chave chave;
    int opcao;
    bool bol;

    do {
        menu();
        scanf("%d", &opcao);
        switch (opcao) {
            case 1:
                InicializarLista(&L);
                printf("Lista inicializada\n");
                break;

            case 2:
                printf("Tamanho da lista: %d\n", RetornarTamanho(&L));
                break;

            case 3:
                ImprimirLista(&L);
                break;

            case 4:
                printf("Digite a chave:");
                scanf("%d", &r.chave);
                bol = InserirChave(&L, r);
                if (bol)
                    printf("Elemento inserido\n");
                else
                    printf("ERRO!!!\n");
                break;

            case 5:
                printf("Digite a chave:");
                scanf("%d", &chave);
                PONT encontrado = BuscarChave(&L, chave);
                if (encontrado)
                    printf("Elemento %d encontrado\n", chave);
                else
                    printf("Elemento %d não encontrado\n", chave);
                break;

            case 6:
                printf("Digite a chave:");
                scanf("%d", &chave);
                bol = RemoverChave(&L, chave);
                if (bol)
                    printf("Elemento %d removido\n", chave);
                else
                    printf("ERRO!!!\n");
                break;

            case 7:
                ReinicializarLista(&L);
                printf("Lista reinicializada\n");
                break;

            case 0:
                printf("Saindo do programa...\n");
                break;

            default:
                printf("ERRO!!! Não existe essa opção\n");
        }
    } while (opcao != 0);

    return 0;
}