#include "common.h"
#include "avl.h"

void showTable(AVL_TREE *tree)
{
    
}


int main(int ac, char *av[])
{
    int i;
    AVL_TREE t;

    init_tree(&t);
    for (i = 1; i < ac; i++) {
        printf("Inserting %d\n", atoi(av[i]));
        if (FAILURE == insert(&t, -1, &(t.root), atoi(av[i])))
            return FAILURE;
        
    }

    inorder(&t, t.root);
    printf("\n");
        
    return 0;
}
