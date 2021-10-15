#include <stdio.h>
#include <locale.h>
#include "get_num.h"

// Faça um algoritmo que receba dois números a e b (a < b). Calcule a média dos números
// inteiros que existem entre a e b.

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
    
    int soma_inteiros = 0;

     // Checar todos os numeros entre a e b, um por um
    for (int i = a; i <= b; i++)
    {
        // Adicionar o número i à soma total
        soma_inteiros += i;
    }
    
    // Conseguir a média
    float media_inteiros = (float) soma_inteiros / (float) b;

    printf("A media da soma dos numeros entre %i e %i é %.2f\n", a, b, media_inteiros);

    return 0;
}