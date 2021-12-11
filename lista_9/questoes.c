#include <stdio.h>
#include <stdlib.h>
#include "get_num.h"
#include "get_string.h"

// 1
// Crie uma estrutura cidade. Ela deve ter os campos: código, nome, temperatura em celsius
// e temperatura em fahrenheit.
typedef struct {
    int codigo;
    char * nome;
    float temp_c;
    float temp_f;
} cidade;

cidade criar_cidade(int codigo, char *nome, float temp_c);
cidade * encontrar_cidade(cidade cidades[], int codigo, int tamanho);
void imprimir_cidades(cidade cidades[], int tamanho);
void altera_temperatura(cidade * cidade, float nova_temp_celsius);

int main()
{
    // 4
    // Na função principal (main), crie um vetor do tipo estrutura cidade com 3 elementos.
    // Chame a função que gera cidades 3 vezes (questão 3) e atribua cada cidade retornada
    // para uma região do vetor. (De preferência, tentem criar esse vetor na memória heap.)
    cidade vetor_cidades[3];

    printf("=== Preenchendo os campos das cidades ===\n");
    for (int i = 0; i < 3; i++)
    {
        int codigo, ja_existe;
        do {
            printf("\nDigite o código da cidade %i: ", i + 1);
            scanf("%i", &codigo);
            ja_existe = encontrar_cidade(vetor_cidades, codigo, 3) != NULL;
            if (ja_existe)
                printf("Já existe uma cidade com esse código.\n");
        } while (ja_existe);

        vetor_cidades[i] = criar_cidade(
               codigo,
               get_string("Digite o nome da cidade: ", 20),
               get_float("Digite a temperatura da cidade em Celsius: ")); 
    }

    // 8
    // Na função principal (após ter criado as 3 cidades), exiba as opções: [1] - Listar cidades, [2]
    // - Alterar temperatura de cidade, [0] - Sair. Se o usuário digitar 1, exiba a lista de cidades
    // para ele (com as informações de cada uma). Após isso, exiba novamente a mensagem
    // inicial com as 3 opções. Caso ele digite 2, pergunte para ele o código da cidade e a
    // quantidade de graus em celsius que ele deseja alterar. Atualize a temperatura da cidade
    // (usando as funções de buscar cidade e alterar temperatura) e, após isso, mostre novamente
    // as opções iniciais para o usuário. Caso o usuário digite 0, nalize o programa.
   
    int opcao;
    do
    {
        printf("\nDigite o código do que você deseja fazer:\n");
        opcao = get_int("[1] - Listar cidades, [2]- Alterar temperatura de cidade, [0] - Sair:\n");
        
        if (opcao == 1)
            imprimir_cidades(vetor_cidades, 3);
        else if (opcao == 2)
        {
            cidade *pc = encontrar_cidade(
                    vetor_cidades,
                    get_int("Qual o código da cidade que você quer alterar a temperatura? "),
                    3);
            if (!pc)
            {
                printf("Não existe uma cidade com esse código.\n");
                continue;
            }
            
            altera_temperatura(pc, get_float("Qual a nova temperatura da cidade (em Celsius)? "));
        }

    } while (opcao != 0);


    return 0;
}

// 2
// Crie uma função que tenha como parâmetro uma variável do tipo oat que indica uma
// temperatura em Celsius. A função deve retornar o valor em Fahrenheit.
float converter_c_para_f(float c)
{
    return ((9*c)/5) + 32;
}

// 3
// Crie uma função que retorne uma nova estrutura do tipo cidade. Ela deve ter os seguintes
// parâmetros: o código da cidade, o nome da cidade e a temperatura em Celsius. Calcule
// o campo Fahrenheit da estrutura utilizando a função da questão 2.

cidade criar_cidade(int codigo, char *nome, float temp_c)
{
    cidade nova_cidade = {codigo, nome, temp_c, converter_c_para_f(temp_c)};
    return nova_cidade;
}

// 5
// Crie um procedimento que tem como parâmetros um vetor de cidades e o tamanho do
// vetor. O procedimento deve imprimir as informações de todas as cidades registradas no
// vetor.

void imprimir_cidades(cidade cidades[], int tamanho)
{
    printf("\n=== Imprimindo informações das cidades ===\n");
    for (int i = 0; i < tamanho; i++)
    {
        printf("\nCidade %i\n", i + 1);
        printf("Código: %i\n", cidades[i].codigo);
        printf("Nome: %s\n", cidades[i].nome);
        printf("Temperatura em Celsius: %.2fº\n", cidades[i].temp_c);
        printf("Temperatura em Fahrenheit: %.2fº\n", cidades[i].temp_f);
    }
}

// 6
// Crie uma função que tem como parâmetros um vetor de cidades, o código de uma cidade,
// e o tamanho do vetor. A função deve retornar um ponteiro que possui o endereço da
// cidade no vetor que tem o código passado como parâmetro. Caso não exista uma cidade
// com o código passado, retorne NULL.

cidade * encontrar_cidade(cidade cidades[], int codigo, int tamanho)
{
    for (int i = 0; i < tamanho; i++)
        if (cidades[i].codigo == codigo)
            return &cidades[i];
    return NULL;
}

// 7
// Crie um procedimento com nome altera_temperatura que tem como parâmetros uma
// estrutura do tipo cidade e um número real (pode ser negativo) que é a quantidade de
// unidades em Celsius que será incrementado (ou decrementado) da temperatura da cidade.
// Após atualizar a temperatura em Celsius, atualize a temperatura em Fahrenheit também
// (usando a função da primeira questão).

void altera_temperatura(cidade * cidade, float nova_temp_celsius)
{
    cidade->temp_c = nova_temp_celsius;
    cidade->temp_f = converter_c_para_f(nova_temp_celsius);
}
