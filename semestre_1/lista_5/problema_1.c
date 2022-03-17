#include <stdio.h>
#include <string.h>
#include <limits.h>
#include "get_num.h"

// Faça um programa que preencha um vetor com 10 números. Depois, imprima o vetor
// preenchido e informe o menor valor do vetor.

int main()
{
    // Declaração de variáveis
    int vetor[10], menor = INT_MAX;

    // Preenchendo o vetor
    for (int i = 0; i < 10; i++)
    {
        printf("Digite o %iº número:\t", i + 1);
        scanf("%d", &vetor[i]);
        if (vetor[i] < menor) menor = vetor[i];
    }

    // Imprimindo o vetor
    printf("\nVetor: [ ");
    for (int i = 0; i < 10; i++)
        printf("%d ", vetor[i]);

    printf("]\n");

    // Imprimindo o menor valor
    printf("\nO menor número desse vetor é: %i\n", menor);

    return 0;
}
