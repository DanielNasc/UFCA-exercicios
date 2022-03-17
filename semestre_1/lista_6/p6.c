#include <stdio.h>
#include <locale.h>
#include "get_num.h"

// Faça um algoritmo que leia uma matriz m × n e imprima o maior elemento de cada linha
// da matriz.

int main()
{
    setlocale(LC_ALL, "Portuguese");
    int lin = get_positive_int("Digite a quantidade de linhas: "),
        col = get_positive_int("Digite a quantidade de colunas: "),
        matriz[lin][col], maiores[lin];
    
    printf("\n");
    for (int i = 0; i < lin; i++)
    {
        int maior_num_indice = 0;

        for (int j = 0; j < col; j++)
        {
            printf("Digite o elemento da linha %d e coluna %d: ", i + 1, j + 1);
            scanf("%d", &matriz[i][j]);
            if (matriz[i][j] > matriz[i][maior_num_indice])
                maior_num_indice = j;
        }

        maiores[i] = matriz[i][maior_num_indice];
        printf("\n");
    }

    for (int i = 0; i < lin; i++)
        printf("O maior elemento da linha %d é %d\n", i + 1, maiores[i]);

    return 0;
}
