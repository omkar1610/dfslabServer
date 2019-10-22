#include <stdio.h>
#include <stdlib.h>
#include <string.h>
static int comp(const void *p1, const void *p2)
{
	int *a = (int *)p1;
	int *b = (int *)p2;
	return *b-*a;
}

int main(int argc, char const *argv[])
{
	int data[argc];

	for (int i = 1; i < argc; i++)
		data[i-1] = atoi(argv[i]);
	
	int tot_num = argc-1;
	
	qsort(data, tot_num, sizeof(int), comp);

	// for (int i = 0; i < tot_num; ++i)
	// 	printf("%d ", data[i]);
	// printf("\n");

	int max_possible_h = tot_num<data[0]?tot_num:data[0];

	int curr_h = 0;
	for (int i = 1; i <= max_possible_h && i <= data[i-1]; ++i);

	printf("%d\n", curr_h);
	return 0;
}