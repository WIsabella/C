///����һ�������������������ٸ���һ��������ʹ���۰���ҷ��жϸ������Ƿ����������ڣ���������±�

//�����ʽ
//��һ�в��� N��M��N Ϊ��һ�����ĸ�����M Ϊ�����ҵ������ڶ���Ϊ N ��������Ϊ����������

//�����ʽ
//һ������ J�������ҵ���������������������ڵ��±꣬���޷��ҵ��������-1��
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