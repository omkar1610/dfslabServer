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


void prog1(HEAP *h)
{
	NODE m1, m2, m3;
	NODE *arr = malloc(sizeof(NODE) * h->num_used); 
	
	int i = 0, flag;
	deleteMax(h, &m1); deleteMax(h, &m2); deleteMax(h, &m3);
	//printf("%c(%0.2f) %c(%0.2f) %c(%0.2f)\n", m1.c, m1.value, m2.c, m2.value,m3.c, m3.value);
	if(m1.value == m2.value)
	{		
		if(m2.value == m3.value)//Array of {m1}
		{
			flag = 1;arr[i++] = m1; arr[i++] = m2; arr[i++] = m3;
		}
		else//Array of {m1, m2}  {m3 array}
		{
			flag = 2;arr[i++] = m3;
		}
	}
	else
	{
		if(m2.value == m3.value)//Array of {m1}  {m2, m3 array}
		{
			flag = 3;arr[i++] = m2; arr[i++] = m3;
		}
		else//Array of {m1} {m2}  {m3 array}
		{
			flag = 4;arr[i++] = m3;
		}
	}
	//keep on getting till you get same as m3
	//showArrNODE(h);

	NODE tmp = m3;
	while(h->num_used != 0 && tmp.value == m3.value)
	{
		deleteMax(h, &tmp);
		if(tmp.value == m3.value)
			arr[i++] = tmp;
	}
	insert(h, &tmp);


	//PRINTING THE COMBINATIONS
	//###########################
	if(flag == 1)//1st Case//Array of {m1}
		for(int j = 0; j<i-2;j++)
			for(int k = j+1; k<i-1;k++)
				for(int l = k+1; l<i;l++)
					printf("%c(%0.2f) %c(%0.2f) %c(%0.2f)\n", arr[j].c, arr[j].value, arr[k].c, arr[k].value, arr[l].c, arr[l].value); //nC3
	
	else if(flag == 2)//2nd CaseArray of {m1, m2}  {m3 array}
		for(int j = 0; j<i;j++)
			printf("%c(%0.2f) %c(%0.2f) %c(%0.2f)\n", m1.c, m1.value, m2.c, m2.value, arr[j].c, arr[j].value);
	
	else if(flag == 3)//3rd CaseArray of {m1}  {m2, m3 array}
		for(int k = 0; k<i-1;k++)
			for(int l = k+1; l<i;l++)
				printf("%c(%0.2f) %c(%0.2f) %c(%0.2f)\n", m1.c, m1.value, arr[k].c, arr[k].value, arr[l].c, arr[l].value);
	
	else//4th CaseArray of {m1} {m2}  {m3 array}
		for(int j = 1; j<i;j++)
			printf("%c(%0.2f) %c(%0.2f) %c(%0.2f)\n", m1.c, m1.value, m2.c, m2.value, arr[j].c, arr[j].value);
}


int main()
{
	HEAP heap; HEAP *h = &heap;
	initHeap(h, sizeof(NODE),  compare_node);
	
	NODE node;
	char c, tmp;float x;
	/*node.c = 'u'; node.value = 0.8; insert(h, &node);
	node.c = 'v'; node.value = 0.8; insert(h, &node);
	node.c = 'w'; node.value = 0.5; insert(h, &node);
	node.c = 'x'; node.value = 0.5; insert(h, &node);
	node.c = 'y'; node.value = 0.5; insert(h, &node);
	node.c = 'z'; node.value = 0.5; insert(h, &node);
	node.c = 'a'; node.value = 0.3; insert(h, &node);
	node.c = 'b'; node.value = 0.2; insert(h, &node);
	node.c = 'c'; node.value = 0.1; insert(h, &node);
	prog1(h);*/
	printf("Enter $$ to stop \n");
	
	while(scanf("%c%f%c",&node.c,&node.value,&tmp) == 3 && tmp == '\n')
		insert(h, &node);
	
	prog1(h);
	return 0;
}