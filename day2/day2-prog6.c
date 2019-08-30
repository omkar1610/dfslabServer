/*-----------------------------------
Name: P Omkar Ashrit
Roll number: CS1914
Date:30 July 2019
Program description:Letmandnbe 32-bit unsigned integers.  Use bitwiseoperations to assign tomthe following functions ofn:
					1 ifnis odd, 0 ifnis even.
					1 ifnis divisible by 4, 0 otherwise.
					2n(Assume thatn<= 31).
					nrotated bykpositions to the left for some integerk>= 0.
					nrotated bykpositions to the right for some integerk>= 0
Acknowledgements:
------------------------------------*/
#include<stdio.h>


void leftrot(unsigned int n,int k)
{
	int bits = 32;
	while(k--)
	{
		int msb = n>>bits-1;// Get most sig bit
		n = n<<1;//left shift
		n = n|msb;//put msb at last
	}
	printf("%u\n", n);
}

void rightrot(unsigned int n,int k)
{
	int bits = 32;
	while(k--)
	{
		int lsb = n&1;//get lsb
		n = n>>1;
		lsb = lsb<<bits-1;
		n = n|lsb;//put at first
	}
	printf("%u\n", n);
}
int main()
{
	unsigned int n; scanf("%u",&n);
	printf("%u\n", n&1); // Even or odd and with 1
	printf("%u\n", n&3); // Even or odd and with 3
	printf("%u\n", n<<1); // 2n means left shift
	int bits = 32;
	int k = 2;
	leftrot(n,k);
	rightrot(n,k);


}