#include <stdio.h>
#include <stdlib.h>
#include "common.h"

#ifndef BT_H
#define BT_H


typedef int DATA;

typedef struct
{
	DATA data;
	int left, right, parent;
}BT_NODE;

typedef struct
{
	unsigned int num_nodes, max_nodes;
    int root, free_list;
    BT_NODE *nodelist;
}BT_TREE;

int init_btree(BT_TREE *tree) {
    int i;

    tree->num_nodes = 0;
    tree->max_nodes = 20;
    if (NULL == (tree->nodelist = Malloc(tree->max_nodes, BT_NODE))) ERR_MESG("init_tree: out of memory");
    
    tree->root = -1;
    tree->free_list = 0;
    
    tree->nodelist[0].parent = -1;
    for (i = 1; i < tree->max_nodes; i++) {
        tree->nodelist[i-1].left = i;
        tree->nodelist[i-1].right = -1;
        tree->nodelist[i].parent = i-1;
    }
    tree->nodelist[i-1].left = -1;
    return 0;
}








#endif