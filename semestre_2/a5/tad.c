#include <stdio.h>
#include <stdlib.h>

#include "tad.h"

typedef struct tad {
  unsigned qtd, max;
  int *vetor;
} Tad;

Tad *criar(unsigned int max) {
  Tad *novoTad = (Tad *)malloc(sizeof(Tad));

  if (novoTad) {
    novoTad->qtd = 0;
    novoTad->max = max;
    novoTad->vetor = (int *)malloc(sizeof(int) * max);
  }

  return novoTad;
}

bool destruir(Tad *tad) {
  if (!tad)
    return false;

  free(tad->vetor);
  free(tad);
  return true;
}

bool inserir(Tad *t, int novoValor) {
  if (t->max == t->qtd)
    return false;

  t->vetor[t->qtd] = novoValor;
  t->qtd++;

  return true;
}

void imprimir(Tad *t) {
  printf("Qtd: %d\n", t->qtd);
  printf("Max: %d\n", t->max);

  printf("Vetor:\n[");
  for (int i = 0; i < t->qtd; i++) {
    printf(" %i", t->vetor[i]);
  }
  printf(" ]\n");
}

bool pop(Tad *t) {
  if (!t || t->qtd < 1)
    return false;

  t->qtd--;
  return true;;
}

bool verSeExiste(Tad *t, int n) {
  for (int i = 0; i < t->qtd; i++)
    if (t->vetor[i] == n)
      return true;
  return false;
}

int pegarQuantidade(Tad *t) {
  if (!t)
    return -1;

  return t->qtd;
}

bool shift(Tad *t) {
  if (!t || t->qtd == 0)
    return false;

  for (int i = 1; i < t->qtd; i++)
    t->vetor[i - 1] = t->vetor[i];
  t->qtd--;

  return true;
}

bool inserirInicio(Tad *t, int valor) {
  if (!t)
    return false;

  // shift para a direita
  for (int i = t->qtd - 1; i > 0; i--)
    t->vetor[i] = t->vetor[i - 1];
  
  t->vetor[0] = valor;

  return true;
}

bool removerIndice(Tad *t, int indice) {
  if (!t || indice < 0 || indice >= t->qtd)
    return false;

  // shift para a esquerda
  for (int i = indice; i < t->qtd - 1; i++)
    t->vetor[i] = t->vetor[i + 1];

  t->qtd--;

  return true;
}

bool inverter(Tad * t) {
  if (!t || t->qtd < 2)
    return false;

  for (int i = 0; i < t->qtd / 2; i++) {
    int aux = t->vetor[i];
    t->vetor[i] = t->vetor[t->qtd - i - 1];
    t->vetor[t->qtd - i - 1] = aux;
  }

  return true;
}

bool concatenar(Tad *t1, Tad *t2) {
  if (!t1 || !t2)
    return false;
  
  printf("Concatenando...\n");
  for (int i = 0; i < t2->qtd; i++) {
    if (!inserir(t1, t2->vetor[i]))
      break;
  }

  return true;
}

bool removerValor(Tad *t, int valor) {
  if (!t)
    return false;
  
  for (int i = 0; i < t->qtd; i++)
    if (t->vetor[i] == valor) {
      removerIndice(t, i);
      return true;
    }

  return false;
}