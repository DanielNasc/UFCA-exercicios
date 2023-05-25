#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <mpi.h>

#define SIZE 100000
#define MAIN_RANK 0

__int8_t *generate_bin_array(int size) {
    __int8_t *array = (__int8_t *) malloc(sizeof(__int8_t) * (size + 1));

    for (int i = 0; i < size; i++) {
        array[i] = rand() % 2;
    }

    array[size] = 0;

    return array;
}

int main() {
    MPI_Init(NULL, NULL);

    int ncpus, rank;

    MPI_Comm_size(MPI_COMM_WORLD, &ncpus);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);

    __int8_t *array;

    if (rank == MAIN_RANK) {
        srand(time(NULL));
        array = generate_bin_array(SIZE);
    }

    int sub_size = SIZE / ncpus, partial_ones_amount = 0;
    __int8_t *sub_array = (__int8_t *) malloc(sizeof(__int8_t) * sub_size);

    MPI_Scatter(array, sub_size, MPI_INT8_T, sub_array, sub_size, MPI_INT8_T, 0, MPI_COMM_WORLD);

    for (int i = 0; i < sub_size; i++) 
        if (sub_array[i] == 1) 
            partial_ones_amount++;

    int *results;

    if (rank == MAIN_RANK) results = (int *) malloc(sizeof(int) * ncpus);

    MPI_Gather(&partial_ones_amount, 1, MPI_INT, results, 1, MPI_INT, 0, MPI_COMM_WORLD);

    if (rank == MAIN_RANK) {
        int ones_amount = 0;

        for (int i = 0; i < ncpus; i++) {
            ones_amount += results[i];
        }

        printf("Quantidade de 1s: %d\n", ones_amount);


        if (ones_amount % 2 != 0) {
            printf("É necessário adicionar mais um 1.\n");
            
            array[SIZE] = 1;

            printf("1 Adicionado\n");
        }
    }

    MPI_Finalize();
}