//题目描述
//系统将给出三个数：A、B、C，其中 C 是 A 进制数，要求将 C 转换为 B 进制数。

//A、B 均为整数
//A、B 的值在 2、8、10、16 中选取
//C 的长度不大于 10
//16 进制中字母的输入输出均为小写
//注：将数制之间的转换方法利用程序实现，不能利用 itoa()系列函数进行自动转换，不允许直接利用“%d”、”%o”及”%x”等格式由机器自动转换。
//输入格式
//两个整数：A、B；一个字符串 C，其中 C 是 A 进制数，要求将 C 转换为 B 进制数。

//输出格式
//一个字符串

#include<stdio.h>
#include<string.h>
#include<math.h>
int main()
{
    int A=0,B=0,TA=0;
    int T[10]={0};
    char C[10]={0};
    char Q[10]={0};

    scanf("%d",&A);
    scanf("%d",&B);
    scanf("%s",&C);

        for(int i=9;i>=0;i++)//怎么实现只输入三位数，让他填到这三位上；
        {
            T[i]=pow(A,i)*C[i];
            TA +=T[i];
        }
printf("%d",TA);

        for(int i=0;;i++)
        {
            
            Q[i]=TA%B;
            TA =TA/B;
            if(TA=0)
            break;
        }
        for(int i=9;i>=0;i--)
        {
            printf("%s",Q[i]);
        }

        
        













}