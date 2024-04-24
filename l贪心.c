#include<stdio.h>

struct Good
{
    float value;
    float weight;
    float pw;
};

int main()
{
    int n;
    int C;
    float v=0.0;
    float w=0.0;
    struct Good good;
    scanf("%d %d",&n,&C);
    struct Good Good[n];
    for(int i=0;i<n;i++)
    {
        scanf("%f %f",&Good[i].weight,&Good[i].value);
        Good[i].pw=Good[i].value/Good[i].weight;
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n-1;j++)
        {
            if(Good[j].pw<Good[j+1].pw)
            {
                good=Good[j];
                Good[j]=Good[j+1];
                Good[j+1]=good;
            }
            
        }
    }
    for(int i=0;i<n;i++)
    {
        if(w+Good[i].weight<=C)
        {
            w+=Good[i].weight;
            v+=Good[i].value;
        }
        else
        break;
    }
    printf("%.0f\n",w);
    printf("%.0f",v);
}