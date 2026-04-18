#include <stdio.h>
#include <time.h>

int main() {

    clock_t inicio, fim;
    double tempo_gasto;

    long long int i;
    long long int soma = 0;

    inicio = clock();
    printf("Início: %ld\n", inicio);

    for (i = 0; i < 1000000000L; i++) {
        for (int j = 0; j < 1000000000L; j++) {
            soma += i;
        }
    }

    fim = clock();

    printf("Fim: %ld\n", fim);

    tempo_gasto = (double)(fim - inicio) / CLOCKS_PER_SEC;

    printf("Tempo gasto: %f segundos\n", tempo_gasto);
    printf("Soma: %lld\n", soma);

    return 0;
}