#include <stdio.h>
#include <stdlib.h>
#include <mpi.h>
#include <math.h>
#include <time.h>

#define SIZE 100
#define RANDOM_VAR_MAX 50

double mean(int *X) {
    int m = 0;

    for (int i = 0; i < SIZE; i++) {
        m += X[i];
    }

    return (double) m / (double) SIZE;
}

double variance(int *X, int N, double mean) {
    double sd = 0;

    for (int i = 0; i < N; i++) {
        sd += pow(((double) X[i] - mean), 2)/SIZE;
    }

    return sd;
}

int *createRandomVariable() {
    int *X = (int *) malloc(sizeof(int) * SIZE);

    for (int i = 0; i < SIZE; i++) {
        X[i] = (rand() % RANDOM_VAR_MAX);
    }

    return X;
}

double standartDeviationSerial(int *X, double m) {
    double sd = variance(X, SIZE, m);

    return sqrt(sd);
}

int main() {
    MPI_Init(NULL, NULL);
    int n_cpus;
    MPI_Comm_size(MPI_COMM_WORLD, &n_cpus);
    int my_rank;
    MPI_Comm_rank(MPI_COMM_WORLD, &my_rank);

    int N_sub = SIZE / n_cpus;
    int *X, *subArrX;
    double  m, v, *results = NULL, 
            start_serial, end_serial,
            start_mpi, end_mpi;

    if (my_rank == 0) {
        srand(time(NULL));
        
        X = createRandomVariable();
        m = mean(X);

        printf("Média: %f\n", m);

        printf("\n");
        printf("Começando o cálculo do desvio padrão de forma serial\n");
        start_serial = MPI_Wtime();
        double serialSd = standartDeviationSerial(X, m);
        end_serial = MPI_Wtime();
        printf("Desvio Padrão: %f\n", serialSd);
        printf("Tempo decorrido: %f\n", end_serial - start_serial);

        printf("\n");
        printf("Começando o cálculo do desvio padrão de forma paralela\n");
        start_mpi = MPI_Wtime();
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
            sd += results[i];
        }

        sd = sqrt(sd);

        end_mpi = MPI_Wtime();

        printf("Desvio Padrão: %f\n", sd);
        printf("Tempo decorrido: %f\n", end_mpi - start_mpi);
    }

    MPI_Finalize();
    return 0;
}