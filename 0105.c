int FactorialSum(List L)
{
    int sum = 0;
    while (L)
    {
        int fact = 1;
        for (int i = 2; i <= L->Data; i++)
            fact *= i;
        sum += fact;
        L = L->Next;
    }
    return sum;
}
