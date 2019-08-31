/*-----------------------------------
Name: P Omkar Ashrit
Roll number: CS1914
Date:30 July 2019
Program description: Ann-digit number isSPECIALif the addition of its sum of thedigits and the product of its digits equals to the originalnumber.  E.g., 19 is aSPECIAL2-digit number.  
					Write aprogram to verify whether a given number isSPECIALor not.Extend this program to verify whether there exists anySPECIALnumber for a given value of number of digitsn.
Acknowledgements:
------------------------------------*/
#include <stdio.h>

int isNice(int n)
{
	int sum=0, prod=1;
	int p = n;
	while(n>0)
	{
		sum += n%10;
		prod *= n%10;
		n = n/10;
	}
	return sum + prod == p?1:0;
}


int main()
{
	int n, i;
	scanf("%d",&n);
	for(i = 1; i<800;i++)
		if(isNice(i))
			printf("%d ", i);

	return 0;
}