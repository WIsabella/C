#include<stdio.h>
#include<string.h>
#define ROWS 10
#define COLS 10


void mul(int A[ROWS][COLS],int B[ROWS][COLS],int R[ROWS][COLS],int row1,int col1,int col2)
{
    for(int i=0;i<row1;i++)
    {
        for(int j=0;j<col2;j++)
        {
            for(int k=0;k<col1;k++)
            {
                R[i][j]+=A[i][k]*B[k][j];
            }
        }
    }
}

int main()
{
    int T=0;
    scanf("%d",&T);
    int row1,row2,col1,col2;
    scanf("%d%d",&row1,&col1);
    int A[ROWS][COLS];
    for(int i=0;i<row1;i++)
    {
        for(int j=0;j<col1;j++)
        {
            scanf("%d",&A[i][j]);
        }
    }
    for(int k=0;k<T-1;k++)
    {
        scanf("%d%d",&row2,&col2);
        if(col1!=row2)
     {
        printf("wrong\n");
        return 0;
     }
     int B[ROWS][COLS];
     for(int i=0;i<row2;i++)
     {
        for(int j=0;j<col2;j++)
        {
            scanf("%d",&B[i][j]);
        }
     }
     int R[ROWS][COLS];
     memset(R,0,4*ROWS*COLS);
     mul(A,B,R,row1,col1,col2);
     col1=col2;
     for(int i=0;i<row1;i++)
     {
        for(int j=0;j<col2;j++)
        {
            A[i][j]=R[i][j];
        }
     }
   
    }
    for(int i=0;i<row1;i++)
    {
        for(int j=0;j<col2;j++)
        {
            printf("%d ",A[i][j]);
        }
        printf("\n");
    }
    


}