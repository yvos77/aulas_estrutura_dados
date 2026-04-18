/*
fatorial.c: Ler um número inteiro positivo e calcular o seu fatorial de duas formas: utilizando repetição; e utilizando recursividade. Indicar a complexidade assintótica de cada solução.
*/

#include <stdio.h>

long int fatorial_it(int num) {

    if (num == 0 || num == 1) {
        return 1;
    }

    long int resultado = num;
    for (int i = num-1; i > 1; i--) {
        resultado *= i;
    }
    return resultado;
}

long int fatorial_rec(int num) {
    if (num == 0 || num == 1) {
        return 1;
    }

    return num * fatorial_rec(num - 1);
}

int main() {

    int num = 10;

    printf("O fatorial iterativo do número %d é: %ld\n", num, fatorial_it(num));

    printf("O fatorial recursivo do número %d é: %ld\n", num, fatorial_rec(num));

    return 0;
}

/* A solução iterativa possui complexidade de tempo O(n), pois realiza um laço que percorre n elementos, e complexidade de espaço O(1), pois utiliza apenas variáveis auxiliares. */

/* A solução recursiva também possui complexidade de tempo O(n), pois realiza n chamadas recursivas. Entretanto, sua complexidade de espaço é O(n), devido ao uso da pilha de chamadas. */

