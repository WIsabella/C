//ʹ�õݹ鷨��쳲��������е� n ���ֵ��

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