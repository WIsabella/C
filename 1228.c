#include <stdio.h>
#include<math.h>
int jud(long long n);
int main()
{
    long long a[20]={0};
    int i=0,p=0,sum=0;
    while(scanf("%1lld",&a[i])!=EOF)
    {
        i++;
        p++;
    }
    for(int i=0;i<p-1;i++)
    {
        a[p+i]=a[p-2-i];
    }
    for(int j=0;j<2*p-1;j++)
    {
        sum+=a[j]*pow(10,2*p-2-j);
    }
    int z=jud(sum);
    if(z)
    printf("prime");
    else
     printf("noprime");


}
int jud(long long n)
{
    int flag=1;
    for(int i=2;i<=sqrt(n);i++)
    {
        if((n%i)==0)
        {
            flag=0;
            break;
        }
    }
    return flag;
}