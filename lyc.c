#include<stdio.h>

int main()
{
    int m=0,n=0,k=0,a=0;
    scanf("%d,%d",&m,&n);
    k=m<n?m:n;
    while(m%k!=0||n%k!=0)
    k--;
    printf("%d\n",k);
    a=m*n/k;
    printf("%d\n",a);
    return 0;
}