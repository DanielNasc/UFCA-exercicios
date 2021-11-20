#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <malloc.h>

char *get_string(char *str_dsc, int max_size)
{
    // Alocando memória para o vetor de caracteres
    char *str = (char *)malloc((max_size + 1) * sizeof(char));

    // Pedir ao usuário para introduzir uma string
    printf("Digite %s:\n", str_dsc);
    fgets(str, max_size, stdin);

    return str;
}
