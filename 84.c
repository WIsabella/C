#include<stdio.h>
int main()
{
    int N,M=0;
    scanf("%d",&N);
    int Array[N];

    for(int i=0;i<N;i++)
    {
        if(i==N-1)
        scanf("%d",&Array[N-1]);
        else
        scanf("%d ",&Array[i]);
    }
    for(int j =1;j<N;j++)
    {
        if(Array[j]>Array[M])
        M=j;
        
    }
    if(Array[M]<Array[0])
        M=0;
    printf("%d",M);
}    