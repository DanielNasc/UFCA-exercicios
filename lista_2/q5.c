#include <stdio.h>
#include <locale.h>
#include <math.h>
#include "get_num.h"

void checar_situacao(float imc);

int main()
{
    setlocale(LC_ALL, "Portuguese");
    float massa = get_float("sua massa"), altura = get_float("sua altura");
    float imc = massa / pow(altura, 2);
    printf("Seu IMC é: %.2f\n", imc);

    checar_situacao(imc);
    
    return 0;
}

void checar_situacao(float imc)
{
    printf("Você está na situação de: ");

    // Um jeito de resolver esse problema sem criar 5 if elses (só que é maior)
    char *situacoes[4] = {"Abaixo do peso","Peso normal", "Sobrepeso", "Obesidade"};
    int imcs[4] = {20, 25, 30, 40};

    for (int i = 0; i < 4; i++)
    {
        if(imc <= imcs[i])
        {   
            printf("%s\n", situacoes[i]);
            return;
        }
    }
    
    // Se IMC > 40
    printf("Obesidade Mórbida\n");
    return;
}
// for (int i = 20, s = 0; i + 5 < 40; i += 5, s++)
// {
//     if (imc > i && imc <= i + 5)
//     {
//         printf("%s\n", situacoes[s]);
//         return;
//     }
// }


// if (imc <= 20) printf("Abaixo do peso");
// else if (imc <= 25) printf("Peso normal");
// else if (imc <= 30) printf("Sobrepeso");
// else if (imc <= 40) printf("Obesidade");