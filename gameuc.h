#ifndef GAMEUC_H
#define GAMEUC_H

void initBoard(int size);
void displayBoard(int size);
int  isValidMove(int row, int col, int size);
void getPlayerMove(int player, int size);
int  checkWin(int size);
int  checkDraw(int size);
void logMove(int player, int size);
void getComputerMove(int size);
void cleanupBoard(int size);
void setCurrentPlayer(int player);

#endif
