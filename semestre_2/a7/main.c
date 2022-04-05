#include "ldse.h"

void tests();

int main() {
  tests();
  return 0;
}

void tests() {
  Lista *l = criarLista();
  char *nome = "FOO";

  for (int i = 0; i < 3; i++) {
    Aluno *a = criarAluno(nome, (i + 1) * 101);
    Elemento *e = criarElemento(a);
    inserirFim(l, e);
  }

  for (int i = 0; i < 4; i++) {
    Aluno *a = criarAluno(nome, (i + 1) * 102);
    Elemento *e = criarElemento(a);
    inserirInicio(l, e);
  }

  imprimir(l);

  printf("\n\nTamanho: %d\n\n\n", tamanho(l));

  removerInicio(l);
  removerValor(l, 204);
  removerFim(l);
  imprimir(l);
  printf("\n\nTamanho: %d\n", tamanho(l));


  destruir(l);

  // NULL ==========
  printf("\n\nTestando NULL\n");
  inserirInicio(NULL, NULL);
  inserirOrdenado(NULL, NULL);
  inserirFim(NULL, NULL);
  removerInicio(NULL);
  removerValor(NULL, 0);
  removerFim(NULL);
  imprimir(NULL);
  tamanho(NULL);
  destruir(NULL);

  printf("OK\n");

  // ORDENADO ======
  printf("\n\nTestando ORDENADO\n");
  l = criarLista();
  nome = "FOO";

  for (int i = 0; i < 3; i++) {
    Aluno *a = criarAluno(nome, (i + 1) * 101);
    inserirOrdenado(l, a);
  }

  Aluno *a = criarAluno(nome, 222);
  inserirOrdenado(l, a);

  imprimir(l);
  destruir(l);

  printf("OK\n");
}
