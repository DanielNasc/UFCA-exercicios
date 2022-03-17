#include <stdio.h>
#include <stdlib.h>

/*
Faça um algoritmo que receba um inteiro n e crie um vetor inteiro de n posições. Peça
para o usuário preencher o vetor. Após isso, inverta os elementos do vetor e imprima ele.
Por exemplo o vetor [5,3,6,2] deverá ficar [2,6,3,5]. É importante que o vetor seja alterado
na memória.
*/

void inverter(int *vetor, int tamanho)
{
    int a;
    for (int i = 0; i < tamanho / 2; i++)
    {
        a = vetor[i];
        vetor[i] = vetor[tamanho - 1 - i];
        vetor[tamanho - 1 - i] = a;
    }
}

int main()
{
    int n;

    printf("n: ");
    scanf("%d", &n);

    int *vetor = (int *) malloc(sizeof(int) * n);

    printf("\n");
    for (int i = 0; i < n; i++)
    {
        printf("vetor[%d]: ", i);
        scanf("%d", &vetor[i]);
    }

    inverter(vetor, n);

    printf("\n[ ");
    for (int i = 0; i < n; i++)
        printf("%d ", vetor[i]);
    printf("]\n");

    free(vetor);
    return 0;
}