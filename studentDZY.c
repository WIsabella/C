/*
�������򣺴���ҵ
������Ա������2023302071091
����ʱ�䣺2023.12
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100		
int read_data_from_file(struct Student* s);
int menu(void);
void show_students(struct Student* p, int n);
void xuehao_paixu(struct Student* s, int n);
void GPA_paixu(struct Student* s, int n);
void name_chaxun(struct Student* s, struct Student* y, int n);
void nianji_chaxun(struct Student* s, char y, int n);
void GPA_chaxun(struct Student* s, int n);
void tongji_renshu(struct Student* s, int n);
static void paixu1(struct Student* s, int n);
static void paixu2(struct Student* s, int n);
static void paixu3(struct Student* s, int n);
static void paixu4(struct Student* s, int n);
struct Student
{
	char number[14];
	char name[11];
	char department[31];
	float GPA;
};
struct StudentClass
{
	struct Student s[MAX];
	int items;
};
int main(void)
{
	struct StudentClass sc;
	int select;
	sc.items = read_data_from_file(sc.s);
	do
	{
		select = menu();
		switch (select)
		{
			case 1: show_students(sc.s, sc.items); break;        //[1]��ʾȫ��ѧ����Ϣ
			case 2: xuehao_paixu(sc.s, sc.items); break;         //[2]��ѧ������
			case 3: GPA_paixu(sc.s, sc.items); break;            //[3] ��GPA����
			case 4: {
						printf("������Ҫ��ѯ��ѧ��������:\n");
						struct Student x;
						scanf("%s", x.name);
						name_chaxun(sc.s,&x, sc.items);
						break;
					}                                            //[4] ��������ѯ
			case 5: {
						printf("������Ҫ��ѯ���꼶����������0��1��2�ֱ����2020/2021/2022��)��\n");
						char a;
						scanf("%*c", &a);
						nianji_chaxun(sc.s, a, sc.items);
						break;
					}	//[5] ���꼶��ѯ
			case 6: GPA_chaxun(sc.s, sc.items); break;           //[6] ��GPA�����ѯ
			case 7: tongji_renshu(sc.s, sc.items); break;        //[7] ��ѧԺ����ͳ��
			case 0:printf("\n��л����ʹ�ã��ټ�!\n\n"); break;
		}
	} while (select != 0);
	system("pause");
	return 0;
}
int read_data_from_file(struct Student* s)
{
	FILE* fp;
	int n;
	if ((fp = fopen("student_data.txt", "r")) == NULL)
	{
		printf("�ļ��޷��򿪡�\n");
		system("pause");
		exit(0);
	}
	printf("���ڴ��ļ��ж�ȡ����...\n");
	for (n = 0; n < MAX && fscanf(fp, "%s%s%s%f", s[n].number, s[n].name, s[n].department, &s[n].GPA) != EOF; n++);
	fclose(fp);
	printf("��ȡ��ϡ�\n\n");
	return n;
}
int menu(void)
{
	int select;
	printf("   ��ӭʹ��ѧ����Ϣ��ѯϵͳ��     \n");
	printf("===========================\n");
	printf("   ��ϵͳ�������¹���\n");
	printf("   [1] ��ʾȫ��ѧ����Ϣ\n");
	printf("   [2] ��ѧ������\n");
	printf("   [3] ��GPA����\n");
	printf("   [4] ��������ѯ\n");
	printf("   [5] ���꼶��ѯ\n");
	printf("   [6] ��GPA�����ѯ\n");
	printf("   [7] ��ѧԺ����ͳ��\n");
	printf("   [0] �˳�ϵͳ\n");
	printf("===========================\n");
	printf("��ѡ��Ҫִ�еĹ��ܱ�ţ�");
	scanf("%d", &select);
	while (select < 0 || select > 7)
	{
		printf("�޴˹��ܱ�ţ����������룡\n");
		scanf("%d", &select);
	}
	printf("\n");
	return select;
}
void show_students(struct Student* p, int n)
{
	if (n <= 0)
	{
		printf("ѧ��������ѧ����\n\n");
	}
	else
	{
		printf("%15s%12s%32s%6s\n", "ѧ��", "����", "ѧԺ", "GPA");
		for (int i = 0; i < n; i++)
		{
			printf("%15s%12s%32s%6.1f\n", p[i].number, p[i].name, p[i].department, p[i].GPA);
		}
		printf("\n");
	}
}
void xuehao_paixu(struct Student* s,int n)
{
	int a;
	printf("��ѡ�������ǽ�������1����2����\n");
	scanf(" %d", &a);
	while (a != 1 && a != 2)
	{
		printf("����������������롣\n");
		scanf(" %d", &a);
	}
	if (a == 1)
	{
		paixu1(s,n);
	}
	else paixu2(s,n);
}
void GPA_paixu(struct Student* s, int n)
{
	int a;
	printf("��ѡ�������ǽ�������1����2����\n");
	scanf(" %d", &a);
	while (a != 1 && a != 2)
	{
		printf("����������������롣\n");
		scanf(" %d", &a);
	}
	if (a == 1)
	{
		paixu3(s, n);
	}
	else paixu4(s, n);
}
void name_chaxun(struct Student* s,struct Student*y, int n)
{
	for (int i = 0; i < n; i++)
	{
		if (y->name == s[i].name)
		{
			printf("%15s%12s%32s%6.1f\n", s[i].number, s[i].name, s[i].department, s[i].GPA);
		}
	}
	printf("\n");
}
void nianji_chaxun(struct Student* s,char y, int n)
{
	for (int i = 0; i < n; i++)
	{
		if (y == s[i].number[3])
		{
			printf("%15s%12s%32s%6.1f\n", s[i].number, s[i].name, s[i].department, s[i].GPA);
		}
	}
	printf("\n");
}
void GPA_chaxun(struct Student* s, int n)
{
	printf("������Ҫ��ѯ��GPA���䣨���С�����������������Զ���ѯ������֮���GPA���䣩��\n");
	float p, q;
	scanf("%f%f",&p,&q);
	for (int i = 0; i < n; i++)
	{
		if (s[i].GPA >= p && s[i].GPA <= q)
		{
			printf("%15s%12s%32s%6.1f\n", s[i].number, s[i].name, s[i].department, s[i].GPA);
		}
	}
	printf("\n");
}
void tongji_renshu(struct Student* s, int n)
{
	struct Student y;
	printf("������Ҫ��ѯ��ѧԺ������ˮ��ˮ��ѧԺ������ҽѧԺ������ѧԺ�� ��ѧ��ͳ��ѧԺ������ѧԺ����Դ�뻷����ѧѧԺ������ѧԺ������ѧ��8��ѧԺ����\n");
	scanf("%s", y.department);
	for (int i = 0; i < n; i++)
	{
		if (y.department == s[i].department)
		{
			printf("%15s%12s%32s%6.1f\n", s[i].number, s[i].name, s[i].department, s[i].GPA);
		}
	}
	printf("\n");
}
static void paixu1(struct Student*s,int n)
{
	int i, j;
	for (i = 0; i < n-1; i++)
	{
		for (j = i + 1; j < n; j++)
		{
			if (s[j].number < s[i].number)
			{
				struct Student k;
				k = s[j];
				s[j] = s[i];
				s[i] = k;
			}
		}
	}
	for (int i = 0; i < n; i++)
	{
		printf("%15s%12s%32s%6.1f\n", s[i].number, s[i].name, s[i].department, s[i].GPA);
	}
	printf("\n");
}
static void paixu2(struct Student* s, int n)
{
	int i, j;
	for (i = 0; i < n; i++)
	{
		for (j = i + 1; j < n; j++)
		{
			if (s[j].number > s[i].number)
			{
				struct Student k;
				k = s[j];
				s[j] = s[i];
				s[i] = k;
			}
		}
	}
	for (int i = 0; i < n; i++)
	{
		printf("%15s%12s%32s%6.1f\n", s[i].number, s[i].name, s[i].department, s[i].GPA);
	}
	printf("\n");
}
static void paixu3(struct Student* s, int n)
{
	int i, j;
	for (i = 0; i < n - 1; i++)
	{
		for (j = i + 1; j < n; j++)
		{
			if (s[j].GPA < s[i].GPA)
			{
				struct Student k;
				k = s[j];
				s[j] = s[i];
				s[i] = k;
			}
		}
	}
	for (int i = 0; i < n; i++)
	{
		printf("%15s%12s%32s%6.1f\n", s[i].number, s[i].name, s[i].department, s[i].GPA);
	}
	printf("\n");
}
static void paixu4(struct Student* s, int n)
{
	int i, j;
	for (i = 0; i < n; i++)
	{
		for (j = i + 1; j < n; j++)
		{
			if (s[j].GPA > s[i].GPA)
			{
				struct Student k;
				k = s[j];
				s[j] = s[i];
				s[i] = k;
			}
		}
	}
	for (int i = 0; i < n; i++)
	{
		printf("%15s%12s%32s%6.1f\n", s[i].number, s[i].name, s[i].department, s[i].GPA);
	}
	printf("\n");
}


