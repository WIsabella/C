//一球从100米高度自由落下，每次落地后反跳回原高度的一半；再落下，求它在第10次落地时，共经过多少米？第10次反弹多高？
#include<stdio.h>
int main()
{
    float h=100;
    float l=0;
    for(int i=0;i<10;i++)
    {
        l+=h;
        h/=2;
        if(i==9) break;
        l+=h;
    }
    printf("%f %f",l,h);

}
