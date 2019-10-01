#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(int argc, char const *argv[])
{
	int i, j;
	char 	*a = "010111010", 
			*b = "011110010",
			*n1 = "0100010",
			*n2 = "01111111010";
	size_t la = strlen(a), lb = strlen(b), ln1 = strlen(n1), ln2 = strlen(n2);
	int b1, b2;
	for(i = ln1, j = lb; i>=0 && j >= 0 && n1[i] == b[j]; i--, j--);
	printf("i %d j %d\n", i+1 , j+1);

	for(i = ln2, j = la; i>=0 && j >= 0 && n2[i] == a[j]; i--, j--);
	printf("i %d j %d\n", i+1 , j+1);

	return 0;
}