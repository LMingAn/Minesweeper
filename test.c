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
		printf("��ѡ��");
		scanf_s("%d", &input);
		switch (input)
		{
		case 1:
			game();//ɨ�׵Ļ������裺�����ף��Ų���
			break;
		case 0:
			break;
		default:
			printf("ѡ�����������\n");
		}
	} while (input);
}