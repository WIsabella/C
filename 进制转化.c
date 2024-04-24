#include<stdio.h> 
#include<stdlib.h>
#include<math.h>
#include<string.h> 
int main()
{
  char str[100];
  int num=0;
  char t[10000];
  int a,b,i,j,h;
  int y=0;
  scanf("%d %d %s",&a,&b,str);
  h=strlen(str);

  if(a!=16)
{   
    for(i=0;i<h;i++) 
    y+=(str[h-1-i]-48)*pow(a,i);   
}	
else
{    
    for(i=0;i<h;i++) 
      {
	  if(str[h-1-i]<60)
        num=str[h-1-i]-48;
		 
	  else 
	   {
        num=str[h-1-i]-87;
	   }

	    y=y+num*pow(16,i);
	    	 	           	   
	   }     
}
i=0;
if(b==10)
printf("%d",y);

else
{

    if(b!=16)
     {  
        int len=0;
		while(y!=0)
            {
			t[i]=y%b;
            y/=b;
            i++;
			len++;  
		    } 
			for(i=len-1;i>=0;i--)
			printf("%d",t[i]);
			
      }        
    else
    {  
	while(y!=0)
    	{ 
    		if(y%16>=10)
    		    t[i]=y%16+87;
    	    else
    	        t[i]=y%16+48;
    	   
    	    y=y/16;
		   i++;
		}
    	for(j=i-1;j>=0;j--)
			printf("%c",t[j]);
			
	}    
}
	return 0;
 } 