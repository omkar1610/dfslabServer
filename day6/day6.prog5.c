#include <stdio.h>
#include <math.h>


int main()
{
	int n; scanf("%d",&n);
	int last = (sqrt(8*n+1) -1)/2;
	printf("%d\n", last);
}