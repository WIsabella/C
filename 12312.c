#include<stdio.h>
void fun(int N);
int main()
{
    int N;
    scanf("%d",&N);
    fun(N);
}
void fun(int N)
{
    int n=N;
    int a[3000];
    memset(a,0,sizeof(a));
    a[0]=1;
    int index=1,carry=0;
    for(int i=2;i<=n;i++)
    {
        for(int j=0;j<index;j++)
        {
            int temp=a[j]*i+carry;
            a[j]=temp%10;
            carry=temp/10;
        }
        while(carry)
        {
            a[index++]=carry%10;
            carry/=10;
        }
    }
    for(int i=index-1;i>=0;i--)
    {
        printf("%d",a[i]);
    }
}