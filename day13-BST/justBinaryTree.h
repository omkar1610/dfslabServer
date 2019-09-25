#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
	void *data;
	int left, right, parent;
}NODE;

typedef struct{
	int max_ele, free;
	size_t datasize;
	void (*printData)(void *);
	NODE **array;
}BTREE;

void initTree(BTREE *btree, size_t datasize, void (*printData)(void *))
{
	btree->printData = printData;
	btree->max_ele = 10;
	btree->free = 0;
	btree->datasize = datasize;
	btree->array = malloc(btree->max_ele * sizeof(NODE *));
}

NODE *createNode(BTREE *btree, void *d, int left, int right)
{
	NODE *tmp = malloc(sizeof(NODE));
	
	tmp->data = malloc(btree->datasize);
	memcpy(tmp->data, d, btree->datasize);

	tmp->left = left; tmp->right = right;
	return tmp;
}

void insert(BTREE *btree, void *d, int left, int right)
{
	if(btree->free == btree->max_ele - 1)
	{
		btree->max_ele *= 2;
		btree->array = realloc(btree->array, btree->max_ele * sizeof(NODE *));
	}
	btree->array[btree->free] = createNode(btree, d, left, right);
	btree->free++;
}