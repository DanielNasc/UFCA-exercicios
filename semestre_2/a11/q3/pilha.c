#include <stdlib.h>
#include "pilha.h"

typedef struct elemento {
    int val;
    struct elemento *prox;
} Elemento;

Elemento *criar_elemento(int val) {
    Elemento *e = (Elemento *) malloc(sizeof(Elemento));
    if (e != NULL) {
        e->val = val;
        e->prox = NULL;
    }

    return e;
}

Pilha *criar_pilha() {
    Pilha *p = (Pilha *) malloc(sizeof(Pilha));

    if (p != NULL) *p = NULL;

    return p;    
}

int8_t inserir(Pilha *p, int val) {
    Elemento *e = criar_elemento(val);

    if (e == NULL) return 0;

    e->prox = *p;
    *p = e;

    return 1;
}

Elemento *fundo(Pilha *pilha) {
    if (pilha == NULL || *pilha == NULL) return NULL;

    Elemento *aux = *pilha;

    while (aux->prox != NULL) {
        aux = aux->prox;
    }

    return aux;
}

int qtd_elementos(Pilha *pilha) {
    if (pilha == NULL|| *pilha == NULL) return 0;

    int qtd = 0;

    Elemento *aux = *pilha;

    while (aux != NULL) {
        qtd++;
        aux = aux->prox;
    }

    return qtd;
}

int8_t aglutinar(Pilha *pilha, int n) {
    if (pilha == NULL 
        || *pilha == NULL 
        || qtd_elementos(pilha) < n) 
        return 0;

    Elemento *aux = *pilha, *ant = NULL;

    while (n != 0) {
        aux->prox->val += aux->val;
        ant = aux;
        aux = aux->prox;
        n--;
        free(ant);
    }

    *pilha = aux;

    return 1;
}

int8_t inverter(Pilha *pilha) {
    if (pilha == NULL || *pilha == NULL) return 0;

    Elemento *aux = *pilha, *ant = NULL, *prox = NULL;

    while (aux != NULL) {
        prox = aux->prox;
        aux->prox = ant;
        ant = aux;
        aux = prox;
    }

    *pilha = ant;

    return 1;
}

int8_t mover(Pilha *pilha1, Pilha *pilha2, int id) {
    if (pilha1 == NULL || *pilha1 == NULL || pilha2 == NULL || *pilha2 == NULL) return 0;

    Elemento *aux = *pilha1, *ant = NULL;

    while (aux->val != id && aux != NULL) {
        ant = aux;
        aux = aux->prox;
    }

    if (aux == NULL) return 0;

    if (ant == NULL) {
        *pilha1 = aux->prox;
    } else {
        ant->prox = aux->prox;
    }

    aux->prox = *pilha2;
    *pilha2 = aux;

    return 1;
}