#ifndef PILHA_H
#define PILHA_H

/*
 * pilha.h
 * -------
 * Interface publica do TDA Pilha (estrutura LIFO / FILO).
 *
 * LIFO = Last In, First Out (o ultimo a entrar e o primeiro a sair).
 * FILO = First In, Last Out (o primeiro a entrar e o ultimo a sair).
 * Sao dois nomes para a MESMA regra: so mexemos numa ponta, o TOPO.
 *
 * Assim como na lista, usamos um TIPO OPACO: quem inclui este .h sabe
 * que "Pilha" existe e usa ponteiros para ela, mas nao enxerga seus
 * campos internos (eles ficam escondidos no pilha.c). Encapsulamento.
 */

typedef struct pilha_t Pilha;

/* Cria e inicializa uma pilha vazia. Retorna o ponteiro, ou NULL se falhar. */
Pilha *pilha_criar(void);

/* Coloca 'valor' no topo da pilha. Retorna 1 em sucesso, 0 em falha. */
int pilha_empilhar(Pilha *pilha, int valor);

/*
 * Remove o elemento do topo e o devolve por '*valor_removido'.
 * Retorna 1 se desempilhou, 0 se a pilha estava vazia (nada a remover).
 */
int pilha_desempilhar(Pilha *pilha, int *valor_removido);

/*
 * Consulta (sem remover) o elemento do topo, devolvido por '*valor_topo'.
 * Retorna 1 se havia topo, 0 se a pilha estava vazia.
 */
int pilha_topo(Pilha *pilha, int *valor_topo);

/* Retorna 1 se a pilha estiver vazia, 0 caso contrario. */
int pilha_esta_vazia(Pilha *pilha);

/* Imprime os elementos do topo ate a base. */
void pilha_exibir(Pilha *pilha);

/* Libera toda a memoria da pilha e zera o ponteiro do chamador. */
void pilha_destruir(Pilha **pilha);

#endif /* PILHA_H */