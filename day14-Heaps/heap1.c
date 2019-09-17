#include <stdio.h>
#include <stdlib.h>
#include "common.h"


typedef struct
{
	size_t element_size; // Generic implementation 
	unsigned int num_allocated, num_used; // Keep track of the size
	void *array; // Using one-based indexing
	int (*comparator)(void *, int, int); // Returns -ve, 0, or +ve
}HEAP;

void initHeap(HEAP *h, size_t element_size,int (*comparator)(void *, int, int))
{ 
	h->element_size = element_size;// Allocated size
	h->num_allocated = 10;// Current size
	h->num_used = 0;
	if(NULL == (h->array = Malloc(h->num_allocated, element_size)))
		{
			ERR_MSG("initHeap: Out of memory");
			exit(-1);
		}
	h->comparator = comparator;
	return;
}


void swap(HEAP *h, int i, int j)
{
	// h->array[0] used as swapping variable in one-based indexing
	char *ip = (char *) h->array + i * h->element_size;
	char *jp = (char *) h->array + j * h->element_size;
	char *tp = (char *) h->array;
	// Memory to memory copy of the elements for swapping
	memcpy((void *) tp, (void *) ip, h->element_size);
	memcpy((void *) ip, (void *) jp, h->element_size);
	memcpy((void *) jp, (void *) tp, h->element_size);
	return;
}


static void swapUp(HEAP *h, int k)
{
	// Repeat until the parent is not the root
	while (k > 1 && (h->comparator(h->array, k/2, k) < 0))
	{
		// Swap child at position k with the parent
		swap(h, k, k/2);
		// Move up to the parent level
		k = k/2;
	}
	return;
}

void insert(HEAP *h, void *x)
{
	// Make sure there is space for another element
	if(h->num_used + 1 == h->num_allocated)
	{
		h->num_allocated *= 2;
		if(NULL == (h->array = realloc(h->array,h->num_allocated * h->element_size)))
		{ 
			ERR_MSG("insert: Out of memory");
			exit(-1);
		}
	}
	// Insert element at the end
	h->num_used++;
	//memcpy((char *) h->array + h->num_used * h->element_size,x, h->element_size); //memcpy(to, from , size) // Remove cxhAR FROM HERE
	memcpy(h->array + h->num_used * h->element_size, x, h->element_size); //memcpy(to, from , size) // Remove cxhAR FROM HERE

	// Restore the heap property (max-heap)
	swapUp(h, h->num_used);
	return;
}


static void swapDown(HEAP *h, int k)
{
	// Repeat until the left child (2k) is within the boundary
	while (2*k <= h->num_used)
	{
		int j = 2*k; // Left child (2k)
		// Choose the child with larger key
		if(j < h->num_used && (h->comparator(h->array, j, j+1) < 0))
			j++; 
		// Right child (larger key is at 2k+1)
		if(h->comparator(h->array, k, j) >= 0) // No swapping needed
			break;
		// Swap parent at position k with the largest child
		swap(h, k, j);k = j;
	}
	return;
}

void deleteMax(HEAP *h, void *max)
{
	// Max is at the root (index 1)
	memcpy(max, h->array + h->element_size, h->element_size);
	// Copy last element to root
	memcpy(h->array + h->element_size, h->array + h->num_used *h->element_size, h->element_size); 
	h->num_used--;
	// Restore the heap property (max-heap)
	swapDown(h, 1);
	return;
}


static int compare_int(void *array, int i1, int i2)
{
	// Pick up the element at index i1
	int n1 = *((int *) array + i1);
	// Pick up the element at index i2
	int n2 = *((int *) array + i2);
	return (n1 - n2);
}