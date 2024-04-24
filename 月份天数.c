#include <stdio.h>

int main()
{
    int y,m;
    while(scanf("%d%d",&y,&m)!=EOF)
    {
        if(m==2)
        {
            if(y%4==0)
            {
                if(y%100==0)
                {
                    if(y%400==0)
                    {
                        printf("29\n");
                    }
                    else
                    printf("28\n");
                }
                else
                printf("29\n");
            }
            else
            printf("28\n");
        }
        else
        {
            switch(m)
            {
            case 1:
            case 3:
            case 5:
            case 7:
            case 8:
            case 10:
            case 12:
            {
                printf("31\n");
            break;
            }
            
            case 4:
            case 6:
            case 9:
            case 11:
            {
                printf("30\n");
                break;
            }

            }
            

        }
        
    }

}