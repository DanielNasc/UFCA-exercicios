#include <stdio.h>
#include <locale.h>
#include "get_num.h"

// Faça uma função que recebe, por parâmetro, um valor inteiro positivo e retorna o número
// de divisores desse valor.

int get_num_divisores(int n);

int main()
{
    setlocale(LC_ALL, "Portuguese");
    int n = get_int("Digite um número inteiro: ");

    printf("O número de divisores de %d é %d\n", n, get_num_divisores(n));
    return 0;
}

int get_num_divisores(int n)
{
    int counter = 2;

    for (int i = 2; i <= n / 2; i++) 
        if (n % i == 0) 
            counter++;
    
    return counter;
}