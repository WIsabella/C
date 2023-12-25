#include<stdio.h>

int main()
{
    int xc,yc,xb,yb;
    scanf("%d%d%d%d",&xb,&yb,&xc,&yc);
    int xa=0,ya=0;
    int p[25][25]={0};
    p[xc-1][yc+2]=1;
    p[xc-1][yc-2]=1;
    p[xc-2][yc+1]=1;
    p[xc-2][yc-1]=1;
    p[xc+1][yc-2]=1;
    p[xc+1][yc+2]=1;
    p[xc+2][yc+1]=1;
    p[xc+2][yc-1]=1;
    p[xc][yc]=1;
    long long F[25][25]={0};
    F[0][-1]=0;
    F[-1][0]=0;
    for(int i=0;i<=xb;i++)
    {
        for(int j=0;j<=yb;j++)
        {
            if(p[i][j]!=1)
            {
                F[i][j]=F[i-1][j]+F[i][j-1];
            }  
        }

    }
    printf("%d",F[xb][yb]);
}