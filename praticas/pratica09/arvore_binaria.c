#include <stdio.h>
#include <stdlib.h>
#include "arvore_binaria.h"

typedef struct no_t {
    struct no_t *esquerda;
    int valor;
    struct no_t *direita;
} No;

struct arvore_t {
    No *raiz;
};

static No *no_criar(int valor) {
    No *novo = (No *) malloc(sizeof(No));
    if (novo == NULL) {
        return NULL;
    }
    novo->valor = valor;
    novo->esquerda = NULL;
    novo->direita = NULL;
    return novo;
}

static No *no_inserir(No *raiz, int valor, int *inseriu) {
    if (raiz == NULL) {
        No *novo = no_criar(valor);
        *inseriu = (novo != NULL);
        return novo;
    }
    if (valor < raiz->valor) {
        raiz->esquerda = no_inserir(raiz->esquerda, valor, inseriu);
    } else if (valor > raiz->valor) {
        raiz->direita = no_inserir(raiz->direita, valor, inseriu);
    } else {
        *inseriu = 0;
    }
    return raiz;
}

static void no_pre_ordem(No *raiz) {
    if (raiz == NULL) {
        return;
    }
    printf("%d ", raiz->valor);
    no_pre_ordem(raiz->esquerda);
    no_pre_ordem(raiz->direita);
}

static void no_em_ordem(No *raiz) {
    if (raiz == NULL) {
        return;
    }
    no_em_ordem(raiz->esquerda);
    printf("%d ", raiz->valor);
    no_em_ordem(raiz->direita);
}

static void no_pos_ordem(No *raiz) {
    if (raiz == NULL) {
        return;
    }
    no_pos_ordem(raiz->esquerda);
    no_pos_ordem(raiz->direita);
    printf("%d ", raiz->valor);
}

static void no_destruir(No *raiz) {
    if (raiz == NULL) {
        return;
    }
    no_destruir(raiz->esquerda);
    no_destruir(raiz->direita);
    free(raiz);
}

Arvore *arvore_criar(void) {
    Arvore *arvore = (Arvore *) malloc(sizeof(Arvore));
    if (arvore == NULL) {
        return NULL;
    }
    arvore->raiz = NULL;
    return arvore;
}

int arvore_esta_vazia(Arvore *arvore) {
    if (arvore == NULL) {
        return 1;
    }
    return arvore->raiz == NULL;
}

int arvore_inserir(Arvore *arvore, int valor) {
    if (arvore == NULL) {
        return 0;
    }
    int inseriu = 0;
    arvore->raiz = no_inserir(arvore->raiz, valor, &inseriu);
    return inseriu;
}

void arvore_exibir_pre_ordem(Arvore *arvore) {
    if (arvore_esta_vazia(arvore)) {
        printf("Arvore vazia.\n");
        return;
    }
    printf("Pre-ordem:  ");
    no_pre_ordem(arvore->raiz);
    printf("\n");
}

void arvore_exibir_em_ordem(Arvore *arvore) {
    if (arvore_esta_vazia(arvore)) {
        printf("Arvore vazia.\n");
        return;
    }
    printf("Em-ordem:   ");
    no_em_ordem(arvore->raiz);
    printf("\n");
}

void arvore_exibir_pos_ordem(Arvore *arvore) {
    if (arvore_esta_vazia(arvore)) {
        printf("Arvore vazia.\n");
        return;
    }
    printf("Pos-ordem:  ");
    no_pos_ordem(arvore->raiz);
    printf("\n");
}

void arvore_destruir(Arvore **arvore) {
    if (arvore == NULL || *arvore == NULL) {
        return;
    }
    no_destruir((*arvore)->raiz);
    free(*arvore);
    *arvore = NULL;
}