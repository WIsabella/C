//���������������Ƕ������ɴ��⣺ѧϰ�ɼ�>=90�ֵ�ͬѧ��A��ʾ��60-89��֮�����B��ʾ��60�����µ���C��ʾ��

#include<stdio.h>

int main()
{
    // int score =0;
    // printf("���������ķ�����100���ƣ� \n");
    // scanf("%d",&score);
    // if(score>100||score<0)
    //    printf("Error!");
    // else if(score>=90)
    // printf("���ĵȼ�ΪA");
    // else if(score>=60 &&score<=89)
    // printf("���ĵȼ�ΪB");
    // else 
    // printf("���ĵȼ�ΪC");
    int score=0;
    char grade;
    printf("���������ķ�����100���ƣ� \n");
    scanf("%d",&score);
    grade =(score>=90)?'A':((score>=60)?'B':'C');
    printf("%c\n",grade);




}