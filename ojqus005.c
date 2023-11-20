//利用递归实现。在一组有 n 个元素的有序数据中折半查找关键字 key，如果找到，返回 key 所在的位置，否则返回-1。
//第一行参数 N，M；N 为这一组数的个数，M 为待查找的数；第二行为 N 个整数，为排序后的数。
//一个整数 J，若能找到，这该整数在数组内的下标，若无法找到，则输出-1；

#include<stdio.h>
int tSearch(int start,int end,int M,int Array[])
{
    if(start>end)
    return -1;
    int middle=(start+end)/2;
    if(Array[middle]==M)
    return middle;
    else if(Array[middle]>M)
    return tSearch(start,middle-1,M,Array);
    else if(Array[middle]<M)
    return tSearch(middle+1,end,M,Array);

}
int main()
{
    int N;
    scanf("%d",&N);
    int start=0;
    int end=N-1;
    int M=0;
    scanf("%d",&M);
    int Array[N];
    for(int i=0;i<N;i++)
    {
        scanf("%d",&Array[i]);
    }
    int F=tSearch(start,end,M,Array);
    printf("%d",F);



}