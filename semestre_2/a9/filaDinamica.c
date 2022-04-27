#include "filaDinamica.h"
#include <stdio.h>

typedef struct aluno {
  int matricula;
  char *nome;
} Aluno;

typedef struct elemento {
  Aluno *al;
  struct elemento *prox;
} Elemento;

typedef struct fila {
  Elemento *primeiro;
  Elemento *ultimo;
} Fila;

Aluno *criarAluno(int matricula, char *nome) {
  Aluno *novoAluno = (Aluno *)malloc(sizeof(Aluno));

  if (novoAluno) {
    novoAluno->matricula = matricula;
    novoAluno->nome = nome;
  }

  return novoAluno;
}

Elemento *criarElemento(Aluno *a) {
  Elemento *novoElemento = (Elemento *)malloc(sizeof(Elemento));

  if (novoElemento) {
    novoElemento->al = a;
    novoElemento->prox = NULL;
  }

  return novoElemento;
}

Fila *criarFila() {
  Fila *novaFila = (Fila *)malloc(sizeof(Fila));

  if (novaFila) {
    novaFila->primeiro = NULL;
    novaFila->ultimo = NULL;
  }

  return novaFila;
}

int tamanho(Fila *f) {
  if (!f || !f->primeiro)
    return 0;

  Elemento *aux = f->primeiro;
  int cont = 1;

  while (aux->prox) {
    aux = aux->prox;
    cont++;
  }

  return cont;
}

uint8_t vazia(Fila *f) { return tamanho(f) == 0 ? 0 : 1; }

uint8_t inserir(Fila *f, Aluno *a) {
  if (!f || !a)
    return 0;

  Elemento *novoElemento = criarElemento(a), *aux = f->ultimo;

  if (!novoElemento)
    return 0;

  if (!f->primeiro) {
    f->primeiro = f->ultimo = novoElemento;
    return 1;
  }

  aux->prox = f->ultimo = novoElemento;

  return 1;
}

uint8_t remover(Fila *f) {
  if (!f || !f->primeiro)
    return 0;

  Elemento *aSerRemovido = f->primeiro;
  f->primeiro = f->primeiro->prox;
  free(aSerRemovido);

  return 1;
}

void imprimir(Fila *f) {
  if (!f || !f->primeiro) {
    printf("Tem nada aqui não man\n");
    return;
  }

  Elemento *aux = f->primeiro;

  while (aux != NULL) {
    printf("NOME: %s\nMATRICULA: %d\n\n\n", aux->al->nome, aux->al->matricula);
    aux = aux->prox;
  }

  printf("TAMANHO: %d\n", tamanho(f));
}
