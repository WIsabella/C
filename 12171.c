#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int ReadData()
{
		//下面是写数据，将数字0~9写入到data.txt文件中
		FILE* fpWrite = fopen("C:\\Users\\dell\\source\\repos\\_五子棋\\_五子棋\\Remember.txt", "a");
		if (fpWrite == NULL)
		return 0;
		for (int i = 0; i < 10; i++)
			fprintf(fpWrite, "%d ", i);
		fclose(fpWrite);
		//下面是读数据，将读到的数据存到数组a[10]中，并且打印到控制台上
		int a[10] = { 0 };
		FILE* fpRead = fopen("C:\\Users\\dell\\source\\repos\\_五子棋\\_五子棋\\Remember.txt", "r");
		if (fpRead == NULL)
		return 0;
		for (int i = 0; i < 10; i++)
		{
			fscanf(fpRead, "%d ", &a[i]);
			printf("%d ", a[i]);
		}
		getchar();//等待

		return 1;
	}
int WriteData()
{
	FILE* fpWrite = fopen("C:\\Users\\dell\\source\\repos\\_五子棋\\_五子棋\\Remember.txt", "a");
	if (fpWrite == NULL)
	{
		printf("写入数据存在问题\n");
		return 0;
	}
	for (int i = 0; i < 10; i++)
		fprintf(fpWrite, "%d ", i);
	fclose(fpWrite);
}

int main()
{
	char buff[255] = { 0 };
	char x = 1, y = 2;
	buff[0] = x;
	buff[1] = y;
	FILE* fpWrite = fopen("C:\\Users\\dell\\source\\repos\\_五子棋\\_五子棋\\Remember.txt", "a");
	if (fpWrite == NULL)
	{
		printf("写入数据存在问题\n");
		return 0;
	}
	for (int i = 0; i < 10; i++)
		fprintf(fpWrite, "%d ", i);
	fclose(fpWrite);


}