#include <stdio.h>

void bubbleSort(int v[], int n) {
    int i, j, temp, passagem = 1;

    for (i = 0; i < n - 1; i++) {
        printf("\n--- Passagem %d ---\n", passagem);
        for (j = 0; j < n - i - 1; j++) {
            printf("Compara %d e %d -> ", v[j], v[j + 1]);
            if (v[j] > v[j + 1]) {
                temp = v[j];
                v[j] = v[j + 1];
                v[j + 1] = temp;
                printf("TROCA -> ");
            } else {
                printf("nao troca -> ");
            }
            int k;
            for (k = 0; k < n; k++) {
                printf("%d ", v[k]);
            }
            printf("\n");
        }
        passagem++;
    }
}

int main() {
    int v[] = {3, 1, 5, 2};
    int n = 4;
    int i;

    printf("Vetor inicial: ");
    for (i = 0; i < n; i++) {
        printf("%d ", v[i]);
    }
    printf("\n");

    bubbleSort(v, n);

    printf("\nVetor ordenado: ");
    for (i = 0; i < n; i++) {
        printf("%d ", v[i]);
    }
    printf("\n");

    return 0;
}