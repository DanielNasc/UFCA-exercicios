#include <stdio.h>
#include <locale.h>
#include "get_num.h"

// Faça um algoritmo que receba dois números a e b (a < b). Imprima a quantidade de
// números múltiplos de 3 entre a e b.

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
    
    int quant_mult_3 = 0;

    // Checar todos os numeros entre a e b, um por um
    for (int i = a; i <= b; i++)
    {
        // Checar se o numero i é multiplo de 3, se sim, adiconar 1 ao contador
        if (i % 3 == 0) quant_mult_3++;
    }
    
    // Imprimir a quantidade de números múltiplos de 3 entre a e b.
    printf("A quantidade de multiplos de 3 entre %i e %i é %i\n", a, b, quant_mult_3);

    return 0;
}