//һ���100�׸߶��������£�ÿ����غ�����ԭ�߶ȵ�һ�룻�����£������ڵ�10�����ʱ�������������ף���10�η�����ߣ�
#include<stdio.h>
int main()
{
    float h=100;
    float l=0;
    for(int i=0;i<10;i++)
    {
        l+=h;
        h/=2;
        if(i==9) break;
        l+=h;
    }
    printf("%f %f",l,h);


}
