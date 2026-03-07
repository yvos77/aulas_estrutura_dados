#include <stdio.h>

int main() {

    int n;
    float numero, soma = 0, media;

    printf("Digite quantos numeros deseja informar: ");
    scanf("%d", &n);

    if (n <= 0 || n > 100) {
        printf("Erro: n deve estar entre 1 e 100.\n");
        return 1;
    }

    for (int i = 1; i <= n; i++) {
        printf("Digite o numero %d: ", i);
        scanf("%f", &numero);

        soma = soma + numero;
    }

    media = soma / n;

    printf("Media aritmetica = %.2f\n", media);

    return 0;
}