/*-----------------------------------
Name: P Omkar Ashrit
Roll number: CS1914
Date:2 Aug 2019
Program description:Suppose a set of strings are given as user input.  
					Write aprogram to verify whether the ordering of characters in thelast string preserves the ordering of characters in all thepreceding strings.  
					Note that, conflicts of ordering might existin the preceding strings.
Acknowledgements:
------------------------------------*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int orderComp(int val[], char *str)
{
	int i=2,a=val[str[0]],b=val[str[1]];
	while(i<strlen(str)-1)
	{
		if(!(a != -1 && b != -1 && a<b))
			return 1;
		a = -1==val[str[i]]?a:val[str[i]];
		b = -1==val[str[i+1]]?a:val[str[i+1]];
		i++;
	}
	return 0;
}



int main () 
{
   char *ptr[256];// array of pointers where each pointer points to a string

   char tmpstr[256];//temp string where i will take input and put a pointer to it
   					//before putting a pointer i will malloc those many bytes
   					//
   int j = 0,i,k;
   scanf("%s",tmpstr);
   while(tmpstr[0] != '$')
   {
   		
      	size_t l=strlen(tmpstr);
      	char *x=(char*)malloc(l+1);//used malloc to allocate dynamic memory. l+1 to store "\0".
      	strcpy(x,tmpstr);
      	ptr[j++]=x;
      	scanf("%s",tmpstr);
   }
   int val[256];
   for(i=0;i<256;i++) val[i]=-1;
   int flag = 0;
   for(i=0;i<strlen(ptr[j-1]);i++)
   {
   		val[ptr[0][i]] = flag;flag++;
   }
  
   	for(k=0;k<j-1;k++)
   		if(!orderComp(val,ptr[k]))
   			{printf("NO%d %d",i,k);return 1;}
   	//printf("%s\n", ptr[i]);

   printf("YES");
   return(0);
}