/*-----------------------------------
Name: P Omkar Ashrit
Roll number: CS1914
Date:30 July 2019
Program description:Pattern print
Acknowledgements:
------------------------------------*/
#include <stdio.h>

int main()
{
	int i,j,n;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		for(j=0;j<2*n-1-i;j++)
			printf("%c",(j==i || j == 2*n-2-i)?'*':' ');
		printf("\n");
		
	}
}