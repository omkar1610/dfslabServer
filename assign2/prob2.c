#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void prog(char *a, char *b, char *n1, char *n2)
{
	int i = 0, j = 0;
	size_t la = strlen(a), lb = strlen(b), ln1 = strlen(n1), ln2 = strlen(n2);
	int b1, b2; //First unequal point
	
	int min = la<ln1?la:ln1;
	while(i<=min && a[i] == n1[i]) i++;
	b1 = i;

	i = 0;
	min = lb<ln2?lb:ln2;
	while(i<=min && b[i] == n2[i]) i++;
	b2 = i;
	printf("%d %d\n",b1, b2 );

	for(i = b1; i<= ln1 && b2+i-1<=lb && n1[i] == b[b2+i-1]; i++) ;
		if(i == ln1+1) printf("Y\n");
	
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
	// scanf("%m[^\n]", &b);getchar();
	// scanf("%m[^\n]", &n1);getchar();
	// scanf("%m[^\n]", &n2);getchar();

	// printf("%s %s %s %s\n", a, b, n1, n2);


	return 0;
}