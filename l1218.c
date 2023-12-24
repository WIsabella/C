#include<stdio.h>
#include<math.h>
#include<string.h>
void f(int D,int B)
{
    int n;
    if(D)
    {
        f(D/B,B);
        n=D%B;
        if(n<10)
        printf("%d",n);
        else
        printf("%c",n+87);
    }
}
int main()
{
    int A,B;
    char C[100];
    int anum=0;
    int bnum=0;
    int i=0;
    int  tasum=0;
    char t1[100];
    double tbsum=0,tssum=0;
    scanf("%d %d %s",&A,&B,&C);
    while(C[i]!='.')
    {
        i++;
        anum++;
    }
    i=0;
    bnum=strlen(C)-2;
    for(int i=0;i<anum;i++)
    {
        if(C[i]>96)
        tasum+=(C[i]-87)*pow(A,anum-i-1);
        else
        tasum+=(C[i]-48)*pow(A,anum-i-1);
    }
    for(int i=anum+1;i<strlen(C);i++)
    {
        if(C[i]>96)
        tasum+=(C[i]-87)*pow(A,anum-i-1);
        else
        tbsum+=(C[i]-48)*pow(A,bnum-i-1);
    }
    tssum=tasum+tbsum;//转化为10进制了，但是在一个数里。

    int sanum=0,sbnum=0;
    int t=(int)tssum;
    char An[50];
    f(t,B);
    int k=0,flen=0;
    char t2[100];
    int y=0;
    if(tssum-t>0)
    {
        printf(".");
        double m=tssum-t;
        while(m!=0)
        {
         if(B!=16)
         {
            t2[k]=m*B;
		  y=y*B-t2[k];
		  k++;
		  flen++;
          if(flen>8)
		  flen=8;
		  for(k=0;k<flen;k++)
		  printf("%d",t2[k]);
         }
         else
         {
    	
    		if(y%16>=10)
    		    t1[i]=y%16+87;
    	    else
    	        t1[i]=y%16+48;
    	   
    	    y=y/16;
		   i++;
           for(int j=i-1;j>=0;j--)
			printf("%c",t1[j]);
		 }
    	 
        }
		
			
			
    }
    
    else;

    

}