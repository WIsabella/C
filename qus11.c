//��Ŀ���ж� 101 �� 200 ֮�������,�������

#include<stdio.h>
#include<math.h>
int main()
{
    int i=0,j=0,count=0;
    for (i=101; i<=200; i++) 
    {
        for (j=2; j<i; j++) 
        {
            if (i%j==0) 
                break;
        }

        if (j>=i) 
        {
            count++;
            printf("%d ",i);
            if (count % 5 == 0) 
            printf("\n");
        }
    }    
}