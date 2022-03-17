#include <stdio.h>
#include <locale.h>
#include "get_num.h"

// Faça um algoritmo que leia um vetor de n posições e calcule a média dos elementos do
// vetor.

int main()
{
    setlocale(LC_ALL, "Portuguese");

    int n = get_positive_int("Digite o tamanho de um vetor:\t");
    int vetor[n];

    printf("\n");
    for (int i = 0; i < n; i++)
    {
        printf("Digite o %dº elemento do vetor:\t", i + 1);
        scanf("%d", &vetor[i]);
    }

    int soma = 0;

    for (int i = 0; i < n; i++)
        soma += vetor[i];

    float media = (float) soma / n;

    printf("\nA média dos elementos do vetor é: %.2f\n", media);

    return 0;
}
