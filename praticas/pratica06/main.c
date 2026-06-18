#include <stdio.h>
#include "lista_linear.h"

int main(void) {
    /* 1) Criacao -------------------------------------------------------- */
    Lista *lista = lista_criar();
    if (lista == NULL) {
        printf("Erro: nao foi possivel criar a lista.\n");
        return 1;
    }

    printf("=== TESTE DO TDA LISTA LINEAR ===\n\n");

    printf("Lista esta vazia? %s\n", lista_esta_vazia(lista) ? "sim" : "nao");
    printf("Conteudo inicial: ");
    lista_exibir(lista);
    printf("\n");

    /* 2) Insercao ------------------------------------------------------- */
    printf(">> Inserindo 10, 20, 30, 40 e 50...\n");
    lista_inserir(lista, 10);
    lista_inserir(lista, 20);
    lista_inserir(lista, 30);
    lista_inserir(lista, 40);
    lista_inserir(lista, 50);

    printf("Lista esta vazia? %s\n", lista_esta_vazia(lista) ? "sim" : "nao");
    printf("Conteudo: ");
    lista_exibir(lista);
    printf("\n");

    /* 3) Busca ---------------------------------------------------------- */
    printf(">> Buscando valores...\n");
    printf("Posicao do 30: %d\n", lista_buscar(lista, 30)); /* deve ser 2 */
    printf("Posicao do 10: %d\n", lista_buscar(lista, 10)); /* deve ser 0 */
    printf("Posicao do 99: %d (-1 = nao encontrado)\n", lista_buscar(lista, 99));
    printf("\n");

    /* 4) Remocao -------------------------------------------------------- */
    printf(">> Removendo o 30 (no do meio)...\n");
    lista_remover(lista, 30);
    printf("Conteudo: ");
    lista_exibir(lista);

    printf(">> Removendo o 10 (primeiro no)...\n");
    lista_remover(lista, 10);
    printf("Conteudo: ");
    lista_exibir(lista);

    printf(">> Removendo o 50 (ultimo no)...\n");
    lista_remover(lista, 50);
    printf("Conteudo: ");
    lista_exibir(lista);

    printf(">> Tentando remover o 99 (inexistente): %s\n",
           lista_remover(lista, 99) ? "removido" : "nao encontrado");
    printf("Conteudo: ");
    lista_exibir(lista);
    printf("\n");

    /* 5) Destruicao ----------------------------------------------------- */
    printf(">> Destruindo a lista...\n");
    lista_destruir(&lista);
    printf("Ponteiro da lista apos destruir e NULL? %s\n",
           lista == NULL ? "sim" : "nao");

    return 0;
}