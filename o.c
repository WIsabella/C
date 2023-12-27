#include<stdio.h>
int main()
{
    int n,i,j,count=0,a[1000],k=0;
    scanf("%d",&n);
    for(i=2;i<=n;i++)
    {
        for(j=2;j<i;j++)
        if(i%j==0) break;

        if(i==j)
        {
            count++;
            a[k]=i;
            k++;
        }
        
    }
    printf("%d\n",count);
}