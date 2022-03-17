#include <stdio.h>
#include <locale.h>
#include "get_num.h"

int main()
{
    setlocale(LC_ALL, "Portuguese");
    // Faça um algoritmo que receba uma temperatura em Celsius e depois pergunte se o usuá-
    // rio deseja digitar outra temperatura (1 - Pra sim, Outra tecla para não).
    // O programa deve continuar perguntando temperaturas enquanto o usuário desejar. Após o usuário
    // escolher que não quer mais digitar temperaturas, o programa deve informar a média das
    // temperaturas digitadas em graus Celcius e o somatório das temperaturas em Fahrenheit.

    int qtd_temp = 0, opcao = 0;
    float temp_celsius = 0, temp_fahrenheit = 0;

    do
    {
        qtd_temp++;
        float temp_now = get_float("uma temperatura em Celsius");
        temp_celsius += temp_now;
        temp_fahrenheit += (temp_now * 9 / 5) + 32;
        opcao = get_int("deseja digitar outra temperatura? (1 - sim, outra tecla - não)");
    } while (opcao == 1);

    printf("A média das temperaturas em Celsius é %.2f\n", temp_celsius / qtd_temp);
    printf("O somatório das temperaturas em Fahrenheit é %.2f\n", temp_fahrenheit);

    return 0;
}
