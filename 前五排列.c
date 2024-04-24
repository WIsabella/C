#include <stdio.h>
int main()
{
    int n;
    scanf("%d", &n);
    int A[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &A[i]);
    }

    for (int i = 0; i < 5; i++)
    {
        int max = 0, l = 0;
        for (int j = i; j < n; j++)
        {
            if (A[j] > max)
            {
                max = A[j];
                l = j;
            }
        }
        int t=0;
        t = A[i];
        A[i] = A[l];
        A[l] = t;
    }
    for(int i=0;i<5;i++)
    {
        printf("%d ",A[i]);
    }


}