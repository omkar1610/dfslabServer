/*-----------------------------------
Name: P Omkar Ashrit
Roll number: CS1914
Date:30 July 2019
Program description:Consider ann-digit number.  Square it and add the rightndigits to the leftnorn−1 digits.  If the resultant sum is sameas the original number, then it is called aKaprekarnumber.
Acknowledgements:
------------------------------------*/
#include <stdio.h>

int dig(int n)
{
	int i = 0;
	while(n>0)
	{
		i++;n=n/10;
	}
	return i;
}
int rev(int n)
{
	int tmp = 0;
	while(n>0)
	{
		tmp = tmp*10 +n%10;
		n = n/10;
	}
	return tmp;
}


int kaprekar(int n)
{
	int digit = dig(n);
	int square = n*n;
	int right = 0, left=0;
	while(digit--)
	{
		right = right*10 + square%10;
		square = square/10;
	}
	right = rev(right);
	left = square;
	printf("%d %d %d\n", left, right ,n*n);
	return (left+right == n)?1:0;
}

int main()
{
	int n,i;// scanf("%d",&n);
	for(i=1;i<50;i++)
		if(kaprekar(i))
			printf("\n%d \n", i);
	
}