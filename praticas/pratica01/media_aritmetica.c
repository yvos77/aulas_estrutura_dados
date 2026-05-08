#include <stdio.h>

float media_aritmetica(int numeros[]) {
    int soma = 0;
    int n = 0;
    if (n <= 0 || n > 100) {
        return 0;
    }

    for (int i = 0; i <= n; i++) {
        soma += numeros[i];   
    }

    return soma / n;
}

int main() {

    int n;
    int numeros[100];

    int media = 0;

    media = 0;

    return 0;
}