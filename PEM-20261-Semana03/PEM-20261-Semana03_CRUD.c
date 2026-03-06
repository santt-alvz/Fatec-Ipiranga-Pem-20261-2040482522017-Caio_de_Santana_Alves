#include <stdio.h>
int main(){
    int idproduto[10];
    int opcao, id, i;
    int encontrado;
    for(i = 0; i < 10; i++){
        idproduto[i] = -1;
    }

    do{
        printf("escolha uma opcao: \n");
        printf("1 - inclusao\n");
        printf("2 - consulta\n");
        printf("3 - alteracao\n");
        printf("4 - exclusao\n");
        printf("5 - listar todos\n");
        printf("0 - sair\n");
        scanf("%d", &opcao);

        switch(opcao){

            case 1:
                printf("digite o id do produto: ");
                scanf("%d", &id);
                for(i = 0; i < 10; i++){
                    if(idproduto[i] == -1){
                        idproduto[i] = id;
                        printf("produto cadastrado\n");
                        break;
                    }
                }

            break;

            case 2:
                printf("digite o id para buscar: ");
                scanf("%d", &id);
                encontrado = 0;
                for(i = 0; i < 10; i++){
                    if(idproduto[i] == id){
                        printf("encontrado na posicao %d\n", i);
                        encontrado = 1;
                    }
                }
                if(!encontrado){
                    printf("produto nao encontrado\n");
                }
            break;


            case 3:
                printf("digite o id para alterar: ");
                scanf("%d", &id);
                for(i = 0; i < 10; i++){
                    if(idproduto[i] == id){
                        printf("digite o novo id: ");
                        scanf("%d", &idproduto[i]);
                        printf("produto alterado\n");
                    }
                }
            break;

            case 4:
                printf("digite o id para excluir: ");
                scanf("%d", &id);
                for(i = 0; i < 10; i++){
                    if(idproduto[i] == id){
                        idproduto[i] = -1;
                        printf("produto remOVido\n");
                    }
                }
            break;

            case 5:
                printf("\nlista de produtos\n");
                for(i = 0; i < 10; i++){
                    if(idproduto[i] != -1){
                        printf("posicao %d -> %d\n", i=1, idproduto[i]);
                    }
                }
            break;

            case 0:
                printf("Encerrando sistenma\n");
            break;

            default:
                printf("opcao invalida\n");
        }

    }while(opcao != 0);

return 0;
}
