#ifndef FILA_H
#define FILA_H

typedef struct fila_t Fila;

Fila *fila_criar(void);
int fila_enfileirar(Fila *fila, int valor);
int fila_desenfileirar(Fila *fila, int *valor_removido);
int fila_inicio(Fila *fila, int *valor_inicio);
void lista_exibir(Fila *fila);
int fila_esta_vazia(Fila *fila);
void fila_destruir(Fila **fila);

#endif