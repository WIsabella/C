#include <stdio.h>

int main()
{
    int N;
    scanf("%d",&N);
    int bottle=0,cap=0,money,sum=0;
    money=N%2;
    sum=N/2;
    bottle=N/2;
    cap=N/2;
    
    
        while(bottle>=2||cap>=4)
        {
            while(bottle>=2)
            {
                int m=bottle/2;
                sum+=m;
                cap+=m;
                bottle%=2;
                bottle+=m;
            }
            while(cap>=4)
            {
                int m=cap/4;
                sum+=m;
                bottle+=m;
                cap%=4;
                cap+=m;
            }
        }
    printf("%d %d %d %d",sum,bottle,cap,money);
}