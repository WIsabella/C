//KiKi实现一个简单计算器，实现两个数的“加减乘除”运算，用户从键盘输入算式“操作数1运算符操作数2”，计算并输出表达式的值。
//如果输入的运算符号不包括在（+、-、*、/）范围内，输出“Invalid operation!”。
//当运算符为除法运算，即“/”时。如果操作数2等于0.0，则输出“Wrong!Division by zero!”

#include <stdio.h>

int main()
{
    double a,b;
    char ch;
    while(scanf("%lf %c %lf",&a,&ch,&b)!=EOF)//注意这种输入方式泰酷辣
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