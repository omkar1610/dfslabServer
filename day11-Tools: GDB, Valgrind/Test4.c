/* C program for allocating and deallocating memories. */

#include<stdio.h>
#include <stdlib.h>

int main(){
	char *ptr;

	// Allocation no. 1 of 20 bytes
	ptr = (char *) malloc(20);
	// Allocation no. 2 of 10 bytes
	ptr = (char *) malloc(10);
	free(ptr);
	free(ptr);
	// Allocation no. 3 of 30 bytes
	ptr = (char *) malloc(16);
	return 0;
}