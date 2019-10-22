#include "binary.h"

void Basic()
{
	NODE *root = NULL;
	insert(20,&root);
	insert(13,&root);insert(24,&root);insert(5,&root);
	insert(16,&root);insert(21,&root);insert(3,&root);
	
	//inorder(root); printf("\n");
	
	printf("MIN %d\n", minEle(root));
	printf("Height %d\n", maxHeight(root));
	
	printLevelOrder(root);

	freeMem(root);
}

void FirstProg()
{
	int n = 8;
	NODE *boxes[8], *root = NULL;
	for(int i=0;i<n;i++)
		boxes[i] = create(i,NULL);
	int data[8] = {-1, 0, 0, 1, 2, 2, 4, 4};
	for(int i=0;i<n;i++)
	{	
		if(data[i]!= -1) 
			{
				int par = data[i];
				boxes[i]->parent = boxes[par];
				if(boxes[par]->leftChild == NULL)
					boxes[par]->leftChild = boxes[i];
				else
					boxes[par]->rightChild = boxes[i];
			}
		else 
			root = boxes[i];
	}

	printf("Height %d\n", maxHeight(root));
	
	printLevelOrder(root);
	freeMem(root);
}



int main(int argc, char const *argv[])
{
	Basic();

	FirstProg();
	return 0;
}


