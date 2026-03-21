/*
busca_sequencial.c: Ler um vetor com 100 números e procurar um valor informado pelo usuário utilizando a busca sequencial. Indicar a complexidade assintótica do algorítimo analisando o melhor caso e o pior caso.
*/

#include <stdio.h>

int buscar(int num, int numeros[100]) {
    for (int i = 0; i < 100; i++) {
        if (numeros[i] == num) {
            return i;
        }
    }

    return -1;
}

int main() {

    int num = 99;
    int numeros[100] = {
        12, 45, 78, 23, 56, 89, 34, 67, 90, 11,
        22, 33, 44, 55, 66, 77, 88, 99, 10, 20,
        30, 40, 50, 60, 70, 80, 15, 25, 35, 46,
        57, 68, 79, 81, 92, 13, 24, 36, 47, 58,
        69, 71, 82, 93, 14, 26, 37, 48, 59, 61,
        72, 83, 94, 16, 27, 38, 49, 62, 73, 84,
        95, 17, 28, 39, 51, 63, 74, 85, 96, 18,
        29, 41, 52, 64, 75, 86, 97, 19, 31, 42,
        53, 65, 76, 87, 98, 21, 32, 43, 54, 91,
        100, 1, 2, 3, 4, 5, 6, 7, 8, 9
    };
    int pos = buscar(num, numeros);

    if (pos != -1) {
        printf("Encontrado o valor na posição [ %d ] do vetor\n", pos);
    } else {
        printf("O valor não foi encontrado!\n");
    }

    return 0;
}

/*
Melhor caso: numeros[0] == valor -> O(1);
*/

/*
Pior caso: numeros[99] == valor -> O(n);
*/

/*
A busca sequencial possui complexidade de tempo O(1) no melhor caso, quando o elemento buscado está na primeira posição do vetor. No pior caso, a complexidade é O(n), pois é necessário percorrer todos os elementos do vetor até encontrar o valor ou concluir que ele não está presente.
*/