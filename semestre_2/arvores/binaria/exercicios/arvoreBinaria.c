#include <stdlib.h>
#include <stdio.h>
#include <math.h>
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

// Funções auxiliares

int getHeightNode(Node *node) {
    if (node == NULL) {
        return 0;
    }

    int left = getHeightNode(node->esq);
    int right = getHeightNode(node->dir);

    return ((left > right) ? left : right) + 1;
}

int getHeight(Tree *tree) {
    if (tree == NULL) {
        printf("Erro ao obter a altura da árvore!\n");
        exit(1);
    }

    return getHeightNode(tree->root);
}

int getLevel(Tree *tree, int value) {
    if (tree == NULL) {
        printf("Erro ao obter o nível do nó!\n");
        exit(1);
    }

    if (tree->root == NULL) {
        return 0;
    }

    int level = 0;
    Node *current = tree->root;

    // Loop para percorrer a árvore
    while (current != NULL && current->info != value) {
        // Dependendo do valor do nó atual, o ponteiro auxiliar vai
        // para o filho da esquerda ou da direita.
        current = (value < current->info) ? current->esq : current->dir;
        level++;
    }

    return (current != NULL) ? level : -1;
}

// Funções exercicios

// Checa se o nó tem apenas um filho
bool hasOnlyOneChild(Node *node) {
    if (node == NULL) {
        return false;
    }

    return (node->esq == NULL && node->dir != NULL) || (node->esq != NULL && node->dir == NULL);
}

// percorre a arvore inteira e checa se todos os nós tem dois ou nenhum filho
bool isBinaryTree(Node *node) {
    if (node == NULL) {
        return true;
    }

    if (hasOnlyOneChild(node)) {
        return false;
    }

    return isBinaryTree(node->esq) && isBinaryTree(node->dir);
}

bool estritamente(Tree *tree) // verificar se uma árvore é estritamente binária (retorna 1) ou não (retorna 0).
{
    if (tree == NULL) {
        printf("Não há nada para verificar!\n");
        return false;
    }

    if (tree->root == NULL) {
        return true;
    }

    return isBinaryTree(tree->root);
}

bool balancedHeight(Node *node) {
    if (node == NULL) {
        return true;
    }

    int left = balancedHeight(node->esq);
    if (!left) {
        return false;
    }

    int right = balancedHeight(node->dir);
    if (!right) {
        return false;
    }

    return abs(left - right) <= 1;
}

bool balanceada(Tree *tree) // verificar se uma árvore é balanceada (retorna 1) ou não (retorna 0).
{
    if (tree == NULL) {
        printf("Não há nada para verificar!\n");
        return false;
    }

    if (tree->root == NULL) {
        return true;
    }

    return balancedHeight(tree->root);
}

Node *copyNode(Node *node) {
    if (node == NULL) {
        return NULL;
    }

    Node *newNode = malloc(sizeof(Node)); // aloca memória para o novo nó
    newNode->info = node->info; // copia o valor do nó
    newNode->esq = copyNode(node->esq); // copia o filho da esquerda
    newNode->dir = copyNode(node->dir); // copia o filho da direita

    return newNode; // retorna o novo nó
}

Tree* copia (Tree *original) // gera uma cópia de uma árvore existente (duplicada completamente refeita).
{
    if (original == NULL)
        return NULL;

    Tree *duplicada = createTree(); // cria uma nova árvore
    duplicada->root = copyNode(original->root); // copia o nó raiz e todo o resto da árvore recursivamente

    return duplicada; // retorna a árvore duplicada 
}

int pai(Tree *tree, int x) // acesse o pai de um nó com key x.
{
    if (tree == NULL || tree->root == NULL) {
        printf("Não há nada para acessar!\n");
        return -1;
    }

    Node *parent = NULL,
         *child = tree->root;

    while (child != NULL) {
        // Se o nó com key x foi encontrado, retorna a info do pai, se existir
        if (child->info == x) {
            if (parent != NULL) {
                return parent->info; // o pai existe, então retorna a info do pai
            } else {
                printf("O nó com a chave %d não tem pai!\n", x);
                printf("Pois ele é a raiz da árvore!\n");
                return -1; // o pai não existe, então retorna -1
            }
        }

        parent = child;
        // se o nó com key x for maior que o nó atual, então o nó atual é o filho da esquerda, senão o nó atual é o filho da direita
        child = child->info > x ? child->esq : child->dir;
    }

    printf("O nó com a chave %d não existe!\n", x);
    return -1;
}

