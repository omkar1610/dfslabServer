
#include <stdio.h>
#include <stdlib.h>
#include "stack.h"


#define XXX {\
for(int i = 0; i<s->num_elements;i++)\
		printf("%d ", (((int *)(s->elements))[i]));\
	printf("\n");\
}


int main(int argc, char const *argv[])
{
	STACK st;
	STACK *s = &st;
	initStack(s, sizeof(int));
	int x = 5; int *a = &x;

	printf("Total elements : %lu\n", s->num_elements);
	push(s,a);
	x++;push(s,a);XXX
	x++;push(s,a);XXX
	x++;push(s,a);XXX
	x++;push(s,a);XXX
	x++;push(s,a);XXX
	x++;push(s,a);XXX
	x++;push(s,a);XXX
	x++;push(s,a);XXX
	x++;push(s,a);XXX
	x++;push(s,a);XXX
	printf("Total elements : %lu\n", s->num_elements);

	XXX


	pop(s,a); printf("DELETED %d\n", x);
	pop(s,a); printf("DELETED %d\n", x);
	pop(s,a); printf("DELETED %d\n", x);
	

	XXX
	return 0;
}