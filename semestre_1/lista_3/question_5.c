#include <stdio.h>
#include <locale.h>
#include "get_num.h"

// Faça um programa que leia 3 notas, calcule e imprima a média das notas. Após isso,
// o programa deve perguntar se o usuário deseja continuar (1 - SIM, 2 - NÃO). Caso o
// usuário digite 1, o programa deve repetir o processo anterior. Caso o usuário digite 2, o
// programa deverá ser encerrado.

#define TOTAL_NOTAS 3

void get_notas();

int main()
{
    setlocale(LC_ALL, "Portuguese");

    int continuar;

    // Enquanto usuario quiser continuar (apertando 1), rodar o programa de novo
    do
    {
        get_notas();
        continuar = get_int("1 para continuar, ou 2 para finalizar o programa");
    } while (continuar == 1);

    return 0;
}

void get_notas()
{
    float notas[TOTAL_NOTAS];
    // um loop para preencher cada indice do array de notas
    for (int i = 0; i < TOTAL_NOTAS; i++)
    {
        notas[i] = get_float("uma nota");
    }

    // percorrer o array novamente, somando todso os valores do array em uma variavel total.
    float total = 0;
    for (int i = 0; i < TOTAL_NOTAS; i++)
    {
        total += notas[i];
    }

    // E então dividir a soma total das notas pelo total de notas para conseguir a media.
    float media = total / TOTAL_NOTAS;

    printf("A média das notas é: %.2f\n", media);
}