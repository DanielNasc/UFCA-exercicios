typedef struct matriz Matriz;

Matriz *criarMatriz(int c, int l);
void destruirMatriz(Matriz *m);
int acessarValor(Matriz *matriz, int l, int c);
int *acessarLinha(Matriz *matriz, int l);
int *acessarColuna(Matriz *matriz, int c);
void atribuir(Matriz *matriz, int l, int c, int val);
void imprimir(Matriz *m);
