#include <stdio.h>

int main()
{
    int n;
    scanf("%d",&n);
    int i=0;
    for(i=1;i<=n;i++)
    {
        int t=0;
        int num=i;
        while(num>0)
        {
            t=t*10+num%10;//��������ʵ��һ����д����̫ǿ�ˡ�
            num/=10;
        }
        if(t==i)
        printf("%d\n",i);
    }
}