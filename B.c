#include<stdio.h>

// 二分查找
int search(int *arr, int key, int length)
{
  int start = 0, end = length - 1, mid;
  while (start <= end)
  {
    mid = (start + end) / 2;
    if (key == arr[mid])
      return mid;
    else if (key > arr[mid])
      start = mid + 1;
    else
      end = mid - 1;
  }
  return -1;
}

int main()
{
  int n, m;
  scanf("%d %d", &n, &m);
  int arr[n];
  int target[m];
  for (int i = 0; i < n; ++i)
  {
    scanf("%d", &arr[i]);
  }
  for (int i = 0; i < m; ++i)
  {
    scanf("%d", &target[i]);
  }
  for (int i = 0; i < m; ++i)
  {
    printf("%d\n", search(arr, target[i], n));
  }
  return 0;
}