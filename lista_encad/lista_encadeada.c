#include <stdio.h>
#include <stdlib.h>
#include "lista_encadeada.h"

ListaEncadeada *criar() {
    ListaEncadeada *lista = (ListaEncadeada *) malloc(sizeof(ListaEncadeada));

    if (lista != NULL) {
        lista->primeiro = NULL;
        lista->ultimo = NULL;
        lista->quantidade = 0;
    }

}

void destruir(ListaEncadeada *lista) {
    free(lista); // Só apaga o descritor da lista
}

int lista_vazia(ListaEncadeada *lista) {
    return lista != NULL && lista->primeiro == NULL;
}

void adicionar_final(ListaEncadeada *lista, int valor) {
    No *no = (No *) malloc(sizeof(No));

    if (no == NULL) {
        return;
    }

    no->dado = valor;
    no->proximo = NULL;

    if (lista_vazia(lista)) {
        lista->primeiro = no;
        lista->ultimo = no;
    } else {
        lista->ultimo->proximo = no;
    }

    lista->ultimo = no;
    lista->quantidade++;
}

No *buscar(ListaEncadeada *lista, int valor) {
    if (lista_vazia(lista)) {
        return NULL;
    }

    No *no = lista->primeiro;

    while (no != NULL) {
        if (no->dado == valor) {
            return no;
        }
        no = no->proximo;
    }

    return NULL;
}

void remover(ListaEncadeada *lista, int valor) {

    No *no = lista->primeiro;
    No *anterior = NULL;

    while (no != NULL) {
        if (no->dado == valor) {
            if (anterior != NULL) {
            anterior->proximo = no->proximo;
            } else {
                lista->primeiro = no->proximo;
            }
            free(no);
            break;
        }
        anterior = no; 
        no = no->proximo;
    }
}

int main() {
    ListaEncadeada *lista = criar();

    adicionar_final(lista, 10);
    adicionar_final(lista, 20);
    adicionar_final(lista, 30);

    printf("Lista original:\n");
    No *no = lista->primeiro;
    while (no != NULL) {
        printf("%d -> ", no->dado);
        no = no->proximo;
    }
    printf("NULL\n");

    remover(lista, 20); // remove do meio
    printf("Depois de remover 20:\n");
    no = lista->primeiro;
    while (no != NULL) {
        printf("%d -> ", no->dado);
        no = no->proximo;
    }
    printf("NULL\n");

    remover(lista, 10); // remove o primeiro
    printf("Depois de remover 10:\n");
    no = lista->primeiro;
    while (no != NULL) {
        printf("%d -> ", no->dado);
        no = no->proximo;
    }
    printf("NULL\n");

    destruir(lista);
    return 0;
}