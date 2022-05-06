#include "fila.h"

typedef struct elemento {
    int id;
    struct elemento *prox;
} Elemento;

typedef struct fila {
    Elemento *inicio;
    Elemento *fim;
} Fila;

Fila *criarFila() {
    Fila *f = (Fila *) malloc(sizeof(Fila));
    
    if (f != NULL) {
        f->inicio = NULL;
        f->fim = NULL;
    }

    return f;
}

Elemento *criarElemento(int id) {
    Elemento *e = (Elemento *) malloc(sizeof(Elemento));

    if (e != NULL) {
        e->id = id;
        e->prox = NULL;
    }

    return e;   
}

uint8_t inserirFila(Fila *f, Elemento *e) {
    if (f == NULL || e == NULL) {
        return 0;
    }

    if (f->inicio == NULL) {
        f->inicio = e;
        f->fim = e;
    } else {
        f->fim->prox = e;
        f->fim = e;
    }

    return 1;
}

uint8_t inverterFila(Fila *f) {
    if (f == NULL) {
        return 0;
    }

    Elemento *aux = f->inicio;
    Elemento *ant = NULL;

    while (aux != NULL) {
        Elemento *prox = aux->prox;
        aux->prox = ant;
        ant = aux;
        aux = prox;
    }

    f->fim = f->inicio;
    f->inicio = ant;

    return 1;
}

uint8_t limparFila(Fila *f) {
    if (f == NULL || f->inicio == NULL) {
        return 0;
    }

    Elemento *aux = f->inicio->prox;

    while(aux->id != f->fim->id) {
        Elemento *prox = aux->prox;
        free(aux);
        aux = prox;
    }

    f->inicio->prox = f->fim;

    return 1;
}

uint8_t limparExtremidades(Fila *f) {
    if (f == NULL || f->inicio == NULL) {
        return 0;
    }

    Elemento *aux = f->inicio;
    f->inicio = f->inicio->prox;
    free(aux);

    aux = f->inicio;
    while (aux->prox->id != f->fim->id) {
        aux = aux->prox;
    }
    free(aux->prox);
    aux->prox = NULL;

    return 1;
}

uint8_t checarOrdenada(Fila *f) {
    if (f == NULL || f->inicio == NULL) {
        return 0;
    }

    Elemento *aux = f->inicio;

    while (aux->prox != NULL) {
        if (aux->id > aux->prox->id) {
            return 0;
        }
        aux = aux->prox;
    }

    return 1;
}

uint8_t moverElemento(Fila *f1, Fila *f2, int id) {
    if (f1 == NULL || 
        f2 == NULL || 
        f1->inicio == NULL
    ) {
        return 0;
    }

    Elemento *aux = NULL;

    if (f1->inicio->id == id) {
        aux = f1->inicio;
        f1->inicio = f1->inicio->prox;
    } else {
        Elemento *ant = f1->inicio;
        aux = ant->prox;

        while (aux != NULL && aux->id != id) {
            ant = aux;
            aux = aux->prox;
        }

        if (aux == NULL) {
            printf("Elemento não encontrado.\n");
            return 0;
        }

        ant->prox = aux->prox;
    }
        aux->prox = NULL;
        inserirFila(f2, aux);

    return 1;
}

unsigned int tamanhoFila(Fila *f) {
    if (f == NULL || f->inicio == NULL) {
        return 0;
    }

    Elemento *aux = f->inicio;
    unsigned int tamanho = 0;

    while (aux != NULL) {
        tamanho++;
        aux = aux->prox;
    }

    return tamanho;
}

void imprimirFila(Fila *f) {
    if (f == NULL) {
        return;
    }

    printf("Tamanho da fila: %d\n", tamanhoFila(f));
    Elemento *aux = f->inicio;
    
    while (aux != NULL) {
        printf("[ %d ] -> ", aux->id);
        aux = aux->prox;
    }

    printf("NULL\n");
}

void destruirFila(Fila *f) {
    if (f == NULL) {
        return;
    }

    Elemento *aux = f->inicio;

    while (aux != NULL) {
        Elemento *prox = aux->prox;

        free(aux);
        aux = prox;
    }
}