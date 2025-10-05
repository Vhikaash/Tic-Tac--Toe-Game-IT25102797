#include <stdio.h>
#include "gamem.h"

int main(void) {
    int n;
    do {
        printf("Enter board size N (3 <= N <= 10): ");
        if (scanf("%d", &n) != 1) { while (getchar()!='\n'); n = 0; }
    } while (n < 3 || n > 10);

    int role[3] = {1,0,0};
    for (int i = 0; i < 3; i++) {
        int x;
        do {
            printf("Is Player %d human? (1=yes,0=no): ", i+1);
            if (scanf("%d", &x) != 1) { while (getchar()!='\n'); x = -1; }
        } while (x != 0 && x != 1);
        role[i] = x;
    }
    if (role[0] + role[1] + role[2] == 0) role[0] = 1;

    initBoardM(n);
    displayBoardM(n);

    int turn = 0;
    for (;;) {
        if (role[turn]) getHumanMoveM(turn, n); else getComputerMoveM(turn, n);
        logMoveMM(turn, n);
        displayBoardM(n);
        if (checkWinM(turn, n)) { printf("Player %d wins!\n", turn+1); break; }
        if (checkDrawM(n)) { printf("It's a draw.\n"); break; }
        turn = (turn + 1) % 3;
    }

    cleanupBoardM(n);
    return 0;
}
