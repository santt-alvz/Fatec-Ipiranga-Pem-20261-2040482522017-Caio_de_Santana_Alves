#include <stdio.h>
#include "recursao.h"
#include "interface.h"

int main() {
    int opcao, valor, base, exp;
    do {
        exibirMenu();
        opcao = lerOpcao();
        switch(opcao) {
            case 1:
                printf("Digite o numero decimal: ");
                scanf("%d", &valor);
                printf("Binario: ");
                decToBin(valor); 
                printf("\n");
                break;
            case 0:
                printf("Saindo...\n");
                break;
        }
    } while(opcao != 0);

    return 0;
}
