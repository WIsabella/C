#include<stdio.h>

int f(int n,int a[n]);
int main()
{
    int n;
    scanf("%d",&n);
    int a[n];
    while(f(n,a)!=EOF)
    {
        int sum=0;
        for(int i=0;i<n;i++)
        {
            sum+=a[i];
        }
        printf("%d",sum);
    }
    
}
int f(int n,int a[n])
{
    int flag=0;
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
        flag++;
    }
    if(flag==n)
    return 1;
    else return -1;
}