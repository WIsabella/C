//ϵͳ��������������A��B��C������ C �� A ��������Ҫ�� C ת��Ϊ B ��������

//A��B ��Ϊ����
//A��B ��ֵ�� 2��8��10��16 ��ѡȡ
//C �ĳ��Ȳ����� 10
//16 ��������ĸ�����������ΪСд�� 
//ע��������֮���ת���������ó���ʵ�֣��������� itoa()ϵ�к��������Զ�ת����������ֱ�����á�%d������%o������%x���ȸ�ʽ�ɻ����Զ�ת����
//�����ʽ
//����������A��B��һ���ַ��� C������ C �� A ��������Ҫ�� C ת��Ϊ B ��������

//�����ʽ
//һ���ַ���
#include<stdio.h>
#include<math.h>
#include<string.h>

int Nchg(int m,int B)
{
    int n;
    if(m)
    {
        Nchg(m/B,B);
        n=m%B;
        if(n<10)
        printf("%d",n);
        else
        printf("%c",n+55);

    }
} 

int main()
{
    int A=0,B=0;
    char C[11]={0};
    scanf("%d",&A);
    scanf("%d",&B);
    scanf("%s",C);
    int len=strlen(C);
    int num=0,sum=0;
    for(int i=0;i<len;i++)
    {
        if(C[i]>'A'&&C[i]<'F')
        num=C[i]-'A'+10;
        else if(C[i]>'0'&&C[i]<'9')
        num=C[i]-'0';
        sum=sum*A+num;
    }
    int y=sum;
    int n=0;
    Nchg(sum,B);

}