#include "lse.h"

#define QTD_ELEMENTOS 100

void testes();

int main() {
  testes();
  return 0;
}

void testes() {
  Lista *lista = criarLista();

  if (lista == NULL) {
    printf("Erro ao criar a lista\n");
    exit(1);
  }

  for (int i = 0; i < QTD_ELEMENTOS; i++) {
    Elemento *elemento = criarElemento(i);

    if (elemento == NULL) {
      printf("Erro ao criar um elemento\n");
      exit(1);
    }

    inserirInicio(lista, elemento);
  }

  printf("Imprimindo informacoes da lista \n");
  imprimirInformacoes(pegarInformacoes(lista));
  imprimirLista(lista);

  printf("Invertendo Lista...\n");
  if (!inverter(lista)) {
    printf("Erro ao inverter a lista\n");
    exit(1);
  }
  printf("Imprimindo informacoes da lista invertida\n");
  imprimirInformacoes(pegarInformacoes(lista));
  imprimirLista(lista);

  printf(
      "\nTentando dividir a lista em duas em um indice maior que a quantidade "
      "de elementos...\n");
  if (!segmentar(lista, QTD_ELEMENTOS + 1))
    printf("OK\n");
  else {
    printf("Erro\n");
    exit(1);
  }

  printf("Tentando remover dois elementos do inicio...\n");
  if (removerDoisInicio(lista))
    printf("OK\n");
  else {
    printf("ERRO\n");
    exit(1);
  }

  printf("Tentando remover dois elementos do fim...\n");
  if (removerDoisFim(lista))
    printf("OK\n");
  else {
    printf("ERRO\n");
    exit(1);
  }

  printf("Imprimindo informacoes da lista \n");
  imprimirInformacoes(pegarInformacoes(lista));
  imprimirLista(lista);

  printf("\nDividindo a lista em duas...\n");

  int n;
  printf("Digite o indice em que você quer que a lista seja dividida "
         "(Quantidade maxima = %d): ",
         QTD_ELEMENTOS - 4);
  scanf("%i", &n);

  Lista **listasDivididas = segmentar(lista, n);

  if (listasDivididas == NULL) {
    printf("Erro ao dividir a lista\n");
    exit(1);
  };

  printf("\nImprimindo informacoes da lista 1\n");
  imprimirInformacoes(pegarInformacoes(listasDivididas[0]));
  imprimirLista(listasDivididas[0]);

  printf("\nImprimindo informacoes da lista 2\n");
  imprimirInformacoes(pegarInformacoes(listasDivididas[1]));
  imprimirLista(listasDivididas[1]);

  printf("Concatenando listas...\n");
  lista = concatenar(listasDivididas[0], listasDivididas[1]);

  if (!lista) {
    printf("Erro ao concatenar listas\n");
    exit(1);
  }

  printf("Imprimindo informacoes da lista\n");
  imprimirInformacoes(pegarInformacoes(lista));
  imprimirLista(lista);
}
