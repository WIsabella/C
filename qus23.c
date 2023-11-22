//位运算实现2的n次方。
#include <math.h>
#include <stdio.h>

int main()
{
    int n;
    scanf("%d",&n);
    printf("%d",2<<(n-1));

}