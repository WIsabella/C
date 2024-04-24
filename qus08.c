//题目：输入三个整数x,y,z，请把这三个数由小到大输出。

#include<stdio.h>

int main()
{
    int x=0,y=0,z=0;
    printf("请依次输入这三个数的值： \n");
    scanf("%d",&x);
    scanf("%d",&y);
    scanf("%d",&z);
    int t=0;
    if(y>x)
    {
        t=x;
        x=y;
        y=t;
    }
    if(z>x)
    {
        t=x;
        x=z;
        z=t;
    }
    if(z>y)
    {
        t=z;
        z=y;
        y=t;
    }
    printf("%d\t%d\t%d",z,y,x);
}