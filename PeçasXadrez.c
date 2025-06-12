#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define BOARD_SIZE 8

void printBoard(char board[BOARD_SIZE][BOARD_SIZE], int currentRow, int currentCol) {
    system("clear");
    printf("  a b c d e f g h\n");
    printf("  -----------------\n");
    for (int i = 0; i < BOARD_SIZE; i++) {
        printf("%d |", i + 1);
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (i == currentRow && j == currentCol) {
                printf("X ");
            } else {
                printf("%c ", board[i][j]);
            }
        }
        printf("|\n");
    }
    printf("  -----------------\n");
    printf("Posicao Atual: (%c, %d)\n", 'a' + currentCol, currentRow + 1);
}

void initializeBoard(char board[BOARD_SIZE][BOARD_SIZE]) {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            board[i][j] = '.';
        }
    }
}

void moveRook(char board[BOARD_SIZE][BOARD_SIZE], int startRow, int startCol) {
    printf("\n--- Modulo Novato: Movimento da Torre ---\n");
    printf("Simulando movimento da Torre de (%c, %d). 'X' marca a posicao atual.\n", 'a' + startCol, startRow + 1);
    int currentRow = startRow;
    int currentCol = startCol;

    printf("\nMovendo Para Cima:\n");
    for (int i = currentRow - 1; i >= 0; i--) {
        printBoard(board, i, currentCol);
        printf("Movido para: (%c, %d)\n", 'a' + currentCol, i + 1);
        getchar();
    }
    currentRow = startRow;

    printf("\nMovendo Para Baixo:\n");
    for (int i = currentRow + 1; i < BOARD_SIZE; i++) {
        printBoard(board, i, currentCol);
        printf("Movido para: (%c, %d)\n", 'a' + currentCol, i + 1);
        getchar();
    }
    currentRow = startRow;

    printf("\nMovendo Para Esquerda:\n");
    for (int j = currentCol - 1; j >= 0; j--) {
        printBoard(board, currentRow, j);
        printf("Movido para: (%c, %d)\n", 'a' + j, currentRow + 1);
        getchar();
    }
    currentCol = startCol;

    printf("\nMovendo Para Direita:\n");
    for (int j = currentCol + 1; j < BOARD_SIZE; j++) {
        printBoard(board, currentRow, j);
        printf("Movido para: (%c, %d)\n", 'a' + j, currentRow + 1);
        getchar();
    }
    printBoard(board, startRow, startCol);
    printf("\nSimulacao de movimento da Torre concluida. Pressione Enter para continuar...\n");
    getchar();
}

void moveBishop(char board[BOARD_SIZE][BOARD_SIZE], int startRow, int startCol) {
    printf("\n--- Modulo Novato: Movimento do Bispo ---\n");
    printf("Simulando movimento do Bispo de (%c, %d). 'X' marca a posicao atual.\n", 'a' + startCol, startRow + 1);
    int currentRow, currentCol;

    printf("\nMovendo Para Cima-Direita:\n");
    currentRow = startRow - 1;
    currentCol = startCol + 1;
    while (currentRow >= 0 && currentCol < BOARD_SIZE) {
        printBoard(board, currentRow, currentCol);
        printf("Movido para: (%c, %d)\n", 'a' + currentCol, currentRow + 1);
        getchar();
        currentRow--;
        currentCol++;
    }

    printf("\nMovendo Para Cima-Esquerda:\n");
    currentRow = startRow - 1;
    currentCol = startCol - 1;
    while (currentRow >= 0 && currentCol >= 0) {
        printBoard(board, currentRow, currentCol);
        printf("Movido para: (%c, %d)\n", 'a' + currentCol, currentRow + 1);
        getchar();
        currentRow--;
        currentCol--;
    }

    printf("\nMovendo Para Baixo-Direita:\n");
    currentRow = startRow + 1;
    currentCol = startCol + 1;
    while (currentRow < BOARD_SIZE && currentCol < BOARD_SIZE) {
        printBoard(board, currentRow, currentCol);
        printf("Movido para: (%c, %d)\n", 'a' + currentCol, currentRow + 1);
        getchar();
        currentRow++;
        currentCol++;
    }

    printf("\nMovendo Para Baixo-Esquerda:\n");
    currentRow = startRow + 1;
    currentCol = startCol - 1;
    while (currentRow < BOARD_SIZE && currentCol >= 0) {
        printBoard(board, currentRow, currentCol);
        printf("Movido para: (%c, %d)\n", 'a' + currentCol, currentRow + 1);
        getchar();
        currentRow++;
        currentCol--;
    }
    printBoard(board, startRow, startCol);
    printf("\nSimulacao de movimento do Bispo concluida. Pressione Enter para continuar...\n");
    getchar();
}

