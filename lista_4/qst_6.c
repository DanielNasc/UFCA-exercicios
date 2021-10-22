#include <stdio.h>
#include <locale.h>
#include "get_num.h"

// Faça um programa que receba 3 notas de um aluno e mostre a média. O programa deve
// ter validação de notas. Ou seja, se uma nota digitada for menor que 0 ou maior que 10, o
// programa deve informar "nota inválida"e pedir para o usuário digitar a nota novamente.

// criando o tipo bool
typedef enum { false, true } bool;

int main()
{
    setlocale(LC_ALL, "Portuguese");
	
	float notas[3], soma_total = 0, media; 
	bool nota_ok = false;

	for (int i = 0; i < 3; i++)
	{
		do
		{
			// pedir a iº ao usuario
			printf("Digite a nota %i:\n", i + 1);
			scanf("%f", &notas[i]);

			// e recusa se ela for maior que 10 ou menor que 0
			nota_ok = notas[i] <= 10 && notas[i] >= 0;
			if (!nota_ok) printf("Nota inválida\n");
		} while (!nota_ok);
	}

	// somar todas as notas
	for (int i = 0; i < 3; i++)
	{
		soma_total += notas[i];
	}

	// conseguir a media
	media = soma_total / 3;

	printf("A média do aluno é %.2f\n", media);

    return 0;
}
