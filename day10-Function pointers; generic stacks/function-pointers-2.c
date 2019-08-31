#include "common.h"

int compare_strings_wrong (void *elem1, void *elem2)
{
    char *s1 = elem1;
    char *s2 = elem2;
    return strcmp (s1, s2);
}

int compare_strings_implicit (void *elem1, void *elem2)
{
    char **s1 = elem1;
    char **s2 = elem2;
    return strcmp (*s1, *s2);
}

int compare_strings_explicit (void *elem1, void *elem2)
{
    char *s1 = *((char **) elem1);
    char *s2 = *((char **) elem2);
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
    char *array1[5] = {"Ab", "F#", "B", "Eb", "D"};
    char **array2;
    int status, i;

    if (NULL == (array2 = Malloc(5, char *)))
        ERR_MESG("function-pointers: out of memory");
    array2[0] = strdup ("Ab");
    array2[1] = strdup ("F#");
    array2[2] = strdup ("B");
    array2[3] = strdup ("Eb");
    array2[4] = strdup ("D");

    char *key1 = "Eb";
    char *key2 = strdup("Eb");

    printf("With incorrect type cast in comparator:\n");
    status = genericLinearSearch (&key1, array1, 5, sizeof (char *), compare_strings_wrong);
    printf("key1, array1: %d\n", status);

    status = genericLinearSearch (&key1, array2, 5, sizeof (char *), compare_strings_wrong);
    printf("key1, array2: %d\n", status);

    status = genericLinearSearch (&key2, array1, 5, sizeof (char *), compare_strings_wrong);
    printf("key2, array1: %d\n", status);

    status = genericLinearSearch (&key2, array2, 5, sizeof (char *), compare_strings_wrong);
    printf("key2, array2: %d\n", status);

    printf("With implicit type casting in comparator:\n");
    status = genericLinearSearch (&key1, array1, 5, sizeof (char *), compare_strings_implicit);
    printf("key1, array1: %d\n", status);

    status = genericLinearSearch (&key1, array2, 5, sizeof (char *), compare_strings_implicit);
    printf("key1, array2: %d\n", status);

    status = genericLinearSearch (&key2, array1, 5, sizeof (char *), compare_strings_implicit);
    printf("key2, array1: %d\n", status);

    status = genericLinearSearch (&key2, array2, 5, sizeof (char *), compare_strings_implicit);
    printf("key2, array2: %d\n", status);

    printf("With explicit type casting in comparator:\n");
    status = genericLinearSearch (&key1, array1, 5, sizeof (char *), compare_strings_explicit);
    printf("key1, array1: %d\n", status);

    status = genericLinearSearch (&key1, array2, 5, sizeof (char *), compare_strings_explicit);
    printf("key1, array2: %d\n", status);

    status = genericLinearSearch (&key2, array1, 5, sizeof (char *), compare_strings_explicit);
    printf("key2, array1: %d\n", status);

    status = genericLinearSearch (&key2, array2, 5, sizeof (char *), compare_strings_explicit);
    printf("key2, array2: %d\n", status);

    return 0;
}
