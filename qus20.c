#include <stdio.h>

int main()
{
    char c;
    while((c=getchar())!=EOF)
    {
        getchar();
        c=c+32;
        printf("%c\n",c);
    }
}