#include <stdio.h>
#include <locale.h>
#include "get_num.h"

int main()
{
    setlocale(LC_ALL, "Portuguese");
    int numero = get_int("inteiro");
    printf("Número digitado: %i\n", numero);
    return 0;
}