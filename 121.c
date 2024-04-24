#include <stdio.h>

int main()
{
    int n=0;
    for(int i=1;i<=2019;i++)
    {
        int m=i;//把i单独取出来处理，防止过程中i的循环无法实现。
        while(m>0)
        {
            if(m%10==9)
            {
                n++;
                break;
            }
            else
            m/=10;
        }
    }
    printf("%d\n",n);
}