#include <stdio.h>

void SWAP(int *a, int i, int j)
{
	int tmp = a[i];
	a[i] = a[j];
	a[j]=tmp;
}

void permut(int *a, int start, int n)
{
	int i;
	if(start == n)
	{
		for(i=0;i<n;i++)
			printf("%d ", a[i]);
		printf("\n");
		return;
	}
	for(i=start;i<n;i++)
		{
			SWAP(a,i,start);
			permut(a,start+1,n);
			SWAP(a,start,i);
		}
}


int main()
{
	int a[] = {1,2,3};
	permut(a,0,3);
}