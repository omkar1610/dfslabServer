#include "justBinaryTree.h"

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

void preorder(BTREE *btree, int i)
{
	if(i != EMPTY_NODE)
	{
		btree->dataPrint(btree->array[i]->data);
		preorder(btree, btree->array[i]->left);
		preorder(btree, btree->array[i]->right);
	}
}

void postorder(BTREE *btree, int i)
{
	if(i != EMPTY_NODE)
	{
		postorder(btree, btree->array[i]->left);
		postorder(btree, btree->array[i]->right);
		btree->dataPrint(btree->array[i]->data);
	}
}





