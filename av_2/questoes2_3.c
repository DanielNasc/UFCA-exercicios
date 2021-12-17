#include <stdio.h>
#include "get_num.h"

// 2
// Faça um algoritmo que receba um número n digitado pelo o usuário e crie um vetor de
// n posições. O usuário também deve digitar os elementos do vetor. Após isso, imprima
// quantas vezes cada número aparece no vetor (Não se preocupe em mostrar várias vezes a
// quantidade do mesmo número).
// EX: n = 5, vet = [1, 2, 1, 2, 5]
// Número 1, quantidade: 2
// Número 2, quantidade: 2
// Número 1, quantidade: 2
// Número 2, quantidade: 2
// Número 5, quantidade: 1

// 3
// (DESAFIO) - Faça a questão 2 sem repetir os mesmos números. No caso do exemplo
// mostrado, o algoritmo deve imprimir:
// Número 1, quantidade: 2
// Número 2, quantidade: 2
// Número 5, quantidade: 1

int qtd_elementos_iguais(int vetor[], int n, int num);
int check_black_list(int black_list[], int n, int num);

int main()
{
    int n = get_positive_int("Digite a quantidade de elementos: "), 
            vetor[n], black_list[n], len_black_list = 0;

    printf("\nPreencha o vetor ===============================\n\n");
    get_int_array(vetor, n, "elemento do vetor", 'o');

    printf("\nRepetição de elementos =========================\n\n");
    for (int i = 0; i < n; i++)
    {
        if (!check_black_list(black_list, len_black_list, vetor[i]))
        {
            printf("Número %d, quantidade: %d\n", vetor[i], qtd_elementos_iguais(vetor, n, vetor[i]));
            black_list[len_black_list] = vetor[i];
            len_black_list++;
        }
    }
        

    return 0;
}

int qtd_elementos_iguais(int vetor[], int n, int num)
{
    int qtd = 0;
    for (int i = 0; i < n; i++)
    {
        if (vetor[i] == num)
            qtd++;
    }
    return qtd;
}

int check_black_list(int black_list[], int n, int num)
{
    for (int i = 0; i < n; i++)
    {
        if (black_list[i] == num)
            return 1;
    }
    return 0;
}