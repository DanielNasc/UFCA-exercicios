#include <stdio.h>
#include <locale.h>
#include "get_num.h"

// Faça um programa que leia uma matriz 4 × 4 de números inteiros e execute as seguintes
// tarefas:
// (a) Imprima a soma dos elementos que estão em colunas ímpares.
// (b) Imprima a média dos elementos que estão em colunas pares;

int main()
{
    setlocale(LC_ALL, "Portuguese");

    int matriz[4][4], soma_impares = 0, soma_pares = 0;

    for (int i = 0; i < 4; i++)
    {
        printf("\n");
        for (int j = 0; j < 4; j++)
        {
            printf("Digite o valor da posição [%d][%d]: ", i, j);
            scanf("%d", &matriz[i][j]);

            if(j % 2 == 0)
                soma_pares += matriz[i][j];
            else
                soma_impares += matriz[i][j];
        }
    }

    printf("\nSoma dos elementos que estão em colunas ímpares: %d\n", soma_impares);
    printf("Média dos elementos que estão em colunas pares: %.2f\n", (float)soma_pares / 4);

    return 0;
}
