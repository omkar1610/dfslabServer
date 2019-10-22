#include <stdio.h>
#include <stdlib.h>
#define NODE struct node

NODE
{
	int data;
	int bf;
	int Lheight, Rheight;
	NODE *left, *right;
	NODE *parent;
};

NODE *create(int x, NODE *father)
{
	NODE *tmp = (NODE*)malloc(sizeof(NODE));
	tmp->data = x;
	tmp->Lheight = 0;tmp->Rheight =0;
	tmp->left =NULL; tmp->right = NULL;
	tmp->parent = father;
	return tmp;
}

void insertNode(int x, NODE *node)
{
	if(node == NULL)
		node = create(x, NULL);
	else if(node->data<x)
		if(node->left)
			insertNode(x, node->left);
		else
			node->left = create(x, node->left);
	else
		if(node->right)
			insertNode(x, node->right);
		else
			node->right = create(x, node->right);
}

int main()
{
	NODE *root = NULL;
	root = create(5, NULL);
	insertNode(1,root);
	
	printf("NODE %d, Lheight %d, Rheight %d\n", root->data, root->Lheight, root->Rheight);
}
