#include <stdio.h>
#include <string.h>
#include "get_num.h"
#include "get_string.h"

// Faça um programa que verique se duas frases digitadas são iguais. OBS: Não pode
// usar a função strcmp

int checar_se_sao_iguais(char *frase1, char *frase2);

int main()
{
    // Declaração de variáveis
    char 
    *frase1 = get_string("a primeira frase", 100),
    *frase2 = get_string("a segunda frase", 100);

    // Imprime o resultado
    if (checar_se_sao_iguais(frase1, frase2)) 
        printf("As frases são iguais\n");
    else 
        printf("As frases não são iguais\n");

    return 0;
}

int checar_se_sao_iguais(char *frase1, char *frase2) {
    // Checa se as frases têm o mesmo tamanho
    if (strlen(frase1) != strlen(frase2)) 
        return 0;
    
    // Compara as duas frases
    for (int i = 0; i < strlen(frase1); i++) {
        if (frase1[i] != frase2[i]) {
        return 0;
        }
    }
    return 1;
}