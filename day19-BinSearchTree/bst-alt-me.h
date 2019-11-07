#include <stdio.h>
#include <stdlib.h>


#ifndef MAX
#define MAX(a,b) (((a)>(b))?(a):(b))
#define MIN(a,b) (((a)<(b))?(a):(b))
#endif


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
    NUM_ELE--;
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
    NUM_ELE--;
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

    //replace the value
    NL[node].data = NL[successor].data;

    //delete the successor
    int node_to_delete = successor;
    parent = par_succ;

    //Either 0 child or 1 child //No left child for sure

    if(NL[node_to_delete].right == -1)
        __delete_leaf(tree, parent, node_to_delete);
    else
        __delete_single_child(tree, parent, node_to_delete);
}

void __delete_root(BT_TREE *tree)
{
    int child_no = __child_no(tree, ROOT);
    if(child_no == 0)
    {
        NL[ROOT].left = FREE;
        FREE = ROOT;
        ROOT = -1;
        NUM_ELE--;
    }

    else if(child_no == 1)
    {
        //left child exists
        int tmp = ROOT;
        if(NL[ROOT].left != -1)
            ROOT = NL[ROOT].left;
        //right child
        else
            ROOT = NL[ROOT].right;

        NL[tmp].left = FREE;
        FREE = tmp;
        NUM_ELE--;
    }
    else
    {
        int par_succ = ROOT;
        int successor = NL[ROOT].right;
        while(NL[successor].left != -1)
        {
            par_succ = successor;
            successor = NL[successor].left;
        }

        NL[ROOT].data = NL[successor].data;

        //delete the successor
        int node_to_delete = successor;
        int parent = par_succ;

        //Either 0 child or 1 child

        if(__child_no(tree, node_to_delete) == 0)
            __delete_leaf(tree, parent, node_to_delete);
        else
            __delete_single_child(tree, parent, node_to_delete);
    }
}


int __height(BT_TREE *tree, int node)
{
    if(node != -1)
        return 1 + MAX(__height(tree, NL[node].left), __height(tree, NL[node].right));
    else
        return 0;
}

#endif