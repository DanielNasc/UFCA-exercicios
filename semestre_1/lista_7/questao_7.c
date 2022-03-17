#include <stdio.h>
#include "get_num.h"

// Crie uma função recursiva que recebe um valor n e que retorna o n−ésimo elemento da
// sequência de fibonacci. Considere que: fib(0) = 0, fib(1) = 1 e, para n > 1, fib(n) =
// fib(n − 1) + fib(n − 2)

int fib(int n);

int main()
{
    int n = get_positive_int("Digite um número n para que o n−ésimo elemento da sequência de fibonacci seja impresso: ");
    printf("O %iº elemento da sequência de fibonacci é %i\n", n, fib(n));
    return 0;
}

int fib(int n)
{
    if (n == 0) return 0;
    if (n == 1) return 1;
    return fib(n - 1) + fib(n - 2);
}
