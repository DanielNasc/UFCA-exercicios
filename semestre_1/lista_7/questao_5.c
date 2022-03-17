#include <stdio.h>
#include <locale.h>
#include "get_num.h"

// Crie uma função que recebe um valor inteiro n e retorna o n−ésimo elemento da sequência
// de fibonacci.

int fibonacci(int n);

int main()
{
    setlocale(LC_ALL, "Portuguese");
    int n = get_positive_int("Digite a posição do elemento da sequência de fibonacci que você quer: ");
    printf("O %dº elemento da sequência de fibonacci é %d\n", n, fibonacci(n));
    return 0;
}

int fibonacci(int n)
{
    if (n == 0)
        return 0;
    else if (n == 1)
        return 1;
    else
        return fibonacci(n - 1) + fibonacci(n - 2);
}