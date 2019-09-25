#include "justBinaryTree.h"
#include "stack.h"

typedef struct{
	int data;
}DATA;

void dataPrint(void *data)
{
	printf("%d ",*(int*)(data) );
}

void postorder_iterative_single_stack(BTREE *btree)// Not DOne Properly
{
	// Base Case
      
    STACK s; 
	initStack(&s, sizeof(int));
	int curr = 0; 
	do
    { 
        // Move to leftmost node 
        while (curr != -1) 
        { 
            // Push root's right child and then root to stack. 
           
            if (CURR_RIGHT != -1)
    		{ 
	            int tmp = CURR_RIGHT;
	            push(&s, &tmp); 
	        }
            push(&s, &curr); 
  
            // Set root as root's left child   
            curr = CURR_LEFT; 
        } 
  
        // Pop an item from stack and set it as root     
        pop(&s, &curr);
  
        // If the popped item has a right child and the right child is not 
        // processed yet, then make sure right child is processed before root 
        int tmp; peek(&s, &tmp);
        if (CURR_RIGHT != -1 && tmp == CURR_RIGHT) 
        { 
                        
            pop(&s, &tmp);  
            push(&s, &curr); // push root back to stack 
            curr = CURR_RIGHT; // change root so that the right  
                                // child is processed next 
        } 
        else  // Else print root's data and set root as NULL 
        { 
            btree->dataPrint(btree->array[curr]->data);
            curr = -1;
        } 
    } while (s.num_elements != 0);
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
	preorder_iteratice(&btree);printf("\n");
	printf("\n");
	inorder(&btree, 0);printf("\n");
	inorder_iterative(&btree);printf("\n");
	printf("\n");
	postorder(&btree, 0);printf("\n");
	postorder_iterative(&btree);printf("\n");
	printf("\n");
	postorder_iterative_single_stack(&btree);printf("\n");
	return 0;
}