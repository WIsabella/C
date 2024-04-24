#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    int A[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &A[i]);
    }
    for (int i = 1; i < n; i++)
    {
        if (A[1] >=A[0])
        {
            if (A[i] < A[i - 1])
            {
                printf("unsorted");
                break;
            }
            if (i == n - 1)
                printf("sorted");
        }
        if(A[1]<A[0])
        {
            if(A[i]>A[i-1])
            {
                printf("unsorted");
                break;
            }
            if (i == n - 1)
            printf("sorted");
        }



    }

}