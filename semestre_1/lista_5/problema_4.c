#include <stdio.h>
#include <locale.h>
#include "get_num.h"

// Faça um programa que receba um número n e preencha um vetor com n números inteiros.
// Em seguida, imprima o vetor na ordem inversa. Ex: n:3, Vetor: [4,76,9]  Ordem de
// Impressão: [9,76,4].

int main()
{
    setlocale(LC_ALL, "Portuguese");
    int n = get_positive_int("o tamanho do vetor");
    int vetor[n], vetor_invertido[n];

    for (int i = 0; i < n; i++)
    {
        printf("Digite o %dº número:\t", i + 1);
        scanf("%d", &vetor[i]);
    }

    for (int i = 0; i < n; i++)
        vetor_invertido[i] = vetor[n - i - 1];

    printf("\nVetor invertido: ( ");
    for (int i = 0; i < n; i++)
        printf("%d ", vetor_invertido[i]);
    printf(")\n");

    return 0;
}
