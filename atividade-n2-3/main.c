#include <stdio.h>
#include "recursao.h"   
#include "interface.h"  

int main() {
    int opcao, n, base, exp;

    do {
        exibirMenu();
        opcao = lerInteiro("");

        switch (opcao) {
            case 1:
                n = lerInteiro("Digite um numero decimal: ");
                printf("Resultado em Binario: ");
                if (n == 0) printf("0");
                else decToBin(n); 
                printf("\n");
                break;

            case 2:
                base = lerInteiro("Digite a base: ");
                exp = lerInteiro("Digite o expoente (>=0): ");
                printf("Resultado da Potencia: %d\n", potencia(base, exp)); 
                break;

            case 3:
                n = lerInteiro("Digite um numero inteiro: ");
                printf("Soma dos digitos: %d\n", somaDigitos(n)); 
                break;

            case 0:
                printf("Encerrando o sistema CUCC...\n");
                break;

            default:
                printf("Opcao invalida!\n");
        }
    } while (opcao != 0);

    return 0;
}
