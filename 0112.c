#include<stdio.h>
#include<string.h>

int main()
{
    char c[20]={"0"};
    char ch[20]={"0"};

    scanf("%[^\n]", c);//�Ի���ֹͣ����
    getchar();
    scanf("%[^\n]", ch);
    
    int flag=0;
    for(int i=0;i<=strlen(c);i++)
    {
        //�ӵ�һ������ʼ�ҵ���ͷ
        if(ch[0]==c[i])
        {
            //�ж��Ƿ���������ʼ��ͬ
            for(int j=0;j<strlen(ch);j++)
            {
                if(c[i+j]==ch[j])
                {
                    //�������ͬ
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