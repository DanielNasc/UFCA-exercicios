#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
#include <time.h>

int *genVec();
double serialTime(int *);
double parallelTime(int *);

#define N 500000000
// #define omp_get_num_procs() omp_get_num_procs()
#define prtln printf("\n\n");

int main()
{
    srand(time(NULL));
    printf("Preechendo vetor\n");
    int *vec = genVec();
    printf("Vetor preenchido\n");

    prtln    
    double serial = serialTime(vec);
    prtln
    double parallel = parallelTime(vec);

    double speedup = serial / parallel;
    double eff = speedup / omp_get_num_procs();

    prtln
    printf("Speedup:: %.6f\n", speedup);
    printf("Eficiencia:: %.6f\n", eff);    
    printf("omp_get_num_procs() %d\n", omp_get_num_procs());

    return 0;
}

int *genVec() {
    int *vec = (int*) malloc(sizeof(int) * N);
    
    for (int i = 0; i < N; i++)
        vec[i] = rand() % 100000;

    return vec;
}

double serialTime(int *vec) {
    double start, end, total;
    double media = 0;

    start = omp_get_wtime();
    for (int i = 0; i < N; i++)
        media += vec[i];
    media /= N;
    end = omp_get_wtime();
    total = end - start;

    printf("Media:: %.6f\n", media);
    printf("Tempo Gasto:: Serial: %.6f\n", total);

    return total;
}

double parallelTime(int *vec) {
    double start, end, total;
    double media = 0;

    start = omp_get_wtime();
    // #pragma omp parallel num_threads(omp_get_num_procs())
    // {
    #pragma omp parallel for reduction(+:media)
    for(int i = 0; i < N; i++)
        media += vec[i];
    // }
    media /= N;
    end = omp_get_wtime();
    total = end - start;

    printf("Media:: %.6f\n", media);
    printf("Tempo Gasto:: Paralelo: %.6f\n", total);

    return total;
}