#include "lse.h"

typedef struct elemento {
  int val;
  struct elemento *prox;
} Elemento;

typedef struct info {
  int qtdPares, qtdImpares, qtd;
  Elemento *maior, *menor;
} Informacoes;

typedef struct lista {
  Elemento *primeiro;
} Lista;

Elemento *criarElemento(int val) {
  Elemento *novoElemento = (Elemento *)malloc(sizeof(Elemento));

  if (novoElemento) {
    novoElemento->val = val;
    novoElemento->prox = NULL;
  }

  return novoElemento;
}

Lista *criarLista() {
  Lista *novaLista = (Lista *)malloc(sizeof(Lista));

  if (novaLista) {
    novaLista->primeiro = NULL;
  }

  return novaLista;
}

uint8_t checarSeJaExiste(Lista *l, int val) {
  if (!l)
    return 0;
  Elemento *aux = l->primeiro;

  while (aux) {
    if (aux->val == val) {
      return 1;
    }

    aux = aux->prox;
  }

  return 0;
}

uint8_t inserirInicio(Lista *l, Elemento *e) {
  if (!l || !e)
    return 0;

  if (checarSeJaExiste(l, e->val))
    return 0;

  Elemento *aux = l->primeiro;
  l->primeiro = e;
  e->prox = aux;

  return 1;
}

Informacoes *pegarInformacoes(Lista *l) {
  if (!l)
    return NULL;

  Informacoes *info = (Informacoes *)malloc(sizeof(Informacoes));
  Elemento *aux;

  if (info) {
    info->maior = info->menor = aux = l->primeiro;
    info->qtdPares = info->qtdImpares = 0;

    while (aux) {
      if (aux->val > info->maior->val)
        info->maior = aux;
      else if (aux->val < info->menor->val)
        info->menor = aux;

      (aux->val % 2 == 0) ? info->qtdPares++ : info->qtdImpares++;

      aux = aux->prox;
    }

    info->qtd = info->qtdPares + info->qtdImpares;
  }

  return info;
}

void imprimirInformacoes(Informacoes *info) {
  if (!info)
    return;

  printf("\n================================================\n");
  printf("Valor do maior elemento: %d\n", info->maior->val);
  printf("Valor do menor elemento: %d\n", info->menor->val);
  printf("Quantidade de pares: %d\n", info->qtdPares);
  printf("Quantidade de impares: %d\n", info->qtdImpares);
  printf("Quantidade total: %d\n", info->qtd);
  printf("================================================\n");
}

uint8_t removerDoisInicio(Lista *l) {
  if (!l || pegarInformacoes(l)->qtd < 2)
    return 0;

  Elemento *aux = l->primeiro;
  for (int i = 0; i < 2; i++)
    l->primeiro = l->primeiro->prox;

  free(aux->prox);
  free(aux);

  return 1;
}

uint8_t removerDoisFim(Lista *l) {
  if (!l)
    return 0;

  Informacoes *info = pegarInformacoes(l);
  int qtd = info->qtd;

  if (qtd < 2)
    return 0;
  else if (qtd == 2) {
    free(l->primeiro->prox);
    free(l->primeiro);
    l->primeiro = NULL;
    return 1;
  }

  Elemento *ant = l->primeiro, *aux = ant->prox;

  while (aux->prox->prox) {
    ant = aux;
    aux = aux->prox;
  };

  free(aux->prox);
  free(aux);
  ant->prox = NULL;

  return 1;
}

uint8_t inverter(Lista *l) {
  if (!l)
    return 0;

  Elemento *ant = NULL, *curr = l->primeiro, *prox;

  while (curr) {
    prox = curr->prox;
    curr->prox = ant;
    ant = curr;
    curr = prox;
  }

  l->primeiro = ant;

  return 1;
}

Lista *concatenar(Lista *l1, Lista *l2) {
  if (!l1 || !l2)
    return NULL;

  Lista *l = l1;

  if (!l->primeiro) {
    l->primeiro = l2->primeiro;
  } else {
    Elemento *aux = l->primeiro;

    while (aux->prox) {
      aux = aux->prox;
    }

    aux->prox = l2->primeiro;
  }

  l1 = l2 = NULL;

  return l;
}

Elemento *copiarElementos(Elemento *e) {
  if (e == NULL)
    return NULL;

  Elemento copia = *e, *enderecoCopia = &copia;

  enderecoCopia->prox = copiarElementos(e->prox);
  return enderecoCopia;
}

Lista *copiar(Lista *l) {
  if (l == NULL)
    return NULL;

  Lista *novaLista = criarLista();

  if (novaLista) {
    novaLista->primeiro = copiarElementos(l->primeiro);
  }

  return novaLista;
}

Lista **segmentar(Lista *l, int n) {
  Lista **listas = (Lista **)malloc(sizeof(Lista *) * 2);

  if (listas == NULL || n < 0 || pegarInformacoes(l)->qtd < n)
    return NULL;

  listas[0] = criarLista();
  listas[1] = criarLista();

  if (!listas[0] || !listas[1])
    return NULL;

  Elemento *aux = listas[0]->primeiro = l->primeiro;

  for (int i = 1; i < n; i++)
    aux = aux->prox;

  listas[1]->primeiro = aux->prox;
  aux->prox = NULL;

  return listas;
}

void imprimirLista(Lista *l) {
  if (l == NULL)
    return;

  Elemento *aux = l->primeiro;

  for (int i = 0; aux; i++) {
    printf("[%i] Valor: %i\n", i, aux->val);
    aux = aux->prox;
  }
}
