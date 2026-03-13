// #include <stdio.h>

// int main() {

//     int base, expoente;
//     int resultado = 1;

//     printf("Digite a base: ");
//     scanf("%d", &base);

//     printf("Digite o expoente: ");
//     scanf("%d", &expoente);

//     for(int i = 0; i < expoente; i++) {
//         resultado = resultado * base;
//     }

//     printf("Resultado: %d\n", resultado);

//     return 0;
// }


#include <stdio.h>

double potencia(int base, int expoente) {
    int resultado = 1;

    if (expoente == 0) {
        return resultado = 1;
    }

    for(int i = 0; i < expoente; i++) {
        resultado *= base;
    }

    return resultado;
}

int main() {

    long double resultado = 1;

    resultado = potencia(2, 2);
    printf("base = 2, expoente = 2, resultado = %Lf\n", resultado);

    resultado = potencia(10, 2);
    printf("base = 10, expoente = 2, resultado = %Lf\n", resultado);

    resultado = potencia(5, 0);
    printf("base = 5, expoente = 0, resultado = %Lf\n", resultado);

    resultado = potencia(7, 0);
    printf("base = 7, expoente = 0, resultado = %Lf\n", resultado);

    resultado = potencia(2, 3);
    printf("base = 2, expoente = 3, resultado = %Lf\n", resultado);

    return 0;
}