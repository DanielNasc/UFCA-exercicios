// Faça um programa que receba 3 números e imprima o maior número digitado.
#include <stdio.h>
#include <locale.h>
#include "get_num.h"

int main()
{
    setlocale(LC_ALL, "Portuguese");
    int maior_num;
    for (int i = 0; i < 3; i++)
    {
        if (i == 0) maior_num = get_int("um numero");
        else 
        {
            int novo_num = get_int("um numero");
            maior_num = novo_num > maior_num ? novo_num: maior_num;
        }
    }

    printf("O maior numero é: %i\n", maior_num);
    return 0;
}