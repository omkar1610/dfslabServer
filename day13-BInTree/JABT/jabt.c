#include "justBinaryTree.h"
#include "stack.h"

typedef struct{
	int data;
}DATA;

void dataPrint(void *data)
{
	printf("%d ",*(int*)(data) );
}



int main(int argc, char const *argv[])
{
	BTREE btree; 
	DATA d; 
	initTree(&btree, sizeof(DATA), dataPrint);


	d.data = 60; insert(&btree, &d, 1, 2);
	d.data = 50; insert(&btree, &d, 3, 4);
	d.data = 70; insert(&btree, &d, -1, 5);
	d.data = 45; insert(&btree, &d, -1, -1);
	d.data = 55; insert(&btree, &d, -1, -1);
	d.data = 75; insert(&btree, &d, -1, -1);

	displayTable(&btree);
	preorder(&btree, 0);printf("\n");
	preorder_iteratice(&btree);printf("\n");
	printf("\n");
	inorder(&btree, 0);printf("\n");
	inorder_iterative(&btree);printf("\n");
	printf("\n");
	postorder(&btree, 0);printf("\n");
	postorder_iterative(&btree);printf("\n");
	printf("\n");
	postorder_iterative_single_stack(&btree);printf("\n");
	return 0;
}