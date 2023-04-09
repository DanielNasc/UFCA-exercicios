#include <omp.h>
#include <stdio.h>
#include <stdlib.h>

#define print_result(result, time) \
    printf("pi = %6f, time = %6f\n", result, time);

double pi_serial(int N);
double pi_critical(int N);
double pi_atomic(int N);

int main() {
    double pi, start, end;
    int N = 100000000;

    printf("Parallelizing with critical\n");

    start = omp_get_wtime();
    pi = pi_critical(N);
    end = omp_get_wtime();

    print_result(pi, end - start);

    printf("Parallelizing with atomic\n");

    start = omp_get_wtime();
    pi = pi_atomic(N);
    end = omp_get_wtime();

    print_result(pi, end - start);
}

double f(double x) 
{
    return 4.0 / (1.0 + x * x);
}

double pi_serial(int N) 
{
    double step = 1.0 / (double) N;
    double pi;
    int i;

    pi = 0.0;
    for (i = 0; i < N; i++) {
        double x = (i + 0.5) * step;
        pi += f(x);
    }
    pi *= step;

    return pi;
}

double pi_critical(int N) 
{
    double step = 1.0 / (double) N;
    double pi;
    int procs = omp_get_num_procs();

    pi = 0.0;
    
    #pragma omp parallel num_threads(procs)
    {
        double x, sum = 0.0;
        int i, id, nthrds;

        id = omp_get_thread_num();
        nthrds = omp_get_num_threads();

        for (i = id; i < N; i += nthrds) {
            x = (i + 0.5) * step;
            sum += f(x);
        }

        #pragma omp critical
            pi += sum * step;
    }

    return pi;
}

double pi_atomic(int N) 
{
    double step = 1.0 / (double) N;
    double pi;
    int procs = omp_get_num_procs();

    pi = 0.0;
    
    #pragma omp parallel num_threads(procs)
    {
        double x, sum = 0.0;
        int i, id, nthrds;

        id = omp_get_thread_num();
        nthrds = omp_get_num_threads();

        for (i = id; i < N; i += nthrds) {
            x = (i + 0.5) * step;
            sum += f(x);
        }

        #pragma omp atomic
            pi += sum * step;
    }

    return pi;
}

double pi_paralelo() {
    int i;
    double step, pi;
    double start, end, time;

    int STEPS = 100000000;
    
    printf("Iniciando método paralelo...\n");
    start = omp_get_wtime();
    step = 1.0/(double)STEPS;

    #pragma omp parallel num_threads(4)
    {
        double x,sum=0.0;
        int i, id, nthrds;
        id = omp_get_thread_num();
        nthrds = omp_get_num_threads();

        for(i = id, sum = 0.0; i < STEPS; i = i+nthrds) {
            x = i * step;
            sum = sum + 4.0/(1.0 + x * x);
        }
        
        #pragma omp critical
            pi = step * sum;
    }
    
    end = omp_get_wtime();
    time = end - start;
    printf("Pi: %f\n", pi);
    printf("Tempo Paralelo: %f\n\n", time);
    return time;
}