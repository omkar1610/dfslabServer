#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MIN(x,y) ((x)<(y)?(x):(y))

void prog(char *a, char *b, char *n1, char *n2)
{
	int i = 0, j = 0;
	size_t la = strlen(a), lb = strlen(b), ln1 = strlen(n1), ln2 = strlen(n2);
	
	int e_1, e_2;
	int i, j;
	//from last in n1 and b till they are same
	for(i = lb, j = ln1;i>=0 && j>=0 && b[i] == n1[j]; i--, j--);
	e1 = i;
	for(i = la, j = ln2;i>=0 && j>=0 && a[i] == n2[j]; i--, j--);
	e2 = i;
	int end = MIN(e1,e2);
}

int main(int argc, char const *argv[])
{
	int i, j;
	char 	*a = "010111010", 
			*b = "011110010",
			*n1 = "0100010",
			*n2 = "01111111010";
	prog(a,b,n1,n2);
	
	// scanf("%m[^\n]", &a);getchar();


	return 0;
}