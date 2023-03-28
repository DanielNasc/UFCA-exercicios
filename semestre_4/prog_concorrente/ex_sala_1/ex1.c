#include <omp.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define N 500000000

double serial(int x, int x_pos);
double parallel(int x, int x_pos);

int main() {
    srand(time(NULL));

    int x = 0xcafebabe;
    int x_pos = (N / omp_get_num_procs()) * 2 - 1; // last pos in second chunk

    printf("Serial:\n");
    double serial_time = serial(x, x_pos);

    printf("\nParallel:\n");
    double parallel_time = parallel(x, x_pos);

    double speedup = serial_time / parallel_time;
    printf("\nSpeedup: %f\n", speedup);
    printf("Efficiency: %f\n", speedup / omp_get_num_procs());
}

double serial(int x, int x_pos) {
    int * vec = (int*) malloc(N * sizeof(int));

    // initialize the array
    double start = omp_get_wtime();
    for (int i = 0; i < N; i++) {
        vec[i] = rand();
    }
    double end = omp_get_wtime();

    printf("Time to initialize the array: %f\n", end - start);

    vec[x_pos] = x;

    // find x
    int found = -1;

    start = omp_get_wtime();
    for (int i = 0; i < N; i++) {
        if (vec[i] == x) {
            found = i;
            break;
        }
    }
    if (found == x_pos) {
        printf("Found x at position %d\n", found);
    }
    else {
        printf("Found x at position %d, but it should be at position %d\n", found, x_pos);
    }
    end = omp_get_wtime();
    printf("Time to find x: %f\n", end - start);
    free(vec);

    return end - start;

}

double parallel(int x, int x_pos) {
    int *vec = (int*) malloc(N * sizeof(int));
    int threads = omp_get_num_procs();

    // divide the array into chunks
    int chunk_size = floor((double) N / threads);

    double start = omp_get_wtime();
    // initialize the array
    #pragma omp parallel for shared(vec)
    for (int i = omp_get_thread_num() * chunk_size; i < (omp_get_thread_num() + 1) * chunk_size - 1; i++)
    {
        *(vec + i) = rand();
    }
    double end = omp_get_wtime();

    printf("Time to initialize the array: %f\n", end - start);

    // insert x
    vec[x_pos] = x;

    int found = 0;

    // find x
    start = omp_get_wtime();
    #pragma omp parallel for shared(found, vec)
    for (int i = omp_get_thread_num() * chunk_size; i < (omp_get_thread_num() + 1) * chunk_size - 1; i++)
    {
        if (found) continue;
        if (*(vec + i) == x) {
            found = 1;
            printf("Found x at position %d\n", i);

        }
    }
    end = omp_get_wtime();

    printf("Time to find x: %f\n", end - start);
    free(vec);

    return end - start;
}
