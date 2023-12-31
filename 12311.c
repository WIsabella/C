#include<stdio.h>
#include<string.h>
int main()
{
    int a[100],b[100],c[100];
    memset(a,0,sizeof(a));
    memset(b,0,sizeof(b));
    memset(c,0,sizeof(c));
    int la=0,lb=0;
    while(scanf("%1d",&a[la])!=EOF)
    {
        la++;
    }
    while(scanf("%1d",&b[lb])!=EOF)
    {
        lb++;
    }
    int m;
    m = la >= lb ? la:lb;
    int count=0;
    for(int i=la;i>=0;i--)
    {
        if(i!=0)
        {
            if(a[i]+b[i]+count>=10)
        {
            c[i]=a[i]+b[i]+count-10;
            count=1;
        }
        else
        {
            c[i]=a[i]+b[i]+count;
            count=0;
        }
        }
        else
        {
            c[0]=a[i]+b[i]+count;
        }
        
        
    }
    
    if(c[0]>10)
    {
        
        printf("1");
        c[0]-=10;
        for(int i=0;i<la;i++)
        {
            printf("%d",c[i]);
        }
    }
    else
    {
     for(int i=0;i<=la-1;i++)
     {
        printf("%d",c[i]);
     }
    }
}