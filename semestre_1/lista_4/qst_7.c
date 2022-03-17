#include <stdio.h>
#include <locale.h>
#include "get_num.h"

// Faça um algoritmo que recebe dez números digitados pelo usuário. Após isso, o algoritmo
// deve informar o maior e o menor número digitado (Utilize estruturas de repetição).

int main()
{
    setlocale(LC_ALL, "Portuguese");

    int nums[10], maior, menor;

    printf("O programa vai precisar de 10 números.\n");

    // pedir os 10 numeros ao usuario
    for (int i = 0; i < 10; i++)
    {
        printf("Digite o %iº número:\n", i+1);
        scanf("%d", &nums[i]);
    }

    // atribuir o primeiro valor às variaveis para serem comparadas
    maior = menor = nums[0];

    // comparar nota por nota e atualizar os valores de maior ou menor dependendo do caso
    for (int i = 1; i < 10; i++)
    {
        if (nums[i] > maior) maior = nums[i];
        if (nums[i] < menor) menor = nums[i];
    }

    printf("O maior número da lista é %i\n", maior);
    printf("O menor número da lista é %i\n", menor);

    return 0;
}