#include <stdio.h>
int main()
{
	int month = 0;
	printf("请输入月份:");
	scanf("%d", &month);
	printf("一\t二\t三\t四\t五\t六\t日\n");
	int day = 0;
	int day0 = 0;
	//判断月数
	for (int m = 1; m <= month; m++)
	{
		switch (m)
		{
		case 4:
		case 6:
		case 9:
		case 11:
			day0 = 30;
			break;
		case 2:
				day0 =29;
			break;
		default:
			day0 = 31;
			break;
		}
		if (m < month)
		{
			day += day0;
		}
	}
	int t = day % 7;
	for (int i = 0; i < t; i++)
	{
		printf("\t");
	}

	for (int i = 1; i <=day0; i++)
	{
		printf("%d\t", i );
		if ((i + day) % 7 == 0)
		{
			printf("\n");
		}
	}
	printf("\n");
	return 0;
}

