#include<stdio.h>
#include<string.h>
int main()
{
	char data[50], stuff[50];	
	int i, j, count, len;		
	printf("enter the data\n");
	scanf("%s",data);		
	len=strlen(data);	
	count= 0;
    j=0;	
	for(i=0; i<len; i++)	
	{		
		if(data[i]=='1') 
		 count++;			
		else
		 count=0;	
			
		stuff[j]=data[i];	
		j++; 
        if(count==5 && data[i+1]=='1')
		{	
			stuff[j]='0';	
            j++;	
			count=0;          
		}
	}
printf("Stuffed data is : \n 01111110   %s      01111110", stuff);
getch();
return 0;
}

