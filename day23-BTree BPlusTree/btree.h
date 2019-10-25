#include <stdio.h>
#include <stdlib.h>

#define int DATA;
// #define order 5
// #define k 5
#define MAX_ELE tree->max_ele
#define NUM_ELE tree->num_ele
#define ORDER tree->order
#define NODELIST tree->nodelist
#define DATALIST tree->datalist


typedef struct{
	DATA *d;//[order - 1];
	int *link;//[order];
	int parent;
}NON_LEAFNODE;

typedef struct{
	DATA *d;//[k];
	int parent;
}LEAFNODE;

typedef struct{
	int num_ele, max_ele;
	int order, k;
	NON_LEAFNODE *nodelist;
	LEAFNODE *datalist;

}BTREE;



void init_nonleaf(BTREE *tree, NON_LEAFNODE *nl)
{
	nl->d = malloc((ORDER - 1)* sizeof(DATA));
	nl->link = malloc(ORDER * sizeof(int));
}


void init(BTREE *tree, int order, int k)
{
	NUM_ELE = 0;
	MAX_ELE = 1000;
	ORDER = order; tree->k = k;
	NODELIST = malloc(MAX_ELE * sizeof(NON_LEAFNODE));
	for (int i = 0; i < MAX_ELE; ++i) 
		init_nonleaf(tree, NODELIST[i]);
	
	DATALIST = malloc(MAX_ELE * sizeof(LEAFNODE));
	for (int i = 0; i < MAX_ELE; ++i)
	{
		DATALIST[i].d = malloc(tree->k * sizeof(DATA));
	}
}
