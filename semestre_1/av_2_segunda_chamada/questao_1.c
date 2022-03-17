#include <stdio.h>
#include <stdlib.h>

// Crie uma estrutura produto com os campos: código (int), preço (oat).
typedef struct {
    int codigo;
    float preco;
} Produto;

void testes();

int main()
{
    testes();
    return 0;
}

/*
(a) Crie um procedimento que tenha como parâmetro um produto e um valor (int). O
procedimento deve adicionar o valor no preço do produto. (OBS: A passagem do
produto deve ser feita por referência)
*/

void adiciona_valor(Produto *p, int valor) {
    p->preco += valor;
}

/*
Crie uma função que tenha como parâmetro um vetor de produtos e o seu tamanho.
A função deve retornar a média dos preços dos produtos nesse vetor
*/

float media_dos_precos(Produto *p, int tamanho)
{
    float soma = 0;
    for (int i = 0; i < tamanho; i++)
        soma += p[i].preco;
    return soma / tamanho;
}

/*
Crie uma função que tenha como parâmetro um vetor de produtos e o seu tamanho.
A função deve retornar a quantidade de produtos que tem preço menor do que 100
*/

int qtd_precos_menores_q_100(Produto *p, int tamanho)
{
    int qtd = 0;
    for (int i = 0; i < tamanho; i++)
        if (p[i].preco < 100)
            qtd++;
    return qtd;
}

/*
Crie uma função que tenha como parâmetro um vetor de produtos e o seu tamanho.
A função deve retornar o endereço inicial de um vetor de inteiros (alocado na memória
heap). Os elementos do vetor devem ser os códigos dos produtos que possuírem preço
menor do que 100. Além disso, deve ser colocado o valor -1 na última posição desse
vetor. Por exemplo, supondo que no vetor de produtos os códigos 1, 5 e 8 são os
produtos com preço menor do que 100, o vetor retornado deverá ser [1, 5, 8, -1].
*/

int * codigos_menores_q_100(Produto *p, int tamanho)
{
    int * codigos = (int *) malloc(sizeof(int) * (qtd_precos_menores_q_100(p, tamanho) + 2));
    int qtd_codigos_ja_inseridos = 0;

    for (int i = 0; i < tamanho; i++)
    {
        if (p[i].preco < 100)
        {
            codigos[qtd_codigos_ja_inseridos] = p[i].codigo;
            qtd_codigos_ja_inseridos++;
        }
    }

    codigos[qtd_codigos_ja_inseridos] = -1;
    return codigos;
}

void testes()
{
    // OBS: esse teste não tem nenhuma validação, apenas para testar a função
    int n;
    printf("n: ");
    scanf("%d", &n);
    Produto *p = (Produto *) malloc(sizeof(Produto) * n);

    printf("\n");
    for (int i = 0; i < n; i++)
    {
        printf("Produto %d\n", i);
        printf("Codigo: ");
        scanf("%d", &p[i].codigo);
        printf("Preco: ");
        scanf("%f", &p[i].preco);
        printf("\n");
    }

    char opcao;
    printf("Quer adicionar um valor aos preços dos produtos? (s/n): ");
    scanf(" %c", &opcao);

    if (opcao == 83 || opcao == 115)
    {
        int id;
        float valor;
        printf("\nId do produto: ");
        scanf("%d", &id);
        printf("Valor: ");
        scanf("%f", &valor);

        printf("\nValor antes: %.2f\n", p[id].preco);
        adiciona_valor(&p[id], valor);
        printf("Valor depois: %.2f\n", p[id].preco);
    }

    printf("\nMedia dos preços: %.2f\n", media_dos_precos(p, n));
    int * codigos = codigos_menores_q_100(p, n);
    printf("\nCodigos dos produtos com preços menores que 100: \n[");
    for (int i = 0; *(codigos + i) != -1; i++)   
        printf(" %d", *(codigos + i));
    printf(" ]\n");

    free(p);
    free(codigos);
}
