/*-----------------------------------
Name: P Omkar Ashrit
Roll number: CS1914
Date:6 Aug 2019
Program description: No of Macros
Acknowledgements:
------------------------------------*/
#include<stdio.h>


int main()
{
	FILE *fp;
	char ch;

	fp = fopen("data.txt", "r");

   	if (fp == NULL) return 0;

   	int count = 0;
   	char str[20];


   	while ((ch = fgetc(fp) )!= EOF)
	{
		//printf ("%c", ch);
		if(ch == '#')
		{

			while((ch = fgetc(fp) ) != EOF && ((ch != '{') && (ch != '\n'))) ;
				//printf("%c~", ch);
			//printf("21%c~", ch);
			if(ch == '\n') count++;//printf("\nGOT A LINE %d\n",count);
			else if(ch == '{')
			{
				while((ch = fgetc(fp) ) != EOF && (ch != '}'))
					{
						//printf ("%c", ch);
						if(ch == '\n') 
							count++;//printf("\nGOT A LINE %d\n",count);
					}
				if(ch == '}') count++;
			}
		}
    }
    printf("COUNT %d\n", count);
   	fclose(fp);
	return 0;
}