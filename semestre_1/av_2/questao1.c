#include <stdio.h>
#include "get_num.h"

// Crie uma estrutura aluno. Ela deve ter os campos matricula e notas. A matricula deve
// ser do tipo inteiro, enquanto notas deve ser um vetor do tipo foat e com o tamanho três.

typedef struct {
    int matricula;
    float notas[3];
} aluno;

float calcular_media(aluno a);
int aluno_com_maior_media(aluno aln[], int tamanho);
int qtd_alunos_com_media_maior_que_7(aluno aln[], int tamanho);
int checar_se_matricula_ja_existe(aluno aln[], int tamanho, int matricula);

int main()
{
    // Testes 

    int n = get_positive_int("Digite a quantidade de alunos: "  );
    aluno aln[n];

    printf("\nPreencha os dados dos alunos:\n");
    for (int i = 0; i < n; i++)
    {
        printf("\nAluno %d:\n", i + 1);
        
        int ja_existe;
        do {
            aln[i].matricula = get_positive_int("Digite a matricula do aluno: ");
            ja_existe = checar_se_matricula_ja_existe(aln, i, aln[i].matricula);
            if (ja_existe)
                printf("Matricula ja existe!\n");
        } while (ja_existe);
        
        get_float_array(aln[i].notas, 3, "nota do aluno: ", 'a');

    }

    printf("\nResultados ==============================\n");
    for (int i = 0; i < n; i++)
    {
        printf("\nAluno %d:\n", i + 1);
        printf("\nMatricula: %d\n", aln[i].matricula);
        printf("Notas: ");
        for (int j = 0; j < 3; j++)
        {
            printf("%.2f ", aln[i].notas[j]);
        }
        printf("\nMedia: %.2f\n", calcular_media(aln[i]));
    }

    printf("\nMatrícula do aluno com maior media: %d\n", aluno_com_maior_media(aln, n));
    printf("Quantidade de alunos com a média maior que 7: %d\n", qtd_alunos_com_media_maior_que_7(aln, n));

    return 0;
}

// Crie uma função que tenha como parâmetro um aluno. A função deve retornar a
// média desse aluno.

float calcular_media(aluno a)
{
    float media = 0;

    for (int i = 0; i < 3; i++)
        media += a.notas[i];

    return media / 3;
}

// Crie uma função que tenha como parâmetro um vetor de alunos e o tamanho do
// vetor. A função deve retornar a matrícula do aluno que tem a maior média.

int aluno_com_maior_media(aluno aln[], int tamanho)
{
    int matricula_do_aluno_com_maior_media;
    float maior_media = 0;

    for (int i = 0; i < tamanho; i++)
    {
        float media = calcular_media(aln[i]);

        if (media > maior_media)
        {
            maior_media = media;
            matricula_do_aluno_com_maior_media = aln[i].matricula;
        }
    }

    return matricula_do_aluno_com_maior_media;
}

// Crie uma função que tenha como parâmetro um vetor de alunos e o seu tamanho.
// A função deve retornar a quantidade de alunos com média acima de 7.

int qtd_alunos_com_media_maior_que_7(aluno aln[], int tamanho)
{
    int qtd_alunos_com_media_maior_que_7 = 0;

    for (int i = 0; i < tamanho; i++)
    {
        float media = calcular_media(aln[i]);

        if (media > 7)
            qtd_alunos_com_media_maior_que_7++;
    }

    return qtd_alunos_com_media_maior_que_7;
}

// Checar se a matrícula já existe
int checar_se_matricula_ja_existe(aluno aln[], int tamanho, int matricula)
{
    for (int i = 0; i < tamanho; i++)
    {
        if (aln[i].matricula == matricula)
            return 1;
    }

    return 0;
}