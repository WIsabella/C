#include<stdio.h>

void f(int n);

int main()
{
    int n;
    scanf("%d",&n);
    f(n);

}
void f(int n)
{
    if(n%4==0)
    {
        if(n%100==0)
        {
            if(n%400==0)
            {
                printf("Yes!");
            }
            else
            printf("No!");
        }
        else
        printf("Yes!");
    }
    else
    printf("No!");
}