#include <time.h>
#include "fila.h"
#include "tests.h"

#define QTD_ELEMENTOS 10

Fila *criarFilaTeste(uint8_t randomIds);
void testarInverterFila(Fila *f);
void testarLimparFila(Fila *f);
void testarLimparExtremidades(Fila *f);
void testarChecarOrdenada(Fila *f);
void testarMoverElemento(Fila *f, Fila *f2);

void tests() {
    srand(time(NULL));

    Fila *fila = criarFilaTeste(0);

    imprimirFila(fila);
    printf("\n");

    testarInverterFila(fila);
    imprimirFila(fila);
    printf("\n");
    destruirFila(fila);

    printf("Gerando nova fila...\n");
    fila = criarFilaTeste(0);
    printf("Fila gerada com sucesso\n");

    testarLimparFila(fila);
    imprimirFila(fila);
    printf("\n");
    destruirFila(fila);

    printf("Gerando nova fila...\n");
    fila = criarFilaTeste(0);
    printf("Fila gerada com sucesso\n");

    testarLimparExtremidades(fila);
    imprimirFila(fila);
    printf("\n");
    destruirFila(fila);

    printf("Gerando nova fila...\n");
    fila = criarFilaTeste(0);
    printf("Fila gerada com sucesso\n");

    testarChecarOrdenada(fila);
    printf("\n");

    printf("Gerando fila com ids aleatórios...\n");
    Fila *filaAleatoria = criarFilaTeste(1);
    printf("Fila gerada com sucesso\n");
    
    imprimirFila(filaAleatoria);
    testarChecarOrdenada(filaAleatoria);
    printf("\n");

    printf("Testar mover elemento...\n");
    testarMoverElemento(fila, filaAleatoria);
    printf("Fila 1:\n");
    imprimirFila(fila);
    printf("Fila aleatória:\n");
    imprimirFila(filaAleatoria);
    printf("\n");

    printf("Testar mover elemento de fila vazia...\n");
    Fila *filaVazia = criarFila();
    testarMoverElemento(filaVazia, filaAleatoria);
    printf("Fila vazia:\n");
    imprimirFila(filaVazia);
    printf("Fila aleatória:\n");
    imprimirFila(filaAleatoria);
    printf("\n");

    destruirFila(filaVazia);

    printf("Testar mover elemento de uma lista para ela mesma...\n");
    testarMoverElemento(fila, fila);
    imprimirFila(fila);
    printf("\n");

    printf("Testar mover elemento de uma lista para uma lista vazia...\n");
    filaVazia = criarFila();
    testarMoverElemento(fila, filaVazia);
    imprimirFila(filaVazia);

    destruirFila(fila);
    destruirFila(filaAleatoria);

    printf("\n");
    printf("Fim dos testes\n");
}

Fila *criarFilaTeste(uint8_t randomIds) {
    Fila *fila = criarFila();

    if (fila == NULL) {
        printf("Erro ao criar a fila\n");
        exit(1);
    }

    for (int i = 0; i < QTD_ELEMENTOS; i++) {
        Elemento *e = criarElemento(randomIds ? rand() % 100 : i);
        if (!inserirFila(fila, e)) {
            printf("Erro ao inserir o elemento %d\n", i);
            exit(1);
        }
    }

    return fila;
}

void testarInverterFila(Fila *f) {
    printf("Invertendo fila...\n");

    if (inverterFila(f)) 
        printf("Fila invertida com sucesso\n");
    else {
        printf("Erro ao inverter fila\n");
        exit(1);
    }
}

void testarLimparFila(Fila *f) {
    printf("Limpando fila...\n");

    if (limparFila(f))
        printf("Fila limpa com sucesso\n");
    else {
        printf("Erro ao limpar fila\n");
        exit(1);
    }
}

void testarLimparExtremidades(Fila *f) {
    printf("Limpando extremidades...\n");

    if (limparExtremidades(f))
        printf("Fila limpa com sucesso\n");
    else {
        printf("Erro ao limpar extremidades\n");
        exit(1);
    }
}

void testarChecarOrdenada(Fila *f) {
    printf("Checando ordenação...\n");

    printf(checarOrdenada(f) ? "Fila ordenada\n" : "Fila não ordenada\n");
}

void testarMoverElemento(Fila *f, Fila *f2) {
    printf("Movendo elemento...\n");

    int randomIndex = rand() % QTD_ELEMENTOS;

    printf("Indice aleatório: %d\n", randomIndex);

    printf(
        moverElemento(f, f2, randomIndex) ? 
        "Elemento movido com sucesso\n" : 
            "Erro ao mover elemento\n"
    );
}
