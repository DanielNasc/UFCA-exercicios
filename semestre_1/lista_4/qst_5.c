#include <stdio.h>
#include <locale.h>
#include "get_num.h"

//Faça um programa que receba um número inteiro do usuário (maior do que 1) e imprima
//se ele é primo ou não.


int main()
{
    setlocale(LC_ALL, "Portuguese");
	
	int n = get_int("um número para o programa checar se é primo ou não");
	char *e_primo = "é";

	for (int i = 2; i < n; i++)
	{
		// checar se o numero n é divisivel por algum dos numeros entre 2 e ele
		// se sim, não é primo
		if (n%i == 0)
		{
			e_primo = "não é";
			break;
		}
	}

	printf("O número %i %s primo\n", n, e_primo);

    return 0;
}
