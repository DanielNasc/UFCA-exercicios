#include <stdlib.h>
#include <stdio.h>
#include "arvoreBinaria.h"

typedef struct node {
    int info;
    struct node *esq;
    struct node *dir;
} Node;

typedef struct tree {
    Node *root;
} Tree;

// Funções básicas
Tree *createTree() {
    Tree *t = (Tree *) malloc(sizeof(Tree));

    if (t == NULL) {
        printf("Erro ao criar árvore!\n");
        exit(1);
    }

    t->root = NULL;

    return t;
}

Node *createNode(int info) {
    Node *node = (Node *) malloc(sizeof(Node));

    if (node == NULL) {
        printf("Erro ao alocar memória para o nó.\n");
        exit(1);
    }

    node->info = info;
    node->esq = node->dir = NULL;

    return node;
}

bool insert(Tree *t, int info) {
    if (t == NULL) {
        printf("Erro ao inserir nó!\n");
        exit(1);
    }

    // checa se o nó já existe
    if (doesValueExist(t, info)) {
        printf("O valor %d já existe na árvore.\n", info);
        return false;
    }

    if (t->root == NULL) {
        // Se a árvore estiver vazia, cria o nó root
        t->root = createNode(info);
    } else {
        Node *current = t->root;
        Node *parent;

        while (current != NULL) {
            parent = current;

            // Se o valor do nó atual for maior que o valor a ser inserido,
            // o nó atual será o filho da direita.
            // Caso contrário, o nó atual será o filho da esquerda.
            current = (info < current->info) ? current->esq : current->dir;
        }

        if (info < parent->info) {
            parent->esq = createNode(info);
        } else {
            parent->dir = createNode(info);
        }
    }

    return true;
}

void removeNode(Tree *tree, int value) {
    if (tree == NULL) {
        printf("Erro ao remover nó!\n");
        exit(1);
    }

    if (tree->root == NULL) {
        printf("Árvore vazia!\n");
        return;
    }

    Node *current = tree->root;
    Node *parent = NULL;

    while (current != NULL && current->info != value) {
        parent = current;

        // Se o valor do nó atual for maior que o valor a ser removido,
        // o nó atual será o filho da direita.
        // Caso contrário, o nó atual será o filho da esquerda.
        current = (value < current->info) ? current->esq : current->dir;
    }

    if (current == NULL) {
        printf("Nó não encontrado!\n");
        return;
    }

    // Se o nó a ser removido não tem filhos, remove o nó atual.
    if (current->esq == NULL && current->dir == NULL) {
        if (parent == NULL) {
            tree->root = NULL;
        } else if (parent->esq == current) {
            parent->esq = NULL;
        } else {
            parent->dir = NULL;
        }

        free(current);

    } else if (current->esq == NULL) {
        // Se o nó a ser removido tem apenas o filho da direita,
        // substitui o nó atual pelo filho da direita.
        if (parent == NULL) {
            tree->root = current->dir;
        } else if (parent->esq == current) {
            parent->esq = current->dir;
        } else {
            parent->dir = current->dir;
        }

        free(current);
    } else if (current->dir == NULL) {
        // Se o nó a ser removido tem apenas o filho da esquerda,
        // Substitui o nó atual pelo filho da direita
        if (parent == NULL) {
            tree->root = current->esq;
        } else if (parent->esq == current) {
            parent->esq = current->esq;
        } else {
            parent->dir = current->esq;
        }

        free(current);
    } else {
        // Se o nó a ser removido tem os dois filhos,
        // substitui o nó atual pelo seu antecessor imediato.
        Node *paiAnt = current;
        Node *ant = current->esq;

        // Encontra o antecessor imediato do nó a ser removido
        // Que é o nó que tem o maior valor entre todos os filhos da esquerda.
        while (ant->dir != NULL) {
            paiAnt = ant;
            ant = ant->dir;
        }

        // Substitui o nó atual pelo antecessor imediato
        current->info = ant->info;

        // Só sei explicar isso desenhando
        if (paiAnt == current) {
            paiAnt->esq = ant->esq;
        } else {
            paiAnt->dir = ant->esq;
        }

        free(ant);
    }
}

bool doesValueExist(Tree *tree, int value) {
    if (tree == NULL) {
        printf("Erro ao verificar se o valor existe!\n");
        exit(1);
    }

    // Se a árvore estiver vazia, o valor não existe
    if (tree->root == NULL) {
        return false;
    }

    Node *current = tree->root;

    // Loop para percorrer a árvore
    while (current != NULL && current->info != value) {
        // Dependendo do valor do nó atual, o ponteiro auxiliar vai
        // para o filho da esquerda ou da direita.
        current = (value < current->info) ? current->esq : current->dir;
    }

    return (current != NULL); // Se o nó atual for diferente de NULL, o valor existe
}

/*
    * Função: freeNode
    * Descrição: libera, primeiramente, todos os nós filhos do nó passado como parâmetro recursivamente.
    * Após isso, libera o nó passado como parâmetro.
*/
void freeNode(Node *node) {
    if (node == NULL) {
        return;
    }

    freeNode(node->esq);
    freeNode(node->dir);
    free(node);
}

// Libera todos os nós da árvore e depois a própria árvore
void destroy(Tree *tree) {
    if (tree == NULL) {
        printf("Mas a arvore ja esta vazia!\n");
        return;
    }

    freeNode(tree->root);
    free(tree);
}


void printPreOrder(Node *node) {
    if (node == NULL) {
        return;
    }

    printf("%d ", node->info);
    printPreOrder(node->esq);
    printPreOrder(node->dir);
}

void printInOrder(Node *node) {
    if (node == NULL) {
        return;
    }

    printInOrder(node->esq);
    printf("%d ", node->info);
    printInOrder(node->dir);
}

void printPostOrder(Node *node) {
    if (node == NULL) {
        return;
    }

    printPostOrder(node->esq);
    printPostOrder(node->dir);
    printf("%d ", node->info);
}

void print(Tree *tree, Order order) {
    if (tree == NULL) {
        printf("Não há nada para imprimir!\n");
        return;
    }

    switch (order) {
        case PREORDER:
            printPreOrder(tree->root);
            break;
        case INORDER:
            printInOrder(tree->root);
            break;
        case POSORDER:
            printPostOrder(tree->root);
            break;
    }
}