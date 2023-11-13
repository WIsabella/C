//第一行一个整数 n，代表接下来有多少行字符串需要读取，接下来 n 行为待读取的字符串，字符串中包含空格。
//输出读入的 n 行字符串
#include<stdio.h>
int main()
{
    int n=0;
    scanf("%d",&n);
    getchar();
    int a[100];
    for(int i=0;i<n;i++)
    {
        scanf("%[^\n]",a);
        getchar();
        printf("%s\n",a);
    }

 
}