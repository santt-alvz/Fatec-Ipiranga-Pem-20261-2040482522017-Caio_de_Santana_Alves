#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*
FACULDADE DE TECNOLOGIA DO ESTADO DE SÃO PAULO - FATEC IPIRANGA                     
Disciplina: Programação Estruturada e Modular                               
Professor: Veríssimo                                                        
Aluno: Caio de Santana Alves                                                
Data: 19/03/2026                                                            
Atividade: Semana 5 - Xeque Pastor                                          
*/

#define LINHAS 8
#define COLUNAS 8
#define ESPACO 4

void inicializarTabuleiro(char tabuleiro[LINHAS][COLUNAS][ESPACO]) {
    char pecasIniciais[LINHAS][COLUNAS][ESPACO] = {
        {"tP1", "cP2", "bP3", "dP4", "rP5", "bP6", "cP7", "tP8"},
        {"PP1", "PP2", "PP3", "PP4", "PP5", "PP6", "PP7", "PP8"},
        {"   ", "   ", "   ", "   ", "   ", "   ", "   ", "   "},
        {"   ", "   ", "   ", "   ", "   ", "   ", "   ", "   "},
        {"   ", "   ", "   ", "   ", "   ", "   ", "   ", "   "},
        {"   ", "   ", "   ", "   ", "   ", "   ", "   ", "   "},
        {"PB1", "PB2", "PB3", "PB4", "PB5", "PB6", "PB7", "PB8"},
        {"TB1", "CB2", "BB3", "DB4", "RB5", "BB6", "CB7", "TB8"}
    };

    int i, j;
    for (i = 0; i < LINHAS; i++) {
        for (j = 0; j < COLUNAS; j++) {
            strcpy(tabuleiro[i][j], pecasIniciais[i][j]);
        }
    }
}

void desenharTabuleiro(char tabuleiro[LINHAS][COLUNAS][ESPACO], char *descricao) {
    int i, j;
    printf("\n%s\n", descricao);
    printf("  a   b   c   d   e   f   g   h\n");
    for (i = 0; i < LINHAS; i++) {
        printf("%d ", 8 - i);
        for (j = 0; j < COLUNAS; j++) {
            printf("%-3s ", tabuleiro[i][j]);
        }
        printf("\n");
    }
    printf("================================\n");
}

void moverPeca(char tabuleiro[LINHAS][COLUNAS][ESPACO], int lOrigem, int cOrigem, int lDestino, int cDestino) {
    strcpy(tabuleiro[lDestino][cDestino], tabuleiro[lOrigem][cOrigem]);
    strcpy(tabuleiro[lOrigem][cOrigem], "...");
}

int main() {
    char tabuleiro[LINHAS][COLUNAS][ESPACO];

    inicializarTabuleiro(tabuleiro);
    desenharTabuleiro(tabuleiro, "--- Posicao Inicial ---");

    moverPeca(tabuleiro, 6, 4, 4, 4);
    desenharTabuleiro(tabuleiro, "--- Brancas jogam e4 ---");
    
    moverPeca(tabuleiro, 1, 4, 3, 4);
    desenharTabuleiro(tabuleiro, "--- Pretas jogam e5 ---");

    moverPeca(tabuleiro, 7, 5, 4, 2);
    desenharTabuleiro(tabuleiro, "--- Brancas jogam Bc4 ---");
    
    moverPeca(tabuleiro, 0, 1, 2, 2);
    desenharTabuleiro(tabuleiro, "--- Pretas jogam Cc6 ---");

    moverPeca(tabuleiro, 7, 3, 3, 7);
    desenharTabuleiro(tabuleiro, "--- Brancas jogam Dh5 ---");
    
    moverPeca(tabuleiro, 0, 6, 2, 5);
    desenharTabuleiro(tabuleiro, "--- Pretas jogam Cf6 ---");

    moverPeca(tabuleiro, 3, 7, 1, 5);
    desenharTabuleiro(tabuleiro, "--- Brancas capturam Peao PP6 em f7 e Xeque MATE (Dxf7#) ---");

    return 0;
}