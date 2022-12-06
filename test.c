#include"game.h"

void menu()
{
	printf("*****************************\n");
	printf("*******    1. play    *******\n");
	printf("*******    0. exit    *******\n");
	printf("*****************************\n");
}

void game()
{
	char true[ROWS][COLS];//true棋盘用于存放放置的雷的信息
	char show[ROWS][COLS];//show棋盘用于存放排查出的雷的信息
	//初始化棋盘 -- true棋盘初始化为0,show棋盘初始化为*
	InitBoard(true, ROWS, COLS, '0');
	InitBoard(show, ROWS, COLS, '*');
	//打印棋盘
	DisPlayBoard(true, ROW, COL);
	DisPlayBoard(show, ROW, COL);

	//布置雷
	SetMine(true, ROW, COL);
	//检查布置情况
	DisPlayBoard(true, ROW, COL);

	//排查雷
	FindMine(true, show, ROW, COL);
}

int main()
{
	int input;
	srand((unsigned int)time(NULL));//用于生成随机的雷
	do
	{
		menu();
		printf("请选择：");
		scanf_s("%d", &input);
		switch (input)
		{
		case 1:
			game();//扫雷的基本步骤：布置雷，排查雷
			break;
		case 0:
			break;
		default:
			printf("选择错误，请重试\n");
		}
	} while (input);
}

//游戏优化方向
//1.如果不是雷，周围没有雷 - 展开一片 - 递归
//2.标记雷

//网页扫雷是用HTML+CSS前端技术实现的