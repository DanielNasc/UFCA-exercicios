#include <stdio.h>
#include "get_num.h"

// Faça um algoritmo que peça para o usuário digitar um inteiro n e uma matriz de inteiros
// n × n. Após isso, crie um vetor de n posições. O elemento i do vetor deve armazenar a
// média da linha i da matriz digitada. (2,5)

float calcular_media_linha(int linha[], int n);

int main()
{
    int n = get_positive_int("Digite um número inteiro n para o programa criar uma matriz nxn: "),
        matriz[n][n];

    float vetor[n];

    printf("\nPreencha a matriz ======================\n");
    for (int i = 0; i < n; i++)
    {
        printf("\n");
        for (int j = 0; j < n; j++)
        {
            printf("Digite o elemento [%d][%d] da matriz: ", i, j);
            scanf("%d", &matriz[i][j]);
        }
    }

    printf("\nMédias das linhas ======================\n\n");
    for (int i = 0; i < n; i++)
    {
        vetor[i] = calcular_media_linha(matriz[i], n);
        printf("Média da linha %d: %.2f\n", i, vetor[i]);
    }

    return 0;
}

// Calcula a média de uma linha da matriz
float calcular_media_linha(int linha[], int n)
{
    float soma = 0;
    for (int i = 0; i < n; i++)
        soma += linha[i];
    return soma / n;
}