void moveQueen(char board[BOARD_SIZE][BOARD_SIZE], int startRow, int startCol) {
    printf("\n--- Modulo Novato: Movimento da Rainha ---\n");
    printf("Simulando movimento da Rainha de (%c, %d). 'X' marca a posicao atual.\n", 'a' + startCol, startRow + 1);
    int currentRow, currentCol;
    int dx, dy;

    int directions[8][2] = {
        {0, 1}, {0, -1}, {1, 0}, {-1, 0},
        {1, 1}, {-1, -1}, {1, -1}, {-1, 1}
    };

    for (int i = 0; i < 8; i++) {
        dx = directions[i][0];
        dy = directions[i][1];

        currentRow = startRow + dx;
        currentCol = startCol + dy;

        printf("\nMovendo na direcao (%d, %d):\n", dx, dy);
        do {
            if (currentRow >= 0 && currentRow < BOARD_SIZE && currentCol >= 0 && currentCol < BOARD_SIZE) {
                printBoard(board, currentRow, currentCol);
                printf("Movido para: (%c, %d)\n", 'a' + currentCol, currentRow + 1);
                getchar();
            } else {
                break;
            }
            currentRow += dx;
            currentCol += dy;
        } while (currentRow >= 0 && currentRow < BOARD_SIZE && currentCol >= 0 && currentCol < BOARD_SIZE);
    }
    printBoard(board, startRow, startCol);
    printf("\nSimulacao de movimento da Rainha concluida. Pressione Enter para continuar...\n");
    getchar();
}

void moveKnight(char board[BOARD_SIZE][BOARD_SIZE], int startRow, int startCol) {
    printf("\n--- Modulo Aventureiro: Movimento do Cavalo ---\n");
    printf("Simulando movimento do Cavalo de (%c, %d). 'X' marca a posicao atual.\n", 'a' + startCol, startRow + 1);
    int currentRow = startRow;
    int currentCol = startCol;

    int knightMoves[8][2] = {
        {-2, -1}, {-2, 1},
        {-1, -2}, {-1, 2},
        {1, -2}, {1, 2},
        {2, -1}, {2, 1}
    };

    printf("\nPossiveis movimentos do Cavalo de (%c, %d):\n", 'a' + startCol, startRow + 1);

    for (int i = 0; i < 8; i++) {
        int nextRow = startRow + knightMoves[i][0];
        int nextCol = startCol + knightMoves[i][1];

        if (nextRow >= 0 && nextRow < BOARD_SIZE && nextCol >= 0 && nextCol < BOARD_SIZE) {
            printBoard(board, nextRow, nextCol);
            printf("Tentando mover para: (%c, %d)\n", 'a' + nextCol, nextRow + 1);
            getchar();
        } else {
            printf("O movimento (%d, %d) de (%c, %d) estaria fora dos limites.\n",
                   knightMoves[i][0], knightMoves[i][1], 'a' + startCol, startRow + 1);
        }
    }
    printBoard(board, startRow, startCol);
    printf("\nSimulacao de movimento do Cavalo concluida. Pressione Enter para continuar...\n");
    getchar();
}

