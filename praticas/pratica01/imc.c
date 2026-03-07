#include <stdio.h>

int main() {

    float peso, altura;

    printf("Digite seu peso: ");
    if (scanf("%f", &peso) != 1) {
        printf("Erro: peso invalido.\n");
        return 1;
    }

    printf("Digite sua altura em metros: ");
    if (scanf("%f", &altura) != 1) {
        printf("Erro: altura invalida.\n");
        return 1;
    }

    if (peso <= 0 || altura <= 0) {
        printf("Erro: valores devem ser maiores que zero.\n");
        return 1;
    }

    float imc = peso / (altura * altura);

    printf("Seu IMC é: %.2f\n", imc);

    if (imc < 18.5) {
        printf("Abaixo do peso\n");
    }
    else if (imc < 25) {
        printf("Peso normal\n");
    }
    else if (imc < 30) {
        printf("Sobrepeso\n");
    }
    else {
        printf("Obesidade\n");
    }

    return 0;
}