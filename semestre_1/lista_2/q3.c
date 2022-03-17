#include <stdio.h>
#include <locale.h>
#include "get_num.h"

int main()
{
    setlocale(LC_ALL, "Portuguese");

    int n1 = get_int("um número"),n2 = get_int("outro número");

    char *e_divisivel= n1 % n2 == 0 ? "":  "não ";
    printf("%i %sé divisível por %i\n", n1, e_divisivel, n2);
    return 0;
}