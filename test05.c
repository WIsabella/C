#include<stdio.h>
int main()
{
    int T=0;
    scanf("%d",&T);
    int N,M;
    scanf("%d %d",&N,&M);
    int A[N][M];
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<M;j++)
        {
            scanf("%d",&A[i][j]);
        }
    }
    int n,m;
    scanf("%d %d",&n,&m);
    int B[n][m];
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            scanf("%d",&B[i][j]);
        }
    }
    int C[N][m];
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<m;j++)
        {
            C[i][j]=0;
        }
    }
    if(M==n)
    {
        for(int i=0;i<N;i++)
        {
            for(int j=0;j<m;j++)
            {
                for(int k=0;k<M;k++)
                {
                    C[i][j]+=A[i][k]*B[k][j];
                    
                }
                if(j==m-1)
                printf("%d",C[i][j]);
                else
                printf("%d ",C[i][j]);
                
            }
            printf("\n");
        }
    }
    else
    printf("wrong");
}