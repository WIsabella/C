#include<stdio.h>

void f(int n);
int main()
{
    int n;
    printf("��������Ҫ�������\n");
    scanf("%d",&n);
    f(n);

}

void f(int n)
{
        for(int i=1;i<n+1;i++)
    {
        for(int j=1;j<=i;j++)
        {
            printf("%d*%d=%d\t",i,j,i*j);
        }
        printf("\n");
    }
}