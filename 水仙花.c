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

            a = i / 100; //��λŶ
            b = (i % 100) / 10; //ʮλ�
            c = i % 10;  //��λ
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