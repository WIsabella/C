//���õݹ�ʵ�֡���һ���� n ��Ԫ�ص������������۰���ҹؼ��� key������ҵ������� key ���ڵ�λ�ã����򷵻�-1��
//��һ�в��� N��M��N Ϊ��һ�����ĸ�����M Ϊ�����ҵ������ڶ���Ϊ N ��������Ϊ����������
//һ������ J�������ҵ�����������������ڵ��±꣬���޷��ҵ��������-1��

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