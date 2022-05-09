#include <inttypes.h>

typedef struct elemento Elemento;
typedef Elemento *Pilha;

Elemento *criar_elemento(int valor);
Pilha *criar_pilha();

int8_t inserir(Pilha *, int);

// a) Fundo. Acesse o elemento no fundo da pilha.
Elemento *fundo(Pilha *pilha);
// b) Aglutinar. Dado um inteiro n, "junte" os n primeiros elementos 
// de uma pilha somando seus valores (pilha de inteiros simples, ou faça isso usando apenas o campo 
// id/matrícula/código).
int8_t aglutinar(Pilha *pilha, int n);

// c) Inverter. Use uma segunda pilha para realizar a inversão.
int8_t inverter(Pilha *pilha);

// d) Mover. Faça uma função que permita você mover um elemento de uma pilha para outra pilha.
int8_t mover(Pilha *pilha1, Pilha *pilha2, int id);