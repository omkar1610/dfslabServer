/* C program for memory management. */

#include<stdio.h>
#include<stdlib.h>

void f(void){

	int* x = malloc(10 * sizeof(int));

	x[10] = 0;
	// problem 1: heap block overrun
}

// problem 2: memory leak -- x not freed
int main(void){

	int i, arr[10];

	f();
	for(i=0; i<10; i++){
		printf("%3d",i);
	}
	return 0;
}