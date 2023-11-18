//使用递归法求斐波那契序列第 n 项的值。

#include<stdio.h>

int main()
{
    int F[300],n=0;
    F[0]=0;
    F[1]=0;
    F[2]=1;
    scanf("%d",&n);
    for(int i=3;i<=n;i++)
    {
        F[i]=F[i-1]+F[i-2];
    }
    printf("%d",F[n]);



}