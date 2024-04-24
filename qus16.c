//输入一行字符，分别统计出其中英文字母、空格、数字和其它字符的个数。
#include<stdio.h>


int main()
{
    char c;
    int letters=0,spaces=0,number=0,others=0;
    printf("请输入一段字符：\n");
    while((c=getchar())!='\n')
    {
        if(c>='a'&&c<='z'||c>='A'&&c<='Z')//如何判断一个字符是不是英文字母
        letters++;
        else if(c==' ')//如何确定为单个字符，注意是==而不是=
        spaces++;
        else if(c>='0'&&c<='9')//全部给我用 ‘ ’ 字符哇
        number++;
        else
        others++;
    }
    printf("字母个数为%d个,空格为%d个,数字为%d个,其他字符为%d个",letters,spaces,number,others);


}