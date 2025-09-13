#ifndef GAME_H
#define GAME_H

// Function names
void initBoard(int size);
void displayBoard(int size);
void getPlayerMove(int player, int size);
int isValidMove(int row, int col, int size);
int checkWin(int size);
int checkDraw(int size);
void logMove(int player, int size);
void getComputerMove(int size);

#endif

