#include <stdlib.h>
#include <time.h>
#include<stdio.h>
//RAND_MAX==32,767
void menu()
{
	printf("***********************\n");
	printf("***     1. play     ***\n");
	printf("***     0. exit     ***\n");
	printf("***********************\n");
}

void game()
{
	//1. ���������
	int guess = 0;
	int ret = rand() % 100 + 1;
	//printf("%d\n", ret);
	//2. ������
	int count = 5;
	while (count)
	{
		printf("�㻹�� %d �λ���\n", count);
		printf("������Ҫ�µ�����:>");
		scanf("%d", &guess);
		if (guess < ret)
		{
			printf("��С��\n");
		}
		else if (guess > ret)
		{
			printf("�´���\n");
		}
		else
		{
			printf("��ϲ�㣬�¶��ˣ�������:%d\n", ret);
			break;
		}
		count--;
	}
	if (count == 0)
	{
		printf("���ź�����λ���ʹ���꣬��սʧ�ܣ�������ǣ�%d\n", ret);
	}
}

int main()
{
	int input = 0;
	srand((unsigned int)time(NULL));
	do
	{
		menu();
		printf("��ѡ��:>");
		scanf("%d", &input);//1 0 
		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			printf("�˳���Ϸ\n");
			break;
		default:
			printf("ѡ���������ѡ��\n");
			break;
		}
	} while (input);

	return 0;
}

