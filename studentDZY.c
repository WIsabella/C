/*
开发程序：大作业
开发人员：马弘昊2023302071091
开发时间：2023.12
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
			case 1: show_students(sc.s, sc.items); break;        //[1]显示全部学生信息
			case 2: xuehao_paixu(sc.s, sc.items); break;         //[2]按学号排序
			case 3: GPA_paixu(sc.s, sc.items); break;            //[3] 按GPA排序
			case 4: {
						printf("请输入要查询的学生的姓名:\n");
						struct Student x;
						scanf("%s", x.name);
						name_chaxun(sc.s,&x, sc.items);
						break;
					}                                            //[4] 按姓名查询
			case 5: {
						printf("请输入要查询的年级（输入数字0、1、2分别代表2020/2021/2022级)：\n");
						char a;
						scanf("%*c", &a);
						nianji_chaxun(sc.s, a, sc.items);
						break;
					}	//[5] 按年级查询
			case 6: GPA_chaxun(sc.s, sc.items); break;           //[6] 按GPA区间查询
			case 7: tongji_renshu(sc.s, sc.items); break;        //[7] 各学院人数统计
			case 0:printf("\n感谢您的使用，再见!\n\n"); break;
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
		printf("文件无法打开。\n");
		system("pause");
		exit(0);
	}
	printf("正在从文件中读取数据...\n");
	for (n = 0; n < MAX && fscanf(fp, "%s%s%s%f", s[n].number, s[n].name, s[n].department, &s[n].GPA) != EOF; n++);
	fclose(fp);
	printf("读取完毕。\n\n");
	return n;
}
int menu(void)
{
	int select;
	printf("   欢迎使用学生信息查询系统！     \n");
	printf("===========================\n");
	printf("   本系统共有如下功能\n");
	printf("   [1] 显示全部学生信息\n");
	printf("   [2] 按学号排序\n");
	printf("   [3] 按GPA排序\n");
	printf("   [4] 按姓名查询\n");
	printf("   [5] 按年级查询\n");
	printf("   [6] 按GPA区间查询\n");
	printf("   [7] 各学院人数统计\n");
	printf("   [0] 退出系统\n");
	printf("===========================\n");
	printf("请选择要执行的功能编号：");
	scanf("%d", &select);
	while (select < 0 || select > 7)
	{
		printf("无此功能编号，请重新输入！\n");
		scanf("%d", &select);
	}
	printf("\n");
	return select;
}
void show_students(struct Student* p, int n)
{
	if (n <= 0)
	{
		printf("学生班中无学生！\n\n");
	}
	else
	{
		printf("%15s%12s%32s%6s\n", "学号", "姓名", "学院", "GPA");
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
	printf("请选择升序还是降序，输入1升序，2降序\n");
	scanf(" %d", &a);
	while (a != 1 && a != 2)
	{
		printf("输入错误，请重新输入。\n");
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
	printf("请选择升序还是降序，输入1升序，2降序\n");
	scanf(" %d", &a);
	while (a != 1 && a != 2)
	{
		printf("输入错误，请重新输入。\n");
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
	printf("请输入要查询的GPA区间（请从小到大输入两个数，自动查询两个数之间的GPA区间）：\n");
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
	printf("请输入要查询的学院（共有水利水电学院、基础医学院、电气学院、 数学与统计学院、动机学院、资源与环境科学学院、物理学院、弘毅学堂8个学院）：\n");
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


