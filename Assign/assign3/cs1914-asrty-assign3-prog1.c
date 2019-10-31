#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
#define SWAP(i,j){\
    char *tmp = a[j]; \
    a[j] = a[i]; \
    a[i] = tmp; \
    count++; \
}

#define DATA {\
    for (int k = 1; k < argc; ++k) \
        printf("%s ", a[k]); \
    printf("\n"); \
}

#define CMP(i,j) strcmp(a[(i)],a[(j)])

int main(int argc, char *a[])
{
    int count = 0;
    // for (int i = 1; i < argc; ++i)        printf("%d ", i);    printf("\n");

    int n = argc -1;
    // DATA;
    // a[1], a[2], .... , a[argc-2], a[argc-1]
    // printf("FORWARD\n");
    for (int i = 1; i < argc-1; ++i)
    {
        if(CMP(i, i+1) == 0)
        {
            int j = i+2;
            int flag = 1;
            // Find appropriate j to swap with i+1  in forward pass
            while(j<=argc-1 && flag)
            {
                // printf("\ni j %d %d\n", i, j);
                // i neq j
                if(CMP(i,j) != 0 /*&& printf("j = %d ", j)*/)
                {
                    flag = 0;
                    // i neq j-1
                    if(j>i+2 && CMP(i,j-1) == 0 /*&& printf("j-1 %d ", j-1)*/) flag = 1;
                    // i neq j+1
                    if(j<argc-1 && CMP(i, j+1) == 0 /*&& printf("j+1 %d\n", j+1)*/) flag = 1;
                    // Swap if all 3 above is satisfied
                    if(flag == 0) SWAP(i+1, j);
                    // printf("\nswapping %d %d\n", i, j);
    
                    // DATA;

                }
                j++;
            }
            
        }

        
    }
    // DATA;
    // printf("BACKWARD\n");
    for (int i = argc-1; i >1 ; --i)
    {
        if(CMP(i, i-1) == 0)
        {
            int j = i-2;
            int flag = 1;
            while(j>=1 && flag)
            {
                // printf("\ni j %d %d\n", i, j);
                // i neq j
                if(CMP(i,j) != 0 /*&& printf("j = %d ", j)*/)
                {
                    flag = 0;
                    // i neq j-1
                    if(j<i+2 && CMP(i,j-1) == 0 /*&& printf("j-1 %d ", j-1)*/) flag = 1;
                    // i neq j+1
                    if(j>1 && CMP(i, j+1) == 0 /*&& printf("j+1 %d\n", j+1)*/) flag = 1;
                    // Swap if all 3 above is satisfied
                    if(flag == 0) SWAP(i-1, j);
                    // printf("\nswapping %d %d\n", i, j);
                    // DATA;

                }
                j--;
            }
        }
    }

    printf("No of swaps : %d\n", count);
    DATA;
    return 0;
}