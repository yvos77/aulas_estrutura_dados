// #include <stdio.h>

// int main() {

//     float peso, altura;

//     printf("Digite seu peso: ");
//     if (scanf("%f", &peso) != 1) {
//         printf("Erro: peso invalido.\n");
//         return 1;
//     }

//     printf("Digite sua altura em metros: ");
//     if (scanf("%f", &altura) != 1) {
//         printf("Erro: altura invalida.\n");
//         return 1;
//     }

//     if (peso <= 0 || altura <= 0) {
//         printf("Erro: valores devem ser maiores que zero.\n");
//         return 1;
//     }

//     float imc = peso / (altura * altura);

//     printf("Seu IMC é: %.2f\n", imc);

//     if (imc < 18.5) {
//         printf("Abaixo do peso\n");
//     }
//     else if (imc < 25) {
//         printf("Peso normal\n");
//     }
//     else if (imc < 30) {
//         printf("Sobrepeso\n");
//     }
//     else {
//         printf("Obesidade\n");
//     }

//     return 0;
// }

#include <stdio.h>


float calcular_imc(float altura, float peso) {
    if (altura <= 0.0f || peso <= 0.0f) {
        return 0.0f;
    }

    return peso / (altura * altura);
}

int main() {
    float imc = 0.0f;

    imc = calcular_imc(0.0f, 50.0f);
    printf("altura = 0, peso = 50, imc = %.1f => %i\n", imc, imc == 0);

    imc = calcular_imc(1.75f, 0.0f);
    printf("altura = 1.75, peso = 0, imc = %.1f => %i\n", imc, imc == 0);

    imc = calcular_imc(1.75f, 50.0f);
    printf("altura = 1.75, peso = 50, imc = %.1f => %i\n", imc, imc < 18.5f);

    imc = calcular_imc(1.75f, 65.0f);
    printf("altura = 1.75, peso = 65, imc = %.1f => %i\n", imc, imc >= 18.5f && imc < 24.9f);

    imc = calcular_imc(1.75f, 85.0f);
    printf("altura = 1.75, peso = 85, imc = %.1f => %i\n", imc, imc >= 25.0f && imc < 29.9f);

    imc = calcular_imc(1.75f, 95.0f);
    printf("altura = 1.75, peso = 95, imc = %.1f >= %i\n", imc, imc >= 30.0f);

    return 0;
}