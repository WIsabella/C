#include<stdio.h> 
#include<stdlib.h>
#include<math.h>
#include<string.h> 
int main()
{
  char str[100];
  char t1[10000];
  int t2[10000];
  char t3[1000];
  int num;//16�����µ� ����  
  int A,B;//a,bΪ������ 
  int i;//�����ֲ����� 

  int h;//�ַ����� 
  int y1=0;//��������ʮ���ƵĴ�С 
  double y2=0; //С������ʮ���ƵĴ�С 
  double sum=0;//�� 
  scanf("%d %d %s",&A,&B,str);
  h=strlen(str);//�ַ��ĳ���
  int number=0;//�����γ��� 
    while(str[number]!='.')
    number++;
     
    
       
    if(A!=16)
   {    for(i=0;i<number;i++) 
            y1+=(str[number-1-i]-48)*pow(A,i);
      for(i=number+1;i<h;i++) 
            y2+=(str[i]-48)*pow(A,-i+number);    
	   sum=y2+y1;  
			
	}	
	else
    {
        for(i=0;i<number;i++) 
      {
	    if(str[number-1-i]<60)
        num=str[number-1-i]-48; 
	    else 
	    {
        num=str[number-1-i]-87;
	    }  
	    y1=y1+num*pow(16,i);//���� 
	  }
        for(i=number+1;i<h;i++) 
      {
	    if(str[i]<60)
        num=str[i]-48;
	    else 
	    {
        num=str[i]-87;
		}  
	    y2=y2+num*pow(16,-i+number);//С�� 
	  }  
		sum=y1+y2;	
		if(A==16&&B==10)
		{
            printf("%.8lf",sum);
		goto l; 
		}
}//����ʮ��������			

			
			
 
   if(B==10)
   printf("%g\n",sum) ;
   else 
{   
     if(B!=16)
     {  
        int len=0,flen=0;
        int k=0,j=0;

        if(y1==0)
        printf("0");

		while(y1!=0)
            {
			  t1[j]=y1%B;
              y1/=B;
              j++;
			  len++;  
		    } 
			for(j=len-1;j>=0;j--)
			printf("%d",t1[j]);
			printf(".");

		while(y2!=0)
		    {
		    t2[k]=y2*B;
		    y2=y2*B-t2[k];
		    k++;
		    flen++;
			}	
			if(flen>8)
			flen=8;
			for(k=0;k<flen;k++)
			printf("%d",t2[k]);
		
      } 
	  else
	  {	
        int len=0,flen=0;
        int k=0,j=0;

        if(y1==0)
        printf("0");
	  	
        while(y1!=0)
    	{ 
    		if(y1%16>=10)
    		    t1[j]=y1%16+87;
    	    else
    	        t1[j]=y1%16+48;
    	   
    	    y1=y1/16;
		    j++;
		    len++;
		}

    	for(j=len-1;j>=0;j--)
			printf("%c",t1[j]);
			printf(".");
		while(y2!=0)
		    {int y=(int)(y2*16);
		    if(y>=10)
            t3[k]=y+87;
				
    	    else
                t3[k]=y+48;		
		    y2=y2*16-y;
		    k++;
		    flen++;
			}

			if(flen>8)
			flen=8;

			for(k=0;k<flen;k++)
			printf("%c",t3[k]);
		
      } 	
	        
}
 l:
	return 0;
 } 

