// Construa um algoritmo que leia três números do teclado e calcule a média. Se a média for
// maior ou igual à sete, imprima: "Parabéns, você foi aprovado!". Caso contrário, imprima:
// "Você fará prova nal!".
#include "get_num.h"

#define TOTAL_NOTAS 3

int main()
{
    // Para evitar repetições caso eu queria reutilizar esse programa para mais notas depois,
    float notas[TOTAL_NOTAS];
    // é so criar um array de notas e criar um loop para preencher cada indice dele.
    for (int i = 0; i < TOTAL_NOTAS; i++)
    {
        notas[i] = get_float("uma nota");
    }

    // Depois é só percorrer ele novamente, somando todso os valores do array em uma variavel total.
    float total = 0;
    for (int i = 0; i < TOTAL_NOTAS; i++)
    {
        total += notas[i];
    }

    // E então dividir a soma total das notas pelo total de notas para conseguir a media.
    float media = total / TOTAL_NOTAS;

    // Ao inves de criar um IF ELSE para "printar" duas strings diferentes, usa-se um operador ternario.
    char *conlusao = media >= 7 ? "Parabéns, você foi aprovado!" : "Você fará prova final!";
    printf("%s\n", conlusao);

    return 0;
}