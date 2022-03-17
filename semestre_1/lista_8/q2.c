#include <stdio.h>
#include <stdlib.h>
#include "get_num.h"

// Crie um programa que contenha um vetor de inteiros contendo 5 elementos. Utilizando
// apenas aritmética de ponteiros (ou seja, navegar o vetor utilizando a propriedade de
// ponteiros), leia esse vetor do teclado e imprima cada elemento multipicado por 2.

int main()
{
    int *vetor = (int*)malloc(sizeof(int)*5);

    get_int_array(vetor, 5);

    printf("\n");
    for (int i = 0; i < 5; i++)
        printf("Multiplicando o %iº elemento por 2, temos: 2*%i = %i: \n", i+1, 
        *(vetor + i), 
        *(vetor + i)*2);

    free(vetor);

    return 0;
}
