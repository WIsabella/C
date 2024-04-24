#include <stdio.h>

int main()
{
    int n,m;
    scanf("%d %d",&n,&m);
    int A[n],B[m];
    for(int i=0;i<n;i++)
    {
        A[i]=0;
    }
    for(int j=0;j<m;j++)
    {
        B[j]=0;
    }
    for(int i=0;i<n;i++)
    {
        scanf("%d",&A[i]);
    }
    for(int j=0;j<m;j++)
    {
        scanf("%d",&B[j]);
    }
    int C[n+m];
    int i=0,j=0;
    for(int k=0;k<n+m;k++)
    {
        if(i==n||j==m)
        {
            if(i==n)
            {
                C[k]=B[j];
                j++;
                continue;
            }
            if(j==m)
            {
                C[k]=A[i];
                i++;
                continue;
            }
        }
        else if(A[i]<B[j])
        {
            C[k]=A[i];
            i++;
            continue;
        }
        else if(A[i]>B[j])
        {
            C[k]=B[j];
            j++;
            continue;
        }

    }
    
    for(int i=0;i<n+m;i++)
    {
        printf("%d ",C[i]);
    }
}