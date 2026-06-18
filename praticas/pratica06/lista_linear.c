#include <stdio.h>
#include <stdlib.h>
#include "lista_linear.h"

typedef struct no_t {
    struct no_t *anterior;
    int valor;
    struct no_t *proximo;
} No;

struct lista_t {
    No *primeiro;
    No *ultimo;
};

/* ------------------------------------------------------------------ */

Lista *lista_criar(void) {
    Lista *lista = (Lista *) malloc(sizeof(Lista));
    if (lista == NULL) {
        return NULL;
    }
    lista->primeiro = NULL;
    lista->ultimo = NULL;
    return lista;
}

int lista_esta_vazia(Lista *lista) {
    if (lista == NULL) {
        return 1;
    }
    return lista->primeiro == NULL;
}

int lista_inserir(Lista *lista, int valor) {
    if (lista == NULL) {
        return 0;
    }

    No *novo = (No *) malloc(sizeof(No));
    if (novo == NULL) {
        return 0;
    }

    novo->valor = valor;
    novo->proximo = NULL;
    novo->anterior = lista->ultimo;

    if (lista_esta_vazia(lista)) {
        lista->primeiro = novo;
    } else {
        lista->ultimo->proximo = novo;
    }

    lista->ultimo = novo;
    return 1;
}

int lista_buscar(Lista *lista, int valor) {
    if (lista == NULL) {
        return -1;
    }

    int posicao = 0;
    No *atual = lista->primeiro;

    while (atual != NULL) {
        if (atual->valor == valor) {
            return posicao;
        }
        atual = atual->proximo;
        posicao++;
    }
    return -1;
}

int lista_remover(Lista *lista, int valor) {
    if (lista_esta_vazia(lista)) {
        return 0;
    }

    No *atual = lista->primeiro;
    while (atual != NULL && atual->valor != valor) {
        atual = atual->proximo;
    }
    if (atual == NULL) {
        return 0;
    }

    if (atual->anterior != NULL) {
        atual->anterior->proximo = atual->proximo;
    } else {
        lista->primeiro = atual->proximo;
    }

    if (atual->proximo != NULL) {
        atual->proximo->anterior = atual->anterior;
    } else {
        lista->ultimo = atual->anterior;
    }

    free(atual);
    return 1;
}

void lista_exibir(Lista *lista) {
    if (lista_esta_vazia(lista)) {
        printf("[] (lista vazia)\n");
        return;
    }

    No *atual = lista->primeiro;
    printf("[");
    while (atual != NULL) {
        printf("%d", atual->valor);
        if (atual->proximo != NULL) {
            printf(", ");
        }
        atual = atual->proximo;
    }
    printf("]\n");
}

void lista_destruir(Lista **lista) {

    if (lista == NULL || *lista == NULL) {
        return;
    }

    No *atual = (*lista)->primeiro;
    while (atual != NULL) {
        No *proximo = atual->proximo;
        free(atual);
        atual = proximo;
    }

    free(*lista);
    *lista = NULL;
}