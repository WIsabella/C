//第一行一个数 N，为题目描述中的 n；

#include<stdio.h>
int Find(int Array[],int N)
{
    int sum1=0;
    int sum2=0;
    for(int i=0;i<=pow(2,N-1)-1;i++)
    sum1 +=Array[i];
    for(int i=pow(2,N-1);i<=pow(2,N)-1;i++)
    sum2 +=Array[i];
    if(sum1>sum2)
    return Find(Array,N-1);
}
int main()
{



}

