#include "bst-alt-me.h"

#ifndef BT_H_UTILS
#define BT_H_UTILS


void init_btree(BT_TREE *tree) 
{
    int i;

    NUM_ELE = 0;
    MAX_ELE = 25;
    NL = malloc(MAX_ELE * sizeof(BT_NODE));   
    ROOT = -1;
		FREE = 0;
    
    for (i = 0; i < MAX_ELE; i++) {
        NL[i].left = i+1;
        NL[i].right = -1;
    }
    NL[i-1].left = -1;
}

void inorder(BT_TREE *tree, int node)
{
    if(node != -1){
        inorder(tree, NL[node].left);
        printf("%d ", NL[node].data);
        inorder(tree, NL[node].right);
    }
}


void display(BT_TREE *tree)
{
    printf("TREE\n");
    for (int i = 0; i < MAX_ELE; ++i)
        printf("%d %d %d %d\n", i, NL[i].data, NL[i].left, NL[i].right);
    // printf("FREE\n");
    // for (int i = FREE; i != -1  ; i = NL[i].left)
    //     printf("%d %d %d %d\n", i, NL[i].data, NL[i].left, NL[i].right);
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


int search(BT_TREE *tree, int key)
{
 
    return __search(tree, ROOT, key);
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

void remove_element(BT_TREE *tree, int key)
{
    int parent = parent_search(tree, key);
    if(parent == -2)
        printf("NOT PRESENT TO DELETE\n");
    else if(parent == -1)
    {
        //delete root
        __delete_root(tree);
    }
    else
    {
        //Left or right child of the parent
        int left = NL[parent].left, right = NL[parent].right;
        int node_to_delete;

        if(NL[left].data == key)  node_to_delete = NL[parent].left;
        else                      node_to_delete = NL[parent].right;

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



int height(BT_TREE *tree)
{
	__height(tree, ROOT);
}

#endif