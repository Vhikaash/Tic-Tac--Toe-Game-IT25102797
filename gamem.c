#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "gamem.h"

static char **boardM = NULL;
static int gNM = 0;
static FILE *logfpM = NULL;
static const char SYM[3] = {'X','O','Z'};

static void printBoardToM(FILE *out) {
    int n = gNM;
    fprintf(out, "\n   ");
    for (int j = 0; j < n; j++) fprintf(out, "  %d ", j);
    fprintf(out, "\n   ");
    for (int j = 0; j < n; j++) fprintf(out, "+---");
    fprintf(out, "+\n");
    for (int i = 0; i < n; i++) {
        fprintf(out, " %d ", i);
        for (int j = 0; j < n; j++) fprintf(out, "| %c ", boardM[i][j]);
        fprintf(out, "|\n   ");
        for (int j = 0; j < n; j++) fprintf(out, "+---");
        fprintf(out, "+\n");
    }
}

void initBoardM(int size) {
    gNM = size;
    boardM = (char**)malloc(gNM * sizeof(char*));
    for (int i = 0; i < gNM; i++) {
        boardM[i] = (char*)malloc(gNM * sizeof(char));
        for (int j = 0; j < gNM; j++) boardM[i][j] = ' ';
    }
    logfpM = fopen("gamelog3.txt", "w");
    srand((unsigned)time(NULL));
}

void displayBoardM(int size) { (void)size; printBoardToM(stdout); }

int isValidMoveM(int r, int c, int size) {
    (void)size;
    if (r < 0 || r >= gNM || c < 0 || c >= gNM) return 0;
    return boardM[r][c] == ' ';
}

void getHumanMoveM(int which, int size) {
    (void)size;
    int r, c;
    for (;;) {
        printf("Player %d (%c), enter row and col (0-%d): ", which+1, SYM[which], gNM-1);
        if (scanf("%d %d", &r, &c) != 2) { while (getchar()!='\n'); continue; }
        if (!isValidMoveM(r, c, gNM)) continue;
        boardM[r][c] = SYM[which];
        break;
    }
}

void getComputerMoveM(int which, int size) {
    (void)size;
    for (;;) {
        int r = rand() % gNM, c = rand() % gNM;
        if (isValidMoveM(r, c, gNM)) { boardM[r][c] = SYM[which]; break; }
    }
}

static int lineAllM(char ch, int r0, int c0, int dr, int dc) {
    for (int k = 0; k < gNM; k++) {
        int r = r0 + dr*k, c = c0 + dc*k;
        if (boardM[r][c] != ch) return 0;
    }
    return 1;
}

int checkWinM(int which, int size) {
    (void)size;
    char s = SYM[which];
    int n = gNM;
    for (int i = 0; i < n; i++) if (lineAllM(s, i, 0, 0, 1)) return 1;
    for (int j = 0; j < n; j++) if (lineAllM(s, 0, j, 1, 0)) return 1;
    if (lineAllM(s, 0, 0, 1, 1)) return 1;
    if (lineAllM(s, 0, n-1, 1, -1)) return 1;
    return 0;
}

int checkDrawM(int size) {
    (void)size;
    for (int i = 0; i < gNM; i++) for (int j = 0; j < gNM; j++) if (boardM[i][j] == ' ') return 0;
    return 1;
}

void logMoveMM(int which, int size) {
    (void)size;
    if (!logfpM) return;
    fprintf(logfpM, "Player %d (%c) moved\n", which+1, SYM[which]);
    printBoardToM(logfpM);
    fflush(logfpM);
}

void cleanupBoardM(int size) {
    (void)size;
    if (logfpM) fclose(logfpM);
    if (boardM) {
        for (int i = 0; i < gNM; i++) free(boardM[i]);
        free(boardM);
    }
    boardM = NULL;
    gNM = 0;
}
