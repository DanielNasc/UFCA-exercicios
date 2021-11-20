#include <stdio.h>
#include <locale.h>
#include <malloc.h>
#include "get_num.h"

// Faça um algoritmo que receba dois vetores de tamanho n e calcule o produto escalar entre
// eles. Ou seja, dado dois vetores x = [x1, x2, ..., xn] e y = [y1, y2, ..., yn] calcular o produto
// escalar obtido por: x.y = x1.y1 + x2.y2 + ... + xn.yn.

void preencher_vetor(int *vetor[], int n, char m_id);

int main()
{
    setlocale(LC_ALL, "Portuguese");

    // Inicialização das variáveis
    int n = get_positive_int("Digite o tamanho dos vetores: "),
            *x[n], *y[n], escalar = 0;

    // Preenche os vetores
    preencher_vetor(x, n, 'x');
    preencher_vetor(y, n, 'y');

    // Calcula o produto escalar e libera a memória alocada para os vetores
    for (int i = 0; i < n; i++){
        escalar += (*x[i]) * (*y[i]);
        free(x[i]); free(y[i]);
    }

    // Imprime o resultado
    printf("\nO produto escalar entre os vetores é: %d\n", escalar);
    return 0;
}

void preencher_vetor(int *vetor[], int n, char v_id)
{
    printf("\n================== Vetor %c ==================\n", v_id);

    for (int i = 0; i < n; i++)
    {
        vetor[i] = malloc(sizeof(int));
        printf("Digite o valor do elemento %d: ", i + 1);
        scanf("%d", vetor[i]);
    }
}