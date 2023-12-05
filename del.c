#include <stdio.h>

int main()
{
    int n;
    scanf("%d",&n);
    int A[n];
    int B[n];
    for(int i=0;i<n;i++)
    {
        scanf("%d",&A[i]);
    }
    int m;
    scanf("%d",&m);
    int j=0;
    for(int i=0;i<n;i++)
    {
        
            if(A[i]!=m)
            {
                B[j]=A[i];
                j++;
            }
        
    }
    for(int i=0;i<j;i++)
    {
        printf("%d ",B[i]);
    }
}