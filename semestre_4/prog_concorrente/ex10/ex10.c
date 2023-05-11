#include <mpi.h>
#include <stdio.h>

#define N 100000000

int main() {
    MPI_Init(NULL, NULL);

    int n_cpus;

    MPI_Comm_size(MPI_COMM_WORLD, &n_cpus);
    int rank;
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);

    double div_pi, start_time, end_time, sum, x, h;
    long int i;

    start_time = MPI_Wtime();

    h = 1 / (double) N;

    for (i = rank; i < N; i += n_cpus) {
        x = h * ((double) i - .5);
        sum += 4 / (1 + x*x);
    }

    div_pi += h * sum;

    double pi;
    MPI_Reduce(&div_pi, &pi, 1, MPI_DOUBLE, MPI_SUM, 0, MPI_COMM_WORLD);

    if (rank == 0) {
        printf("Valor de pi: %f\n", pi);
        end_time = MPI_Wtime();
        printf("Took: %f\n", end_time - start_time);
    }

    MPI_Finalize();

    return 0;
}