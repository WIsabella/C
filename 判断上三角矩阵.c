#include <stdio.h>
int jud(int n,int a[n][n]);
int main()
{
    int n;
    scanf("%d",&n);
    int a[n][n];
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            scanf("%d",&a[i][j]);
        }
    }
    if(jud(n,a))
    printf("YES\n");
    else
     printf("NO\n");
    
}
int jud(int n,int a[n][n])
{
    int count=0;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<i;j++)
        {
            if(a[i][j]!=0)
            {
                count++;
            }
        }
    }
    if(count==0)
    return 1;
    else
     return 0;
}