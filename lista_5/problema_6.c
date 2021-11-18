#include <stdio.h>
#include <string.h>
#include <locale.h>
#include "get_num.h"

// Faça um programa que receba duas frases e, em seguida, crie uma string que contenha
// as duas frases concatenadas. OBS: Não pode usar a função strcat Ex.: Frase1: Lá
// vem o disco voador. Frase2: Se for difícil, ande mais devagar.  Frase Concatenada:
// Lá vem o disco voador.Se for difícil, ande mais devagar..

int main()
{
    setlocale(LC_ALL, "Portuguese");
    char frase1[100], frase2[100]; 

    printf("Digite a primeira frase: ");
    scanf("%[^\n]", frase1);
    getchar();

    printf("Digite a segunda frase: ");
    scanf("%[^\n]", frase2);
    getchar();

    char frase_concatenada[strlen(frase1) + strlen(frase2) + 1];

    strcpy(frase_concatenada, frase1);

    for (int i = 0; i < strlen(frase2); i++)
        frase_concatenada[strlen(frase1) + i] = frase2[i];
    frase_concatenada[strlen(frase1) + strlen(frase2)] = '\0';

    printf("Frase concatenada: %s\n", frase_concatenada);

    return 0;
}
