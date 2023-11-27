#include<stdio.h>

int Search(int A[],int key,int length)
{
    int start=0;
    int end=length-1;
    int mid;
    while(start<=end)
    {
        mid=(start+end)/2;
        if(A[mid]==key)
        return mid;
        else if(A[mid]<key)
        {
            start=mid+1;
        }
        else if(A[mid]>key)
        {
            end =mid-1;
        }
    }
    return -1;

} 
int main()
{
    int n=0;
    scanf("%d",&n);
    int m;
    scanf("%d",&m);
    int A[n];
    int B[m];
    for(int i=0;i<n;i++)
    {
        scanf("%d",&A[i]);
    }
    for(int i=0;i<m;i++)
    {
        scanf("%d",&B[i]);
    }
    for(int i=0;i<m;i++)
    {
        printf("%d\n",Search(A,B[i],n));
    }


}