#include <stdio.h>
#include <locale.h>
#include "get_num.h"

// Faça um algoritmo que receba a idade, sexo (1 - masculino, 2 - feminino) e vacina (1 -
// Tomou, 2 - Não tomou) de n pessoas (n informado pelo usuário).

typedef struct {
    int idade;
    int sexo;
    int vacina;
} pessoa;

int checar_se_1_ou_2(int num) {
    if (num != 1 && num != 2) {
        printf("\nO valor informado não é válido.\n");
        return 0;
    }
    return 1;
}

int main()
{
    setlocale(LC_ALL, "Portuguese");
    int n = get_positive_int("o número de pessoas");
    pessoa pessoas[n];

    for (int i = 0; i < n; i++) {
        printf("\nPessoa %d\n", i + 1);
        pessoas[i].idade = get_positive_int("a idade");
        do 
            pessoas[i].sexo = get_int("o sexo (1 - masculino, 2 - feminino)");
        while (!checar_se_1_ou_2(pessoas[i].sexo));

        do
            pessoas[i].vacina = get_int("se tomou a vacina (1 - Tomou, 2 - Não tomou)");
        while(!checar_se_1_ou_2(pessoas[i].vacina));
    }

    // Calcule a média da idade das pessoas do sexo feminino.
    // Calcule a média da idade das pessoas do sexo masculino.
    // Qual o percentual de mulheres que não tomaram vacina?
    // Qual o percentual de homens que tomaram vacina?

    int 
    soma_idades_feminino = 0, soma_idades_masculino = 0, 
    qtd_fem_nao_tomou = 0, qtd_masc_tomou = 0,
    qtd_masc = 0, qtd_fem = 0;

    for (int i = 0; i < n; i++) {
        if (pessoas[i].sexo == 1) {
            soma_idades_masculino += pessoas[i].idade;
            qtd_masc++;
            if (pessoas[i].vacina == 1)
                qtd_masc_tomou++;
        }
        else {
            soma_idades_feminino += pessoas[i].idade;
            qtd_fem++;
            if (pessoas[i].vacina == 2)
                qtd_fem_nao_tomou++;
        }
    }

    float 
    media_idades_feminino = (float) soma_idades_feminino / qtd_fem,
    media_idades_masculino = (float) soma_idades_masculino / qtd_masc,
    percentual_fem_nao_tomou = (float) qtd_fem_nao_tomou * 100 / qtd_fem,
    percentual_masc_tomou = (float) qtd_masc_tomou * 100 / qtd_masc;

    printf("\nA média da idade das mulheres é %.2f\n", media_idades_feminino);
    printf("A média da idade dos homens é %.2f\n", media_idades_masculino);
    printf("O percentual de mulheres que não tomaram vacina é %.2f%%\n", percentual_fem_nao_tomou);
    printf("O percentual de homens que tomaram vacina é %.2f%%\n", percentual_masc_tomou);

    return 0;
}
