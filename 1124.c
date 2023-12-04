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
    for(int i=0;i<m;i++)
    {
        scanf("%d",&B[i]);
    }
    int C[n+m];
    int i=0,j=0;
    for(int k=0;k<n+m;k++)
    {
        if(A[i]<B[j])
        {
            C[k]=A[i];
            i++;
        }
        if(A[i]>B[j])
        {
            C[k]=B[j];
            j++;
        }

    }
    
    for(int i=0;i<n+m;i++)
    {
        printf("%d ",C[i]);
    }
}