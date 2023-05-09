#include <omp.h>
#include <stdio.h>
#include <stdlib.h>

int main() {
    #pragma omp parallel default(none) // default none -> 
    {
        #pragma omp task
        {
            printf("Task 1\n");
        }
        #pragma omp task
        {
            printf("Task 2\n");
        }
    }

    return 0;
}

