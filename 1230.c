#include<stdio.h>
#include<string.h>
int main()
{
    int i,n;
    scanf("%d",&n);
    char c[55];
    scanf("%s",c);
    int len=strlen(c);
    while(n>26) n-=26;
    for(int i=0;i<len;i++)
    {
        c[i]+=n;
        if(c[i]>122)//Ӧ�ø�Ϊ��if(c[i]>122);��Ϊ���Ѿ�����һ�м���
        {
            c[i]-=26;
        }
        
    }
    printf("%s",c);
        return 0;
}