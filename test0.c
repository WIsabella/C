#include<stdio.h>
int multiple(int A[N][X],int B[X][M])
{
    int C[N][M];
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<M;j++)
        {
            C[N][M]=0;
        }
    }
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<M;j++)
        {
            for(int k=0;k<X;k++)
            {
                C[i][j]+=A[i][k]*B[k][j];
            }
        }
    }

}
int main()
{
    int T=2;
    for(int i=0;i<2;i++)
    {
        int N,M;
        scanf("%d %d",&N,&M);
        int A[N][M];
        for(int j=0;j<N;j++)
        {
            for(int k=0;k<M;k++)
            {
                scanf("%d",&A[i][j]); 
            }
        }

    }


}