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
	char true[ROWS][COLS];//true�������ڴ�ŷ��õ��׵���Ϣ
	char show[ROWS][COLS];//show�������ڴ���Ų�����׵���Ϣ
	//��ʼ������ -- true���̳�ʼ��Ϊ0,show���̳�ʼ��Ϊ*
	InitBoard(true, ROWS, COLS, '0');
	InitBoard(show, ROWS, COLS, '*');
	//��ӡ����
	DisPlayBoard(true, ROW, COL);
	DisPlayBoard(show, ROW, COL);

	//������
	SetMine(true, ROW, COL);
	//��鲼�����
	DisPlayBoard(true, ROW, COL);

	//�Ų���
	FindMine(true, show, ROW, COL);
}

int main()
{
	int input;
	srand((unsigned int)time(NULL));//���������������
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

//��Ϸ�Ż�����
//1.��������ף���Χû���� - չ��һƬ - �ݹ�
//2.�����

//��ҳɨ������HTML+CSSǰ�˼���ʵ�ֵ