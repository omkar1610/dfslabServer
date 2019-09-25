#include "justBinaryTree.h"

typedef struct{
	int data;
}DATA;

void printData(void *data)
{
	printf("%d",*(int*)(data) );
}


void display(BTREE *btree)
{
	printf("i\tdata\tleft\tright\n");
	for(int i=0; i<btree->free; i++)
	{		
		printf("%d\t", i);
		NODE *node = (btree->array)[i];
		void *data = node->data;
		btree->printData(data);
		printf("\t%d\t%d\n", node->left, node->right);
	}
}

int main(int argc, char const *argv[])
{
	BTREE btree;
	initTree(&btree, sizeof(DATA), printData);

	DATA d; d.data = 15;
	insert(&btree, &d, 3, 4);
	d.data = 6; insert(&btree, &d, 3, 4);
	display(&btree);

	return 0;
}