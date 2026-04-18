#include <stdio.h>
#include <stdlib.h>
#include "conta.h"

struct conta_t {
    int numero;
    double saldo;
};

Conta *conta_criar(int numero) {
    Conta *c = (Conta *)malloc(sizeof(struct conta_t));
    if (c == NULL) {
        fprintf(stderr, "Erro: falha ao alocar memória para a conta.\n");
        return NULL;
    }
    c->numero = numero;
    c->saldo  = 0.0;
    return c;
}

int conta_depositar(Conta *c, double valor) {
    if (c == NULL || valor <= 0.0) {
        fprintf(stderr, "Erro: depósito inválido (valor=%.2f).\n", valor);
        return 0;
    }
    c->saldo += valor;
    return 1;
}

int conta_sacar(Conta *c, double valor) {
    if (c == NULL || valor <= 0.0) {
        fprintf(stderr, "Erro: saque inválido (valor=%.2f).\n", valor);
        return 0;
    }
    if (valor > c->saldo) {
        fprintf(stderr, "Erro: saldo insuficiente (saldo=%.2f, saque=%.2f).\n",
                c->saldo, valor);
        return 0;
    }
    c->saldo -= valor;
    return 1;
}

double conta_ver_saldo(Conta *c) {
    if (c == NULL) return -1.0;
    return c->saldo;
}

void conta_destruir(Conta *c) {
    if (c != NULL) {
        free(c);
    }
}