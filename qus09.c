//Êä³ö9*9¿Ú¾÷
#include<stdio.h>
int main()
{
    for(int i=1;i<10;i++)
    {
        for(int j=1;j<=i;j++)
        {
            printf("%d*%d=%d\t",i,j,i*j);
        }
        printf("\n");
    }
}