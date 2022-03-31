#include "matriz.h"
#include <stdio.h>
#include <stdlib.h>

#define LINHAS 3
#define COLUNAS 3

int main() {
  Matriz *matriz = criarMatriz(LINHAS, COLUNAS);

  for (int i = 0; i < LINHAS; i++) {
    for (int j = 0; j < COLUNAS; j++) {
      atribuir(matriz, i, j, i + j);
    }
  }

  printf("Linha 1:\n");
  int *linha = acessarLinha(matriz, 1);
  for (int i = 0; i < LINHAS; i++)
    printf("Elemento %i\n", linha[i]);

  printf("\n\nColuna 1:\n");
  int *coluna = acessarColuna(matriz, 1);
  for (int i = 0; i < COLUNAS; i++)
    printf("Elemento %i\n", coluna[i]);

  printf("\n\nElemento [1][1]: %i\n", acessarValor(matriz, 1, 1));
  printf("Atribuindo valor 32432 a esse elemento...\n");
  atribuir(matriz, 1, 1, 32432);
  printf("Elemento [1][1]: %i\n", acessarValor(matriz, 1, 1));

  printf("\n\nMatriz completa:\n");
  imprimir(matriz);

  destruirMatriz(matriz);
  return 0;
}
