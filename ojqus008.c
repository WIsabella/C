#include<stdio.h>
#include<math.h>
#define row 100000
int Find(int a[],int n)
{
    int start=0,end=n-1;//和这里的取值有关，中间数是怎么定义的，mid。
    while(start<end)
    {
        int sum1=0,sum2=0;
        int mid=start+(end-start)/2;//mid 为什么这么定义，一个意思。
        for(int i=start;i<=mid;i++)//为什么是<=  ???
        {
            sum1+=a[i];
        }
        for(int i=mid+1;i<=end;i++)
        {
            sum2+=a[i];
        }
        if(sum1==sum2)
        return start;
        else if(sum1>sum2)
        {
            start=mid+1;
        }
        else if(sum1<sum2)
        {
            end=mid;
        }
    }
    return start;
}
int main()
{
    int n;
    scanf("%d",&n);
    int m=pow(2,n);
    int a[m];
    for(int i=0;i<pow(2,n);i++)
    {
        scanf("%d",&a[i]);
    }
    int f=Find(a,m);
    printf("%d",f);
}