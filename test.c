#include"game.h"

void menu()
{
	printf("*****************************");
	printf("*******    1. play    *******");
	printf("*******    0. exit    *******");
	printf("*****************************");
}

int main()
{
	int input;
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