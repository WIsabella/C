//KiKiʵ��һ���򵥼�������ʵ���������ġ��Ӽ��˳������㣬�û��Ӽ���������ʽ��������1�����������2�������㲢������ʽ��ֵ��
//��������������Ų������ڣ�+��-��*��/����Χ�ڣ������Invalid operation!����
//�������Ϊ�������㣬����/��ʱ�����������2����0.0���������Wrong!Division by zero!��

#include <stdio.h>

int main()
{
    double a,b;
    char ch;
    while(scanf("%lf %c %lf",&a,&ch,&b)!=EOF)//ע���������뷽ʽ̩����
    {
        if(ch=='+'||ch=='-'||ch=='*'||ch=='/')
        {
            if(ch=='+')
            {
                printf("%.4lf%c%.4lf=%.4lf\n",a,ch,b,a+b);
            }
            if(ch=='-')
            {
                printf("%.4lf%c%.4lf=%.4lf\n",a,ch,b,a-b);
            }
            if(ch=='*')
            {
                printf("%.4lf%c%.4lf=%.4lf\n",a,ch,b,a*b);
            }
            if(ch=='/')
            {
                if(b==0.0)
                printf("Wrong!Division by zero!\n");
                else
                printf("%.4lf%c%.4lf=%.4lf\n",a,ch,b,a/b);
            }
            

        }
        else
        {
          printf("Invalid operation!\n");
        }
    }
    


}