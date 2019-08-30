/*-----------------------------------
Name: P Omkar Ashrit
Roll number: CS1914
Date:6 Aug 2019
Program description: Header
Acknowledgements:
------------------------------------*/


#include "myhead.h"

void readFile(char *file)
{
    FILE *fp;
   char ch;

   /*  open for writing */
   fp = fopen(file, "r");

   while ((ch = fgetc(fp) )!= EOF)
      printf ("%c", ch);
	
	fclose(fp);
}


int main()
{
	show(2);
 
   readFile("f1.c");
   readFile("f2.c");
   swap_file("f1.c","f2.c");
   readFile("f1.c");
   readFile("f2.c");
   

}