#include <stdio.h>
#include <locale.h>
#include "get_num.h"

// Dada a serie de Fibonacci formada pela sequência 1, 1, 2, 3, 5, 8, 13, 21, 34..., crie um algo-
// ritmo que receba um número n do usuário e que calcule e imprima a soma dos n primeiros
// números da série.

int main()
{
    setlocale(LC_ALL, "Portuguese");

    int n, a = 1, soma = a, b = 1, c;; 
    
    do
    {
        n = get_int("quantos números da sequência de Fibonacci você quer");
    } while (n < 1);

    // se a o usuario digitar o numero 1, a soma sera o primeiro numero
    // se for maior, entao os outros valores tambem serao somados
    if (n >= 2) soma += b;

    for (int i = 2; i < n; i++)
    {  
        c = a + b;
        soma += c;
        a = b;
        b = c;
    }

    printf("%i\n", soma);

    return 0;
}