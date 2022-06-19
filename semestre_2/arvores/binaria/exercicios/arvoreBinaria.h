#include <stdbool.h>

typedef struct node Node;
typedef struct tree Tree;

typedef enum order {
    PREORDER = 1,
    INORDER,
    POSORDER
} Order;

// Funções básicas
Tree *createTree();
bool insert(Tree *tree, int value);
void removeNode(Tree *tree, int value);
void destroy(Tree *tree);
void print(Tree *tree, Order order);
// mesma função acessarValor que Roberto usa
bool doesValueExist(Tree *tree, int value);

// Funções auxiliares
int getHeight(Tree *tree);
// pegar o nivel de um nó
int getLevel(Tree *tree, int value);


// Funções exercicios
bool estritamente(Tree *tree); // verificar se uma árvore é estritamente binária (retorna 1) ou não (retorna 0).
bool balanceada(Tree *tree); // verificar se uma árvore é balanceada (retorna 1) ou não (retorna 0).
Tree* copia (Tree *original); // gera uma cópia de uma árvore existente (duplicada completamente refeita).
int pai(Tree *tree, int x); // acesse o pai de um nó com chave x.
int maior(Tree *tree); // retorne a maior chave de uma árvore.
int menor(Tree *tree); // retorno a menor chave de uma árvore.
void ancestrais (Tree *tree, int x); // imprima todos os ancestrais de uma determinada chave.
// -> Exemplo suponha uma árvore com impressão pré-ordem: 5, 3, 2, 1. Sendo x = 2 imprimiria (2 filho de 3 filho de 5)
int kthmenor(Tree *tree, int k); // retorne a k-ésimo menor chave de uma árvore.
void outono(Tree *tree); // remova todas as folhas de uma árvore.
int quantidadeumfilho (Tree *tree); // retorne a quantidade de nós com apenas um filho.
void nosnivel(Tree *tree, int n); // imprima todos nós de um nível n de uma árvore.