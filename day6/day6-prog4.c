#include <stdio.h>

int sum(int n)
{
	return n<10?n:(n%10)+sum(n/10);
}

int super(int n)
{
	return n<10?n:super(sum(n));
}

int main()
{
	printf("%d\n", super(9875));
}