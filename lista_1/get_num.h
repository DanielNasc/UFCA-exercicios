#include <stdio.h>
#include <locale.h>

int get_int(char *num_desc)
{
    setlocale(LC_ALL, "Portuguese");
    int numero;
    printf("Digite %s: \n", num_desc);
    scanf("%i", &numero);
    return numero;
}

int get_float(char *num_desc)
{
    setlocale(LC_ALL, "Portuguese");
    float numero;
    printf("Digite %s: \n", num_desc);
    scanf("%f", &numero);
    return numero;
}