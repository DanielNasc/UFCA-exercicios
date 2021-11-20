#include <stdio.h>
#include <malloc.h>
#include <locale.h>
#include "get_num.h"

// Crie dois vetores a e b de tamanho n. Crie e imprima um vetor c, de tal forma que
// c[i] = a[i] − b[i] para todo i inteiro pertencente ao intervalo [0, n − 1].

void preencher_vetor(int *vetor[], int n, char v);

int main()
{
    setlocale(LC_ALL, "Portuguese");
    
    // Inicialização de variáveis
    int n = get_positive_int("Digite o tamanho do vetor:\t");
    int *a[n], *b[n], c[n];

    // Preenchimento de vetores a partir de seus respectivos ponteiros
    preencher_vetor(a, n, 'a');
    preencher_vetor(b, n, 'b');

    for (int i = 0; i < n; i++){
        // Cálculo de c
        c[i] = *a[i] - *b[i];

        // liberação de memória por causa do malloc
        free(a[i]); free(b[i]);
    }

    // Impressão de c
    printf("\n================== Vetor c ==================\n(");
    for (int i = 0; i < n; i++)
        printf(" %d ", c[i]);
    printf(")\n");

    return 0;
}

void preencher_vetor(int *vetor[], int n, char v)
{
    printf("\n================== Vetor %c ==================\n", v);

    for (int i = 0; i < n; i++)
    {
        vetor[i] = malloc(sizeof(int));
        printf("Digite o valor do elemento %d do vetor %d:\t", i + 1, n);
        scanf("%d", vetor[i]);
    }
}