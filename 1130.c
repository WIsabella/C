#include <stdio.h>

int main()
{
    int a, b,c;
    while(scanf("%d%d%d",&a,&b,&c)!=EOF)
    {
            if((a+b<=c)||(a+c<=b)||(b+c<=a)) printf("Not a triangle!");
    else{
        if(a!=b&&b!=c&&a!=c) printf("Ordinary triangle!");
        else if((a=b)&&(b=c)) printf("Equilateral triangle!");
        else printf("Isosceles triangle!");
    }
    }

   
    return 0;
}