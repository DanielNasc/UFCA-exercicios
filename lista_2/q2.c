#include "get_num.h"

int main()
{
    int n = get_int("um número");

    char *paridade = n % 2 == 0 ? "par" : "impar";

    printf("O numero %i e %s\n", n, paridade);

    return 0;
}