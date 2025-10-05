#ifndef GAMEM_H
#define GAMEM_H

void initBoardM(int size);
void displayBoardM(int size);
int  isValidMoveM(int row, int col, int size);
void getHumanMoveM(int which, int size);
void getComputerMoveM(int which, int size);
int  checkWinM(int which, int size);
int  checkDrawM(int size);
void logMoveMM(int which, int size);
void cleanupBoardM(int size);

#endif
