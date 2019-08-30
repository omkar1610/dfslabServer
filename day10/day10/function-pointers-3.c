#include "common.h"

int compare_strings_wrong (void *elem1, void *elem2)
{
    char *s1 = elem1, *p1;
    char *s2 = elem2, *p2;
    return strcmp (s1, s2);
}

int genericLinearSearch ( void *key, void *base, int num_elements, int elem_size, int (*comparator) (void *, void *) )
{
    int i;
    for (i = 0; i < num_elements; i++) {
        void *eptr = (char *) base + i * elem_size;
        if (comparator(eptr, key) == 0)
            return i;
    }
    return -1;
}

int main ()
{
    char *array1[5] = {"Ab", "Eb", "B", "F#", "D"};
    char *key1 = "Eb";
    int status;

#ifdef DEBUG
    printf("array1: %p (%lu)\n", &(array1[0]), (long unsigned int) &(array1[0]));
    printf("key1: %p (%lu)\n", &key1, (long unsigned int) &key1);
    printf("status: %p (%lu)\n\n", &status, (long unsigned int) &status);

    int i;
    for (i = 0; i < 5; i++)
        printf("%p\n", array1[i]);
    printf("\n%p\n", key1);
#endif // DEBUG

    status = genericLinearSearch (&key1, array1, 5, sizeof (char *), compare_strings_wrong);
    printf("key1, array1: %d\n", status);

    return 0;
}
