#include <stdio.h>

int main()
{
    int n,m,l,r;
    char c[n];
    char c1,c2;
    scanf("%d%d",&n,&m);
    getchar();
    for(int i=0;i<m;i++)
    {
        scanf("%d %d %c %c",&l,&r,&c1,&c2);
        getchar();
        for(int j=l;j<=r;j++)
        {
            if(c[j-1]==c1)
            c[j-1]=c2;
        }
    }
    for(int i=0;i<n;i++)
    {
        printf("%c",c[i]);
    }
}