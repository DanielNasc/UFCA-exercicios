#include <stdio.h>
#include <locale.h>
#include <string.h>
#include "get_num.h"

// prototype
void print_percent(char *tipo_voto , float votos, float total);

int main()
{
    setlocale(LC_ALL, "Portuguese");

    // conseguir valores
    int nulos = get_int("a quantidade de votos nulos");
    int brancos = get_int("a quantidade de votos brancos");
    int validos = get_int("a quantidade de votos válidos");

    // conseguir total de votos
    int total = nulos + validos + brancos;

    // para não dar erro ao tentar dividir um número por 0
    if (total == 0) return 1;

    // "printar" a porcetagem de cada tipo de voto
    print_percent("nulos", nulos, total);
    print_percent("brancos", brancos, total);
    print_percent("válidos", validos, total);

    // tudo OK
    return 0;
}

void print_percent(char *tipo_voto , float votos, float total)
{
    float percentual = (100 * votos) / total;
    // https://stackoverflow.com/questions/17774821/how-do-i-print-the-percent-sign-in-c
    printf("O percentual de votos %s é: %.2f%%\n", tipo_voto, percentual);
}