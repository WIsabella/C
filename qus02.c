//��һ��һ������ n������������ж������ַ�����Ҫ��ȡ�������� n ��Ϊ����ȡ���ַ������ַ����а����ո�
//�������� n ���ַ���
#include<stdio.h>
int main()
{
    int n=0;
    scanf("%d",&n);
    getchar();
    int a[100];
    for(int i=0;i<n;i++)
    {
        scanf("%[^\n]",a);
        getchar();
        printf("%s\n",a);
    }

 
}