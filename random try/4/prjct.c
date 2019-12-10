#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define n 2000
#define C_l 50

#define numActive *(int*)B
#define deltaLast *((int*)B + 1)

#define CELL_SIZE_B sizeof(int)
#define CELL_SIZE_L (int)ceil(log2(n))

#define CELL_COUNT_B n
#define CELL_COUNT_L (int) n/C_l

#define CELL_of_B_in_L (int)ceil(((float)CELL_COUNT_L * CELL_SIZE_L)/(8 * CELL_SIZE_B))
#define N_base (2 + CELL_of_B_in_L)

struct
{
	int i, val, next, prev;
}Node;


struct {
   unsigned int age : CELL_SIZE_L;
} Age;

int main()
{
	void* B = malloc(CELL_COUNT_B * CELL_SIZE_B);

	// printf("B = %d cells = %lu bytes(%lu bits)\n", CELL_COUNT_B, CELL_COUNT_B * CELL_SIZE_B, 8 * CELL_COUNT_B * CELL_SIZE_B);

	// printf("G = %d cells = %lu bytes(%lu bits)\n", 2, 2 * CELL_SIZE_B, 8 * 2 * CELL_SIZE_B);
	
	// printf("L = %d cells = %lu bytes(%lu bits)\n", CELL_COUNT_L, CELL_COUNT_L * CELL_SIZE_L, 8 * CELL_COUNT_L * CELL_SIZE_L);

	// printf("L = %d cell of B", CELL_of_B_in_L);

	printf("CELL_SIZE_B %luB \nCELL_SIZE_L %db \nCELL CELL_COUNT_L %d \nCELL_of_B_in_L %d\n", CELL_SIZE_B , CELL_SIZE_L , CELL_COUNT_L , CELL_of_B_in_L);
	printf("N_base %d\n", N_base);

	numActive = 0;
	deltaLast = 2;


	Age.age = 20;
	printf( "Sizeof( Age ) : %d\n", sizeof(Age) );
	printf( "Age.age : %d\n", Age.age );

	unsigned int j : 3;
	j = 5;
	printf("%d\n", j);



}
