#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define ROW 9
#define COL 9

#define ROWS ROW + 2
#define COLS COL + 2

//≥ı ºªØ∆Â≈Ã
void InitBoard(char board[ROWS][COLS], int rows, int cols, char init);

//¥Ú”°∆Â≈Ã
void DisPlayBoard(char board[ROWS][COLS], int rows, int cols);

//≤º÷√¿◊
void SetMine(char true[ROWS][COLS], int row, int col);

//≈≈≤È¿◊
void FindMine(char true[ROWS][COLS], char show[ROWS][COLS], int row, int col);