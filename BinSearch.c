#include<stdio.h>


int bin_search(int arr[], int left, int right, int key)
{
    while(left<right)
    {
    int middle=(left+right)/2;
    if(arr[middle]==key)
    {
        return middle;
    }
    else if(arr[middle]<key)
    {
        left=middle+1;
    }
    else if(arr[middle]>key)
    {
        right=middle+1;
    }
    }
    return -1;
    
}
int main()
{
    printf("����������Ԫ�صĸ���\n");
    int n;
    scanf("%d",&n);
    int arr[n];
    printf("���������������Ԫ�ش�С:\n");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    int left=0;
    int right=n-1;
    printf("������Ҫ���ҵ�����:\n");
    int key;
    scanf("%d",&key);
    int a=bin_search(arr,left,right,key);
    printf("%d��Ӧ������Ǳ���%d",key,a);
}