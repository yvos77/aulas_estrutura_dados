#include <stdio.h>

int main() {

    int base, expoente;
    int resultado = 1;

    printf("Digite a base: ");
    scanf("%d", &base);

    printf("Digite o expoente: ");
    scanf("%d", &expoente);

    for(int i = 0; i < expoente; i++) {
        resultado = resultado * base;
    }

    printf("Resultado: %d\n", resultado);

    return 0;
}