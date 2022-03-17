#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "estruturas.h"

#define RESET "\033[0m"

void inicializarTabuleiro(tabuleiro *tab)
{
    tab->pilhas = (pilha **) malloc(5 * sizeof(pilha *));
    tab->players= (player *) malloc(4 * sizeof(player));

    // Incializar players
    char * cores[4] = {"\033[31m", "\033[32m", "\033[33m", "\033[34m"};
    for (int i = 0; i < 4; i++)
    {
        tab->players[i].id = i;
        tab->players[i].cor = (char *) malloc(10 * sizeof(char));
        strcpy(tab->players[i].cor, cores[i]);
        tab->players[i].qtd_pecas = tab->players[i].qtd_pecas_inicializacao = 5;
    }

    // Inicializar pilhas em posições aleatórias
    for (int i = 0; i < 5; i++)
    {
        tab->pilhas[i] = (pilha *) malloc(sizeof(pilha) * 5);
        
        for (int j = 0; j < 5; j++)
        {
            if (i % 2 == 0 && j % 2 == 0 && ((j+i) % 4 == 0))
            {
                tab->pilhas[i][j].player_id = -1;
                continue;
            }

            tab->pilhas[i][j].qtd_pecas = 1;
            
            unsigned int seed = rand() * time(NULL);
            srand(seed);
            int random;
            player * player_random;
            do
            {
                random = rand() % 4;
                player_random = tab->players + random;
            } while (player_random->qtd_pecas_inicializacao == 0);

            player_random->qtd_pecas_inicializacao--;
            tab->pilhas[i][j].player_id = player_random->id;
        }
    }
}

void exibeTabuleiro(tabuleiro * tab)
{
    printf("| a | b | c | d | e |\n");
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            if (tab->pilhas[i][j].player_id == -1)
                printf("|   ");
            else
                printf("| %s%i%s ",
                    tab->players[tab->pilhas[i][j].player_id].cor,
                    tab->pilhas[i][j].qtd_pecas,
                    RESET);
        }
        printf("| %i \n", i);    
    }
}