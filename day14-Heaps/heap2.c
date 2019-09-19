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



void prog2(HEAP *h)
{
	//Take Input
	int k = 3, j;
	char ***ptr = malloc(k*sizeof(char **));//Array of lists containg 
											//list of strings
	for(int i = 0; i<k; i++)
	{
		ptr[i]  = malloc(1*sizeof(char *)); j = 0;
	
		scanf("%m[^\n]",&ptr[i][j]);
	
		char *tmp = strtok(ptr[i][j], " ");
		j++;
		while(NULL != (tmp = strtok(NULL, " ")))
		{
			ptr[i]  = realloc(ptr[i], (j+1)*sizeof(char *)); 
			ptr[i][j++] = tmp;//printf("%s\n", tmp);
		}
		ptr[i]  = realloc(ptr[i], (j+1)*sizeof(char *)); 
		ptr[i][j] = NULL;
        getchar();//To eat last new line
	}

	node2d n2d;
	
	int *result = malloc(50*sizeof(int));int r_loc = 0;

	for(int i = 0; i<k ; i++)
		{
			n2d.x = i;n2d.y = 1; n2d.value = ptr[i][1];
			insert(h, &n2d);
		}
	showArrStr(h);

	
	while(h->num_used >0)
	{
		deleteMax(h, &n2d);
		//showArrStr(h);
		result[r_loc++] = atoi(n2d.value);
		if(ptr[n2d.x][++n2d.y]!=NULL) 
		{
			n2d.value = ptr[n2d.x][n2d.y];
			insert(h, &n2d);
		}
		//showArrStr(h);
	}
	for(int i = 0; i<r_loc;i++)
		printf("%d ",result[i] );
}


int main()
{
	HEAP heap; HEAP *h = &heap;
	initHeap(h, sizeof(node2d),  compare_str_int);
	prog2(h);
	
	return 0;
}