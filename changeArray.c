#include<stdio.h>
int a,b;
void change(int *a,int *b)
{
    int t=*a;
    *a=*b;
    *b=t;
}
int main()
{
    int n;
    scanf("%d",&n);
    int A[n],B[n];
    for(int i=0;i<n;i++)
    {
        scanf("%d",&A[i]);
    }
    for(int i=0;i<n;i++)
    {
        scanf("%d",&B[i]);
    }
    for(int i=0;i<n;i++)
    {
        change(&A[i],&B[i]);
    }
    for(int i=0;i<n;i++)
    {
        printf("%d ",A[i]);
    }
    printf("\n");
    for(int i=0;i<n;i++)
    {
        printf("%d ",B[i]);
    }
}