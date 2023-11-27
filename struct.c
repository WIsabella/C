#include<stdio.h>
struct student
    {
        char name[20];
        char sex[1];
        unsigned num;
        unsigned birthday;
        float height;
        float weight;
    }wjl;
int main()
{
    struct student ctz;
    struct student lzh;
    struct student dhl;
    scanf("%s",&wjl.name);
    fflush(stdin);//Çå¿Õ»º´æÇø
    scanf("%c",&wjl.sex);
    scanf("%u",&wjl.num);
    scanf("%u",&wjl.birthday);
    scanf("%f",&wjl.height);
    scanf("%f",&wjl.weight);
    printf("%c",wjl.sex);
    printf("%u",wjl.num);
    printf("%u",wjl.birthday);


}