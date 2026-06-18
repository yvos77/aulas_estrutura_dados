#include <stdio.h>
#include <stdlib.h>
#include "fila.h"

typedef struct no_t {
    int valor;
    struct no_t *proximo;
} No;

struct fila_t {
    No *inicio;
    No *fim;
};

Fila *fila_criar(void) {
    Fila *fila = (Fila *) malloc(sizeof(Fila));
    if (fila == NULL) {
        return NULL;
    }
    fila->inicio = NULL;
    fila->fim = NULL;
    return fila;
}

int fila_esta_vazia(Fila *fila) {
    if (fila == NULL) {
        return 1;
    }
    return fila->inicio == NULL;
}

int fila_enfileirar(Fila *fila, int valor) {
    if (fila == NULL) {
        return 0;
    }

    No *novo = (No *) malloc(sizeof(No));
    if (novo == NULL) {
        return 0;
    }
    novo->valor = valor;
    novo->proximo = NULL;

    if (fila_esta_vazia(fila)) {
        fila->inicio = novo;
    } else {
        fila->fim->proximo = novo;
    }
    fila->fim = novo;
    return 1;
}

int fila_desenfileirar(Fila *fila, int *valor_removido) {
    if (fila_esta_vazia(fila)) {
        return 0;
    }

    No *removido = fila->inicio;
    if (valor_removido != NULL) {
        *valor_removido = removido->valor;
    }

    fila->inicio = removido->proximo;
    if (fila->inicio == NULL) {
        fila->fim = NULL;
    }

    free(removido);
    return 1;
}

int fila_inicio(Fila *fila, int *valor_inicio) {
    if (fila_esta_vazia(fila)) {
        return 0;
    }
    if (valor_inicio != NULL) {
        *valor_inicio = fila->inicio->valor;
    }
    return 1;
}

void lista_exibir(Fila *fila) {
    if (fila_esta_vazia(fila)) {
        printf("Fila vazia.\n");
        return;
    }

    No *atual = fila->inicio;
    printf("Inicio -> ");
    while (atual != NULL) {
        printf("[%d]", atual->valor);
        if (atual->proximo != NULL) {
            printf(" -> ");
        }
        atual = atual->proximo;
    }
    printf(" -> Fim\n");
}

void fila_destruir(Fila **fila) {
    if (fila == NULL || *fila == NULL) {
        return;
    }

    No *atual = (*fila)->inicio;
    while (atual != NULL) {
        No *proximo = atual->proximo;
        free(atual);
        atual = proximo;
    }

    free(*fila);
    *fila = NULL;
}