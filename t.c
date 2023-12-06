#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>


int main()
{
    int n;
    scanf("%d",&n);
    if(n==1||n==0)
    {
        printf("No");
    }
    else
    {
        while(n>1)
    {
        if(n%2==1)
        {
            printf("No");
            break;
        }
        if(n==2)
        {
            printf("Yes");
            break;
        }
        else
        n/=2;
    }
    }
}
