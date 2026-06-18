/*
 * main.c
 * ------
 * Programa de teste do TDA Pilha.
 *
 * Repare como as operacoes respeitam a regra LIFO: empilhamos 10, 20, 30
 * e, ao desempilhar, os valores saem na ordem INVERSA: 30, 20, 10.
 */

#include <stdio.h>
#include "pilha.h"

int main(void) {
    /* 1) Criacao -------------------------------------------------------- */
    Pilha *pilha = pilha_criar();
    if (pilha == NULL) {
        printf("Erro: nao foi possivel criar a pilha.\n");
        return 1;
    }

    printf("=== TESTE DO TDA PILHA (LIFO/FILO) ===\n\n");

    printf("Pilha esta vazia? %s\n", pilha_esta_vazia(pilha) ? "sim" : "nao");
    pilha_exibir(pilha);
    printf("\n");

    /* 2) Empilhar ------------------------------------------------------- */
    printf(">> Empilhando 10, 20, 30, 40...\n");
    pilha_empilhar(pilha, 10);
    pilha_empilhar(pilha, 20);
    pilha_empilhar(pilha, 30);
    pilha_empilhar(pilha, 40);

    printf("Pilha esta vazia? %s\n", pilha_esta_vazia(pilha) ? "sim" : "nao");
    pilha_exibir(pilha);
    printf("\n");

    /* 3) Consultar o topo (sem remover) --------------------------------- */
    int topo;
    if (pilha_topo(pilha, &topo)) {
        printf(">> Topo atual: %d (continua na pilha)\n", topo);
    }
    pilha_exibir(pilha);
    printf("\n");

    /* 4) Desempilhar ---------------------------------------------------- */
    printf(">> Desempilhando todos os elementos (devem sair 40, 30, 20, 10):\n");
    int removido;
    while (pilha_desempilhar(pilha, &removido)) {
        printf("   Saiu: %d\n", removido);
    }
    printf("Pilha esta vazia? %s\n", pilha_esta_vazia(pilha) ? "sim" : "nao");
    printf("\n");

    /* 5) Tentar desempilhar de pilha vazia ------------------------------ */
    printf(">> Tentando desempilhar de pilha vazia: %s\n",
           pilha_desempilhar(pilha, &removido) ? "removeu" : "pilha vazia (esperado)");
    printf("\n");

    /* 6) Destruicao ----------------------------------------------------- */
    printf(">> Empilhando 1, 2, 3 e destruindo a pilha cheia...\n");
    pilha_empilhar(pilha, 1);
    pilha_empilhar(pilha, 2);
    pilha_empilhar(pilha, 3);
    pilha_destruir(&pilha);
    printf("Ponteiro da pilha apos destruir e NULL? %s\n",
           pilha == NULL ? "sim" : "nao");

    return 0;
}