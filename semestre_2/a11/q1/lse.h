#include <inttypes.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct elemento Elemento;
typedef struct info Informacoes;
typedef struct lista Lista;

Elemento *criarElemento(int);
Lista *criarLista();

uint8_t checarSeJaExiste(Lista *, int);

// a) Inserir sem repetição no início. Isto é, ao tentar inserir algo com
// id/matrícula/código (escolha um) à algum já existe na lista, não permitir.
uint8_t inserirInicio(Lista *, Elemento *);
// b) Informações. Dizer quantos impares, pares, maior e menor valor de uma
//  lista.
Informacoes *pegarInformacoes(Lista *);
void imprimirInformacoes(Informacoes *);
// c) Remover dois do início. Em vez de remover apenas o 1º, remove o 1º e 2º.
uint8_t removerDoisInicio(Lista *);
// d) Remover dois do fim. Em vez de remover apenas o último, remove o último e
// penultimo.
uint8_t removerDoisFim(Lista *);
// e) Inverter. Use manipulação de ponteiros, não crie uma lista nova.
uint8_t inverter(Lista *);
// f) Concatenar. Gere uma terceira lista e esvazie as outras duas.
Lista *concatenar(Lista *, Lista *);
// g) Cópia. Faça uma funçao que gere uma cópia de uma lista.
Lista *copiar(Lista *);
// h) Segmentar. Dado um inteiro n, divida a lista em duas, uma do primeiro
// elemento até n e outra de n em diante.
Lista **segmentar(Lista *, int);

void imprimirLista(Lista *);
