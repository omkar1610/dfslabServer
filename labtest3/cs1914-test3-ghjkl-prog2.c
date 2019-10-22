#include "cs1914-test3-ghjkl-prog2.h"

//Since we already have a BST, and we need to change the node and the right child,
// So the postorder result should be the inorder of the current BST


//Post order of new = in order of old

int main(int argc, char const *argv[])
{

	TREE tree;
	initFromFile(&tree, argv[1]);
	// showTable(&tree);

	int inorder_data[tree.max_nodes];
	inorder(&tree, 0, inorder_data);
	// //Change wrt post and replace accordingly

	update(&tree, 0, inorder_data);
	showTable(&tree);
}