#include <stdio.h>
int main()
{
    int a,max=0,min=100,sum=0,count=0;
    while(scanf("%d",&a)!=EOF)
    {
        if(a>max)
        max=a;
        if(a<min)
        min=a;
        sum+=a;
        count++;
        if(count==7)//���������������룬�ж����ݸ���ȡ�����ָ����
        {
            printf("%.2f\n",(sum-max-min)/5.0);
            count =0;
            max=0;
            min=100;
            sum=0;
        }
    }
}