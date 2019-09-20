#include <stdio.h>
#include <stdlib.h>
#define MAX(x,y) ((x)>(y)?(x):(y))

typedef struct{
	int key;
}DATA;


typedef struct treeNode{
	DATA d;
	struct treeNode *leftChild, *rightChild;
	struct treeNode *parent; // This is optional
}NODE;

void addNode(NODE *head, NODE *data)
{
	if(head == NULL)
	{
		head = data;
	}
	else
	{
		;
	}
}




int main(int argc, char const *argv[])
{
	NODE *head = NULL;

	NODE tmp;
	tmp.d.key = 56;
	tmp.leftChild = NULL;
	tmp.rightChild = NULL;
	tmp.parent = NULL; 

	addNode(head, &tmp);
	
	printf("%d\n", head==NULL?1:head->d.key);

	return 0;
}