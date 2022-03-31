#include "matriz.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct matriz {
  int linhas;
  int colunas;
  int **valores;
} Matriz;

Matriz *criarMatriz(int l, int c) {
  Matriz *m = (Matriz *)malloc(sizeof(Matriz));
  if (m == NULL)
    exit(1);

  int **val = (int **)malloc(sizeof(int *) * l);
  for (int i = 0; i < c; i++) {
    *(val + i) = (int *)malloc(sizeof(int) * c);
  }

  m->linhas = l;
  m->colunas = c;
  m->valores = val;

  return m;
}

void destruirMatriz(Matriz *m) {
  for (int i = 0; i < m->linhas; i++) {
    free(m->valores[i]);
  }
  free(m->valores);
  free(m);
}

int acessarValor(Matriz *matriz, int l, int c) { return matriz->valores[l][c]; }

int *acessarColuna(Matriz *matriz, int c) {
  int *coluna = (int *)malloc(sizeof(int) * matriz->linhas);

  for (int i = 0; i < matriz->linhas; i++) {
    coluna[i] = matriz->valores[i][c];
  }

  return coluna;
}

int *acessarLinha(Matriz *matriz, int l) {
  int *linha = (int *)malloc(sizeof(int) * matriz->colunas);

  for (int i = 0; i < matriz->colunas; i++) {
    linha[i] = matriz->valores[l][i];
  }

  return linha;
}

void atribuir(Matriz *matriz, int l, int c, int val) {
  matriz->valores[l][c] = val;
}

void imprimir(Matriz *m) {
  printf("Quantidades de linhas da matriz: %i\n", m->linhas);
  printf("Quantidades de colunas da matriz: %i\n", m->colunas);
  printf("\n\n");

  for (int i = 0; i < m->linhas; i++)
    for (int j = 0; j < m->colunas; j++)
      printf("Elemento [%i][%i] da matriz: %i\n", i, j, m->valores[i][j]);
}
