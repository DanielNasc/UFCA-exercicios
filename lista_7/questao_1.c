#include <stdio.h>
#include "get_num.h"

// Faça uma função que recebe um valor em Celsius (como parâmetro) e retorna um valor
// em Farenheit

float c_para_f(float c)
{
    return ((9*c)/5) + 32;
}

int main()
{
    float c = get_float("Digite uma temperatura em Celsius para ser convertida para Farenheit ");
    printf("Essa temperatura em Farenheit é %.2f\n", c_para_f(c));
    return 0;
}
