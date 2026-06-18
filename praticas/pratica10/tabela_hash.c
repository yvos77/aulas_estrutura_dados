#include <stdio.h>
#include <stdlib.h>
#include "tabela_hash.h"

typedef struct no_t {
    int valor;
    struct no_t *proximo;
} No;

struct hash_t {
    No **tabela;
    int tamanho;
};

static int hash_indice(TabelaHash *hash, int valor) {
    return ((valor % hash->tamanho) + hash->tamanho) % hash->tamanho;
}

TabelaHash *hash_criar(int tamanho) {
    if (tamanho <= 0) {
        return NULL;
    }

    TabelaHash *hash = (TabelaHash *) malloc(sizeof(TabelaHash));
    if (hash == NULL) {
        return NULL;
    }

    hash->tabela = (No **) calloc(tamanho, sizeof(No *));
    if (hash->tabela == NULL) {
        free(hash);
        return NULL;
    }

    hash->tamanho = tamanho;
    return hash;
}

int hash_esta_vazia(TabelaHash *hash) {
    if (hash == NULL) {
        return 1;
    }
    for (int i = 0; i < hash->tamanho; i++) {
        if (hash->tabela[i] != NULL) {
            return 0;
        }
    }
    return 1;
}

int hash_buscar(TabelaHash *hash, int valor) {
    if (hash == NULL) {
        return 0;
    }
    int indice = hash_indice(hash, valor);
    No *atual = hash->tabela[indice];
    while (atual != NULL) {
        if (atual->valor == valor) {
            return 1;
        }
        atual = atual->proximo;
    }
    return 0;
}

int hash_inserir(TabelaHash *hash, int valor) {
    if (hash == NULL) {
        return 0;
    }
    if (hash_buscar(hash, valor)) {
        return 0;
    }

    No *novo = (No *) malloc(sizeof(No));
    if (novo == NULL) {
        return 0;
    }
    novo->valor = valor;

    int indice = hash_indice(hash, valor);
    novo->proximo = hash->tabela[indice];
    hash->tabela[indice] = novo;
    return 1;
}

int hash_remover(TabelaHash *hash, int valor) {
    if (hash == NULL) {
        return 0;
    }
    int indice = hash_indice(hash, valor);
    No *atual = hash->tabela[indice];
    No *anterior = NULL;

    while (atual != NULL && atual->valor != valor) {
        anterior = atual;
        atual = atual->proximo;
    }
    if (atual == NULL) {
        return 0;
    }

    if (anterior == NULL) {
        hash->tabela[indice] = atual->proximo;
    } else {
        anterior->proximo = atual->proximo;
    }

    free(atual);
    return 1;
}

void hash_exibir(TabelaHash *hash) {
    if (hash == NULL) {
        return;
    }
    for (int i = 0; i < hash->tamanho; i++) {
        printf("[%d]: ", i);
        No *atual = hash->tabela[i];
        if (atual == NULL) {
            printf("(vazio)");
        }
        while (atual != NULL) {
            printf("%d", atual->valor);
            if (atual->proximo != NULL) {
                printf(" -> ");
            }
            atual = atual->proximo;
        }
        printf("\n");
    }
}

void hash_destruir(TabelaHash **hash) {
    if (hash == NULL || *hash == NULL) {
        return;
    }
    for (int i = 0; i < (*hash)->tamanho; i++) {
        No *atual = (*hash)->tabela[i];
        while (atual != NULL) {
            No *proximo = atual->proximo;
            free(atual);
            atual = proximo;
        }
    }
    free((*hash)->tabela);
    free(*hash);
    *hash = NULL;
}