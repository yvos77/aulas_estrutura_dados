#ifndef AGENDA_H
#define AGENDA_H

#define LIMITE 100

typedef struct {
    char nome[101];
    char telefone[21];
    int bloqueado; 
} Contato;

typedef struct {
    Contato contatos[LIMITE];
    int tamanho; 
    int quantidade; 
} Agenda;

Agenda criar_agenda(int tamanho); 
void adicionar_contato(Agenda *agenda, Contato contato);
void remover_contato(Agenda *agenda, char *nome);
void bloquear_contato(Agenda *agenda, char *nome);
void desbloquear_contato(Agenda *agenda, char *nome);
void editar_contato(Agenda *agenda, char *nome_antigo, Contato novo_contato);
void listar_contatos(Agenda agenda);

#endif