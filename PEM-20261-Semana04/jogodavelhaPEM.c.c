#include <stdio.h>
#define VAZIO ' '
//separar e declarar funções por fora do int main para melhorar a leitura, visualização e roteirazição do jogo. 
//modularizar por fora do int main garantindo o uso das funções mais eficiente 
void inicializarTabuleiro(char tabuleiro[3][3]);                                  //modulo para inicializar o jogo
void exibirTabuleiro(char tabuleiro[3][3]);                                       // modulo para exibir o tabuleiro   
int jogada_valida(char tabuleiro[3][3], int linha, int coluna);                   // modulo de verificação da jogada (usar if) 
void jogada_action(char tabuleiro[3][3], int linha, int coluna, char player); /*modulo que vai REALIZAR a jogada (acabei criando um printf dentro do modulo pra visualizar e entender o 
porque as cordenadas estavam saindo com o valor do sistema e nao do indice)*/
int verificarVitoria(char tabuleiro[3][3], char player);                          // modulo de verifição da vitoria
int tabuleiroCheio (char tab[3][3]);                                              // modulo de verificação caso o jogo de velha
void alternarJogador (char *player);                                              // modulo alterna os valores e os guarda (ponteiro numa variavel existente para mover a memoria)
int menu();

int main(){
    int linha, coluna;
    char tabuleiro [3][3];
    int jogoAtivo;   //vou usar essa variavel para manter o jogo ativo
    char playerAtual= 'X'; 
    int opcao; //importante, a variavel precisa ser declarada na main para controlar o laço, e mesma sera usada pelo modulo "menu"

    do{

    opcao = menu(); //ativando a primeira função

        switch(opcao) { //recebendo a resposta do "return opcao" e inicializando o modulo do jogo
            case 1:
                inicializarTabuleiro(tabuleiro); 
                playerAtual = 'X';
                jogoAtivo= 1; // mantém o jogo ligado enquanto a varivel for igual a 1

                while(jogoAtivo) {
                    exibirTabuleiro(tabuleiro);
                    printf("\nJogador %c, digite linha e coluna do tabuleiro (1-3): ", playerAtual);
                    scanf("%d %d", &linha, &coluna);
                    
                    if (linha < 1 || linha > 3 || coluna < 1 || coluna > 3) { // criando um verificador para so aceitar jogadas validas
                        printf("\nInvalido, cordenadas devem estar entre 1 e 3.\n");
                        continue; //uso do pulo de codigo para manter memoria eficiente e nao engasgar o sistema.
                    }
                    int linha_coord = linha - 1;
                    int coluna_coord = coluna - 1;
                    //alinhar o sistema com o jogador, assim como pedido na aula (coordenadas alinhdsas)
                    //correção do problema que estava tendo em verificar as variaveis do sistema
                    /*nota: tive dificuldade para concluir que preciso separar as funçoes do sistema das saídas e o tabuleiro. no caso durante a correção o sistema deve
                    ter como nucleo a função e instrução, lembrar também de entender que a manipulçao da memoria é um grande fator dentro do sistema. sistema <-> interação*/

                    if(!jogada_valida(tabuleiro, linha_coord, coluna_coord)){
                        exibirTabuleiro(tabuleiro);
                        printf("posição ja ocupada.\n");
                        continue;
                    }
                    // usando exclamação para antes do modulo de jogada valida para verificar se a posição está ocupada. usa um modulo ja existente.
                    
                    jogada_action (tabuleiro, linha_coord, coluna_coord, playerAtual); //modulo que responsavel por realizar as jogadas

                    if(verificarVitoria(tabuleiro, playerAtual)){
                        exibirTabuleiro(tabuleiro);
                        printf("\nO jogador [%c] venceu!\n\n", playerAtual);
                        jogoAtivo = 0;
                    }
                    else if(tabuleiroCheio(tabuleiro)){
                        exibirTabuleiro(tabuleiro);
                        printf("\nO jogo terminou em empate.\n");
                        jogoAtivo = 0;
                    }
                    else{
                        alternarJogador(&playerAtual);
                    }

                    
                }
                
            break;

            case 2:
            printf("até mais!\n");
            break;

            default:
            printf("znopcao invalida!\n");
        }

    }
    while (opcao != 2);



    return 0;
}

//ATIVANDO OS MODULOS E FUNÇÕES

int menu () {
    int opcao;
    printf("\n[==] JOGO DA VELHA [==]\n");
    printf("1- Jogar");
    printf("\n2- Sair");
    printf("\nescolha: ");
    scanf("%d", &opcao);
    return opcao; //return esta sendo usado aqui para informar ao sistema a escolha feita que será repassado ao switch
}
void inicializarTabuleiro(char tabuleiro[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            tabuleiro[i][j] = ' ';
        }
    }
} //modulo que limpa e inicializa o tabuleiro.

void exibirTabuleiro(char tabuleiro[3][3]) {
    printf("\n");
    printf("    1   2   3\n");
    for (int i = 0; i < 3; i++) {
        printf("%d  ", i + 1);
        for (int j = 0; j < 3; j++) {
            printf(" %c ", tabuleiro[i][j]);
            if (j < 2) printf("|");
        }
        printf("\n");
        if (i < 2) {
            printf("   ---+---+---\n");
        }
    }
    printf("\n");
    }// modulo de construção do tabuleiro

int jogada_valida(char tabuleiro[3][3], int linha, int coluna) {
    return (tabuleiro[linha][coluna] == ' ');
}//verificação se a coordenada ta vazia

void jogada_action(char tabuleiro[3][3], int linha, int coluna, char player) {
    //printf("recebi linha=%d, coluna=%d, jogador=%c\n", linha, coluna, player);
    tabuleiro[linha][coluna] = player;
}

int verificarVitoria(char tabuleiro[3][3], char player) {
    // verificadir linhas
    for (int i = 0; i < 3; i++) {
        if (tabuleiro[i][0] == player && tabuleiro[i][1] == player && tabuleiro[i][2] == player)
            return 1;
    }
    // verificador colunas
    for (int j = 0; j < 3; j++) {
        if (tabuleiro[0][j] == player && tabuleiro[1][j] == player && tabuleiro[2][j] == player)
            return 1;
    }
    // para diganal principal
    if (tabuleiro[0][0] == player &&tabuleiro[1][1] == player && tabuleiro[2][2] == player)
        return 1;
    // para a outra diagonal
    if (tabuleiro[0][2] == player && tabuleiro[1][1] == player && tabuleiro[2][0] == player)
        return 1;
    return 0;
}
//repetir os testes com matriz para garantir o funcionamento do sistema
//verificador de vitoria por linha, coluna e diagnal
       
int tabuleiroCheio(char tab[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (tab[i][j] == ' ') return 0;
        }
    }
    return 1;

}// função que declara percorre o tabuleiro verificando se ele esta vazio ainda ou cheio, caso esteja completo declara empate e encerra o jogo
void alternarJogador(char *player) {
    if (*player == 'X')
        *player = 'O';
    else
        *player = 'X';
} //função que vai alternar o jogador entre e o valor de char entre 'O' e 'X'