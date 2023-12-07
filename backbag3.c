#include<stdio.h>
#include<math.h>
int n; 
void fun(int x[n])
{
	int i;
	for(i=0;i<n;i++) 
	   if(x[i]!=1)
        {x[i]=1; return;}
	   else x[i]=0;
	   return;
}
 
int main()
{
    int w[100],v[100];
	int x[100]={0},y[100]={0};
	int tv=0,tv1=0,tw=0,i,j,C;
	scanf("%d",&C);
	scanf("%d",&n); 
	for(i=0;i<n;i++)
	scanf("%d",&w[i]);
	for(i=0;i<n;i++)
	scanf("%d",&v[i]);
	for(j=1;j<=pow(2,n);j++)
    {
		fun(x);
		for(i=0;i<n;i++)
        {
			tw+=w[i]*x[i];
			tv+=v[i]*x[i];
		}
		if(tw<=C&&tv>tv1)
        {
			tv1=tv;    
			for(i=0;i<n;i++)
            {
				y[i]=x[i];		
			}
		}
		tw=0;
		tv=0;
	}
	printf("0-1背包问题的最优解为:");//输出形式不对
	  for(i=0;i<n;i++)  printf("%d ",y[i]);
	  printf("\n总价值为:%d",tv1);	
}