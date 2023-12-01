#include <stdio.h>
//实现6进制转换。
void print(int x)
{
    if(x>5)
    {
        print(x/6);//
    }
    printf("%d",x%6);
}
int main()
{
    int n=0;
    scanf("%d",&n);
    print(n);

}