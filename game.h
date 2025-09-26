#ifndef GAME_H
#define GAME_H

#define MIN_SIZE 3
#define MAX_SIZE 10

void initBoard(int size);
void displayBoard(int size);
void getPlayerMove(int player, int size);
int  isValidMove(int row, int col, int size);
int  checkWin(int size);
int  checkDraw(int size);
void logMove(int player, int size);
void getComputerMove(int size);
void cleanupBoard(int size);

#endif
