#include <inttypes.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct elemento Elemento;
typedef struct fila Fila;

Fila *criarFila();
Elemento *criarElemento(int valor);

uint8_t inserirFila(Fila *f, Elemento *e);
void imprimirFila(Fila *f);
void destruirFila(Fila *f);

// a) Inverter. Use manipulação de ponteiros, não crie uma fila nova.
uint8_t inverterFila(Fila *f);

// b) Limpeza central. Remova tudo da fila, exceto o primeiro e o último elemento.
uint8_t limparFila(Fila *f);

// c) Limpeza extremidades. Remova o primeiro e o último elemento da fila.
uint8_t limparExtremidades(Fila *f);

// d) Ordenada. Função verifica se fila está ordenada (por id/matrícula/código).
uint8_t checarOrdenada(Fila *f);

// e) Mover. Faça uma função que permita você mover um elemento de uma fila para outra fila.
uint8_t moverElemento(Fila *f1, Fila *f2, int id);