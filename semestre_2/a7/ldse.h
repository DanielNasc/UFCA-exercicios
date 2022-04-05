#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>

typedef struct aluno Aluno;
typedef struct elemento Elemento;
typedef Elemento *Lista;

Lista *criarLista();
Aluno *criarAluno(char *nome, int matricula);
Elemento *criarElemento(Aluno *aluno);

int8_t inserirFim(Lista *l, Elemento *novoElemento);
int8_t inserirInicio(Lista *, Elemento *);
int8_t removerInicio(Lista *);
int8_t removerFim(Lista *);
void imprimir(Lista *);
unsigned int tamanho(Lista *);

// pra casa
void destruir(Lista *);
int8_t removerValor(Lista *, int matricula);
int8_t inserirOrdenado(Lista *, Aluno *);
