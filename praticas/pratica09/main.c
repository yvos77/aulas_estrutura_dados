#include <stdio.h>
#include "arvore_binaria.h"

int main(void) {
    Arvore *arvore = arvore_criar();
    if (arvore == NULL) {
        printf("Erro: nao foi possivel criar a arvore.\n");
        return 1;
    }

    printf("=== TESTE DO TDA ARVORE BINARIA DE BUSCA ===\n\n");

    printf("Arvore esta vazia? %s\n", arvore_esta_vazia(arvore) ? "sim" : "nao");
    arvore_exibir_em_ordem(arvore);
    printf("\n");

    int valores[] = {50, 30, 70, 20, 40, 60, 80};
    int n = sizeof(valores) / sizeof(valores[0]);

    printf(">> Inserindo: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", valores[i]);
        arvore_inserir(arvore, valores[i]);
    }
    printf("\n\n");

    printf(">> Tentando inserir 30 (duplicado): %s\n\n",
           arvore_inserir(arvore, 30) ? "inseriu" : "ja existia (ignorado)");

    printf("Arvore esta vazia? %s\n\n", arvore_esta_vazia(arvore) ? "sim" : "nao");

    printf(">> Percursos:\n");
    arvore_exibir_pre_ordem(arvore);
    arvore_exibir_em_ordem(arvore);
    arvore_exibir_pos_ordem(arvore);
    printf("\n");

    printf(">> Destruindo a arvore...\n");
    arvore_destruir(&arvore);
    printf("Ponteiro da arvore apos destruir e NULL? %s\n",
           arvore == NULL ? "sim" : "nao");

    return 0;
}