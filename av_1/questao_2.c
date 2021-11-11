#include <stdio.h>
#include <locale.h>
#include "get_num.h"

int fatorial(int n);

int main()
{
    setlocale(LC_ALL, "Portuguese");
	int n = get_positive_int("um número"), 
	p = get_positive_int("outro número");

	float arranjo = (float) fatorial(n) / fatorial(n - p);

	printf("%.2f\n", arranjo);

    return 0;
}

int fatorial(int n)
{
	if (n == 0) return 1;
	int n_fat = 1;

	for (int i = 0; i < n; i++)
		n_fat *= n - i;
		
	return n_fat;
}
