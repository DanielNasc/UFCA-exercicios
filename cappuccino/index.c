#include <stdio.h>
#include "tabuleiro.h"

/*
    Cappuccino é um jogo abstrato para até quatro jogadores cujo objetivo é ter a maior
    quantidade de pilhas sobre seu domínio ao final da partida. Esse objetivo é alcançado
    empilhando peças durante a partida. Neste projeto a versão será apenas para 4 jogadores, não
    precisando implementação para 2 ou 3 jogadores.
*/

int main()
{
    tabuleiro * tab = (tabuleiro *) malloc(sizeof(tabuleiro));

    // Inicialização do tabuleiro
    inicializarTabuleiro(tab);
    
    // Exibição do tabuleiro
    exibeTabuleiro(tab);

    return 0;   
}