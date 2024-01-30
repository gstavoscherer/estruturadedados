#include <stdio.h>

float soma(float num1, float num2) {
    return num1 + num2;
}

float produto(float num1, float num2) {
    return num1 * num2;
}

float diferenca(float num1, float num2) {
    return num1 - num2;
}

float divisao(float num1, float num2) {
    if (num2 != 0) {
        return num1 / num2;
    } else {
        printf("Erro: Divisão por zero não é permitida.\n");
        return 0;
    }
}

float calcularOperacao(float num1, float num2, char operacao) {
    switch (operacao) {
        case '+':
            return soma(num1, num2);
        case '-':
            return diferenca(num1, num2);
        case '*':
            return produto(num1, num2);
        case '/':
            return divisao(num1, num2);
        default:
            printf("Erro: Operação inválida.\n");
            return 0;
    }
}

int main() {
    float num1, num2, resultado;
    char operacao;

    printf("Digite o primeiro número: ");
    scanf("%f", &num1);
    printf("Digite o segundo número: ");
    scanf("%f", &num2);
    printf("Digite a operação (+, -, *, /): ");
    scanf(" %c", &operacao);

    resultado = calcularOperacao(num1, num2, operacao);

    printf("Resultado: %.2f\n", resultado);

    return 0;
}
