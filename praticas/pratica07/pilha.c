/*
 * pilha.c
 * -------
 * Implementacao do TDA Pilha como estrutura dinamica encadeada.
 *
 * Diferenca-chave para a lista da pratica 06:
 *   - A pilha so mexe numa ponta: o TOPO.
 *   - Por isso o no precisa apenas de 'proximo' (encadeamento simples),
 *     nao de 'anterior'. Nao ha necessidade de andar para tras.
 *   - A struct da pilha guarda apenas o ponteiro 'topo'. Nao precisamos
 *     de 'base' porque nunca inserimos nem removemos pela base.
 *
 * Empilhar e desempilhar acontecem sempre no inicio do encadeamento
 * (no topo), e por isso ambas as operacoes custam O(1): nao percorremos
 * a estrutura, so ajustamos um ponteiro.
 */

#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"

/*
 * No da pilha: guarda o valor e aponta para o proximo no abaixo dele.
 * O 'proximo' do no do topo aponta para o segundo elemento, e assim
 * por diante, ate o ultimo no (a base), cujo 'proximo' e NULL.
 */
typedef struct no_t {
    int valor;
    struct no_t *proximo;
} No;

/*
 * A pilha em si guarda apenas o ponteiro para o no do TOPO.
 * Pilha vazia <=> topo == NULL.
 */
struct pilha_t {
    No *topo;
};

/* ------------------------------------------------------------------ */

Pilha *pilha_criar(void) {
    Pilha *pilha = (Pilha *) malloc(sizeof(Pilha));
    if (pilha == NULL) {
        return NULL; /* sem memoria */
    }
    pilha->topo = NULL; /* pilha nasce vazia */
    return pilha;
}

int pilha_esta_vazia(Pilha *pilha) {
    if (pilha == NULL) {
        return 1; /* pilha inexistente tratada como vazia */
    }
    return pilha->topo == NULL;
}

int pilha_empilhar(Pilha *pilha, int valor) {
    if (pilha == NULL) {
        return 0;
    }

    /* Cria o novo no. */
    No *novo = (No *) malloc(sizeof(No));
    if (novo == NULL) {
        return 0;
    }
    novo->valor = valor;

    /* O novo no passa a apontar para o antigo topo (que vai ficar abaixo),
     * e entao ele proprio vira o novo topo. Esta e a essencia do LIFO. */
    novo->proximo = pilha->topo;
    pilha->topo = novo;
    return 1;
}

int pilha_desempilhar(Pilha *pilha, int *valor_removido) {
    if (pilha_esta_vazia(pilha)) {
        return 0; /* nada para desempilhar */
    }

    /* Guarda o no do topo e o seu valor. */
    No *removido = pilha->topo;
    if (valor_removido != NULL) {
        *valor_removido = removido->valor;
    }

    /* O topo "desce" um nivel: passa a ser o no que estava abaixo. */
    pilha->topo = removido->proximo;

    /* So agora liberamos o no antigo (depois de ja termos salvado o que
     * precisavamos dele). */
    free(removido);
    return 1;
}

int pilha_topo(Pilha *pilha, int *valor_topo) {
    if (pilha_esta_vazia(pilha)) {
        return 0;
    }
    /* Apenas LE o valor do topo, sem remover nada. */
    if (valor_topo != NULL) {
        *valor_topo = pilha->topo->valor;
    }
    return 1;
}

void pilha_exibir(Pilha *pilha) {
    if (pilha_esta_vazia(pilha)) {
        printf("Pilha vazia.\n");
        return;
    }

    /* Percorre do topo ate a base. O primeiro impresso e o do topo. */
    No *atual = pilha->topo;
    printf("Topo -> ");
    while (atual != NULL) {
        printf("[%d]", atual->valor);
        if (atual->proximo != NULL) {
            printf(" -> ");
        }
        atual = atual->proximo;
    }
    printf(" -> Base\n");
}

void pilha_destruir(Pilha **pilha) {
    /* Recebe Pilha ** para poder anular o ponteiro do chamador no fim. */
    if (pilha == NULL || *pilha == NULL) {
        return;
    }

    /* Libera no por no, salvando 'proximo' antes de cada free. */
    No *atual = (*pilha)->topo;
    while (atual != NULL) {
        No *proximo = atual->proximo;
        free(atual);
        atual = proximo;
    }

    free(*pilha);
    *pilha = NULL; /* evita dangling pointer */
}