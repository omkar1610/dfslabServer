#include <stdio.h>
#include <stdlib.h>
#include "common.h"

#ifndef BT_H
#define BT_H

#define ROOT tree->root
#define FREE tree->free
#define NUM_ELE tree->num_ele
#define MAX_ELE tree->max_ele
#define NL tree->nodelist

typedef int DATA;

typedef struct
{
	DATA data;
	int left, right, parent;
}BT_NODE;

typedef struct
{
	unsigned int num_ele, max_ele;
    int root, free;
    BT_NODE *nodelist;
}BT_TREE;

void init_btree(BT_TREE *tree) 
{
    int i;

    NUM_ELE = 0;
    MAX_ELE = 5;
    NL = Malloc(MAX_ELE, BT_NODE);    
    ROOT = -1;
    FREE = 0;
    
    for (i = 0; i < MAX_ELE; i++) {
        NL[i].left = i+1;
        NL[i].right = -1;
    }
    NL[i-1].left = -1;
}

void display(BT_TREE *tree)
{
    printf("TREE\n");
    for (int i = 0; i < MAX_ELE; ++i)
        printf("%d %d %d %d\n", i, NL[i].data, NL[i].left, NL[i].right);
    // printf("FREE\n");
    // for (int i = FREE; i != -1  ; i = NL[i].left)
    // {
    //     printf("%d %d %d %d\n", i, NL[i].data, NL[i].left, NL[i].right);
    // }
}

void __insert(BT_TREE *tree, int node, int key)
{
    //node is not -1 since we are starting with at least one element
    if(key<=NL[node].data)
    {
        if(NL[node].left == -1)
        {
            NL[node].left = FREE;
            FREE = NL[FREE].left;

            int left = NL[node].left;
            NL[left].data = key;
            NL[left].left = -1;
            NUM_ELE++;
        }
        else
            __insert(tree, NL[node].left, key);
    }
    else
    {
        if(NL[node].right == -1)
        {
            NL[node].right = FREE;
            FREE = NL[FREE].left;

            int right = NL[node].right;
            NL[right].data = key;
            NL[right].left = -1;
            NUM_ELE++;

        }
        else
            __insert(tree, NL[node].right, key);
    }
}



void insert(BT_TREE *tree, int key)
{
    if(ROOT == -1) //Empty Tree
    {
        ROOT = FREE;
        FREE = NL[FREE].left;

        NL[ROOT].data = key;
        NL[ROOT].left = -1;
        NUM_ELE++;
    }
    else
    {
        //If full tree then reallocate and then recurse
        if(FREE == -1)
        {
            int i;
            FREE = MAX_ELE;
            MAX_ELE *= 2;
            NL = realloc(NL, MAX_ELE * sizeof(BT_NODE));
            for (i = FREE; i < MAX_ELE; ++i)
            {
                NL[i].left = i+1;
                NL[i].right = -1;
            }
            NL[i-1].left = -1;
        }
        __insert(tree, ROOT, key); //Recursive function
    }
}

int __search(BT_TREE *tree, int node, int key)
{
    // -1 if not found
    if(node != -1)
    {
        if(NL[node].data == key)
            return node;
        else if(NL[node].data > key)
            __search(tree, NL[node].left,key);
        else
           __search(tree, NL[node].right, key);
   }
   else
    return -1;
}

int search(BT_TREE *tree, int key)
{
 
    return __search(tree, ROOT, key);
}

int __parent_search(BT_TREE *tree, int node, int key)
{
    //Search if node is the parent of the node containing key
    if(node != -1)
    {
        if(key <= NL[node].data)
        {
            //go left
            int left = NL[node].left;
            if(left == -1)
                return -2;
            else if(NL[left].data == key)
                return node;
            else
                return __parent_search(tree, left, key);
        }
        else
        {
            //go right 
            int right = NL[node].right;
            if(right == -1)
                return -2;
            else if(NL[right].data == key)
                return node;
            else
                return __parent_search(tree, right, key);
        }
    }
    else
        return -2;
}

int parent_search(BT_TREE *tree, int key)
{
    //returns -2 if not found the key, -1 if the root has the key, else the index of the parent
    if(ROOT == -1)
        return -2;
    else if(NL[ROOT].data == key)
        return -1;
    else
        return __parent_search(tree, ROOT, key);
}

int __child_no(BT_TREE *tree, int node)
{
    //Get how many children for delete purpose
    int left = NL[node].left, right = NL[node].right;
    if(left+right == -2)
        return 0;
    else
        if(left == -1 || right == -1)
            return 1;
        else 
            return 2;
}


void __delete_leaf(BT_TREE *tree, int parent, int node)
{
    //left child    
    if(NL[parent].left == node)
        NL[parent].left = -1;
    //right child
    else
        NL[parent].right = -1;

    NL[node].left = FREE; NL[node].data = 0;//Changing data is not needed
    FREE = node;
}

void __delete_single_child(BT_TREE *tree, int parent, int node)
{
    int tmp = NL[node].left!=-1?NL[node].left:NL[node].right;
    //left child    
    if(NL[parent].left == node)
        NL[parent].left = tmp;
    //right child
    else
        NL[parent].right = tmp;

    NL[node].left = FREE; NL[node].left = -1; NL[node].data = 0;//Changing data is not needed
    FREE = node;
}

void __delete_double_child(BT_TREE *tree, int parent, int node)
{
    //Find the inorder successor and replace that and then delete the leaf

    //successor = left most of right subtree
    int par_succ = node;
    int successor = NL[node].right;

    while(NL[successor].left != -1)
    {
        par_succ = successor;
        successor = NL[successor].left;
    }

    NL[node].data = NL[successor].data;

    //delete the successor
    int node_to_delete = successor;
    parent = par_succ;
    //Either 0 child or 1 child

    if(__child_no(tree, node_to_delete) == 0)
        __delete_leaf(tree, parent, node_to_delete);
    else
        __delete_single_child(tree, parent, node_to_delete);
}


void remove_element(BT_TREE *tree, int key)
{
    int parent = parent_search(tree, key);
    if(parent == -2)
        printf("NOT PRESENT TO DELETE\n");
    else if(parent == -1)
    {
        //delete root
    }
    else
    {
        //Left or right child of the parent
        int left = NL[parent].left, right = NL[parent].right;
        int node_to_delete;

        if(NL[left].data == key)
            node_to_delete = NL[parent].left;
        else
            node_to_delete = NL[parent].right;

        //How many child of the node to delte
        int child_no = __child_no(tree, node_to_delete);
        if(child_no == 0)
            __delete_leaf(tree, parent, node_to_delete);
        else if(child_no == 1)
            __delete_single_child(tree, parent, node_to_delete);
        else
            __delete_double_child(tree, parent, node_to_delete);
    }

}

#endif