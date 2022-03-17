#include <stdio.h>
#include <locale.h>
#include "get_num.h"

// Faça uma função que tenha um parâmetro inteiro n e que retorne 1 se n for positivo, -1
// se n for negativo e 0 caso n seja nulo.

char *positivo_negativo_nulo(int n);

int main()
{
    setlocale(LC_ALL, "Portuguese");
    printf("O número digitado é: %s\n", positivo_negativo_nulo(get_int("Digite um número: ")));
    return 0;
}

char *positivo_negativo_nulo(int n) {
    if (n > 0) {
        return "Positivo";
    } else if (n < 0) {
        return "Negativo";
    } else {
        return "Nulo";
    }
}