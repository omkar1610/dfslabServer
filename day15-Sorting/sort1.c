#include "heap.h"

int main()
{
	HEAP heap; HEAP *h = &heap;
	initHeap(h, sizeof(int),  compare_int);
	int x;
	x = 2; insert(h, &x);
	x = 23; insert(h, &x);
	x = 12; insert(h, &x);
	x = 41; insert(h, &x);
	x = 20; insert(h, &x);
	x = 35; insert(h, &x);
	x = 15; insert(h, &x);
	x = 22; insert(h, &x);
	showArrInt(h);
	
	x = h->num_used; //Store it to print later
	while(h->num_used >1) // Keep on extracting the max till there is no other element and keep the max at last
		extractMax(h);

	showFullArrInt(h, x);
	
	return 0;
}