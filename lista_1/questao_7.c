#include <stdio.h>
#include <locale.h>
#include "get_num.h"

int main()
{
    setlocale(LC_ALL, "Portuguese");
    
    float quilometros = get_float("a quantidade de quilometros percorridos");
    int dias = get_int("a quantidade de dias do aluguel");

    float preco_aluguel = (quilometros * .15) + (dias * 60);

    printf("O total a ser pago pelo aluguel do carro é: R$%.2f\n", preco_aluguel);

    return 0;
}