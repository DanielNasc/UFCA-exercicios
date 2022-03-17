#include <stdio.h>
#include <locale.h>
#include "get_num.h"

float f(float x);

int main()
{
    setlocale(LC_ALL, "Portuguese");
	float x, resultado;
	do 
	{
		x = get_float("um valor x");
		if (x == 16) printf("x tem que ser diferente de 16.\n");
	} while (x == 16);

	resultado = f(x);
	printf("O resultado é %.2f\n", resultado);
    return 0;
}

float f(float x)
{
	if (x <= 1)
		return 1;
	else if (x <= 2)
		return 2;
	else if (x <= 4)
		return 2*x;

	return ((5*x) + 3) / (x - 16);
}
