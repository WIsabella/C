#include <stdio.h>

int main()
{
    int n=0;
    for(int i=1;i<=2019;i++)
    {
        int m=i;//��i����ȡ����������ֹ������i��ѭ���޷�ʵ�֡�
        while(m>0)
        {
            if(m%10==9)
            {
                n++;
                break;
            }
            else
            m/=10;
        }
    }
    printf("%d\n",n);
}