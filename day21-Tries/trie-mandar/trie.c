#include "common.h"
#include "trie.h"


char START_CHAR_DFS = 'a';

unsigned long max_nodes, num_nodes;
TRIE_NODE *trie;

int init_trie(char start_char)
{
    START_CHAR_DFS = start_char;
    max_nodes = 10000;
    if (NULL == (trie = (TRIE_NODE *) calloc(max_nodes, sizeof(TRIE_NODE))))
        ERR_MESG("init-trie: out of memory\n");
    num_nodes = 1;
    return 0;
}

int insert_node()
{
    if (num_nodes == max_nodes) {
        max_nodes *= 2;
        if (NULL == (trie = Realloc(trie, max_nodes, TRIE_NODE)))
            ERR_MESG("insert-node: out of memory\n");
        bzero((void *) (trie + num_nodes), num_nodes * sizeof(TRIE_NODE));
    }
    num_nodes++;
    return num_nodes - 1;
}

int insert_string(char *s)
{
    unsigned int index = 0;
    int c, new_index;

    while (*s) {
        c = *s;
        if (c >= 'A' && c <= 'Z')
            c = 'a' + c -'A';
        if (c >= 'a' && c <= 'z') {
            c = c - 'a';
            if (trie[index][c] != 0)
                /* just follow the pointer */
                index = trie[index][c];
            else {
                /* need new node */
                if (UNDEF == (new_index = insert_node()))
                    return UNDEF;
                index = trie[index][c] = new_index;
            }                
        }
        else
            fprintf(stderr, "Unexpected character %c\n", c);
        s++;
    }
    trie[index][NUM_SYMS]++;

    return 0;
}


int insert_number(char *s)
{
    unsigned int index = 0;
    int c, new_index;

    while (*s) {
        c = *s;
        if (c >= '0' && c <= '9') {
            c = c - '0';
            if (trie[index][c] != 0)
                /* just follow the pointer */
                index = trie[index][c];
            else {
                /* need new node */
                if (UNDEF == (new_index = insert_node()))
                    return UNDEF;
                index = trie[index][c] = new_index;
            }                
        }
        else
            fprintf(stderr, "Unexpected character %c\n", c);
        s++;
    }
    trie[index][NUM_SYMS]++;

    return 0;
}

typedef struct {
    char c;
    unsigned long index;
    unsigned int level;
} STACK_NODE;

int trie_dfs()
{
    char word[BUF_LEN << 10], c;
    unsigned int level;
    int i;
    unsigned long top = 1, index, count;
    STACK_NODE *stack, *sptr;

    if (NULL == (stack = Malloc(num_nodes, STACK_NODE)))
        ERR_MESG("trie_dfs: out of memory");
    sptr = stack;
    sptr->c = '\0';
    sptr->index = 0;
    sptr->level = 0;
    while (top > 0) {
        sptr = stack + top - 1;
        top--;
        c = sptr->c;
        index = sptr->index;
        level = sptr->level;
        count = trie[index][NUM_SYMS];
        if (c) {
            assert(level > 0);
            word[level - 1] = c;
        }
        if (count > 0) {
            word[level] = '\0';
            printf("%s %lu\n", word, count);
        }
        for (i = NUM_SYMS - 1; i >= 0; i--) {
            if (trie[index][i] > 0) {
                sptr = stack + top;
                sptr->c = START_CHAR_DFS + i;
                sptr->index = trie[index][i];
                sptr->level = level + 1;
                top++;
            }
        }
    }

    return 0;
}
