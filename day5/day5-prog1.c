 /*-----------------------------------
Name: P Omkar Ashrit
Roll number: CS1914
Date:9 Aug 2019
Program description: Tower of hanoi

Acknowledgements:
------------------------------------*/
#include <stdio.h>


void tower(int n, char A, char B, char C)
{
	if(n == 1)
	{
		printf("%c --> %c\n",A,C);
		return;
	}
	else
	{
		tower(n-1,A,C,B);
		printf("%c --> %c \n", A,C);
		tower(n-1,B,A,C);

	}
}


int main()
{
	int n;
	scanf("%d",&n);
	tower(n,'A','B','C');
}