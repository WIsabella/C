#include<stdio.h>
#include<math.h>

int main()
{
    int C,n,Weight=0,Value=0;
    
    scanf("%d%d",&C,&n);
    int W[n],V[n];
    for(int i=0;i<n;i++)
    {
        scanf("%d",&W[i]);
    }
    for(int i=0;i<n;i++)
    {
        scanf("%d",&V[i]);
    }
    int D[n],B[n],E[n];
    for(int i=0;i<n;i++)
    {
        D[i]=0,B[i]=0,E[i]=0;
    }
    int k=0,l=0;
    for(int i=0;i<pow(2,n);i++)
    {
        int a=i;
        while(a>0)
        {
            B[k]=a%2;
            a/=2;
            k++;
        }
        for(int j=k-1;j>=0;j--)
        {
            D[l]=B[j];
            l++;
        }
        int tWeight =0,tValue=0;
        for(int j=0;j<n;j++)
        {
            tWeight+=D[i]*W[i];
        }
        for(int j=0;j<n;j++)
        {
            tValue+=D[i]*V[i];
        }
        if(tWeight<=C)
        {
            if(tValue>=Value)
            {
                Value=tValue;
                Weight=tWeight;
                for(int i=0;i<n;i++)
                {
                    E[i]=D[i];
                }
            }
            
        }
    }
    for(int i=0;i<n;i++)
    {
        printf("%d ",E[i]);
    }
    printf("%d ",Weight,Value);

    
}