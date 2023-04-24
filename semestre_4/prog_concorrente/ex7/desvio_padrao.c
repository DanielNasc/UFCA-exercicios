#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
#include <math.h>
#include <time.h>

#define N 100000000
#define implementation(start, result, end, imp)  start = omp_get_wtime(); \
                                                 result = imp(X); \
                                              end = omp_get_wtime();

double desvio_padrao_serial(double *X);
double desvio_padrao_parallel(double *X);

int main()
{
    srand(time(NULL));
    double *X = (double *) malloc(sizeof(double) * N);
    double start_serial, end_serial, start_parallel, end_parallel, result_serial, result_parallel;

    for (int i = 0; i < N; i++) {
        X[i] = rand();
    }

    implementation(start_serial, result_serial, end_serial, desvio_padrao_serial)
    implementation(start_parallel, result_parallel, end_parallel, desvio_padrao_parallel)

    printf("\t\t\tSerial\t\t\tParallel\n");
    printf("Desvio padrão:\t\t%f\t%f\n", result_serial, result_parallel);
    printf("Time:\t\t\t%f\t\t%f\n", end_serial - start_serial, end_parallel - start_parallel);

    return 0;
}

double desvio_padrao_serial(double *X) {
    double  μ = 0,
            dp = 0;

    for (int i = 0; i < N; i++) {
        μ += X[i];
    }

    μ /= N;

    for (int i = 0; i < N; i++) {
        dp += pow(X[i] - μ, 2);
    }

    dp = sqrt(dp / N);

    return dp;
}

double desvio_padrao_parallel(double *X) {
    double  μ = 0,
            dp = 0;

    #pragma omp parallel for reduction(+:μ)
    for (int i = 0; i < N; i++) {
        μ += X[i];
    }

    μ /= N;

    #pragma omp parallel for reduction(+:dp)
    for (int i = 0; i < N; i++) {
        dp += pow(X[i] - μ, 2);
    }

    dp = sqrt(dp / N);

    return dp;
}