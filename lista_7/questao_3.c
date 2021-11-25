#include <stdio.h>
#include <locale.h>
#include "get_num.h"

// Faça uma função que receba 3 notas por parâmetro, calcule a média e retorne 1 caso a
// média seja maior ou igual a 7 e 0 caso contrário.

float media(float notas[3]);

int main()
{
    setlocale(LC_ALL, "Portuguese");
    
    float notas[3];

    for (int i = 0; i < 3; i++)
    {
        printf("Digite a nota %d: ", i + 1);
        scanf("%f", &notas[i]);
    }

    media(notas) ? printf("\nAprovado!\n") : printf("\nReprovado!\n");

    return 0;
}

float media(float notas[3])
{
    float media = 0;

    for (int i = 0; i < 3; i++)
        media += notas[i];
    media /= 3;

    return media >= 7 ? 1 : 0;
}