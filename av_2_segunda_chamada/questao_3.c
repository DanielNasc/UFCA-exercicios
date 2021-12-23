#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
/*
Faça um algoritmo que leia um inteiro n digitado e gere uma matriz n × n também
digitada. Imprima a linha e a coluna do maior elemento digitado
*/

int main()
{
    int n;

    printf("n: ");
    scanf("%d", &n);

    // Alocando memória para a matriz =========================================
    int ** matriz = (int**) malloc(sizeof(int *) * n);

    for (int i = 0; i < n; i ++)
        *(matriz + i) = (int*) malloc(sizeof(int) * n);
    // =========================================================================

    int *linhas_maiores_elementos = (int *)malloc(sizeof(int)), 
        *colunas_maiores_elementos = (int *)malloc(sizeof(int)),
        maior_elemento = INT_MIN,
        qtd_maiores_elementos = 1;

    *linhas_maiores_elementos = *colunas_maiores_elementos = 0;

    for (int i = 0; i < n; i++)
    {
        printf("\n");
        for(int j = 0; j < n; j ++)
        {
            printf("Matriz[%d][%d]: ", i, j);
            scanf("%d", &matriz[i][j]);

            /*
            Se o elemento i for maior que a variável maior_elemento,
            então as variáveis são reiniciadas
            */
            if (matriz[i][j] > maior_elemento)
            {
                maior_elemento = matriz[i][j];
                linhas_maiores_elementos = (int *) realloc(linhas_maiores_elementos, sizeof(int));
                *linhas_maiores_elementos = i;
                colunas_maiores_elementos = (int *) realloc(colunas_maiores_elementos, sizeof(int));
                *colunas_maiores_elementos = j;
                qtd_maiores_elementos = 1;
            }
            /*
            Se o elemento i for igual ao maior elemento,
            então é adicionado mais um espaços ás variáveis linhas_maiores_elementos e colunas_maiores_elementos
            onde serão armazenados os valores das linhas e colunas do elemento i
            */
            else if (matriz[i][j] == maior_elemento)
            {
                qtd_maiores_elementos++;
                linhas_maiores_elementos = (int *) realloc(linhas_maiores_elementos, 
                                                            sizeof(int) * (qtd_maiores_elementos));
                colunas_maiores_elementos = (int *) realloc(colunas_maiores_elementos,
                                                            sizeof(int) * (qtd_maiores_elementos));
                linhas_maiores_elementos[qtd_maiores_elementos - 1] = i;
                colunas_maiores_elementos[qtd_maiores_elementos - 1] = j;
            }
        }
    }

    /*
    Se houver apenas um elemento com o maior valor,
    então não é necessário formatar a saída como se houvesse diversos elementos com o mesmo valor
    */
    if (qtd_maiores_elementos == 1)
        printf("\nA linha e a coluna do maior elemento são, respectivamente, %d e %d\n",
                *linhas_maiores_elementos, *colunas_maiores_elementos);
    else 
    {
        printf("\nAs linhas e as colunas que armazenam os maiores elementos são:\n");
        for (int i = 0; i < qtd_maiores_elementos; i++)
            printf("[%d][%d]\n", linhas_maiores_elementos[i], colunas_maiores_elementos[i]);
    }

    // Liberando memória alocada para as variáveis =============================
    for (int i = 0; i < n; i++)
        free(*(matriz + i));
    free(matriz);
    free(linhas_maiores_elementos);
    free(colunas_maiores_elementos);
    // =========================================================================
    return 0;
}
