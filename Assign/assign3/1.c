#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
#define SWAP(i,j){\
    char *tmp = a[j]; \
    a[j] = a[i]; \
    a[i] = tmp; \
}

int main(int argc, char *a[])
{
    for (int i = 1; i < argc; ++i)
        printf("%s ", a[i]);
    printf("\n");

    for (int i = 1; i < argc-1; ++i)
    {
        if(strcmp(a[i],a[i+1]) == 0)
        {
            int j = i+2;
            while(j<argc && strcmp(a[i],a[j])==0)
                j++;
            if(j<argc)
            {
                SWAP(j, i+1);
            }
            else
            {
                j = i-2;
                while(j>=0 && strcmp(a[i], a[j]) == 0 && (j<1 || strcmp(a[j], a[j-1]) != 1))
                    j--;
                if(j>=0)
                    SWAP(j, i+1);
            }

            for (int k = 1; k < argc; ++k)
        printf("%s ", a[k]);
    printf("\n");
        }
        

    }

    for (int i = 1; i < argc; ++i)
        printf("%s ", a[i]);
    printf("\n");
    return 0;
}