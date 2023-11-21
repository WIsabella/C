#include<stdio.h>

int main()
{
    float a;
    scanf("%f",&a);
    if(a>=0.0)
    printf("%d",(int)(a+0.5));
    if(a<0)
    printf("%d",(int)(a-0.5));
}