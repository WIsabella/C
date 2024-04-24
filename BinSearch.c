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
    printf("请输入数组元素的个数\n");
    int n;
    scanf("%d",&n);
    int arr[n];
    printf("请依次输入数组的元素大小:\n");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    int left=0;
    int right=n-1;
    printf("请输入要查找的数据:\n");
    int key;
    scanf("%d",&key);
    int a=bin_search(arr,left,right,key);
    printf("%d对应的数组角标是%d",key,a);
}