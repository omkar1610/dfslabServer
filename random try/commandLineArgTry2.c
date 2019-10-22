#include <stdio.h>
#include <stdlib.h>

int main(int argc, int const *argv[])
{
	printf("%d\n", argc);
	for(int i=0 ; i<argc ; i++)
		printf("%lu\n", argv[i]);
	return 0;
}