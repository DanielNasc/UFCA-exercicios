#include "ldse.h"

typedef struct aluno {
  int matricula;
  char *nome;
} Aluno;

typedef struct elemento {
  Aluno *al;
  struct elemento *prox;
} Elemento;

typedef Elemento *Lista;

Lista *criarLista() {
  Lista *ldse = (Lista *)malloc(sizeof(Lista));

  if (ldse != NULL)
    *ldse = NULL;

  return ldse;
}

Aluno *criarAluno(char *nome, int matricula) {
  Aluno *novoAluno = (Aluno *)malloc(sizeof(Aluno));

  if (novoAluno != NULL) {
    novoAluno->matricula = matricula;
    novoAluno->nome = nome;
  }
  return novoAluno;
}

Elemento *criarElemento(Aluno *aluno) {
  if (!aluno)
    return NULL;

  Elemento *novoElemento = (Elemento *)malloc(sizeof(Elemento));
  novoElemento->al = aluno;
  novoElemento->prox = NULL;
  return novoElemento;
}

int8_t inserirInicio(Lista *l, Elemento *novoElemento) {
  if (!l || !novoElemento)
    return 0;

  if (!*l) {
    *l = novoElemento;
    return 1;
  }

  novoElemento->prox = *l;
  *l = novoElemento;
  return 1;
}

int8_t inserirOrdenado(Lista *l, Aluno *al) {
  if (!l || !al)
    return 0;
  
  Elemento *novoElemento = criarElemento(al);
  if (!novoElemento)
    return 0;

  if (!*l) {
    *l = novoElemento;
    return 1;
  }

  Elemento *aux = *l;
  Elemento *ant = NULL;

  while (aux && aux->al->matricula < al->matricula) {
    ant = aux;
    aux = aux->prox;
  }

  if (!aux) {
    ant->prox = novoElemento;
    return 1;
  }

  novoElemento->prox = aux;
  if (ant)
    ant->prox = novoElemento;
  else
    *l = novoElemento;
}

int8_t inserirFim(Lista *l, Elemento *novoElemento) {
  if (!l || !novoElemento)
    return 0;

  Elemento *aux = *l;

  if (!aux) {
    *l = novoElemento;
    return 1;
  }

  while (aux->prox != NULL) {
    aux = aux->prox;
  }
  aux->prox = novoElemento;
  return 1;
}

int8_t removerInicio(Lista *l) {
  if (!l || !*l)
    return 0;

  Elemento *aSerRemovido = *l;
  *l = aSerRemovido->prox;
  free(aSerRemovido);
  return 1;
}

int8_t removerValor(Lista *l, int matricula) {
  if (!l)
    return 0;

  Elemento *aux = *l;

  if (aux->al->matricula == matricula) {
    *l = aux->prox;
    free(aux);
    return 1;
  }

  while (aux->prox != NULL) {
    if (aux->prox->al->matricula == matricula) {
      Elemento *aSerRemovido = aux->prox;
      aux->prox = aSerRemovido->prox;
      free(aSerRemovido);
      return 1;
    }
    aux = aux->prox;
  }

  return 0;
} 

int8_t removerFim(Lista *l) {
  if (!l || !*l)
    return 0;

  if (tamanho(l) == 1) {
    free(*l);
    *l = NULL;
    return 1;
  }

  Elemento *penultimo = *l;
  while (penultimo->prox->prox != NULL) {
    penultimo = penultimo->prox;
  }

  free(penultimo->prox);
  penultimo->prox = NULL;
  return 1;
}

void imprimir(Lista *l) {
  if (!l)
    return;

  Elemento *aux = *l;

  while (aux != NULL) {
    printf("Aluno: %s | Matricula: %i\n", aux->al->nome, aux->al->matricula);

    aux = aux->prox;
  }
}

unsigned int tamanho(Lista *l) {
  if (!l)
    return 0;

  int tam = 0;

  for (Elemento *aux = *l; aux != NULL; aux = aux->prox)
    tam++;

  return tam;
}

void destruir(Lista *l) {
  if (!l)
    return;

  Elemento *aux = *l;

  while (aux != NULL) {
    Elemento *aSerRemovido = aux;
    aux = aux->prox;
    free(aSerRemovido);
  }

  *l = NULL;
}