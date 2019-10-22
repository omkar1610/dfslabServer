#include "bin-alt.h"



void show(BT_TREE *tree)
{
	printf("DATA %d FREE %d\n", tree->root, tree->free_list);
	for(int i=0 ; i<tree->max_nodes ; i++)
		printf("%d %d %d %d\n", i,tree->nodelist[i].left, tree->nodelist[i].right, tree->nodelist[i].parent);
	// printf("DATA\n");
	// for(int i=tree->root ; i!=-1 ; i = tree->nodelist[i].left)
	// 	printf("%d %d %d %d\n", i,tree->nodelist[i].left, tree->nodelist[i].right, tree->nodelist[i].parent);


	// printf("FREE\n");
	// for(int i=tree->free_list ; i!=-1 ; i = tree->nodelist[i].left)
	// 	printf("%d %d %d %d\n", i,tree->nodelist[i].left, tree->nodelist[i].right, tree->nodelist[i].parent);
}

int main()
{
	BT_TREE tree;
	init_btree(&tree);
	show(&tree);
}