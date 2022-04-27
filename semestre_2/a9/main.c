#include "filaDinamica.h"
#include <stdio.h>

#define QTD_ALUNOS 5

void testes();

int main() {
  testes();
  return 0;
}

void testes() {
  char *nomeTest = "TEST";
  Fila *fila = criarFila();

  for (int i = 0; i < QTD_ALUNOS; i++) {
    Aluno *novoAluno = criarAluno(0xA << (2 + i), nomeTest);

    inserir(fila, novoAluno);
  }

  imprimir(fila);

  printf("\n================\n\n");

  remover(fila);
  imprimir(fila);

  printf("\n================\n\n");

  inserir(fila, criarAluno(121221212, nomeTest));
  imprimir(fila);
}
