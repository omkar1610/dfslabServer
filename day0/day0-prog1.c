/*-----------------------------------
Name: P Omkar Ashrit
Roll number: CS1914
Date:23 July 2019
Program description:Given two positive integers, find their lowest common multiple (LCM)
Acknowledgements:
------------------------------------*/
#include<stdio.h>

int gcd(int m, int n){
	return n==0?m:gcd(n,m%n);
}
void main()
{
 int m, n;
 printf("Enter m n : ");
 scanf("%d%d",&m,&n);
 printf("LCM = %d\n",(m*n)/gcd(m,n));
}
