//���õݹ�ʵ�֡���һ���� n ��Ԫ�ص������������۰���ҹؼ��� key������ҵ������� key ���ڵ�λ�ã����򷵻�-1��
//������ʽ����һ�в��� N��M��N Ϊ��һ�����ĸ�����M Ϊ�����ҵ������ڶ���Ϊ N ��������Ϊ����������
//�����ʽ��һ������ J�������ҵ�����������������ڵ��±꣬���޷��ҵ��������-1��

#include<stdio.h>
int main()
{
    int n=0,key=0;
    scanf("%d",&n);
    int Array[n];
    scanf("%d",&key);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&Array[i]);
    }
    int start=0;
    int end =n-1;
    int middle=0;
    while(start<=end)
    {
        middle=(start+end)/2;
        if(Array[middle]==key)
        {
            printf("%d",middle);
            break;
        }
        else if(Array[middle]>key)
        {
            end=middle-1;
        }
        else 
        start=middle+1;
        if(start>=end-1&&Array[start]!=key&&Array[end]!=key)
        {
            printf("-1");
            break;

        }
        
    }


}