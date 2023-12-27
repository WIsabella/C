#include <stdio.h>

int main()
{
    char s[100]={0};
    while(scanf("%s",&s)!=EOF)
    {
        if(s[0]>=65&&s[0]<=90)
        {
            printf("%c",s[0]);
        }
        else printf("%c",s[0]-32);
    }

}