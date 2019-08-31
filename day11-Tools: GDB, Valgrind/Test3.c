/* C program for printing the addition of three components. Each componet consists
   of integers taken pairwise from three integers and some error flags. The three
   integers are provided as command line arguments. */

#include<stdio.h>
#include<stdlib.h>

#define PI 3.14
#define ERROR_FLAG_1 EF1
#define ERROR_FLAG_2 EF2

int sum(int x, int y, int z){
	char ERROR_FLAG_2 = 1;
	int *a = 0; // Segmentation fault
	return (ERROR_FLAG_2 + x + y + z + *a)/2;
}

int main(int argc, char *argv[]){

	int i, j, k;
	int result;
	char ERROR_FLAG_1 = 0;

 	if(argc = 1){ // Assignment instead of condition check
		printf("Please specify three integers as parameters!!!\n");
     		exit(1);
	}
	i = atoi(argv[1]);
	j = atoi(argv[2]);
	k = atoi(argv[3]);
	result = sum(i,j,ERROR_FLAG_1) + sum(j,k,ERROR_FLAG_1) + sum(k,i,ERROR_FLAG_1);
	printf("%d\n", result);
	return 0;
}