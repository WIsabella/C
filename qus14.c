//利用条件运算符的嵌套来完成此题：学习成绩>=90分的同学用A表示，60-89分之间的用B表示，60分以下的用C表示。

#include<stdio.h>

int main()
{
    // int score =0;
    // printf("请输入您的分数（100分制） \n");
    // scanf("%d",&score);
    // if(score>100||score<0)
    //    printf("Error!");
    // else if(score>=90)
    // printf("您的等级为A");
    // else if(score>=60 &&score<=89)
    // printf("您的等级为B");
    // else 
    // printf("您的等级为C");
    int score=0;
    char grade;
    printf("请输入您的分数（100分制） \n");
    scanf("%d",&score);
    grade =(score>=90)?'A':((score>=60)?'B':'C');
    printf("%c\n",grade);




}