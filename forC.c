#include<stdio.h>

void fun(int num,int m);
int main()
{
    printf("������2024����·�(��:1)(����0��ʾ�˳�)");
    int num=0;
    int m=0;
    while(scanf("%d",&num))
    {
        if(num==0)
        break;
        switch(num)
        {
            case 1:
            case 3:
            case 5:
            case 7:
            case 8:
            case 10:
            case 12:
            m=31;
            break;
            case 4:
            case 6:
            case 9:
            case 11:
            m=30;
            break;
            case 2:
            m=29;
            break;
        }
        fun(num,m);
    }
        

}

void fun(int num,int m)
{
    for(int i=1;i<=m;i++)
        {
            printf("%d��%d��    ",num,i);
        }
        printf("\n");
}