//����һ���ַ����ֱ�ͳ�Ƴ�����Ӣ����ĸ���ո����ֺ������ַ��ĸ�����
#include<stdio.h>


int main()
{
    char c;
    int letters=0,spaces=0,number=0,others=0;
    printf("������һ���ַ���\n");
    while((c=getchar())!='\n')
    {
        if(c>='a'&&c<='z'||c>='A'&&c<='Z')//����ж�һ���ַ��ǲ���Ӣ����ĸ
        letters++;
        else if(c==' ')//���ȷ��Ϊ�����ַ���ע����==������=
        spaces++;
        else if(c>='0'&&c<='9')//ȫ�������� �� �� �ַ���
        number++;
        else
        others++;
    }
    printf("��ĸ����Ϊ%d��,�ո�Ϊ%d��,����Ϊ%d��,�����ַ�Ϊ%d��",letters,spaces,number,others);


}