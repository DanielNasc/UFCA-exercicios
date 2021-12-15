#include <stdio.h>
#include <stdlib.h>

void print_num_desc(char * num_desc)
{
    if (num_desc)
        printf("%s", num_desc);
}

int get_int(char *num_desc )
{
    int numero;
    print_num_desc(num_desc);
    scanf("%i", &numero);
    return numero;
}

float get_float(char *num_desc)
{
    float numero;
    print_num_desc(num_desc);
    scanf("%f", &numero);
    return numero;
}

int get_positive_int(char *num_desc)
{
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
    float numero;
    do
    {
        numero = get_float(num_desc);
        if (numero < 0)
            printf("O numero deve ser positivo!\n");
    } while (numero <= 0);
    return numero;
}

void get_int_array(int *array, int size, char * num_desc)
{
    for (int i = 0; i < size; i++)
    {
        printf("Digite o %iº %s: ", i + 1, num_desc);
        scanf("%i", (array + i));
    }
}

int * get_int_pointer(char *num_desc)
{
    int * n = (int *) malloc(sizeof(int));
    print_num_desc(num_desc);
    scanf("%i", n);
    return n;
}
