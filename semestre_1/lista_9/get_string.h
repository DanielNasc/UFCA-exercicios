#include <stdio.h>
#include <stdlib.h>

char *get_string(char *str_dsc, int size)
{
    // Alocando memória para o vetor de caracteres
    char *str = (char *)malloc((size + 1) * sizeof(char));

    // Pedir ao usuário para introduzir uma string
    printf("%s", str_dsc);
    scanf("%s", str);

    return str;
}
