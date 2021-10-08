#include "get_num.h"

int main()
{
    int n1 = get_int("um numero"),n2 = get_int("outro numero");
    char *e_divisivel= n1 % n2 == 0 ? "":  "nao ";
    printf("%i %se divisivel por %i\n", n1, e_divisivel, n2);
    return 0;
}