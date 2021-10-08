#include <stdio.h>
#include <locale.h>
#include "get_num.h"

int main()
{
    setlocale(LC_ALL, "Portuguese");
    int codigo;

    do
    {
        codigo = get_int("um código entre 1 e 9");
    } 
    while (codigo < 0 || codigo > 9);
    
    char *mensagens[9] = 
    {
        "Lave as mãos.",
        "Passe álcool em gel.",
        "Use máscara",
        "Cuide dos idosos",
        "Cultive paciência",
        "Cultive sabedoria",
        "Ame o próximo",
        "Exercite a disciplina",
        "Acalme a mente"
    };

    printf("%s\n", mensagens[codigo - 1]);

    return 0;
}