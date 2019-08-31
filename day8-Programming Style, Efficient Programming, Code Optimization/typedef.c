#include <stdio.h>
#include <stdlib.h>

typedef struct TRIANGLE{
	int data;
	struct TRIANGLE *next;
}TRIANGLE;


TRIANGLE *createnode(int x)
{
	TRIANGLE *node = (TRIANGLE *)malloc(sizeof(TRIANGLE));
	node->data = x;

	return node;
}


int main()
{
	TRIANGLE *t = createnode(50);
	t->next = createnode(70);
	t->next->next = createnode(40);
	t->next->next->next = createnode(50);
	t->next->next->next->next = NULL;
	while(t = t->next)
		printf("%d\n",t->data );

	return 0;
}