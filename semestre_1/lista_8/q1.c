#include <stdio.h>
#include <stdlib.h>
#include "get_num.h"

// Elaborar um programa que leia dois valores inteiros (a e b) na função main. Em seguida
// faça uma função que retorne a 2a + 2b. Além disso, a função deve alterar os valores de a
// e b do escopo main. Nesse sentido, a deve valer 2a enquanto b deve valer 2b.

int duplicar_e_somar(int *a, int *b);

int main(void)
{
    int *a = get_int_pointer("Digite o valor de a: "),
        *b = get_int_pointer("Digite o valor de b: ");

    printf("\na antes da função: %d\n", *a);
    printf("b antes da função: %d\n", *b);

    int soma = duplicar_e_somar(a, b);

    printf("\na depois da função: %d\n", *a);
    printf("b depois da função: %d\n", *b);
    printf("a + b: %d\n", soma);

    free(a);
    free(b);

    return 0;
}

int duplicar_e_somar(int *a, int *b)
{
    *a = 2 * *a;
    *b = 2 * *b;

    return *a + *b;
}
