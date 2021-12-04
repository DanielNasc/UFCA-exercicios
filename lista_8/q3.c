#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "get_num.h"

// Crie um programa que contenha um vetor de inteiros contendo 7 elementos. Utilizando
// apenas aritmética de ponteiros (ou seja, navegar o vetor utilizando a propriedade de
// ponteiros),leia esse vetor do teclado e imprima a soma dos elementos que estão em posição
// par.

int main()
{
    setlocale(LC_ALL, "Portuguese");

    int * vetor = (int *) malloc(7 * sizeof(int)), soma = 0;

    get_int_array(vetor, 7);

    for (int i = 1; i < 7; i+=2)
        soma += vetor[i];

    printf("\nA soma dos elementos que estão em posição par é: %d\n", soma);

    free(vetor);
    return 0;
}
