#include <stdio.h>

#include "tad.h"

int main() {
  Tad *d = criar(3);

  inserir(d, 2);
  inserir(d, 24322);
  inserir(d, 222);

  if (!inserir(d, 232))
    printf("ijfowjf3r\n");

  imprimir(d);
  inserirInicio(d, 23);
  imprimir(d);

  imprimir(d);
  printf(verSeExiste(d, 24322) ? "Existe\n" : "Não existe\n");
  pop(d);
  printf(verSeExiste(d, 24322) ? "Existe\n" : "Não existe\n");

  imprimir(d);
  shift(d);
  imprimir(d);

  inserir(d, 23);
  inserir(d, 12313);
  imprimir(d);

  removerIndice(d, 1);
  imprimir(d);
  inverter(d);
  imprimir(d);
  
  pop(d);

  Tad * d2 = criar(3);
  inserir(d2, 2);
  inserir(d2, 24322);
  inserir(d2, 222);
  imprimir(d2);

  concatenar(d, d2);
  imprimir(d);

  removerValor(d, 2);
  imprimir(d);

  destruir(d);


  Tad * t = criar(5);

  inserirOrdenado(t, 2);
  inserirOrdenado(t, 5);
  inserirOrdenado(t, 24);
  inserirOrdenado(t, 23);

  imprimir(t);

  destruir(t);

  return 0;
}
