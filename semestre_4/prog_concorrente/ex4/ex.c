#include <omp.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/*
    Escreva um programa em C, com OpenMP, que dado um numero maior do
    que 10^9, calcular a soma de todos os seus divisores.

    Utilize os metodos:
        - Explicitando uma memoria critica
        - Redução com for estático
        - Redução com for dinâmico
*/

#define print_result(s) printf("Abordagem %s: %d\n", s, soma);
#define print_time(s, t) printf("Tempo %s: %f\n", s, t);
#define execute(start, end, f) start = omp_get_wtime(); \
                                f(n); \
                                end = omp_get_wtime();

unsigned int soma_divisores_serial(const unsigned int n);
unsigned int soma_divisores_parallel_static(const unsigned int n);
unsigned int soma_divisores_parallel_dynamic(const unsigned int n);
unsigned int soma_divisores_parallel_dynamic_atomic(const unsigned int n);
unsigned int soma_divisores_parallel_static_atomic(const unsigned int n);

int main() 
{
    const unsigned int n = pow(10, 9);
    double  start_s, end_s,
            start_psr, end_psr,
            start_pdr, end_pdr,
            start_psa, end_psa,
            start_pda, end_pda;

    execute(start_s, end_s, soma_divisores_serial)
    execute(start_psr, end_psr, soma_divisores_parallel_static)
    execute(start_psa, end_psa, soma_divisores_parallel_static_atomic)
    execute(start_pdr, end_pdr, soma_divisores_parallel_dynamic)
    execute(start_pda, end_psa, soma_divisores_parallel_dynamic_atomic)

    printf("\n");

    print_time("serial", end_s - start_s)
    print_time("parallel static with reduction", end_psr - start_psr)
    print_time("parallel dynamic with reduction", end_pdr - start_pdr)
    print_time("parallel static with atomic", end_pdr - start_pdr)
    print_time("parallel dynamic with atomic", end_pdr - start_pdr)
    
    return 0;
}

unsigned int soma_divisores_serial(const unsigned int n)
{
    int soma = 1 + n; // 1 * n (2 divisores)

    for (int i = 2; i < floor((double) n/2); i++)
    {
        if (n % i == 0) {
            soma += i;
        }
    }

    print_result("serial")

    return soma;
}

unsigned int soma_divisores_parallel_static(const unsigned int n)
{
    int soma = n + 1; // 1 + n
    int max = floor((double) n/2);

    #pragma omp parallel for schedule(static) reduction(+: soma)
    for (int i = 2; i < max; i++)
    {
        if (n % i == 0) {
            soma += i;
        }
    }

    print_result("parallel static with reduction")

    return soma;
}


unsigned int soma_divisores_parallel_dynamic(const unsigned int n)
{
    int soma = n + 1;
    int max = floor((double) n/2);

    #pragma omp parallel for schedule(dynamic, 64) reduction(+: soma)
    for (int i = 2; i < max; i++)
    {
        if (n % i == 0) {
            soma += i;
        }
    }

    print_result("parallel dynamic with reduction")

    return soma;
}

unsigned int soma_divisores_parallel_dynamic_atomic(const unsigned int n)
{
    int soma = n + 1;
    int max = floor((double) n/2);

    #pragma omp parallel for schedule(dynamic, 64)
    for (int i = 2; i < max; i++)
    {
        if (n % i == 0) {
            #pragma omp atmoic
                soma += i;
        }
    }

    print_result("parallel dynamic with atomic")

    return soma;
}

unsigned int soma_divisores_parallel_static_atomic(const unsigned int n) 
{
    int soma = n + 1; // 1 + n
    int max = floor((double) n/2);

    #pragma omp parallel for schedule(static)
    for (int i = 2; i < max; i++)
    {
        if (n % i == 0) {
            soma += i;
        }
    }

    print_result("parallel static with atomic")

    return soma;
}