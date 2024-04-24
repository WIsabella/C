#include<stdio.h>
int main()
{
    int T=0;
    scanf("%d",&T);
    for(int i=0;i<T;i++)
    {
        if(i==0)
        {
        int n=0,m=0;
        scanf("%d %d",&n,&m);
        int A[T][n][m];    
        for(int j=0;j<n;j++)
        {
            for(int k=0;k<m;k++)
            {
                scanf("%d",&A[T][j][k]);
            }
        }

        }
        if(i>0)
        {
        int N=0,M=0;
        scanf("%d %d",&N,&M);
        int B[T][N][M];    
        for(int j=0;j<N;j++)
        {
            for(int k=0;k<M;k++)
            {
                scanf("%d",&B[T][j][k]);
                if(m!=N)
                {
                    printf("wrong");
                }
                
            }
        }
        }
    }
    
}