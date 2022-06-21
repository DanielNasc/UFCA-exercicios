#include <stdio.h>
#include "arvoreBinaria.h"

int main() {
    Tree *tree = createTree();

    int values[] = { 50, 10, 70, 7, 20, 99, 9, 30, 40, 55, 53, 60, 8, 51 };
    int choose;
    printf("Você deseja inserir os valores manualmente ou usar os valores padrão?\n");
    printf("1 - Manual\n");
    printf("2 - Padrão\n");

    do {
        scanf("%d", &choose);
        if (choose != 1 && choose != 2) {
            printf("Opção inválida!\n");
        }
    } while (choose != 1 && choose != 2);

    if (choose == 1) {
        printf("Quantos nós deseja inserir? ");
        int n;
        scanf("%d", &n);

        for (int i = 0; i < n; i++) {
            bool inserted;

            do {
                printf("Digite o valor do nó %d: ", i + 1);
                int value;
                scanf("%d", &value);
                inserted = insert(tree, value);
            } while (!inserted);
        }
    } else {
        for (int i = 0; i < sizeof(values) / sizeof(int); i++) {
            insert(tree, values[i]);
        }
    }

    printf("Nós inseridos com sucesso!\n");
    if (balanceada(tree)) {
        printf("A árvore é balanceada!\n");
    } else {
        printf("A árvore não é balanceada!\n");
    }
    printf("\n");

    printf("Em que ordem deseja imprimir?\n");
    printf("1 - Pre-ordem\n");
    printf("2 - In-ordem\n");
    printf("3 - Pos-ordem\n");
    int order;
    scanf("%d", &order);

    print(tree, order);

    printf("\n");

    printf("Digite uma chave e os seus ancestrais serão impressos: ");
    int key;
    scanf("%d", &key);
    ancestrais(tree, key);

    printf("Digite o valor a ser buscado: ");
    int value;  
    scanf("%d", &value);

    if (doesValueExist(tree, value)) {
        printf("O valor %d existe na árvore.\n", value);
    } else {
        printf("O valor %d não existe na árvore.\n", value);
    }

    printf("\n");

    printf("Digite o valor a ser removido: ");
    scanf("%d", &value);
    removeNode(tree, value);

    printf("\n");

    printf("Em que ordem deseja imprimir?\n");
    printf("1 - Pre-ordem\n");
    printf("2 - In-ordem\n");
    printf("3 - Pos-ordem\n");
    scanf("%d", &order);

    print(tree, order);

    printf("\n");

    printf("Digite um nivel e os nós que estão serão impressos (a raiz tem nível 0): ");
    int level;
    scanf("%d", &level);
    nosnivel(tree, level);

    printf("\n");

    printf("Liberando folhas...\n");
    outono(tree);

    printf("\n");

    printf("Em que ordem deseja imprimir?\n");
    printf("1 - Pre-ordem\n");
    printf("2 - In-ordem\n");
    printf("3 - Pos-ordem\n");
    scanf("%d", &order);

    print(tree, order);

    destroy(tree);

    printf("\n\nAdeus!\n");

    return 0;
}