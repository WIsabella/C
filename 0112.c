#include<stdio.h>
#include<string.h>

int main()
{
    char c[20]={"0"};
    char ch[20]={"0"};

    scanf("%[^\n]", c);//自换行停止读入
    getchar();
    scanf("%[^\n]", ch);
    
    int flag=0;
    for(int i=0;i<=strlen(c);i++)
    {
        //从第一个数开始找到开头
        if(ch[0]==c[i])
        {
            //判断是否从这个数开始相同
            for(int j=0;j<strlen(ch);j++)
            {
                if(c[i+j]==ch[j])
                {
                    //到最后相同
                    if(j==(strlen(ch)-1))
                    {
                        flag=i+1;
                        goto L;
                    }
                }
                else 
                break;
            }
        }
    }
    L:;
    if(flag==0)
    {
        printf("No!");
    }
    else
    printf("%d",flag);
}