#include <stdio.h>
#include <stdlib.h>

#define TOT_ELE ll->tot_ele
#define NUM_ELE ll->num_ele
#define HEAD ll->head
#define TAIL ll->tail
#define FREE ll->free
#define ELEMENT ll->elements

#define getdata(x) ll->elements[(x)].data
#define getnext(x) ll->elements[(x)].next

#define DATA int

typedef struct
{
	DATA data;
	int next;
}NODE;

typedef struct
{
	int tot_ele, num_ele;
	int head, tail, free;
	NODE *elements;
}LL;


void init(LL *ll, int tot_ele);//Initialize linked list of total elements = tot_ele
void showll(LL *ll);	//Show the list
void showComplete(LL *ll);	//Show the complete list with DATA and FREE positions
void insert(LL *ll, DATA x);
void delete_data(LL *ll, DATA x);