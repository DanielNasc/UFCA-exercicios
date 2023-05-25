#include <stdio.h>
#include <stdlib.h>
#include <mpi.h>
#include <math.h>
#include <time.h>

double mean(int *X, int N) {
    int m = 0;

    for (int i = 0; i < N; i++) {
        m += X[i];
    }

    return (double) m / (double) N;
}

double variance(int *X, int N, double mean) {
    double sd = 0;

    for (int i = 0; i < N; i++) {
        sd += pow(((double) X[i] - mean), 2)/N;
    }

    return sd;
}

int *createRandomVariable(int N, int max) {
    int *X = (int *) malloc(sizeof(int) * N);

    for (int i = 0; i < N; i++) {
        X[i] = (rand() % max);
    }

    return X;
}

int main() {
    MPI_Init(NULL, NULL);
    int n_cpus;
    MPI_Comm_size(MPI_COMM_WORLD, &n_cpus);
    int my_rank;
    MPI_Comm_rank(MPI_COMM_WORLD, &my_rank);

    int N = 100, N_sub = 5;
    int *X, *subArrX;
    double m, v, *results = NULL;

    if (my_rank == 0) {
        srand(time(NULL));
        
        X = createRandomVariable(N, 50);
        m = mean(X, N);
    }

    subArrX = (int *) malloc(sizeof(int) * N_sub);

    MPI_Scatter(X, N_sub, MPI_INT, subArrX, N_sub, MPI_INT, 0, MPI_COMM_WORLD);
    MPI_Bcast(&m, 1, MPI_DOUBLE, 0, MPI_COMM_WORLD);

    v = variance(subArrX, N_sub, m);

    if (my_rank == 0) {
        results = (double *) malloc(sizeof(double) * n_cpus);
    }

    MPI_Gather(&v, 1, MPI_DOUBLE, results, 1, MPI_DOUBLE, 0, MPI_COMM_WORLD);

    if (my_rank == 0) {
        double sd = 0;

        for (int i = 0; i < n_cpus; i++) {
            sd += results[0];
        }

        sd = sqrt(sd);

        printf("Desvio Padrão: %f\n", sd);
    }

    MPI_Finalize();
    return 0;
}