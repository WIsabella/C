#include <stdio.h>

int main()
{
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        int A[n];
        for(int i=1;i<n;i++)
        {
            A[i]=i+1;
        }
        int sum=0;
        for(int j=2;j<n;j++)
        {
            for(int i=2;i<j;i++)
            {
                if(A[j]!=0&&A[j]%i==0)
                {
                  A[j]=0;
                  sum++;
                }
            }
        }
        for(int i=1;i<n;i++)
        {
            if(A[i]!=0)
            printf("%d ",A[i]);
        }
        printf("\n");
        printf("%d",sum);
    }
}