 /*-----------------------------------
Name: P Omkar Ashrit
Roll number: CS1914
Date:9 Aug 2019
Program description: G(N)
Acknowledgements:
------------------------------------*/
#include <stdio.h>



int G(int n)
{
	if(n<=2) return n;
	else return G(n-1)+G(n-2)+G(n-3);
}


int main()
{
	int n,i; scanf("%d",&n);
	if(n<0) {printf("ENTER VALID ENTRY\n"); return 0;}
	for(i=0;i<n;i++)
		printf("%d ", G(i));


	printf("\n");

	int g0 = 0,g1=1,g2=2;
	for(i=0;i<n;i++)
		if(i<=2) printf("%d ", i);
		else 
		{
			int sum = g0+g1+g2;g0=g1;g1=g2;g2=sum;
			printf("%d ", sum);
		}
}
