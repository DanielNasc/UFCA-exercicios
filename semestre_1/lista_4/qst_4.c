#include <stdio.h>
#include <locale.h>
#include "get_num.h"

// Faça um algoritmo que receba um número natural e imprima se ele é ou não triangular.
// Um número natural é triangular se ele é produto de três números naturais consecutivos.
// Exemplo: 120 é triangular, pois 4∗5∗6 = 120. O número 6 é triangular, já que 1∗2∗3 = 6.

int main()
{
    setlocale(LC_ALL, "Portuguese");
	int n = get_int("um número");

	for (int i = 1; i <= n; i++)
	{
		// obter a multiplocação de 3 némeros consecutivos
		int produto = i * (i + 1) * (i + 2);

		// se a multiplicação deles começar a ultrapassar o valor do número n,
		// parar o programa
		if (produto > n)
		{
			printf("%i não é um número triangular\n", n);
			break;
		}

		// se a multiplicação for igual ao numero n, é triangular
		else if (produto == n)
		{
			printf("%i é um número triangular\n", n);
			break;
		}
	}
    return 0;
}
