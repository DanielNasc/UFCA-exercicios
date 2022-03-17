#include <stdio.h>
#include <locale.h>
#include "get_num.h"

// faça uma função recursiva que tenha um parâmetro
// inteiro n e retorne 2^n

int dois_a_potencia(int n);

int main()
{
    setlocale(LC_ALL, "Portuguese");

    int n = get_int("Digite um expoente para ser aplicado a uma base 2: ");
    printf("2^%d = %d\n", n, dois_a_potencia(n));

    return 0;
}

int dois_a_potencia(int n)
{
    if (n == 0)
        return 1;
    else if (n > 0)
        return 2 * dois_a_potencia(n - 1);
    else
        return 2 / dois_a_potencia(n + 1);
}