//求s=a+aa+aaa+aaaa+aa...a的值，其中a是一个数字，n为最大a的个数。例如n=5时，2+22+222+2222+22222(此时共有5个数相加)，几个数相加有键盘控制。
#include<stdio.h>

int main()
{
    int s=0,a=0,n=0,t=0;
    printf("请输入a和n的值: \n");
    scanf("%d%d",&a,&n);
    t=a;
    while(n>0)
    {
        s+=t;
        a=a*10;
        t+=a;
        n--;
    }
    printf("a+aa+aaa+...+aaaaa的值为%d",s);

}