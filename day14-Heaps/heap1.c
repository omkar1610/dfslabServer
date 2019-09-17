#include "heap.h"

/*
typedef struct
{
	size_t element_size; // Generic implementation 
	unsigned int num_allocated, num_used; // Keep track of the size
	void *array; // Using one-based indexing
	int (*comparator)(void *, int, int); // Returns -ve, 0, or +ve
}HEAP;

void initHeap(HEAP *h, size_t element_size,int (*comparator)(void *, int, int))

void swap(HEAP *h, int i, int j)

static void swapUp(HEAP *h, int k)

void insert(HEAP *h, void *x)

static void swapDown(HEAP *h, int k)

void deleteMax(HEAP *h, void *max)

static int compare_int(void *array, int i1, int i2)
*/

void showArrInt(HEAP *h)
{
	printf("HEAP : ");
	for(int i = 1; i<=h->num_used;i++)
	{
		int *ele = (int*)(h->array + i * h->element_size);
		printf("%d ", *ele);
	}
	printf("\n");
}

void showArrFloat(HEAP *h)
{
	printf("HEAP : ");
	for(int i = 1; i<=h->num_used;i++)
	{
		float *ele = (float*)(h->array + i * h->element_size);
		printf("%0.2f ", *ele);
	}
	printf("\n");
}

void prog1(HEAP *h)
{
	float m1, m2, m3;

	float *arr = malloc(sizeof(int) * h->num_used); int i;
	deleteMax(h, &m1);
	deleteMax(h, &m2);
	deleteMax(h, &m3);
	if(m1 == m2)
	{		
		if(m2 == m3)
		{
			printf("h1\n");
			//Array of {m1}
			i = 0;
			arr[i++] = m1;
			arr[i++] = m2;
			arr[i++] = m3;
		}
		else if(m2 != m3)
		{
			printf("h2\n");
			//Array of {m1, m2}  {m3 array}
			i = 0;
			arr[i++] = m3;
		}
	}
	else if(m1 != m2)
	{
		if(m2 == m3)
		{
			printf("h3\n");
			//Array of {m1}  {m2, m3 array}
			i = 0;
			arr[i++] = m2;
			arr[i++] = m3;
		}
		else if(m2 != m3)
		{
			printf("h4\n");
			//Array of {m1} {m2}  {m3 array}
			i = 0;
			arr[i++] = m3;
		}
	}
	//keep on getting till you get same as m3
	showArrFloat(h);

	float tmp = m3;
	while(tmp == m3)
	{
		deleteMax(h, &tmp);
		if(tmp == m3)
			arr[i++] = tmp;
	}
	insert(h, &tmp);
	for(int J = 0; J<i;J++)
		printf("%0.2f",arr[J] );printf("\n");

}


int main()
{
	HEAP heap; HEAP *h = &heap;
	initHeap(h, sizeof(float),  compare_float);
	
	float x = 0.5; insert(h, &x);
	x = 0.3; insert(h, &x);
	x = 0.3; insert(h, &x);
	x = 0.1; insert(h, &x);
	x = 0.8; insert(h, &x);
	x = 0.2; insert(h, &x);
	x = 0.3; insert(h, &x);
	showArrFloat(h);
	prog1(h);
	showArrFloat(h);

	return 0;
}