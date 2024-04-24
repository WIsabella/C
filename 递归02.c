#include <stdio.h>
int digit(int x,int i);
int main()
{
    int x,i;
    scanf("%d%d",&x,&i);
    int a=digit(x,i);
}
int digit(int x,int i)
{
    if(i==1)
    {
        return x%10;
    }
    else 
    {
        return digit(x/10,i-1)*10+x%10;
    }
}