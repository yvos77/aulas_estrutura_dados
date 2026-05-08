#include <stdio.h>
#include "conta.h"

int main(void) {
    printf("=== Teste do TDA Conta ===\n\n");

    Conta *c = conta_criar(1001);
    if (c == NULL) return 1;
    printf("Conta 1001 criada com sucesso.\n");
    printf("Saldo inicial: R$ %.2f\n\n", conta_ver_saldo(c));

    conta_depositar(c, 500.00);
    printf("Depósito de R$ 500,00 realizado.\n");
    printf("Saldo atual:  R$ %.2f\n\n", conta_ver_saldo(c));

    conta_depositar(c, 300.00);
    printf("Depósito de R$ 300,00 realizado.\n");
    printf("Saldo atual:  R$ %.2f\n\n", conta_ver_saldo(c));

    if (conta_sacar(c, 200.00))
        printf("Saque de R$ 200,00 realizado.\n");
    printf("Saldo atual:  R$ %.2f\n\n", conta_ver_saldo(c));

    printf("Tentando sacar R$ 700,00 (deve falhar):\n");
    conta_sacar(c, 700.00);
    printf("Saldo atual:  R$ %.2f\n\n", conta_ver_saldo(c));

    printf("Tentando depositar valor negativo (deve falhar):\n");
    conta_depositar(c, -50.00);
    printf("Saldo atual:  R$ %.2f\n\n", conta_ver_saldo(c));

    conta_destruir(c);
    printf("Conta destruída. Memória liberada.\n");

    return 0;
}