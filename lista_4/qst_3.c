#include <stdio.h>
#include <locale.h>
#include "get_num.h"

// Faça um algoritmo que receba dois números inteiros positivos do usuário. O programa
// deve calcular e exibir a multiplicação dos dois números. (Não pode utilizar o operador de
// multiplicação *).

int main()
{
    setlocale(LC_ALL, "Portuguese");
    int fatores[2], produto = 0;

    // só aceitar o input do usuário se o número for maior que 0
    for (int i = 0; i < 2; i++)
    {
        do
        {
            fatores[i] = get_int("um número");
            if (fatores[i] < 0) printf("O número tem que ser um inteiro positivo.\n");
        } while (fatores[i] < 0);
    }

    // um numero vezes n é o próprio número somado a si mesmo n vezes
    for (int i = 0; i < fatores[1]; i++)
    {
        produto += fatores[0];
    }

    printf("%i multiplicado por %i é igual a %i\n", fatores[0], fatores[1], produto);

    return 0;
}