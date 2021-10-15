#include <stdio.h>
#include <locale.h>
#include "get_num.h"

// Faça um algoritmo que receba um inteiro n e imprima os n primeiros termos da sequência
// de Fibonacci. A série é dada pelos termos: 1, 1, 2, 3, 5, 8, 13...

int main()
{
    setlocale(LC_ALL, "Portuguese");

    int n; 
    
    // O usuário tem que pedir pelo menos 1 número
    do
    {
        n = get_int("quantos números da sequência de Fibonacci você quer");
    } while (n < 1);

    int a = 0, b = 1, c;

    // Se ele quis só 1, não precisa fazer contas, só imprimir o primeiro
    if (n == 1) printf("%d", b);
    // Se ele quer dois ou mais, imprimir os dois primeros (que não precisam de conta)
    if (n >= 2) printf("%d %d", a, b);

    // calcular os numeros da sequencia, pulando os dois primeiros (pois ja foram imprimidos)
    for (int i = 2; i < n; i++)
    {  
        c = a + b;
        printf(" %d", c);
        a = b;
        b = c;
    }

    printf("\n");

    return 0;
}