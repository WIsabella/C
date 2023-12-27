#include <stdio.h>
#include <math.h>
int main()
{
    int star,min;
    scanf("%d %d",&star,&min);
    int h=star/100;
    int m=star%100;
    int add_h=min/60;
    int add_m=min%60;
    h+=add_h;
    if(min<0)
    {
        if(m<abs(add_m))
        {
            h--;
            m=60+m+add_m;
        }
        }
    else
    {
        if(m+add_m>=60)
        {
            h++;
            m=m+add_m-60;
        }
          else{
            m+=add_m;
        }
        }
    
    printf("%d%02d",h,m);
}
