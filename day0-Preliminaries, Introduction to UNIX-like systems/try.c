#include<stdio.h>

int gcd(int m, int n)
{
	if(n==0)
		return m;
	else
		return gcd(n,m%n);
}
void main()
{
 int n = 2;
 printf("LCM = %d\n",n==1?1:2);
}
