#include <stdio.h>
#include <locale.h>
#include "get_num.h"

// Faça um algoritmo que receba um número digitado pelo usuário e imprima todos os
// divisores do número.

int main()
{
    setlocale(LC_ALL, "Portuguese");

    int n = get_int("um número");

    printf("Os divisores do número dado são:\n");

    // checar se o número n é divisivel por cada um dos numeros entre 1 e n
    for (int i = 1; i <= n; i++)
    {
        if (n%i == 0) printf("%i\n", i);
    }
    
    return 0;
}
