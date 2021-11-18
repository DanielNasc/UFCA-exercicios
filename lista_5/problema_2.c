#include <stdio.h>
#include <locale.h>
#include "get_num.h"

// Faça um programa que recebe 10 números inteiros e os armazene em um vetor. Calcule
// e mostre:
// (a) A quantidade de números pares.
// (b) A soma dos números pares.
// (c) A quantidade de números ímpares.
// (d) A soma dos números ímpares.

int main()
{
    setlocale(LC_ALL, "Portuguese");

    // Declaração de variáveis
    int num[10], par = 0, impar = 0, soma_par = 0, soma_impar = 0;

    for (int i = 0; i < 10; i++)
    {
        printf("Digite o %dº número:\t", i + 1);
        scanf("%d", &num[i]);

        // Verifica se o número é par ou ímpar
        if (num[i] % 2 == 0)
        {
            par++;
            soma_par += num[i];
        }
        else
        {
            impar++;
            soma_impar += num[i];
        }
    }

    printf("\nQuantidade de números pares: %d\n", par);
    printf("Soma dos números pares: %d\n", soma_par);
    printf("Quantidade de números ímpares: %d\n", impar);
    printf("Soma dos números ímpares: %d\n", soma_impar);

    return 0;
}
