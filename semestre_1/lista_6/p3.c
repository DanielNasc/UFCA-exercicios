#include <stdio.h>
#include <locale.h>
#include <malloc.h>
#include "get_num.h"

// Faça um programa que leia duas matrizes a e b de dimensões n × n. Imprima a matriz c
// de tal forma que c = a + b.

void preencher_matriz(int n, int *matriz[][n], char m_id);

int main()
{
    setlocale(LC_ALL, "Portuguese");

    // Recebe o tamanho da matriz
    int n = get_positive_int("Digite o tamanho da matriz quadrada: "),
        // Aloca memória para as matrizes
        *matriz_a[n][n], *matriz_b[n][n], matriz_c[n][n];

    // Preenche as matrizes
    preencher_matriz(n, matriz_a, 'a');
    preencher_matriz(n, matriz_b, 'b');

    // Calcula a matriz c e libera a memória alocada para as matrizes
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++){
            matriz_c[i][j] = *matriz_a[i][j] + *matriz_b[i][j];
            free(matriz_a[i][j]); free(matriz_b[i][j]);
        }


    // Imprime a matriz c
    printf("\n================== Matriz c ==================\n{");
    for (int i = 0; i < n; i++)
    {
        printf("\n  {");
        for (int j = 0; j < n; j++)
            printf(" %d ", matriz_c[i][j]);
        printf("}");
    }
    printf("\n}\n");

    return 0;
}

void preencher_matriz(int n, int *matriz[][n], char m_id)
{
    printf("\n================== Matriz %c ==================\n", m_id);

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
        {
            // Aloca memória para o elemento da matriz
            matriz[i][j] = malloc(sizeof(int));

            // Preenche o elemento da matriz
            printf("Digite o elemento [%d][%d] da matriz %c: ", i, j, m_id);
            scanf("%d", matriz[i][j]);
        }
}