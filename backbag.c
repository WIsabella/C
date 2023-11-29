#include<stdio.h>
#include<math.h>
int main()
{
    int c;
    int n;
    scanf("%d%d",&c,&n);
    int V[n];
    int W[n];
    for(int i=0;i<n;i++)
    {
        scanf("%d",&W[i]);
    }
    for(int i=0;i<n;i++)
    {
        scanf("%d",&V[i]);
    }
    int m=pow(2,n);
    int a[m];
    int max=0;
    int Weight=0,Value=0;
    for(int i=0;i<m;i++)
    {

        for(int i=0;i<m;i++)
     {
        int x=i;
        while(x > 0)       
      {
        a[--n] = x % 2;
        x /= 2;
      }
      for(int j=0;j<n;j++)
        {
            Weight+=a[j]*W[j];
            Value +=a[j]*V[j];
        }
        if(Weight<=c)
        {
            if(Value>=max)
            max=Value;
        }
        if(i!=m-1)
        Weight=0,Value=0;

     }
        
        
    }
    for(int i=0;i<n;i++)
    {
        if(a[i]==1)
        printf("%d ",i+1);
    }
    printf("%d %d",Weight,max);
    
    
    

    
}