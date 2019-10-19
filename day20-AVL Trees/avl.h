#ifndef AVL_H
#define AVL_H

#include <time.h>

#define MAX_NODES 100

typedef int DATA;

typedef struct node {
    DATA data;
    int left, right, parent, height; // following Weiss, DS & AA in C++, 4ed.
} AVL_NODE;

typedef struct {
    unsigned int num_nodes, max_nodes;
    int root, free_list;
    AVL_NODE *nodelist;
} AVL_TREE;


/* UTILITY FUNCTIONS */
extern int grow_tree(AVL_TREE *);
extern int get_new_node(AVL_TREE *);
extern void free_up_node(AVL_TREE *, int);
extern int find_successor(AVL_TREE *, int);

extern void rotate_on_insert_LL(AVL_TREE *, int , int *);
extern void rotate_on_insert_RR(AVL_TREE *, int , int *);
extern void rotate_on_insert_LR(AVL_TREE *, int , int *);
extern void rotate_on_insert_RL(AVL_TREE *, int , int *);
extern void balance(AVL_TREE *, int, int *);

extern void inorder(AVL_TREE *, int);
extern void print_tree(AVL_TREE *, int, int);
extern void print_pstree(AVL_TREE *, int);

#define HEIGHT(T, nodeindex) ( ((nodeindex) == -1) ? -1 : T->nodelist[nodeindex].height )
#define PRINT_NODE(T, nodeindex) { \
    if (nodeindex != -1) \
        printf("%d\n", T->nodelist[nodeindex].data); \
    }

/* API FUNCTIONS */
extern int init_tree(AVL_TREE *);
extern int search(AVL_TREE *, int , DATA);
extern int insert(AVL_TREE *, int , int *, DATA);
extern int delete(AVL_TREE *, int , int *, DATA);

#define DELETE_TREE(tree) free(tree->nodelist);

#endif /* AVL_H */
