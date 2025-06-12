#include <stdio.h>
#include <stdlib.h>

#define LINHAS 10
#define COLUNAS 10
#define NUM_NAVIOS 5

char tabuleiro1[LINHAS][COLUNAS];
char tabuleiro2[LINHAS][COLUNAS];
char tabuleiro_revelado1[LINHAS][COLUNAS];
char tabuleiro_revelado2[LINHAS][COLUNAS];

void inicializarTabuleiro(char tabuleiro[LINHAS][COLUNAS]) {
    for (int i = 0; i < LINHAS; i++) {
        for (int j = 0; j < COLUNAS; j++) {
            tabuleiro[i][j] = '~';
        }
    }
}

void imprimirTabuleiro(char tabuleiro[LINHAS][COLUNAS], int revelarNavios) {
    printf("   ");
    for (int j = 0; j < COLUNAS; j++) {
        printf("%d ", j);
    }
    printf("\n");

    for (int i = 0; i < LINHAS; i++) {
        printf("%2d ", i);
        for (int j = 0; j < COLUNAS; j++) {
            if (!revelarNavios && tabuleiro[i][j] == 'N') {
                printf("~ ");
            } else {
                printf("%c ", tabuleiro[i][j]);
            }
        }
        printf("\n");
    }
}

void posicionarNavios(char tabuleiro[LINHAS][COLUNAS], int jogador) {
    int linha, coluna;
    printf("\n--- Jogador %d: Posicione seus %d navios ---\n", jogador, NUM_NAVIOS);

    for (int i = 0; i < NUM_NAVIOS; i++) {
        while (1) {
            printf("Posicione o navio %d (linha coluna): ", i + 1);
            scanf("%d %d", &linha, &coluna);

            if (linha >= 0 && linha < LINHAS && coluna >= 0 && coluna < COLUNAS && tabuleiro[linha][coluna] == '~') {
                tabuleiro[linha][coluna] = 'N';
                break;
            } else {
                printf("Posição inválida ou já ocupada. Tente novamente.\n");
            }
        }
        printf("Tabuleiro do Jogador %d:\n", jogador);
        imprimirTabuleiro(tabuleiro, 1);
    }
}

int realizarAtaque(char tabuleiro_oponente[LINHAS][COLUNAS], char tabuleiro_revelado_proprio[LINHAS][COLUNAS], int *navios_restantes_oponente) {
    int linha, coluna;
    printf("Digite as coordenadas para o ataque (linha coluna): ");
    scanf("%d %d", &linha, &coluna);

    if (linha < 0 || linha >= LINHAS || coluna < 0 || coluna >= COLUNAS) {
        printf("Coordenadas fora do tabuleiro. Tente novamente.\n");
        return -1;
    }

    if (tabuleiro_revelado_proprio[linha][coluna] != '~') {
        printf("Você já atacou essa posição. Tente novamente.\n");
        return -1;
    }

    if (tabuleiro_oponente[linha][coluna] == 'N') {
        printf("Parabéns! Você acertou um navio!\n");
        tabuleiro_oponente[linha][coluna] = 'X';
        tabuleiro_revelado_proprio[linha][coluna] = 'X'; // <-- AQUI ESTAVA O ERRO! Faltava o 'X';
        (*navios_restantes_oponente)--;
        return 1;
    } else {
        printf("Que pena! Você acertou a água.\n");
        tabuleiro_oponente[linha][coluna] = 'O';
        tabuleiro_revelado_proprio[linha][coluna] = 'O';
        return 0;
    }
}

int main() {
    inicializarTabuleiro(tabuleiro1);
    inicializarTabuleiro(tabuleiro2);
    inicializarTabuleiro(tabuleiro_revelado1);
    inicializarTabuleiro(tabuleiro_revelado2);

    int navios_jogador1 = NUM_NAVIOS;
    int navios_jogador2 = NUM_NAVIOS;

    posicionarNavios(tabuleiro1, 1);
    posicionarNavios(tabuleiro2, 2);

    printf("\n--- Início da Batalha! ---\n");

    while (navios_jogador1 > 0 && navios_jogador2 > 0) {
        printf("\n--- Turno do Jogador 1 ---\n");
        printf("Seu tabuleiro (seus navios):\n");
        imprimirTabuleiro(tabuleiro1, 1);
        printf("\nTabuleiro do inimigo (seus ataques):\n");
        imprimirTabuleiro(tabuleiro_revelado2, 0);

        int resultado_ataque1 = realizarAtaque(tabuleiro2, tabuleiro_revelado2, &navios_jogador2);
        if (resultado_ataque1 == -1) {
            continue;
        }

        if (navios_jogador2 == 0) {
            printf("\n!!! PARABÉNS, JOGADOR 1 VENCEU A BATALHA NAVAL !!!\n");
            break;
        }

        printf("\nPressione Enter para o próximo turno...");
        getchar();
        getchar();

        printf("\n--- Turno do Jogador 2 ---\n");
        printf("Seu tabuleiro (seus navios):\n");
        imprimirTabuleiro(tabuleiro2, 1);
        printf("\nTabuleiro do inimigo (seus ataques):\n");
        imprimirTabuleiro(tabuleiro_revelado1, 0);

        int resultado_ataque2 = realizarAtaque(tabuleiro1, tabuleiro_revelado1, &navios_jogador1);
        if (resultado_ataque2 == -1) {
            continue;
        }

        if (navios_jogador1 == 0) {
            printf("\n!!! PARABÉNS, JOGADOR 2 VENCEU A BATALHA NAVAL !!!\n");
            break;
        }

        printf("\nPressione Enter para o próximo turno...");
        getchar();
        getchar();
    }

    printf("\n--- Fim do Jogo ---\n");
    printf("\nTabuleiro final do Jogador 1:\n");
    imprimirTabuleiro(tabuleiro1, 1);
    printf("\nTabuleiro final do Jogador 2:\n");
    imprimirTabuleiro(tabuleiro2, 1);

    return 0;
}
