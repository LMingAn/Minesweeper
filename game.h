#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define ROW 9
#define COL 9

#define ROWS ROW + 2
#define COLS COL + 2

//��ʼ������
void InitBoard(char board[ROWS][COLS], int rows, int cols, char init);

//��ӡ����
void DisPlayBoard(char board[ROWS][COLS], int rows, int cols);

//������
void SetMine(char true[ROWS][COLS], int row, int col);

//�Ų���
void FindMine(char true[ROWS][COLS], char show[ROWS][COLS], int row, int col);