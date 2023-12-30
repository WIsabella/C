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
        if(c[i]>122)//应该改为：if(c[i]>122);因为你已经在上一行加了
        {
            c[i]-=26;
        }
        
    }
    printf("%s",c);
        return 0;
}