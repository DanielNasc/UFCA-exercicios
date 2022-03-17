#include <stdio.h>
#include <locale.h>

// Faça um algoritmo que leia 10 números. O algoritmo deve imprimir a soma dos números
// digitados que são maiores do que 40.

int main()
{
    setlocale(LC_ALL, "Portuguese");

    int soma_total = 0;

    printf("O programa vai precisar de 10 númeors\n");

    for (int i = 0; i < 10; i++)
    {   
        int n;
        printf("Digite o %iº número: ", i + 1);
        scanf("%d", &n);
        if (n > 40) soma_total += n;
    }

    printf("A soma dos números maiores que 40 é %i\n", soma_total);

    return 0;
}