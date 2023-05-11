# OPENMPI

## O que é o OpenMPI?

O OpenMPI é uma implementação de código aberto da API MPI usada para programação em computação paralela de alta performance. A MPI é uma especificação para a comunicação de processos em um ambiente distribuído. O OpenMPI é uma implementação de referência da MPI.

O OpenMPI é mantido por um consórcio de organizações acadêmicas, pesquisadores e fornecedores de tecnologia.

## Casos de uso

O OpenMPI é frequentemente usado em ambientes que requerem computação de alta performace para processamento de grandes volumes de dados e cálculos complexos. O OpenMPI é usado em uma variedade de indústrias, incluindo:

- Modelagem e simulação: Pesquisadores de diversas áreas, como física, química, biologia, engenharia e economia, usam o OpenMPI para modelar e simular fenômenos complexos.
- Análise de dados: O OpenMPI é usado para análise de dados em ambientes de computação de alto desempenho.
- Machine learning: Pesquisadores executam algoritmos para treinar modelos mais complexos e precisos de machine learning.
- Dinâmica molecular: O OpenMPI é usado para simular a dinâmica molecular de moléculas biológicas complexas. Ele permite que os pesquisadores realizem simulações em escala maior e mais rápida para entender melhor o comportamento de moléculas biológicas.

## Exemplo de uso - by ChatGPT

Um exemplo simples de uso do OpenMPI pode ser a implementação de um programa de soma de vetores em paralelo. Suponha que temos dois vetores A e B, cada um com um milhão de elementos, e queremos somá-los em paralelo usando quatro processos.

Aqui está um exemplo de código que usa o OpenMPI para realizar essa tarefa:

```c
#include <stdio.h>
#include <stdlib.h>
#include <mpi.h>

#define N 1000000

int main(int argc, char *argv[]) {
    int rank, size, i;
    int *A, *B, *C;
    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    if (rank == 0) {
        // Inicializa os vetores A e B com valores aleatórios
        A = (int*) malloc(N * sizeof(int));
        B = (int*) malloc(N * sizeof(int));
        for (i = 0; i < N; i++) {
            A[i] = rand() % 100;
            B[i] = rand() % 100;
        }
    }

    // Divide os vetores A e B entre os processos
    int n = N / size;
    int *localA = (int*) malloc(n * sizeof(int));
    int *localB = (int*) malloc(n * sizeof(int));
    MPI_Scatter(A, n, MPI_INT, localA, n, MPI_INT, 0, MPI_COMM_WORLD);
    MPI_Scatter(B, n, MPI_INT, localB, n, MPI_INT, 0, MPI_COMM_WORLD);

    // Calcula a soma local de cada processo
    int *localC = (int*) malloc(n * sizeof(int));
    for (i = 0; i < n; i++) {
        localC[i] = localA[i] + localB[i];
    }

    // Combina as somas locais em um vetor global C no processo 0
    if (rank == 0) {
        C = (int*) malloc(N * sizeof(int));
    }
    MPI_Gather(localC, n, MPI_INT, C, n, MPI_INT, 0, MPI_COMM_WORLD);

    if (rank == 0) {
        // Imprime o vetor resultado C
        for (i = 0; i < N; i++) {
            printf("%d ", C[i]);
        }
        printf("\n");
        free(A);
        free(B);
        free(C);
    }

    free(localA);
    free(localB);
    free(localC);

    MPI_Finalize();
    return 0;
}
```
