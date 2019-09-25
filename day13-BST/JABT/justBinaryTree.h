#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define EMPTY_NODE -1 


//-----------------------------------------------------------------------------------//
//*****************************Array Implementation**********************************//
//-----------------------------------------------------------------------------------//

typedef struct{
	void *data;
	int left, right, parent;
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
