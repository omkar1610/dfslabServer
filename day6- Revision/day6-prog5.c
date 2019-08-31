#include <stdio.h>
#include <math.h>


int main()
{
	int n; scanf("%d",&n);
	int last = (sqrt(8*n+1) -1)/2;
	int remain = n - (last * (last +1)/2);
	//printf("LAST %d REMAIN %d sum %d\n", last, remain, last+2);
	int i;
	if(remain == 0)
	{
		printf("1%d/%d\n", i = last%2?1:last,last-i);
	}
	if(last%2)
		printf("2%d/%d\n", remain,last+2-remain);
	else
		printf("3%d/%d\n", last-remain, remain+2);
}