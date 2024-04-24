#include <stdio.h>

int main()
{
    int n,x;
    scanf("%d %d",&n,&x);
    int sum=0;
    for(int i=1;i<n+1;i++)
    {
        int m=i;
        while(m>0)
        {
            if(m%10==x)
            sum++;
            m/=10;
        }

    }
    printf("%d",sum);
    }