int maior(Tree *tree) // retorne a maior chave de uma árvore.
{
    if (tree == NULL || tree->root == NULL) {
        printf("Não há nada para acessar!\n");
        return -1;
    }

    Node *node = tree->root;

    // o nó com maior chave é o nó mais à direita da árvore
    while (node->dir != NULL) {
        node = node->dir;
    }

    return node->info;
}

int menor(Tree *tree) // retorno a menor chave de uma árvore.
{
    if (tree == NULL || tree->root == NULL) {
        printf("Não há nada para acessar!\n");
        return -1;
    }

    Node *node = tree->root;

    // o nó com menor chave é o nó mais à esquerda da árvore
    while (node->esq != NULL) {
        node = node->esq;
    }

    return node->info;
}
void ancestrais (Tree *tree, int x) // imprima todos os ancestrais de uma determinada chave.
// -> Exemplo suponha uma árvore com impressão pré-ordem: 5, 3, 2, 1. Sendo x = 2 imprimiria (2 filho de 3 filho de 5)
{
    if (tree == NULL || tree->root == NULL) {
        printf("Não há nada para acessar!\n");
        return;
    }

    // Checa se o nó com key x existe
    int level = getLevel(tree, x);
    if (level == -1) {
        printf("O nó com a chave %d não existe!\n", x);
        return;
    } else if (level == 0) {
        printf("O nó com a chave %d é a raiz!\n", x);
        return;
    }

    int keys[level];
    Node *node = tree->root;

    // Preenche o vetor com as chaves dos nós do nível do nó com key x
    for (int i = 0; i < level; i++) {
        keys[i] = node->info;
        node = node->info > x ? node->esq : node->dir;
    }

    // Imprime os nós do nível do nó com key x
    printf("%d", x);
    for (int i = level - 1; i >= 0; i--) {
        printf(" filho de %d", keys[i]);
    }
    printf("\n");
}

int kthmenor(Tree *tree, int k); // retorne a k-ésimo menor chave de uma árvore.

Node *liberaFolhas(Node *node) // libera todas as folhas de uma árvore
{
    if (node == NULL) {
        return NULL;
    }

    if (node->esq == NULL && node->dir == NULL) {
        free(node);
        return NULL;
    }

    node->esq = liberaFolhas(node->esq);
    node->dir = liberaFolhas(node->dir);

    return node;
}

void outono(Tree *tree) // remova todas as folhas de uma árvore.
{
    if (tree == NULL || tree->root == NULL) {
        printf("Não há nada para acessar!\n");
        return;
    }

    tree->root = liberaFolhas(tree->root);
}

int countNodesWithOneChild(Node *node) // conte o número de nós que tem um filho único.
{
    if (node == NULL)
        return 0;

    if (node->esq == NULL && node->dir != NULL) {
        return 1 + countNodesWithOneChild(node->dir);
    } else if (node->esq != NULL && node->dir == NULL) {
        return 1 + countNodesWithOneChild(node->esq);
    } else if (node->esq == NULL && node->dir == NULL) {
        return 0;
    } else {
        return countNodesWithOneChild(node->esq) + countNodesWithOneChild(node->dir);
    }
}

int quantidadeumfilho (Tree *tree) // retorne a quantidade de nós com apenas um filho.
{
    if (tree == NULL || tree->root == NULL) {
        printf("Não há nada para acessar!\n");
        return -1;
    }

    return countNodesWithOneChild(tree->root);
}

void printLevel(Node *node, int level) // imprima todos os nós de um nível.
{
    if (node == NULL)
        return;

    if (level == 0) {
        printf("%d ", node->info);
    } else {
        printLevel(node->esq, level - 1);
        printLevel(node->dir, level - 1);
    }
}

void nosnivel(Tree *tree, int n) // imprima todos nós de um nível n de uma árvore.
{
    if (tree == NULL || tree->root == NULL) {
        printf("Não há nada para acessar!\n");
        return;
    }

    printLevel(tree->root, n);
}