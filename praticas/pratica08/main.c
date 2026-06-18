#include <stdio.h>
#include "fila.h"

int main(void) {
    Fila *fila = fila_criar();
    if (fila == NULL) {
        printf("Erro: nao foi possivel criar a fila.\n");
        return 1;
    }

    printf("=== TESTE DO TDA FILA (FIFO) ===\n\n");

    printf("Fila esta vazia? %s\n", fila_esta_vazia(fila) ? "sim" : "nao");
    lista_exibir(fila);
    printf("\n");

    printf(">> Enfileirando 10, 20, 30, 40...\n");
    fila_enfileirar(fila, 10);
    fila_enfileirar(fila, 20);
    fila_enfileirar(fila, 30);
    fila_enfileirar(fila, 40);

    printf("Fila esta vazia? %s\n", fila_esta_vazia(fila) ? "sim" : "nao");
    lista_exibir(fila);
    printf("\n");

    int frente;
    if (fila_inicio(fila, &frente)) {
        printf(">> Inicio atual: %d (continua na fila)\n", frente);
    }
    lista_exibir(fila);
    printf("\n");

    int removido;
    printf(">> Desenfileirando 2 elementos (devem sair 10 e 20):\n");
    fila_desenfileirar(fila, &removido);
    printf("   Saiu: %d\n", removido);
    fila_desenfileirar(fila, &removido);
    printf("   Saiu: %d\n", removido);
    lista_exibir(fila);
    printf("\n");

    printf(">> Desenfileirando o resto (devem sair 30 e 40):\n");
    while (fila_desenfileirar(fila, &removido)) {
        printf("   Saiu: %d\n", removido);
    }
    printf("Fila esta vazia? %s\n", fila_esta_vazia(fila) ? "sim" : "nao");
    printf("\n");

    printf(">> Enfileirando 99 numa fila ja esvaziada...\n");
    fila_enfileirar(fila, 99);
    lista_exibir(fila);
    printf("\n");

    printf(">> Destruindo a fila...\n");
    fila_destruir(&fila);
    printf("Ponteiro da fila apos destruir e NULL? %s\n",
           fila == NULL ? "sim" : "nao");

    return 0;
}