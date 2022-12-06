#include"game.h"

//初始化棋盘
void InitBoard(char board[ROWS][COLS], int rows, int cols, char init)
{
	int x, y;
	for (x = 0; x < rows; x++)
	{
		for (y = 0; y < cols; y++)
			board[x][y] = init;
	}
}
//void InitBoard(char show[ROWS][COLS], int rows, int cols)
//{
//	int x, y, a = 0;
//	//先初始化第一行和第一列的数字，再初始化棋盘的符号*
//	//第一行的数字
//	for (y = 0; y < cols - 1; y++)
//	{
//		show[0][y] = 'a';
//		a++;
//	}
//	//第一列的数字
//	for (x = 0; x < rows - 1; x++)
//	{
//		show[x][0] = 'a';
//		a++;
//	}
//	//棋盘内容
//	for (x = 1; x < rows - 1; x++)
//	{
//		for (y = 1; y < cols - 1; y++)
//			show[x][y] = '*';
//	}
//}

//打印棋盘
void DisPlayBoard(char board[ROWS][COLS], int row, int col)
{
	int x, y;
	printf("---------扫雷游戏---------\n");
	for (x = 0; x <= row; x++)
	{
		if (x == 0)//打印横坐标
		{
			for (y = 0; y <= col; y++)
				printf("%d ", y);
			printf("\n");//打印完空行
			x++;
		}
		printf("%d ", x);//打印纵坐标
		for (y = 1; y <= col; y++)
			printf("%c ", board[x][y]);
		printf("\n");
	}
	printf("---------扫雷游戏---------\n");
	printf("\n");
}

//布置雷
void SetMine(char true[ROWS][COLS], int row, int col)
{
	int x, y, a = Mode;//a为布置雷的个数
	while(a)//此处也可用for循环，但修改雷个数较麻烦
	{
		x = rand() % row + 1;
		y = rand() % col + 1;
		if (true[x][y] == '0')
		{
			true[x][y] = '1';//布置雷
			a--;
		}
	}
}

//排查雷
//static
//1.修饰局部变量
//2.修饰全局变量
//3.修饰函数

static int MineSum(char true[ROWS][COLS], int x, int y)
{
	return true[x - 1][y - 1] +
		true[x - 1][y] +
		true[x - 1][y + 1] +
		true[x][y - 1] +
		true[x][y + 1] +
		true[x + 1][y - 1] +
		true[x + 1][y] +
		true[x + 1][y + 1] - 8 * '0';
}

void FindMine(char true[ROWS][COLS], char show[ROWS][COLS], int row, int col)
{
	//1.输入要排查的坐标
	//2.判断坐标处是不是雷
		//（1）是雷 - 很遗憾游戏失败 - 游戏结束
		//（2）不是雷 - 统计坐标周围有几个雷并打印出来 - 游戏继续

	int Win = 0;
	int x, y;
	while (Win < row * col - Mode)
	{
		printf("请输入坐标：");
		scanf_s("%d %d", &x, &y);
		//判断坐标的合法性
		if (x >= 1 && x <= row && y >= 1 && y <= col)
		{
			if (true[x][y] == '1')
			{
				printf("很遗憾，游戏失败：\n");
				break;
			}
			else
			{
				//在没有踩到雷的情况下，检查周围有几个雷
				int sum = MineSum(true, x, y);//MineSum用于统计周围雷的个数
				show[x][y] = sum + '0';
				//显示排查出的信息
				DisPlayBoard(show, row, col);
				Win++;
			}
		}
		else
			printf("输入错误，请重试：\n");
	}
	if (Win == row * col - Mode)
		printf("恭喜你，游戏获胜\n");
}