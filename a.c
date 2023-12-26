#include <stdio.h>
int Ack(int n,int m);
int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    int a=Ack(n,m);
    printf("%d",a);
}
int Ack(int n,int m)
{
    if(m==0)
    return n+1;
    if(m>0&&n==0)
    {
        return Ack(m,1);
    }
    if(m>0&&n>0)
    {
        return Ack(m-1,(Ack(m,n-1)));
    }
}