#include <stdio.h>
#include<math.h>
int main()
{
    float a,b,c;
    while(scanf("%f%f%f",&a,&b,&c)!=EOF)
    {
        if(a==0)
    printf("Not quadratic equation");
    if(a!=0)
    {
        int det;
        det=pow(b,2)-4*a*c;
        if(det==0)
        printf("x1=x2=%.2f\n",(-b/(2*a))+0);
        if(det>0)
        printf("x1=%.2f;x2=%.2f\n",(-b-pow(det,0.5))/(2*a),(-b+pow(det,0.5))/(2*a));
        if(det<0)
        printf("x1=%.2f-%.2fi;x2=%.2f+%.2fi\n",-b/(2*a),pow(-det,0.5)/(2*a),-b/(2*a),pow(-det,0.5)/(2*a));
    }
    }   
}