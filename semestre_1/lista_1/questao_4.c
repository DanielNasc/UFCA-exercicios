#include <stdio.h>
#include <locale.h>
#include "get_num.h"

#define PI 3.1415

int main()
{
    setlocale(LC_ALL, "Portuguese");
    float r = get_float("o raio de um circulo");
    printf("A área do círculo é: %.2f\n", PI * (r * r));
}