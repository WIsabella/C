#include<stdio.h>
int main()
{
    int n,m;
    scanf("%d",&n);
    scanf("%d",&m);
    int nums[n];
    int targets[m];
    for(int i=0;i<n;i++)
    {
        scanf("%d",&nums[i]);
    }
    for(int i=0;i<m;i++)
    {
        scanf("%d",&targets[i]);
    }
    for(int i=0;i<m;i++)
    {
        int now=targets[i];
        int start=0,end=n-1;
        for(;;)
        {
            int middle;
            middle=(start+end)/2;
            if(nums[middle]==now)
            {
                printf("%d\n",middle);
                break;
            }
            else if(nums[middle]>now)
            {
                end =middle-1;
            }
            else if(nums[middle]<now)
            {
                start =middle+1;
            }
            if(middle>=end&&nums[middle]!=now)
            {
                printf("-1");
                break;
            }


        }
    }


}