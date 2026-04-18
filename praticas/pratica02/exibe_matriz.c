/*
exibe_matriz.c: Percorrer uma matriz 10x10 de duas maneiras diferentes: com dois laços aninhados; com apenas um laço. Calcular o tempo de execução para cada abordagem. Indicar a complexidade assintótica das duas soluções.
*/

#include <stdio.h>
#include <time.h>

void exibir_2loops(int matriz[10][10]) {
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            int x = matriz[i][j];
        }
    }
}

void exibir_1loop(int matriz[10][10]) {
    for (int i = 0; i < 100; i++) {
        int x = matriz[i/10][i%10];
        }
    }

void imprimir_matriz(int matriz[10][10]) {
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            printf("[%d]", matriz[i][j]);
        }
        printf("\n");
    }
}

int main() {

    clock_t inicio, fim;
    double tempo_gasto;

    
    int matriz[10][10] = {
        {1, 2, 3, 4, 5, 6, 7, 8, 9, 10},
        {11, 12, 13, 14, 15, 16, 17, 18, 19, 20},
        {21, 22, 23, 24, 25, 26, 27, 28, 29, 30},
        {31, 32, 33, 34, 35, 36, 37, 38, 39, 40},
        {41, 42, 43, 44, 45, 46, 47, 48, 49, 50},
        {51, 52, 53, 54, 55, 56, 57, 58, 59, 60},
        {61, 62, 63, 64, 65, 66, 67, 68, 69, 70},
        {71, 72, 73, 74, 75, 76, 77, 78, 79, 80},
        {81, 82, 83, 84, 85, 86, 87, 88, 89, 90},
        {91, 92, 93, 94, 95, 96, 97, 98, 99, 100}
    };
    
    printf("Matriz: \n");
    imprimir_matriz(matriz);

    printf("\n");

    inicio = clock();

    exibir_2loops(matriz);

    fim = clock();

    tempo_gasto = (double)(fim - inicio) / CLOCKS_PER_SEC;

    printf("\nTempo gasto 2 loops: %f segundos\n", tempo_gasto);

    printf("\n\n");

    inicio = clock();

    exibir_1loop(matriz);

    fim = clock();

    tempo_gasto = (double)(fim - inicio) / CLOCKS_PER_SEC;

    printf("Tempo gasto 1 loop: %f segundos\n", tempo_gasto);

    return 0;
}