#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "get_num.h"

int *fib(int n);

int main()
{
    setlocale(LC_ALL, "Portuguese");

    // 5
    // Na função principal (main), chame a função da questão anterior (n digitado pelo usuário),
    // armazene o vetor retornado em um ponteiro int* e imprima os seus elementos.

    int n = get_positive_int("Digite um número inteiro: "),
        *fib_n = fib(n);

    printf("Fibonacci de %d: [", n);
    for (int i = 0; i < n; i++)
        printf(" %d ", fib_n[i]);
    printf("]\n");

    // 6
    // Na função principal (main), utilize a função realloc para aumentar a quantidade de
    // posições do vetor. Nesse caso, o vetor terá duas vezes o seu tamanho original. Nas
    // posições novas do vetor, espelhe as posições originais de tal forma que as novas posições
    // tenham 3 vezes o valor das posições originais.

    fib_n = realloc(fib_n, 2 * n * sizeof(int));

    for (int i = n; i < 2 * n; i++)
        fib_n[i] = fib_n[i - n] * 3;

    // 7
    // Imprima os valores do novo vetor (após o relloc). Depois disso, libere o vetor da memória
    // e encerre o programa.   

    printf("\nVetor após realloc: [");
    for (int i = 0; i < 2*n; i++)
        printf(" %d ", fib_n[i]);
    printf("]\n");

    free(fib_n);

    return 0;
}

// 4
// Faça uma função que receba um parâmetro inteiro n e aloca na memória heap um vetor
// de n posições. Além disso, cada posição do vetor deve estar relacionada com o número
// da sequência de Fibonacci daquela posição. Após isso, a função deve retornar o endereço
// inicial do vetor.

int *fib(int n)
{
    int * vetor = (int *) malloc(n * sizeof(int));
    int a, b, c;

    vetor[0] = vetor[1] = a = b = 1;

    for (int i = 2; i < n; i++)
    {
        c = a + b;
        a = b;
        b = c;
        vetor[i] = c;
    }

    return vetor;
}