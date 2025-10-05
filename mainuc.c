#include <stdio.h>
#include "gameuc.h"

int main(void) {
    int n;
    do {
        printf("Enter board size N (3 <= N <= 10): ");
        if (scanf("%d", &n) != 1) { while (getchar()!='\n'); n = 0; }
    } while (n < 3 || n > 10);

    initBoard(n);
    displayBoard(n);

    for (;;) {
        setCurrentPlayer(1);
        getPlayerMove(1, n);
        logMove(1, n);
        displayBoard(n);
        if (checkWin(n)) { printf("Player 1 (X) wins!\n"); break; }
        if (checkDraw(n)) { printf("It's a draw.\n"); break; }

        getComputerMove(n);
        logMove(2, n);
        displayBoard(n);
        if (checkWin(n)) { printf("Computer (O) wins!\n"); break; }
        if (checkDraw(n)) { printf("It's a draw.\n"); break; }
    }

    cleanupBoard(n);
    return 0;
}
