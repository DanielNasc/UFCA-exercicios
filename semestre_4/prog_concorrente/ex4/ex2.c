#include <omp.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*
    Escreva um programa serial e paralelo em C, com OpenMP, 
    que dado um vetor de inteiros e um valor x, encontrar quantas vezes x 
    ocorre no vetor. Calcular as métricas de desempenho.
*/

#define N 100000000

int count_occurrences_serial(int x, int *vec);
int count_occurrences_parallel(int x, int *vec);


int main()
{
    srand(time(NULL));

    int *vec = (int *) malloc(sizeof(int) * N);
    int x = 23;

    for (int i = 0; i < N; i++) {
        vec[i] = rand() % 25;
    }

    double start_s, end_s,
            start_d, end_d;

    start_s = omp_get_wtime();
    int occ_serial = count_occurrences_serial(x, vec);
    end_s = omp_get_wtime();

    start_d = omp_get_wtime();
    int occ_parallel = count_occurrences_parallel(x, vec);
    end_d = omp_get_wtime();

    printf("Occurrences Serial: %d\tOccurrences Parallel: %d\n", occ_serial, occ_parallel);
    printf("Serial: %f\tParallel: %f\n", end_s - start_s, end_d - start_d);

    double speedup = (end_s - start_s) / (end_d - start_d);
    double eff = speedup / omp_get_num_procs();

    printf("Speedup: %f\nEfficiency: %f\n", speedup, eff);

    return 0;
}



int count_occurrences_serial(int x, int *vec) {
    int occ = 0;

    for (int i = 0; i < N; i++)
        if (vec[i] == x) 
            occ++;

    return occ;
}

int count_occurrences_parallel(int x, int *vec) {
    int occ = 0;

    #pragma omp parallel for reduction(+:occ)
    for (int i = 0; i < N; i++)
        if (vec[i] == x) 
            occ++;

    return occ;
}