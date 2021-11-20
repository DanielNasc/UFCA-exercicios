#include <stdio.h>
#include <locale.h>
#include "get_num.h"

// Faça um programa que leia uma matriz m × n do usuário e crie e imprima a matriz
// transposta n × m.

void imprimir_matriz(int lin, int col, int matriz[][col], char *m_nome);

int main()
{
    setlocale(LC_ALL, "Portuguese");
    
    int m = get_positive_int("Digite o número de linhas da matriz: "),
        n = get_positive_int("Digite o número de colunas da matriz: "),
        matriz_transposta[n][m];


    // Preenche a matriz
    printf("\n");
    for (int i = 0; i < m; i++){
        for (int j = 0; j < n; j++){
            printf("Digite um número para o elemento [%d, %d] da matriz: ", i, j);
            scanf("%i", &matriz_transposta[j][i]);
        }
        printf("\n");
    }

    imprimir_matriz(n, m, matriz_transposta, "transposta");

    return 0;
}

void imprimir_matriz(int lin, int col, int matriz[][col], char *m_nome)
{

    printf("\n================== Matriz %s ==================\n{", m_nome);
    for (int i = 0; i < lin; i++){

        printf("\n {");
        for (int j = 0; j < col; j++)
            printf(" %d ", matriz[i][j]);
        printf("}");
    }
    printf("\n}\n");
}
