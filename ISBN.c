#include <stdio.h>

int main()
{
    char c[11];
    scanf("%c",&c[0]);
    getchar();
    scanf("%c%c%c",&c[1],&c[2],&c[3]);
    getchar();
    scanf("%c%c%c%c%c",&c[4],&c[5],&c[6],&c[7],&c[8]);
    getchar();
    scanf("%c",&c[9]);
    int sum=0;
    for(int i=0;i<9;i++)
    {
        sum +=((i+1)*(int)(c[i]-'0'));//字符数字转换为实际数字。
    }
    int det;
    det=sum%11;

    if(c[9]=='X'&&det==10)
    printf("Right");
    if(c[9]=='X'&&det!=10)
     printf("%c-%c%c%c-%c%c%c%c%c-%d",c[0],c[1],c[2],c[3],c[4],c[5],c[6],c[7],c[8],det);
    if(c[9]!='X')
    {
      if(det==(c[9]-'0'))
      printf("Right");
      else if(det==10)
      {
        printf("%c-%c%c%c-%c%c%c%c%c-X",c[0],c[1],c[2],c[3],c[4],c[5],c[6],c[7],c[8]);
      }
      else if(det!=10)
      printf("%c-%c%c%c-%c%c%c%c%c-%d",c[0],c[1],c[2],c[3],c[4],c[5],c[6],c[7],c[8],det);
      
    
    }
    

}