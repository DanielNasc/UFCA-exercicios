#include <stdio.h>
#include <locale.h>
#include "get_num.h"

int main()
{
    setlocale(LC_ALL, "Portuguese");
    
    int n = get_int("um número");

    char *paridade = n % 2 == 0 ? "par" : "impar";

    printf("O número %i é %s\n", n, paridade);

    return 0;
}