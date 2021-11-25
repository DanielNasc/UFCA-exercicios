#include <stdio.h>
#include <locale.h>

int get_int(char *num_desc)
{
    setlocale(LC_ALL, "Portuguese");
    int numero;
    printf("%s", num_desc);
    scanf("%i", &numero);
    return numero;
}

float get_float(char *num_desc)
{
    setlocale(LC_ALL, "Portuguese");
    float numero;
    printf("%s", num_desc);
    scanf("%f", &numero);
    return numero;
}

int get_positive_int(char *num_desc)
{
    setlocale(LC_ALL, "Portuguese");
    int numero;
    do
    {
        numero = get_int(num_desc);
        if (numero < 0)
            printf("O numero deve ser positivo!\n");
    } while (numero <= 0);
    return numero;
}

float get_positive_float(char *num_desc)
{
    setlocale(LC_ALL, "Portuguese");
    float numero;
    do
    {
        numero = get_float(num_desc);
        if (numero < 0)
            printf("O numero deve ser positivo!\n");
    } while (numero <= 0);
    return numero;
}