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

float get_float(char *num_desc)
{
    setlocale(LC_ALL, "Portuguese");
    float numero;
    printf("Digite %s: \n", num_desc);
    scanf("%f", &numero);
    return numero;
}

int get_positive_int(char *num_desc)
{
    setlocale(LC_ALL, "Portuguese");
    int numero;
    do
    {
        printf("Digite %s: \n", num_desc);
        scanf("%i", &numero);
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
        printf("Digite %s: \n", num_desc);
        scanf("%f", &numero);
        if (numero < 0)
            printf("O numero deve ser positivo!\n");
    } while (numero <= 0);
    return numero;
}