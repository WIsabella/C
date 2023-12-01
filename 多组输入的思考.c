#include <stdio.h>
int main()
{
    int a,max=0,min=100,sum=0,count=0;
    while(scanf("%d",&a)!=EOF)
    {
        if(a>max)
        max=a;
        if(a<min)
        min=a;
        sum+=a;
        count++;
        if(count==7)//配合上面的无限输入，判断数据个数取组来分割进行
        {
            printf("%.2f\n",(sum-max-min)/5.0);
            count =0;
            max=0;
            min=100;
            sum=0;
        }
    }
}