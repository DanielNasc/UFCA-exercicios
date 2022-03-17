#include <stdio.h>
#include <stdlib.h>
#include "get_num.h"

// Ainda faltam uns 50 minutos para terminar a prova, então vou refazer a questão 4,
// só que agora usando ponteiros.

// Faça um algoritmo que peça para o usuário digitar um inteiro n e uma matriz de inteiros
// n × n. Após isso, crie um vetor de n posições. O elemento i do vetor deve armazenar a
// média da linha i da matriz digitada.

float calcular_media_linha(int * linha, int tamanho);

int main()
{
    int n = get_positive_int("Digite um número inteiro n para o programa criar uma matriz nxn: "),
        **matriz = (int **) malloc(n * sizeof(int *));

    float * medias = (float *) malloc(n * sizeof(float));

    printf("\nPreencha a matriz ======================\n");
    for (int i = 0; i < n; i++)
    {
        *(matriz + i) = (int *) malloc(n * sizeof(int));

        for (int j = 0; j < n; j++)
        {
            printf("Digite o valor da posição [%d][%d] na matriz: ", i, j);
            scanf("%i", *(matriz + i) + j);
        }
        printf("\n");
    }
        
    printf("Médias das linhas ======================\n\n");
    for (int i = 0; i < n; i++){
        *(medias + i) = calcular_media_linha(*(matriz + i), n);
        printf("A média da linha %d é %.2f\n", i, *(medias + i));
    }

    for (int i = 0; i < n; i++)
        free(*(matriz + i));
    free(matriz);
    free(medias);

    return 0;
}

// Calcula a média de uma linha da matriz
float calcular_media_linha(int * linha, int tamanho)
{
    float media = 0;

    for (int i = 0; i < tamanho; i++)
        media += *(linha + i);

    return media / tamanho;
}