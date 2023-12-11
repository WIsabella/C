#include<stdio.h>
#include<string.h>
#include<math.h>
void f(int D,int B)
{
    int n;
    if(D)
    {
        f(D/B,B);
        n=D%B;
        if(n<10)
        printf("%d",n);
        else
        printf("%c",n-9+96);

    }
}
int main()
{
    int A,B;
    char C[10];
    int D=0;
    scanf("%d %d",&A,&B);
    scanf("%s",C);
    int n=strlen(C);
    for(int i=0;i<n;i++)
    {
        D+=(C[i]-48)*pow(A,(n-1-i));//储存的是ASCII码   减去48才是真正的数据！！！！
    }
    // do
    //     {
    //         if(B==8)
    //         printf("o");
    //         if(B==16)
    //         printf("ox");
    //     }while(0);
    f(D,B);
}