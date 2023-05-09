# OpenMP Tasks

## O que são OpenMP Tasks?

São blocos de código que podem ser executados de forma assíncrona, ou seja, sem a necessidade de sincronização entre as threads. A execução de um bloco de código é chamada de tarefa. As tarefas são executadas por uma thread que é chamada de thread mestre. A thread mestre é a thread que criou a tarefa. A thread mestre pode ser uma thread de uma região paralela ou uma thread de uma região sequencial.

## Como utilizar OpenMP Tasks?

Para utilizar OpenMP Tasks é necessário incluir a biblioteca omp.h e utilizar a diretiva


    pragma omp task

seguido de uma linha de código ou de um bloco de código. 

## Exemplo de OpenMP Tasks

Um dos exemplos mais simples de OpenMP Tasks é o seguinte:

```c
#omp_set_num_threads(2)

#pragma omp default(none)
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
```

Se executarmos esse código, podemos obter a seguinte saída:

```
Task 1
Task 2
Task 1
Task 2
```

Isso ocorreu porque 

## Qual a diferença entre OpenMP Tasks e OpenMP Sections?

## Quando utilizar OpenMP Tasks?
