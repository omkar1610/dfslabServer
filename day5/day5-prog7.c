 /*-----------------------------------
Name: P Omkar Ashrit
Roll number: CS1914
Date:9 Aug 2019
Program description: n-d pass
Acknowledgements:
------------------------------------*/
#include <stdio.h>

int f(int n, int k)
{
	if(n==1)
		return 2*k+1;
	if(k==0)
		return 1;

	else
	{
		int i, sum = 0;
		for(i=k-1;i>=0;i--)
			sum += 2*f(n-1,i);
		return sum + f(n-1,k);
	}
}

int main()
{
	int n,k;scanf("%d%d",&n,&k);
	printf("%d\n", f(n,k));
}