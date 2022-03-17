typedef struct {
    int id;
    char * cor;
    int qtd_pecas;
    int qtd_pecas_inicializacao;
} player;

typedef struct {
    int player_id;
    int qtd_pecas;
} pilha;

typedef struct {
    pilha ** pilhas;
    player * players;
} tabuleiro;
