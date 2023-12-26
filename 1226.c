#include <stdio.h>

int main()
{
    int n;
    scanf("%d",&n);
    int a[n][n];
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(j==0||i==j)
            {
                a[i][j]=1;
            }
            else
            a[i][j]=0;
        }
    }
    for(int i=2;i<n;i++)
    {
        for(int j=1;j<i;j++)
        {
            a[i][j]=a[i][j-1]+a[i-1][j-1];
        }
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(a[i][j]==0)
            printf("     ");
            else
             printf("%5d",a[i][j]);
        }
        printf("\n");
    }
    

}