#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define MAX_NODES tree->max_nodes
#define ROOT tree->root
#define NODELIST tree->nodelist

int glob_ptr;

typedef struct node {
    int data, left, right;
} NODE;

typedef struct {
    unsigned int max_nodes;
    int root;
    NODE *nodelist;
} TREE;


void initFromFile(TREE *tree, const char *file)
{
	FILE *fp;
	char *line = NULL;
	size_t len = 0, read;
	int i, loc = 0;

	fp = fopen(file, "r");
	if (fp == NULL)
	   exit(EXIT_FAILURE);

	read = getline(&line, &len, fp);
	int tot_line = atoi(line);

	MAX_NODES = tot_line;
	ROOT = 0; 
	NODELIST = malloc(tot_line * sizeof(NODE));

	for (int i = 0; i < tot_line; ++i)
	{
		read = getline(&line, &len, fp);
		// printf("LINE : ~%s$\nTokens : \n", line);
		NODELIST[i].data = atoi(strtok(line, " "));
		NODELIST[i].left = atoi(strtok(NULL, " "));
		NODELIST[i].right = atoi(strtok(NULL, " \n"));
	}
	fclose(fp);
}

void showTable(TREE *tree)
{
	for (int i = 0; i < MAX_NODES; ++i)
		printf("%d %d %d\n",NODELIST[i].data, NODELIST[i].left, NODELIST[i].right);
}

void inorder_(TREE *tree, int key, int *inorder_data) //Traverse and store the result in the array
{
	if(key != -1)
	{
		inorder_(tree, NODELIST[key].left, inorder_data);
		inorder_data[glob_ptr++] = NODELIST[key].data;
		inorder_(tree, NODELIST[key].right, inorder_data);
	}
}

void inorder(TREE *tree, int key, int *inorder_data)
{
	glob_ptr = 0;
	inorder_(tree, key, inorder_data);
}



void update_(TREE *tree, int key, int *inorder_data) // Change the tree appropriately comparting with the inorder output
{
	if(key != -1)
	{
		update_(tree, NODELIST[key].left, inorder_data);
		update_(tree, NODELIST[key].right, inorder_data);
		NODELIST[key].data = inorder_data[glob_ptr++];
	}
}

void update(TREE *tree, int key, int *inorder_data)
{
	glob_ptr = 0;
	update_(tree, key, inorder_data);
}