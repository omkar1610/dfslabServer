 /*-----------------------------------
Name: P Omkar Ashrit
Roll number: CS1914
Date:9 Aug 2019
Program description: 
Acknowledgements:
------------------------------------*/

#include <stdio.h>


int f(int n)
{
	int s = 0;
	while(n--) s += 1+f(n);
	return s;
}

int f1(int n)
{
	if(n==0) return 0;
	return 2*f(n-1)+1;
}


int main()
{
	int i,n;scanf("%d",&n);
	for(i = 0; i<n;i++)
		printf("%d %d\n", f(i), f1(i));
}


// FUNC RETURNS f(n) = 2f(n-1)+1, 0 if n = 0