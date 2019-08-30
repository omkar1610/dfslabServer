/*-----------------------------------
Name: P Omkar Ashrit
Roll number: CS1914
Date:26 July 2019
Program description:A number ispseudoperfectif the sum of all or some of itsproper divisors is equal to the number itself.  
					Write a programto verify whether a given number is pseudoperfect or not.
					This is the recurssive code.
Acknowledgements:
------------------------------------*/
#include<stdio.h>
#include<string.h>

int isSubset(int set[], int n, int sum)
{
	if(sum == 0)
		return 1;
	else if(n==0 && sum >0)
		return 0;
	else
		return isSubset(set,n-1,sum)||isSubset(set,n-1,sum-set[n-1]);
}



int main()
{
	int set[255];
	int n;
	scanf("%d",&n);
	int i, j;
	j = 0;
	for(i=1;i<n;i++)
		if(n%i == 0 )
			set[j++] = i;


	printf("%d\n", isSubset(set,j,n));

}