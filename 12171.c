#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int ReadData()
{
		//������д���ݣ�������0~9д�뵽data.txt�ļ���
		FILE* fpWrite = fopen("C:\\Users\\dell\\source\\repos\\_������\\_������\\Remember.txt", "a");
		if (fpWrite == NULL)
		return 0;
		for (int i = 0; i < 10; i++)
			fprintf(fpWrite, "%d ", i);
		fclose(fpWrite);
		//�����Ƕ����ݣ������������ݴ浽����a[10]�У����Ҵ�ӡ������̨��
		int a[10] = { 0 };
		FILE* fpRead = fopen("C:\\Users\\dell\\source\\repos\\_������\\_������\\Remember.txt", "r");
		if (fpRead == NULL)
		return 0;
		for (int i = 0; i < 10; i++)
		{
			fscanf(fpRead, "%d ", &a[i]);
			printf("%d ", a[i]);
		}
		getchar();//�ȴ�

		return 1;
	}
int WriteData()
{
	FILE* fpWrite = fopen("C:\\Users\\dell\\source\\repos\\_������\\_������\\Remember.txt", "a");
	if (fpWrite == NULL)
	{
		printf("д�����ݴ�������\n");
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
	FILE* fpWrite = fopen("C:\\Users\\dell\\source\\repos\\_������\\_������\\Remember.txt", "a");
	if (fpWrite == NULL)
	{
		printf("д�����ݴ�������\n");
		return 0;
	}
	for (int i = 0; i < 10; i++)
		fprintf(fpWrite, "%d ", i);
	fclose(fpWrite);


}