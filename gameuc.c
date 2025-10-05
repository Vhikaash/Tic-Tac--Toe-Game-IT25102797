#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "game.h"

static char **board = NULL;
static int gSize = 0;
static FILE *logfp = NULL;
static int currentPlayer = 1;

static void printBoardTo(FILE *out) {
    int n = gSize;
    fprintf(out, "\n   ");
    for (int j = 0; j < n; j++) fprintf(out, "  %d ", j);
    fprintf(out, "\n   ");
    for (int j = 0; j < n; j++) fprintf(out, "+---");
    fprintf(out, "+\n");
    for (int i = 0; i < n; i++) {
        fprintf(out, " %d ", i);
        for (int j = 0; j < n; j++) fprintf(out, "| %c ", board[i][j]);
        fprintf(out, "|\n   ");
        for (int j = 0; j < n; j++) fprintf(out, "+---");
        fprintf(out, "+\n");
    }
}

void setCurrentPlayer(int player) { currentPlayer = player; }

void initBoard(int size) {
    gSize = size;
    board = (char**)malloc(gSize * sizeof(char*));
    for (int i = 0; i < gSize; i++) {
        board[i] = (char*)malloc(gSize * sizeof(char));
        for (int j = 0; j < gSize; j++) board[i][j] = ' ';
    }
    logfp = fopen("gamelog.txt", "w");
    srand((unsigned)time(NULL));
}

void displayBoard(int size) { (void)size; printBoardTo(stdout); }

int isValidMove(int row, int col, int size) {
    (void)size;
    if (row < 0 || row >= gSize || col < 0 || col >= gSize) return 0;
    return board[row][col] == ' ';
}

void getPlayerMove(int player, int size) {
    (void)size;
    setCurrentPlayer(player);
    int r, c;
    for (;;) {
        printf("Player %d (%c) enter row and col (0-%d): ", player, player == 1 ? 'X' : 'O', gSize - 1);
        if (scanf("%d %d", &r, &c) != 2) { while (getchar() != '\n'); continue; }
        if (!isValidMove(r, c, gSize)) continue;
        board[r][c] = player == 1 ? 'X' : 'O';
        break;
    }
}

int checkWin(int size) {
    (void)size;
    char s = currentPlayer == 1 ? 'X' : 'O';
    int n = gSize;
    for (int i = 0; i < n; i++) {
        int ok = 1; for (int j = 0; j < n; j++) if (board[i][j] != s) { ok = 0; break; } if (ok) return 1;
    }
    for (int j = 0; j < n; j++) {
        int ok = 1; for (int i = 0; i < n; i++) if (board[i][j] != s) { ok = 0; break; } if (ok) return 1;
    }
    int ok = 1; for (int k = 0; k < n; k++) if (board[k][k] != s) { ok = 0; break; } if (ok) return 1;
    ok = 1; for (int k = 0; k < n; k++) if (board[k][n-1-k] != s) { ok = 0; break; } if (ok) return 1;
    return 0;
}

int checkDraw(int size) {
    (void)size;
    for (int i = 0; i < gSize; i++) for (int j = 0; j < gSize; j++) if (board[i][j] == ' ') return 0;
    return 1;
}

void logMove(int player, int size) {
    (void)size;
    if (!logfp) return;
    fprintf(logfp, "Player %d (%c) moved\n", player, player == 1 ? 'X' : 'O');
    printBoardTo(logfp);
    fflush(logfp);
}

void getComputerMove(int size) {
    (void)size;
    setCurrentPlayer(2);
    for (;;) {
        int r = rand() % gSize;
        int c = rand() % gSize;
        if (isValidMove(r, c, gSize)) { board[r][c] = 'O'; break; }
    }
}

void cleanupBoard(int size) {
    (void)size;
    if (logfp) fclose(logfp);
    if (board) {
        for (int i = 0; i < gSize; i++) free(board[i]);
        free(board);
    }
    board = NULL;
    gSize = 0;
}
