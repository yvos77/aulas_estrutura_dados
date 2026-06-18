#ifndef LISTA_LINEAR_H
#define LISTA_LINEAR_H

typedef struct lista_t Lista;

Lista *lista_criar(void);

int lista_inserir(Lista *lista, int valor);

int lista_remover(Lista *lista, int valor);

int lista_buscar(Lista *lista, int valor);

void lista_exibir(Lista *lista);

int lista_esta_vazia(Lista *lista);

void lista_destruir(Lista **lista);

#endif 