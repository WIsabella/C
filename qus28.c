#include<stdio.h>
#include<math.h>
int main()
{
    for(int i=100;i<201;i++)
    {
        int j=2;
        for(j=2;j<=sqrt(i);j++)
        {
            if(i%j==0)
            break;
        }
        if(j>sqrt(i))
        printf("%d ",i);
    }
}