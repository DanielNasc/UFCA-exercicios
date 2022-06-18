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