#include<stdio.h>

int main()
{
    int n;
    scanf("%d",&n);
    int A[n];
    int B[n];
    for(int i=0;i<n;i++)
    {
        scanf("%d",&A[i]);
        scanf("%d",&B[i]);
    }
    A[n]=1001;
    for(int i=0;i<n;i++)
    {
        if(B[i]>=A[i+1])
        {
            B[i]=-1;
            A[i+1]=-1;
        }
    }
    int i=1,j=0;
    printf("%d ",A[0]);
    while(i<n&&j<n)
    {
        if(A[i]==-1||B[j]==-1)
        {
            if(A[i]==-1)
            {
                i++;
                continue;
            }
            if(B[j]==-1)
            {
                j++;
                continue;
            }
        }
        printf("%d\n",B[j]);
        j++;
        printf("%d ",A[i]);
        i++;
        
    }
    printf("%d",B[n-1]);
}