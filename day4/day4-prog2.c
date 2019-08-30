/*-----------------------------------
Name: P Omkar Ashrit
Roll number: CS1914
Date:6 Aug 2019
Program description: Password(MAsking not done)
Acknowledgements:
------------------------------------*/
#include<stdio.h>
#include <math.h>
#include <string.h>
int isPrime(int n)//zero returns 1
{
	if(n==0) return 1;
	if(n<2) return 0;
	int i, flag = 0;
	for(i=2;i<=sqrt(n);i++)
		if(n%i == 0)
			return 0;
	return 1;
}



int strength(char *str)
{
	int i = 0, lc=0, uc=0, dig=0, spec =0;
	char ch;
	while((ch=str[i++]) != '\0')
		{
			if(ch>='a' && ch<='z') lc++;
			else if(ch>='A' && ch <='Z') uc++;
			else if(ch>='0' && ch <='9') dig++;
			else spec++;
			//printf("%d %d %d %d \n",lc,uc,dig,spec );
		}
	//printf("%d %d %d %d \n",lc,uc,dig,spec );
	if(isPrime(lc) && isPrime(uc) && isPrime(dig) && isPrime(spec))
		return 1;
	else
		return 0;

}

int main()
{
	char str[255];
	scanf("%s",str);
	printf("%d",strength(str));
	return 0;
}