void explorePathRecursive(char board[BOARD_SIZE][BOARD_SIZE], int currentRow, int currentCol,
                          int targetRow, int targetCol, int steps, int maxSteps) {
    if (steps > maxSteps || currentRow < 0 || currentRow >= BOARD_SIZE ||
        currentCol < 0 || currentCol >= BOARD_SIZE) {
        return;
    }

    printBoard(board, currentRow, currentCol);
    printf("Explorando caminho: (%c, %d), Passos dados: %d\n", 'a' + currentCol, currentRow + 1, steps);
    getchar();

    if (currentRow == targetRow && currentCol == targetCol) {
        printf("Alvo alcancado! (%c, %d)\n", 'a' + targetCol, targetRow + 1);
        return;
    }

    int nextRow = currentRow;
    int nextCol = currentCol;

    if (currentRow < targetRow) nextRow++;
    else if (currentRow > targetRow) nextRow--;

    if (currentCol < targetCol) nextCol++;
    else if (currentCol > targetCol) nextCol--;

    if (nextRow != currentRow || nextCol != currentCol) {
        explorePathRecursive(board, nextRow, nextCol, targetRow, targetCol, steps + 1, maxSteps);
    }
}

void moveKing(char board[BOARD_SIZE][BOARD_SIZE], int startRow, int startCol) {
    printf("\n--- Modulo Mestre: Movimento do Rei (Loop Complexo) ---\n");
    printf("Simulando movimento do Rei de (%c, %d). 'X' marca a posicao atual.\n", 'a' + startCol, startRow + 1);
    int currentRow = startRow;
    int currentCol = startCol;

    printf("\nPossiveis movimentos do Rei de (%c, %d):\n", 'a' + startCol, startRow + 1);

    for (int dr = -1; dr <= 1; dr++) {
        for (int dc = -1; dc <= 1; dc++) {
            if (dr == 0 && dc == 0) {
                continue;
            }

            int nextRow = currentRow + dr;
            int nextCol = currentCol + dc;

            if (nextRow >= 0 && nextRow < BOARD_SIZE && nextCol >= 0 && nextCol < BOARD_SIZE) {
                printBoard(board, nextRow, nextCol);
                printf("Tentando mover para: (%c, %d)\n", 'a' + nextCol, nextRow + 1);
                getchar();
            } else {
                printf("O movimento (%d, %d) de (%c, %d) estaria fora dos limites.\n",
                       dr, dc, 'a' + startCol, startRow + 1);
            }
        }
    }
    printBoard(board, startRow, startCol);
    printf("\nSimulacao de movimento do Rei concluida. Pressione Enter para continuar...\n");
    getchar();
}

int main() {
    char board[BOARD_SIZE][BOARD_SIZE];
    initializeBoard(board);

    printf("Bem-vindo ao Jogo de Xadrez Revolucionario da MateCheck!\n");
    printf("Prepare-se para dominar a programacao atraves dos movimentos de xadrez em C.\n\n");
    printf("Pressione Enter para iniciar o Modulo Novato...\n");
    getchar();

    moveRook(board, 3, 3);
    moveBishop(board, 3, 3);
    moveQueen(board, 3, 3);

    printf("\nModulo Novato Concluido! Pressione Enter para prosseguir para o Modulo Aventureiro...\n");
    getchar();

    moveKnight(board, 3, 3);

    printf("\nModulo Aventureiro Concluido! Pressione Enter para prosseguir para o Modulo Mestre...\n");
    getchar();

    printf("\n--- Modulo Mestre: Movimento Avancado (Recursao) ---\n");
    printf("Simulando uma exploracao de caminho recursiva simples. Mova de (a,1) para (h,8) em no maximo 14 passos.\n");
    explorePathRecursive(board, 0, 0, 7, 7, 0, 14);
    printBoard(board, 0, 0);
    printf("\nSimulacao de exploracao de caminho recursiva concluida. Pressione Enter para continuar...\n");
    getchar();

    moveKing(board, 3, 3);

    printf("\nParabens! Voce concluiu todos os modulos e demonstrou dominio das estruturas de repeticao em C!\n");
    printf("Obrigado por jogar o Jogo de Xadrez da MateCheck!\n");

    return 0;
}
