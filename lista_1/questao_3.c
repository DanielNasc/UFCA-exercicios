#include <stdio.h>
#include <locale.h>
#include "get_num.h"

int main()
{
    setlocale(LC_ALL, "Portuguese");
    float metros = get_float("uma distancia em metros");
    printf("%.2f em centímetros é: %.0f\n", metros, metros * 100);
}