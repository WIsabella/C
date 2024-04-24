#include <stdio.h>
int main()
{
    int n;
    scanf("%d",&n);
    int A[n];
    for(int i=0;i<n;i++)
    {
        scanf("%d",&A[i]);
    }
    int m;
    scanf("%d",&m);
    int j;
    A[-1]=-1;
    A[n]=100;//wok,Ì«ÉñÆæÁË°É£¡
    for(j=0;j<=n-1;j++)
    {
        if(A[j-1]<m&&A[j]>m)
        {
            break;
        }
    }
    if(m>A[n-1])
    j=n;
    
    for(int l=n;l>j;l--)
    {
        A[l]=A[l-1];
    }
    A[j]=m;
    for(int i=0;i<=n;i++)
    {
    printf("%d ",A[i]);
    }

}