#include<stdio.h>

int main()
{
    int a,b,c,m,y;
    scanf("%f,%f,%f,%f",&a,&b,&c,&m);
    if(a>1.0||b>1.0||c>1.0||m>30.0)
    {
        printf("Error\n");
    }
    else
    {
        if(m<10.0)
        {
            printf("%.2f\n",0.8*m+0.2);
        }
        else if(m<20.0)
        {
            printf("%.2f\n",0.75*m+0.2);
        }
        else
        {
            printf("%.2f\n",0.7*m+0.2);
        }
    }
}