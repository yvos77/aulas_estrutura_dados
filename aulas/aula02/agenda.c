#include <stdio.h>
#include <string.h>
#include "agenda.h"

Agenda criar_agenda(int tamanho) {
    Agenda agenda; 
    agenda.tamanho = (tamanho > LIMITE) ? LIMITE : tamanho; 
    agenda.quantidade = 0;
    return agenda;
}

void adicionar_contato(Agenda *agenda, Contato contato) {
    if (agenda->quantidade == agenda->tamanho) {
        printf("Erro: Agenda Lotada\n");
        return;
    }
    // Make sure new contacts are not blocked by default
    contato.bloqueado = 0; 
    agenda->contatos[agenda->quantidade] = contato;
    agenda->quantidade++;
}

void listar_contatos(Agenda agenda) {
    if (agenda.quantidade == 0) {
        printf("Agenda vazia\n");
        return;
    }

    for (int i = 0; i < agenda.quantidade; i++) {
        char *status = agenda.contatos[i].bloqueado ? "[BLOQUEADO]" : "";
        printf("%s - %s %s\n", agenda.contatos[i].nome, 
                               agenda.contatos[i].telefone, 
                               status);
    }
}

void remover_contato(Agenda *agenda, char *nome) {
    for (int i = 0; i < agenda->quantidade; i++) {
        if (strcmp(agenda->contatos[i].nome, nome) == 0) {
            for (int j = i; j < agenda->quantidade - 1; j++) {
                agenda->contatos[j] = agenda->contatos[j + 1];
            }
            agenda->quantidade--;
            printf("Contato removido.\n");
            return;
        }
    }
    printf("Contato nao encontrado.\n");
}

void bloquear_contato(Agenda *agenda, char *nome) {
    for (int i = 0; i < agenda->quantidade; i++) {
        if (strcmp(agenda->contatos[i].nome, nome) == 0) {
            agenda->contatos[i].bloqueado = 1;
            printf("Contato '%s' bloqueado.\n", nome);
            return;
        }
    }
    printf("Contato nao encontrado.\n");
}

// --- NEW FUNCTIONS BELOW ---

void desbloquear_contato(Agenda *agenda, char *nome) {
    for (int i = 0; i < agenda->quantidade; i++) {
        if (strcmp(agenda->contatos[i].nome, nome) == 0) {
            agenda->contatos[i].bloqueado = 0;
            printf("Contato '%s' desbloqueado.\n", nome);
            return;
        }
    }
    printf("Contato nao encontrado.\n");
}

void editar_contato(Agenda *agenda, char *nome_antigo, Contato novo_contato) {
    for (int i = 0; i < agenda->quantidade; i++) {
        if (strcmp(agenda->contatos[i].nome, nome_antigo) == 0) {
            // Keep the blocked status unless you want the edit to reset it
            int status_salvo = agenda->contatos[i].bloqueado;
            
            agenda->contatos[i] = novo_contato;
            agenda->contatos[i].bloqueado = status_salvo;
            
            printf("Contato '%s' atualizado para '%s'.\n", nome_antigo, novo_contato.nome);
            return;
        }
    }
    printf("Contato '%s' nao encontrado para edicao.\n", nome_antigo);
}