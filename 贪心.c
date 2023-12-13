#include<stdio.h>

struct good
{
	int weight;  //物品重量
	int value;   //物品价值
	float pw;    //物品单位重量的价值； pw=value/weight;
};

int main()
{
	int n, C;
	scanf("%d %d", &n, &C);
	struct good goods[n];
	struct good Good;
	for (int i = 0; i < n; i++)
	{
		scanf("%d %d", &goods[i].weight, &goods[i].value);
		goods[i].pw = (float)goods[i].value / goods[i].weight;
	}
	for (int j = 0; j < n; j++)
	{
		for (int i = 0; i < n - 1; i++)
		{
			if (goods[i].pw < goods[i + 1].pw)
			{
				Good = goods[i];
				goods[i] = goods[i + 1];
				goods[i + 1] = Good;
			}
		}
	}
	int c = 0, v = 0;
	for (int i = 0; i < n; i++)
	{
		if (c + goods[i].weight <= C)
		{
			c += goods[i].weight;
			v += goods[i].value;
		}
		else
			break;
	}
	printf("%d\n%d", c, v);

}