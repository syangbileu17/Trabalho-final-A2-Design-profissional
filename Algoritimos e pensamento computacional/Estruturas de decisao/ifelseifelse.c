#include <stdio.h>
#include <math.h>
#include <string.h>

int main() {
    double numero1, numero2, resultado;
    char operação[10];

    printf("Digite o primeiro numero: ");
    scanf("%lf", &numero1);

    printf("Digite o segundo numero: ");
    scanf("%lf", &numero2);

    printf("Digite a operacao (+, -, *, /, pow, log): ");
    scanf("%s", operação);

    if (strcmp(operação, "+") == 0) {
        resultado = numero1 + numero2;
        printf("Resultado: %.2lf\n", resultado);
    } else if (strcmp(operação, "-") == 0) {
        resultado = numero1 - numero2;
        printf("Resultado: %.2lf\n", resultado);
    } else if (strcmp(operação, "*") == 0) {
        resultado = numero1 * numero2;
        printf("Resultado: %.2lf\n", resultado);
    } else if (strcmp(operação, "/") == 0) {
        if (numero2 != 0) {
            resultado = numero1 / numero2;
            printf("Resultado: %.2lf\n", resultado);
        } else {
            printf("Erro: Divisao por zero nao e permitida.\n");
        }
    } else if (strcmp(operação, "pow") == 0) {
        resultado = pow(numero1, numero2);
        printf("Resultado: %.2lf\n", resultado);
    } else if (strcmp(operação, "log") == 0) {
        if (numero1 > 0 && numero2 > 0 && numero2 != 1) {
            resultado = log(numero1) / log(numero2);
            printf("Resultado: %.2lf\n", resultado);
        } else {
            printf("Erro: Logaritmo invalido. Base deve ser maior que 0 e diferente de 1, e o numero deve ser maior que 0.\n");
        }
    } else {
        printf("Operacao invalida. Use +, -, *, /, pow ou log.\n");
    }

    printf("Fim do programa\n");
    return 0;
}
