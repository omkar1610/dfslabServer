#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define n 200
#define C_l 50
#define numActive B[0]
#define deltaLast B[1]
#define w sizeof(int)
#define num_LL (int) n/C_l
#define ele_L (int)floor(log2(n))


struct
{
	int i, val, next, prev;
}Node;


int main()
{
	int* B = malloc(n * sizeof(int));
	printf("each bit of L = %d\n", (int)floor(log2(n)));

	printf("size of B = %lu bytes(%lu bits)\n", n * sizeof(int), 8 * n * sizeof(int));
	printf("size of G = %lu bytes(%lu bits)\n", 2 * sizeof(int), 8 * 2 * sizeof(int));
	printf("size of L = ? bytes(%d bits)\n", num_LL * ele_L);
	printf("cells of B in  L = %d\n", (int)ceil((num_LL * ele_L)/(8 * sizeof(int))));




}