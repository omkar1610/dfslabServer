#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define EMPTY_NODE -1 
#define CURR_RIGHT btree->array[curr]->right
#define CURR_LEFT btree->array[curr]->left
#define MAX(x,y) ((x)>(y))?(x):(y)
//-----------------------------------------------------------------------------------//
//*****************************Array Implementation**********************************//
//-----------------------------------------------------------------------------------//

typedef struct{
	void *data;
	int left, right, parent;
	int height;
}NODE;

typedef struct{
	int max_ele, free;
	size_t datasize;
	void (*dataPrint)(void *);
	NODE **array;
}BTREE;

void initTree(BTREE *btree, size_t datasize, void (*dataPrint)(void *));

NODE *createNode(BTREE *btree, void *d, int left, int right);

void insert(BTREE *btree, void *d, int left, int right);

void displayTable(BTREE *btree);

void inorder(BTREE *btree, int i);

void preorder(BTREE *btree, int i);

void postorder(BTREE *btree, int i);

void inorder_iterative(BTREE *btree);

void preorder_iteratice(BTREE *btree);

void postorder_iterative(BTREE *btree); //Using 2 stacks

void postorder_iterative_single_stack(BTREE *btree); //Using 1 stack




void initTree(BTREE *btree, size_t datasize, void (*dataPrint)(void *))
{
	btree->dataPrint = dataPrint;
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


void displayTable(BTREE *btree)
{
	printf("i\tdata\tleft\tright\n");
	for(int i=0; i<btree->free; i++)
	{		
		printf("%d\t", i);
		NODE *node = btree->array[i];	
		void *data = node->data;
		btree->dataPrint(data);
		printf("\t%d\t%d\n", node->left, node->right);
	}
}

void inorder(BTREE *btree, int i)
{
	if(i != EMPTY_NODE)
	{
		inorder(btree, btree->array[i]->left);
		btree->dataPrint(btree->array[i]->data);
		inorder(btree, btree->array[i]->right);
	}
}

int update_height(BTREE *btree, int i)
{
	if(i == EMPTY_NODE)
		return 0;
	else if(btree->array[i]->left == EMPTY_NODE && btree->array[i]->right == EMPTY_NODE)
		return 1;
	else
		return 1 + MAX(update_height(btree, btree->array[i]->left), update_height(btree, btree->array[i]->right));

}