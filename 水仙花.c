#include<stdio.h>
int main()
{
    int m, n;
    int a, b, c;
    while (scanf("%d %d", &m, &n) != EOF)
    {
        int flag = 0;
        for (int i = m; i <= n; i++)
        {

            a = i / 100; //个位哦
            b = (i % 100) / 10; //十位嗷
            c = i % 10;  //百位
            if (a * a * a + b * b * b + c * c * c == i)
            {
                flag++;
                printf("%d ", i);
            }
        }
        if (flag == 0)
            printf("no\n");

        else
            printf("\n");
    }

}