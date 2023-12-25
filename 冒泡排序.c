#include <stdio.h>

int main()
{
    int N;
    scanf("%d",&N);
    int A[N];
    for(int i=0;i<5;i++)
    {
        scanf("%d",&A[i]);
    }
    for(int i=0;i<N-1;i++)
    {
        for(int j=0;j<N-1-i;j++)
        {
            if(A[j]>A[j+1])
            {
                int t=A[j];
                A[j]=A[j+1];
                A[j+1]=t;
            }
        }
    }
    for(int i=0;i<5;i++)
    {
        printf("%d",A[i]);
    }

}