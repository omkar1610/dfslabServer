#include <stdio.h>
#include <stdlib.h>

int compare(const void *d, const void *d1)
{
	int n1 = *(int *)d, n2 = *(int *)d1;
	return n1-n2;
}

int main(int argc, char const *argv[])
{
	int a[] = {5,7,1,9,6,1,3};
	qsort(a, 7, sizeof(int), compare);
	for(int i = 0; i<7; i++)
		printf("%d\n", a[i]);
	return 0;
}