#include <stdio.h>
int cal(int *p,int n);
int main() {
    int n;
    scanf("%d",&n);
    int A[n];
    for(int i=0;i<n;i++)
    {
        scanf("%d",&A[i]);
    }
    int *p=A;
    printf("%d",cal(p,n));

}

int cal(int *p,int n)
{
    if(n==1)
    return *p;
    else
    return *p+cal((p+1),n-1);
}