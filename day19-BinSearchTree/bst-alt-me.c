#include "common.h"
#include "bst-alt-me.h"




int main(int ac, char *av[])
{
    BT_TREE tree;
    init_btree(&tree);
    insert(&tree, 10);
    insert(&tree, 15);
    insert(&tree, 2);
    insert(&tree, 17);
    insert(&tree, 13);
    insert(&tree, 7);
    insert(&tree, 19);
    display(&tree);

    printf("%d\n", search(&tree, 21));
    int x; scanf("%d", &x);
    printf("%d\n", parent_search(&tree, x));

    return 0;
}
