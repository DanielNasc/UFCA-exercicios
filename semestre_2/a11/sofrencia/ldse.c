struct elemento {
    int id;
    struct elemento *prox;
};

typedef struct elemento Elemento;

int sem_repeticao (Lista* ldse, int vlr) {
    if(ldse == NULL || *ldse == NULL) return 0;

    Elemento* aux = *ldse;
    while(aux->id != vlr && aux != NULL) {
        aux = aux->prox;
    }
    if(aux == NULL) return 0;
    else {
        Elemento* novo = (Elemento*)malloc(sizeof(Elemento));
        novo->id = vlr;
        novo->prox = *ldse;
        *ldse = novo;
        return 1;
    }
}
