#include <inttypes.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct aluno Aluno;
typedef struct elemento Elemento;
typedef struct fila Fila;

Aluno *criarAluno(int, char *);
Elemento *ciarElemento(Aluno *);
Fila *criarFila();
void destruir(Fila *);
int tamanho(Fila *);
uint8_t vazia(Fila *);
uint8_t inserir(Fila *, Aluno *);
uint8_t remover(Fila *);
uint8_t acessar(Fila *, Aluno *);
void imprimir(Fila *);
