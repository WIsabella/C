//利用递归法找出一个数组中的最大元素
//第一行一个数 N，为数组中元素的个数，第二行 N 个整数，以空格进行分隔，为数组中的元素。
//一个数 M，为数组中的最大元素。
#include<stdio.h>
int SearchMax(int N,int Array[])
{
    
    if(N>=1)
    {
        if(SearchMax(N-1,Array)>Array[N-1])
            return SearchMax(N-1,Array);
        else
        return Array[N-1];
    }
    else
    return Array[0];


}

int main()
{
    int N=0;
    scanf("%d",&N);
    int Array[N];
    for(int i=0;i<N;i++)
    {
        scanf("%d",&Array[i]);
    }
    int M=0;
    M =SearchMax(N,Array);
    printf("%d",M);

}