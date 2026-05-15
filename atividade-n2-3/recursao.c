#include "recursao.h"
#include <stdio.h>

//exibição pela pilha recursiva 
void decToBin(int n) {
    if (n == 0) return; // controle - quando nao tem mais nada para dividir
    
    decToBin(n / 2);    // empilha as divisoes
    printf("%d", n % 2); // na volta da recursao os valores sao impressos
}


int potencia(int base, int exp) {
    if (exp == 0) return 1; // definindo a potenciação por 0
    
    return base * potencia(base, exp - 1); 
}


int somaDigitos(int n) {
    if (n == 0) return 0; 
    
    //  seleciona o último dígito (n % 10) - resto;  e soma com o restante do número (n / 10)
    return (n % 10) + somaDigitos(n / 10);
}
