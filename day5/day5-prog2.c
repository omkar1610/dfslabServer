 /*-----------------------------------
Name: P Omkar Ashrit
Roll number: CS1914
Date:9 Aug 2019
Program description: nCr

Acknowledgements:
------------------------------------*/
#include <stdio.h>


int C(int n, int r)
{	

	if(n<r) return 0;
	if(r==0 || n==r || n==1) return 1;
	return C(n-1,r)+C(n-1,r-1);
}


int main()
{
	int n,r;
	scanf("%d%d",&n,&r);
	if(n<1 || n<r) {printf("INVALID ENTRY"); return 0;} 
	printf("%d\n", C(n,r));
	
}