#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <assert.h>

__int8_t sign(double x) {
    if (x > 0) return 1;
    if (x < 0) return -1;
    return 0;
}

// bisseção sem tolerância
double * 
bissecao (double (*f)(double), double a, double b, int max_i ) 
{
    double *ret = malloc(sizeof(double) * 2);

    if (a > b) {
        printf("O intervalo dado é inválido.\n");
        exit(1);
    }

    if (sign(f(a)) == sign(f(b))) {
        printf("Não há raiz no intervalo dado.\n");
        exit(1);
    }

    double x;
    int i = 0;
    while (i < max_i) {
        x = (a + b) / 2;

        if (f(x) == 0 || f(x) == -0) {
            *(ret) = x;
            *(ret + 1) = (double) i;
            return ret;
        }

        if (sign(f(x)) * sign(f(a)) < 0) {
            b = x;
        } else {
            a = x;
        }

        i++;
    }

    *ret = x;
    *(ret + 1) = (double) i;
    return ret;
}

double f(double x) {
    return pow(x, 2) - 2;
}

int main() {
    double a = 1, b = 2;
    int max_i = 1000000;
    double *result = bissecao(f, a, b, max_i); // [0] = raiz (ou o mais próximo dela), [1] = iteracoes
    
    if (*(result + 1) == max_i)
        printf("f(%.12f) = %lf (iteracoes: %lf, limite de iteracoes atingido)\n", *(result), f(*(result)), *(result + 1));
    else
        printf("f(%.12lf) = %lf (iteracoes: %lf)\n", *(result), f(*(result)), *(result + 1));

    free(result);

    return 0;
}