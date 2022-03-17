#include <stdio.h>
#include <locale.h>
#include "get_num.h"

// Faça um programa que receba um número n e preencha um vetor com n números inteiros.
// Em seguida, verique e informe se o vetor está em ordem crescente, decrescente, ou se ele
// não satisfaz nenhuma estas condições.

int main()
{
    setlocale(LC_ALL, "Portuguese");
    int n = get_positive_int("o tamanho do vetor"), cre = 1, dec = 1;
    int vetor[n];

    for (int i = 0; i < n; i++)
    {
        printf("Digite o %dº número: ", i + 1);
        scanf("%d", &vetor[i]);
    }

    // Verifica se o vetor está em ordem crescente ou decrescente
    for (int i = 0; i < n - 1; i++)
    {
        if (vetor[i] > vetor[i + 1])
            cre = 0;
        if (vetor[i] < vetor[i + 1])
            dec = 0;
        if ( (cre == 0) && (dec == 0) )
            break;
    }

    printf("\n");

    // Imprime se o vetor está em ordem crescente, decrescente ou nenhuma
    if (cre == 1)
        printf("O vetor está em ordem crescente.\n");
    else if (dec == 1)
        printf("O vetor está em ordem decrescente.\n");
    else
        printf("O vetor não satisfaz nenhuma das condições.\n");

    return 0;
}
