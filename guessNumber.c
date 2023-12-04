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
	//1. 生成随机数
	int guess = 0;
	int ret = rand() % 100 + 1;
	//printf("%d\n", ret);
	//2. 猜数字
	int count = 5;
	while (count)
	{
		printf("你还有 %d 次机会\n", count);
		printf("请输入要猜的数字:>");
		scanf("%d", &guess);
		if (guess < ret)
		{
			printf("猜小了\n");
		}
		else if (guess > ret)
		{
			printf("猜大了\n");
		}
		else
		{
			printf("恭喜你，猜对了，数字是:%d\n", ret);
			break;
		}
		count--;
	}
	if (count == 0)
	{
		printf("很遗憾，五次机会使用完，挑战失败，随机数是：%d\n", ret);
	}
}

int main()
{
	int input = 0;
	srand((unsigned int)time(NULL));
	do
	{
		menu();
		printf("请选择:>");
		scanf("%d", &input);//1 0 
		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			printf("退出游戏\n");
			break;
		default:
			printf("选择错误，重新选择\n");
			break;
		}
	} while (input);

	return 0;
}

