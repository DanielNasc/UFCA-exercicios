#include <stdbool.h>

typedef struct tad Tad;

Tad *criar(unsigned int);
bool destruir(Tad *);
bool inserir(Tad *, int);
void imprimir(Tad *);
bool pop(Tad *);
bool verSeExiste(Tad *t, int n);
int pegarQuantidade(Tad *t);
bool shift(Tad *t);

// para fzr em casa
// inserir inicio, ordenado
bool inserirInicio(Tad *, int);
bool inserirOrdenado(Tad *, int);
// remover inicio, valor, indice
bool removerInicio(Tad *, int *);
bool removerIndice(Tad *, int);
bool removerValor(Tad *, int);
// inverter
bool inverter(Tad *);
// concatenar
bool concatenar(Tad *, Tad *);
