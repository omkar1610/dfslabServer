#include "bst-alt-me.h"
#include "bst-alt-me-utils.h"




int main(int ac, char *av[])
{
    BT_TREE tree;
    init_btree(&tree);

    char op[1] = "+"; int tmp;
    //add remove inorder display_table
    while(op[0] != 'q')
    {

        scanf("%s", op);
        // printf("%s %d\n", op, tmp);
        if(op[0] == 'a')
        {
            scanf("%d", &tmp);
            insert(&tree, tmp);
        }
        else if(op[0] == 'r')
        {
            scanf("%d", &tmp);
            remove_element(&tree, tmp);
        }
        else if(op[0] == 'i')
        {
            printf("INORDER : "); inorder(&tree, tree.root);printf("\n");
        }
        else if(op[0] == 'd')
            display(&tree);

        else if(op[0] == 'q')
            printf("OK BYE !!\n");

        else if(op[0] != 'q')
            printf("INVALID ENTRY\n");

        fflush(stdin);
    }

    return 0;
}
