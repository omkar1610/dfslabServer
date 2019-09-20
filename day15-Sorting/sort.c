#include "sort.h"


static int compare_Int(void *array, int i1, int i2)
{
	int n1 = *((int *) array + i1);
	int n2 = *((int *) array + i2);
	return (n1 - n2);
}



int main()
{
	int a[8] = {0, 4,6,7,5,9,3,8};
	int n = 8;
	
	//insertionSort(a, n, sizeof(int), compare_Int);
	//bubbleSort(a, n, sizeof(int), compare_Int);
	//heapSort(a, n, sizeof(int), compare_Int);
	msort(a, 1, 7, compare_Int, sizeof(int));

	for(int i = 1; i<n; i++)
		printf("%d ", a[i]);
}