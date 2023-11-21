//将16进制的数输出为十进制，十六进制的存储方式
//将10进制转换为8进制，16进制
#include <stdio.h>

int main()
{
    int a=0xABCDEF;
    printf("%15d",a);
    
    int a=1234;
    printf("%#o %#X",a,a);
}