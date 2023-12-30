void Print_Factorial(const int N)
{
    int n = N;
    if (n < 0)
        printf("Invalid input");
    else
    {
        int a[3000] = { 1,0 }, index = 1, carry = 0;
        for (int i = 2; i <= n; i++)
        {
            for (int j = 0; j < index; j++)
            {
                int temp = a[j] * i + carry;
                a[j] = temp % 10;
                carry = temp / 10;
            }
            while (carry)
            {
                a[index++] = carry % 10;
                carry /= 10;
            }
        }
        for (int i = index - 1; i >= 0; i--)
            printf("%d", a[i]);
    }   
}