#include <stdio.h>
#include <locale.h>
#include "get_num.h"

// Faça um algoritmo que receba um valor n e calcule n!.

int main()
{
    setlocale(LC_ALL, "Portuguese");

    int n;
    // Com o long, o maior número que se pode obter o fatorial é 20
    long n_fatorial = 1;

    // Pedir ao usuário o segundo número, e só aceitar se for maior que 0 (não existe fatorial de número negativo)
    do
    {
        n = get_int("um número");
    } while (n < 0);
        

    // Se o número for 0, então seu fatorial é 1,
    if (n == 0) n_fatorial = 1;
    else
    {
        // se não, calcular o fatorial do numero atraves de um loop que multiplica o valor de n_fatorial por n - i
        // Ex: n_fatorial = (n - 0) * (n - 1) * (n - 2)...
        for (int i = 0; i < n; i++)
        {
            n_fatorial *= n - i;
        }
    }

    printf("!%i é %li\n", n, n_fatorial);

    return 0;
}