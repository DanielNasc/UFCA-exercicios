#include <stdio.h>
#include <locale.h>
#include "get_num.h"

int main()
{
    setlocale(LC_ALL, "Portuguese");
    
    // conseguir valores
    float salario_bruto = get_float("quanto você ganha por mês");
    float impostos = salario_bruto * .08;
    float sindicato = salario_bruto * .05;

    // "printar" o salario bruto, o quanto pagou de imposto, o quanto pagou ao sindicato e o salário liquído
    printf("Seu salário bruto é de R$%.2f;\n", salario_bruto);
    printf("Você pagou R$%.2f em impostos;\n", impostos);
    printf("Você pagou R$%.2f ao sindicato;\n", sindicato);
    printf("E seu salário líquido é de R$%.2f.\n", salario_bruto - impostos - sindicato);

    return 0;
}