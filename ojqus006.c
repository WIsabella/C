//���õݹ鷨�ҳ�һ�������е����Ԫ��
//��һ��һ���� N��Ϊ������Ԫ�صĸ������ڶ��� N ���������Կո���зָ���Ϊ�����е�Ԫ�ء�
//һ���� M��Ϊ�����е����Ԫ�ء�
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