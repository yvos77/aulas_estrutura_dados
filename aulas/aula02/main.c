#include <stdio.h>
#include <string.h>
#include "agenda.h"

int main() {
    // 1. Create the agenda
    Agenda minha_agenda = criar_agenda(10);
    
    // 2. Create some test contacts
    Contato c1 = {"Alice", "1111-1111", 0};
    Contato c2 = {"Bob", "2222-2222", 0};
    Contato c3 = {"Charlie", "3333-3333", 0};

    // 3. Test Adding
    printf("--- Testing Add ---\n");
    adicionar_contato(&minha_agenda, c1);
    adicionar_contato(&minha_agenda, c2);
    adicionar_contato(&minha_agenda, c3);
    listar_contatos(minha_agenda);

    // 4. Test Blocking
    printf("\n--- Testing Block (Bob) ---\n");
    bloquear_contato(&minha_agenda, "Bob");
    listar_contatos(minha_agenda);

    // 5. Test Editing
    printf("\n--- Testing Edit (Alice -> Alicia) ---\n");
    Contato nova_alice = {"Alicia", "9999-9999", 0};
    editar_contato(&minha_agenda, "Alice", nova_alice);
    listar_contatos(minha_agenda);

    // 6. Test Removing
    printf("\n--- Testing Remove (Charlie) ---\n");
    remover_contato(&minha_agenda, "Charlie");
    listar_contatos(minha_agenda);

    return 0;
}