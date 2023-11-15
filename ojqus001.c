//系统将给出三个数：A、B、C，其中 C 是 A 进制数，要求将 C 转换为 B 进制数。

//A、B 均为整数
//A、B 的值在 2、8、10、16 中选取
//C 的长度不大于 10
//16 进制中字母的输入输出均为小写。 
//注：将数制之间的转换方法利用程序实现，不能利用 itoa()系列函数进行自动转换，不允许直接利用“%d”、”%o”及”%x”等格式由机器自动转换。
//输入格式
//两个整数：A、B；一个字符串 C，其中 C 是 A 进制数，要求将 C 转换为 B 进制数。

//输出格式
//一个字符串
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