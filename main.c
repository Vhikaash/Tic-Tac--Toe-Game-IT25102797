#include <stdio.h>
#include "game.h"

int main() {
    int n;
    for (;;) {
        printf("Enter board size N (%d-%d): ", MIN_SIZE, MAX_SIZE);
        if (scanf("%d", &n) == 1 && n >= MIN_SIZE && n <= MAX_SIZE) break;
        while (getchar() != '\n');
        printf("Invalid size.\n");
    }

    initBoard(n);

    int player = 1;
    for (;;) {
        displayBoard(n);
        getPlayerMove(player, n);
        logMove(player, n);
        if (checkWin(n)) { displayBoard(n); printf("Player %d wins!\n", player); break; }
        if (checkDraw(n)) { displayBoard(n); printf("It's a draw!\n"); break; }
        player = (player == 1) ? 2 : 1;
    }

    cleanupBoard(n);
    return 0;
}
