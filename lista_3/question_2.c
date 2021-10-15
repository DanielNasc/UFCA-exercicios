#include <stdio.h>
#include <locale.h>
#include "get_num.h"

// Faça um algoritmo que receba dois números a e b (a < b). Calcule a soma dos números
// pares que existem entre a e b.

int main()
{
    setlocale(LC_ALL, "Portuguese");

    int a = get_int("um número"), b;

    // Pedir ao usuário o segundo número, e só aceitar se for maior que o primeiro
    do
    {
        b = get_int("outro número");
        if (a >= b) printf("O segundo número tem que ser maior que o primeiro\n");

    } while (a >= b);
    
    int soma_pares = 0;

    // Checar todos os numeros entre a e b, um por um
    for (int i = a; i <= b; i++)
    {
        // Checar se o numero i é par, se sim, adiconá-lo à soma total
        if (i % 2 == 0) soma_pares += i;
    }
    
    printf("A soma dos números pares entre %i e %i é %i\n", a, b, soma_pares);

    return 0;
}