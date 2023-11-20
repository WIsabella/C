//ÃÉÌØ¿¨ÂŞËã·¨
#include<stdio.h>
#include<stdlib.h>

int main()
{
    unsigned int b=0;
    double m=0,n=0;
    scanf("%u",&b);
    int N=0;
    scanf("%d",&N);
    double end=0.0;
    srand(b);
    double a=0,c=0;
    for(int i=0;i<N;i++)
    {
        a = ((double)(rand()/(double)RAND_MAX)+1);       
        c = ((double)rand()/(double)RAND_MAX);
        if(c<=1/a)
        m++;
    }
    end =m/N;
    printf("%lf",end);
    


}

