#include "justBinaryTree.h"
#include "/home/omkar/Documents/dfslabServer/day10-Function pointers; generic stacks/stack.h"

typedef struct{
	int data;
}DATA;

void dataPrint(void *data)
{
	printf("%d ",*(int*)(data) );
}

void inorder_iterative(BTREE *btree)
{
	STACK s;
	initStack(&s, sizeof(int));
	int curr = 0;
	while (curr != -1 || s.num_elements != 0) 
    { 
        /* Reach the left most Node of the 
           curr Node */
        while (curr !=  -1) 
        {
            push(&s, &curr); 
            curr = btree->array[curr]->left;
        } 
  
        /* Current must be NULL at this point */
       	pop(&s, &curr);
	  	btree->dataPrint(btree->array[curr]->data);

        /* we have visited the node and its 
           left subtree.  Now, it's right 
           subtree's turn */
		curr = btree->array[curr]->right;
  
    }
}

int main(int argc, char const *argv[])
{
	BTREE btree; 
	DATA d; 
	initTree(&btree, sizeof(DATA), dataPrint);


	d.data = 60; insert(&btree, &d, 1, 2);
	d.data = 50; insert(&btree, &d, 3, 4);
	d.data = 70; insert(&btree, &d, -1, 5);
	d.data = 45; insert(&btree, &d, -1, -1);
	d.data = 55; insert(&btree, &d, -1, -1);
	d.data = 75; insert(&btree, &d, -1, -1);

	displayTable(&btree);
	preorder(&btree, 0);printf("\n");
	inorder(&btree, 0);printf("\n");
	postorder(&btree, 0);printf("\n");
	inorder_iterative(&btree);printf("\n");
	


	return 0;
}