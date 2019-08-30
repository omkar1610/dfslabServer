/* C program that accesses various memories */

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main(void)
{
    char *ptr1 = (char*)malloc(10*sizeof(char)); // Never freed memory (memory leak)
    char *ptr2 = (char*)malloc(20);

    memset(ptr2, 0, 20);

    strncpy(ptr2, "Memcheck", strlen("Memcheck"));

    printf("\n ptr2 = [%s]\n", ptr);

    free(ptr2);

    ptr2[0] = 'a'; // Invalid write
    return 0;
}