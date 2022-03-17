#include <stdio.h>
#include <locale.h>
#include "get_num.h"

int main()
{
    setlocale(LC_ALL, "Portuguese");
    int horas = get_int("quantas horas você trabalha por mês");
    int valor_hora = get_float("quanto você ganha por hora");
    printf("Seu salário deve ser de R$%.2f\n", (float) horas * valor_hora);
    return 0;
}