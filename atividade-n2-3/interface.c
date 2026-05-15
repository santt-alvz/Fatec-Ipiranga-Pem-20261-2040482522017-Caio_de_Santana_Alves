#include <stdio.h>
#include "interface.h"

void exibirMenu() {
    printf("\n--- Conversor e Calculadora Cientifica (CUCC) ---\n");
    printf("1. Converter Decimal para Binario\n");
    printf("2. Calcular Potencia\n");
    printf("3. Soma de Digitos\n");
    printf("0. Sair\n");
    printf("Escolha uma opcao: ");
}

int lerInteiro(char* mensagem) {
    int valor;
    printf("%s", mensagem);
    scanf("%d", &valor);
    return valor;
}
