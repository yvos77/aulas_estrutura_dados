#include <stdio.h>
#include "tabela_hash.h"

int main(void) {
    TabelaHash *hash = hash_criar(7);
    if (hash == NULL) {
        printf("Erro: nao foi possivel criar a tabela hash.\n");
        return 1;
    }

    printf("=== TESTE DO TDA TABELA HASH (tamanho 7) ===\n\n");

    printf("Tabela esta vazia? %s\n\n", hash_esta_vazia(hash) ? "sim" : "nao");

    int valores[] = {10, 20, 30, 17, 24, 5, 3};
    int n = sizeof(valores) / sizeof(valores[0]);

    printf(">> Inserindo: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", valores[i]);
        hash_inserir(hash, valores[i]);
    }
    printf("\n");
    printf("   (10, 17, 24 e 3 colidem no indice 3, formando uma cadeia)\n\n");

    printf(">> Tentando inserir 17 (duplicado): %s\n\n",
           hash_inserir(hash, 17) ? "inseriu" : "ja existia (ignorado)");

    printf("Tabela esta vazia? %s\n\n", hash_esta_vazia(hash) ? "sim" : "nao");

    printf(">> Estado da tabela:\n");
    hash_exibir(hash);
    printf("\n");

    printf(">> Buscas:\n");
    printf("   24 esta na tabela? %s\n", hash_buscar(hash, 24) ? "sim" : "nao");
    printf("   99 esta na tabela? %s\n\n", hash_buscar(hash, 99) ? "sim" : "nao");

    printf(">> Removendo 17 (do meio da cadeia do indice 3)...\n");
    hash_remover(hash, 17);
    printf("   17 ainda esta na tabela? %s\n\n", hash_buscar(hash, 17) ? "sim" : "nao");

    printf(">> Estado da tabela apos remocao:\n");
    hash_exibir(hash);
    printf("\n");

    printf(">> Destruindo a tabela...\n");
    hash_destruir(&hash);
    printf("Ponteiro da tabela apos destruir e NULL? %s\n",
           hash == NULL ? "sim" : "nao");

    return 0;
}