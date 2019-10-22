#include "newbst.h"

typedef struct{

	int key;
}DATA;

DATA *create_data(int x)
{
	DATA *tmp = malloc(sizeof(DATA));
	tmp->key = x;
	return tmp;
}

int comparator(void *d1, void *d2)
{
	int n1 = ((DATA *)(d1))->key;
	int n2 = ((DATA *)(d2))->key;
	return n1-n2;
}



void printData(void *d, void *parent_data)
{
	int data = ((DATA *)(d))->key;
	int parent = ((DATA *)(parent_data))->key;
	printf("%d(%d) ",data, parent);
}

size_t element_size = sizeof(DATA);




int main()
{
	NODE *root = NULL;
	
	insertMain(&root, create_data(5));
	insertMain(&root, create_data(12));
	insertMain(&root, create_data(9));
	insertMain(&root, create_data(4));
	insertMain(&root, create_data(3));
	insertMain(&root, create_data(16));
	insertMain(&root, create_data(14));
	insertMain(&root, create_data(13));
	insertMain(&root, create_data(8));
	insertMain(&root, create_data(18));
	
	inorder(root);printf("\n");

	Delete(root, create_data(12));
	inorder(root);printf("\n");

	printLevelOrder(root);

	return 0;
}