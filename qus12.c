//打印出所有的"水仙花数"，所谓"水仙花数"是指一个三位数，其各位数字立方和等于该数 本身。
//例如：153是一个"水仙花数"，因为153=1的三次方＋5的三次方＋3的三次方。
#include<stdio.h>
#include<math.h>
int main()
{
    for(int i=100;i<=999;i++)
    {
        int x=i%10;
        int y=i/10%10;
        int z=i/100%10;

        if(pow(x,3)+pow(y,3)+pow(z,3)==i)
        printf("%d%d%d\n",z,y,x);
    }
}