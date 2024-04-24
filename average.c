#include<stdio.h>

int main()
{
    int A[10];
    float sum=0.0;
    for(int i=0;i<10;i++)
    {
        scanf("%d",&A[i]);
        sum+=A[i];
    }
    printf("%.1f",sum/10.0);
}