/* C program for finding out the multiplication of the integers from 1 to n.
   Here n is the user input. */

#include<stdio.h>

int main(){

	int i, n;
	int mult;
	
	scanf("%i", &n);
	// Wrong initialization
	mult = 1;
	for(i = 1; i <= n; i++) // Error in condition check
		mult *= i;
	printf("%d", mult);
	return 0;
}
