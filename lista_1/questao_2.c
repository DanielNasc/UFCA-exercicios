#include <stdio.h>
#include <locale.h>
#include "get_num.h"

#define DESC "um número inteiro"

int main()
{
    setlocale(LC_ALL, "Portuguese");
    int num_1 = get_int(DESC);
    int num_2 = get_int(DESC);

    printf("O produto entre %i e %i é: %ld\n", 
    num_1, 
    num_2, 
    (long) num_1 * (long) num_2);

    return 0;
}