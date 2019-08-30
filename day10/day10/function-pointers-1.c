#include "common.h"

#ifdef EX1
char **fun()
{
    static char *z = (char*) "Hello world!";
    return &z;
}

int main()
{
    char **ptr = NULL;
    char **(*fun_ptr)(); //declaration of pointer to the function
    fun_ptr = &fun;
    ptr = fun();
    printf("\n %s \n Address of function = [%p]", *ptr, fun_ptr);
    printf("\n Address of first variable created in fun() = [%p]", (void*)ptr);

    return;
}
#elifdef EX2
int compare_int (void *elem1, void *elem2) {
    int *ip1 = elem1;
    int *ip2 = elem2;
    /* int *ip1 = *((int *) elem1); */
    /* int *ip2 = *((int *) elem2); */

    return *ip1 - *ip2;
}
#elifdef EX3
int stringCmp (void *elem1, void *elem2) {
    char *s1 = * (char **) elem1;
    char *s2 = * (char **) elem2;
    return strcmp (s1, s2);
}
#elifdef EX4
int stringCmp (void *elem1, void *elem2) {
    char **s1 = elem1;
    char **s2 = elem2;
    return strcmp (*s1, *s2);
}
#endif
