#include<stdio.h>
int main()
{
    int day=0;
    int sum=0;
    scanf("%d",&day);
    int count =0;            
    for(int i=1;i<=day;i++)
    {
        for(int j=0;j<i;j++)
        {
            sum+=i;
            count++;         
            if(count==day)
            {
                goto here;
            }
        } 

    }
    here: printf("%d",sum);
    return 0;
}