/*-----------------------------------
Name: P Omkar Ashrit
Roll number: CS1914
Date:30 July 2019
Program description:Given a positive integernas user input, find out the numberof trailing zeros in n!
Acknowledgements:
------------------------------------*/
#include <stdio.h>

int main()
{
	int n;scanf("%d",&n);
	int sum = 0; int den = 5;
	while(n>den)
	{
		sum = sum + n/den;
		den *= 5;
	}

	printf("%d\n", sum);
}