#include <stdio.h>

//modulo de processamento
void processarCarga(float *ptr_vetor, int n);

int main() {
    //declaração dos 10 pacotes
    float pesos[10] = {100.0, 120.5, 80.0, 150.2, 95.0, 110.0, 130.8, 85.5, 90.0, 105.0};
    int i;

    //estado antes do processamento
    printf("Pesos Iniciais\n");
    for(i = 0; i < 10; i++) {
        printf("Pacote %d: %.2f kg\n", i + 1, pesos[i]);
    }

    //chamada da função, move o endereço do vetor 
    processarCarga(pesos, 10);

    //exibir condição pós processamento
    printf("\nPesos Apos Processamento \n");
    for(i = 0; i < 10; i++) {
        printf("Pacote %d: %.2f kg\n", i + 1, pesos[i]);
    }

    return 0;
}

//implementação do modulo de processamento citado anteriormente
void processarCarga(float *ptr_vetor, int n) {
    float soma = 0, media;
    int i;

    // a. calculo da media aritmética do peso do lote
    for(i = 0; i < n; i++) {
        soma += *(ptr_vetor + i); // Uso de aritmética de ponteiros 
    }
    media = soma / n;

    printf("\nMedia do lote: %.2f kg\n", media);
    printf("liite (Media + 10%%): %.2f kg\n", media * 1.10);

    // b. localizando pesos que excedam a média em mais de 10% 
    for(i = 0; i < n; i++) {
        if (*(ptr_vetor + i) > (media * 1.10)) {
            // c. aplicaando a correção de -5% diretamente no endereço (ponteiro) 
            *(ptr_vetor + i) = *(ptr_vetor + i) * 0.95; 
            printf("ajuste aplicado no indice %d\n", i);
        }
    }
}