#include <stdio.h>
#include <locale.h>
#include <math.h>
#include "get_num.h"

// Faça um algoritmo que receba um número n do usuário e calcule o valor da série S dos n
// primeiros termos da série:
// S = 1/1 - 2/4 + 3/9 - 4/16 + ...

int main()
{
    setlocale(LC_ALL, "Portuguese");

    int n = get_int("um número"); 
    float s = 0;

    for (int i = 1; i <= n; i++)
    {
        // alternar os sinais dos números,
        // o primeiro é positivo, o segundo é negativo, o terceiro é adiz, ...
        if (i%2 == 0) s -= (float) i / pow(i, 2);
        else s += (float) i / pow(i, 2);
    }

    printf("A soma da série S é: %.2f\n", s);

    return 0;
}