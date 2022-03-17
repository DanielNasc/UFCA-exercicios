#include <stdio.h>
#include <locale.h>
#include <string.h>
#include "get_num.h"

// Faça um programa que receba uma frase e dois caracteres. Depois verique se o pri-
// meiro caractere digitado aparece na frase digitada. Caso armativo, substitua todas as
// aparições do primeiro caractere pela do segundo caractere. Por m imprima a frase alte-
// rada. (Considere letras maiúsculas e minúsculas como diferentes e considere que o usuário
// não vai pedir para modicar letras acentuadas). Ex.: Frase: Lá vem o disco voador,
// Caractere1: o, Caractere2: w- Frase Final: Lá vem w discw vwadwr.

int main()
{
    setlocale(LC_ALL, "Portuguese");
    char frase[100], c1, c2;

    printf("Digite uma frase:\t");
    scanf("%s", frase);

    printf("\nDigite o caractere 1:\t");
    scanf(" %c", &c1);
    printf("Digite o caractere 2:\t");
    scanf(" %c", &c2);

    int esta_na_frase = 0;
    for (int i = 0; i < strlen(frase); i++)
        if(frase[i] == c1)
        {
            esta_na_frase = 1;
            break;
        }
    
    if (!esta_na_frase)
    {
        printf("O caractere dado não está na frase.\n");
        return 0;
    }

    for (int i = 0; i < strlen(frase); i++)
        if(frase[i] == c1) frase[i] = c2;

    printf("\n%s\n", frase);

    return 0;
}
