///给定一组排序后递增的整数，再给定一个整数，使用折半查找法判断该整数是否在整数组内，并输出其下标

//输入格式
//第一行参数 N，M；N 为这一组数的个数，M 为待查找的数；第二行为 N 个整数，为排序后的数。

//输出格式
//一个整数 J，若能找到，则输出该整数在数组内的下标，若无法找到，则输出-1；
#include<stdio.h>

int main()
{
    int N=0,M=0;
    
    scanf("%d %d",&N,&M);
    int Num[N];
    int start=0,end=N;
    int middle=0;
    for(int i=0;i<N;i++)
    {
        scanf("%d",Num[i]);
    }
    for(int i=0;i<10;i++)
    {
        if(start == end-1)
        {
            if(M>Num[start]&&M>Num[end])
            printf("-1");
        }

        middle =(start+end)/2;

        if(M>Num[middle])
        {
            start=middle;
            continue;
        }
        if(middle<Num[middle])
        {
            end = middle;
            continue;
        }

        if(M=Num[middle])
        {
            printf("%d",middle);
            break;
        }
    }

    


}