#include<stdio.h>

int main()
{
    int n=0;
    scanf("%d",&n);
    int A[n];
    int B[n];
    for(int i=0;i<n;i++)
    {
        B[i]=0;
    }
    for(int i=0;i<n;i++)
    {
        scanf("%d",&A[i]);
    }
    int max=A[0];
    for(int i=0;i<n;i++)
    {
        if(A[i]>max)
        {
            max=A[i];
        }
    }

    int j=0;
    for(int i=0;i<n;i++)
    {
        if(A[i]==max)
        {
           B[j]=i;
           j++; 
        }
        
    }
    if(B[0]==max)
    printf("0 ");
    for(int i=0;i<n;i++)
    {
        
        if(B[i]!=0)
        printf("%d ",B[i]);
    }
}