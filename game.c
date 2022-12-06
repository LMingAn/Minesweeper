#include"game.h"

//��ʼ������
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
//	//�ȳ�ʼ����һ�к͵�һ�е����֣��ٳ�ʼ�����̵ķ���*
//	//��һ�е�����
//	for (y = 0; y < cols - 1; y++)
//	{
//		show[0][y] = 'a';
//		a++;
//	}
//	//��һ�е�����
//	for (x = 0; x < rows - 1; x++)
//	{
//		show[x][0] = 'a';
//		a++;
//	}
//	//��������
//	for (x = 1; x < rows - 1; x++)
//	{
//		for (y = 1; y < cols - 1; y++)
//			show[x][y] = '*';
//	}
//}

//��ӡ����
void DisPlayBoard(char board[ROWS][COLS], int row, int col)
{
	int x, y;
	printf("---------ɨ����Ϸ---------\n");
	for (x = 0; x <= row; x++)
	{
		if (x == 0)//��ӡ������
		{
			for (y = 0; y <= col; y++)
				printf("%d ", y);
			printf("\n");//��ӡ�����
			x++;
		}
		printf("%d ", x);//��ӡ������
		for (y = 1; y <= col; y++)
			printf("%c ", board[x][y]);
		printf("\n");
	}
	printf("---------ɨ����Ϸ---------\n");
	printf("\n");
}

//������
void SetMine(char true[ROWS][COLS], int row, int col)
{
	int x, y, a = Mode;//aΪ�����׵ĸ���
	while(a)//�˴�Ҳ����forѭ�������޸��׸������鷳
	{
		x = rand() % row + 1;
		y = rand() % col + 1;
		if (true[x][y] == '0')
		{
			true[x][y] = '1';//������
			a--;
		}
	}
}

//�Ų���
//static
//1.���ξֲ�����
//2.����ȫ�ֱ���
//3.���κ���

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
	//1.����Ҫ�Ų������
	//2.�ж����괦�ǲ�����
		//��1������ - ���ź���Ϸʧ�� - ��Ϸ����
		//��2�������� - ͳ��������Χ�м����ײ���ӡ���� - ��Ϸ����

	int Win = 0;
	int x, y;
	while (Win < row * col - Mode)
	{
		printf("���������꣺");
		scanf_s("%d %d", &x, &y);
		//�ж�����ĺϷ���
		if (x >= 1 && x <= row && y >= 1 && y <= col)
		{
			if (true[x][y] == '1')
			{
				printf("���ź�����Ϸʧ�ܣ�\n");
				break;
			}
			else
			{
				//��û�вȵ��׵�����£������Χ�м�����
				int sum = MineSum(true, x, y);//MineSum����ͳ����Χ�׵ĸ���
				show[x][y] = sum + '0';
				//��ʾ�Ų������Ϣ
				DisPlayBoard(show, row, col);
				Win++;
			}
		}
		else
			printf("������������ԣ�\n");
	}
	if (Win == row * col - Mode)
		printf("��ϲ�㣬��Ϸ��ʤ\n");
}